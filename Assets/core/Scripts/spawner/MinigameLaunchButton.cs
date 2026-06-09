using Unity.Netcode;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

/// <summary>
/// Grabbable button that launches a minigame scene for EVERY player in the
/// current network session at once (networked, server-authoritative load).
///
/// HOW IT WORKS:
///   - Put this on a grabbable object (one with an XRGrabInteractable or any
///     XRBaseInteractable). When any player grabs it, RequestLaunch() runs.
///   - The load is done through NetworkManager.SceneManager.LoadScene, which
///     transitions ALL connected clients to the target scene together and keeps
///     them in the same NGO session. The target scene provides its OWN player
///     rig — we do NOT carry this scene's rig over.
///   - Only the server actually performs the load. A non-server grabber asks the
///     server to do it via an RPC, so any player can trigger it.
///
/// SETUP (see the step-by-step in chat):
///   1. Add this component to your grabbable button object.
///   2. Set "Scene To Load" to the exact scene name (must be in Build Profiles).
///   3. Make sure the object also has a NetworkObject (so the RPC works) OR rely
///      on the auto-found XR interactable + server check (NetworkObject is needed
///      only if non-host players must be able to trigger it — recommended).
/// </summary>
public class MinigameLaunchButton : NetworkBehaviour
{
    [Header("Target")]
    [Tooltip("Exact scene name to load for all players. Must be in Build Profiles.")]
    [SerializeField] private string sceneToLoad = "RPS_BAL";

    [Header("Options")]
    [Tooltip("If true, any player can trigger the launch. If false, only the host/server can.")]
    [SerializeField] private bool anyPlayerCanLaunch = true;

    [Tooltip("Ignore further grabs once a load has been requested (prevents double-loads).")]
    [SerializeField] private bool launchOnce = true;

    private bool _launchRequested;

    private void Awake()
    {
        // Auto-hook the grab/select event from whatever XR interactable is on this object.
        var interactable = GetComponent<XRBaseInteractable>();
        if (interactable != null)
        {
            interactable.selectEntered.AddListener(_ => RequestLaunch());
        }
        else
        {
            Debug.LogWarning($"[MinigameLaunchButton] No XRBaseInteractable on '{name}'. " +
                             "Add an XR Grab Interactable (or call RequestLaunch() from a UI Button).");
        }
    }

    /// <summary>
    /// Public entry point. Safe to also wire to a UI Button's OnClick or any
    /// other event. Routes to the server so the load is networked.
    /// </summary>
    public void RequestLaunch()
    {
        if (launchOnce && _launchRequested) return;

        if (NetworkManager.Singleton == null || !NetworkManager.Singleton.IsListening)
        {
            Debug.LogError("[MinigameLaunchButton] No active network session — cannot networked-load.");
            return;
        }

        if (IsServer)
        {
            DoServerLaunch();
        }
        else
        {
            if (!anyPlayerCanLaunch)
            {
                Debug.Log("[MinigameLaunchButton] Only the host can launch; ignoring client grab.");
                return;
            }
            RequestLaunchServerRpc();
        }
    }

    [ServerRpc(RequireOwnership = false)]
    private void RequestLaunchServerRpc() => DoServerLaunch();

    private void DoServerLaunch()
    {
        if (!IsServer) return;
        if (launchOnce && _launchRequested) return;
        _launchRequested = true;

        if (string.IsNullOrEmpty(sceneToLoad))
        {
            Debug.LogError("[MinigameLaunchButton] sceneToLoad is empty.");
            return;
        }

        Debug.Log($"[MinigameLaunchButton] Networked-loading '{sceneToLoad}' for all clients.");
        var status = NetworkManager.Singleton.SceneManager.LoadScene(sceneToLoad, LoadSceneMode.Single);
        Debug.Log($"[MinigameLaunchButton] LoadScene({sceneToLoad}) → {status}");
    }
}
