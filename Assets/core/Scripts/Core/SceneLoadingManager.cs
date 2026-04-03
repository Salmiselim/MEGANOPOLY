using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneLoadingManager : MonoBehaviour
{
    public static SceneLoadingManager Instance { get; private set; }

    [SerializeField] private bool debugMode = true;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
    }

    /// <summary>
    /// Load a minigame scene additively (don't unload main board)
    /// minigameType: 0=Khobz, 1=3allouch, 2=BentWalad
    /// </summary>
    public void LoadMinigameScene(int minigameType)
    {
        string sceneName = GetMinigameSceneName(minigameType);
        if (string.IsNullOrEmpty(sceneName))
        {
            Debug.LogError($"[SceneManager] Unknown minigame type: {minigameType}");
            return;
        }

        if (debugMode)
            Debug.Log($"[SceneManager] Loading minigame scene: {sceneName}");

        // Load additively so main board stays active
        SceneManager.LoadScene(sceneName, LoadSceneMode.Additive);
    }

    /// <summary>
    /// Unload a minigame scene and return to board
    /// </summary>
    public void UnloadMinigameScene(int minigameType)
    {
        string sceneName = GetMinigameSceneName(minigameType);
        if (string.IsNullOrEmpty(sceneName))
        {
            Debug.LogError($"[SceneManager] Unknown minigame type: {minigameType}");
            return;
        }

        if (debugMode)
            Debug.Log($"[SceneManager] Unloading minigame scene: {sceneName}");

        // Make sure main board is active again
        SceneManager.SetActiveScene(SceneManager.GetSceneByName("SampleScene"));
        SceneManager.UnloadSceneAsync(sceneName);
    }

    private string GetMinigameSceneName(int minigameType)
    {
        return minigameType switch
        {
            0 => "Khobz",
            1 => "3allouch",
            2 => "BentWaladScene",
            _ => null
        };
    }
}
