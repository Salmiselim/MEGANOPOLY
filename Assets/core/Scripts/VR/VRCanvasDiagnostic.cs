using System.Collections;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

/// <summary>
/// Drop on any persistent scene object (e.g. your GameManager GameObject).
/// Waits until Camera.main is available (after XROwnershipGuard enables Camera Offset),
/// then auto-fixes all World Space canvases and logs a full diagnostic.
/// </summary>
public class VRCanvasDiagnostic : MonoBehaviour
{
    [Header("Auto-Fix")]
    [Tooltip("Assign the active camera to all World Space canvases when Camera.main becomes available.")]
    [SerializeField] private bool autoFixCanvases = true;

    [Tooltip("Swap GraphicRaycaster → TrackedDeviceGraphicRaycaster on World Space canvases.")]
    [SerializeField] private bool autoAddTrackedRaycaster = true;

    [Tooltip("Remove StandaloneInputModule if found (it blocks XR input).")]
    [SerializeField] private bool autoRemoveStandaloneInput = true;

    [Header("Diagnostics")]
    [Tooltip("Run a full diagnostic log after fixing.")]
    [SerializeField] private bool runDiagnosticAfterFix = true;

    private int runCount = 0;

    // ── Start: poll until Camera.main is live ─────────────────────────────────

    private void Start()
    {
        StartCoroutine(WaitForCameraAndFix());
    }

    private IEnumerator WaitForCameraAndFix()
    {
        float waited = 0f;
        while (Camera.main == null)
        {
            yield return new WaitForSeconds(1f);
            waited += 1f;
            if (waited > 60f)
            {
                Debug.LogError("[VRDiag] Camera.main never became available after 60s. " +
                               "Check XROwnershipGuard and player spawn.");
                yield break;
            }
        }

        Debug.Log($"[VRDiag] Camera.main found: '{Camera.main.name}' after {waited:F0}s. Running fixes.");

        if (autoFixCanvases) FixWorldSpaceCanvases();
        if (autoRemoveStandaloneInput) FixEventSystem();
        if (runDiagnosticAfterFix) RunDiagnostic();

        // Run again at 10s in case late-spawned canvases appeared
        yield return new WaitForSeconds(10f);
        if (autoFixCanvases) FixWorldSpaceCanvases();
        if (runDiagnosticAfterFix) RunDiagnostic();
    }

    // ── Fixes ─────────────────────────────────────────────────────────────────

    private void FixWorldSpaceCanvases()
    {
        Camera main = Camera.main;
        if (main == null) return;

        foreach (Canvas canvas in FindObjectsOfType<Canvas>(true))
        {
            if (canvas.renderMode != RenderMode.WorldSpace) continue;

            // Assign world camera
            if (canvas.worldCamera == null)
            {
                canvas.worldCamera = main;
                Debug.Log($"[VRDiag] Assigned Camera.main to World Space canvas '{canvas.name}'.");
            }

            // Swap raycaster
            if (autoAddTrackedRaycaster)
            {
                GraphicRaycaster old = canvas.GetComponent<GraphicRaycaster>();
                if (old != null && canvas.GetComponent<TrackedDeviceGraphicRaycaster>() == null)
                {
                    Destroy(old);
                    canvas.gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();
                    Debug.Log($"[VRDiag] Swapped GraphicRaycaster → TrackedDeviceGraphicRaycaster on '{canvas.name}'.");
                }
            }
        }
    }

    private void FixEventSystem()
    {
        EventSystem es = FindObjectOfType<EventSystem>();
        if (es == null) return;

        StandaloneInputModule sim = es.GetComponent<StandaloneInputModule>();
        if (sim != null && sim.enabled)
        {
            sim.enabled = false;
            Debug.Log("[VRDiag] Disabled StandaloneInputModule (blocks XR input).");
        }

        if (es.GetComponent<XRUIInputModule>() == null)
        {
            es.gameObject.AddComponent<XRUIInputModule>();
            Debug.Log("[VRDiag] Added XRUIInputModule to EventSystem.");
        }
    }

    // ── Diagnostic log ────────────────────────────────────────────────────────

    private void RunDiagnostic()
    {
        runCount++;
        Debug.Log($"===== VR CANVAS DIAGNOSTIC #{runCount} at {Time.timeSinceLevelLoad:F1}s =====");

        // EventSystem
        EventSystem es = FindObjectOfType<EventSystem>();
        if (es == null) { Debug.LogError("[DIAG] NO EventSystem in scene!"); return; }

        XRUIInputModule xrInput = es.GetComponent<XRUIInputModule>();
        StandaloneInputModule legacy = es.GetComponent<StandaloneInputModule>();

        if (xrInput == null)
            Debug.LogError("[DIAG] MISSING XRUIInputModule on EventSystem!");
        else
            Debug.Log($"[DIAG] XRUIInputModule OK (enabled={xrInput.enabled})");

        if (legacy != null && legacy.enabled)
            Debug.LogError("[DIAG] StandaloneInputModule ENABLED — blocks XR input!");

        // Cameras
        Camera main = Camera.main;
        Debug.Log($"[DIAG] Camera.main = {(main != null ? main.name : "NULL")}");
        foreach (Camera c in FindObjectsOfType<Camera>())
            Debug.Log($"[DIAG] Camera: '{c.name}' tag={c.tag} active={c.gameObject.activeInHierarchy}");

        // World Space canvases
        foreach (Canvas canvas in FindObjectsOfType<Canvas>(true))
        {
            if (canvas.renderMode != RenderMode.WorldSpace) continue;
            Debug.Log($"[DIAG] WorldSpace Canvas: '{canvas.name}' active={canvas.gameObject.activeInHierarchy}");

            if (canvas.worldCamera == null)
                Debug.LogError($"[DIAG]   worldCamera = NULL on '{canvas.name}'!");
            else
                Debug.Log($"[DIAG]   worldCamera = '{canvas.worldCamera.name}'");

            if (canvas.GetComponent<TrackedDeviceGraphicRaycaster>() == null)
                Debug.LogError($"[DIAG]   MISSING TrackedDeviceGraphicRaycaster on '{canvas.name}'!");

            foreach (Button btn in canvas.GetComponentsInChildren<Button>(true))
            {
                Image img = btn.GetComponent<Image>();
                if (btn.targetGraphic == null)
                    Debug.LogError($"[DIAG]   Button '{btn.name}': NO targetGraphic!");
                else if (img == null || !img.raycastTarget)
                    Debug.LogError($"[DIAG]   Button '{btn.name}': Image missing or raycastTarget=false!");
                else
                    Debug.Log($"[DIAG]   Button '{btn.name}': OK interactable={btn.interactable}");
            }
        }

        // XR Interactors
        var nfi = FindObjectsOfType<UnityEngine.XR.Interaction.Toolkit.Interactors.NearFarInteractor>(true);
        var ray = FindObjectsOfType<UnityEngine.XR.Interaction.Toolkit.Interactors.XRRayInteractor>(true);
        Debug.Log($"[DIAG] NearFarInteractor={nfi.Length}  XRRayInteractor={ray.Length}");
        if (nfi.Length == 0 && ray.Length == 0)
            Debug.LogError("[DIAG] NO XR interactors found — XR rig may not be spawned yet.");

        Debug.Log($"===== DIAGNOSTIC #{runCount} DONE =====");
    }
}