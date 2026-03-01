using UnityEngine;
using UnityEngine.Events;

/// <summary>
/// Global VR game events broadcast across systems.
/// </summary>
public static class VREvents
{
    /// <summary>Fired once when the VR camera is found and assigned.</summary>
    public static UnityAction<Camera> OnVRCameraReady;

    /// <summary>Fired when the local XR player spawns.</summary>
    public static UnityAction OnPlayerSpawned;
}