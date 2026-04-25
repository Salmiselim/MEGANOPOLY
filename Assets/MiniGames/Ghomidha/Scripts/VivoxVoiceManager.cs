using System.Collections.Generic;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using Unity.Services.Core;
using Unity.Services.Vivox;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR;
using TMPro;
using XRInputDevice = UnityEngine.XR.InputDevice;
using XRCommonUsages = UnityEngine.XR.CommonUsages;

/// <summary>
/// Manages Vivox voice chat for Meganopoly.
/// - Initializes Unity Gaming Services and signs in anonymously
/// - Joins a shared voice channel automatically
/// - Push-to-talk via keyboard key (editor) or Quest controller button (device)
/// - Singleton with DontDestroyOnLoad so voice persists across scenes
///
/// Setup:
/// 1. Create an empty GameObject, name it "VivoxManager"
/// 2. Attach this script
/// 3. Make sure Vivox is enabled in your Unity Dashboard (dashboard.unity3d.com)
/// 4. Make sure your project is linked in Edit > Project Settings > Services
/// </summary>
public class VivoxVoiceManager : MonoBehaviour
{
    // ── Singleton ────────────────────────────────────────────────────────────
    public static VivoxVoiceManager Instance { get; private set; }

    // ── Inspector ─────────────────────────────────────────────────────────────
    [Header("Vivox Settings")]
    [Tooltip("Name of the voice channel all players join.")]
    [SerializeField] private string channelName = "GlobalVoice";

    [Header("UI (Optional)")]
    [Tooltip("Optional TMP text to display the mic status (MUTED/UNMUTED).")]
    [SerializeField] private TMP_Text micStatusText;

    [Header("Push To Talk")]
    [Tooltip("Keyboard key for press-to-toggle mic (editor / simulator). Uses new Input System key names.")]
    [SerializeField] private Key pushToTalkKey = Key.Space;

    [Tooltip("When ON, pressing the Quest right-controller Primary Button (A) also toggles the mic.")]
    [SerializeField] private bool useXRButton = true;

    [Header("Mic Behavior")]
    [Tooltip("If true, the mic starts MUTED right after joining the channel.")]
    [SerializeField] private bool startMuted = true;

    // ── State ─────────────────────────────────────────────────────────────────
    private bool _isVivoxConnected   = false;
    private bool _isInChannel        = false;
    private bool _isMicActive        = false; // true = unmuted (transmitting allowed)
    private bool _loggedKeyboardNull = false;
    private XRInputDevice _rightController;
    private bool _lastXRPrimaryButton = false;

    // ─────────────────────────────────────────────────────────────────────────
    #region Unity Lifecycle
    // ─────────────────────────────────────────────────────────────────────────

    private void Awake()
    {
        // Destroy duplicates that appear on scene reload
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        // Allow keyboard input even when the Game window is not focused (editor testing)
        InputSystem.settings.backgroundBehavior = InputSettings.BackgroundBehavior.IgnoreFocus;

        UpdateMicStatusText();
    }

    private async void Start()
    {
        await InitializeVivoxAsync();
    }

    private void Update()
    {
        if (!_isInChannel) return;

        if (IsTogglePressedThisFrame())
            ToggleMic();
    }

    private async void OnApplicationQuit()
    {
        if (_isInChannel && VivoxService.Instance != null)
        {
            try { await VivoxService.Instance.LeaveAllChannelsAsync(); }
            catch { /* ignore on quit */ }
        }
    }

    #endregion

    // ─────────────────────────────────────────────────────────────────────────
    #region Vivox Initialization
    // ─────────────────────────────────────────────────────────────────────────

    private async Task InitializeVivoxAsync()
    {
        try
        {
            // 1. Initialize Unity Gaming Services
            if (UnityServices.State == ServicesInitializationState.Uninitialized)
                await UnityServices.InitializeAsync();

            // 2. Sign in anonymously (Vivox requires a valid UGS auth token)
            if (!AuthenticationService.Instance.IsSignedIn)
            {
                try
                {
                    await AuthenticationService.Instance.SignInAnonymouslyAsync();
                }
                catch (AuthenticationException ex) when (ex.Message.Contains("already signing in") || ex.ErrorCode == 10002)
                {
                    // Another script is mid sign-in — wait for it to finish
                    Debug.Log("[Vivox] Sign-in already in progress by another script, waiting...");
                    while (!AuthenticationService.Instance.IsSignedIn)
                        await Task.Delay(50);
                }
                Debug.Log($"[Vivox] Signed in. Player ID: {AuthenticationService.Instance.PlayerId}");
            }

            // 3. Initialize Vivox SDK
            await VivoxService.Instance.InitializeAsync();
            _isVivoxConnected = true;
            Debug.Log("[Vivox] Initialized successfully.");

            // 4. Join the shared voice channel — mic stays open for testing
            await JoinChannelAsync();
        }
        catch (System.Exception e)
        {
            Debug.LogError(
                "[Vivox] Setup failed. Make sure:\n" +
                "  1. Your project is linked in Project Settings > Services\n" +
                "  2. Vivox is enabled in your Unity Dashboard\n" +
                "  3. Your PC clock is synced (Win+I > Time & Language > Sync Now)\n" +
                $"Error: {e.Message}");
        }
    }

    private async Task JoinChannelAsync()
    {
        if (!_isVivoxConnected || _isInChannel) return;

        try
        {
            await VivoxService.Instance.JoinGroupChannelAsync(channelName.Trim(), ChatCapability.AudioOnly);
            _isInChannel = true;
            Debug.Log($"[Vivox] Joined channel: {channelName}");

            // Immediately enforce the starting mic state (prevents any brief open-mic moment on join).
            Debug.Log($"[Vivox] Applying startMuted={startMuted} after join.");
            SetMicMuted(startMuted, log: true);
        }
        catch (System.Exception e)
        {
            Debug.LogError($"[Vivox] Failed to join channel '{channelName}': {e.Message}");
        }
    }

    #endregion

    // ─────────────────────────────────────────────────────────────────────────
    #region Toggle Input (Press)
    // ─────────────────────────────────────────────────────────────────────────

    /// <summary>
    /// Returns true on the exact frame the toggle input is PRESSED.
    /// Supports keyboard (editor) and Quest right-controller A button (device).
    /// </summary>
    private bool IsTogglePressedThisFrame()
    {
        // Keyboard (editor / XR Device Simulator) — new Input System
        var keyboard = Keyboard.current;
        if (keyboard == null)
        {
            if (!_loggedKeyboardNull)
            {
                _loggedKeyboardNull = true;
                Debug.LogWarning("[Vivox] Keyboard.current is NULL — PTT keyboard shortcut unavailable. " +
                                 "Use Quest A button instead, or click the Game window to focus it.");
            }
        }
        else if (keyboard[pushToTalkKey].wasPressedThisFrame)
        {
            return true;
        }

        // Quest right-controller Primary Button (A) — rising edge only
        if (useXRButton)
        {
            if (!_rightController.isValid)
            {
                var devices = new List<XRInputDevice>();
                InputDevices.GetDevicesAtXRNode(XRNode.RightHand, devices);
                if (devices.Count > 0) _rightController = devices[0];
            }

            if (_rightController.isValid &&
                _rightController.TryGetFeatureValue(XRCommonUsages.primaryButton, out bool held))
            {
                bool pressedThisFrame = held && !_lastXRPrimaryButton;
                _lastXRPrimaryButton = held;
                if (pressedThisFrame) return true;
            }
        }

        return false;
    }

    #endregion

    // ─────────────────────────────────────────────────────────────────────────
    #region Public API
    // ─────────────────────────────────────────────────────────────────────────

    /// <summary>Force-mutes the local mic regardless of PTT state.</summary>
    public void ForceMute()
    {
        Debug.Log($"[Vivox] ForceMute() called. isReady={_isInChannel}");
        if (!_isInChannel) return;
        SetMicMuted(true, log: true);
    }

    /// <summary>
    /// Toggle mic muted/unmuted (press مرة = unmute, press ثانية = mute).
    /// Hook this up to a VR button OnClick / OnPress event.
    /// </summary>
    public void ToggleMic()
    {
        Debug.Log($"[Vivox] ToggleMic() called. isReady={_isInChannel} currentActive={_isMicActive}");
        if (!_isInChannel) return;
        // SetMicMuted(true) means "mute the mic".
        // So if we're currently active/unmuted, we want to mute (true). If currently muted, we want to unmute (false).
        SetMicMuted(_isMicActive, log: true);
    }

    /// <summary>True if the local mic is currently transmitting.</summary>
    public bool IsMicActive => _isMicActive;

    /// <summary>True once Vivox is initialized and the channel is joined.</summary>
    public bool IsReady => _isInChannel;

    #endregion

    // ─────────────────────────────────────────────────────────────────────────
    #region Mic State Helpers
    // ─────────────────────────────────────────────────────────────────────────

    private void SetMicMuted(bool muted, bool log)
    {
        if (!_isInChannel) return;

        try
        {
            if (muted)
            {
                VivoxService.Instance.MuteInputDevice();
                _isMicActive = false;
                if (log) Debug.Log("[Vivox] MIC MUTED");
            }
            else
            {
                VivoxService.Instance.UnmuteInputDevice();
                _isMicActive = true;
                if (log) Debug.Log("[Vivox] MIC UNMUTED (speaking allowed)");
            }
        }
        catch (System.Exception e)
        {
            Debug.LogError($"[Vivox] Failed to set mic state: {e.Message}");
        }

        UpdateMicStatusText();
    }

    private void UpdateMicStatusText()
    {
        if (micStatusText == null) return;
        micStatusText.text = _isMicActive ? "MIC: UNMUTED" : "MIC: MUTED";
    }

    #endregion
}
