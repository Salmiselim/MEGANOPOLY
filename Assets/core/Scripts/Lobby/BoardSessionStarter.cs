using System.Collections;
using Unity.Netcode;
using Unity.Netcode.Transports.UTP;
using Unity.Services.Multiplayer;     // AllocationUtils.ToRelayServerData
using Unity.Services.Relay;
using Unity.Services.Relay.Models;
using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Drop this on a GameObject in the BOARD scene (SampleScene). On scene load it:
///   1. Destroys the VRMP NetworkManager (DA topology) that carried over from the lobby.
///   2. Creates a fresh NetworkManager + UnityTransport with ClientServer topology.
///   3. Configures the transport with the Relay allocation from GameContext.
///   4. Starts as Host (if GameContext.IsHost) or Client.
///
/// On failure it returns to the lobby scene with cleared GameContext.
/// </summary>
public class BoardSessionStarter : MonoBehaviour
{
    [Tooltip("Scene to return to if the board session fails to start.")]
    [SerializeField] private string lobbySceneOnFailure = "Lobby";

    [Tooltip("Seconds the client will wait for the relay connection to complete before giving up.")]
    [SerializeField] private float clientConnectionTimeout = 15f;

    [Tooltip("Relay connection type. \"dtls\" is encrypted, \"udp\" is not.")]
    [SerializeField] private string relayConnectionType = "dtls";

    [Header("Board NetworkPrefabs")]
    [Tooltip("Every prefab that CompleteGameManager (or any board script) spawns via NGO. " +
             "Drag them here so the fresh NetworkManager can resolve them on both sides. " +
             "The player prefab used by CompleteGameManager must be in this list.")]
    [SerializeField] private GameObject[] boardNetworkPrefabs = new GameObject[0];

    private void Start()
    {
        // Safety guard: only run when the lobby has actually transitioned us here.
        if (!GameContext.IsHost && string.IsNullOrEmpty(GameContext.JoinCode))
        {
            string scene = gameObject.scene.name;
            Debug.LogWarning(
                $"[BoardSession] GameContext is empty (IsHost=false, JoinCode=''). " +
                $"This component is on '{gameObject.name}' in scene '{scene}'. " +
                $"It will sit idle — make sure this script is in SampleScene only " +
                $"and that you pressed Start in the lobby.");
            enabled = false;
            return;
        }

        StartCoroutine(BootSession());
    }

    private IEnumerator BootSession()
    {
        // ── Step 1: Destroy the VRMP NetworkManager ───────────────────────────
        // The VRMP NetworkManager is configured for Distributed Authority topology.
        // We cannot reliably switch it to ClientServer at runtime because the DA
        // transport keeps internal state that causes a topology-mismatch shutdown
        // even after we change NetworkConfig.NetworkTopology. The only reliable fix
        // is to destroy it entirely and create a fresh ClientServer NetworkManager.
        var oldNm = NetworkManager.Singleton;
        if (oldNm != null)
        {
            if (oldNm.IsListening)
            {
                Debug.Log("[BoardSession] Shutting down residual VRMP session.");
                oldNm.Shutdown();
                yield return null;
            }
            Debug.Log("[BoardSession] Destroying VRMP NetworkManager.");
            Destroy(oldNm.gameObject);
            // Wait two frames: one for Destroy, one for the singleton to clear.
            yield return null;
            yield return null;
        }

        // ── Step 2: Create a fresh NetworkManager (ClientServer topology) ─────
        var nmGo = new GameObject("BoardNetworkManager");
        var nm   = nmGo.AddComponent<NetworkManager>();
        var transport = nmGo.AddComponent<UnityTransport>();

        // NetworkConfig is null when NetworkManager is added via AddComponent (no
        // serialized inspector data). Build one from scratch.
        nm.NetworkConfig = new NetworkConfig();
        nm.NetworkConfig.NetworkTransport     = transport;
        nm.NetworkConfig.NetworkTopology      = NetworkTopologyTypes.ClientServer;
        // Scene management ON so NGO syncs in-scene NetworkObjects (CompleteGameManager,
        // dice, etc.) from host to client. Both peers loaded SampleScene independently
        // before NGO started, so the sync only confirms matching scene state — no scene
        // reload. The previous hash-mismatch issue was caused by the carried-over VRMP
        // NetworkManager; our fresh one starts with no stale scene state.
        nm.NetworkConfig.EnableSceneManagement = true;
        nm.NetworkConfig.ForceSamePrefabs     = false;

        // Register every board NetworkPrefab so NGO can spawn/receive them.
        int prefabCount = 0;
        foreach (var prefab in boardNetworkPrefabs)
        {
            if (prefab != null && prefab.GetComponent<NetworkObject>() != null)
            {
                nm.NetworkConfig.Prefabs.Add(new NetworkPrefab { Prefab = prefab });
                prefabCount++;
            }
        }

        Debug.Log($"[BoardSession] Fresh NetworkManager created. " +
                  $"Topology={nm.NetworkConfig.NetworkTopology}  " +
                  $"RegisteredPrefabs={prefabCount}");

        // ── Step 2.5: Rebind in-scene NetworkObjects to the fresh NM ──────────
        // SampleScene's in-scene NetworkObjects (CompleteGameManager, dice, …)
        // ran Awake while the OLD VRMP NetworkManager was still alive. Reset
        // their NetworkManagerOwner (internal field) AND explicitly mark them
        // as scene objects so the host's SpawnSweep claims them.
        var activeScene = UnityEngine.SceneManagement.SceneManager.GetActiveScene();
        var sceneObjects = FindObjectsByType<NetworkObject>(FindObjectsInactive.Include, FindObjectsSortMode.None);
        var ownerField = typeof(NetworkObject).GetField("NetworkManagerOwner",
            System.Reflection.BindingFlags.Instance |
            System.Reflection.BindingFlags.NonPublic |
            System.Reflection.BindingFlags.Public);
        int reboundActive = 0, reboundDDOL = 0;
        var rebindNames = new System.Text.StringBuilder();
        foreach (var no in sceneObjects)
        {
            if (no == null) continue;
            if (ownerField != null) ownerField.SetValue(no, nm);

            bool inActiveScene = no.gameObject.scene == activeScene;
            if (inActiveScene)
            {
                no.SetSceneObjectStatus(true);
                reboundActive++;
                rebindNames.Append($"  ✓ {no.gameObject.name}\n");
            }
            else
            {
                reboundDDOL++;
                rebindNames.Append($"  · DDOL {no.gameObject.name} (skipped scene-flag)\n");
            }
        }
        Debug.Log($"[BoardSession] Rebound {reboundActive} active-scene + {reboundDDOL} DDOL " +
                  $"NetworkObject(s) to fresh NM (reflection {(ownerField != null ? "OK" : "FAILED")}):\n{rebindNames}");

        // Give the engine one frame so the NM is fully initialised before we
        // hand it relay data and call StartHost/StartClient.
        yield return null;

        // ── Step 3: Configure relay & start ───────────────────────────────────
        if (GameContext.IsHost)
            yield return StartAsHost(nm, transport);
        else
            yield return StartAsClient(nm, transport);
    }

    private IEnumerator StartAsHost(NetworkManager nm, UnityTransport transport)
    {
        if (GameContext.HostAllocation == null)
        {
            Debug.LogError("[BoardSession] IsHost=true but GameContext.HostAllocation is null.");
            FailAndReturnToLobby();
            yield break;
        }

        bool started;
        try
        {
            var serverData = GameContext.HostAllocation.ToRelayServerData(relayConnectionType);
            transport.SetRelayServerData(serverData);
            started = nm.StartHost();
        }
        catch (System.Exception e)
        {
            Debug.LogError($"[BoardSession] Host start threw: {e.Message}");
            FailAndReturnToLobby();
            yield break;
        }

        if (!started)
        {
            Debug.LogError("[BoardSession] StartHost returned false.");
            FailAndReturnToLobby();
            yield break;
        }

        Debug.Log($"[BoardSession] Host started. JoinCode={GameContext.JoinCode}  " +
                  $"SpawnedSceneObjects={nm.SpawnManager?.SpawnedObjectsList?.Count ?? -1}");

        // List the objects that NGO actually spawned so we can see whether
        // CompleteGameManager's NetworkObject is in there. If it isn't, that
        // explains the missing OnNetworkSpawn log.
        if (nm.SpawnManager?.SpawnedObjectsList != null)
        {
            var sb = new System.Text.StringBuilder("[BoardSession] Spawned objects after StartHost:\n");
            foreach (var so in nm.SpawnManager.SpawnedObjectsList)
            {
                if (so == null) continue;
                sb.Append($"  • {so.gameObject.name}  IsSpawned={so.IsSpawned}  IsSceneObject={so.IsSceneObject}\n");
            }
            Debug.Log(sb.ToString());
        }

        var cgm = CompleteGameManager.Instance;
        Debug.Log($"[BoardSession] CompleteGameManager.Instance={(cgm != null ? cgm.gameObject.name : "NULL")}  " +
                  $"IsSpawned={(cgm != null ? cgm.IsSpawned.ToString() : "?")}");
    }

    private IEnumerator StartAsClient(NetworkManager nm, UnityTransport transport)
    {
        const float waitForJoinCode = 3f;
        float elapsed = 0f;
        while (string.IsNullOrEmpty(GameContext.JoinCode) && elapsed < waitForJoinCode)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        if (string.IsNullOrEmpty(GameContext.JoinCode))
        {
            Debug.LogError($"[BoardSession] JoinCode still empty after {waitForJoinCode}s.");
            FailAndReturnToLobby();
            yield break;
        }

        Debug.Log($"[BoardSession] Client starting with JoinCode='{GameContext.JoinCode}'.");

        var joinTask = RelayService.Instance.JoinAllocationAsync(GameContext.JoinCode);
        while (!joinTask.IsCompleted) yield return null;

        if (joinTask.IsFaulted || joinTask.Result == null)
        {
            Debug.LogError($"[BoardSession] JoinAllocation failed: {joinTask.Exception?.GetBaseException().Message}");
            FailAndReturnToLobby();
            yield break;
        }

        bool started;
        try
        {
            var serverData = joinTask.Result.ToRelayServerData(relayConnectionType);
            transport.SetRelayServerData(serverData);
            started = nm.StartClient();
        }
        catch (System.Exception e)
        {
            Debug.LogError($"[BoardSession] Client start threw: {e.Message}");
            FailAndReturnToLobby();
            yield break;
        }

        if (!started)
        {
            Debug.LogError("[BoardSession] StartClient returned false.");
            FailAndReturnToLobby();
            yield break;
        }

        float connectElapsed = 0f;
        while (!nm.IsConnectedClient && connectElapsed < clientConnectionTimeout)
        {
            connectElapsed += Time.deltaTime;
            yield return null;
        }

        if (!nm.IsConnectedClient)
        {
            Debug.LogError("[BoardSession] Client connect timed out.");
            nm.Shutdown();
            FailAndReturnToLobby();
            yield break;
        }

        Debug.Log("[BoardSession] Client connected.");
    }

    private void FailAndReturnToLobby()
    {
        GameContext.Clear();
        if (!string.IsNullOrEmpty(lobbySceneOnFailure))
            SceneManager.LoadScene(lobbySceneOnFailure);
    }
}
