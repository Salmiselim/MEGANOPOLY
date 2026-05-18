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

    [Header("Scale")]
    [Tooltip("World space size of the canvas — 0.001 converts Unity units to metres")]
    public float canvasScale = 0.002f;

    private Camera _vrCamera;

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

        Debug.Log("[AuthWorldSpaceUI] Auth panel placed successfully.");
    }

    // ── Camera swap detection ─────────────────────────────────────────────────

    private void Update()
    {
        // Keep worldCamera up to date if the active camera changes
        if (Camera.main != null && _vrCamera != Camera.main)
        {
            _vrCamera = Camera.main;
            if (authCanvas != null) authCanvas.worldCamera = _vrCamera;
        }
    }
}