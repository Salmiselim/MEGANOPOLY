using System.Collections;
using Unity.Collections;
using Unity.Netcode;
using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// DA-compatible bridge that ships the board's relay join code from the
/// session owner to every other peer in the lobby. Uses a NetworkVariable
/// (which DA supports natively) — NGO's CustomMessaging is not usable for
/// peer-to-peer in Distributed Authority mode.
///
/// SETUP (one-time, in the Lobby scene):
///   1. Find the GameObject that has the LobbyRelayManager script on it.
///   2. Add a NetworkObject component to it (NGO → NetworkObject).
///   3. Add this script (BoardSessionBroadcaster) to it.
///   4. Save the scene.
/// That's it. The NetworkObject auto-spawns when VRMP starts the lobby session.
/// </summary>
public class BoardSessionBroadcaster : NetworkBehaviour
{
    public static BoardSessionBroadcaster Instance { get; private set; }

    // NetworkVariable: owner-write, everyone-read. The session owner sets
    // the value, every client sees the change via OnValueChanged.
    private readonly NetworkVariable<FixedString64Bytes> _joinCode = new(
        readPerm: NetworkVariableReadPermission.Everyone,
        writePerm: NetworkVariableWritePermission.Owner);

    [Tooltip("Scene to load when a join code arrives. Must match LobbyRelayManager.gameSceneName.")]
    [SerializeField] private string boardSceneName = "SampleScene";

    [Tooltip("Time the client waits after receiving the join code before " +
             "shutting down VRMP and loading the board scene.")]
    [SerializeField] private float clientTransitionDelay = 0.2f;

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else Destroy(gameObject);
    }

    public override void OnNetworkSpawn()
    {
        base.OnNetworkSpawn();
        _joinCode.OnValueChanged += OnJoinCodeChanged;
    }

    public override void OnNetworkDespawn()
    {
        _joinCode.OnValueChanged -= OnJoinCodeChanged;
        base.OnNetworkDespawn();
    }

    /// <summary>
    /// Called by the session owner (LobbyRelayManager.TryStartGame) after
    /// allocating the relay. Sets the NetworkVariable — NGO replicates the
    /// change to every other peer.
    /// </summary>
    public bool PublishJoinCode(string joinCode)
    {
        if (!IsSpawned)
        {
            Debug.LogError("[Broadcaster] Not spawned. Did you forget to add NetworkObject?");
            return false;
        }

        if (!IsOwner)
        {
            Debug.LogError("[Broadcaster] Only the session owner (owner of this NetworkObject) " +
                           "can publish the join code. Local IsOwner=False.");
            return false;
        }

        if (string.IsNullOrEmpty(joinCode) || joinCode.Length > 63)
        {
            Debug.LogError($"[Broadcaster] Invalid join code '{joinCode}'.");
            return false;
        }

        _joinCode.Value = new FixedString64Bytes(joinCode);
        Debug.Log($"[Broadcaster] Published join code '{joinCode}' to NetworkVariable.");
        return true;
    }

    private void OnJoinCodeChanged(FixedString64Bytes previous, FixedString64Bytes current)
    {
        if (current.Length == 0) return;
        if (IsOwner) return; // The host published it; only non-owners react.

        string code = current.ToString();
        Debug.Log($"[Broadcaster] Client received join code '{code}' via NetworkVariable.");

        GameContext.IsHost   = false;
        GameContext.JoinCode = code;

        StartCoroutine(TransitionToBoard());
    }

    private IEnumerator TransitionToBoard()
    {
        yield return new WaitForSeconds(clientTransitionDelay);

        var nm = NetworkManager.Singleton;
        if (nm != null && nm.IsListening)
        {
            Debug.Log("[Broadcaster] Client shutting down VRMP session.");
            nm.Shutdown();
        }
        yield return null;

        Debug.Log($"[Broadcaster] Client loading board scene '{boardSceneName}'.");
        SceneManager.LoadScene(boardSceneName, LoadSceneMode.Single);
    }
}
