using Unity.Netcode;
using UnityEngine;
using UnityEngine.UI;

namespace RockPaperScissors
{
    public class NetworkUITest : MonoBehaviour
    {
        [SerializeField] private Button startHostButton;
        [SerializeField] private Button startClientButton;

        void Start()
        {
            // Option 1: Link via Code (Easier)
            if (startHostButton != null)
            {
                startHostButton.onClick.AddListener(() => {
                    NetworkManager.Singleton.StartHost();
                });
            }

            if (startClientButton != null)
            {
                startClientButton.onClick.AddListener(() => {
                    NetworkManager.Singleton.StartClient();
                });
            }
        }

        // Option 2: Public methods for Inspector
        public void StartHost()
        {
            NetworkManager.Singleton.StartHost();
        }

        public void StartClient()
        {
            NetworkManager.Singleton.StartClient();
        }
    }
}
