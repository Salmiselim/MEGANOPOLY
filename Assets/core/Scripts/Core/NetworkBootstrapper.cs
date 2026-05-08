using System.Collections;
using UnityEngine;
using Unity.Netcode;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// Drop this on the same GameObject as your NetworkManager (or any persistent object).
/// Replaces the default NGO HUD with a proper lobby that lets you start with 2-4 players.
///
/// SETUP:
///   This script auto-creates its own Canvas/UI at runtime — no prefab needed.
///   Just attach it to a scene GameObject and play.
/// </summary>
public class NetworkBootstrapper : MonoBehaviour
{
    [Header("Game Settings")]
    [Tooltip("Minimum players needed before 'Force Start' appears.")]
    [SerializeField] private int minPlayersToStart = 2;
    [Tooltip("Auto-start when this many players connect (0 = never auto-start).")]
    [SerializeField] private int autoStartAt = 4;

    // UI refs (created at runtime)
    private Canvas _canvas;
    private GameObject _lobbyPanel;
    private TextMeshProUGUI _statusText;
    private Button _hostBtn;
    private Button _clientBtn;
    private Button _forceStartBtn;
    private Button _disconnectBtn;

    private bool _gameStarted = false;

    // ── Lifecycle ─────────────────────────────────────────────────────────────

    private void Start()
    {
        BuildUI();
        ShowLobby(true);
    }

    private void Update()
    {
        if (_gameStarted) return;
        if (NetworkManager.Singleton == null || !NetworkManager.Singleton.IsServer) return;

        int count = NetworkManager.Singleton.ConnectedClientsList.Count;
        UpdateStatus(count);

        // Show force-start as soon as you're hosting (host counts as 1)
        _forceStartBtn.gameObject.SetActive(count >= 1);

        // Auto-start
        if (autoStartAt > 0 && count >= autoStartAt)
            ForceStart();
    }

    // ── UI Actions ────────────────────────────────────────────────────────────

    private void OnHostClicked()
    {
        NetworkManager.Singleton.StartHost();
        _hostBtn.interactable = false;
        _clientBtn.interactable = false;
        UpdateStatus(1);
    }

    private void OnClientClicked()
    {
        NetworkManager.Singleton.StartClient();
        _hostBtn.interactable = false;
        _clientBtn.interactable = false;
        _forceStartBtn.gameObject.SetActive(false);
        SetStatusText("Connecting…");
    }

    private void ForceStart()
    {
        if (_gameStarted) return;
        _gameStarted = true;

        int count = NetworkManager.Singleton.ConnectedClientsList.Count;
        Debug.Log($"[Bootstrapper] Force-starting with {count} player(s).");

        // Tell CompleteGameManager to start now with however many are connected
        if (CompleteGameManager.Instance != null)
            CompleteGameManager.Instance.ForceStartWithCurrentPlayers();
        else
            Debug.LogError("[Bootstrapper] CompleteGameManager.Instance is null!");

        ShowLobby(false);
    }

    private void OnDisconnectClicked()
    {
        if (NetworkManager.Singleton.IsHost) NetworkManager.Singleton.Shutdown();
        else if (NetworkManager.Singleton.IsClient) NetworkManager.Singleton.Shutdown();
        _gameStarted = false;
        _hostBtn.interactable = true;
        _clientBtn.interactable = true;
        _forceStartBtn.gameObject.SetActive(false);
        ShowLobby(true);
        SetStatusText("Disconnected.");
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private void UpdateStatus(int count)
    {
        SetStatusText($"Players connected: {count} / {autoStartAt}\n" +
                      (count >= minPlayersToStart ? "Ready to start!" : $"Waiting for {minPlayersToStart - count} more…"));
    }

    private void SetStatusText(string msg)
    {
        if (_statusText != null) _statusText.text = msg;
    }

    private void ShowLobby(bool show) => _lobbyPanel.SetActive(show);

    // ── Runtime UI builder ────────────────────────────────────────────────────

    private void BuildUI()
    {
        // Canvas
        var canvasGo = new GameObject("BootstrapCanvas");
        _canvas = canvasGo.AddComponent<Canvas>();
        _canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        _canvas.sortingOrder = 999;
        canvasGo.AddComponent<CanvasScaler>();
        canvasGo.AddComponent<UnityEngine.UI.GraphicRaycaster>();
        DontDestroyOnLoad(canvasGo);

        // Panel
        _lobbyPanel = MakePanel(canvasGo.transform);

        // Status text
        _statusText = MakeText(_lobbyPanel.transform, "Waiting…", 18, new Vector2(0, 80));

        // Buttons
        _hostBtn = MakeButton(_lobbyPanel.transform, "Start Host", new Vector2(0, 30), OnHostClicked);
        _clientBtn = MakeButton(_lobbyPanel.transform, "Start Client", new Vector2(0, -20), OnClientClicked);
        _forceStartBtn = MakeButton(_lobbyPanel.transform, "▶ Force Start", new Vector2(0, -70), ForceStart);
        _disconnectBtn = MakeButton(_lobbyPanel.transform, "Disconnect", new Vector2(0, -120), OnDisconnectClicked);

        _forceStartBtn.gameObject.SetActive(false);
        SetStatusText("Choose role:");
    }

    private GameObject MakePanel(Transform parent)
    {
        var go = new GameObject("LobbyPanel");
        go.transform.SetParent(parent, false);
        var rt = go.AddComponent<RectTransform>();
        rt.anchorMin = rt.anchorMax = new Vector2(0, 1);
        rt.pivot = new Vector2(0, 1);
        rt.anchoredPosition = new Vector2(10, -10);
        rt.sizeDelta = new Vector2(220, 200);
        var img = go.AddComponent<UnityEngine.UI.Image>();
        img.color = new Color(0, 0, 0, 0.75f);
        return go;
    }

    private TextMeshProUGUI MakeText(Transform parent, string text, int size, Vector2 pos)
    {
        var go = new GameObject("StatusText");
        go.transform.SetParent(parent, false);
        var rt = go.AddComponent<RectTransform>();
        rt.sizeDelta = new Vector2(200, 40);
        rt.anchoredPosition = pos;
        var tmp = go.AddComponent<TextMeshProUGUI>();
        tmp.text = text;
        tmp.fontSize = size;
        tmp.alignment = TMPro.TextAlignmentOptions.Center;
        tmp.color = Color.white;
        return tmp;
    }

    private Button MakeButton(Transform parent, string label, Vector2 pos, System.Action onClick)
    {
        var go = new GameObject(label.Replace(" ", "") + "Btn");
        go.transform.SetParent(parent, false);
        var rt = go.AddComponent<RectTransform>();
        rt.sizeDelta = new Vector2(180, 36);
        rt.anchoredPosition = pos;
        var img = go.AddComponent<UnityEngine.UI.Image>();
        img.color = new Color(0.2f, 0.2f, 0.2f, 1f);
        var btn = go.AddComponent<Button>();
        btn.targetGraphic = img;
        var colors = btn.colors;
        colors.highlightedColor = new Color(0.35f, 0.35f, 0.35f);
        colors.pressedColor = new Color(0.1f, 0.1f, 0.1f);
        btn.colors = colors;
        btn.onClick.AddListener(() => onClick());

        // Label
        var labelGo = new GameObject("Label");
        labelGo.transform.SetParent(go.transform, false);
        var lrt = labelGo.AddComponent<RectTransform>();
        lrt.anchorMin = Vector2.zero; lrt.anchorMax = Vector2.one;
        lrt.sizeDelta = Vector2.zero;
        var tmp = labelGo.AddComponent<TextMeshProUGUI>();
        tmp.text = label;
        tmp.fontSize = 16;
        tmp.alignment = TMPro.TextAlignmentOptions.Center;
        tmp.color = Color.white;

        return btn;
    }
}