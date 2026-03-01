using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

/// <summary>
/// Fixed CompleteGameManager with proper array bounds checking
/// </summary>
public class CompleteGameManager : MonoBehaviour
{
    public static CompleteGameManager Instance { get; private set; }

    [Header("Game Settings")]
    [SerializeField] private int numberOfPlayers = 4;
    [SerializeField] private int startingMoney = 1500;
    [SerializeField] private int goBonus = 200;

    [Header("References")]
    [SerializeField] private BoardManager boardManager;
    [SerializeField] private GameObject playerPrefab;
    [SerializeField] private SimpleDiceController[] dice = new SimpleDiceController[2];

    [Header("Spawn System")]
    [SerializeField] private bool useManualSpawnPoints = true;
    [SerializeField] private PlayerSpawnPoint[] manualSpawnPoints = new PlayerSpawnPoint[4];

    [Header("Fallback Spawn")]
    [SerializeField] private float playerSpacing = 10f;
    [SerializeField] private Vector3 manualSpawnOffset = Vector3.zero;

    [Header("Player Setup")]
    [SerializeField]
    private Color[] playerColors = new Color[4]
    {
        Color.red,
        Color.blue,
        Color.green,
        Color.yellow
    };
    [SerializeField]
    private string[] playerNames = new string[4]
    {
        "Player 1",
        "Player 2",
        "Player 3",
        "Player 4"
    };

    [Header("DEBUG — disable in final build")]
    [SerializeField] private bool enableDebugCheats = true;
    [SerializeField] private KeyCode cheatKey_GiveMonopoly    = KeyCode.F1;
    [SerializeField] private KeyCode cheatKey_OpenBuildMenu   = KeyCode.F2;
    [SerializeField] private KeyCode cheatKey_GiveMoney       = KeyCode.F3;
    [SerializeField] private KeyCode cheatKey_TestRent        = KeyCode.F4;
    [SerializeField] private KeyCode cheatKey_BuyAll          = KeyCode.F5;
    [SerializeField] private KeyCode cheatKey_TestTrain        = KeyCode.F6;

    // Game State
    private GameState currentGameState = GameState.Setup;
    private PlayerData[] players;
    private int currentPlayerIndex = 0;
    private bool waitingForDiceRoll = false;

    // Dice tracking
    private bool dice1HasResult = false;
    private bool dice2HasResult = false;
    private int dice1Result = 0;
    private int dice2Result = 0;

    // Events
    public UnityEvent OnGameStarted = new UnityEvent();
    public UnityEvent<int> OnTurnChanged = new UnityEvent<int>();

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        else
        {
            Destroy(gameObject);
            return;
        }

        if (boardManager == null)
            boardManager = FindObjectOfType<BoardManager>();

        // Auto-find dice if not assigned
        if (dice == null || dice.Length < 2 || dice[0] == null || dice[1] == null)
        {
            SimpleDiceController[] foundDice = FindObjectsOfType<SimpleDiceController>();
            if (foundDice.Length >= 2)
            {
                // Sort by diceNumber to ensure consistent ordering
                System.Array.Sort(foundDice, (a, b) => a.diceNumber.CompareTo(b.diceNumber));
                dice = new SimpleDiceController[2];
                dice[0] = foundDice[0];
                dice[1] = foundDice[1];
                Debug.Log($"✓ Auto-found {foundDice.Length} dice controllers");
            }
            else if (foundDice.Length == 1)
            {
                Debug.LogWarning($"⚠️ Only found 1 dice controller, need 2");
            }
        }

        // Auto-find spawn points
        if (useManualSpawnPoints && (manualSpawnPoints == null || manualSpawnPoints.Length == 0 || manualSpawnPoints[0] == null))
        {
            PlayerSpawnPoint[] foundPoints = FindObjectsOfType<PlayerSpawnPoint>();
            if (foundPoints.Length >= numberOfPlayers)
            {
                manualSpawnPoints = new PlayerSpawnPoint[numberOfPlayers];
                System.Array.Sort(foundPoints, (a, b) => a.playerIndex.CompareTo(b.playerIndex));

                for (int i = 0; i < numberOfPlayers; i++)
                {
                    manualSpawnPoints[i] = foundPoints[i];
                }

                Debug.Log($"✓ Auto-found {foundPoints.Length} spawn points");
            }
            else
            {
                Debug.LogWarning($"⚠️ Only found {foundPoints.Length} spawn points");
                useManualSpawnPoints = false;
            }
        }
    }

    private void Start()
    {
        StartCoroutine(InitializeGame());
    }

    private IEnumerator InitializeGame()
    {
        currentGameState = GameState.Setup;

        Debug.Log("═══════════════════════════════════");
        Debug.Log("   MEGANOPOLY - GAME START");
        Debug.Log("═══════════════════════════════════");

        yield return new WaitForSeconds(0.5f);

        if (boardManager == null)
        {
            Debug.LogError("❌ BoardManager not found!");
            yield break;
        }

        if (dice == null || dice.Length < 2 || dice[0] == null || dice[1] == null)
        {
            Debug.LogError("❌ Dice not assigned!");
            yield break;
        }

        yield return new WaitForSeconds(0.5f);

        InitializePlayers();
        SetupDiceEvents();

        yield return new WaitForSeconds(1f);
        StartGame();
    }

    private void InitializePlayers()
    {
        Debug.Log($"\n--- Creating {numberOfPlayers} Players ---");

        players = new PlayerData[numberOfPlayers];

        for (int i = 0; i < numberOfPlayers; i++)
        {
            players[i] = new PlayerData(i, playerNames[i], playerColors[i]);
            players[i].money = startingMoney;

            Vector3 spawnPos = GetSpawnPosition(i);

            if (playerPrefab == null)
            {
                Debug.LogError("❌ Player prefab not assigned!");
                return;
            }

            GameObject avatarObj = Instantiate(playerPrefab, spawnPos, Quaternion.identity);
            avatarObj.name = $"Player_{i}_{playerNames[i]}";

            // Apply color
            Renderer renderer = avatarObj.GetComponentInChildren<Renderer>();
            if (renderer != null)
            {
                Material mat = new Material(renderer.material);
                mat.color = playerColors[i];
                renderer.material = mat;
            }

            players[i].playerAvatar = avatarObj;
            players[i].avatarTransform = avatarObj.transform;

            // Setup movement
            PlayerMovement movement = avatarObj.GetComponent<PlayerMovement>();
            if (movement == null)
                movement = avatarObj.AddComponent<PlayerMovement>();

            movement.Initialize(players[i]);
            players[i].movementController = movement;

            // Subscribe to events WITH BOUNDS CHECKING
            int playerIndex = i; // Capture for closure

            movement.OnTileLanded.AddListener((tile) => {
                // SAFE: Check if player index is valid
                if (playerIndex >= 0 && playerIndex < players.Length && players[playerIndex] != null)
                {
                    OnPlayerLandedOnTile(players[playerIndex], tile);
                }
            });

            movement.OnPassedGO.AddListener(() => {
                // SAFE: Check if player index is valid
                if (playerIndex >= 0 && playerIndex < players.Length && players[playerIndex] != null)
                {
                    HandlePassGO(players[playerIndex]);
                }
            });

            Debug.Log($"✓ {playerNames[i]} spawned at {spawnPos}");
        }

        Debug.Log($"✓ All players initialized!\n");
    }

    private Vector3 GetSpawnPosition(int playerIndex)
    {
        if (useManualSpawnPoints && manualSpawnPoints != null && playerIndex < manualSpawnPoints.Length)
        {
            if (manualSpawnPoints[playerIndex] != null)
            {
                return manualSpawnPoints[playerIndex].transform.position;
            }
        }

        TileData goTile = boardManager.GetTile(0);
        if (goTile == null)
        {
            Debug.LogError("❌ GO tile not found!");
            return Vector3.zero;
        }

        Vector3 spawnPos = goTile.worldPosition + manualSpawnOffset;
        spawnPos += Vector3.right * (playerIndex * playerSpacing);

        return spawnPos;
    }

    private void SetupDiceEvents()
    {
        if (dice[0] != null)
        {
            dice[0].OnDiceRolled.AddListener(OnDice1Rolled);
            Debug.Log("✓ Dice 1 connected");
        }

        if (dice[1] != null)
        {
            dice[1].OnDiceRolled.AddListener(OnDice2Rolled);
            Debug.Log("✓ Dice 2 connected");
        }
    }

    private void StartGame()
    {
        currentGameState = GameState.Playing;

        Debug.Log("\n═══════════════════════════════════");
        Debug.Log("       🎮 GAME STARTED! 🎮");
        Debug.Log("═══════════════════════════════════\n");

        OnGameStarted?.Invoke();
        StartTurn(0);
    }

    private void StartTurn(int playerIndex)
    {
        currentPlayerIndex = playerIndex;

        // SAFE: Bounds check
        if (currentPlayerIndex < 0 || currentPlayerIndex >= players.Length)
        {
            Debug.LogError($"Invalid player index: {currentPlayerIndex}");
            return;
        }

        PlayerData currentPlayer = players[currentPlayerIndex];

        currentPlayer.currentState = PlayerState.WaitingToRoll;

        Debug.Log($"\n┌──────────────────────────────────────┐");
        Debug.Log($"│  {currentPlayer.playerName}'s TURN");
        Debug.Log($"├──────────────────────────────────────┤");
        Debug.Log($"│  💰 Money: ${currentPlayer.money}");
        Debug.Log($"│  📍 Tile: {boardManager.GetTile(currentPlayer.currentTileIndex)?.tileName ?? "Unknown"}");
        Debug.Log($"│  🏠 Properties: {currentPlayer.ownedProperties.Count}");
        Debug.Log($"└──────────────────────────────────────┘");
        Debug.Log($"🎲 Press SPACE to roll!\n");

        OnTurnChanged?.Invoke(currentPlayerIndex);

        if (currentPlayer.isInJail)
        {
            HandleJailTurn(currentPlayer);
            return;
        }

        EnableDiceForPlayer();
    }

    private void HandleJailTurn(PlayerData player)
    {
        player.jailTurnsRemaining--;

        if (player.jailTurnsRemaining <= 0)
        {
            player.ReleaseFromJail();
            Debug.Log($"🔓 Released from jail!");
        }

        EndTurn();
    }

    private void EnableDiceForPlayer()
    {
        waitingForDiceRoll = true;
        dice1HasResult = false;
        dice2HasResult = false;
        dice1Result = 0;
        dice2Result = 0;

        if (dice[0] != null) dice[0].ResetDice();
        if (dice[1] != null) dice[1].ResetDice();
    }

    private void OnDice1Rolled(int value)
    {
        if (!waitingForDiceRoll) return;

        dice1Result = value;
        dice1HasResult = true;

        Debug.Log($"🎲 Dice 1: {value}");

        CheckBothDiceResults();
    }

    private void OnDice2Rolled(int value)
    {
        if (!waitingForDiceRoll) return;

        dice2Result = value;
        dice2HasResult = true;

        Debug.Log($"🎲 Dice 2: {value}");

        CheckBothDiceResults();
    }

    private void CheckBothDiceResults()
    {
        if (dice1HasResult && dice2HasResult)
        {
            waitingForDiceRoll = false;
            int total = dice1Result + dice2Result;

            Debug.Log($"\n🎲🎲 TOTAL: {dice1Result} + {dice2Result} = {total}\n");

            StartCoroutine(HandlePlayerMove(total));
        }
    }

    private IEnumerator HandlePlayerMove(int spaces)
    {
        // SAFE: Bounds check
        if (currentPlayerIndex < 0 || currentPlayerIndex >= players.Length)
        {
            Debug.LogError($"Invalid player index during move: {currentPlayerIndex}");
            yield break;
        }

        PlayerData currentPlayer = players[currentPlayerIndex];
        currentPlayer.currentState = PlayerState.Rolling;

        yield return new WaitForSeconds(0.5f);

        Debug.Log($"🚶 {currentPlayer.playerName} moving {spaces} spaces...");

        if (currentPlayer.movementController == null)
        {
            Debug.LogError($"❌ No movement controller!");
            EndTurn();
            yield break;
        }

        currentPlayer.movementController.MoveByDiceRoll(spaces, boardManager.allTiles);

        // Wait for movement
        float timeout = 20f;
        float elapsed = 0f;

        while (currentPlayer.movementController.IsMoving() && elapsed < timeout)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        if (elapsed >= timeout)
        {
            Debug.LogError("❌ Movement timeout!");
        }

        yield return new WaitForSeconds(0.5f);

        HandleTileLanding(currentPlayer);
    }

    private void HandleTileLanding(PlayerData player)
    {
        // SAFE: Bounds check
        if (player.currentTileIndex < 0 || player.currentTileIndex >= 40)
        {
            Debug.LogError($"Invalid tile index: {player.currentTileIndex}");
            EndTurn();
            return;
        }

        TileData landedTile = boardManager.GetTile(player.currentTileIndex);

        if (landedTile == null)
        {
            Debug.LogError($"Tile {player.currentTileIndex} is null!");
            EndTurn();
            return;
        }

        Debug.Log($"\n📍 Landed on: {landedTile.tileName} ({landedTile.tileType})");

        player.currentState = PlayerState.OnTile;

        switch (landedTile.tileType)
        {
            case TileType.Property:
                HandleProperty(player, landedTile);
                break;

            case TileType.Railroad:
                HandleRailroad(player, landedTile);
                break;

            case TileType.Tax:
                int tax = landedTile.baseRent;
                player.RemoveMoney(tax);
                Debug.Log($"💸 Paid ${tax} tax");
                EndTurn();
                break;

            case TileType.GoToJail:
                Debug.Log($"🚔 Going to JAIL!");
                player.SendToJail();
                player.currentTileIndex = 10;
                player.movementController?.TeleportToTile(10, boardManager.allTiles);
                EndTurn();
                break;

            default:
                EndTurn();
                break;
        }
    }

    // ── Railroad / Train routes ───────────────────────────────────────────────

    // Bidirectional routes: key = from tile index, value = to tile index
    private static readonly Dictionary<int, int> s_TrainRoutes = new Dictionary<int, int>
    {
        { 5,  25 }, { 25, 5  },
        { 15, 35 }, { 35, 15 },
    };

    private static int GetTrainDestination(int fromIndex)
    {
        return s_TrainRoutes.TryGetValue(fromIndex, out int dest) ? dest : -1;
    }

    private static int CalculateTrainFare(TileData station, PlayerData rider, PlayerData[] allPlayers)
    {
        if (!station.IsOwned()) return 50;
        if (station.ownerId == rider.playerId) return 0;

        PlayerData owner = null;
        foreach (PlayerData p in allPlayers)
            if (p != null && p.playerId == station.ownerId) { owner = p; break; }

        if (owner == null) return 50;

        int stationCount = 0;
        foreach (TileData t in owner.ownedProperties)
            if (t.tileType == TileType.Railroad) stationCount++;

        int[] fareTable = { 0, 25, 50, 100, 200 };
        return fareTable[Mathf.Clamp(stationCount, 0, 4)];
    }

    private void HandleRailroad(PlayerData player, TileData station)
    {
        int destIndex = GetTrainDestination(station.tileIndex);
        if (destIndex < 0) { EndTurn(); return; }

        TileData destTile = boardManager.GetTile(destIndex);
  if (destTile == null) { EndTurn(); return; }

        // Unowned — offer to buy first, then show train menu
        if (!station.IsOwned())
        {
            TileMarker marker = boardManager.GetTileMarker(station.tileIndex);
  if (PropertyCardUI.Instance != null && marker != null && marker.propertyCard != null)
       {
         PropertyCardUI.Instance.OnPurchaseDecision.RemoveAllListeners();
                PropertyCardUI.Instance.OnPurchaseDecision.AddListener((didBuy) =>
        {
          if (didBuy) PropertyManager.Instance?.TryBuyProperty(player, station);
        ShowTrainChoice(player, station, destTile);
      });
       PropertyCardUI.Instance.ShowPropertyCard(player, station, marker);
          return;
         }
        }

      ShowTrainChoice(player, station, destTile);
    }

    private void ShowTrainChoice(PlayerData player, TileData station, TileData destTile)
    {
        if (TrainMenuUI.Instance == null)
        {
 Debug.LogWarning("[Railroad] TrainMenuUI.Instance is null — add a TrainMenuUI canvas to the scene.");
      EndTurn();
    return;
 }

        int fare = CalculateTrainFare(station, player, players);

        Vector3 playerPos = player.avatarTransform != null
          ? player.avatarTransform.position
 : (Camera.main != null ? Camera.main.transform.position : Vector3.zero);

 TrainMenuUI.Instance.OnDecision.RemoveAllListeners();
   TrainMenuUI.Instance.OnDecision.AddListener((tookTrain) =>
      {
          if (tookTrain)
 {
       if (fare > 0)
         {
         if (station.IsOwned() && station.ownerId != player.playerId
  && station.ownerId >= 0 && station.ownerId < players.Length)
          {
          players[station.ownerId].AddMoney(fare);
        Debug.Log($"[Railroad] {fare} DT fare → {players[station.ownerId].playerName}");
 }
       player.RemoveMoney(fare);
   }
 player.currentTileIndex = destTile.tileIndex;
                player.movementController?.TeleportToTile(destTile.tileIndex, boardManager.allTiles);
        Debug.Log($"[Railroad] {player.playerName} → {destTile.tileName}");
    }
        EndTurn();
        });

      TrainMenuUI.Instance.ShowTrainMenu(
          station.tileName, destTile.tileName,
      fare, player.money, playerPos);
    }

    private void HandleProperty(PlayerData player, TileData property)
    {
        if (!property.IsOwned())
        {
            // Get the tile marker to access the card
            TileMarker marker = boardManager.GetTileMarker(property.tileIndex);

            if (PropertyCardUI.Instance != null && marker != null && marker.propertyCard != null)
            {
                // Use animated card UI
                PropertyCardUI.Instance.OnPurchaseDecision.RemoveAllListeners();
                PropertyCardUI.Instance.OnPurchaseDecision.AddListener((didBuy) =>
                {
                    if (didBuy)
                    {
                        PropertyManager.Instance?.TryBuyProperty(player, property);
                    }
                    EndTurn();
                });

                PropertyCardUI.Instance.ShowPropertyCard(player, property, marker);
                return; // Wait for player decision
            }
            else
            {
                // Fallback: console-based decision
                Debug.Log($"🏠 {property.tileName} - {property.purchasePrice} DT");
                Debug.Log($"💰 Your Balance: {player.money} DT");

                if (player.CanAfford(property.purchasePrice))
                    Debug.LogWarning("⚠️ PropertyCardUI not set up - auto-passing");
            }
        }
        else if (property.ownerId == player.playerId)
        {
            // Player landed on their OWN property — open the building menu
            if (BuildingMenuUI.Instance != null)
            {
                Debug.Log($"[GameManager] Opening BuildingMenuUI for {property.tileName}");
                BuildingMenuUI.Instance.OnMenuClosed.RemoveAllListeners();
                BuildingMenuUI.Instance.OnMenuClosed.AddListener(EndTurn);
                BuildingMenuUI.Instance.ShowBuildingMenu(player, property);
                return; // Wait for player to close the menu
            }
            else
            {
                Debug.LogWarning("[GameManager] BuildingMenuUI.Instance is null — make sure the Canvas has the BuildingMenuUI script attached!");
            }
        }
        else if (property.ownerId >= 0 && property.ownerId < players.Length)
        {
            int rent = property.GetCurrentRent();
            PlayerData owner = players[property.ownerId];

            if (RentMenuUI.Instance != null)
            {
                // Show rent payment UI — wait for player to click Pay
                RentMenuUI.Instance.OnRentPaid.RemoveAllListeners();
                RentMenuUI.Instance.OnRentPaid.AddListener((paidAmount) =>
                {
                    if (player.RemoveMoney(paidAmount))
                    {
                        owner.AddMoney(paidAmount);
                        Debug.Log($"💸 {player.playerName} paid {paidAmount} DT rent to {owner.playerName}");
                    }
                    else
                    {
                        Debug.LogWarning($"⚠️ {player.playerName} can't afford {paidAmount} DT rent!");
                    }
                    EndTurn();
                });

                RentMenuUI.Instance.ShowRentMenu(player, property, owner);
                return; // Wait for player to click Pay
            }
            else
            {
                // Fallback: silent pay if no UI
                if (player.RemoveMoney(rent))
                {
                    owner.AddMoney(rent);
                    Debug.Log($"💸 Paid {rent} DT rent to {owner.playerName}");
                }
            }
        }

        EndTurn();
    }

    private void OnPlayerLandedOnTile(PlayerData player, TileData tile)
    {
        if (player != null && tile != null)
        {
            Debug.Log($"📍 {player.playerName} → {tile.tileName}");
        }
    }

    private void HandlePassGO(PlayerData player)
    {
        if (player != null)
        {
            player.AddMoney(goBonus);
            Debug.Log($"💵 {player.playerName} passed GO! +${goBonus}");
        }
    }

    private void EndTurn()
    {
        if (currentPlayerIndex >= 0 && currentPlayerIndex < players.Length)
        {
            players[currentPlayerIndex].currentState = PlayerState.Idle;
        }

        Debug.Log($"\n✓ Turn ended\n");
        StartCoroutine(NextPlayerTurn());
    }

    private IEnumerator NextPlayerTurn()
    {
        yield return new WaitForSeconds(2f);
        currentPlayerIndex = (currentPlayerIndex + 1) % numberOfPlayers;
        StartTurn(currentPlayerIndex);
    }

    /// <summary>
    /// PUBLIC: Get all players (for PlayerMovement to check tile occupancy)
    /// </summary>
    public PlayerData[] GetAllPlayers()
    {
        return players;
    }

    public PlayerData GetCurrentPlayer()
    {
        if (players != null && currentPlayerIndex >= 0 && currentPlayerIndex < players.Length)
            return players[currentPlayerIndex];
        return null;
    }

    // ── DEBUG CHEATS ─────────────────────────────────────────────────────────

    private void Update()
    {
        if (!enableDebugCheats) return;
        if (players == null || currentGameState != GameState.Playing) return;
        if (currentPlayerIndex < 0 || currentPlayerIndex >= players.Length) return;

        if (Input.GetKeyDown(cheatKey_GiveMonopoly))  Cheat_GiveMonopoly();
        if (Input.GetKeyDown(cheatKey_OpenBuildMenu)) Cheat_OpenBuildingMenu();
        if (Input.GetKeyDown(cheatKey_GiveMoney))     Cheat_GiveMoney();
        if (Input.GetKeyDown(cheatKey_TestRent))      Cheat_TestRent();
        if (Input.GetKeyDown(cheatKey_BuyAll))        Cheat_BuyAllProperties();
        if (Input.GetKeyDown(cheatKey_TestTrain))     Cheat_TestTrain_Station();
    }

    /// <summary>
    /// F1 — Gives the current player the first fully-free color group found on the board.
    /// After pressing, press F2 to immediately open the building menu on the first owned property.
    /// </summary>
    private void Cheat_GiveMonopoly()
    {
        PlayerData player = players[currentPlayerIndex];

        foreach (PropertyColor color in System.Enum.GetValues(typeof(PropertyColor)))
        {
            if (color == PropertyColor.None) continue;

            List<TileData> group = boardManager.GetTilesByColor(color);
            if (group == null || group.Count == 0) continue;

            // Skip groups where another player already owns something
            bool blocked = false;
            foreach (TileData t in group)
            {
                if (t.ownerId >= 0 && t.ownerId != player.playerId)
                { blocked = true; break; }
            }
            if (blocked) continue;

            // Give every tile in the group to this player
            foreach (TileData t in group)
            {
                if (!player.ownedPropertyIndices.Contains(t.tileIndex))
                    player.AddProperty(t);
            }

            Debug.Log($"[CHEAT F1] {player.playerName} got MONOPOLY on {color}! Press F2 to open building menu.");
            return;
        }

        Debug.LogWarning("[CHEAT F1] No free color group found — all groups have mixed ownership.");
    }

    /// <summary>
    /// F2 — Teleports the current player to their first owned property
    /// and immediately opens the BuildingMenuUI so you can test buying houses.
    /// </summary>
    private void Cheat_OpenBuildingMenu()
    {
        PlayerData player = players[currentPlayerIndex];

        if (player.ownedProperties.Count == 0)
        {
            Debug.LogWarning("[CHEAT F2] Player owns no properties. Press F1 first to get a monopoly.");
            return;
        }

        // Stop any waiting dice roll
        waitingForDiceRoll = false;
        StopAllCoroutines();

        TileData target = player.ownedProperties[0];
        player.currentTileIndex = target.tileIndex;
        player.movementController?.TeleportToTile(target.tileIndex, boardManager.allTiles);

        Debug.Log($"[CHEAT F2] Teleported {player.playerName} to {target.tileName} — opening BuildingMenuUI");

        if (BuildingMenuUI.Instance != null)
        {
            BuildingMenuUI.Instance.OnMenuClosed.RemoveAllListeners();
            BuildingMenuUI.Instance.OnMenuClosed.AddListener(EndTurn);
            BuildingMenuUI.Instance.ShowBuildingMenu(player, target);
        }
        else
        {
            Debug.LogError("[CHEAT F2] BuildingMenuUI.Instance is null! Make sure the canvas has the BuildingMenuUI script.");
        }
    }

    /// <summary>
    /// F3 — Gives the current player 5000 DT so they can afford buildings.
    /// </summary>
    private void Cheat_GiveMoney()
    {
        PlayerData player = players[currentPlayerIndex];
        player.AddMoney(5000);
        Debug.Log($"[CHEAT F3] Gave {player.playerName} 5000 DT. New balance: {player.money} DT");
    }

    /// <summary>
    /// F4 — Gives ALL property tiles to Player 2, then teleports Player 1
    /// onto the first one so the RentMenuUI pops up immediately.
    /// </summary>
    private void Cheat_TestRent()
    {
        PlayerData player = players[currentPlayerIndex];
        int otherIndex = (currentPlayerIndex + 1) % numberOfPlayers;
    PlayerData otherPlayer = players[otherIndex];

        // Give every property tile to the other player
        int given = 0;
        TileData firstTile = null;
        foreach (TileData tile in boardManager.allTiles)
        {
     if (tile.tileType != TileType.Property) continue;

  // Skip tiles already owned by current player
            if (tile.ownerId == player.playerId) continue;

   // Assign to other player
      if (!otherPlayer.ownedPropertyIndices.Contains(tile.tileIndex))
            {
      otherPlayer.AddProperty(tile);
         given++;
  }

            if (firstTile == null) firstTile = tile;
   }

        if (firstTile == null)
  {
      Debug.LogWarning("[CHEAT F4] No property tiles found on the board.");
            return;
        }

    Debug.Log($"[CHEAT F4] Gave {given} properties to {otherPlayer.playerName}.");

     // Stop any active coroutines/dice
        waitingForDiceRoll = false;
   StopAllCoroutines();

        // Teleport current player onto the first property
  player.currentTileIndex = firstTile.tileIndex;
        player.movementController?.TeleportToTile(firstTile.tileIndex, boardManager.allTiles);

 Debug.Log($"[CHEAT F4] Teleporting {player.playerName} to '{firstTile.tileName}' — RentMenuUI should open.");

        HandleProperty(player, firstTile);
    }

    /// <summary>
    /// F5 — Gives the current player ALL unowned property tiles for free
    /// and fills their wallet so they can afford buildings immediately.
    /// Also callable from the in-game CheatMenuUI button.
    /// </summary>
    private void Cheat_BuyAllProperties()
    {
        if (players == null || currentPlayerIndex < 0 || currentPlayerIndex >= players.Length) return;

    PlayerData player = players[currentPlayerIndex];
  int bought = 0;

    foreach (TileData tile in boardManager.allTiles)
      {
         if (tile.tileType != TileType.Property) continue;
   if (tile.IsOwned()) continue;
            player.AddProperty(tile);
     bought++;
        }

    player.AddMoney(99999);
        Debug.Log($"[CHEAT F5] {player.playerName} bought all {bought} free properties and received 99999 DT.");
    }

    /// <summary>F6 — Teleport to Bizerte Station (tile 5) and open TrainMenuUI immediately.</summary>
    private void Cheat_TestTrain_Station()
    {
     PlayerData player = players[currentPlayerIndex];
        waitingForDiceRoll = false;
        StopAllCoroutines();

        int stationIndex = 5;
        player.currentTileIndex = stationIndex;
        player.movementController?.TeleportToTile(stationIndex, boardManager.allTiles);

        TileData station = boardManager.GetTile(stationIndex);
     if (station == null) { Debug.LogError("[CHEAT F6] Tile 5 not found."); return; }

        Debug.Log($"[CHEAT F6] {player.playerName} → {station.tileName} — TrainMenuUI opening");
        HandleRailroad(player, station);
    }
}