using System.Collections;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;

/// <summary>
/// Animates property cards to fly in front of the player with Buy/Pass options
/// </summary>
public class PropertyCardUI : MonoBehaviour
{
    public static PropertyCardUI Instance { get; private set; }

    [Header("Animation Settings")]
    [SerializeField] private float flyDuration = 0.5f;
    [SerializeField] private float cardDisplayHeight = 2f;
    [SerializeField] private float cardDistanceFromPlayer = 3f;
    [SerializeField] private AnimationCurve flyCurve = AnimationCurve.EaseInOut(0, 0, 1, 1);

    [Header("UI Buttons (World Space Canvas)")]
    [SerializeField] private GameObject buttonPanel;
    [SerializeField] private Button buyButton;
    [SerializeField] private Button passButton;
    [SerializeField] private Text balanceText;
    [SerializeField] private Text priceText;

    [Header("References")]
    [SerializeField] private BoardManager boardManager;

    // Events
    public UnityEvent<bool> OnPurchaseDecision = new UnityEvent<bool>();

    // State
    private GameObject currentCard;
    private Vector3 cardOriginalPosition;
    private Quaternion cardOriginalRotation;
    private Vector3 cardOriginalScale;
    private TileData currentProperty;
    private PlayerData currentPlayer;
    private bool isWaitingForInput = false;

    private void Awake()
    {
        if (Instance == null)
            Instance = this;
        else
            Destroy(gameObject);

        if (boardManager == null)
            boardManager = FindObjectOfType<BoardManager>();

        if (buttonPanel != null)
            buttonPanel.SetActive(false);

        if (buyButton != null)
            buyButton.onClick.AddListener(OnBuyClicked);

        if (passButton != null)
            passButton.onClick.AddListener(OnPassClicked);
    }

    private void Update()
    {
        if (!isWaitingForInput) return;

        // Keyboard shortcuts
        if (Input.GetKeyDown(KeyCode.B) || Input.GetKeyDown(KeyCode.Return))
        {
            OnBuyClicked();
        }
        else if (Input.GetKeyDown(KeyCode.P) || Input.GetKeyDown(KeyCode.Escape))
        {
            OnPassClicked();
        }
    }

    /// <summary>
    /// Show property card flying to player with purchase options
    /// </summary>
    public void ShowPropertyCard(PlayerData player, TileData property, TileMarker marker)
    {
        if (player == null || property == null || marker == null) return;
        if (marker.propertyCard == null)
        {
            Debug.LogWarning($"⚠️ No property card assigned for {property.tileName}");
            OnPurchaseDecision?.Invoke(false);
            return;
        }

        currentPlayer = player;
        currentProperty = property;
        currentCard = marker.propertyCard;

        // Store original transform
        cardOriginalPosition = currentCard.transform.position;
        cardOriginalRotation = currentCard.transform.rotation;
        cardOriginalScale = currentCard.transform.localScale;

        // Update UI texts
        UpdateUITexts();

        // Start animation
        StartCoroutine(AnimateCardToPlayer(player));
    }

    private void UpdateUITexts()
    {
        if (balanceText != null)
            balanceText.text = $"Your Balance: {currentPlayer.money} DT";

        if (priceText != null)
            priceText.text = $"Price: {currentProperty.purchasePrice} DT";

        if (buyButton != null)
            buyButton.interactable = currentPlayer.CanAfford(currentProperty.purchasePrice);
    }

    private IEnumerator AnimateCardToPlayer(PlayerData player)
    {
        if (player.avatarTransform == null) yield break;

        // Calculate target position in front of player
        Vector3 playerPos = player.avatarTransform.position;
        Vector3 cameraForward = Camera.main != null ? Camera.main.transform.forward : Vector3.forward;
        cameraForward.y = 0;
        cameraForward.Normalize();

        Vector3 targetPosition = playerPos + cameraForward * cardDistanceFromPlayer + Vector3.up * cardDisplayHeight;

        // Face the camera
        Quaternion targetRotation = Quaternion.LookRotation(cameraForward, Vector3.up);

        // Animate card flying to position
        float elapsed = 0f;
        Vector3 startPos = cardOriginalPosition;
        Quaternion startRot = cardOriginalRotation;

        while (elapsed < flyDuration)
        {
            elapsed += Time.deltaTime;
            float t = flyCurve.Evaluate(elapsed / flyDuration);

            currentCard.transform.position = Vector3.Lerp(startPos, targetPosition, t);
            currentCard.transform.rotation = Quaternion.Slerp(startRot, targetRotation, t);

            // Add a slight scale pop
            float scaleT = Mathf.Sin(t * Mathf.PI);
            currentCard.transform.localScale = cardOriginalScale * (1f + scaleT * 0.1f);

            yield return null;
        }

        // Ensure final position
        currentCard.transform.position = targetPosition;
        currentCard.transform.rotation = targetRotation;
        currentCard.transform.localScale = cardOriginalScale;

        // Show buttons
        ShowButtons(targetPosition);

        isWaitingForInput = true;

        Debug.Log($"📋 Showing card for {currentProperty.tileName}");
        Debug.Log($"   Price: {currentProperty.purchasePrice} DT | Your Balance: {currentPlayer.money} DT");
        Debug.Log($"   Press [B] to BUY or [P] to PASS");
    }

    private void ShowButtons(Vector3 cardPosition)
    {
        if (buttonPanel == null) return;

        // Position buttons below the card
        buttonPanel.transform.position = cardPosition + Vector3.down * 1.5f;

        // Face camera
        if (Camera.main != null)
        {
            buttonPanel.transform.LookAt(Camera.main.transform);
            buttonPanel.transform.Rotate(0, 180, 0);
        }

        buttonPanel.SetActive(true);
    }

    private void OnBuyClicked()
    {
        if (!isWaitingForInput) return;

        if (!currentPlayer.CanAfford(currentProperty.purchasePrice))
        {
            Debug.Log("❌ Cannot afford this property!");
            return;
        }

        Debug.Log($"✓ {currentPlayer.playerName} chose to BUY {currentProperty.tileName}");

        StartCoroutine(AnimateCardBack(true));
    }

    private void OnPassClicked()
    {
        if (!isWaitingForInput) return;

        Debug.Log($"✓ {currentPlayer.playerName} chose to PASS on {currentProperty.tileName}");

        StartCoroutine(AnimateCardBack(false));
    }

    private IEnumerator AnimateCardBack(bool didBuy)
    {
        isWaitingForInput = false;

        if (buttonPanel != null)
            buttonPanel.SetActive(false);

        // Animate card back to original position
        float elapsed = 0f;
        Vector3 startPos = currentCard.transform.position;
        Quaternion startRot = currentCard.transform.rotation;

        while (elapsed < flyDuration)
        {
            elapsed += Time.deltaTime;
            float t = flyCurve.Evaluate(elapsed / flyDuration);

            currentCard.transform.position = Vector3.Lerp(startPos, cardOriginalPosition, t);
            currentCard.transform.rotation = Quaternion.Slerp(startRot, cardOriginalRotation, t);

            yield return null;
        }

        // Ensure original transform
        currentCard.transform.position = cardOriginalPosition;
        currentCard.transform.rotation = cardOriginalRotation;
        currentCard.transform.localScale = cardOriginalScale;

        currentCard = null;

        OnPurchaseDecision?.Invoke(didBuy);
    }

    public bool IsShowing()
    {
        return isWaitingForInput;
    }
}