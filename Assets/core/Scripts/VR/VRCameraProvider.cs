using System.Collections;
using UnityEngine;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class VRCameraProvider : MonoBehaviour
{
    public static VRCameraProvider Instance { get; private set; }
    private static Camera s_Camera;

    public static Camera Camera
    {
        get
        {
  if (s_Camera != null) return s_Camera;
            s_Camera = FindVRCamera();
          return s_Camera;
      }
    }

    public static void Invalidate() => s_Camera = null;

    private void Awake()
    {
        if (Instance == null) { Instance = this; DontDestroyOnLoad(gameObject); }
        else Destroy(gameObject);
    }

    private void Start() => StartCoroutine(PollUntilFound());

    private IEnumerator PollUntilFound()
    {
        while (s_Camera == null)
        {
   s_Camera = FindVRCamera();
            if (s_Camera != null)
            {
    Debug.Log($"[VRCameraProvider] Found: '{s_Camera.name}' tag='{s_Camera.tag}'");
  AssignToAllWorldSpaceCanvases(s_Camera);
      yield break;
          }
    yield return new WaitForSeconds(0.25f);
        }
    }

  private static Camera FindVRCamera()
    {
        Camera main = UnityEngine.Camera.main;
        if (main != null) return main;

        XROrigin origin = FindObjectOfType<XROrigin>();
        if (origin != null && origin.Camera != null) return origin.Camera;

        return FindObjectOfType<Camera>();
    }

 public static void AssignToAllWorldSpaceCanvases(Camera cam)
    {
   if (cam == null) return;
        foreach (Canvas c in FindObjectsOfType<Canvas>(true))
        {
            if (c.renderMode == RenderMode.WorldSpace && c.worldCamera == null)
         {
    c.worldCamera = cam;
     Debug.Log($"[VRCameraProvider] Canvas '{c.name}' worldCamera set to '{cam.name}'");
            }
        }
    }
}