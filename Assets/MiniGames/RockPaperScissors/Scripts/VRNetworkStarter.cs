using Unity.Netcode;
using UnityEngine;
using UnityEngine.XR;
using TMPro;

namespace RockPaperScissors
{
    /// <summary>
    /// VR-friendly network starter using controller buttons
    /// Left Trigger = Start Host
    /// Right Trigger = Start Client
    /// OR auto-start as Client on Quest
    /// </summary>
    public class VRNetworkStarter : MonoBehaviour
    {
        [Header("Settings")]
        [SerializeField] private bool autoStartAsClient = false;
        [SerializeField] private TextMeshProUGUI statusText;
        
        private bool hasStarted = false;
        private InputDevice leftController;
        private InputDevice rightController;
        
        void Start()
        {
            // Get controllers
            leftController = InputDevices.GetDeviceAtXRNode(XRNode.LeftHand);
            rightController = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
            
            // Auto-start on Quest/Android
            #if UNITY_ANDROID
            if (autoStartAsClient)
            {
                Debug.Log("[VR Network] Auto-starting as Client (Quest)...");
                Invoke(nameof(StartAsClient), 1f);
            }
            #endif
            
            UpdateStatusText("Press LEFT TRIGGER for Host\nPress RIGHT TRIGGER for Client");
        }
        
        void Update()
        {
            if (hasStarted) return;
            
            // Check left trigger (Host)
            if (leftController.TryGetFeatureValue(CommonUsages.triggerButton, out bool leftTrigger) && leftTrigger)
            {
                StartAsHost();
            }
            
            // Check right trigger (Client)
            if (rightController.TryGetFeatureValue(CommonUsages.triggerButton, out bool rightTrigger) && rightTrigger)
            {
                StartAsClient();
            }
            
            // Fallback: Check primary buttons (A/X)
            if (rightController.TryGetFeatureValue(CommonUsages.primaryButton, out bool aButton) && aButton)
            {
                StartAsHost();
            }
            
            if (rightController.TryGetFeatureValue(CommonUsages.secondaryButton, out bool bButton) && bButton)
            {
                StartAsClient();
            }
        }
        
        void StartAsHost()
        {
            if (hasStarted) return;
            hasStarted = true;
            
            Debug.Log("[VR Network] Starting as HOST...");
            UpdateStatusText("Starting as HOST...");
            
            if (NetworkManager.Singleton != null)
            {
                NetworkManager.Singleton.StartHost();
                Debug.Log($"[VR Network] Host started! IsHost: {NetworkManager.Singleton.IsHost}");
                UpdateStatusText($"HOST ACTIVE\nPlayers: {NetworkManager.Singleton.ConnectedClients.Count}");
            }
            else
            {
                Debug.LogError("[VR Network] NetworkManager.Singleton is NULL!");
                UpdateStatusText("ERROR: No NetworkManager!");
            }
        }
        
        void StartAsClient()
        {
            if (hasStarted) return;
            hasStarted = true;
            
            Debug.Log("[VR Network] Starting as CLIENT...");
            UpdateStatusText("Connecting to host...");
            
            if (NetworkManager.Singleton != null)
            {
                NetworkManager.Singleton.StartClient();
                Debug.Log($"[VR Network] Client started! IsClient: {NetworkManager.Singleton.IsClient}");
                UpdateStatusText("CLIENT CONNECTED!");
            }
            else
            {
                Debug.LogError("[VR Network] NetworkManager.Singleton is NULL!");
                UpdateStatusText("ERROR: No NetworkManager!");
            }
        }
        
        void UpdateStatusText(string message)
        {
            if (statusText != null)
            {
                statusText.text = message;
            }
        }
    }
}
