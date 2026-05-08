using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;
using Unity.Netcode;

public class RentMenuUI : NetworkBehaviour
{
    public static RentMenuUI Instance { get; private set; }

    [Header("Panel Root")]
    [SerializeField] private GameObject menuPanel;

    [Header("Buttons")]
    [SerializeField] private Button payButton;
    [SerializeField] private Button playMinigameButton;

    [Header("Info Texts")]
    [SerializeField] private Text propertyNameText;
    [SerializeField] private Text ownerNameText;
    [SerializeField] private Text rentAmountText;
    [SerializeField] private Text balanceText;

    [Header("Display Settings")]
    [SerializeField] private float distanceFromPlayer = 1.5f;
    [SerializeField] private float heightAbovePlayer = 1.2f;
    [SerializeField] private float canvasWorldScale = 0.002f;

    // Cached indices sent from server
    private int _payerIndex;
    private int _ownerIndex;
    private int _tileIndex;
    private int _rentAmount;
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
        if (old != null) Destroy(old);
        if (GetComponent<TrackedDeviceGraphicRaycaster>() == null)
            gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();

        transform.localScale = Vector3.one * canvasWorldScale;

        if (menuPanel != null) menuPanel.SetActive(false);
        if (payButton != null) payButton.onClick.AddListener(OnPayClicked);
        if (playMinigameButton != null) playMinigameButton.onClick.AddListener(OnPlayMinigameClicked);

        EnsureImg(payButton);
        EnsureImg(playMinigameButton);
    }

    private void Start() => TryAssignCamera();

    private void Update()
    {
        if (_canvas != null && _canvas.worldCamera == null) TryAssignCamera();
        if (!_isShowing) return;
        if (Input.GetKeyDown(KeyCode.Return) || Input.GetKeyDown(KeyCode.P)) OnPayClicked();
        PositionCanvas();
    }

    private void TryAssignCamera()
    {
        if (_canvas == null) return;
        Camera cam = VRCameraProvider.Camera;
        if (cam != null) _canvas.worldCamera = cam;
    }

    // ── SERVER entry point ────────────────────────────────────────────────────

    public void ShowRentMenu(PlayerData payer, TileData property, PlayerData owner)
    {
        if (!IsServer) return;
        if (payer == null || property == null || owner == null) return;

        int rent = property.GetCurrentRent();
        ulong target = ClientIdForPlayer(payer.playerId);

        ShowRentMenuClientRpc(
            payer.playerId,
            owner.playerId,
            property.tileIndex,
            rent,
            payer.money,
            owner.playerName,
            new ClientRpcParams
            {
                Send = new ClientRpcSendParams { TargetClientIds = new[] { target } }
            });
    }

    // ── CLIENT receive ────────────────────────────────────────────────────────

    [ClientRpc]
    private void ShowRentMenuClientRpc(int payerIndex, int ownerIndex, int tileIndex,
        int rentAmount, int payerMoney, string ownerName,
        ClientRpcParams rpcParams = default)
    {
        _payerIndex = payerIndex;
        _ownerIndex = ownerIndex;
        _tileIndex = tileIndex;
        _rentAmount = rentAmount;
        _isShowing = true;

        TileData tile = Object.FindFirstObjectByType<BoardManager>()?.GetTile(tileIndex);

        if (propertyNameText != null) propertyNameText.text = tile?.tileName ?? $"Tile {tileIndex}";
        if (ownerNameText != null) ownerNameText.text = $"Owner: {ownerName}";
        if (rentAmountText != null) rentAmountText.text = $"Rent: {rentAmount} DT";
        if (balanceText != null) balanceText.text = $"Your Balance: {payerMoney} DT";

        if (payButton != null)
        {
            payButton.interactable = payerMoney >= rentAmount;
            var lbl = payButton.GetComponentInChildren<Text>();
            if (lbl != null) lbl.text = $"Pay {rentAmount} DT";
        }

        if (playMinigameButton != null)
            playMinigameButton.gameObject.SetActive(payerMoney < rentAmount);

        TryAssignCamera();
        PositionCanvas();
        if (menuPanel != null) menuPanel.SetActive(true);
        Debug.Log($"[RentMenuUI] Player {payerIndex} owes {rentAmount} DT");
    }

    // ── Buttons → ServerRpc ───────────────────────────────────────────────────

    private void OnPayClicked()
    {
        if (!_isShowing) return;
        CloseLocal();
        PayRentServerRpc(_payerIndex, _ownerIndex, _rentAmount);
    }

    private void OnPlayMinigameClicked()
    {
        if (!_isShowing) return;
        CloseLocal();
        RequestMinigameServerRpc(_payerIndex, _tileIndex, _rentAmount);
    }

    [Rpc(SendTo.Server, InvokePermission = RpcInvokePermission.Everyone)]
    private void PayRentServerRpc(int payerIndex, int ownerIndex, int amount)
    {
        PlayerData payer = CompleteGameManager.Instance?.GetServerPlayer(payerIndex);
        PlayerData owner = CompleteGameManager.Instance?.GetServerPlayer(ownerIndex);

        if (payer == null || owner == null)
        {
            CompleteGameManager.Instance?.OnRentMenuClosed();
            return;
        }

        if (payer.RemoveMoney(amount))
        {
            owner.AddMoney(amount);
            Debug.Log($"[Server] Rent paid: {payer.playerName} → {owner.playerName} {amount} DT");
            _ = CloudSaveManager.Instance?.SaveProfileOnlyAsync(payer);
            _ = CloudSaveManager.Instance?.SaveProfileOnlyAsync(owner);
        }
        else
        {
            Debug.LogWarning($"[Server] {payer.playerName} can't afford {amount} DT — minigame fallback");
            TileData tile = Object.FindFirstObjectByType<BoardManager>()?.GetTile(_tileIndex);
            if (tile != null)
                CompleteGameManager.Instance?.TriggerMinigameChallenge(payer, tile, 0, amount, isRentContext: true);
            return; // minigame ends the turn via OnMinigameEnded
        }

        CompleteGameManager.Instance?.OnRentMenuClosed();
    }

    [Rpc(SendTo.Server, InvokePermission = RpcInvokePermission.Everyone)]
    private void RequestMinigameServerRpc(int payerIndex, int tileIndex, int prizeAmount)
    {
        PlayerData payer = CompleteGameManager.Instance?.GetServerPlayer(payerIndex);
        TileData tile = Object.FindFirstObjectByType<BoardManager>()?.GetTile(tileIndex);

        if (payer == null || tile == null)
        {
            CompleteGameManager.Instance?.OnRentMenuClosed();
            return;
        }

        Debug.Log($"[Server] {payer.playerName} chose minigame instead of rent on {tile.tileName}");
        CompleteGameManager.Instance?.TriggerMinigameChallenge(payer, tile, 0, prizeAmount, isRentContext: true);
        // Turn continues via CompleteGameManager.OnMinigameEnded
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
        PlayerData p = (all != null && _payerIndex >= 0 && _payerIndex < all.Length)
                            ? all[_payerIndex] : null;

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