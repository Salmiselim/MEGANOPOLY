using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.SceneManagement;
using Unity.Netcode;

[System.Serializable]
public class MinigameEndedEvent : UnityEvent<int, int>
{
}

/// <summary>
/// Server-authoritative minigame transition controller.
///
/// Persists across scene loads (DontDestroyOnLoad).
/// Uses NetworkManager.SceneManager to load scenes on ALL clients at once (Single mode).
///
/// FLOW:
///   CompleteGameManager.HandleProperty (unowned tile)
///     → TriggerMinigameChallenge → RegisterClientPlayerMap → StartMinigame
///     → NetworkManager.SceneManager.LoadScene(minigameScene, Single)
///         [all clients land in minigame scene]
///   Minigame scene calls MinigameOrchestrator.FinishMinigame(winnerClientId, prize)
///     → resolves clientId → board player index via stored map
///     → NetworkManager.SceneManager.LoadScene(boardScene, Single)
///         [all clients land back in board scene]
///     → 1s delay → OnMinigameEnded fires → CompleteGameManager.OnMinigameEnded
/// </summary>
public class MinigameOrchestrator : MonoBehaviour
{
    public static MinigameOrchestrator Instance { get; private set; }

    // ── Inspector ─────────────────────────────────────────────────────────────

    [Header("Events")]
    public MinigameEndedEvent OnMinigameEnded = new MinigameEndedEvent();

    [Header("Scene Names")]
    [Tooltip("The main board scene to return to after a minigame ends.")]
    [SerializeField] private string boardSceneName = "SampleScene";

    [Tooltip("For testing: ALL property tiles will launch this minigame scene.")]
    [SerializeField] private string testMinigameScene = "RPS+SFX";

    [Header("Settings")]
    [SerializeField] private bool debugMode = true;

    // ── Pending result (persisted across scene boundary) ──────────────────────

    private int  _pendingWinnerId  = -1;
    private int  _pendingPrize     = 0;

    // ── State ─────────────────────────────────────────────────────────────────

    private bool _minigameRunning  = false;
    private bool _returningToBoard = false;

    // ── clientId → board player index map ─────────────────────────────────────
    // Built in TriggerMinigameChallenge (board scene) so minigame scenes can
    // report a Netcode clientId and we resolve it to a board player index here.

    private readonly Dictionary<ulong, int> _clientIdToPlayerIndex = new();

    // ── Lifecycle ─────────────────────────────────────────────────────────────

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    // ── Public API ────────────────────────────────────────────────────────────

    /// <summary>
    /// Store the clientId → board player index mapping before loading the minigame scene.
    /// Called by CompleteGameManager.TriggerMinigameChallenge on the server.
    /// </summary>
    public void RegisterClientPlayerMap(Dictionary<ulong, int> map)
    {
        _clientIdToPlayerIndex.Clear();
        foreach (var kv in map)
            _clientIdToPlayerIndex[kv.Key] = kv.Value;

        if (debugMode)
            foreach (var kv in _clientIdToPlayerIndex)
                Debug.Log($"[MinigameOrchestrator] Map: clientId={kv.Key} → playerIndex={kv.Value}");
    }

    /// <summary>
    /// Launches the minigame. Must be called on the server.
    /// Loads testMinigameScene on ALL connected clients via NetworkManager.
    /// </summary>
    public void StartMinigame(int minigameType, string propertyName,
        PlayerData challenger, int prizeAmount, int challengerIndex = -1)
    {
        if (!IsServerSide())
        {
            Debug.LogWarning("[MinigameOrchestrator] StartMinigame called on a non-server — ignoring.");
            return;
        }

        if (_minigameRunning)
        {
            Debug.LogWarning("[MinigameOrchestrator] Minigame already running!");
            return;
        }

        _minigameRunning = true;
        Time.timeScale   = 1f; // safety reset in case PauseGame was called

        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] START  type={minigameType}  property={propertyName}" +
                      $"  challenger={challenger?.playerName ?? "?"}  prize={prizeAmount}");

        // Subscribe BEFORE loading so we catch the board-scene-loaded event later
        NetworkManager.Singleton.SceneManager.OnLoadEventCompleted += OnSceneLoadCompleted;

        NetworkManager.Singleton.SceneManager.LoadScene(testMinigameScene, LoadSceneMode.Single);
    }

    /// <summary>
    /// Called by a minigame scene when the match is over. Server only.
    /// winnerClientId – Netcode clientId of the winner, or ulong.MaxValue for a tie.
    /// Use this overload from scenes that track clientIds (e.g. RPS).
    /// </summary>
    public static void FinishMinigame(ulong winnerClientId, int prizeAmount)
    {
        if (Instance == null)
        {
            Debug.LogWarning("[MinigameOrchestrator] FinishMinigame called but no instance!");
            return;
        }

        if (!IsServerSide())
        {
            Debug.LogWarning("[MinigameOrchestrator] FinishMinigame must be called on the server.");
            return;
        }

        int playerIndex = -1;
        if (winnerClientId != ulong.MaxValue)
        {
            if (Instance._clientIdToPlayerIndex.TryGetValue(winnerClientId, out int idx))
                playerIndex = idx;
            else
                Debug.LogWarning($"[MinigameOrchestrator] clientId {winnerClientId} not in map — treating as no winner.");
        }

        if (Instance.debugMode)
            Debug.Log($"[MinigameOrchestrator] FinishMinigame(ulong): clientId={winnerClientId} → playerIndex={playerIndex}");

        Instance.HandleMinigameFinished(playerIndex, prizeAmount);
    }

    /// <summary>
    /// Overload for scripts that already know the board player index directly
    /// (MinigameIntegration, SimpleMinigameController). Pass -1 for tie/no winner.
    /// Server only.
    /// </summary>
    public static void FinishMinigame(int winnerPlayerIndex, int prizeAmount)
    {
        if (Instance == null)
        {
            Debug.LogWarning("[MinigameOrchestrator] FinishMinigame called but no instance!");
            return;
        }

        if (!IsServerSide())
        {
            Debug.LogWarning("[MinigameOrchestrator] FinishMinigame must be called on the server.");
            return;
        }

        if (Instance.debugMode)
            Debug.Log($"[MinigameOrchestrator] FinishMinigame(int): playerIndex={winnerPlayerIndex}  prize={prizeAmount}");

        Instance.HandleMinigameFinished(winnerPlayerIndex, prizeAmount);
    }

    // ── Private: return to board ──────────────────────────────────────────────

    private void HandleMinigameFinished(int winnerPlayerIndex, int prizeAmount)
    {
        if (!_minigameRunning)
        {
            Debug.LogWarning("[MinigameOrchestrator] FinishMinigame — no minigame was running!");
            return;
        }

        _pendingWinnerId  = winnerPlayerIndex;
        _pendingPrize     = prizeAmount;
        _returningToBoard = true;

        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] FINISH  playerIndex={winnerPlayerIndex}  prize={prizeAmount}" +
                      $"  → loading '{boardSceneName}'");

        NetworkManager.Singleton.SceneManager.LoadScene(boardSceneName, LoadSceneMode.Single);
    }

    // ── Scene load callback ───────────────────────────────────────────────────

    private void OnSceneLoadCompleted(string sceneName, LoadSceneMode loadSceneMode,
        List<ulong> clientsCompleted, List<ulong> clientsTimedOut)
    {
        if (!_returningToBoard)          return;
        if (sceneName != boardSceneName) return;

        NetworkManager.Singleton.SceneManager.OnLoadEventCompleted -= OnSceneLoadCompleted;

        _returningToBoard = false;
        _minigameRunning  = false;

        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] Board scene loaded on all clients. Firing OnMinigameEnded in 1 s…");

        StartCoroutine(FireEndedAfterDelay(_pendingWinnerId, _pendingPrize));
    }

    private IEnumerator FireEndedAfterDelay(int winnerId, int prizeAmount)
    {
        yield return new WaitForSeconds(1f);

        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] → OnMinigameEnded(winner={winnerId}, prize={prizeAmount})");

        OnMinigameEnded.Invoke(winnerId, prizeAmount);

        _pendingWinnerId = -1;
        _pendingPrize    = 0;
        _clientIdToPlayerIndex.Clear();
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private static bool IsServerSide() =>
        NetworkManager.Singleton != null && NetworkManager.Singleton.IsServer;

    public string TestMinigameScene => testMinigameScene;

    /// <summary>The playerId of the player who triggered the current/last mini-game.</summary>
    public int LastChallengerId => _pendingWinnerId;
}
