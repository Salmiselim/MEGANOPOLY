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
            // 1. Cleanly disable the old offline XROrigin / Camera instead of destroying it
            Camera[] allCams = FindObjectsOfType<Camera>();
            foreach (Camera c in allCams)
            {
                if (c.transform.root != this.transform.root && c.gameObject.scene.name != "DontDestroyOnLoad")
                {
                    // Disable the old camera and its root object cleanly
                    c.enabled = false;
                    
                    var oldOrigin = c.transform.root.GetComponentInChildren<XROrigin>(true);
                    if (oldOrigin != null)
                    {
                        oldOrigin.gameObject.SetActive(false);
                    }
                    else
                    {
                        c.gameObject.SetActive(false);
                    }
                }
            }

            // 2. Ensure our camera is tagged correctly
            Camera myCam = cameraOffsetRoot.GetComponentInChildren<Camera>(true);
            if (myCam != null)
            {
                myCam.tag = "MainCamera";
            }

            Debug.Log($"[XROwnershipGuard] Local Player spawned. Keeping Camera Rig.");
        }
        else
        {
            // 3. We DO NOT own this player. Destroy their camera rig physically 
            // so it cannot act like a camera on our screen.
            Destroy(cameraOffsetRoot);

            Debug.Log($"[XROwnershipGuard] Remote Player spawned. Destroyed their Camera Rig.");
        }
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