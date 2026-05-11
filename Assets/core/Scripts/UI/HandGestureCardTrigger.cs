using UnityEngine;
using Unity.Services.CloudSave;
using Unity.Services.Authentication;
using System.Collections.Generic;
using System.Threading.Tasks;

public class HandGestureCardTrigger : MonoBehaviour
{
    private const string KEY_PLAYER_PROFILE = "player_profile";
    private const string KEY_PROPERTIES = "owned_properties";

    [Header("Card")]
    public PlayerCardUI cardUI;

    [Header("Placement (relative to camera)")]
    [Tooltip("Distance in front of the camera the card sits when shown (meters).")]
    public float distanceFromCamera = 0.6f;

    [Tooltip("Vertical offset applied so the card doesn't sit dead-center in the view.")]
    public float verticalOffset = -0.05f;

    [Tooltip("Horizontal offset (positive = right of view center).")]
    public float horizontalOffset = 0f;

    [Tooltip("Uniform scale applied to the card. World Space canvases need ~0.001.")]
    public float scale = 0.001f;

    [Header("Behavior")]
    [Tooltip("If true, the card faces the camera each frame.")]
    public bool billboardToCamera = true;

    [Tooltip("Cooldown after a toggle so a held palm-open doesn't spam toggles.")]
    public float toggleCooldownSeconds = 0.5f;

    [Header("Animation")]
    [Tooltip("How long the pop-in / pop-out animation lasts (seconds).")]
    public float popDuration = 0.22f;

    [Tooltip("Peak scale multiplier during the overshoot bounce (1.0 = no overshoot).")]
    public float popOvershoot = 1.15f;

    [Header("Audio")]
    [Tooltip("Sound played when the card pops in.")]
    public AudioClip openSfx;

    [Tooltip("Sound played when the card closes (optional).")]
    public AudioClip closeSfx;

    [Range(0f, 1f)]
    [Tooltip("Volume scalar applied to both open and close SFX.")]
    public float sfxVolume = 0.7f;

    private AudioSource _audioSource;
    private bool _isOpen;
    private float _lastToggleTime = -999f;
    private bool _dataLoadedOnce;

    private bool _initialized;

    private void Awake()
    {
        TryResolveCard();
    }

    private void Start()
    {
        // Retry on Start in case the singleton was created later in Awake order.
        TryResolveCard();
    }

    private void TryResolveCard()
    {
        if (_initialized) return;

        if (PlayerCardUI.Instance != null) cardUI = PlayerCardUI.Instance;
        if (cardUI == null) cardUI = FindFirstObjectByType<PlayerCardUI>();
        if (cardUI == null) return; // try again later, when the gesture fires

        cardUI.transform.SetParent(null, worldPositionStays: true);
        cardUI.transform.localScale = new Vector3(scale, scale, scale);
        if (cardUI.cardRoot != null) cardUI.cardRoot.SetActive(false);
        _isOpen = false;
        _initialized = true;
    }

    private void LateUpdate()
    {
        if (!_isOpen || cardUI == null) return;
        UpdateWorldPose();
    }

    /// <summary>Wired to StaticHandGesture.GesturePerformed.</summary>
    public async void OnPalmOpenGesture()
    {
        // Lazy resolve in case Awake/Start ran before the singleton existed.
        if (!_initialized) TryResolveCard();

        if (cardUI == null)
        {
            Debug.LogError("[HandGestureCardTrigger] No PlayerCardUI found. Make sure PlayerCardSpawner is in the scene with cardPrefab assigned.");
            return;
        }
        if (cardUI.cardRoot == null) return;
        if (Time.time - _lastToggleTime < toggleCooldownSeconds) return;
        _lastToggleTime = Time.time;

        _isOpen = !_isOpen;

        if (_isOpen)
        {
            cardUI.cardRoot.SetActive(true);
            UpdateWorldPose();
            StartPopAnimation(opening: true);
            PlayOneShot(openSfx);
            if (!_dataLoadedOnce)
            {
                await LoadAndDisplayPlayerData();
                _dataLoadedOnce = true;
            }
        }
        else
        {
            StartPopAnimation(opening: false);
            PlayOneShot(closeSfx);
        }
    }

    private void PlayOneShot(AudioClip clip)
    {
        if (clip == null) return;
        if (_audioSource == null)
        {
            _audioSource = gameObject.AddComponent<AudioSource>();
            _audioSource.playOnAwake = false;
            _audioSource.spatialBlend = 0f; // 2D — UI sound, not positional
        }
        _audioSource.PlayOneShot(clip, sfxVolume);
    }

    private Coroutine _popRoutine;

    private void StartPopAnimation(bool opening)
    {
        if (_popRoutine != null) StopCoroutine(_popRoutine);
        _popRoutine = StartCoroutine(PopRoutine(opening));
    }

    private System.Collections.IEnumerator PopRoutine(bool opening)
    {
        float full = scale;
        float t = 0f;
        var card = cardUI.transform;

        if (opening)
        {
            // 0 → overshoot → full
            while (t < popDuration)
            {
                t += Time.deltaTime;
                float u = Mathf.Clamp01(t / popDuration);
                // Back-out easing: overshoots then settles.
                float s = EaseOutBack(u, popOvershoot) * full;
                card.localScale = new Vector3(s, s, s);
                yield return null;
            }
            card.localScale = new Vector3(full, full, full);
        }
        else
        {
            // full → 0 (faster, ease-in)
            float startScale = card.localScale.x;
            while (t < popDuration)
            {
                t += Time.deltaTime;
                float u = Mathf.Clamp01(t / popDuration);
                float s = Mathf.Lerp(startScale, 0f, u * u); // ease-in quadratic
                card.localScale = new Vector3(s, s, s);
                yield return null;
            }
            card.localScale = Vector3.zero;
            cardUI.cardRoot.SetActive(false);
        }
        _popRoutine = null;
    }

    /// <summary>
    /// Back-out easing: smoothly approaches 1, briefly overshoots past it, settles.
    /// strength controls the peak (1.0 = no overshoot, 1.15 = ~15% overshoot).
    /// </summary>
    private static float EaseOutBack(float u, float strength)
    {
        float overshoot = (strength - 1f) * 10f; // tuning: maps 1.15 -> 1.5
        float c1 = overshoot;
        float c3 = c1 + 1f;
        float um1 = u - 1f;
        return 1f + c3 * um1 * um1 * um1 + c1 * um1 * um1;
    }

    private void UpdateWorldPose()
    {
        var cam = VRCameraProvider.Camera;
        if (cam == null) return;

        var camT = cam.transform;
        cardUI.transform.position = camT.position
                                  + camT.forward * distanceFromCamera
                                  + camT.up      * verticalOffset
                                  + camT.right   * horizontalOffset;

        if (billboardToCamera)
            cardUI.transform.rotation = Quaternion.LookRotation(cardUI.transform.position - camT.position, camT.up);
    }

    private async Task LoadAndDisplayPlayerData()
    {
        if (!AuthenticationService.Instance.IsSignedIn)
        {
            Debug.LogWarning("[HandGestureCardTrigger] Not signed in — skipping cloud load.");
            return;
        }

        try
        {
            var keys = new HashSet<string> { KEY_PLAYER_PROFILE, KEY_PROPERTIES };
            var results = await CloudSaveService.Instance.Data.Player.LoadAsync(keys);

            string profileJson = results != null && results.TryGetValue(KEY_PLAYER_PROFILE, out var profileEntry)
                ? profileEntry.Value.GetAsString()
                : null;

            var indices = new List<int>();
            if (results != null && results.TryGetValue(KEY_PROPERTIES, out var propsEntry))
            {
                string raw = propsEntry.Value.GetAsString();
                Debug.Log($"[HandGestureCardTrigger] owned_properties raw JSON: {raw}");
                var propData = JsonUtility.FromJson<PropertySaveData>(raw);
                if (propData != null && propData.ownedIndices != null)
                    indices = propData.ownedIndices;
                Debug.Log($"[HandGestureCardTrigger] Parsed {indices.Count} property indices: [{string.Join(",", indices)}]");
            }
            else
            {
                Debug.LogWarning("[HandGestureCardTrigger] No 'owned_properties' key in cloud save.");
            }

            if (profileJson != null)
                cardUI.PopulateFromCloudData(profileJson, indices);
            else
                Debug.LogWarning("[HandGestureCardTrigger] No player_profile in cloud save.");

            // Always show the live auth username — overrides whatever name the cloud profile had.
            string liveName = AuthenticationService.Instance.PlayerName;
            if (!string.IsNullOrEmpty(liveName) && cardUI.playerNameText != null)
            {
                // Unity returns names in the form "username#1234" — strip the discriminator.
                int hashIdx = liveName.IndexOf('#');
                cardUI.playerNameText.text = hashIdx > 0 ? liveName.Substring(0, hashIdx) : liveName;
            }
        }
        catch (System.Exception e)
        {
            Debug.LogError($"[HandGestureCardTrigger] Cloud load failed: {e.Message}");
        }
    }
}
