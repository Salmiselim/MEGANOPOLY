using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

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
    [Tooltip("Metres in front of the player (1.5 = normal VR scale)")]
    [SerializeField] private float distanceFromPlayer = 1.5f;
    [Tooltip("Metres above the player pivot (1.2 = normal VR scale)")]
    [SerializeField] private float heightAbovePlayer = 1.2f;
    [Tooltip("Canvas world scale — 0.001 to 0.003 for VR")]
    [SerializeField] private float canvasWorldScale = 0.002f;

    private PlayerData currentPlayer;
    private TileData currentProperty;
    private bool isShowing = false;
    private Canvas canvas;

    public UnityEvent OnMenuClosed = new UnityEvent();

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
        if (Input.GetKeyDown(KeyCode.Return) || Input.GetKeyDown(KeyCode.Escape)) OnEndTurnClicked();
        FaceCamera();
    }

    private void TryAssignCamera()
    {
        if (canvas == null) return;
        Camera cam = VRCameraProvider.Camera;
        if (cam != null) canvas.worldCamera = cam;
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
        if (img == null)
        {
            img = btn.gameObject.AddComponent<Image>();
            img.color = new Color(1f, 1f, 1f, 0f);
        }
        img.raycastTarget = true;
        btn.targetGraphic = img;
    }

    public void ShowBuildingMenu(PlayerData player, TileData property)
    {
        if (player == null || property == null) return;
        if (property.ownerId != player.playerId) return;

        currentPlayer = player;
        currentProperty = property;
        isShowing = true;

        TryAssignCamera();
        MoveCanvasToPlayer();
        if (menuPanel != null) menuPanel.SetActive(true);
        UpdateTexts();
        Debug.Log($"[BuildingMenuUI] Open: {property.tileName}");
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
        if (propertyNameText != null) propertyNameText.text = currentProperty.tileName;
        int houseCost = currentProperty.houseCost;
        int hotelCost = currentProperty.hotelCost > 0 ? currentProperty.hotelCost : currentProperty.houseCost;
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

    private void OnBuyHouseClicked()
    {
        if (!isShowing || PropertyManager.Instance == null) return;
        if (PropertyManager.Instance.TryBuyHouse(currentPlayer, currentProperty))
        { Debug.Log($"House built on {currentProperty.tileName}!"); UpdateTexts(); }
    }

    private void OnBuyHotelClicked()
    {
        if (!isShowing || PropertyManager.Instance == null) return;
        if (PropertyManager.Instance.TryBuyHotel(currentPlayer, currentProperty))
        { Debug.Log($"Hotel built on {currentProperty.tileName}!"); UpdateTexts(); }
    }

    private void OnEndTurnClicked()
    {
        if (!isShowing) return;
        isShowing = false;
        if (menuPanel != null) menuPanel.SetActive(false);
        Debug.Log("[BuildingMenuUI] Closed");
        OnMenuClosed?.Invoke();
    }
}