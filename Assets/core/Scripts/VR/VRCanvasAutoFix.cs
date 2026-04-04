using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class VRCanvasAutoFix : MonoBehaviour
{
    private Canvas canvas;

    private void Awake()
    {
        canvas = GetComponent<Canvas>();
        if (canvas == null) return;

        canvas.renderMode = RenderMode.WorldSpace;

        GraphicRaycaster old = GetComponent<GraphicRaycaster>();
        if (old != null) Destroy(old);

        if (GetComponent<TrackedDeviceGraphicRaycaster>() == null)
            gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();

        foreach (Button btn in GetComponentsInChildren<Button>(true))
        {
            if (btn.targetGraphic is Image) continue;
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

    private void Start() => TryAssignCamera();

    private void Update()
    {
        if (canvas != null && canvas.worldCamera == null)
            TryAssignCamera();
    }

    private void TryAssignCamera()
    {
        if (canvas == null) return;
        Camera cam = VRCameraProvider.Camera;
        if (cam != null) canvas.worldCamera = cam;
    }
}