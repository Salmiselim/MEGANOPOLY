using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;
using Unity.Netcode;

public class TrainMenuUI : NetworkBehaviour
{
    public static TrainMenuUI Instance { get; private set; }

    [Header("Panel")]
    [SerializeField] private GameObject menuPanel;

    [Header("Buttons")]
    [SerializeField] private Button takeTrain;
    [SerializeField] private Button passButton;

    [Header("Info Texts")]
    [SerializeField] private Text fromText;
    [SerializeField] private Text toText;
    [SerializeField] private Text fareText;
    [SerializeField] private Text balanceText;
    [SerializeField] private Text titleText;

    [Header("Display Settings")]
    [SerializeField] private float distanceFromPlayer = 1.5f;
    [SerializeField] private float heightAbovePlayer = 1.2f;
    [SerializeField] private float canvasWorldScale = 0.002f;

    // Cached for ServerRpc
    private int _playerIndex;
    private int _fromTileIndex;
    private int _toTileIndex;
    private int _fare;
    private int _playerMoney;
    private bool _isShowing;

    private Canvas _canvas;

    // ── Lifecycle ─────────────────────────────────────────────────────────────

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else { Destroy(gameObject); return; }

        _canvas = GetComponent<Canvas>();
        if (_canvas != null) _canvas.renderMode = RenderMode.WorldSpace;

        var old = GetComponent<GraphicRaycaster>();
        if (old != null) DestroyImmediate(old);
        if (GetComponent<TrackedDeviceGraphicRaycaster>() == null)
            gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();

        transform.localScale = Vector3.one * canvasWorldScale;

        if (menuPanel != null) menuPanel.SetActive(false);
        if (takeTrain != null) takeTrain.onClick.AddListener(OnTakeTrainClicked);
        if (passButton != null) passButton.onClick.AddListener(OnPassClicked);

        EnsureImg(takeTrain);
        EnsureImg(passButton);
    }

    private void Start() => TryAssignCamera();

    private void Update()
    {
        if (_canvas != null && _canvas.worldCamera == null) TryAssignCamera();
        if (!_isShowing) return;
        if (Input.GetKeyDown(KeyCode.T)) OnTakeTrainClicked();
        if (Input.GetKeyDown(KeyCode.P) || Input.GetKeyDown(KeyCode.Escape)) OnPassClicked();
        PositionCanvas();
    }

    private void TryAssignCamera()
    {
        if (_canvas == null) return;
        Camera cam = VRCameraProvider.Camera;
        if (cam != null) _canvas.worldCamera = cam;
    }

    // ── SERVER entry point ────────────────────────────────────────────────────

    public void ShowTrainMenu(PlayerData player, TileData fromStation, TileData destTile, int fare)
    {
        if (!IsServer) return;
        if (player == null || fromStation == null || destTile == null) return;

        ulong target = ClientIdForPlayer(player.playerId);

        ShowTrainMenuClientRpc(
            player.playerId,
            fromStation.tileIndex,
            destTile.tileIndex,
            fromStation.tileName,
            destTile.tileName,
            fare,
            player.money,
            new ClientRpcParams
            {
                Send = new ClientRpcSendParams { TargetClientIds = new[] { target } }
            });
    }

    // ── CLIENT receive ────────────────────────────────────────────────────────

    [ClientRpc]
    private void ShowTrainMenuClientRpc(int playerIndex, int fromTileIndex, int toTileIndex,
        string fromName, string toName, int fare, int playerMoney,
        ClientRpcParams rpcParams = default)
    {
        _playerIndex = playerIndex;
        _fromTileIndex = fromTileIndex;
        _toTileIndex = toTileIndex;
        _fare = fare;
        _playerMoney = playerMoney;
        _isShowing = true;

        if (titleText != null) titleText.text = "TRAIN STATION";
        if (fromText != null) fromText.text = $"From: {fromName}";
        if (toText != null) toText.text = $"To:   {toName}";
        if (fareText != null) fareText.text = $"Ticket: {fare} DT";
        if (balanceText != null) balanceText.text = $"Balance: {playerMoney} DT";

        if (takeTrain != null)
        {
            bool canAfford = playerMoney >= fare;
            takeTrain.interactable = canAfford;
            var lbl = takeTrain.GetComponentInChildren<Text>();
            if (lbl != null) lbl.text = canAfford ? $"Take Train  ({fare} DT)" : "Can't Afford";
        }
        if (passButton != null)
        {
            var lbl = passButton.GetComponentInChildren<Text>();
            if (lbl != null) lbl.text = "Pass (Stay)";
        }

        TryAssignCamera();
        PositionCanvas();
        if (menuPanel != null) menuPanel.SetActive(true);
        Debug.Log($"[TrainMenuUI] {fromName} → {toName}  fare={fare} DT");
    }

    // ── Buttons → ServerRpc ───────────────────────────────────────────────────

    private void OnTakeTrainClicked()
    {
        if (!_isShowing) return;
        CloseLocal();
        TrainDecisionServerRpc(_playerIndex, _fromTileIndex, _toTileIndex, _fare, true);
    }

    private void OnPassClicked()
    {
        if (!_isShowing) return;
        CloseLocal();
        TrainDecisionServerRpc(_playerIndex, _fromTileIndex, _toTileIndex, _fare, false);
    }

    [Rpc(SendTo.Server, InvokePermission = RpcInvokePermission.Everyone)]
    private void TrainDecisionServerRpc(int playerIndex, int fromTile, int toTile, int fare, bool tookTrain)
    {
        PlayerData[] all = CompleteGameManager.Instance?.GetAllPlayers();
        if (all == null || playerIndex < 0 || playerIndex >= all.Length)
        {
            CompleteGameManager.Instance?.OnTrainMenuClosed(playerIndex, fromTile, toTile, false, fare);
            return;
        }

        PlayerData rider = all[playerIndex];

        if (tookTrain && fare > 0)
        {
            TileData station = Object.FindFirstObjectByType<BoardManager>()?.GetTile(fromTile);
            if (station != null && station.IsOwned() && station.ownerId != rider.playerId)
            {
                int ownerIdx = station.ownerId;
                if (ownerIdx >= 0 && ownerIdx < all.Length && all[ownerIdx] != null)
                {
                    all[ownerIdx].AddMoney(fare);
                    _ = CloudSaveManager.Instance?.SaveProfileOnlyAsync(all[ownerIdx]);
                }
            }
            rider.RemoveMoney(fare);
            _ = CloudSaveManager.Instance?.SaveProfileOnlyAsync(rider);
        }

        if (tookTrain)
        {
            rider.currentTileIndex = toTile;
            var bm = Object.FindFirstObjectByType<BoardManager>();
            rider.movementController?.TeleportToTile(toTile, bm?.allTiles);
        }

        Debug.Log($"[Server] Train decision: player={playerIndex} tookTrain={tookTrain} fare={fare}");
        CompleteGameManager.Instance?.OnTrainMenuClosed(playerIndex, fromTile, toTile, tookTrain, fare);
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private void CloseLocal()
    {
        _isShowing = false;
        if (menuPanel != null) menuPanel.SetActive(false);
    }

    private void PositionCanvas()
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) return;

        PlayerData[] all = CompleteGameManager.Instance?.GetAllPlayers();
        PlayerData p = (all != null && _playerIndex >= 0 && _playerIndex < all.Length)
                            ? all[_playerIndex] : null;

        Vector3 forward = cam.transform.forward;
        forward.y = 0f;
        if (forward.sqrMagnitude < 0.001f) forward = cam.transform.forward;
        forward.Normalize();

        Vector3 origin = p?.avatarTransform != null ? p.avatarTransform.position : cam.transform.position;
        transform.position = origin + forward * distanceFromPlayer + Vector3.up * heightAbovePlayer;
        transform.LookAt(cam.transform);
        transform.Rotate(0f, 180f, 0f);
    }

    private ulong ClientIdForPlayer(int playerIndex)
    {
        var ids = NetworkManager.Singleton.ConnectedClientsIds;
        if (playerIndex >= 0 && playerIndex < ids.Count) return ids[playerIndex];
        return NetworkManager.ServerClientId;
    }

    public bool IsShowing() => _isShowing;

    private static void EnsureImg(Button btn)
    {
        if (btn == null) return;
        if (btn.targetGraphic is Image) return;
        Image img = btn.GetComponent<Image>() ?? btn.gameObject.AddComponent<Image>();
        img.color = new Color(1f, 1f, 1f, 0f);
        img.raycastTarget = true;
        btn.targetGraphic = img;
    }
}