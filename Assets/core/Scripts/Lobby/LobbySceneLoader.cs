using Unity.Netcode;
using UnityEngine;
using UnityEngine.SceneManagement;

public class LobbySceneLoader : NetworkBehaviour
{
    [Tooltip("If true, only the host can trigger the scene load. If false, any player can trigger it.")]
    public bool onlyHostCanStart = true;

    /// <summary>
    /// Call this from a UI Button or XRI Interactable UnityEvent.
    /// Passes the exact name of the scene to load (e.g. "Khobz").
    /// </summary>
    public void RequestLoadScene(string sceneName)
    {
        if (NetworkManager.Singleton == null)
        {
            Debug.LogError("[LobbySceneLoader] NetworkManager instance is missing.");
            return;
        }

        bool isHost = NetworkManager.Singleton.IsServer;
        var sessionMgr = XRMultiplayer.XRINetworkGameManager.Instance.sessionManager;
        if (sessionMgr != null && sessionMgr.currentSession != null)
        {
            isHost = sessionMgr.currentSession.IsHost;
        }

        if (onlyHostCanStart && !isHost)
        {
            Debug.LogWarning("[LobbySceneLoader] Only the host can start the game.");
            return;
        }

        // Check Minimum Participants
        if (NetworkManager.Singleton.ConnectedClients.Count <= 1)
        {
            Debug.LogWarning("[LobbySceneLoader] Cannot start: At least 2 players are required to start a Minigame.");
            return;
        }

        // Check All Players Ready
        foreach (var client in NetworkManager.Singleton.ConnectedClientsList)
        {
            var playerObj = client.PlayerObject;
            if (playerObj != null && playerObj.TryGetComponent<XRMultiplayer.XRINetworkPlayer>(out var networkPlayer))
            {
                if (!networkPlayer.isReady.Value)
                {
                    Debug.LogWarning($"[LobbySceneLoader] Cannot start: Player {networkPlayer.playerName} is not ready.");
                    return;
                }
            }
        }

        if (isHost)
        {
            LoadSceneRpc(sceneName);
        }
    }

    [Rpc(SendTo.Everyone)]
    private void LoadSceneRpc(string sceneName)
    {
        Debug.Log($"[LobbySceneLoader] LoadSceneRpc triggered for {sceneName}. Loading locally.");
        SceneManager.LoadScene(sceneName, LoadSceneMode.Single);
    }
}
