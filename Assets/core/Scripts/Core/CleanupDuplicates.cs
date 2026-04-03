using UnityEngine;
using UnityEngine.EventSystems;

public class CleanupDuplicates : MonoBehaviour
{
    private void Start()
    {
        // Destroy duplicate EventSystem from minigame scene
        EventSystem[] eventSystems = FindObjectsOfType<EventSystem>();
        if (eventSystems.Length > 1)
        {
            for (int i = 1; i < eventSystems.Length; i++)
            {
                Debug.Log("[Cleanup] Destroying duplicate EventSystem from: " + eventSystems[i].gameObject.scene.name);
                Destroy(eventSystems[i].gameObject);
            }
        }

        // Destroy duplicate AudioListener
        AudioListener[] listeners = FindObjectsOfType<AudioListener>();
        if (listeners.Length > 1)
        {
            for (int i = 1; i < listeners.Length; i++)
            {
                Debug.Log("[Cleanup] Destroying duplicate AudioListener from: " + listeners[i].gameObject.scene.name);
                Destroy(listeners[i].gameObject);
            }
        }
    }
}
