using UnityEngine;
using Unity.Netcode;
using XRMultiplayer;

public class StartButtonUI : MonoBehaviour
{
    [SerializeField] private VRButtonJuice buttonJuice;
    [SerializeField] private string startText = "START GAME";
    [SerializeField] private string hostOnlyText = "HOST ONLY";

    private void Start()
    {
        if (buttonJuice == null) buttonJuice = GetComponent<VRButtonJuice>();
        UpdateStatus();
    }

    private void OnEnable()
    {
        if (NetworkManager.Singleton != null)
        {
            NetworkManager.Singleton.OnClientConnectedCallback += (id) => UpdateStatus();
            NetworkManager.Singleton.OnClientDisconnectCallback += (id) => UpdateStatus();
        }
    }

    private void UpdateStatus()
    {
        if (buttonJuice == null) return;

        bool isHost = NetworkManager.Singleton != null && NetworkManager.Singleton.IsServer;
        
        // Use the session manager if available as it's more accurate for VRMP
        var sessionMgr = XRINetworkGameManager.Instance.sessionManager;
        if (sessionMgr != null && sessionMgr.currentSession != null)
        {
            isHost = sessionMgr.currentSession.IsHost;
        }

        buttonJuice.SetText(isHost ? startText : hostOnlyText);
    }
}
