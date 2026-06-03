using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;
using Unity.Netcode;

public class PropertyCardUI : NetworkBehaviour
{
    public static PropertyCardUI Instance { get; private set; }

    [Header("Animation Settings")]
    [SerializeField] private float flyDuration = 0.5f;
    [SerializeField] private float cardDisplayHeight = 1.4f;
    [SerializeField] private float cardDistanceFromPlayer = 1.5f;
    [SerializeField] private AnimationCurve flyCurve = AnimationCurve.EaseInOut(0, 0, 1, 1);

    [Header("Card Display")]
    [SerializeField] private float cardDisplayScale = 0.15f;
    [SerializeField] private float cardTiltAngle = 25f;
    [SerializeField] private float buttonPanelGap = 0.4f;

    [Header("UI Buttons (World Space Canvas)")]
    [SerializeField] private GameObject buttonPanel;
    [SerializeField] private Button buyButton;
    [SerializeField] private Button passButton;
    [SerializeField] private Text balanceText;
    [SerializeField] private Text priceText;

    [Header("Canvas Scale")]
    [SerializeField] private float canvasWorldScale = 0.002f;

    [Header("References")]
    [SerializeField] private BoardManager boardManager;

    // ── Runtime state ─────────────────────────────────────────────────────────
    private GameObject _currentCard;
    private Vector3 _cardOriginalPosition;
    private Quaternion _cardOriginalRotation;
    private Vector3 _cardOriginalScale;

    private int _playerIndex;
    private int _tileIndex;
    private int _purchasePrice;
    private int _playerMoney;
    private bool _isWaiting;

    private Canvas _canvas;
    private Canvas _buttonPanelCanvas;

    // ── Lifecycle ─────────────────────────────────────────────────────────────

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else { Destroy(gameObject); return; }

        if (boardManager == null) boardManager = Object.FindFirstObjectByType<BoardManager>();

        foreach (Canvas c in GetComponentsInChildren<Canvas>(true))
        {
            c.renderMode = RenderMode.WorldSpace;
            var old = c.GetComponent<GraphicRaycaster>();
            if (old != null) DestroyImmediate(old);
            if (c.GetComponent<TrackedDeviceGraphicRaycaster>() == null)
                c.gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();
        }

        _canvas = GetComponent<Canvas>();
        if (buttonPanel != null)
        {
            _buttonPanelCanvas = buttonPanel.GetComponent<Canvas>()
                ?? buttonPanel.GetComponentInChildren<Canvas>(true);
        }
        if (_buttonPanelCanvas == null)
        {
            foreach (Canvas c in GetComponentsInChildren<Canvas>(true))
                if (c != _canvas) { _buttonPanelCanvas = c; break; }
        }

        transform.localScale = Vector3.one * canvasWorldScale;

        if (buttonPanel != null) buttonPanel.SetActive(false);
        if (buyButton != null) buyButton.onClick.AddListener(OnBuyClicked);
        if (passButton != null) passButton.onClick.AddListener(OnPassClicked);

        EnsureImg(buyButton);
        EnsureImg(passButton);
    }

    private void Start() => TryAssignCamera();

    private void Update()
    {
        if (_canvas != null && _canvas.worldCamera == null) TryAssignCamera();
        if (!_isWaiting) return;
        if (Input.GetKeyDown(KeyCode.B) || Input.GetKeyDown(KeyCode.Return)) OnBuyClicked();
        else if (Input.GetKeyDown(KeyCode.P) || Input.GetKeyDown(KeyCode.Escape)) OnPassClicked();
    }

    private void TryAssignCamera()
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) return;
        foreach (Canvas c in GetComponentsInChildren<Canvas>(true))
            if (c.worldCamera == null) c.worldCamera = cam;
    }

    // ── SERVER entry point ────────────────────────────────────────────────────

    public void ShowPropertyCard(PlayerData player, TileData property, TileMarker marker)
    {
        if (!IsServer) return;
        if (player == null || property == null || marker == null) return;

        if (marker.propertyCard == null)
        {
            CompleteGameManager.Instance?.OnPropertyCardClosed(player.playerId, property.tileIndex, false);
            return;
        }

        ulong target = ClientIdForPlayer(player.playerId);

        ShowPropertyCardClientRpc(
            player.playerId,
            property.tileIndex,
            property.purchasePrice,
            player.money,
            new ClientRpcParams
            {
                Send = new ClientRpcSendParams { TargetClientIds = new[] { target } }
            });
    }

    // ── CLIENT receive ────────────────────────────────────────────────────────

    [ClientRpc]
    private void ShowPropertyCardClientRpc(int playerIndex, int tileIndex,
        int purchasePrice, int playerMoney, ClientRpcParams rpcParams = default)
    {
        _playerIndex = playerIndex;
        _tileIndex = tileIndex;
        _purchasePrice = purchasePrice;
        _playerMoney = playerMoney;

        if (boardManager == null) boardManager = Object.FindFirstObjectByType<BoardManager>();

        TileMarker marker = boardManager?.GetTileMarker(tileIndex);
        if (marker == null || marker.propertyCard == null)
        {
            Debug.LogWarning($"[PropertyCardUI] No marker/card for tile {tileIndex} on this client.");
            DeclinePurchaseServerRpc(playerIndex, tileIndex);
            return;
        }

        _currentCard = marker.propertyCard;
        _cardOriginalPosition = _currentCard.transform.position;
        _cardOriginalRotation = _currentCard.transform.rotation;
        _cardOriginalScale = _currentCard.transform.localScale;

        TryAssignCamera();
        UpdateTexts(playerMoney, purchasePrice);
        StartCoroutine(AnimateCardToPlayer(playerIndex, playerMoney));
    }

    // ── Animation ─────────────────────────────────────────────────────────────

    private IEnumerator AnimateCardToPlayer(int playerIndex, int playerMoney)
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) yield break;

        PlayerData[] all = CompleteGameManager.Instance?.GetAllPlayers();
        PlayerData local = (all != null && playerIndex >= 0 && playerIndex < all.Length)
                                ? all[playerIndex] : null;

        Vector3 origin = local?.avatarTransform != null
            ? local.avatarTransform.position
            : cam.transform.position;

        Vector3 forward = cam.transform.forward;
        forward.y = 0f;
        if (forward.sqrMagnitude < 0.001f) forward = cam.transform.forward;
        forward.Normalize();

        Vector3 targetPos = origin + forward * cardDistanceFromPlayer + Vector3.up * cardDisplayHeight;

        Vector3 toPlayer = (cam.transform.position - targetPos);
        toPlayer.y = 0f;
        toPlayer.Normalize();

        Quaternion standUp = Quaternion.LookRotation(toPlayer, Vector3.up);
        Quaternion flip = Quaternion.AngleAxis(90f, Vector3.right);
        Quaternion upright = standUp * flip;
        Quaternion tilt = Quaternion.AngleAxis(cardTiltAngle, upright * Vector3.right);
        Quaternion targetRot = tilt * upright;
        Vector3 targetScale = _cardOriginalScale * cardDisplayScale;

        // Show the button panel from the start of the animation and keep it
        // glued under the card every frame, so the UI flies in WITH the card
        // instead of snapping in at the end.
        if (buttonPanel != null) buttonPanel.SetActive(true);

        float elapsed = 0f;
        while (elapsed < flyDuration)
        {
            elapsed += Time.deltaTime;
            float t = flyCurve.Evaluate(elapsed / flyDuration);
            Vector3 cardPos = Vector3.Lerp(_cardOriginalPosition, targetPos, t);
            _currentCard.transform.position = cardPos;
            _currentCard.transform.rotation = Quaternion.Slerp(_cardOriginalRotation, targetRot, t);
            _currentCard.transform.localScale = Vector3.Lerp(_cardOriginalScale, targetScale, t);

            if (buttonPanel != null)
            {
                buttonPanel.transform.position = cardPos - Vector3.up * buttonPanelGap;
                buttonPanel.transform.LookAt(cam.transform);
                buttonPanel.transform.Rotate(0, 180, 0);
            }
            yield return null;
        }

        _currentCard.transform.position = targetPos;
        _currentCard.transform.rotation = targetRot;
        _currentCard.transform.localScale = targetScale;

        if (buttonPanel != null)
        {
            buttonPanel.transform.position = targetPos - Vector3.up * buttonPanelGap;
            buttonPanel.transform.LookAt(cam.transform);
            buttonPanel.transform.Rotate(0, 180, 0);
        }

        _isWaiting = true;
    }

    private IEnumerator AnimateCardBack(bool didBuy)
    {
        _isWaiting = false;

        Vector3 startPos = _currentCard.transform.position;
        Quaternion startRot = _currentCard.transform.rotation;
        Vector3 startScale = _currentCard.transform.localScale;
        float elapsed = 0f;

        Camera cam = VRCameraProvider.Camera;
        while (elapsed < flyDuration)
        {
            elapsed += Time.deltaTime;
            float t = flyCurve.Evaluate(elapsed / flyDuration);
            Vector3 cardPos = Vector3.Lerp(startPos, _cardOriginalPosition, t);
            _currentCard.transform.position = cardPos;
            _currentCard.transform.rotation = Quaternion.Slerp(startRot, _cardOriginalRotation, t);
            _currentCard.transform.localScale = Vector3.Lerp(startScale, _cardOriginalScale, t);

            if (buttonPanel != null && cam != null)
            {
                buttonPanel.transform.position = cardPos - Vector3.up * buttonPanelGap;
                buttonPanel.transform.LookAt(cam.transform);
                buttonPanel.transform.Rotate(0, 180, 0);
            }
            yield return null;
        }

        _currentCard.transform.position = _cardOriginalPosition;
        _currentCard.transform.rotation = _cardOriginalRotation;
        _currentCard.transform.localScale = _cardOriginalScale;
        _currentCard = null;

        if (buttonPanel != null) buttonPanel.SetActive(false);

        if (didBuy)
            BuyPropertyServerRpc(_playerIndex, _tileIndex);
        else
            DeclinePurchaseServerRpc(_playerIndex, _tileIndex);
    }

    // ── Buttons ───────────────────────────────────────────────────────────────

    private void OnBuyClicked()
    {
        if (!_isWaiting || _playerMoney < _purchasePrice) return;
        StartCoroutine(AnimateCardBack(true));
    }

    private void OnPassClicked()
    {
        if (!_isWaiting) return;
        StartCoroutine(AnimateCardBack(false));
    }

    // ── ServerRpcs ────────────────────────────────────────────────────────────

    [Rpc(SendTo.Server, InvokePermission = RpcInvokePermission.Everyone)]
    private void BuyPropertyServerRpc(int playerIndex, int tileIndex)
    {
        PlayerData player = CompleteGameManager.Instance?.GetServerPlayer(playerIndex);
        TileData property = Object.FindFirstObjectByType<BoardManager>()?.GetTile(tileIndex);

        if (player == null || property == null)
        {
            CompleteGameManager.Instance?.OnPropertyCardClosed(playerIndex, tileIndex, false);
            return;
        }

        bool bought = PropertyManager.Instance != null
            && PropertyManager.Instance.TryBuyProperty(player, property);

        if (bought)
            _ = CloudSaveManager.Instance?.SavePropertiesOnlyAsync(player);

        Debug.Log($"[Server] Property buy: {player.playerName} → {property.tileName} bought={bought}");
        CompleteGameManager.Instance?.OnPropertyCardClosed(playerIndex, tileIndex, bought);
    }

    [Rpc(SendTo.Server, InvokePermission = RpcInvokePermission.Everyone)]
    private void DeclinePurchaseServerRpc(int playerIndex, int tileIndex)
    {
        Debug.Log($"[Server] Player {playerIndex} declined tile {tileIndex}");
        CompleteGameManager.Instance?.OnPropertyCardClosed(playerIndex, tileIndex, false);
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private void UpdateTexts(int playerMoney, int price)
    {
        if (balanceText != null) balanceText.text = $"Balance: {playerMoney} DT";
        if (priceText != null) priceText.text = $"Price: {price} DT";
        if (buyButton != null) buyButton.interactable = playerMoney >= price;
    }

    private ulong ClientIdForPlayer(int playerIndex)
    {
        var ids = NetworkManager.Singleton.ConnectedClientsIds;
        if (playerIndex >= 0 && playerIndex < ids.Count) return ids[playerIndex];
        return NetworkManager.ServerClientId;
    }

    public bool IsShowing() => _isWaiting;

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