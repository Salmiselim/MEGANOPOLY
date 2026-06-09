using System.Collections;
using System.Collections.Generic;
using Unity.Netcode;
using UnityEngine;

/// <summary>
/// Lightweight player spawner for the minigame TEST scene.
///
/// This is the stripped-down sibling of CompleteGameManager: it reuses the
/// exact same proven flow (despawn carried-over lobby avatars, then spawn one
/// playerPrefab per connected client at a spawn point) WITHOUT starting a
/// Monopoly game. Drop it on a GameObject in the test scene.
///
/// FLOW (mirrors the board):
///   Lobby Start → BoardSessionStarter rebuilds a ClientServer NetworkManager
///   in this scene → host StartHost / clients StartClient → this component's
///   OnNetworkSpawn runs on the host → waits until every expected client is
///   connected → spawns a player rig for each one.
///
/// Setup:
///   1. Put this on a GameObject in MinigameTestScene that ALSO has a
///      NetworkObject (it must be an in-scene NetworkObject so OnNetworkSpawn
///      fires — same as CompleteGameManager).
///   2. Assign playerPrefab = the same VR-rig prefab CompleteGameManager uses.
///   3. Make sure that prefab is also in BoardSessionStarter's
///      "Board NetworkPrefabs" list so NGO can spawn it on both peers.
///   4. (Optional) Drop PlayerSpawnPoint objects in the scene for seating.
/// </summary>
public class TestScenePlayerSpawner : NetworkBehaviour
{
    [Header("Player")]
    [Tooltip("Same VR-rig prefab CompleteGameManager spawns (XR Origin + hands " +
             "+ NetworkObject). Must also be registered in BoardSessionStarter.")]
    [SerializeField] private GameObject playerPrefab;

    [Header("Spawn Points")]
    [Tooltip("Optional. If left empty the spawner auto-finds PlayerSpawnPoint " +
             "objects in the scene, then falls back to a procedural line.")]
    [SerializeField] private PlayerSpawnPoint[] spawnPoints = new PlayerSpawnPoint[4];

    [Tooltip("Spacing used for the procedural fallback when there are not " +
             "enough PlayerSpawnPoints.")]
    [SerializeField] private float fallbackSpacing = 3f;

    [Header("Timing")]
    [Tooltip("How long the host waits for all expected clients before spawning anyway.")]
    [SerializeField] private float maxWaitForClientsSeconds = 20f;

    [Tooltip("Grace period after all clients connect, before spawning.")]
    [SerializeField] private float clientGraceSeconds = 0.75f;

    private bool IsAuthority()
    {
        var nm = NetworkManager.Singleton;
        return nm != null && nm.IsHost;
    }

    public override void OnNetworkSpawn()
    {
        Debug.Log($"[TestSpawner] OnNetworkSpawn ★ LocalClient={NetworkManager.Singleton?.LocalClientId} " +
                  $"IsAuthority={IsAuthority()} prefabAssigned={(playerPrefab != null)}");

        // Only the host spawns. Clients just receive the spawned NetworkObjects.
        if (!IsAuthority()) return;

        AutoFindSpawnPoints();
        StartCoroutine(SpawnWhenReady());
    }

    private IEnumerator SpawnWhenReady()
    {
        var nm = NetworkManager.Singleton;
        int expected = Mathf.Max(1, GameContext.ExpectedPlayerCount);

        float elapsed = 0f;
        while (elapsed < maxWaitForClientsSeconds)
        {
            if (nm == null) yield break;
            int connected = nm.ConnectedClientsList?.Count ?? 0;
            if (connected >= expected)
            {
                Debug.Log($"[TestSpawner] All expected players connected ({connected}/{expected}).");
                break;
            }
            elapsed += Time.deltaTime;
            yield return null;
        }

        // Grace so just-connected clients settle before we spawn for them.
        yield return new WaitForSeconds(clientGraceSeconds);

        if (playerPrefab == null)
        {
            Debug.LogError("[TestSpawner] playerPrefab not assigned — cannot spawn players.");
            yield break;
        }

        // Kill any lobby avatars that survived the scene transition (same fix
        // CompleteGameManager applies). Their references to the destroyed lobby
        // rig are broken, so they spam MissingReferenceException otherwise.
        DespawnLobbyAvatars();

        var clients = new List<ulong>(NetworkManager.Singleton.ConnectedClientsIds);
        Debug.Log($"[TestSpawner] Spawning {clients.Count} player rig(s).");

        for (int i = 0; i < clients.Count; i++)
        {
            ulong ownerClientId = clients[i];
            Vector3 pos = GetSpawnPosition(i);
            Quaternion rot = GetSpawnRotation(i);

            GameObject rig = Instantiate(playerPrefab, pos, rot);
            rig.name = $"TestPlayer_{i}_client{ownerClientId}";

            var netObj = rig.GetComponent<NetworkObject>();
            if (netObj == null)
            {
                Debug.LogError("[TestSpawner] playerPrefab is missing NetworkObject!");
                Destroy(rig);
                continue;
            }

            netObj.SpawnWithOwnership(ownerClientId, true);
            Debug.Log($"[TestSpawner] Spawned player {i} for client {ownerClientId} at {pos}.");
        }
    }

    private void DespawnLobbyAvatars()
    {
        var orphans = FindObjectsByType<XRMultiplayer.XRINetworkPlayer>(FindObjectsSortMode.None);
        foreach (var p in orphans)
        {
            if (p == null) continue;
            var no = p.NetworkObject;
            if (no != null && no.IsSpawned)
            {
                try { no.Despawn(true); }
                catch (System.Exception e) { Debug.LogWarning($"[TestSpawner] Despawn failed: {e.Message}"); }
            }
            else if (p.gameObject != null)
            {
                Destroy(p.gameObject);
            }
        }
    }

    private void AutoFindSpawnPoints()
    {
        bool inspectorAssigned = spawnPoints != null && spawnPoints.Length > 0 && spawnPoints[0] != null;
        if (inspectorAssigned) return;

        var found = FindObjectsByType<PlayerSpawnPoint>(FindObjectsSortMode.None);
        if (found.Length == 0)
        {
            Debug.LogWarning("[TestSpawner] No PlayerSpawnPoint in scene — using procedural spawn.");
            return;
        }
        System.Array.Sort(found, (a, b) => a.playerIndex.CompareTo(b.playerIndex));
        spawnPoints = found;
        Debug.Log($"[TestSpawner] Auto-found {found.Length} spawn point(s).");
    }

    private Transform GetSpawnTransform(int playerIndex)
    {
        if (spawnPoints == null || spawnPoints.Length == 0) return null;
        foreach (var sp in spawnPoints)
            if (sp != null && sp.playerIndex == playerIndex) return sp.transform;
        if (playerIndex < spawnPoints.Length && spawnPoints[playerIndex] != null)
            return spawnPoints[playerIndex].transform;
        return null;
    }

    private Vector3 GetSpawnPosition(int playerIndex)
    {
        Transform t = GetSpawnTransform(playerIndex);
        if (t != null) return t.position;
        // Procedural fallback: a line along X.
        return new Vector3(playerIndex * fallbackSpacing, 0f, 0f);
    }

    private Quaternion GetSpawnRotation(int playerIndex)
    {
        Transform t = GetSpawnTransform(playerIndex);
        return t != null ? t.rotation : Quaternion.identity;
    }
}
