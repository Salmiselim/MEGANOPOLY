using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;
using Unity.Netcode;

public class BuildingMenuUI : NetworkBehaviour
{
    public static BuildingMenuUI Instance { get; private set; }

    [Header("Panel Root")]
    [SerializeField] private GameObject menuPanel;

    [Header("Buttons")]
    [SerializeField] private Button buyHouseButton;
    [SerializeField] private Button buyHotelButton;
    [SerializeField] private Button endTurnButton;

    [Header("Info Texts")]
    [SerializeField] private Text propertyNameText;
    [SerializeField] private Text houseCostText;
    [SerializeField] private Text hotelCostText;
    [SerializeField] private Text balanceText;
    [SerializeField] private Text buildingStatusText;

    [Header("Display Settings")]
    [SerializeField] private float distanceFromPlayer = 1.5f;
    [SerializeField] private float heightAbovePlayer = 1.2f;
    [SerializeField] private float canvasWorldScale = 0.002f;

    // Local copies received via ClientRpc
    private PlayerData _currentPlayer;
    private TileData _currentProperty;
    private bool _isShowing;
    private Canvas _canvas;

    // Cached indices for ServerRpc calls
    private int _playerIndex;
    private int _tileIndex;

    // Server-authoritative facts about the current player/property/state.
    // The client can't compute these from its stub PlayerData (no owned-
    // properties list synced), so the server sends them via the ClientRpc
    // and the UI uses them directly when deciding which buttons to enable.
    private bool _serverOwns;
    private bool _serverHasMonopoly;
    private int _serverHouseCount;

    // ── Lifecycle ─────────────────────────────────────────────────────────────

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else { Destroy(gameObject); return; }

        _canvas = GetComponent<Canvas>();
        if (_canvas != null) _canvas.renderMode = RenderMode.WorldSpace;

        var old = GetComponent<GraphicRaycaster>();
        if (old != null) Destroy(old);
        if (GetComponent<TrackedDeviceGraphicRaycaster>() == null)
            gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();

        transform.localScale = Vector3.one * canvasWorldScale;

        if (menuPanel != null) menuPanel.SetActive(false);
        if (buyHouseButton != null) buyHouseButton.onClick.AddListener(OnBuyHouseClicked);
        if (buyHotelButton != null) buyHotelButton.onClick.AddListener(OnBuyHotelClicked);
        if (endTurnButton != null) endTurnButton.onClick.AddListener(OnEndTurnClicked);

        EnsureImg(buyHouseButton);
        EnsureImg(buyHotelButton);
        EnsureImg(endTurnButton);
    }

    private void Start() => TryAssignCamera();

    private void Update()
    {
        if (_canvas != null && _canvas.worldCamera == null) TryAssignCamera();
        if (!_isShowing) return;

        if (Input.GetKeyDown(KeyCode.H)) OnBuyHouseClicked();
        if (Input.GetKeyDown(KeyCode.T)) OnBuyHotelClicked();
        if (Input.GetKeyDown(KeyCode.Return) || Input.GetKeyDown(KeyCode.Escape)) OnEndTurnClicked();

        PositionCanvas();
    }

    private void TryAssignCamera()
    {
        if (_canvas == null) return;
        Camera cam = VRCameraProvider.Camera;
        if (cam != null) _canvas.worldCamera = cam;
    }

    // ── SERVER entry point ────────────────────────────────────────────────────

    public void ShowBuildingMenu(PlayerData player, TileData property)
    {
        if (!IsServer) return;
        if (player == null || property == null) return;
        if (property.ownerId != player.playerId) return;

        ulong target = ClientIdForPlayer(player.playerId);

        BoardManager bm = Object.FindFirstObjectByType<BoardManager>();
        TileData[] allTiles = bm != null ? bm.allTiles : new TileData[0];
        bool serverHasMonopoly = player.HasMonopoly(property.propertyColor, allTiles);

        ShowBuildingMenuClientRpc(
            player.playerId,
            property.tileIndex,
            player.money,
            serverHasMonopoly,
            property.houseCount,
            new ClientRpcParams
            {
                Send = new ClientRpcSendParams { TargetClientIds = new[] { target } }
            });
    }

    // ── CLIENT receive ────────────────────────────────────────────────────────

    [ClientRpc]
    private void ShowBuildingMenuClientRpc(int playerIndex, int tileIndex, int playerMoney,
        bool serverHasMonopoly, int serverHouseCount,
        ClientRpcParams rpcParams = default)
    {
        _playerIndex = playerIndex;
        _tileIndex = tileIndex;
        _serverHasMonopoly = serverHasMonopoly;
        _serverHouseCount = serverHouseCount;
        // The server already verified ownership before opening the menu — if
        // we're receiving the ClientRpc, this player owns the property.
        _serverOwns = true;

        // Resolve local references
        PlayerData[] all = CompleteGameManager.Instance?.GetAllPlayers();
        _currentPlayer = (all != null && playerIndex >= 0 && playerIndex < all.Length)
                            ? all[playerIndex] : null;

        if (_currentPlayer == null)
        {
            // Fallback stub so UI can still display
            _currentPlayer = new PlayerData(playerIndex, $"Player {playerIndex + 1}", Color.white);
            _currentPlayer.money = playerMoney;
        }

        _currentProperty = Object.FindFirstObjectByType<BoardManager>()?.GetTile(tileIndex);

        if (_currentPlayer == null || _currentProperty == null)
        {
            Debug.LogError($"[BuildingMenuUI] Could not find player {playerIndex} or tile {tileIndex}.");
            return;
        }

        _isShowing = true;
        TryAssignCamera();
        PositionCanvas();
        if (menuPanel != null) menuPanel.SetActive(true);
        UpdateTexts();

        Debug.Log($"[BuildingMenuUI] Showing for player {playerIndex} — {_currentProperty.tileName} " +
                  $"(serverOwns={_serverOwns} monopoly={_serverHasMonopoly} houses={_serverHouseCount})");
    }

    // ── Buttons → ServerRpc ───────────────────────────────────────────────────

    private void OnBuyHouseClicked()
    {
        if (!_isShowing) return;
        BuyHouseServerRpc(_playerIndex, _tileIndex);
    }

    private void OnBuyHotelClicked()
    {
        if (!_isShowing) return;
        BuyHotelServerRpc(_playerIndex, _tileIndex);
    }

    private void OnEndTurnClicked()
    {
        if (!_isShowing) return;
        _isShowing = false;
        if (menuPanel != null) menuPanel.SetActive(false);
        Debug.Log("[BuildingMenuUI] Closed by client.");
        NotifyMenuClosedServerRpc();
    }

    [Rpc(SendTo.Server, InvokePermission = RpcInvokePermission.Everyone)]
    private void BuyHouseServerRpc(int playerIndex, int tileIndex)
    {
        PlayerData player = CompleteGameManager.Instance?.GetServerPlayer(playerIndex);
        TileData property = Object.FindFirstObjectByType<BoardManager>()?.GetTile(tileIndex);
        if (player == null || property == null) return;

        if (PropertyManager.Instance != null &&
            PropertyManager.Instance.TryBuyHouse(player, property))
        {
            Debug.Log($"[Server] House built on {property.tileName}");
            ulong target = ClientIdForPlayer(playerIndex);
            RefreshUIClientRpc(player.money, property.houseCount,
                new ClientRpcParams
                {
                    Send = new ClientRpcSendParams { TargetClientIds = new[] { target } }
                });
        }
    }

    [Rpc(SendTo.Server, InvokePermission = RpcInvokePermission.Everyone)]
    private void BuyHotelServerRpc(int playerIndex, int tileIndex)
    {
        PlayerData player = CompleteGameManager.Instance?.GetServerPlayer(playerIndex);
        TileData property = Object.FindFirstObjectByType<BoardManager>()?.GetTile(tileIndex);
        if (player == null || property == null) return;

        if (PropertyManager.Instance != null &&
            PropertyManager.Instance.TryBuyHotel(player, property))
        {
            Debug.Log($"[Server] Hotel built on {property.tileName}");
            ulong target = ClientIdForPlayer(playerIndex);
            RefreshUIClientRpc(player.money, property.houseCount,
                new ClientRpcParams
                {
                    Send = new ClientRpcSendParams { TargetClientIds = new[] { target } }
                });
        }
    }

    [Rpc(SendTo.Server, InvokePermission = RpcInvokePermission.Everyone)]
    private void NotifyMenuClosedServerRpc()
    {
        CompleteGameManager.Instance?.OnBuildingMenuClosed();
    }

    // ── CLIENT: refresh after a purchase ─────────────────────────────────────

    [ClientRpc]
    private void RefreshUIClientRpc(int updatedMoney, int updatedHouseCount,
        ClientRpcParams rpcParams = default)
    {
        if (_currentPlayer != null) _currentPlayer.money = updatedMoney;
        if (_currentProperty != null) _currentProperty.houseCount = updatedHouseCount;
        // Keep the server-authoritative house count in sync so the button
        // states update correctly after each purchase.
        _serverHouseCount = updatedHouseCount;
        UpdateTexts();
    }

    // ── UI helpers ────────────────────────────────────────────────────────────

    private void PositionCanvas()
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) return;

        Vector3 forward = cam.transform.forward;
        forward.y = 0f;
        if (forward.sqrMagnitude < 0.001f) forward = cam.transform.forward;
        forward.Normalize();

        Vector3 origin = _currentPlayer?.avatarTransform != null
            ? _currentPlayer.avatarTransform.position
            : cam.transform.position;

        transform.position = origin + forward * distanceFromPlayer + Vector3.up * heightAbovePlayer;
        transform.LookAt(cam.transform);
        transform.Rotate(0f, 180f, 0f);
    }

    private void UpdateTexts()
    {
        if (_currentProperty == null || _currentPlayer == null) return;

        if (propertyNameText != null) propertyNameText.text = _currentProperty.tileName;
        int houseCost = _currentProperty.houseCost;
        int hotelCost = _currentProperty.hotelCost > 0 ? _currentProperty.hotelCost : houseCost;
        if (houseCostText != null) houseCostText.text = $"House: {houseCost} DT";
        if (hotelCostText != null) hotelCostText.text = $"Hotel: {hotelCost} DT";
        if (balanceText != null) balanceText.text = $"Balance: {_currentPlayer.money} DT";
        if (buildingStatusText != null) buildingStatusText.text = GetBuildingStatusText();

        RefreshButtonStates();
    }

    private string GetBuildingStatusText()
    {
        if (_currentProperty.houseCount == 0) return "No buildings";
        if (_currentProperty.houseCount == 5) return "Hotel";
        return $"{_currentProperty.houseCount} house(s)";
    }

    private void RefreshButtonStates()
    {
        // TEST MODE: force both build buttons to be interactable so the
        // build flow can be exercised on Quest without waiting for the
        // owned-properties list to sync. The server still validates the
        // purchase in TryBuyHouse / TryBuyHotel, so this only loosens the
        // client-side gate.
        int houseCount = _serverHouseCount;
        int hotelCost = _currentProperty.hotelCost > 0
                            ? _currentProperty.hotelCost
                            : _currentProperty.houseCost;

        if (buyHouseButton != null)
        {
            buyHouseButton.interactable = true;
            var lbl = buyHouseButton.GetComponentInChildren<Text>();
            if (lbl != null) lbl.text = $"Buy House\n({_currentProperty.houseCost} DT)";
        }

        if (buyHotelButton != null)
        {
            buyHotelButton.interactable = true;
            var lbl = buyHotelButton.GetComponentInChildren<Text>();
            if (lbl != null) lbl.text = $"Buy Hotel\n({hotelCost} DT)";
        }
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