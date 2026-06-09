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
        // Once a real camera (an owned XR rig camera) exists, fully DISABLE the
        // fallback. Previously we left it enabled and relied on depth ordering
        // (-100 vs 0) to be drawn over. That breaks when the machine has more
        // than one XR Origin in the scene at once — e.g. the HOST holds both its
        // own rig AND the remote player's (stripped) rig. LateUpdate then snaps
        // the fallback to an arbitrary XROrigin (sometimes the dead remote one),
        // leaving the host stuck staring at a frozen fallback view with the
        // player-prefab placeholder Cube in frame. Disabling the fallback when a
        // real camera is present removes that whole failure mode.
        bool haveRealCamera = s_Camera != null && s_Camera.isActiveAndEnabled;
        if (_fallbackCamera != null) _fallbackCamera.enabled = !haveRealCamera;
        if (_fallbackListener != null)
            _fallbackListener.enabled = !haveRealCamera && !SceneHasOtherAudioListener();
    }

    private bool SceneHasOtherAudioListener()
    {
        foreach (var l in FindObjectsOfType<AudioListener>())
            if (l != _fallbackListener && l.isActiveAndEnabled) return true;
        return false;
    }

    private IEnumerator PollUntilFound()
    {
        // Keep polling until we have a REAL, currently-enabled camera. We don't
        // yield out the instant s_Camera is non-null, because on the host the
        // first camera found can be the remote player's rig camera that the
        // ownership guard disables a frame later. If that happens the cached
        // camera goes inactive and we must look again — otherwise the host is
        // left with a dead camera reference and a black/frozen view.
        while (true)
        {
            if (s_Camera == null || !s_Camera.isActiveAndEnabled)
                s_Camera = FindRealCamera(excluding: _fallbackCamera);

            UpdateFallbackState();

            if (s_Camera != null && s_Camera.isActiveAndEnabled)
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
        // Only ever return an ENABLED camera. On the host there can be a second,
        // DISABLED rig camera (the remote player's, silenced by XROwnershipGuard).
        // Returning that would leave us rendering nothing.
        Camera main = UnityEngine.Camera.main; // Camera.main already ignores disabled cameras
        if (main != null && main != excluding && main.isActiveAndEnabled) return main;

        XROrigin origin = FindObjectOfType<XROrigin>();
        if (origin != null && origin.Camera != null && origin.Camera != excluding
            && origin.Camera.isActiveAndEnabled)
            return origin.Camera;

        foreach (Camera c in FindObjectsOfType<Camera>())
            if (c != excluding && c.isActiveAndEnabled)
                return c;

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
