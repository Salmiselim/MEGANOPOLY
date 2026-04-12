using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;
using Unity.Netcode;

public class BuildingMenuUI : MonoBehaviour
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

    // Local copies of data received via ClientRpc
    private PlayerData currentPlayer;
    private TileData currentProperty;
    private bool isShowing = false;
    private Canvas canvas;

    // Cached indices so we can re-look them up on the client
    private int _playerIndex;
    private int _tileIndex;

    public UnityEvent OnMenuClosed = new UnityEvent();

    // ── Awake / Start ─────────────────────────────────────────────────────────

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else { Destroy(gameObject); return; }

        canvas = GetComponent<Canvas>();
        if (canvas != null) canvas.renderMode = RenderMode.WorldSpace;

        GraphicRaycaster old = GetComponent<GraphicRaycaster>();
        if (old != null) Destroy(old);
        if (GetComponent<TrackedDeviceGraphicRaycaster>() == null)
            gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();

        transform.localScale = Vector3.one * canvasWorldScale;

        if (menuPanel != null) menuPanel.SetActive(false);

        if (buyHouseButton != null) buyHouseButton.onClick.AddListener(OnBuyHouseClicked);
        if (buyHotelButton != null) buyHotelButton.onClick.AddListener(OnBuyHotelClicked);
        if (endTurnButton != null) endTurnButton.onClick.AddListener(OnEndTurnClicked);

        EnsureButtonImages();
    }

    private void Start() => TryAssignCamera();

    private void Update()
    {
        if (canvas != null && canvas.worldCamera == null) TryAssignCamera();
        if (!isShowing) return;

        if (Input.GetKeyDown(KeyCode.H)) OnBuyHouseClicked();
        if (Input.GetKeyDown(KeyCode.T)) OnBuyHotelClicked();
        if (Input.GetKeyDown(KeyCode.Return)
         || Input.GetKeyDown(KeyCode.Escape)) OnEndTurnClicked();

        FaceCamera();
    }

    // ── Camera ────────────────────────────────────────────────────────────────

    private void TryAssignCamera()
    {
        if (canvas == null) return;
        Camera cam = VRCameraProvider.Camera;
        if (cam != null) canvas.worldCamera = cam;
    }

    // ── SERVER: called by CompleteGameManager ─────────────────────────────────

    /// <summary>
    /// Server calls this. Sends a ClientRpc to the owner of that player slot
    /// so the UI appears only on the correct client.
    /// </summary>
    public void ShowBuildingMenu(PlayerData player, TileData property)
    {
      
        if (player == null || property == null) return;
        if (property.ownerId != player.playerId) return;

        // Find which client owns this player slot
        ulong targetClient = GetClientIdForPlayer(player.playerId);

        // Send data to that client only
        ShowBuildingMenuClientRpc(
            player.playerId,
            property.tileIndex,
            player.money,
            new ClientRpcParams
            {
                Send = new ClientRpcSendParams
                {
                    TargetClientIds = new[] { targetClient }
                }
            }
        );
    }

    // ── CLIENT: receive and display ───────────────────────────────────────────


    private void ShowBuildingMenuClientRpc(int playerIndex, int tileIndex, int playerMoney, ClientRpcParams rpcParams = default)
    {
        _playerIndex = playerIndex;
        _tileIndex = tileIndex;

        // Rebuild local references from indices
        currentPlayer = GetLocalPlayerData(playerIndex, playerMoney);
        currentProperty = GetLocalTileData(tileIndex);

        if (currentPlayer == null || currentProperty == null)
        {
            Debug.LogError($"[BuildingMenuUI] Could not find player {playerIndex} or tile {tileIndex} on client.");
            return;
        }

        isShowing = true;
        TryAssignCamera();
        MoveCanvasToPlayer();
        if (menuPanel != null) menuPanel.SetActive(true);
        UpdateTexts();

        Debug.Log($"[BuildingMenuUI] Showing for player {playerIndex} — {currentProperty.tileName}");
    }

    // ── BUTTONS: client clicks → ServerRpc → server executes ─────────────────

    private void OnBuyHouseClicked()
    {
        if (!isShowing) return;
        BuyHouseServerRpc(_playerIndex, _tileIndex);
    }

    private void OnBuyHotelClicked()
    {
        if (!isShowing) return;
        BuyHotelServerRpc(_playerIndex, _tileIndex);
    }

    private void OnEndTurnClicked()
    {
        if (!isShowing) return;
        isShowing = false;
        if (menuPanel != null) menuPanel.SetActive(false);
        Debug.Log("[BuildingMenuUI] Closed by client.");
        OnMenuClosed?.Invoke();          // local close
        NotifyServerMenuClosedServerRpc(); // tell server to continue turn
    }

    [ServerRpc(RequireOwnership = false)]
    private void BuyHouseServerRpc(int playerIndex, int tileIndex)
    {
        PlayerData player = GetServerPlayerData(playerIndex);
        TileData property = GetServerTileData(tileIndex);
        if (player == null || property == null) return;

        if (PropertyManager.Instance != null &&
            PropertyManager.Instance.TryBuyHouse(player, property))
        {
            Debug.Log($"[Server] House built on {property.tileName}");
            // Refresh the UI on the client with updated money
            ulong target = GetClientIdForPlayer(playerIndex);
            RefreshUIClientRpc(player.money, property.houseCount,
                new ClientRpcParams { Send = new ClientRpcSendParams { TargetClientIds = new[] { target } } });
        }
    }

    [ServerRpc(RequireOwnership = false)]
    private void BuyHotelServerRpc(int playerIndex, int tileIndex)
    {
        PlayerData player = GetServerPlayerData(playerIndex);
        TileData property = GetServerTileData(tileIndex);
        if (player == null || property == null) return;

        if (PropertyManager.Instance != null &&
            PropertyManager.Instance.TryBuyHotel(player, property))
        {
            Debug.Log($"[Server] Hotel built on {property.tileName}");
            ulong target = GetClientIdForPlayer(playerIndex);
            RefreshUIClientRpc(player.money, property.houseCount,
                new ClientRpcParams { Send = new ClientRpcSendParams { TargetClientIds = new[] { target } } });
        }

    }
  
    private void NotifyServerMenuClosedServerRpc()
    {
        // Resume the game turn on the server
        OnMenuClosed?.Invoke();
    }

    // ── CLIENT: refresh after a purchase ─────────────────────────────────────

 
    private void RefreshUIClientRpc(int updatedMoney, int updatedHouseCount, ClientRpcParams rpcParams = default)
    {
        if (currentPlayer != null) currentPlayer.money = updatedMoney;
        if (currentProperty != null) currentProperty.houseCount = updatedHouseCount;
        UpdateTexts();
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    /// <summary>Find which NGO client owns a given player slot index.</summary>
    private ulong GetClientIdForPlayer(int playerIndex)
    {
        // ConnectedClientsIds[i] maps to player slot i (same order as ServerInitGame)
        var ids = NetworkManager.Singleton.ConnectedClientsIds;
        if (playerIndex < ids.Count) return ids[playerIndex];
        return NetworkManager.ServerClientId;
    }

    // Server-side lookups (full authoritative data)
    private PlayerData GetServerPlayerData(int index)
    {
        PlayerData[] all = CompleteGameManager.Instance?.GetAllPlayers();
        if (all == null || index < 0 || index >= all.Length) return null;
        return all[index];
    }

    private TileData GetServerTileData(int index)
        => FindObjectOfType<BoardManager>()?.GetTile(index);

    // Client-side lookups (build lightweight local copy from received data)
    private PlayerData GetLocalPlayerData(int playerIndex, int money)
    {
        // Try the game manager first (host has full data, client may too)
        PlayerData[] all = CompleteGameManager.Instance?.GetAllPlayers();
        if (all != null && playerIndex >= 0 && playerIndex < all.Length && all[playerIndex] != null)
            return all[playerIndex];

        // Fallback: minimal stub so UI can display
        PlayerData stub = new PlayerData(playerIndex, $"Player {playerIndex + 1}", Color.white);
        stub.money = money;
        return stub;
    }

    private TileData GetLocalTileData(int tileIndex)
        => FindObjectOfType<BoardManager>()?.GetTile(tileIndex);

    // ── UI helpers ────────────────────────────────────────────────────────────

    private void MoveCanvasToPlayer()
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) return;

        Vector3 forward = cam.transform.forward;
        forward.y = 0f;
        if (forward.sqrMagnitude < 0.001f) forward = cam.transform.forward;
        forward.Normalize();

        Vector3 origin = currentPlayer?.avatarTransform != null
            ? currentPlayer.avatarTransform.position
            : cam.transform.position;

        transform.position = origin + forward * distanceFromPlayer + Vector3.up * heightAbovePlayer;
        FaceCamera();
    }

    private void FaceCamera()
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) return;
        transform.LookAt(cam.transform);
        transform.Rotate(0f, 180f, 0f);
    }

    private void UpdateTexts()
    {
        if (currentProperty == null || currentPlayer == null) return;

        if (propertyNameText != null) propertyNameText.text = currentProperty.tileName;
        int houseCost = currentProperty.houseCost;
        int hotelCost = currentProperty.hotelCost > 0 ? currentProperty.hotelCost : houseCost;
        if (houseCostText != null) houseCostText.text = $"House: {houseCost} DT";
        if (hotelCostText != null) hotelCostText.text = $"Hotel: {hotelCost} DT";
        if (balanceText != null) balanceText.text = $"Balance: {currentPlayer.money} DT";
        if (buildingStatusText != null) buildingStatusText.text = GetBuildingStatusText();

        RefreshButtonStates();
    }

    private string GetBuildingStatusText()
    {
        if (currentProperty.houseCount == 0) return "No buildings";
        if (currentProperty.houseCount == 5) return "Hotel";
        return $"{currentProperty.houseCount} house(s)";
    }

    private void RefreshButtonStates()
    {
        BoardManager bm = FindObjectOfType<BoardManager>();
        TileData[] allTiles = bm != null ? bm.allTiles : new TileData[0];

        bool owns = currentProperty.ownerId == currentPlayer.playerId;
        bool monopoly = currentPlayer.HasMonopoly(currentProperty.propertyColor, allTiles);
        int hotelCost = currentProperty.hotelCost > 0 ? currentProperty.hotelCost : currentProperty.houseCost;

        bool canHouse = owns && monopoly && currentProperty.houseCount < 4 && currentPlayer.CanAfford(currentProperty.houseCost);
        bool canHotel = owns && currentProperty.houseCount == 4 && currentPlayer.CanAfford(hotelCost);

        if (buyHouseButton != null)
        {
            buyHouseButton.interactable = canHouse;
            Text lbl = buyHouseButton.GetComponentInChildren<Text>();
            if (lbl != null)
            {
                if (!monopoly) lbl.text = "Buy House\n(Need Monopoly)";
                else if (currentProperty.houseCount >= 4) lbl.text = "Buy House\n(Max)";
                else lbl.text = $"Buy House\n({currentProperty.houseCost} DT)";
            }
        }

        if (buyHotelButton != null)
        {
            buyHotelButton.interactable = canHotel;
            Text lbl = buyHotelButton.GetComponentInChildren<Text>();
            if (lbl != null)
                lbl.text = currentProperty.houseCount < 4
                    ? "Buy Hotel\n(Need 4 houses)"
                    : $"Buy Hotel\n({hotelCost} DT)";
        }
    }

    private void EnsureButtonImages()
    {
        EnsureImageOnButton(buyHouseButton);
        EnsureImageOnButton(buyHotelButton);
        EnsureImageOnButton(endTurnButton);
    }

    private static void EnsureImageOnButton(Button btn)
    {
        if (btn == null) return;
        if (btn.targetGraphic is Image) return;
        Image img = btn.GetComponent<Image>();
        if (img == null) { img = btn.gameObject.AddComponent<Image>(); img.color = new Color(1f, 1f, 1f, 0f); }
        img.raycastTarget = true;
        btn.targetGraphic = img;
    }

    public bool IsShowing() => isShowing;
}