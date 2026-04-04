using System.Collections;
using UnityEngine;
using UnityEngine.Events;

/// <summary>
/// Simple PlayerMovement - offsets players if tile position is occupied
/// </summary>
public class PlayerMovement : MonoBehaviour
{
    [Header("Movement Settings")]
    [SerializeField] private float moveSpeed = 5f;
    [SerializeField] private float rotationSpeed = 10f;

    [Header("Visual Effects")]
    [SerializeField] private float hopHeight = 0.3f;
    [SerializeField] private float heightOffset = 0.1f;

    [Header("Multi-Player Spacing")]
    [SerializeField] private float occupancyCheckRadius = 2f;
    [SerializeField] private float playerOffset = 8f;

    // State
    private PlayerData playerData;
    private bool isMoving = false;

    // Events
    public UnityEvent<TileData> OnTilePassed = new UnityEvent<TileData>();
    public UnityEvent<TileData> OnTileLanded = new UnityEvent<TileData>();
    public UnityEvent OnPassedGO = new UnityEvent();

    public void Initialize(PlayerData data)
    {
        playerData = data;
    }

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
        Vector3 finalPos = GetFinalPositionOnTile(allTiles[tileIndex].worldPosition);
        transform.position = finalPos + Vector3.up * heightOffset;
    }

    private IEnumerator MoveSequence(int spaces, TileData[] allTiles)
    {
        isMoving = true;

        for (int i = 0; i < spaces; i++)
        {
            int nextTile = (playerData.currentTileIndex + 1) % 40;

            if (nextTile < 0 || nextTile >= allTiles.Length) break;
            if (allTiles[nextTile] == null) break;

            playerData.currentTileIndex = nextTile;

            // Get tile position with offset if occupied
            Vector3 tilePos = allTiles[nextTile].worldPosition;
            Vector3 finalPos = GetFinalPositionOnTile(tilePos);

            // Move to position
            yield return StartCoroutine(MoveToPosition(finalPos));

            OnTilePassed?.Invoke(allTiles[nextTile]);

            if (nextTile == 0 && i > 0)
            {
                OnPassedGO?.Invoke();
            }

            yield return new WaitForSeconds(0.05f);
        }

        if (playerData.currentTileIndex >= 0 && playerData.currentTileIndex < allTiles.Length)
        {
            OnTileLanded?.Invoke(allTiles[playerData.currentTileIndex]);
        }

        isMoving = false;
    }

    /// <summary>
    /// Simple check: if tile center is occupied, offset to the side
    /// </summary>
    private Vector3 GetFinalPositionOnTile(Vector3 tileCenter)
    {
        // Find all other players
        PlayerMovement[] allPlayers = FindObjectsOfType<PlayerMovement>();

        int playersOnThisTile = 0;

        // Count how many players are at this tile position
        foreach (PlayerMovement player in allPlayers)
        {
            if (player == this) continue; // Skip myself

            float distance = Vector3.Distance(player.transform.position, tileCenter);
            if (distance < occupancyCheckRadius)
            {
                playersOnThisTile++;
            }
        }

        // If tile is empty, use center
        if (playersOnThisTile == 0)
        {
            return tileCenter;
        }

        // Otherwise offset based on count
        // Pattern: 1st player offset right, 2nd left, 3rd forward
        Vector3[] offsets = new Vector3[]
        {
            Vector3.right * playerOffset,    // 1st extra player
            Vector3.left * playerOffset,     // 2nd extra player  
            Vector3.forward * playerOffset   // 3rd extra player
        };

        int index = playersOnThisTile - 1;
        if (index < offsets.Length)
        {
            return tileCenter + offsets[index];
        }

        // Fallback: circle pattern
        float angle = playersOnThisTile * 90f * Mathf.Deg2Rad;
        return tileCenter + new Vector3(Mathf.Cos(angle), 0, Mathf.Sin(angle)) * playerOffset;
    }

    private IEnumerator MoveToPosition(Vector3 destination)
    {
        Vector3 start = transform.position;
        float distance = Vector3.Distance(start, destination);
        float duration = distance / moveSpeed;
        float elapsed = 0f;

        // Look at target
        Vector3 direction = (destination - start).normalized;
        if (direction != Vector3.zero)
        {
            transform.rotation = Quaternion.LookRotation(direction);
        }

        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.Clamp01(elapsed / duration);

            // Ground position
            Vector3 groundPos = Vector3.Lerp(start, destination, t);

            // Hop arc
            float hop = Mathf.Sin(t * Mathf.PI) * hopHeight;

            transform.position = groundPos + Vector3.up * (heightOffset + hop);

            yield return null;
        }

        transform.position = destination + Vector3.up * heightOffset;
    }

    public bool IsMoving()
    {
        return isMoving;
    }
}