using System.Collections;
using UnityEngine;
using UnityEngine.Events;
using Unity.Netcode;

/// <summary>
/// PlayerMovement — NetworkBehaviour version.
/// Camera / AudioListener / XR rig activate only for the owning client.
/// </summary>
public class PlayerMovement : NetworkBehaviour
{
    [Header("Movement Settings")]
    [SerializeField] private float moveSpeed = 5f;
    [SerializeField] private float hopHeight = 0.3f;
    [SerializeField] private float heightOffset = 0.1f;

    [Header("Multi-Player Spacing")]
    [SerializeField] private float occupancyCheckRadius = 2f;
    [SerializeField] private float playerOffset = 8f;

    private PlayerData playerData;
    private bool isMoving = false;

    public UnityEvent<TileData> OnTilePassed = new UnityEvent<TileData>();
    public UnityEvent<TileData> OnTileLanded = new UnityEvent<TileData>();
    public UnityEvent OnPassedGO = new UnityEvent();

    // ── NGO: called on every machine once this object is networked ────────────

    public override void OnNetworkSpawn()
    {
        // XROwnershipGuard handles Camera Offset enable/disable.
        // PlayerMovement just needs to make sure the root stays active.
        gameObject.SetActive(true);

        bool isMine = IsOwner;
        Debug.Log($"[PlayerMovement] {gameObject.name} spawned — IsOwner={isMine}");

        // ── AudioListener: only one may be active at a time ──────────────────
        foreach (AudioListener al in GetComponentsInChildren<AudioListener>(true))
            al.enabled = isMine;

        // ── Camera tag: tag this client's camera as MainCamera ───────────────
        // XROwnershipGuard already enables/disables the Camera Offset child.
        // We just need to make sure our camera has the right tag so Camera.main works.
        if (isMine)
        {
            foreach (Camera cam in GetComponentsInChildren<Camera>(true))
                cam.tag = "MainCamera";
        }
    }

    // ── Init called by CompleteGameManager (server side) ─────────────────────

    public void Initialize(PlayerData data)
    {
        playerData = data;
    }

    // ── Public movement API ───────────────────────────────────────────────────

    public void MoveByDiceRoll(int spaces, TileData[] allTiles)
    {
        if (isMoving) return;
        if (allTiles == null || allTiles.Length != 40) return;
        StartCoroutine(MoveSequence(spaces, allTiles));
    }

    public void TeleportToTile(int tileIndex, TileData[] allTiles)
    {
        if (allTiles == null || tileIndex < 0 || tileIndex >= allTiles.Length) return;
        playerData.currentTileIndex = tileIndex;
        transform.position = GetFinalPositionOnTile(allTiles[tileIndex].worldPosition) + Vector3.up * heightOffset;
    }

    public bool IsMoving() => isMoving;

    // ── Movement coroutines ───────────────────────────────────────────────────

    private IEnumerator MoveSequence(int spaces, TileData[] allTiles)
    {
        isMoving = true;

        for (int i = 0; i < spaces; i++)
        {
            int nextTile = (playerData.currentTileIndex + 1) % 40;
            if (nextTile < 0 || nextTile >= allTiles.Length || allTiles[nextTile] == null) break;

            playerData.currentTileIndex = nextTile;

            Vector3 finalPos = GetFinalPositionOnTile(allTiles[nextTile].worldPosition);
            yield return StartCoroutine(MoveToPosition(finalPos));

            OnTilePassed?.Invoke(allTiles[nextTile]);

            if (nextTile == 0 && i > 0)
                OnPassedGO?.Invoke();

            yield return new WaitForSeconds(0.05f);
        }

        if (playerData.currentTileIndex >= 0 && playerData.currentTileIndex < allTiles.Length)
            OnTileLanded?.Invoke(allTiles[playerData.currentTileIndex]);

        isMoving = false;
    }

    private IEnumerator MoveToPosition(Vector3 destination)
    {
        Vector3 start = transform.position;
        float distance = Vector3.Distance(start, destination);
        float duration = Mathf.Max(distance / moveSpeed, 0.05f);
        float elapsed = 0f;

        Vector3 dir = (destination - start).normalized;
        if (dir != Vector3.zero)
            transform.rotation = Quaternion.LookRotation(dir);

        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.Clamp01(elapsed / duration);

            Vector3 groundPos = Vector3.Lerp(start, destination, t);
            float hop = Mathf.Sin(t * Mathf.PI) * hopHeight;

            transform.position = groundPos + Vector3.up * (heightOffset + hop);
            yield return null;
        }

        transform.position = destination + Vector3.up * heightOffset;
    }

    // ── Tile occupancy offset ─────────────────────────────────────────────────

    private Vector3 GetFinalPositionOnTile(Vector3 tileCenter)
    {
        int others = 0;
        foreach (PlayerMovement p in FindObjectsOfType<PlayerMovement>())
        {
            if (p == this) continue;
            if (Vector3.Distance(p.transform.position, tileCenter) < occupancyCheckRadius)
                others++;
        }

        if (others == 0) return tileCenter;

        Vector3[] offsets =
        {
            Vector3.right   * playerOffset,
            Vector3.left    * playerOffset,
            Vector3.forward * playerOffset,
        };

        if (others - 1 < offsets.Length) return tileCenter + offsets[others - 1];

        float angle = others * 90f * Mathf.Deg2Rad;
        return tileCenter + new Vector3(Mathf.Cos(angle), 0, Mathf.Sin(angle)) * playerOffset;
    }
}