using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

/// <summary>
/// Shown when a player lands on a Railroad/Station tile.
/// Receives only primitive/string data — no Assembly-CSharp types.
/// </summary>
public class TrainMenuUI : MonoBehaviour
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
    [SerializeField] private float heightAbovePlayer  = 1.2f;
    [SerializeField] private float canvasWorldScale   = 0.002f;

    private string  _fromName;
    private string  _toName;
    private int     _fare;
    private int     _playerMoney;
    private Vector3 _playerPosition;
    private bool  _isShowing;
  private Canvas  _canvas;

    /// <summary>true = took train, false = passed</summary>
    public UnityEvent<bool> OnDecision = new UnityEvent<bool>();

    private void Awake()
    {
    if (Instance == null) Instance = this;
        else { Destroy(gameObject); return; }

      _canvas = GetComponent<Canvas>();
        if (_canvas != null) _canvas.renderMode = RenderMode.WorldSpace;

        GraphicRaycaster old = GetComponent<GraphicRaycaster>();
    if (old != null) DestroyImmediate(old);
  if (GetComponent<TrackedDeviceGraphicRaycaster>() == null)
   gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();

    transform.localScale = Vector3.one * canvasWorldScale;

        if (menuPanel != null) menuPanel.SetActive(false);
  if (takeTrain  != null) takeTrain.onClick.AddListener(OnTakeTrainClicked);
        if (passButton != null) passButton.onClick.AddListener(OnPassClicked);
  EnsureImage(takeTrain);
EnsureImage(passButton);
    }

    private void Start()
    {
        if (_canvas != null && Camera.main != null)
  _canvas.worldCamera = Camera.main;
    }

    private void Update()
    {
        if (_canvas != null && _canvas.worldCamera == null && Camera.main != null)
      _canvas.worldCamera = Camera.main;

        if (!_isShowing) return;
        FaceCamera();

      if (Input.GetKeyDown(KeyCode.T)) OnTakeTrainClicked();
   if (Input.GetKeyDown(KeyCode.P) || Input.GetKeyDown(KeyCode.Escape)) OnPassClicked();
    }

    // ?? Public API — only primitives, no Assembly-CSharp types ??????????????

    public void ShowTrainMenu(string fromName, string toName, int fare,
          int playerMoney, Vector3 playerWorldPos)
    {
        _fromName       = fromName;
   _toName         = toName;
        _fare           = fare;
        _playerMoney    = playerMoney;
        _playerPosition = playerWorldPos;
      _isShowing      = true;

        if (_canvas != null && Camera.main != null)
         _canvas.worldCamera = Camera.main;

        PositionCanvas();
        UpdateTexts();
        if (menuPanel != null) menuPanel.SetActive(true);

        Debug.Log($"[TrainMenuUI] {fromName} ? {toName}  fare={fare} DT");
    }

    public bool IsShowing() => _isShowing;

    // ?? Buttons ???????????????????????????????????????????????????????????????

    private void OnTakeTrainClicked()
    {
  if (!_isShowing) return;
        _isShowing = false;
        if (menuPanel != null) menuPanel.SetActive(false);
        Debug.Log($"[TrainMenuUI] Player takes train to {_toName}");
        OnDecision?.Invoke(true);
    }

  private void OnPassClicked()
  {
        if (!_isShowing) return;
        _isShowing = false;
        if (menuPanel != null) menuPanel.SetActive(false);
     Debug.Log($"[TrainMenuUI] Player passes at {_fromName}");
 OnDecision?.Invoke(false);
    }

    // ?? Texts ?????????????????????????????????????????????????????????????????

    private void UpdateTexts()
    {
      if (titleText   != null) titleText.text   = "TRAIN STATION";
  if (fromText    != null) fromText.text    = $"From: {_fromName}";
        if (toText      != null) toText.text  = $"To:   {_toName}";
    if (fareText    != null) fareText.text    = $"Ticket: {_fare} DT";
        if (balanceText != null) balanceText.text = $"Balance: {_playerMoney} DT";

        if (takeTrain != null)
        {
 bool canAfford = _playerMoney >= _fare;
     takeTrain.interactable = canAfford;
 Text lbl = takeTrain.GetComponentInChildren<Text>();
          if (lbl != null)
       lbl.text = canAfford ? $"Take Train  ({_fare} DT)" : "Can't Afford";
        }

     if (passButton != null)
        {
      Text lbl = passButton.GetComponentInChildren<Text>();
    if (lbl != null) lbl.text = "Pass (Stay)";
     }
    }

    // ?? Positioning ???????????????????????????????????????????????????????????

    private void PositionCanvas()
    {
        Camera cam = Camera.main;
     if (cam == null) return;

        Vector3 forward = cam.transform.forward;
    forward.y = 0f;
   if (forward.sqrMagnitude < 0.001f) forward = Vector3.forward;
        forward.Normalize();

        transform.position = _playerPosition + forward * distanceFromPlayer
           + Vector3.up * heightAbovePlayer;
        FaceCamera();
    }

    private void FaceCamera()
    {
        Camera cam = Camera.main;
        if (cam == null) return;
        Vector3 dir = transform.position - cam.transform.position;
      if (dir.sqrMagnitude > 0.001f)
   transform.rotation = Quaternion.LookRotation(dir.normalized, Vector3.up);
  }

    private static void EnsureImage(Button btn)
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
}
