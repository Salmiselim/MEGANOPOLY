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

        // Automatically hook up the click event for XR interactables
        var interactable = GetComponent<UnityEngine.XR.Interaction.Toolkit.Interactables.XRBaseInteractable>();
        if (interactable != null)
        {
            interactable.selectEntered.AddListener((args) => OnStartClicked());
        }

        // Also hook up standard UI Buttons
        var uiButton = GetComponent<UnityEngine.UI.Button>();
        if (uiButton != null)
        {
            uiButton.onClick.AddListener(OnStartClicked);
        }
    }

    public void OnStartClicked()
    {
        Debug.Log("[StartButtonUI] Start game clicked.");
        if (LobbyRelayManager.Instance != null)
        {
            LobbyRelayManager.Instance.TryStartGame();
        }
        else
        {
            // Fallback if LobbyRelayManager is not in the scene
            if (NetworkManager.Singleton != null && NetworkManager.Singleton.IsServer)
            {
                NetworkManager.Singleton.SceneManager.LoadScene("SampleScene", UnityEngine.SceneManagement.LoadSceneMode.Single);
            }
        }
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
