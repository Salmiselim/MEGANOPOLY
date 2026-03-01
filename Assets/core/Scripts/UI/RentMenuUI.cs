using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class RentMenuUI : MonoBehaviour
{
    public static RentMenuUI Instance { get; private set; }

    [Header("Panel Root")]
    [SerializeField] private GameObject menuPanel;

    [Header("Buttons")]
    [SerializeField] private Button payButton;

    [Header("Info Texts")]
    [SerializeField] private Text propertyNameText;
    [SerializeField] private Text ownerNameText;
    [SerializeField] private Text rentAmountText;
    [SerializeField] private Text balanceText;

    [Header("Display Settings")]
    [SerializeField] private float distanceFromPlayer = 1.5f;
    [SerializeField] private float heightAbovePlayer = 1.2f;
    [SerializeField] private float canvasWorldScale = 0.002f;

    private PlayerData currentPlayer;
    private TileData currentProperty;
    private string ownerName;
    private int rentAmount;
    private bool isShowing = false;
    private Canvas canvas;

    public UnityEvent<int> OnRentPaid = new UnityEvent<int>();

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
        if (payButton != null) payButton.onClick.AddListener(OnPayClicked);

        EnsureImageOnButton(payButton);
    }

    private void Start() => TryAssignCamera();

    private void Update()
    {
        if (canvas != null && canvas.worldCamera == null) TryAssignCamera();
        if (!isShowing) return;

        if (Input.GetKeyDown(KeyCode.Return) || Input.GetKeyDown(KeyCode.P))
            OnPayClicked();

        FaceCamera();
    }

    private void TryAssignCamera()
    {
        if (canvas == null) return;
        Camera cam = VRCameraProvider.Camera;
        if (cam != null) canvas.worldCamera = cam;
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

    public void ShowRentMenu(PlayerData player, TileData property, PlayerData owner)
    {
        if (player == null || property == null || owner == null) return;

        currentPlayer = player;
        currentProperty = property;
        ownerName = owner.playerName;
        rentAmount = property.GetCurrentRent();
        isShowing = true;

        TryAssignCamera();
        MoveCanvasToPlayer();
        if (menuPanel != null) menuPanel.SetActive(true);
        UpdateTexts();
        Debug.Log($"[RentMenuUI] Open: {player.playerName} owes {rentAmount} DT to {ownerName} for {property.tileName}");
    }

    public bool IsShowing() => isShowing;

    private void MoveCanvasToPlayer()
    {
        Camera cam = VRCameraProvider.Camera;
        if (cam == null) return;

        Vector3 forward = cam.transform.forward;
        forward.y = 0f;
        if (forward.sqrMagnitude < 0.001f) forward = cam.transform.forward;
        forward.Normalize();

        Vector3 origin = currentPlayer.avatarTransform != null
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
        if (propertyNameText != null)
            propertyNameText.text = currentProperty.tileName;

        if (ownerNameText != null)
            ownerNameText.text = $"Owner: {ownerName}";

        if (rentAmountText != null)
            rentAmountText.text = $"Rent: {rentAmount} DT";

        if (balanceText != null)
            balanceText.text = $"Your Balance: {currentPlayer.money} DT";

        if (payButton != null)
        {
            payButton.interactable = true;
            Text lbl = payButton.GetComponentInChildren<Text>();
            if (lbl != null)
                lbl.text = $"Pay {rentAmount} DT";
        }
    }

    private void OnPayClicked()
    {
        if (!isShowing) return;

        isShowing = false;
        if (menuPanel != null) menuPanel.SetActive(false);

        Debug.Log($"[RentMenuUI] {currentPlayer.playerName} pays {rentAmount} DT rent for {currentProperty.tileName}");
        OnRentPaid?.Invoke(rentAmount);
    }
}