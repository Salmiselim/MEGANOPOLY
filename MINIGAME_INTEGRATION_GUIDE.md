# 🎮 MINIGAME INTEGRATION GUIDE - Step By Step

## OVERVIEW
You have 4 scenes to integrate:
- **MonopolyBoard** (main scene) - Assets/Scenes/SampleScene.unity
- **KhobzScene** - Assets/Scenes/Aymen/Khobz.unity
- **SheepScene** - Assets/MiniGames/3allouchEl3id/Scenes/3allouch.unity
- **BentWaladScene** - Assets/MiniGames/BentWalad/scene/BentWaladScene.unity

---

## STEP 1: Configure Build Settings

### 1.1 Open Build Settings
1. Go to **File → Build Settings**
2. Click **Add Open Scenes** to add your current scene (if not already there)
3. Add all 4 scenes in this order:
   - Index 0: **SampleScene** (MonopolyBoard - main scene)
   - Index 1: **Khobz** (KhobzScene)
   - Index 2: **3allouch** (SheepScene)
   - Index 3: **BentWaladScene**

✅ **Verify:** Scene 0 should be SampleScene (MonopolyBoard)

---

## STEP 2: Create Scene Loading Manager

This script handles loading/unloading minigame scenes safely.

### File: `Assets/core/Scripts/Core/SceneManager.cs`

```csharp
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
```

**Setup in Unity:**
1. In SampleScene, create an empty GameObject called "SceneLoadingManager"
2. Add the `SceneLoadingManager` script to it
3. No inspector setup needed

---

## STEP 3: Update Minigame Data

The existing MinigameData is good, but add this constant:

**File:** `Assets/core/Scripts/Utilities/MinigameData.cs` (Update line 18)

```csharp
public class MinigameState
{
    public string propertyName;
    public string currentPlayerName;
    public int minigameType;  // 0=Khobz, 1=3allouch, 2=BentWalad
    public int currentPlayerId;
    public int winner = -1;
    public int winnerMoney = 0;
    public bool isCompleted = false;
}
```

---

## STEP 4: Update MinigameOrchestrator

Replace your existing MinigameOrchestrator with this enhanced version:

**File:** `Assets/core/Scripts/Core/MinigameOrchestrator.cs`

```csharp
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

        Debug.Log($"[MinigameOrchestrator] START minigame type={minigameType}, property={propertyName}, " +
                  $"challenger={challenger?.playerName ?? "Unknown"}, prize={prizeAmount}");

        // Pause main game
        if (CompleteGameManager.Instance != null)
            CompleteGameManager.Instance.PauseGame();

        // Hide main UI
        if (hideMainUIWhileMinigame)
            HideMainUI(true);

        // Load minigame scene additively
        if (SceneLoadingManager.Instance != null)
            SceneLoadingManager.Instance.LoadMinigameScene(minigameType);
        else
            Debug.LogWarning("[MinigameOrchestrator] SceneLoadingManager not found!");
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

        Debug.Log($"[MinigameOrchestrator] FINISH winner={winnerId}, prize={prizeAmount}");

        // Unload minigame scene
        if (SceneLoadingManager.Instance != null)
            SceneLoadingManager.Instance.UnloadMinigameScene(currentMinigameType);

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
        // Find all Canvas objects in main scene and toggle them
        Canvas[] canvases = FindObjectsOfType<Canvas>();
        foreach (Canvas canvas in canvases)
        {
            if (canvas.gameObject.scene.name == "SampleScene")
            {
                canvas.gameObject.SetActive(!hide);
            }
        }
    }
}
```

---

## STEP 5: Update GameManager to Trigger Minigames

In `Assets/core/Scripts/Core/GameManager.cs`, find the `HandleProperty` method
and add this check for properties that should trigger minigames:

**Location:** Around line 599 in HandleProperty method

Add this BEFORE showing the PropertyCardUI:

```csharp
// Check if this property triggers a minigame
if (ShouldTriggerMinigame(property))
{
    int minigameType = GetMinigameTypeForProperty(property);
    int prizeAmount = Mathf.Max(100, property.purchasePrice / 2);
    TriggerMinigameChallenge(player, property, minigameType, prizeAmount);
    return;
}
```

And add these helper methods to GameManager:

```csharp
private bool ShouldTriggerMinigame(TileData property)
{
    // Trigger minigame only if property matches certain criteria
    // For example: every Algerian city triggers minigame
    // You can customize this logic
    return property.tileType == TileType.Property &&
           (property.tileName.Contains("Alger") || property.tileName.Contains("Oran"));
}

private int GetMinigameTypeForProperty(TileData property)
{
    // Map properties to minigames
    // You can customize this based on property names
    if (property.tileName.Contains("Alger"))
        return 0; // Khobz
    else if (property.tileName.Contains("Oran"))
        return 1; // 3allouch
    else
        return 2; // BentWalad
}
```

---

## STEP 6: Setup Each Minigame Scene

For EACH minigame scene (Khobz, 3allouch, BentWalad), do this:

### 6.1 Add MinigameIntegration Script
1. Open the minigame scene (e.g., Khobz.unity)
2. Create an empty GameObject called "MinigameManager"
3. Attach the `MinigameIntegration` script to it

### 6.2 Remove Duplicate EventSystem/AudioListener
Add this script to each minigame scene root:

**File:** `Assets/core/Scripts/Core/CleanupDuplicates.cs`

```csharp
using UnityEngine;

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
                Debug.Log("[Cleanup] Destroying duplicate EventSystem");
                Destroy(eventSystems[i].gameObject);
            }
        }

        // Destroy duplicate AudioListener
        AudioListener[] listeners = FindObjectsOfType<AudioListener>();
        if (listeners.Length > 1)
        {
            for (int i = 1; i < listeners.Length; i++)
            {
                Debug.Log("[Cleanup] Destroying duplicate AudioListener");
                Destroy(listeners[i].gameObject);
            }
        }
    }
}
```

1. Create empty GameObject in minigame scene root
2. Attach `CleanupDuplicates` script
3. Save scene

### 6.3 Ensure Minigame Ends Properly
In your minigame win/lose logic, call:

```csharp
// When minigame is won
MinigameIntegration minigameIntegration = FindObjectOfType<MinigameIntegration>();
if (minigameIntegration != null)
{
    minigameIntegration.EndMinigame(winnerId, prizeAmount);
}
```

---

## STEP 7: Complete Setup Checklist

### In SampleScene (MonopolyBoard):
- [ ] MinigameOrchestrator GameObject exists
- [ ] SceneLoadingManager GameObject exists
- [ ] CompleteGameManager has minigameOrchestrator reference
- [ ] All dice, board, UI are setup

### In Build Settings:
- [ ] Index 0: SampleScene
- [ ] Index 1: Khobz
- [ ] Index 2: 3allouch
- [ ] Index 3: BentWaladScene

### In Each Minigame Scene:
- [ ] MinigameManager GameObject with MinigameIntegration
- [ ] CleanupDuplicates script added
- [ ] End game logic calls MinigameIntegration.EndMinigame()

---

## STEP 8: Testing Minigame Integration

### Quick Test in Unity:

1. **Open SampleScene**
2. **Press Play**
3. **In Inspector**, find CompleteGameManager
4. **Call TriggerMinigameChallenge()** directly from Inspector:
   - Set minigameType = 0
   - Set prizeAmount = 300
5. **Watch:**
   - Game should pause
   - Khobz scene should load additively
   - Main UI should hidden
6. **In Khobz scene**, click "Return to Board" or win
7. **Watch:**
   - Khobz scene unloads
   - Game resumes
   - UI returns
   - Winner gets prize money

---

## STEP 9: Troubleshooting

| Problem | Solution |
|---------|----------|
| Scene won't load | Check Build Settings index order |
| Duplicate Canvas | Add CleanupDuplicates to minigame scene |
| Game doesn't pause | Ensure CompleteGameManager.PauseGame() is called |
| UI stays hidden | Check HideMainUI() logic in MinigameOrchestrator |
| Winner doesn't get money | Check OnMinigameEnded event is wired to OnMinigameEnded() in GameManager |

---

## NEXT STEPS

1. ✅ Setup Build Settings
2. ✅ Create SceneLoadingManager
3. ✅ Update MinigameOrchestrator
4. ✅ Add minigame trigger logic to GameManager
5. ✅ Setup each minigame scene
6. ✅ Test integration
7. 📌 **OPTIONAL:** Add UI button to trigger minigames from main board for testing

---

## CODE FILES TO CREATE/UPDATE

1. **Assets/core/Scripts/Core/SceneManager.cs** ← NEW
2. **Assets/core/Scripts/Core/MinigameOrchestrator.cs** ← UPDATE
3. **Assets/core/Scripts/Core/GameManager.cs** ← MODIFY (add helper methods)
4. **Assets/core/Scripts/Core/CleanupDuplicates.cs** ← NEW
5. **Assets/core/Scripts/Utilities/MinigameData.cs** ← ALREADY EXISTS

---

## MINIGAME SCENE NAMES IN BUILD SETTINGS

Make sure these exact names match:
- This script expects scenes named: "Khobz", "3allouch", "BentWaladScene"
- If your scene names are different, update `GetMinigameSceneName()` in SceneLoadingManager

