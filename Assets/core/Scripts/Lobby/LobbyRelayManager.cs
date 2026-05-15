using System.Collections.Generic;
using TMPro;
using Unity.Netcode;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using XRMultiplayer;

/// <summary>
/// Handles the ready-up and start-game flow in the lobby.
///
/// The relay/lobby connection itself is handled by the existing Connection Canvas
/// (XRINetworkGameManager + SessionManager). This script only manages:
///   - Ready button: toggles the local player's ready state
///   - Start button: visible only to the host, enabled only when all players are ready
///   - UI: live player list with ready indicators, player count
///
/// Setup: drag the two 3D XRSimpleInteractable buttons and any UI text references
/// into the Inspector fields.
/// </summary>
public class LobbyRelayManager : MonoBehaviour
{
    public static LobbyRelayManager Instance { get; private set; }

    [Header("3D Buttons — drag XRSimpleInteractable objects")]
    [Tooltip("Any player presses this to toggle their ready state.")]
    [SerializeField] private XRSimpleInteractable readyButton;

    [Tooltip("Host-only. Active when all players are ready and min player count is met.")]
    [SerializeField] private XRSimpleInteractable startButton;

    [Header("Ready Button Visual Feedback")]
    [Tooltip("Renderer on the ready button — tinted green when YOU are ready.")]
    [SerializeField] private Renderer readyButtonRenderer;
    [SerializeField] private Color readyColor    = new Color(0.2f, 0.8f, 0.2f);
    [SerializeField] private Color notReadyColor = new Color(0.8f, 0.2f, 0.2f);

    [Header("Start Button Visual Feedback")]
    [Tooltip("Renderer on the start button — tinted green when all players are ready.")]
    [SerializeField] private Renderer startButtonRenderer;
    [SerializeField] private Color startActiveColor   = new Color(0.2f, 0.8f, 0.2f);
    [SerializeField] private Color startInactiveColor = new Color(0.4f, 0.4f, 0.4f);

    [Header("UI Text (all optional)")]
    [Tooltip("Shows each player's name and ready state.")]
    [SerializeField] private TextMeshProUGUI playerListText;

    [Tooltip("Shows connected player count, e.g. 'Players: 2 / 4'.")]
    [SerializeField] private TextMeshProUGUI playerCountText;

    [Tooltip("Hint shown below the start button when it is not yet active.")]
    [SerializeField] private TextMeshProUGUI startHintText;

    [Header("Settings")]
    [Tooltip("Minimum players required before the start button can be pressed.")]
    [SerializeField] private int minPlayers = 2;

    [SerializeField] private string gameSceneName = "SampleScene";

    // ── Private state ─────────────────────────────────────────────────────────

    // All XRINetworkPlayers currently tracked (updated when players join/leave).
    private readonly List<XRINetworkPlayer> _players = new();

    // Whether the start button is currently interactable.
    private bool _startEnabled = false;

    // ── Unity lifecycle ───────────────────────────────────────────────────────

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else Destroy(gameObject);
    }

    private void OnEnable()
    {
        if (readyButton != null)
            readyButton.selectEntered.AddListener(_ => OnReadyPressed());

        if (startButton != null)
            startButton.selectEntered.AddListener(_ => TryStartGame());

        // Listen for players joining/leaving via XRINetworkGameManager.
        if (XRINetworkGameManager.Instance != null)
            XRINetworkGameManager.Instance.OnPlayerStateChanged += OnPlayerStateChanged;

        // Also pick up any players already present when this component enables.
        foreach (var p in FindObjectsByType<XRINetworkPlayer>(FindObjectsSortMode.None))
            TrackPlayer(p);

        SetStartButtonEnabled(false);
    }

    private void OnDisable()
    {
        if (readyButton != null)
            readyButton.selectEntered.RemoveAllListeners();

        if (startButton != null)
            startButton.selectEntered.RemoveAllListeners();

        if (XRINetworkGameManager.Instance != null)
            XRINetworkGameManager.Instance.OnPlayerStateChanged -= OnPlayerStateChanged;

        UnsubscribeAllPlayers();
    }

    private void Update()
    {
        // Gather live players once per frame and pass to helpers — avoids
        // multiple FindObjectsByType calls per frame on Quest hardware.
        var live = FindObjectsByType<XRINetworkPlayer>(FindObjectsSortMode.None);
        SyncPlayerList(live);
        RefreshReadyButtonVisual();
        RefreshStartButton(live);
        RefreshUI(live);
    }

    // ── Button handlers ───────────────────────────────────────────────────────

    private void OnReadyPressed()
    {
        if (XRINetworkPlayer.LocalPlayer == null)
        {
            Debug.LogWarning("[LobbyReady] LocalPlayer not found — not connected yet.");
            return;
        }
        XRINetworkPlayer.LocalPlayer.ToggleReady();
    }

    public void TryStartGame()
    {
        if (!_startEnabled) 
        {
            Debug.Log("[LobbyReady] Cannot start game yet. Missing players or not everyone is ready.");
            return;
        }

        if (NetworkManager.Singleton == null || !NetworkManager.Singleton.IsServer)
        {
            Debug.LogWarning("[LobbyReady] OnStartPressed called on a non-host client — ignoring.");
            return;
        }

        Debug.Log("[LobbyReady] Host starting game.");
        NetworkManager.Singleton.SceneManager.LoadScene(
            gameSceneName, UnityEngine.SceneManagement.LoadSceneMode.Single);
    }

    // ── Player tracking ───────────────────────────────────────────────────────

    // Called by XRINetworkGameManager when any player joins or leaves.
    // Signature matches Action<ulong, bool>.
    private void OnPlayerStateChanged(ulong clientId, bool joined)
    {
        if (joined)
        {
            if (XRINetworkGameManager.Instance.TryGetPlayerByID(clientId, out var player))
                TrackPlayer(player);
        }
        else
        {
            // Player already removed from XRINetworkGameManager — find by clientId in our list.
            var leaving = _players.Find(p => p != null &&
                          p.NetworkObject != null &&
                          p.NetworkObject.OwnerClientId == clientId);
            if (leaving != null) UntrackPlayer(leaving);
        }
    }

    private void TrackPlayer(XRINetworkPlayer player)
    {
        if (player == null || _players.Contains(player)) return;
        _players.Add(player);
    }

    private void UntrackPlayer(XRINetworkPlayer player)
    {
        if (player == null) return;
        _players.Remove(player);
    }

    private void UnsubscribeAllPlayers() => _players.Clear();

    // ── Logic helpers ─────────────────────────────────────────────────────────

    private bool IsHost()
        => NetworkManager.Singleton != null && NetworkManager.Singleton.IsServer;

    private int ConnectedCount()
        => NetworkManager.Singleton?.ConnectedClientsList.Count ?? 0;

    private bool AllPlayersReady(XRINetworkPlayer[] live)
    {
        if (live.Length < minPlayers) return false;
        foreach (var p in live)
            if (!p.isReady.Value) return false;
        return true;
    }

    // ── Visual refresh (called every frame from Update) ───────────────────────

    private void SyncPlayerList(XRINetworkPlayer[] live)
    {
        foreach (var p in live)
            if (!_players.Contains(p)) TrackPlayer(p);
    }

    private void RefreshReadyButtonVisual()
    {
        if (readyButtonRenderer == null) return;
        bool localReady = XRINetworkPlayer.LocalPlayer != null &&
                          XRINetworkPlayer.LocalPlayer.isReady.Value;
        SetRendererColor(readyButtonRenderer, localReady ? readyColor : notReadyColor);
    }

    private void RefreshStartButton(XRINetworkPlayer[] live)
    {
        bool canStart = IsHost() && AllPlayersReady(live) && ConnectedCount() >= minPlayers;
        if (canStart != _startEnabled)
            SetStartButtonEnabled(canStart);
    }

    private void RefreshUI(XRINetworkPlayer[] live)
    {
        // Player list
        if (playerListText != null)
        {
            var sb = new System.Text.StringBuilder();
            foreach (var p in live)
            {
                string readyMark = p.isReady.Value ? "<color=#44FF44>✓ Ready</color>"
                                                    : "<color=#FF4444>Not Ready</color>";
                sb.AppendLine($"{p.playerName}  {readyMark}");
            }
            playerListText.text = sb.ToString();
        }

        // Player count
        if (playerCountText != null)
            playerCountText.text = $"Players: {ConnectedCount()}";

        // Start hint
        if (startHintText != null)
        {
            if (!IsHost())
                startHintText.text = "Waiting for the host to start…";
            else if (ConnectedCount() < minPlayers)
                startHintText.text = $"Need at least {minPlayers} players to start.";
            else if (!AllPlayersReady(live))
                startHintText.text = "Waiting for all players to be ready…";
            else
                startHintText.text = "All ready! Press Start.";
        }
    }

    // ── Utility ───────────────────────────────────────────────────────────────

    private void SetStartButtonEnabled(bool active)
    {
        _startEnabled = active;
        if (startButton != null) startButton.enabled = true; // Keep enabled so players can click and get feedback
        if (startButtonRenderer != null)
            SetRendererColor(startButtonRenderer, active ? startActiveColor : startInactiveColor);
    }

    private static void SetRendererColor(Renderer r, Color color)
    {
        // Use MaterialPropertyBlock to avoid creating new material instances.
        var block = new MaterialPropertyBlock();
        r.GetPropertyBlock(block);
        block.SetColor("_BaseColor", color);  // URP lit shader
        block.SetColor("_Color", color);      // Built-in / legacy shader fallback
        r.SetPropertyBlock(block);
    }
}
