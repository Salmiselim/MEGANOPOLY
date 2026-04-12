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

    // ── Awake: disable BEFORE Input System touches anything ──────────────────

    private void Awake()
    {
        // Find Camera Offset if not assigned
        if (cameraOffsetRoot == null)
            cameraOffsetRoot = FindCameraOffset();

        if (cameraOffsetRoot != null)
        {
            cameraOffsetRoot.SetActive(false);
            Debug.Log($"[XROwnershipGuard] Camera Offset disabled on {gameObject.name} (pre-network).");
        }
        else
        {
            Debug.LogWarning($"[XROwnershipGuard] Could not find Camera Offset on {gameObject.name}. " +
                             "XR Input may register on non-owner clients.");
        }
    }

    // ── OnNetworkSpawn: runs after NGO sets IsOwner ───────────────────────────

    public override void OnNetworkSpawn()
    {
        if (cameraOffsetRoot == null)
            cameraOffsetRoot = FindCameraOffset();

        if (cameraOffsetRoot == null)
        {
            Debug.LogError($"[XROwnershipGuard] OnNetworkSpawn: still no Camera Offset on {gameObject.name}!");
            return;
        }

        bool enable = IsOwner;
        cameraOffsetRoot.SetActive(enable);

        Debug.Log($"[XROwnershipGuard] {gameObject.name} — IsOwner={enable} → Camera Offset {(enable ? "ENABLED" : "DISABLED")}");

        // Also enable/disable the AudioListener so only owner's is active
        AudioListener al = cameraOffsetRoot.GetComponentInChildren<AudioListener>(true);
        if (al != null) al.enabled = enable;

        // Tag the owner's camera as MainCamera so Camera.main works
        if (enable)
        {
            Camera cam = cameraOffsetRoot.GetComponentInChildren<Camera>(true);
            if (cam != null)
            {
                cam.tag = "MainCamera";
                Debug.Log($"[XROwnershipGuard] Tagged {cam.name} as MainCamera.");
            }
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