using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class VRCanvasDiagnostic : MonoBehaviour
{
    private int runCount = 0;

    private void Start()
    {
        Invoke(nameof(RunDiagnostic), 2f);
        Invoke(nameof(RunDiagnostic), 5f);
        Invoke(nameof(RunDiagnostic), 10f);
    }

    private void RunDiagnostic()
    {
        runCount++;
        Debug.Log($"===== VR CANVAS DIAGNOSTIC #{runCount} at {Time.timeSinceLevelLoad:F1}s =====");

        EventSystem es = FindObjectOfType<EventSystem>();
        if (es == null) { Debug.LogError("[DIAG] NO EventSystem in scene!"); return; }

        XRUIInputModule xrInput = es.GetComponent<XRUIInputModule>();
        StandaloneInputModule legacy = es.GetComponent<StandaloneInputModule>();

        if (xrInput == null)
            Debug.LogError("[DIAG] MISSING XRUIInputModule on EventSystem!");
        else
            Debug.Log($"[DIAG] XRUIInputModule OK (enabled={xrInput.enabled})");

        if (legacy != null && legacy.enabled)
            Debug.LogError("[DIAG] StandaloneInputModule ENABLED — blocks XR input! Remove it.");

        Camera main = Camera.main;
        Debug.Log($"[DIAG] Camera.main = {(main != null ? main.name : "NULL")}");
        foreach (Camera c in FindObjectsOfType<Camera>())
            Debug.Log($"[DIAG] Camera: '{c.name}' tag={c.tag}");

        foreach (Canvas c in FindObjectsOfType<Canvas>(true))
        {
            if (c.renderMode != RenderMode.WorldSpace) continue;
            Debug.Log($"[DIAG] WorldSpace Canvas: '{c.name}' active={c.gameObject.activeInHierarchy}");

            if (c.worldCamera == null)
                Debug.LogError($"[DIAG]   worldCamera = NULL on '{c.name}'!");
            else
                Debug.Log($"[DIAG]   worldCamera = '{c.worldCamera.name}'");

            if (c.GetComponent<TrackedDeviceGraphicRaycaster>() == null)
                Debug.LogError($"[DIAG]   MISSING TrackedDeviceGraphicRaycaster!");

            foreach (Button btn in c.GetComponentsInChildren<Button>(true))
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

        var nf = FindObjectsOfType<UnityEngine.XR.Interaction.Toolkit.Interactors.NearFarInteractor>(true);
        var ray = FindObjectsOfType<UnityEngine.XR.Interaction.Toolkit.Interactors.XRRayInteractor>(true);
        Debug.Log($"[DIAG] NearFarInteractor={nf.Length} XRRayInteractor={ray.Length}");
        if (nf.Length == 0 && ray.Length == 0)
            Debug.LogError("[DIAG] NO XR interactors! XR rig not spawned yet.");

        Debug.Log($"===== DIAGNOSTIC #{runCount} DONE =====");
    }
}