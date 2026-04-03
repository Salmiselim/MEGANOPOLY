using UnityEngine;
using UnityEngine.Events;
using UnityEngine.SceneManagement;

[System.Serializable]
public class MinigameEndedEvent : UnityEvent<int, int>
{
}

public class MinigameOrchestrator : MonoBehaviour
{
    public static MinigameOrchestrator Instance { get; private set; }

    [Header("Events")]
    public MinigameEndedEvent OnMinigameEnded = new MinigameEndedEvent();

    [Header("Settings")]
    [SerializeField] private bool hideMainUIWhileMinigame = true;
    [SerializeField] private bool debugMode = true;

    private int currentMinigameType = -1;
    private bool minigameRunning = false;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    /// <summary>
    /// Start a minigame: load scene, pause game, hide UI
    /// </summary>
    public void StartMinigame(int minigameType, string propertyName, PlayerData challenger, int prizeAmount)
    {
        if (minigameRunning)
        {
            Debug.LogWarning("[MinigameOrchestrator] Minigame already running!");
            return;
        }

        minigameRunning = true;
        currentMinigameType = minigameType;

        if (debugMode)
        {
            Debug.Log($"[MinigameOrchestrator] START minigame type={minigameType}, property={propertyName}, " +
                      $"challenger={challenger?.playerName ?? "Unknown"}, prize={prizeAmount}");
        }

        // Pause main game
        if (CompleteGameManager.Instance != null)
            CompleteGameManager.Instance.PauseGame();

        // Hide main UI
        if (hideMainUIWhileMinigame)
            HideMainUI(true);

        // Load minigame scene additively
        string sceneName = GetMinigameSceneName(minigameType);
        if (!string.IsNullOrEmpty(sceneName))
        {
            SceneManager.LoadSceneAsync(sceneName, LoadSceneMode.Additive);
        }
        else
        {
            Debug.LogWarning($"[MinigameOrchestrator] No scene mapped for minigameType={minigameType}");
        }
    }

    /// <summary>
    /// Finish minigame: unload scene, resume game, show UI
    /// </summary>
    public static void FinishMinigame(int winnerId, int prizeAmount)
    {
        if (Instance == null)
        {
            Debug.LogWarning("[MinigameOrchestrator] FinishMinigame called but no instance!");
            return;
        }

        Instance.HandleMinigameFinished(winnerId, prizeAmount);
    }

    private void HandleMinigameFinished(int winnerId, int prizeAmount)
    {
        if (!minigameRunning)
        {
            Debug.LogWarning("[MinigameOrchestrator] No minigame was running!");
            return;
        }

        minigameRunning = false;

        if (debugMode)
        {
            Debug.Log($"[MinigameOrchestrator] FINISH winner={winnerId}, prize={prizeAmount}");
        }

        // Unload minigame scene
        string sceneName = GetMinigameSceneName(currentMinigameType);
        if (!string.IsNullOrEmpty(sceneName))
        {
            SceneManager.UnloadSceneAsync(sceneName);
        }

        // Resume game
        if (CompleteGameManager.Instance != null)
            CompleteGameManager.Instance.ResumeGame();

        // Show UI again
        if (hideMainUIWhileMinigame)
            HideMainUI(false);

        // Notify game manager of result
        OnMinigameEnded.Invoke(winnerId, prizeAmount);
    }

    private void HideMainUI(bool hide)
    {
        // NOTE: change "SampleScene" to your Monopoly board scene name if needed
        Canvas[] canvases = FindObjectsOfType<Canvas>();
        foreach (Canvas canvas in canvases)
        {
            if (canvas.gameObject.scene.name == "SampleScene")
            {
                canvas.gameObject.SetActive(!hide);
                if (debugMode)
                    Debug.Log($"[MinigameOrchestrator] {(hide ? "Hiding" : "Showing")} canvas: {canvas.gameObject.name}");
            }
        }
    }

    /// <summary>
    /// Map minigameType to actual scene names in Build Settings.
    /// </summary>
    private string GetMinigameSceneName(int minigameType)
    {
        // TODO: adjust these cases to match your real scene names
        switch (minigameType)
        {
            case 0: return "Khobz";
            case 1: return "3allouch";
            case 2: return "BentWaladScene";
            case 3: return "HandTracking_PlayerVSComputer";
            // add more as needed**
            default: return null;
        }
    }
}