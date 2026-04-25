using System.Collections;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Positions the Auth canvas in world space in front of the VR camera.
/// Waits for Camera.main to be ready — safe for pre-placed XR Origins.
/// Attach to: WorldSpaceAuth GO in AuthScene
/// </summary>
public class AuthWorldSpaceUI : MonoBehaviour
{
    [Header("Panel Reference")]
    [Tooltip("The World Space Canvas containing your Auth UI")]
    public Canvas authCanvas;

    [Header("Positioning")]
    [Tooltip("Distance in front of the camera")]
    public float distanceFromCamera = 1.5f;

    [Tooltip("Height offset relative to camera (negative = slightly below eye level)")]
    public float heightOffset = -0.1f;

    [Tooltip("How fast the panel smoothly follows if camera moves before settled")]
    public float settleSpeed = 5f;

    [Header("Scale")]
    [Tooltip("World space size of the canvas — 0.001 converts Unity units to metres")]
    public float canvasScale = 0.002f;

    private Camera _vrCamera;
    private bool _settled = false;

    private void Start()
    {
        StartCoroutine(WaitForCameraAndInit());
    }

    // ── Wait loop ─────────────────────────────────────────────────────────────

    private IEnumerator WaitForCameraAndInit()
    {
        // Retry every frame until Camera.main is available
        int attempts = 0;
        while (Camera.main == null)
        {
            attempts++;
            if (attempts % 60 == 0) // log every ~1 second so console isn't spammed
                Debug.LogWarning($"[AuthWorldSpaceUI] Waiting for Camera.main... ({attempts} frames)");

            yield return null; // wait one frame
        }

        _vrCamera = Camera.main;
        Debug.Log($"[AuthWorldSpaceUI] Camera found after {attempts} frames: {_vrCamera.name}");

        InitialisePanel();
    }

    // ── Initialise ────────────────────────────────────────────────────────────

    private void InitialisePanel()
    {
        if (authCanvas == null)
        {
            Debug.LogError("[AuthWorldSpaceUI] authCanvas is not assigned in the Inspector.");
            return;
        }

        // 1. Force the Canvas to accept XR Controller Laser Pointers
        var oldRaycaster = authCanvas.GetComponent<GraphicRaycaster>();
        if (oldRaycaster != null && authCanvas.GetComponent<UnityEngine.XR.Interaction.Toolkit.UI.TrackedDeviceGraphicRaycaster>() == null)
        {
            Destroy(oldRaycaster);
        }
        if (authCanvas.GetComponent<UnityEngine.XR.Interaction.Toolkit.UI.TrackedDeviceGraphicRaycaster>() == null)
        {
            authCanvas.gameObject.AddComponent<UnityEngine.XR.Interaction.Toolkit.UI.TrackedDeviceGraphicRaycaster>();
        }

        // 2. Force the EventSystem to use XR Input instead of Mouse/Keyboard
        var es = FindObjectOfType<UnityEngine.EventSystems.EventSystem>();
        if (es != null)
        {
            var standalone = es.GetComponent<UnityEngine.EventSystems.StandaloneInputModule>();
            if (standalone != null) Destroy(standalone);

            if (es.GetComponent<UnityEngine.XR.Interaction.Toolkit.UI.XRUIInputModule>() == null)
            {
                es.gameObject.AddComponent<UnityEngine.XR.Interaction.Toolkit.UI.XRUIInputModule>();
            }
        }

        // Switch to World Space if not already
        authCanvas.renderMode = RenderMode.WorldSpace;
        authCanvas.worldCamera = _vrCamera;

        // Scale the canvas so it looks right in metres (Forced to 0.002 to make it bigger)
        authCanvas.transform.localScale = Vector3.one * 0.002f;

        // Set canvas size (pixels × scale = world size)
        // 1200×900 px × 0.001 = 1.2m × 0.9m panel
        var rect = authCanvas.GetComponent<RectTransform>();
        if (rect != null)
        {
            rect.sizeDelta = new Vector2(1200f, 900f);
        }

        // Position it
        PlacePanelInFrontOfCamera();

        _settled = true;
        Debug.Log("[AuthWorldSpaceUI] Auth panel placed successfully.");
    }

    // ── Placement ─────────────────────────────────────────────────────────────

    private void PlacePanelInFrontOfCamera()
    {
        Vector3 forward = _vrCamera.transform.forward;
        forward.y = 0f;          // keep panel vertical
        forward.Normalize();

        Vector3 targetPos = _vrCamera.transform.position
                             + forward * distanceFromCamera
                             + Vector3.up * heightOffset;

        authCanvas.transform.position = targetPos;

        // Face the player
        authCanvas.transform.rotation = Quaternion.LookRotation(
            authCanvas.transform.position - _vrCamera.transform.position
        );
    }

    // ── Optional: re-settle if camera moves a lot before player touches UI ───

    private void Update()
    {
        if (!_settled) return;

        // Automatically update if the camera changes (e.g. from offline Rig over to Networked Rig)
        if (Camera.main != null && _vrCamera != Camera.main)
        {
            _vrCamera = Camera.main;
            if (authCanvas != null) authCanvas.worldCamera = _vrCamera;
        }

        if (_vrCamera == null) return;

        // Smoothly keep the panel in front until the player interacts
        // (stops updating once they look away — feel free to remove if unwanted)
        Vector3 forward = _vrCamera.transform.forward;
        forward.y = 0f;
        forward.Normalize();

        Vector3 targetPos = _vrCamera.transform.position
                          + forward * distanceFromCamera
                          + Vector3.up * heightOffset;

        // Only reposition if very far off (> 0.5 m) — avoids jitter
        if (Vector3.Distance(authCanvas.transform.position, targetPos) > 0.5f)
        {
            authCanvas.transform.position = Vector3.Lerp(
                authCanvas.transform.position,
                targetPos,
                Time.deltaTime * settleSpeed
            );

            authCanvas.transform.rotation = Quaternion.LookRotation(
                authCanvas.transform.position - _vrCamera.transform.position
            );
        }
    }
}