using Unity.Netcode;
using UnityEngine;

public class BasicNetworkHUD : MonoBehaviour
{
    private void OnGUI()
    {
        if (NetworkManager.Singleton == null) return;
        
        GUILayout.BeginArea(new Rect(10, 10, 200, 300));
        
        // If not connected, show the buttons
        if (!NetworkManager.Singleton.IsClient && !NetworkManager.Singleton.IsServer)
        {
            if (GUILayout.Button("Start Host", GUILayout.Height(40))) 
                NetworkManager.Singleton.StartHost();
                
            if (GUILayout.Button("Start Client", GUILayout.Height(40))) 
                NetworkManager.Singleton.StartClient();
                
            if (GUILayout.Button("Start Server", GUILayout.Height(40))) 
                NetworkManager.Singleton.StartServer();
        }
        else
        {
            // If connected, show current status
            var mode = NetworkManager.Singleton.IsHost ? "Host" : NetworkManager.Singleton.IsServer ? "Server" : "Client";
            GUILayout.Label($"Mode: {mode}");
            
            if (GUILayout.Button("Disconnect", GUILayout.Height(40)))
            {
                NetworkManager.Singleton.Shutdown();
            }
        }
        
        GUILayout.EndArea();
    }
}
