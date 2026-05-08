using System.Collections.Generic;
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
    private int challengerPlayerIndex = -1;

    private readonly List<Camera> savedBoardCameras = new List<Camera>();
    private readonly List<GameObject> savedPlayerAvatars = new List<GameObject>();

    /// <summary>The playerId of the player who triggered the current/last mini-game.</summary>
    public int LastChallengerId => challengerPlayerIndex;

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
    /// Transition all players to the mini-game scene:
    /// disables board cameras + avatars, loads the scene additively.
    /// </summary>
    public void StartMinigame(int minigameType, string propertyName,
        PlayerData challenger, int prizeAmount, int challengerIndex = -1)
    {
        if (minigameRunning)
        {
            Debug.LogWarning("[MinigameOrchestrator] Minigame already running!");
            return;
        }

        minigameRunning = true;
        currentMinigameType = minigameType;
        challengerPlayerIndex = challengerIndex;

        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] START type={minigameType} property={propertyName} " +
                      $"challenger={challenger?.playerName ?? "Unknown"} prize={prizeAmount}");

        if (CompleteGameManager.Instance != null)
            CompleteGameManager.Instance.PauseGame();

        if (hideMainUIWhileMinigame)
            SetBoardUIVisible(false);

        // Disable board cameras so the mini-game camera owns the screen
        DisableBoardCameras();

        // Hide player avatars — they will be restored at their saved positions after the mini-game
        HidePlayerAvatars();

        string sceneName = GetMinigameSceneName(minigameType);
        if (!string.IsNullOrEmpty(sceneName))
            SceneManager.LoadSceneAsync(sceneName, LoadSceneMode.Additive);
        else
            Debug.LogWarning($"[MinigameOrchestrator] No scene mapped for minigameType={minigameType}");
    }

    /// <summary>
    /// Called by each mini-game scene when the game is over.
    /// Restores board state and notifies the GameManager.
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
            Debug.Log($"[MinigameOrchestrator] FINISH winner={winnerId} prize={prizeAmount}");

        string sceneName = GetMinigameSceneName(currentMinigameType);
        if (!string.IsNullOrEmpty(sceneName))
            SceneManager.UnloadSceneAsync(sceneName);

        // Re-enable board cameras
        RestoreBoardCameras();

        // Bring player avatars back to their saved board positions
        RestorePlayerAvatars();

        if (CompleteGameManager.Instance != null)
            CompleteGameManager.Instance.ResumeGame();

        if (hideMainUIWhileMinigame)
            SetBoardUIVisible(true);

        OnMinigameEnded.Invoke(winnerId, prizeAmount);
    }

    // ── Board state helpers ───────────────────────────────────────────────────

    private void DisableBoardCameras()
    {
        savedBoardCameras.Clear();
        foreach (Camera cam in FindObjectsOfType<Camera>())
        {
            if (cam.gameObject.scene.name == "SampleScene" && cam.enabled)
            {
                cam.enabled = false;
                savedBoardCameras.Add(cam);
            }
        }
        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] Disabled {savedBoardCameras.Count} board camera(s).");
    }

    private void RestoreBoardCameras()
    {
        foreach (Camera cam in savedBoardCameras)
            if (cam != null) cam.enabled = true;
        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] Restored {savedBoardCameras.Count} board camera(s).");
        savedBoardCameras.Clear();
    }

    private void HidePlayerAvatars()
    {
        savedPlayerAvatars.Clear();
        if (CompleteGameManager.Instance == null) return;

        foreach (PlayerData player in CompleteGameManager.Instance.GetAllPlayers())
        {
            if (player?.playerAvatar != null && player.playerAvatar.activeSelf)
            {
                player.playerAvatar.SetActive(false);
                savedPlayerAvatars.Add(player.playerAvatar);
            }
        }
        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] Hidden {savedPlayerAvatars.Count} player avatar(s).");
    }

    private void RestorePlayerAvatars()
    {
        foreach (GameObject avatar in savedPlayerAvatars)
            if (avatar != null) avatar.SetActive(true);
        if (debugMode)
            Debug.Log($"[MinigameOrchestrator] Restored {savedPlayerAvatars.Count} player avatar(s).");
        savedPlayerAvatars.Clear();
    }

    private void SetBoardUIVisible(bool visible)
    {
        // NOTE: change "SampleScene" if your board scene has a different name
        Canvas[] canvases = FindObjectsOfType<Canvas>();
        foreach (Canvas canvas in canvases)
        {
            if (canvas.gameObject.scene.name == "SampleScene")
            {
                canvas.gameObject.SetActive(visible);
                if (debugMode)
                    Debug.Log($"[MinigameOrchestrator] {(visible ? "Showing" : "Hiding")} canvas: {canvas.gameObject.name}");
            }
        }
    }

    // ── Scene name mapping ────────────────────────────────────────────────────

    /// <summary>
    /// Maps minigame type index to the scene name registered in Build Settings.
    /// </summary>
    private string GetMinigameSceneName(int minigameType)
    {
        switch (minigameType)
        {
            case 0: return "Khobz";
            case 1: return "3allouch";
            case 2: return "BentWaladScene";
            case 3: return "HandTracking_PlayerVSComputer";
            // Add more cases as new mini-games are added
            default: return null;
        }
    }
}
