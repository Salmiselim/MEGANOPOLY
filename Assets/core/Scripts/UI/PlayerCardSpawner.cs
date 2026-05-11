using UnityEngine;

/// <summary>
/// Place this in the Lobby scene (e.g. on LobbyManager). On Awake it instantiates the
/// PlayerCardUI prefab if no instance exists yet, then forgets about it — the prefab's
/// own Awake handles DontDestroyOnLoad and singleton enforcement.
/// </summary>
public class PlayerCardSpawner : MonoBehaviour
{
    [Tooltip("Prefab containing the PlayerCardUI canvas (World Space, Root with content, etc.).")]
    public PlayerCardUI cardPrefab;

    private void Awake()
    {
        if (PlayerCardUI.Instance != null) return;

        if (cardPrefab == null)
        {
            Debug.LogError("[PlayerCardSpawner] cardPrefab is not assigned.");
            return;
        }

        Instantiate(cardPrefab);
    }
}
