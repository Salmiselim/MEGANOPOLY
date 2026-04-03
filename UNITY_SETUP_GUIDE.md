# 🎮 UNITY SETUP GUIDE - Step by Step (VISUAL)

## PHASE 1️⃣: Build Settings Configuration

### Step 1: Open Build Settings
```
File → Build Settings
```

### Step 2: Add Scenes
Click **"Add Open Scenes"** button to add current scene, then drag/arrange to match:

```
Index 0:  SampleScene    (Main Monopoly Board)
Index 1:  Khobz          (Khobz Minigame)
Index 2:  3allouch       (Sheep/3allouch Minigame)
Index 3:  BentWaladScene (BentWalad Minigame)
```

✅ **Before you continue:** Verify index 0 is SampleScene

---

## PHASE 2️⃣: Setup GameObjects in SampleScene

### Open SampleScene
1. Open **Assets/Scenes/SampleScene.unity**
2. Press Play to warm up, then stop

### Add SceneLoadingManager
1. Right-click in Hierarchy → **Create Empty**
2. Name it: **SceneLoadingManager**
3. With SceneLoadingManager selected, in Inspector → **Add Component**
4. Search and add: **SceneLoadingManager** script
5. Leave default settings (debugMode = true)

### Add MinigameOrchestrator (if not already present)
1. Right-click in Hierarchy → **Create Empty**
2. Name it: **MinigameOrchestrator**
3. With MinigameOrchestrator selected, in Inspector → **Add Component**
4. Search and add: **MinigameOrchestrator** script
5. In Inspector settings:
   - ✅ Hide Main UI While Minigame = **True**
   - ✅ Debug Mode = **True**

### Wire up GameManager
1. Select **GameManager** in Hierarchy
2. Inspector → Locate **CompleteGameManager** script
3. Verify these fields are auto-filled:
   - ✅ **Board Manager** - should be set
   - ✅ **Dice[0] and Dice[1]** - should be set
4. Check debug output at startup shows:
   ```
   ✓ MinigameOrchestrator connected
   ```

**Save SampleScene** (Ctrl+S)

---

## PHASE 3️⃣: Setup Each Minigame Scene

### For EACH scene: Khobz, 3allouch, BentWaladScene

#### Step A: Open Minigame Scene
```
Double-click: Assets/Scenes/Aymen/Khobz.unity
(or the other minigame scenes)
```

#### Step B: Create MinigameManager
1. Right-click in Hierarchy → **Create Empty**
2. Name it: **MinigameManager**
3. With MinigameManager selected → **Add Component**
4. Search and add: **MinigameIntegration** script
5. In Inspector:
   - **Return To Board Button** field: Leave empty (auto-finds)

#### Step C: Add Cleanup Script
1. Select the **Canvas** in the scene (or top-level UI object)
2. → **Add Component**
3. Search and add: **CleanupDuplicates** script
4. No setup needed

#### Step D: Connect Win Logic
Find where your minigame declares a winner and add:

```csharp
// When player wins
MinigameIntegration minigameIntegration = FindObjectOfType<MinigameIntegration>();
if (minigameIntegration != null)
{
    minigameIntegration.EndMinigame(winnerPlayerId, 300);
}
```

Or if you have a button "Return to Board":
1. Select that Button
2. In Inspector → OnClick() section
3. Click **+** to add listener
4. Drag **MinigameManager** object into the object field
5. From Function dropdown: **MinigameIntegration** → **EndMinigame(int, int)**
6. Set values: (0, 300) - player 0 wins 300 points

#### Step E: Save Scene
Press **Ctrl+S**

#### Repeat for all 3 minigame scenes ⚠️

---

## PHASE 4️⃣: Test Integration

### Quick Test (Inspector Method)
1. Open **SampleScene**
2. Press **Play**
3. In Hierarchy, select **GameManager**
4. In Inspector, at the bottom, find script component
5. Locate method **TriggerMinigameChallenge**
6. It should show parameters you can fill:
   - Player (blank - auto-uses current)
   - Property (blank)
   - Minigame Type (use dropdown: 0)
   - Prize Amount (300)
7. Click the method invoke button (▶️)
8. Watch Console:
   ```
   [MinigameOrchestrator] START minigame type=0...
   ✓ Game paused for minigame
   ✓ Hiding canvas...
   [SceneManager] Loading minigame scene: Khobz
   ```
9. Khobz scene should load!

### Quick Test (Return from Minigame)
1. While in minigame, click **Return to Board** button
2. Watch Console:
   ```
   [MinigameOrchestrator] FINISH winner=0, prize=300
   [SceneManager] Unloading minigame scene: Khobz
   ✓ Game resumed from minigame
   ```
3. Khobz scene should unload
4. Main board should be visible again

✅ **If this works, integration is successful!**

---

## PHASE 5️⃣: Customize Minigame Triggers

### Edit: Which properties trigger minigames?

Open: **Assets/core/Scripts/Core/GameManager.cs**

Find method: `bool ShouldTriggerMinigame(TileData property)`

Modify the property names to match YOUR board:

```csharp
private bool ShouldTriggerMinigame(TileData property)
{
    string name = property.tileName.ToLower();

    // Change these to match your ACTUAL property names
    bool isSpecialProperty =
        name.Contains("Alger") ||      // ← Change this
        name.Contains("Oran") ||       // ← And this
        name.Contains("Bizerte");      // ← And this

    return isSpecialProperty && !property.IsOwned();
}
```

### Edit: Map properties to minigames

In same file, find: `int GetMinigameTypeForProperty(TileData property)`

```csharp
private int GetMinigameTypeForProperty(TileData property)
{
    string name = property.tileName.ToLower();

    if (name.Contains("Alger"))       // Maps to Khobz (type 0)
        return 0;
    else if (name.Contains("Oran"))   // Maps to 3allouch (type 1)
        return 1;
    else if (name.Contains("Bizerte")) // Maps to BentWalad (type 2)
        return 2;
    else
        return 0;
}
```

---

## PHASE 6️⃣: Troubleshooting Checklist

| Issue | Checklist |
|-------|-----------|
| **Scenes won't load** | ✅ Build Settings has all 4 scenes? ✅ Scene names match exactly? |
| **Game doesn't pause** | ✅ GameManager has PauseGame() method? ✅ MinigameOrchestrator calls it? |
| **UI stays hidden** | ✅ hideMainUIWhileMinigame = True? ✅ Canvas is in SampleScene? |
| **Duplicate EventSystem error** | ✅ CleanupDuplicates added to minigame Canvas? ✅ Start() method runs? |
| **Winner doesn't get money** | ✅ MinigameIntegration.EndMinigame() called with correct params? ✅ OnMinigameEnded event connected? |
| **Scene doesn't unload** | ✅ UnloadMinigameScene() has correct scene name? ✅ SampleScene set as active? |

---

## FILES CREATED / MODIFIED

✅ **Created:**
- `Assets/core/Scripts/Core/SceneLoadingManager.cs`
- `Assets/core/Scripts/Core/CleanupDuplicates.cs`

✅ **Modified:**
- `Assets/core/Scripts/Core/MinigameOrchestrator.cs`
- `Assets/core/Scripts/Core/GameManager.cs`

✅ **Already Existed:**
- `Assets/core/Scripts/Utilities/MinigameData.cs`
- `Assets/core/Scripts/Core/MinigameIntegration.cs`

---

## FINAL CHECKLIST

- [ ] Build Settings has all 4 scenes in order
- [ ] SampleScene has SceneLoadingManager GameObject
- [ ] SampleScene has MinigameOrchestrator GameObject
- [ ] GameManager is connected to MinigameOrchestrator
- [ ] Each minigame scene has MinigameManager with MinigameIntegration
- [ ] Each minigame scene has CleanupDuplicates script
- [ ] Minigame win logic calls EndMinigame() with correct params
- [ ] Property names in ShouldTriggerMinigame() match your board
- [ ] Minigame → Property mapping in GetMinigameTypeForProperty() is correct
- [ ] **TEST** - Trigger minigame from Inspector
- [ ] **TEST** - Return from minigame and verify resume works

---

## NEXT: Connect to UI Buttons (Optional)

If you want a UI button to trigger minigames:

```csharp
// Add to any button's OnClick() event:
GameManager.Instance.TriggerMinigameChallenge(
    GameManager.Instance.GetCurrentPlayer(),
    propertyTile,
    0,  // minigameType
    300 // prizeAmount
);
```

---

## QUICK DEBUG COMMANDS

Add these to your scene for testing:

```csharp
// Press 'M' to trigger minigame
if (Input.GetKeyDown(KeyCode.M))
{
    MinigameOrchestrator.Instance.StartMinigame(0, "Test",
        CompleteGameManager.Instance.GetCurrentPlayer(), 300);
}

// Press 'R' to return from minigame
if (Input.GetKeyDown(KeyCode.R))
{
    MinigameOrchestrator.FinishMinigame(0, 300);
}
```

