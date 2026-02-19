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
                {
                    Debug.LogWarning("⚠️ PropertyCardUI not set up - auto-passing");
                }
            }
        }
        else if (property.ownerId == player.playerId)
        {
            Debug.Log($"🏠 You own {property.tileName}! ({PropertyManager.Instance?.GetBuildingStatus(property)})");
        }
        else if (property.ownerId >= 0 && property.ownerId < players.Length)
        {
            int rent = property.GetCurrentRent();
            if (player.RemoveMoney(rent))
            {
                players[property.ownerId].AddMoney(rent);
                Debug.Log($"💸 Paid {rent} DT rent to {players[property.ownerId].playerName}");
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
}