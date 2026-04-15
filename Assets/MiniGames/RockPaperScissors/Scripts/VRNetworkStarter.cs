using Unity.Netcode;
using Unity.Netcode.Transports.UTP;
using UnityEngine;
using UnityEngine.XR;
using TMPro;

namespace RockPaperScissors
{
    /// <summary>
    /// VR-friendly network starter.
    /// PC (Editor)  → Left Trigger  = Start Host
    /// Quest        → Right Trigger = Start Client  (connects to HostIP)
    ///
    /// Before building the APK, set HostIP in the Inspector to your PC's
    /// local IP address (run "ipconfig" on the PC to find it, e.g. 192.168.1.45).
    /// </summary>
    public class VRNetworkStarter : MonoBehaviour
    {
        [Header("Connection")]
        [Tooltip("PC's local IP address. Set this before building the Quest APK.\n" +
                 "Find it by running 'ipconfig' in Command Prompt on the PC.")]
        [SerializeField] private string hostIP = "10.180.137.88";

        [Tooltip("Port must match the UnityTransport component on the NetworkManager (default 7777).")]
        [SerializeField] private ushort port = 7777;

        [Header("Auto-start")]
        [Tooltip("When ON the Quest will automatically start as Client after 1 second. " +
                 "Useful so you don't have to press a controller button.")]
        [SerializeField] private bool autoStartAsClientOnQuest = true;

        [Header("UI")]
        [SerializeField] private TextMeshProUGUI statusText;

        private bool _hasStarted = false;
        private InputDevice _leftController;
        private InputDevice _rightController;

        void Start()
        {
            _leftController  = InputDevices.GetDeviceAtXRNode(XRNode.LeftHand);
            _rightController = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);

#if UNITY_ANDROID
            if (autoStartAsClientOnQuest)
            {
                UpdateStatusText($"Connecting to\n{hostIP}:{port}...");
                Invoke(nameof(StartAsClient), 1.5f);
            }
            else
            {
                UpdateStatusText($"Pull RIGHT TRIGGER to connect\nto {hostIP}");
            }
#else
            UpdateStatusText("LEFT TRIGGER  = Host\nRIGHT TRIGGER = Client");
#endif
        }

        void Update()
        {
            if (_hasStarted) return;

            // Re-cache controllers if they weren't ready at Start()
            if (!_leftController.isValid)
                _leftController  = InputDevices.GetDeviceAtXRNode(XRNode.LeftHand);
            if (!_rightController.isValid)
                _rightController = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);

            // Left trigger → Host
            if (_leftController.TryGetFeatureValue(CommonUsages.triggerButton, out bool leftTrigger) && leftTrigger)
                StartAsHost();

            // Right trigger → Client
            if (_rightController.TryGetFeatureValue(CommonUsages.triggerButton, out bool rightTrigger) && rightTrigger)
                StartAsClient();
        }

        public void StartAsHost()
        {
            if (_hasStarted) return;
            _hasStarted = true;

            // Host listens on all interfaces — no IP needed
            SetTransportAddress("0.0.0.0", port);

            UpdateStatusText("Starting HOST...");
            if (NetworkManager.Singleton != null)
            {
                NetworkManager.Singleton.StartHost();
                UpdateStatusText($"HOST ACTIVE\nWaiting for players...");
                Debug.Log("[VR Network] Host started.");
            }
            else
            {
                Debug.LogError("[VR Network] NetworkManager.Singleton is NULL!");
                UpdateStatusText("ERROR: No NetworkManager found!");
            }
        }

        public void StartAsClient()
        {
            if (_hasStarted) return;
            _hasStarted = true;

            // Point the transport at the PC's IP before connecting
            SetTransportAddress(hostIP, port);

            UpdateStatusText($"Connecting to\n{hostIP}:{port}...");
            if (NetworkManager.Singleton != null)
            {
                NetworkManager.Singleton.StartClient();
                Debug.Log($"[VR Network] Client connecting to {hostIP}:{port}");
            }
            else
            {
                Debug.LogError("[VR Network] NetworkManager.Singleton is NULL!");
                UpdateStatusText("ERROR: No NetworkManager found!");
            }
        }

        /// <summary>Sets the UnityTransport connection address at runtime before Start/Client is called.</summary>
        private void SetTransportAddress(string ip, ushort p)
        {
            var transport = NetworkManager.Singleton.GetComponent<UnityTransport>();
            if (transport != null)
                transport.SetConnectionData(ip, p);
            else
                Debug.LogWarning("[VR Network] UnityTransport component not found on NetworkManager!");
        }

        void UpdateStatusText(string message)
        {
            if (statusText != null)
                statusText.text = message;
        }
    }
}

