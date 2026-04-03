# ⚡ MINIGAME INTEGRATION QUICK REFERENCE

## 1️⃣ WHAT TO DO IN UNITY RIGHT NOW

### In SampleScene:
```
GameManager → (auto-finds MinigameOrchestrator)
SceneLoadingManager → ✓ Add script
MinigameOrchestrator → ✓ Add script
```

### In Each Minigame Scene (3x):
```
MinigameManager → Add MinigameIntegration script
Canvas → Add CleanupDuplicates script
```

### In Build Settings:
```
Index 0: SampleScene
Index 1: Khobz
Index 2: 3allouch
Index 3: BentWaladScene
```

---

## 2️⃣ SCRIPT FLOW (HOW IT WORKS)

```
Player lands on special property
        ↓
GameManager.HandleProperty() checks ShouldTriggerMinigame()
        ↓ Yes!
MinigameOrchestrator.StartMinigame()
        ↓
- Calls GameManager.PauseGame()
- Hides canvas
- Calls SceneLoadingManager.LoadMinigameScene()
        ↓
Minigame scene loads additively
        ↓
Player plays minigame...
        ↓
MinigameIntegration.EndMinigame() called with (winnerId, prize)
        ↓
MinigameOrchestrator.HandleMinigameFinished()
        ↓
- Calls SceneLoadingManager.UnloadMinigameScene()
- Calls GameManager.ResumeGame()
- Shows canvas
- Gives winner their prize money
        ↓
Game continues at next turn
```

---

## 3️⃣ KEY CLASS METHODS

### MinigameOrchestrator
```csharp
StartMinigame(minigameType, propertyName, player, prizeAmount)
FinishMinigame(winnerId, prizeAmount) // Static
```

### SceneLoadingManager
```csharp
LoadMinigameScene(minigameType)      // 0=Khobz, 1=3allouch, 2=BentWalad
UnloadMinigameScene(minigameType)
```

### GameManager
```csharp
TriggerMinigameChallenge(player, property, minigameType, prizeAmount)
PauseGame()    // Called automatically
ResumeGame()   // Called automatically
```

### MinigameIntegration
```csharp
EndMinigame(winnerId, prizeAmount)
OnGameFinishedNaturally(winnerIndex)
```

---

## 4️⃣ PROPERTY TRIGGER LOGIC (CUSTOMIZE THIS)

**File:** `GameManager.cs` → `ShouldTriggerMinigame()`

Change property names to match YOUR board:

```csharp
string name = property.tileName.ToLower();
if (name.Contains("YourPropertyName"))
    return true;
```

**Map properties to minigames** → `GetMinigameTypeForProperty()`

```csharp
if (name.Contains("YourProperty1")) return 0; // Khobz
if (name.Contains("YourProperty2")) return 1; // 3allouch
if (name.Contains("YourProperty3")) return 2; // BentWalad
```

---

## 5️⃣ TO TRIGGER MINIGAME FROM CODE

```csharp
// Method 1: Direct trigger
MinigameOrchestrator.Instance.StartMinigame(
    minigameType: 0,
    propertyName: "My Property",
    challenger: currentPlayer,
    prizeAmount: 300
);

// Method 2: Via GameManager
CompleteGameManager.Instance.TriggerMinigameChallenge(
    player: currentPlayer,
    property: tileData,
    minigameType: 0,
    prizeAmount: 300
);
```

---

## 6️⃣ TO END MINIGAME FROM MINIGAME SCENE

```csharp
// When player wins:
MinigameIntegration integration = FindObjectOfType<MinigameIntegration>();
integration.EndMinigame(winnerPlayerId, prizeAmount);

// Via static method:
MinigameOrchestrator.FinishMinigame(winnerPlayerId, prizeAmount);
```

---

## 7️⃣ DEBUG OUTPUT EXPECTED

When starting minigame:
```
[MinigameOrchestrator] START minigame type=0, property=TestProp...
[GameManager] Game paused for minigame
[MinigameOrchestrator] Hiding canvas: CanvasName
[SceneManager] Loading minigame scene: Khobz
```

When finishing minigame:
```
[MinigameOrchestrator] FINISH winner=0, prize=300
[SceneManager] Unloading minigame scene: Khobz
[GameManager] Game resumed from minigame
[MinigameOrchestrator] Showing canvas: CanvasName
[GameManager] Minigame winner: Player1 won 300 DT
```

---

## 8️⃣ COMMON MISTAKES & FIXES

| Problem | Fix |
|---------|-----|
| Scene not in Build Settings | ✅ Add it: File → Build Settings → Add Scene |
| Script not found | ✅ Save file (Ctrl+S) and refresh |
| EventSystem error | ✅ Add CleanupDuplicates to minigame scene |
| Property doesn't trigger minigame | ✅ Update property name in ShouldTriggerMinigame() |
| Game doesn't resume | ✅ Check GameManager.ResumeGame() in OnMinigameEnded() |
| Canvas stays hidden | ✅ Verify Canvas is in SampleScene, not minigame scene |

---

## 9️⃣ MINIGAME TYPE VALUES

```
0 = Khobz
1 = 3allouch (Sheep)
2 = BentWalad
```

Always use these numbers when calling StartMinigame() or LoadMinigameScene()

---

## 🔟 ONE-MINUTE TEST

1. Play SampleScene
2. In GameManager Inspector, scroll to find the scene "Khobz"
3. Call StartMinigame() directly: (0, "Test", null, 300)
4. If Khobz loads → ✅ SUCCESS
5. Click return button → Should unload and resume

---

## 📋 CHECKLIST BEFORE SUBMITTING

- [ ] All 4 scenes in Build Settings
- [ ] SampleScene has SceneLoadingManager & MinigameOrchestrator
- [ ] All minigame scenes have MinigameIntegration & CleanupDuplicates
- [ ] Property names match your board
- [ ] Minigame scenes unload properly
- [ ] Winner gets prize money
- [ ] Game resumes correctly

