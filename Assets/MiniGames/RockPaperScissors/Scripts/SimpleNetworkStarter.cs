using Unity.Netcode;
using UnityEngine;

namespace RockPaperScissors
{
    /// <summary>
    /// Super simple network starter - attach directly to buttons
    /// </summary>
    public class SimpleNetworkStarter : MonoBehaviour
    {
        public void StartHost()
        {
            Debug.Log("=== START HOST BUTTON CLICKED ===");
            
            if (NetworkManager.Singleton == null)
            {
                Debug.LogError("NetworkManager.Singleton is NULL!");
                return;
            }
            
            Debug.Log("Starting Host...");
            NetworkManager.Singleton.StartHost();
            Debug.Log($"Host started! IsHost: {NetworkManager.Singleton.IsHost}");
        }
        
        public void StartClient()
        {
            Debug.Log("=== START CLIENT BUTTON CLICKED ===");
            
            if (NetworkManager.Singleton == null)
            {
                Debug.LogError("NetworkManager.Singleton is NULL!");
                return;
            }
            
            Debug.Log("Starting Client...");
            NetworkManager.Singleton.StartClient();
            Debug.Log($"Client started! IsClient: {NetworkManager.Singleton.IsClient}");
        }
    }
}
