using UnityEngine;
using Unity.Netcode;
using Unity.XR.CoreUtils;

/// <summary>
/// Attach to the ROOT of your player prefab (same GameObject as NetworkObject).
/// 
/// WHAT IT DOES:
///   - Disables Camera Offset immediately in Awake so XR Input System
///     doesn't register pointer indices before we know who owns this object.
///   - In OnNetworkSpawn, re-enables Camera Offset ONLY for the owner.
///
/// SETUP:
///   1. Add this script to the player prefab root.
///   2. Assign the "Camera Offset" child to the cameraOffsetRoot field
///      (or leave blank — it auto-finds via XROrigin or by name).
///   3. In the prefab asset, Camera Offset should start INACTIVE
///      (this script also handles it, but the prefab default is the safety net).
/// </summary>
public class XROwnershipGuard : NetworkBehaviour
{
    [Header("References")]
    [Tooltip("Drag in the 'Camera Offset' child GameObject. Auto-found if left blank.")]
    [SerializeField] private GameObject cameraOffsetRoot;

    // ── OnNetworkSpawn: runs after NGO sets IsOwner ───────────────────────────

    public override void OnNetworkSpawn()
    {
        if (cameraOffsetRoot == null)
            cameraOffsetRoot = FindCameraOffset();

        if (cameraOffsetRoot == null)
        {
            Debug.LogError($"[XROwnershipGuard] OnNetworkSpawn: no Camera Offset found on {gameObject.name}!");
            return;
        }

        if (IsOwner)
        {
            // Local player. Make our camera the rendering main camera AND
            // silence every other Camera/AudioListener in active scenes so
            // they don't outrank ours. We deliberately ONLY disable the
            // Camera/AudioListener components — not the GameObjects — so the
            // XR Device Simulator (in editor) keeps producing head/hand
            // input via its TrackedPoseDriver/InputActions; only its visual
            // camera goes silent. Cameras in DontDestroyOnLoad (e.g. the
            // VRCameraProvider fallback) are left alone — that script
            // already steps aside when a real XR camera shows up.
            Camera myCam = cameraOffsetRoot.GetComponentInChildren<Camera>(true);
            if (myCam != null) myCam.tag = "MainCamera";

            int silenced = 0;
            foreach (var cam in FindObjectsByType<Camera>(FindObjectsInactive.Exclude, FindObjectsSortMode.None))
            {
                if (cam == null || cam == myCam) continue;
                if (cam.transform.root == this.transform.root) continue; // skip our own rig
                if (cam.gameObject.scene.name == "DontDestroyOnLoad") continue; // skip fallback / DDOL cams
                cam.enabled = false;
                var listener = cam.GetComponent<AudioListener>();
                if (listener != null) listener.enabled = false;
                silenced++;
            }

            Debug.Log($"[XROwnershipGuard] Local Player spawned. Kept rig, silenced {silenced} other camera(s).");
        }
        else
        {
            // Remote player. Their VISUAL mesh (hand models, body) must stay
            // visible so other players actually see the avatar, but anything
            // that would render to *our* screen or consume *our* XR input has
            // to go. So: keep the cameraOffsetRoot GameObject (which holds
            // the hand meshes), but disable just the Camera + AudioListener
            // and strip XR input/locomotion components.
            StripRemoteAvatarCamera();
            DisableXrSystemsOnRemoteAvatar();

            Debug.Log($"[XROwnershipGuard] Remote Player spawned. Disabled their Camera + XR systems; visuals kept.");
        }
    }

    /// <summary>
    /// On a remote avatar, disable just the Camera + AudioListener under the
    /// rig so the remote rig stops trying to render to or pull audio through
    /// the local screen — but leave the GameObject tree intact so the
    /// network-synced hand/body meshes still render for us.
    /// </summary>
    private void StripRemoteAvatarCamera()
    {
        foreach (var cam in cameraOffsetRoot.GetComponentsInChildren<Camera>(true))
            cam.enabled = false;
        foreach (var listener in cameraOffsetRoot.GetComponentsInChildren<AudioListener>(true))
            listener.enabled = false;
    }

    /// <summary>
    /// Disables every MonoBehaviour on the rig whose namespace begins with
    /// "UnityEngine.XR" or "Unity.XR" — locomotion providers, controllers,
    /// gravity, hand subsystems, etc. We do this on remote avatars so they
    /// stop reading the destroyed Camera every frame. Renderers / animators
    /// are left alone, so the avatar still shows up.
    /// </summary>
    private void DisableXrSystemsOnRemoteAvatar()
    {
        var behaviours = GetComponentsInChildren<MonoBehaviour>(true);
        int disabled = 0;
        foreach (var b in behaviours)
        {
            if (b == null || b == this) continue;
            // Keep NGO scripts so movement / ownership replication still works.
            if (b is NetworkBehaviour) continue;
            string ns = b.GetType().Namespace;
            if (string.IsNullOrEmpty(ns)) continue;
            // All XR/input-driven namespaces we want silenced on a remote
            // avatar. Critically this includes UnityEngine.InputSystem.XR —
            // that's where TrackedPoseDriver lives, and if it stays enabled
            // the remote avatar reads YOUR local controller poses and
            // duplicates your hand movement on the other player's body.
            if (ns.StartsWith("UnityEngine.XR")
             || ns.StartsWith("Unity.XR")
             || ns.StartsWith("UnityEngine.InputSystem.XR")
             || ns.StartsWith("UnityEngine.SpatialTracking"))
            {
                b.enabled = false;
                disabled++;
            }
        }
        if (disabled > 0)
            Debug.Log($"[XROwnershipGuard] Disabled {disabled} XR component(s) on remote avatar.");
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private GameObject FindCameraOffset()
    {
        // 1. Via XROrigin.CameraFloorOffsetObject
        XROrigin xrOrigin = GetComponentInChildren<XROrigin>(true);
        if (xrOrigin != null && xrOrigin.CameraFloorOffsetObject != null)
            return xrOrigin.CameraFloorOffsetObject;

        // 2. By name anywhere in the hierarchy
        Transform found = FindDeep(transform, "Camera Offset");
        if (found != null) return found.gameObject;

        // 3. By name variant
        found = FindDeep(transform, "CameraOffset");
        if (found != null) return found.gameObject;

        return null;
    }

    private static Transform FindDeep(Transform parent, string name)
    {
        foreach (Transform child in parent)
        {
            if (child.name == name) return child;
            Transform result = FindDeep(child, name);
            if (result != null) return result;
        }
        return null;
    }
}