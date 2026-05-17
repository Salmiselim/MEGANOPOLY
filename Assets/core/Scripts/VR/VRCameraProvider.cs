using System.Collections;
using UnityEngine;
using Unity.XR.CoreUtils;

public class VRCameraProvider : MonoBehaviour
{
    public static VRCameraProvider Instance { get; private set; }
    private static Camera s_Camera;

    // Fallback camera kept on this DontDestroyOnLoad object so the screen is
    // never blank during scene transitions (e.g. Auth → Lobby). It steps aside
    // automatically once a real MainCamera/XR camera becomes available.
    private Camera _fallbackCamera;
    private AudioListener _fallbackListener;

    public static Camera Camera
    {
        get
        {
            if (s_Camera != null) return s_Camera;
            s_Camera = FindRealCamera();
            return s_Camera;
        }
    }

    public static void Invalidate() => s_Camera = null;

    private void Awake()
    {
        if (Instance == null) { Instance = this; DontDestroyOnLoad(gameObject); }
        else { Destroy(this); return; } // destroy duplicate component only — other components on this GO (e.g. CompleteGameManager) must keep living

        EnsureFallbackCamera();
    }

    private void Start() => StartCoroutine(PollUntilFound());

    private void OnEnable()
    {
        UnityEngine.SceneManagement.SceneManager.sceneLoaded += OnSceneLoaded;
    }

    private void OnDisable()
    {
        UnityEngine.SceneManagement.SceneManager.sceneLoaded -= OnSceneLoaded;
    }

    private void OnSceneLoaded(UnityEngine.SceneManagement.Scene scene, UnityEngine.SceneManagement.LoadSceneMode mode)
    {
        // After every scene load, re-evaluate. If the new scene has no real
        // camera yet, our fallback keeps rendering. If it does, we step aside.
        Invalidate();
        UpdateFallbackState();
        StopAllCoroutines();
        StartCoroutine(PollUntilFound());
    }

    private void EnsureFallbackCamera()
    {
        if (_fallbackCamera != null) return;

        _fallbackCamera = gameObject.AddComponent<Camera>();
        _fallbackCamera.clearFlags  = CameraClearFlags.Skybox;
        _fallbackCamera.depth = -100; // any real camera with default depth (0) renders on top
        _fallbackCamera.cullingMask = ~0;
        _fallbackCamera.nearClipPlane = 0.05f;
        _fallbackCamera.farClipPlane  = 1000f;

        _fallbackListener = gameObject.AddComponent<AudioListener>();
    }

    private void UpdateFallbackState()
    {
        // Keep the fallback camera always rendering at low depth — real cameras
        // with higher depth automatically render over it when they produce frames.
        // We only disable the AudioListener if the scene already has another one,
        // because Unity warns about multiple active listeners.
        if (_fallbackCamera != null) _fallbackCamera.enabled = true;
        if (_fallbackListener != null)
            _fallbackListener.enabled = !SceneHasOtherAudioListener();
    }

    private bool SceneHasOtherAudioListener()
    {
        foreach (var l in FindObjectsOfType<AudioListener>())
            if (l != _fallbackListener && l.isActiveAndEnabled) return true;
        return false;
    }

    private IEnumerator PollUntilFound()
    {
        while (s_Camera == null)
        {
            s_Camera = FindRealCamera(excluding: _fallbackCamera);
            UpdateFallbackState();

            if (s_Camera != null)
            {
                Debug.Log($"[VRCameraProvider] Found: '{s_Camera.name}' tag='{s_Camera.tag}'");
                AssignToAllWorldSpaceCanvases(s_Camera);
                yield break;
            }
            yield return new WaitForSeconds(0.25f);
        }
    }

    private void LateUpdate()
    {
        // Snap the fallback camera to wherever the XR Origin's eye is, so the
        // user sees the new scene from a sensible viewpoint instead of from
        // wherever this DontDestroyOnLoad GameObject originally sat.
        if (_fallbackCamera == null || !_fallbackCamera.enabled) return;

        XROrigin origin = FindObjectOfType<XROrigin>();
        Transform eye = origin != null && origin.Camera != null ? origin.Camera.transform : null;
        if (eye != null)
        {
            transform.SetPositionAndRotation(eye.position, eye.rotation);
        }
    }

    private static Camera FindRealCamera(Camera excluding = null)
    {
        Camera main = UnityEngine.Camera.main;
        if (main != null && main != excluding) return main;

        XROrigin origin = FindObjectOfType<XROrigin>();
        if (origin != null && origin.Camera != null && origin.Camera != excluding)
            return origin.Camera;

        foreach (Camera c in FindObjectsOfType<Camera>())
            if (c != excluding) return c;

        return null;
    }

    // Backwards-compat: existing call sites use this name.
    private static Camera FindVRCamera() => FindRealCamera();

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
