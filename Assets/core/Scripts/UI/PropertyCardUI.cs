using System.Collections;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class PropertyCardUI : MonoBehaviour
{
    public static PropertyCardUI Instance { get; private set; }

    [Header("Animation Settings")]
    [SerializeField] private float flyDuration = 0.5f;
    [SerializeField] private float cardDisplayHeight = 1.4f;
    [SerializeField] private float cardDistanceFromPlayer = 1.5f;
    [SerializeField] private AnimationCurve flyCurve = AnimationCurve.EaseInOut(0, 0, 1, 1);

    [Header("Card Display")]
    [Tooltip("Scale multiplier when displayed. 0.15 = 15% of board size.")]
    [SerializeField] private float cardDisplayScale = 0.15f;
    [Tooltip("Tilt top of card toward player (degrees). 25 = comfortably readable.")]
    [SerializeField] private float cardTiltAngle = 25f;
    [Tooltip("Gap between bottom of card and top of button panel.")]
    [SerializeField] private float buttonPanelGap = 0.4f;

    [Header("UI Buttons (World Space Canvas)")]
    [SerializeField] private GameObject buttonPanel;
    [SerializeField] private Button buyButton;
    [SerializeField] private Button passButton;
    [SerializeField] private Text balanceText;
    [SerializeField] private Text priceText;

    [Header("Canvas Scale")]
    [Tooltip("World-scale of the canvas — 0.001 to 0.003 for VR")]
    [SerializeField] private float canvasWorldScale = 0.002f;

    [Header("References")]
    [SerializeField] private BoardManager boardManager;

    public UnityEvent<bool> OnPurchaseDecision = new UnityEvent<bool>();

    private GameObject currentCard;
    private Vector3 cardOriginalPosition;
    private Quaternion cardOriginalRotation;
    private Vector3 cardOriginalScale;
    private TileData currentProperty;
    private PlayerData currentPlayer;
    private bool isWaitingForInput = false;
    private Canvas canvas;
    private Canvas buttonPanelCanvas; // the child Canvas on the buttonPanel

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else { Destroy(gameObject); return; }

        if (boardManager == null) boardManager = FindObjectOfType<BoardManager>();

        // Fix every Canvas on this GameObject and all children
        foreach (Canvas c in GetComponentsInChildren<Canvas>(true))
        {
            c.renderMode = RenderMode.WorldSpace;

            GraphicRaycaster old = c.GetComponent<GraphicRaycaster>();
            if (old != null) DestroyImmediate(old);   // immediate so AddComponent runs clean

            if (c.GetComponent<TrackedDeviceGraphicRaycaster>() == null)
                c.gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();
        }

        // Cache root canvas and buttonPanel canvas for camera assignment
        canvas = GetComponent<Canvas>();
        if (buttonPanel != null)
        {
            buttonPanelCanvas = buttonPanel.GetComponent<Canvas>();
            if (buttonPanelCanvas == null)
                buttonPanelCanvas = buttonPanel.GetComponentInChildren<Canvas>(true);
        }
      // If buttonPanel wasn't assigned or has no Canvas, find any child Canvas that isn't root
        if (buttonPanelCanvas == null)
        {
         foreach (Canvas c in GetComponentsInChildren<Canvas>(true))
            {
         if (c != canvas) { buttonPanelCanvas = c; break; }
            }
 }

        transform.localScale = Vector3.one * canvasWorldScale;

        if (buttonPanel != null) buttonPanel.SetActive(false);
        if (buyButton != null) buyButton.onClick.AddListener(OnBuyClicked);
        if (passButton != null) passButton.onClick.AddListener(OnPassClicked);

        EnsureImageOnButton(buyButton);
        EnsureImageOnButton(passButton);
    }

    private void Start() => TryAssignCamera();

    private void Update()
    {
        if (canvas != null && canvas.worldCamera == null) TryAssignCamera();
        if (!isWaitingForInput) return;
        if (Input.GetKeyDown(KeyCode.B) || Input.GetKeyDown(KeyCode.Return)) OnBuyClicked();
        else if (Input.GetKeyDown(KeyCode.P) || Input.GetKeyDown(KeyCode.Escape)) OnPassClicked();
    }

    private void TryAssignCamera()
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) return;

   // Assign to every Canvas in the hierarchy that still needs it
        foreach (Canvas c in GetComponentsInChildren<Canvas>(true))
            if (c.worldCamera == null) c.worldCamera = cam;
    }

    private static void EnsureImageOnButton(Button btn)
    {
        if (btn == null) return;
        if (btn.targetGraphic is Image) return;
        Image img = btn.GetComponent<Image>();
        if (img == null)
        {
            img = btn.gameObject.AddComponent<Image>();
            img.color = new Color(1f, 1f, 1f, 0f);
        }
        img.raycastTarget = true;
        btn.targetGraphic = img;
    }

    public void ShowPropertyCard(PlayerData player, TileData property, TileMarker marker)
    {
        if (player == null || property == null || marker == null) return;
        if (marker.propertyCard == null) { OnPurchaseDecision?.Invoke(false); return; }

        currentPlayer = player;
        currentProperty = property;
        currentCard = marker.propertyCard;
        cardOriginalPosition = currentCard.transform.position;
        cardOriginalRotation = currentCard.transform.rotation;
        cardOriginalScale = currentCard.transform.localScale;

        TryAssignCamera();
        UpdateUITexts();
        StartCoroutine(AnimateCardToPlayer(player));
    }

    private void UpdateUITexts()
    {
        if (balanceText != null) balanceText.text = $"Balance: {currentPlayer.money} DT";
        if (priceText != null) priceText.text = $"Price: {currentProperty.purchasePrice} DT";
        if (buyButton != null) buyButton.interactable = currentPlayer.CanAfford(currentProperty.purchasePrice);
    }

    private IEnumerator AnimateCardToPlayer(PlayerData player)
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) yield break;

        Vector3 origin = player.avatarTransform != null ? player.avatarTransform.position : cam.transform.position;

        Vector3 forward = cam.transform.forward;
        forward.y = 0f;
        if (forward.sqrMagnitude < 0.001f) forward = cam.transform.forward;
        forward.Normalize();

        Vector3 targetPos = origin + forward * cardDistanceFromPlayer + Vector3.up * cardDisplayHeight;

        // Build target rotation — stand card upright facing player, tilt for readability
        Vector3 toPlayer = (cam.transform.position - targetPos);
        toPlayer.y = 0f;
        toPlayer.Normalize();

        Quaternion standUp = Quaternion.LookRotation(toPlayer, Vector3.up);
        Quaternion flipArtToFront = Quaternion.AngleAxis(90f, Vector3.right);
        Quaternion upright = standUp * flipArtToFront;
        Quaternion tilt = Quaternion.AngleAxis(cardTiltAngle, upright * Vector3.right);
        Quaternion targetRot = tilt * upright;

        Vector3 targetScale = cardOriginalScale * cardDisplayScale;

        float elapsed = 0f;
        while (elapsed < flyDuration)
        {
            elapsed += Time.deltaTime;
            float t = flyCurve.Evaluate(elapsed / flyDuration);

            currentCard.transform.position   = Vector3.Lerp(cardOriginalPosition, targetPos, t);
            currentCard.transform.rotation   = Quaternion.Slerp(cardOriginalRotation, targetRot, t);
            currentCard.transform.localScale = Vector3.Lerp(cardOriginalScale, targetScale, t);
            yield return null;
        }

        currentCard.transform.position   = targetPos;
        currentCard.transform.rotation   = targetRot;
        currentCard.transform.localScale = targetScale;

        if (buttonPanel != null)
        {
            buttonPanel.transform.position = targetPos - Vector3.up * buttonPanelGap;
            buttonPanel.transform.LookAt(cam.transform);
            buttonPanel.transform.Rotate(0, 180, 0);
            buttonPanel.SetActive(true);
        }

        isWaitingForInput = true;
    }

    private void OnBuyClicked()
    {
        if (!isWaitingForInput || !currentPlayer.CanAfford(currentProperty.purchasePrice)) return;
        StartCoroutine(AnimateCardBack(true));
    }

    private void OnPassClicked()
    {
        if (!isWaitingForInput) return;
        StartCoroutine(AnimateCardBack(false));
    }

    private IEnumerator AnimateCardBack(bool didBuy)
    {
        isWaitingForInput = false;
        if (buttonPanel != null) buttonPanel.SetActive(false);

        float elapsed = 0f;
        Vector3 startPos = currentCard.transform.position;
        Quaternion startRot = currentCard.transform.rotation;
        Vector3 startScale = currentCard.transform.localScale;

        while (elapsed < flyDuration)
        {
          elapsed += Time.deltaTime;
          float t = flyCurve.Evaluate(elapsed / flyDuration);
         currentCard.transform.position   = Vector3.Lerp(startPos, cardOriginalPosition, t);
        currentCard.transform.rotation   = Quaternion.Slerp(startRot, cardOriginalRotation, t);
     currentCard.transform.localScale = Vector3.Lerp(startScale, cardOriginalScale, t);
            yield return null;
        }

        currentCard.transform.position   = cardOriginalPosition;
        currentCard.transform.rotation   = cardOriginalRotation;
        currentCard.transform.localScale = cardOriginalScale;
        currentCard = null;
        OnPurchaseDecision?.Invoke(didBuy);
    }

    public bool IsShowing() => isWaitingForInput;
}