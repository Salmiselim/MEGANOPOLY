using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;
using Unity.Netcode;
using Unity.Services.Authentication;
using UnityEngine.InputSystem;

public class CompleteGameManager : NetworkBehaviour
{
    public static CompleteGameManager Instance { get; private set; }

    [Header("Game Settings")]
    [SerializeField] public int numberOfPlayers = 4;
    [SerializeField] private int startingMoney = 1500;
    [SerializeField] private int goBonus = 200;

    [Header("References")]
    [SerializeField] private BoardManager boardManager;
    [SerializeField] private GameObject playerPrefab;
    [SerializeField] private SimpleDiceController[] dice = new SimpleDiceController[2];
    [SerializeField] private DiceControllerV2[] diceV2 = new DiceControllerV2[2];

    [Header("Spawn Points")]
    [SerializeField] private bool useManualSpawnPoints = true;
    [SerializeField] private PlayerSpawnPoint[] manualSpawnPoints = new PlayerSpawnPoint[4];

    [Header("Fallback Spawn")]
    [SerializeField] private float playerSpacing = 10f;
    [SerializeField] private Vector3 manualSpawnOffset = Vector3.zero;

    [Header("Player Setup")]
    [SerializeField] private Color[] playerColors = { Color.red, Color.blue, Color.green, Color.yellow };
    [SerializeField] private string[] playerNames = { "Player 1", "Player 2", "Player 3", "Player 4" };

    [Header("DEBUG")]
    [SerializeField] private bool enableDebugCheats = true;
    [SerializeField] private Key cheatKey_GiveMonopoly = Key.F1;
    [SerializeField] private Key cheatKey_OpenBuildMenu = Key.F2;
    [SerializeField] private Key cheatKey_GiveMoney = Key.F3;
    [SerializeField] private Key cheatKey_TestRent = Key.F4;
    [SerializeField] private Key cheatKey_BuyAll = Key.F5;
    [SerializeField] private Key cheatKey_TestTrain = Key.F6;
    [SerializeField] private Key cheatKey_TestMinigame = Key.F7;
    [SerializeField] private Key cheatKey_TestMinigameRent = Key.F8;

    // ── Auth maps ─────────────────────────────────────────────────────────────
    private Dictionary<ulong, string> clientAuthNames = new Dictionary<ulong, string>();
    private Dictionary<ulong, string> clientUnityPlayerIds = new Dictionary<ulong, string>();

    // ── Runtime state ─────────────────────────────────────────────────────────
    private GameState currentGameState = GameState.Setup;
    private PlayerData[] players;
    private int currentPlayerIndex = 0;
    private bool waitingForDiceRoll = false;
    private bool isGamePaused = false;

    private bool dice1HasResult; private int dice1Result;
    private bool dice2HasResult; private int dice2Result;

    public UnityEvent OnGameStarted = new UnityEvent();
    public UnityEvent<int> OnTurnChanged = new UnityEvent<int>();

    private MinigameOrchestrator minigameOrchestrator;

    // ── Minigame session context ──────────────────────────────────────────────
    private int minigameChallengerIndex = -1;
    private int minigameTileIndex = -1;
    private bool minigameIsRentContext = false;

    [Header("Minigame Rewards")]
    [Tooltip("Money awarded to the winner when they are NOT the player who triggered the mini-game.")]
    [SerializeField] private int nonChallengerReward = 150;

    // ── Awake ─────────────────────────────────────────────────────────────────

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else { Destroy(gameObject); return; }

        if (boardManager == null) boardManager = FindObjectOfType<BoardManager>();

        minigameOrchestrator = FindObjectOfType<MinigameOrchestrator>();
        if (minigameOrchestrator != null)
            minigameOrchestrator.OnMinigameEnded.AddListener(OnMinigameEnded);

        AutoFindDice();
        AutoFindSpawnPoints();
        // Connect dice events immediately so they work even without a network game start.
        // SetupDiceEvents uses RemoveListener+AddListener so calling it again in
        // ServerInitGame (for late-found dice) never duplicates the subscriptions.
        SetupDiceEvents();
    }

    // ── NGO entry point ───────────────────────────────────────────────────────

    public override void OnNetworkSpawn()
    {
        if (IsServer)
        {
            NetworkManager.Singleton.OnClientConnectedCallback += OnClientConnected;
            NetworkManager.Singleton.OnClientDisconnectCallback += OnClientDisconnected;
            return;
        }

        // Client: auth guard
        if (AuthManager.Instance == null || !AuthManager.Instance.IsSignedIn)
        {
            Debug.LogError("[Client] Not authenticated! Redirecting to Auth scene.");
            UnityEngine.SceneManagement.SceneManager.LoadScene("AuthScene");
            return;
        }

        string username = AuthManager.Instance.PlayerName ?? $"Player_{NetworkManager.Singleton.LocalClientId}";
        string playerId = AuthManager.Instance.PlayerId;

        RegisterAuthNameServerRpc(username, playerId, NetworkManager.Singleton.LocalClientId);
        Debug.Log($"[Client] Auth guard passed. Registered as '{username}' (PlayerId: {playerId})");
    }

    // ── Auth registration ─────────────────────────────────────────────────────

    [ServerRpc(RequireOwnership = false)]
    public void RegisterAuthNameServerRpc(string username, string unityPlayerId, ulong clientId,
        ServerRpcParams rpcParams = default)
    {
        clientAuthNames[clientId] = username;
        clientUnityPlayerIds[clientId] = unityPlayerId;
        Debug.Log($"[Server] Client {clientId} registered → '{username}' | id='{unityPlayerId}'");
    }

    // ── Connect / disconnect ──────────────────────────────────────────────────

    private void OnClientConnected(ulong clientId)
        => Debug.Log($"[Server] Client {clientId} connected. Total: {NetworkManager.Singleton.ConnectedClientsList.Count}");

    private void OnClientDisconnected(ulong clientId)
    {
        Debug.LogWarning($"[Server] Client {clientId} disconnected.");
        clientAuthNames.Remove(clientId);
        clientUnityPlayerIds.Remove(clientId);
    }

    // ── Called by NetworkBootstrapper ─────────────────────────────────────────

    public void ForceStartWithCurrentPlayers()
    {
        if (!IsServer) return;
        if (currentGameState != GameState.Setup) return;

        int connected = NetworkManager.Singleton.ConnectedClientsList.Count;
        if (connected == 0) { Debug.LogError("[GameManager] ForceStart: 0 players connected!"); return; }

        numberOfPlayers = connected;
        Debug.Log($"[GameManager] Force-starting with {numberOfPlayers} player(s).");
        StartCoroutine(ServerInitGame());
    }

    // ── Server: spawn all players ─────────────────────────────────────────────

    private IEnumerator ServerInitGame()
    {
        currentGameState = GameState.Setup;
        players = new PlayerData[numberOfPlayers];

        var clients = new List<ulong>(NetworkManager.Singleton.ConnectedClientsIds);

        for (int i = 0; i < numberOfPlayers; i++)
        {
            ulong ownerClientId = (i < clients.Count) ? clients[i] : NetworkManager.ServerClientId;
            string authName = clientAuthNames.TryGetValue(ownerClientId, out string n)
                                        ? n : (i < playerNames.Length ? playerNames[i] : $"Player {i + 1}");
            string unityPlayerId = clientUnityPlayerIds.TryGetValue(ownerClientId, out string pid)
                                        ? pid : ownerClientId.ToString();

            players[i] = new PlayerData(i, authName, playerColors[i]);
            players[i].money = startingMoney;
            players[i].unityPlayerId = unityPlayerId;

            Debug.Log($"[Server] Spawning Player {i} → '{authName}' | id='{unityPlayerId}' | client={ownerClientId}");

            Vector3 spawnPos = GetSpawnPosition(i);
            GameObject avatarObj = Instantiate(playerPrefab, spawnPos, Quaternion.identity);
            avatarObj.name = $"Player_{i}_{authName}";

            NetworkObject netObj = avatarObj.GetComponent<NetworkObject>();
            if (netObj == null)
            {
                Debug.LogError("[Server] Player prefab missing NetworkObject!");
                Destroy(avatarObj);
                continue;
            }

            netObj.SpawnWithOwnership(ownerClientId, true);
            ApplyPlayerColor(avatarObj, playerColors[i]);
            SetupPlayerAvatar(i, avatarObj);
        }

        yield return new WaitForSeconds(0.5f);
        SetupDiceEvents();
        StartGame();
    }

    // ── Avatar helpers ────────────────────────────────────────────────────────

    private void ApplyPlayerColor(GameObject avatarObj, Color color)
    {
        Renderer rend = avatarObj.GetComponentInChildren<Renderer>();
        if (rend != null)
        {
            Material mat = new Material(rend.sharedMaterial);
            mat.color = color;
            rend.material = mat;
        }
    }

    private void SetupPlayerAvatar(int index, GameObject avatarObj)
    {
        players[index].playerAvatar = avatarObj;
        players[index].avatarTransform = avatarObj.transform;

        PlayerMovement movement = avatarObj.GetComponent<PlayerMovement>();
        if (movement == null) movement = avatarObj.AddComponent<PlayerMovement>();

        movement.Initialize(players[index]);
        players[index].movementController = movement;

        int playerIndex = index;
        movement.OnTileLanded.AddListener((tile) =>
        {
            if (playerIndex >= 0 && playerIndex < players.Length && players[playerIndex] != null)
                OnPlayerLandedOnTile(players[playerIndex], tile);
        });
        movement.OnPassedGO.AddListener(() =>
        {
            if (playerIndex >= 0 && playerIndex < players.Length && players[playerIndex] != null)
                HandlePassGO(players[playerIndex]);
        });
    }

    private Vector3 GetSpawnPosition(int playerIndex)
    {
        if (useManualSpawnPoints && manualSpawnPoints != null &&
            playerIndex < manualSpawnPoints.Length && manualSpawnPoints[playerIndex] != null)
            return manualSpawnPoints[playerIndex].transform.position;

        TileData goTile = boardManager.GetTile(0);
        if (goTile == null) { Debug.LogError("GO tile not found!"); return Vector3.zero; }
        return goTile.worldPosition + manualSpawnOffset + Vector3.right * (playerIndex * playerSpacing);
    }

    // ── Dice ──────────────────────────────────────────────────────────────────

    private void AutoFindDice()
    {
        bool haveSimple = (dice != null && dice.Length >= 2 && dice[0] != null && dice[1] != null);
        bool haveV2 = (diceV2 != null && diceV2.Length >= 2 && diceV2[0] != null && diceV2[1] != null);
        if (haveSimple || haveV2) return;

        SimpleDiceController[] found = FindObjectsOfType<SimpleDiceController>();
        if (found.Length >= 2)
        {
            System.Array.Sort(found, (a, b) => a.diceNumber.CompareTo(b.diceNumber));
            dice = new SimpleDiceController[2] { found[0], found[1] };
            Debug.Log($"Auto-found {found.Length} SimpleDiceController dice");
            return;
        }

        DiceControllerV2[] foundV2 = FindObjectsOfType<DiceControllerV2>();
        if (foundV2.Length >= 2)
        {
            System.Array.Sort(foundV2, (a, b) => a.DiceNumber.CompareTo(b.DiceNumber));
            diceV2 = new DiceControllerV2[2] { foundV2[0], foundV2[1] };
            Debug.Log($"Auto-found {foundV2.Length} DiceControllerV2 dice");
            return;
        }

        Debug.LogWarning($"Only found {found.Length} SimpleDice and {foundV2.Length} V2 dice, need 2");
    }

    private void AutoFindSpawnPoints()
    {
        if (!useManualSpawnPoints) return;
        if (manualSpawnPoints != null && manualSpawnPoints.Length >= numberOfPlayers &&
            manualSpawnPoints[0] != null) return;

        PlayerSpawnPoint[] found = FindObjectsOfType<PlayerSpawnPoint>();
        if (found.Length >= numberOfPlayers)
        {
            System.Array.Sort(found, (a, b) => a.playerIndex.CompareTo(b.playerIndex));
            manualSpawnPoints = new PlayerSpawnPoint[numberOfPlayers];
            for (int i = 0; i < numberOfPlayers; i++) manualSpawnPoints[i] = found[i];
            Debug.Log($"Auto-found {found.Length} spawn points");
        }
        else
        {
            Debug.LogWarning($"Only {found.Length} spawn points, using procedural");
            useManualSpawnPoints = false;
        }
    }

    private void SetupDiceEvents()
    {
        // Always remove before adding so calling this multiple times never duplicates listeners.
        if (dice != null)
        {
            if (dice.Length > 0 && dice[0] != null)
            {
                dice[0].OnDiceRolled.RemoveListener(OnDice1Rolled);
                dice[0].OnDiceRolled.AddListener(OnDice1Rolled);
                Debug.Log("SimpleDice 1 connected");
            }
            if (dice.Length > 1 && dice[1] != null)
            {
                dice[1].OnDiceRolled.RemoveListener(OnDice2Rolled);
                dice[1].OnDiceRolled.AddListener(OnDice2Rolled);
                Debug.Log("SimpleDice 2 connected");
            }
        }

        if (diceV2 != null)
        {
            if (diceV2.Length > 0 && diceV2[0] != null)
            {
                diceV2[0].OnDiceRolled.RemoveListener(OnDice1Rolled);
                diceV2[0].OnDiceRolled.AddListener(OnDice1Rolled);
                Debug.Log("V2 Dice 1 connected");
            }
            if (diceV2.Length > 1 && diceV2[1] != null)
            {
                diceV2[1].OnDiceRolled.RemoveListener(OnDice2Rolled);
                diceV2[1].OnDiceRolled.AddListener(OnDice2Rolled);
                Debug.Log("V2 Dice 2 connected");
            }
        }
    }

    // ── Game flow ─────────────────────────────────────────────────────────────

    private void StartGame()
    {
        currentGameState = GameState.Playing;
        Debug.Log("\n═══════════════════════════════════\n       GAME STARTED!\n═══════════════════════════════════\n");
        OnGameStarted?.Invoke();
        StartTurn(0);
    }

    private void StartTurn(int playerIndex)
    {
        currentPlayerIndex = playerIndex;
        if (currentPlayerIndex < 0 || currentPlayerIndex >= players.Length)
        {
            Debug.LogError($"Invalid player index: {currentPlayerIndex}");
            return;
        }

        PlayerData p = players[currentPlayerIndex];
        p.currentState = PlayerState.WaitingToRoll;

        Debug.Log($"\n── {p.playerName}'s TURN  {p.money} DT  {boardManager.GetTile(p.currentTileIndex)?.tileName ?? "?"} ──");

        OnTurnChanged?.Invoke(currentPlayerIndex);
        if (IsSpawned) NotifyTurnClientRpc(currentPlayerIndex);

        if (p.isInJail) { HandleJailTurn(p); return; }
        EnableDiceForPlayer();
    }

    [ClientRpc]
    private void NotifyTurnClientRpc(int playerIdx)
    {
        Debug.Log($"[Client] Player {playerIdx}'s turn.");
        OnTurnChanged?.Invoke(playerIdx);
    }

    private void HandleJailTurn(PlayerData player)
    {
        if (player.jailTurnsRemaining > 0)
        {
            player.jailTurnsRemaining--;
            Debug.Log($"{player.playerName} in Jail. {player.jailTurnsRemaining} turn(s) left.");
            EndTurn();
            return;
        }
        player.ReleaseFromJail();
        Debug.Log($"{player.playerName} released from Jail!");
        EnableDiceForPlayer();
    }

    private void EnableDiceForPlayer()
    {
        waitingForDiceRoll = true;
        dice1HasResult = false; dice1Result = 0;
        dice2HasResult = false; dice2Result = 0;
        if (dice != null)
        {
            if (dice.Length > 0 && dice[0] != null) dice[0].ResetDice();
            if (dice.Length > 1 && dice[1] != null) dice[1].ResetDice();
        }
        if (diceV2 != null)
        {
            if (diceV2.Length > 0 && diceV2[0] != null) diceV2[0].ResetDice();
            if (diceV2.Length > 1 && diceV2[1] != null) diceV2[1].ResetDice();
        }
        Debug.Log($"[Server] Dice ready for Player {currentPlayerIndex} ({players[currentPlayerIndex]?.playerName})");
    }

    public void RequestRoll()
    {
        if (IsServer) DoRoll();
        else RequestRollServerRpc();
    }

    [ServerRpc(RequireOwnership = false)]
    private void RequestRollServerRpc() => DoRoll();

    private void DoRoll()
    {
        if (!waitingForDiceRoll) { Debug.LogWarning("[Server] Roll requested but not waiting — ignored."); return; }
        Debug.Log("[Server] Rolling dice...");
        if (dice != null)
        {
            if (dice.Length > 0 && dice[0] != null) dice[0].RollDice();
            if (dice.Length > 1 && dice[1] != null) dice[1].RollDice();
        }
        if (diceV2 != null)
        {
            if (diceV2.Length > 0 && diceV2[0] != null) diceV2[0].SimulateThrow();
            if (diceV2.Length > 1 && diceV2[1] != null) diceV2[1].SimulateThrow();
        }
    }

    private void OnDice1Rolled(int value)
    {
        if (!waitingForDiceRoll) return;
        dice1Result = value; dice1HasResult = true;
        Debug.Log($"Die 1: {value}");
        CheckBothDice();
    }

    private void OnDice2Rolled(int value)
    {
        if (!waitingForDiceRoll) return;
        dice2Result = value; dice2HasResult = true;
        Debug.Log($"Die 2: {value}");
        CheckBothDice();
    }

    private void CheckBothDice()
    {
        if (!dice1HasResult || !dice2HasResult) return;
        waitingForDiceRoll = false;
        int total = dice1Result + dice2Result;
        Debug.Log($"\n{dice1Result} + {dice2Result} = {total}\n");
        StartCoroutine(HandlePlayerMove(total));
    }

    private IEnumerator HandlePlayerMove(int spaces)
    {
        if (currentPlayerIndex < 0 || currentPlayerIndex >= players.Length)
        {
            Debug.LogError($"Invalid player index during move: {currentPlayerIndex}");
            yield break;
        }

        PlayerData p = players[currentPlayerIndex];
        p.currentState = PlayerState.Rolling;
        yield return new WaitForSeconds(0.5f);

        if (p.movementController == null)
        {
            Debug.LogError("No movement controller!");
            EndTurn();
            yield break;
        }

        p.movementController.MoveByDiceRoll(spaces, boardManager.allTiles);

        float timeout = 20f, elapsed = 0f;
        while (p.movementController.IsMoving() && elapsed < timeout)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        if (elapsed >= timeout) Debug.LogError("Movement timeout!");
        yield return new WaitForSeconds(0.5f);
        HandleTileLanding(p);
    }

    private void HandleTileLanding(PlayerData player)
    {
        if (player.currentTileIndex < 0 || player.currentTileIndex >= 40)
        {
            Debug.LogError($"Invalid tile index: {player.currentTileIndex}");
            EndTurn();
            return;
        }

        TileData tile = boardManager.GetTile(player.currentTileIndex);
        if (tile == null)
        {
            Debug.LogError($"Tile {player.currentTileIndex} is null!");
            EndTurn();
            return;
        }

        Debug.Log($"\nLanded on: {tile.tileName} ({tile.tileType})");
        player.currentState = PlayerState.OnTile;

        switch (tile.tileType)
        {
            case TileType.Property: HandleProperty(player, tile); break;
            case TileType.Railroad: HandleRailroad(player, tile); break;
            case TileType.Tax:
                player.RemoveMoney(tile.baseRent);
                Debug.Log($"Paid {tile.baseRent} DT tax");
                EndTurn();
                break;
            case TileType.GoToJail:
                player.SendToJail();
                player.movementController?.TeleportToTile(10, boardManager.allTiles);
                Debug.Log($"{player.playerName} sent to Jail.");
                EndTurn();
                break;
            default:
                EndTurn();
                break;
        }
    }

    // ── Railroad ──────────────────────────────────────────────────────────────

    private static readonly Dictionary<int, int> s_TrainRoutes = new Dictionary<int, int>
    { { 5, 25 }, { 25, 5 }, { 15, 35 }, { 35, 15 } };

    private static int GetTrainDestination(int from) =>
        s_TrainRoutes.TryGetValue(from, out int d) ? d : -1;

    private static int CalculateTrainFare(TileData station, PlayerData rider, PlayerData[] allPlayers)
    {
        if (!station.IsOwned()) return 50;
        if (station.ownerId == rider.playerId) return 0;
        PlayerData owner = null;
        foreach (var p in allPlayers)
            if (p != null && p.playerId == station.ownerId) { owner = p; break; }
        if (owner == null) return 50;
        int cnt = 0;
        foreach (var t in owner.ownedProperties)
            if (t.tileType == TileType.Railroad) cnt++;
        return new[] { 0, 25, 50, 100, 200 }[Mathf.Clamp(cnt, 0, 4)];
    }

    private void HandleRailroad(PlayerData player, TileData station)
    {
        int destIndex = GetTrainDestination(station.tileIndex);
        if (destIndex < 0) { EndTurn(); return; }

        TileData destTile = boardManager.GetTile(destIndex);
        if (destTile == null) { EndTurn(); return; }

        if (!station.IsOwned())
        {
            TileMarker marker = boardManager.GetTileMarker(station.tileIndex);
            if (PropertyCardUI.Instance != null && marker?.propertyCard != null)
            {
                TileData dest = destTile;
                PropertyCardUI.Instance.ShowPropertyCard(player, station, marker);
                StartCoroutine(WaitForPropertyCardThenShowTrain(player, station, dest));
                return;
            }
        }

        ShowTrainChoice(player, station, destTile);
    }

    private IEnumerator WaitForPropertyCardThenShowTrain(PlayerData player, TileData station, TileData dest)
    {
        float timeout = 60f, elapsed = 0f;
        while (PropertyCardUI.Instance != null && PropertyCardUI.Instance.IsShowing() && elapsed < timeout)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }
        ShowTrainChoice(player, station, dest);
    }

    private void ShowTrainChoice(PlayerData player, TileData station, TileData destTile)
    {
        if (TrainMenuUI.Instance == null) { EndTurn(); return; }
        int fare = CalculateTrainFare(station, player, players);
        TrainMenuUI.Instance.ShowTrainMenu(player, station, destTile, fare);
    }

    // ── Property ──────────────────────────────────────────────────────────────

    private void HandleProperty(PlayerData player, TileData property)
    {
        // ── Unowned: launch minigame immediately.
        // All players are sent to the minigame scene; the winner claims the property.
        if (!property.IsOwned())
        {
            int minigameType = GetMinigameTypeForProperty(property);
            int prize        = Mathf.Max(100, property.purchasePrice / 2);

            Debug.Log($"[GameManager] '{property.tileName}' is unowned → launching minigame type={minigameType} prize={prize}");
            TriggerMinigameChallenge(player, property, minigameType, prize);
            return;
        }

        // ── Owned by this player: show building menu
        if (property.ownerId == player.playerId)
        {
            if (BuildingMenuUI.Instance != null)
            {
                BuildingMenuUI.Instance.ShowBuildingMenu(player, property);
                return;
            }
        }
        // ── Owned by another player: show rent menu
        else if (property.ownerId >= 0 && property.ownerId < players.Length)
        {
            PlayerData owner = players[property.ownerId];
            if (RentMenuUI.Instance != null)
            {
                RentMenuUI.Instance.ShowRentMenu(player, property, owner);
                return;
            }

            // Fallback: no UI
            int rent = property.GetCurrentRent();
            if (player.RemoveMoney(rent))
            {
                owner.AddMoney(rent);
                Debug.Log($"Paid {rent} DT rent (no UI fallback)");
            }
        }

        EndTurn();
    }

    // ── Minigame: triggered ONLY by button click from PropertyCardUI ──────────

    /// <summary>Maps a property's color to a minigame type index.</summary>
    private static int GetMinigameTypeForProperty(TileData property) =>
        property.propertyColor switch
        {
            PropertyColor.Brown     => 0,
            PropertyColor.LightBlue => 1,
            PropertyColor.Pink      => 2,
            PropertyColor.Orange    => 3,
            PropertyColor.Red       => 4,
            PropertyColor.Yellow    => 5,
            PropertyColor.Green     => 6,
            PropertyColor.DarkBlue  => 7,
            _                       => 0
        };

    /// <summary>
    /// Called by PropertyCardUI's "Play Minigame" button via ServerRpc.
    /// Only the server executes the actual minigame launch.
    /// </summary>
    public void RequestMinigameFromUI(int playerIndex, int tileIndex)
    {
        if (!IsServer) return;

        PlayerData player = GetServerPlayer(playerIndex);
        TileData property = boardManager?.GetTile(tileIndex);

        if (player == null || property == null)
        {
            Debug.LogError($"[GameManager] RequestMinigameFromUI: invalid player {playerIndex} or tile {tileIndex}");
            EndTurn();
            return;
        }

        int minigameType = GetMinigameTypeForProperty(property);

        int prize = Mathf.Max(100, property.purchasePrice / 2);

        Debug.Log($"[GameManager] Minigame requested by player {playerIndex} on tile {tileIndex} — type {minigameType}, prize {prize}");
        TriggerMinigameChallenge(player, property, minigameType, prize);
    }

    /// <summary>
    /// ServerRpc wrapper so clients can request a minigame via the button.
    /// </summary>
    [ServerRpc(RequireOwnership = false)]
    public void RequestMinigameServerRpc(int playerIndex, int tileIndex)
    {
        RequestMinigameFromUI(playerIndex, tileIndex);
    }

    // ── UI Callbacks (called by each UI's ServerRpc) ──────────────────────────

    /// <summary>Called by RentMenuUI after rent is paid or declined.</summary>
    public void OnRentMenuClosed()
    {
        if (!IsServer) return;
        EndTurn();
    }

    /// <summary>
    /// Called by PropertyCardUI after buy, pass, or minigame button.
    /// If the player chose to play a minigame, bought=false and
    /// RequestMinigameServerRpc will have already been called by the UI —
    /// so we only end the turn here when NOT launching a minigame.
    /// </summary>
    public void OnPropertyCardClosed(int playerIndex, int tileIndex, bool bought, bool launchedMinigame = false)
    {
        if (!IsServer) return;
        Debug.Log($"[Server] PropertyCard closed: player={playerIndex} tile={tileIndex} bought={bought} minigame={launchedMinigame}");

        // If a minigame was launched the turn ends via OnMinigameEnded, not here
        if (!launchedMinigame)
            EndTurn();
    }

    /// <summary>Called by BuildingMenuUI after the player closes the build menu.</summary>
    public void OnBuildingMenuClosed()
    {
        if (!IsServer) return;
        EndTurn();
    }

    /// <summary>Called by TrainMenuUI after the player's take/pass decision.</summary>
    public void OnTrainMenuClosed(int playerIndex, int fromTile, int toTile, bool tookTrain, int fare)
    {
        if (!IsServer) return;
        Debug.Log($"[Server] Train closed: player={playerIndex} tookTrain={tookTrain} fare={fare}");
        EndTurn();
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private void OnPlayerLandedOnTile(PlayerData player, TileData tile)
    {
        if (player != null && tile != null)
            Debug.Log($"{player.playerName} → {tile.tileName}");
    }

    private void HandlePassGO(PlayerData player)
    {
        if (player == null) return;
        player.AddMoney(goBonus);
        Debug.Log($"{player.playerName} passed GO! +{goBonus} DT");
    }

    private void EndTurn()
    {
        if (currentPlayerIndex >= 0 && currentPlayerIndex < players.Length)
        {
            PlayerData p = players[currentPlayerIndex];
            p.currentState = PlayerState.Idle;
            _ = CloudSaveManager.Instance?.SaveProfileOnlyAsync(p);
        }

        Debug.Log("Turn ended\n");
        StartCoroutine(NextPlayerTurn());
    }

    private IEnumerator NextPlayerTurn()
    {
        yield return new WaitForSeconds(2f);
        currentPlayerIndex = (currentPlayerIndex + 1) % numberOfPlayers;
        StartTurn(currentPlayerIndex);
    }

    // ── Public API ────────────────────────────────────────────────────────────

    public PlayerData[] GetAllPlayers() => players;

    public PlayerData GetCurrentPlayer() =>
        (players != null && currentPlayerIndex >= 0 && currentPlayerIndex < players.Length)
        ? players[currentPlayerIndex] : null;

    public PlayerData GetPlayerByUnityId(string unityPlayerId)
    {
        if (players == null) return null;
        foreach (var p in players)
            if (p != null && p.unityPlayerId == unityPlayerId) return p;
        return null;
    }

    public PlayerData GetServerPlayer(int index)
    {
        if (players == null || index < 0 || index >= players.Length) return null;
        return players[index];
    }

    public void PauseGame() { isGamePaused = true; Time.timeScale = 0f; }
    public void ResumeGame() { isGamePaused = false; Time.timeScale = 1f; }

    // ── Minigame ──────────────────────────────────────────────────────────────

    /// <param name="isRentContext">
    /// True when triggered from a rent payment situation (challenger winning = free rent).
    /// False when triggered from a property buy situation (challenger winning = free property).
    /// </param>
    public void TriggerMinigameChallenge(PlayerData player, TileData property,
        int minigameType = 0, int prizeAmount = 200, bool isRentContext = false)
    {
        if (minigameOrchestrator == null)
        {
            Debug.LogError("[GameManager] MinigameOrchestrator not found!");
            EndTurn();
            return;
        }

        minigameChallengerIndex = player.playerId;
        minigameTileIndex = property.tileIndex;
        minigameIsRentContext = isRentContext;

        // Build clientId → player index map so the minigame scene can resolve the winner.
        // ConnectedClientsIds order matches the order players[] was created in ServerInitGame.
        if (NetworkManager.Singleton != null)
        {
            var clientIds = new List<ulong>(NetworkManager.Singleton.ConnectedClientsIds);
            var map = new Dictionary<ulong, int>();
            for (int i = 0; i < Mathf.Min(clientIds.Count, players.Length); i++)
                map[clientIds[i]] = i;
            minigameOrchestrator.RegisterClientPlayerMap(map);
        }

        minigameOrchestrator.StartMinigame(minigameType, property.tileName, player, prizeAmount, player.playerId);
    }

    private void OnMinigameEnded(int winnerId, int prizeAmount)
    {
        bool challengerWon = winnerId >= 0 && winnerId == minigameChallengerIndex;

        if (winnerId >= 0 && winnerId < players.Length)
        {
            if (challengerWon)
            {
                if (!minigameIsRentContext)
                {
                    // Buy context: challenger wins the property for free
                    TileData tile = boardManager?.GetTile(minigameTileIndex);
                    if (tile != null && !tile.IsOwned())
                    {
                        players[winnerId].AddProperty(tile);
                        Debug.Log($"[GameManager] {players[winnerId].playerName} won the minigame — {tile.tileName} granted for free!");
                        _ = CloudSaveManager.Instance?.SaveProfileOnlyAsync(players[winnerId]);
                    }
                }
                else
                {
                    // Rent context: challenger wins → rent is waived, no payment needed
                    Debug.Log($"[GameManager] {players[winnerId].playerName} won the minigame — rent is waived!");
                }
            }
            else
            {
                // A non-challenger won → small reward
                players[winnerId].AddMoney(nonChallengerReward);
                Debug.Log($"[GameManager] {players[winnerId].playerName} won the minigame and earns {nonChallengerReward} DT reward!");
                _ = CloudSaveManager.Instance?.SaveProfileOnlyAsync(players[winnerId]);
            }
        }
        else
        {
            Debug.Log("[GameManager] Minigame ended with no winner — no reward distributed.");
        }

        minigameChallengerIndex = -1;
        minigameTileIndex = -1;
        minigameIsRentContext = false;
        EndTurn();
    }

    // ── Debug cheats ──────────────────────────────────────────────────────────

    private void Update()
    {
        if (!enableDebugCheats) return;

        // Allow cheats on the server, OR when no network session is active (editor / solo test).
        bool networkActive = NetworkManager.Singleton != null && NetworkManager.Singleton.IsListening;
        if (networkActive && !IsServer) return;

        // Space: roll dice. Works even before a network game is formally started so
        // you can test dice physics and result flow in isolation in the editor.
        if (IsKeyDown(Key.Space))
        {
            Cheat_ForceRollDice();
            return;
        }

        // All other cheat keys require an active game with valid player state.
        if (players == null || currentGameState != GameState.Playing) return;
        if (currentPlayerIndex < 0 || currentPlayerIndex >= players.Length) return;

        if (IsKeyDown(cheatKey_GiveMonopoly)) Cheat_GiveMonopoly();
        if (IsKeyDown(cheatKey_OpenBuildMenu)) Cheat_OpenBuildingMenu();
        if (IsKeyDown(cheatKey_GiveMoney)) Cheat_GiveMoney();
        if (IsKeyDown(cheatKey_TestRent)) Cheat_TestRent();
        if (IsKeyDown(cheatKey_BuyAll)) Cheat_BuyAllProperties();
        if (IsKeyDown(cheatKey_TestTrain)) Cheat_TestTrain_Station();
        if (IsKeyDown(cheatKey_TestMinigame)) Cheat_TestMinigame();
        if (IsKeyDown(cheatKey_TestMinigameRent)) Cheat_TestMinigameRent();
    }

    private static bool IsKeyDown(Key key)
    {
        return Keyboard.current != null && Keyboard.current[key].wasPressedThisFrame;
    }

    /// <summary>
    /// Space bar cheat: resets and rolls both dice. Sets up the minimum game state needed
    /// for the result to be processed, so this works correctly both mid-game and in a
    /// fresh editor session without a network connection.
    /// </summary>
    private void Cheat_ForceRollDice()
    {
        // Bootstrap minimal player state when rolling before a game has been started,
        // so HandlePlayerMove doesn't crash on null players / null movementController.
        if (players == null || players.Length == 0)
        {
            players = new PlayerData[1]
            {
                new(0, "TestPlayer", playerColors[0]) { money = startingMoney }
            };
            currentPlayerIndex = 0;
            currentGameState = GameState.Playing;
            Debug.Log("[CHEAT Space] Bootstrapped test player for dice roll.");
        }

        // Make sure events are wired (dice might have been found after Awake).
        SetupDiceEvents();

        waitingForDiceRoll = true;
        dice1HasResult = false; dice1Result = 0;
        dice2HasResult = false; dice2Result = 0;

        // Reset both dice (clears isRolling and hasResult so result detection works again)
        // then throw them.
        if (dice != null)
        {
            if (dice.Length > 0 && dice[0] != null) { dice[0].ResetDice(); dice[0].RollDice(); }
            if (dice.Length > 1 && dice[1] != null) { dice[1].ResetDice(); dice[1].RollDice(); }
        }
        if (diceV2 != null)
        {
            if (diceV2.Length > 0 && diceV2[0] != null) { diceV2[0].ResetDice(); diceV2[0].SimulateThrow(); }
            if (diceV2.Length > 1 && diceV2[1] != null) { diceV2[1].ResetDice(); diceV2[1].SimulateThrow(); }
        }

        Debug.Log("[CHEAT Space] Dice force-rolled.");
    }

    private void Cheat_GiveMonopoly()
    {
        PlayerData player = players[currentPlayerIndex];
        foreach (PropertyColor color in System.Enum.GetValues(typeof(PropertyColor)))
        {
            if (color == PropertyColor.None) continue;
            List<TileData> group = boardManager.GetTilesByColor(color);
            if (group == null || group.Count == 0) continue;
            bool blocked = false;
            foreach (var t in group)
                if (t.ownerId >= 0 && t.ownerId != player.playerId) { blocked = true; break; }
            if (blocked) continue;
            foreach (var t in group)
                if (!player.ownedPropertyIndices.Contains(t.tileIndex)) player.AddProperty(t);
            Debug.Log($"[CHEAT F1] {player.playerName} got MONOPOLY on {color}!");
            return;
        }
        Debug.LogWarning("[CHEAT F1] No free color group found.");
    }

    private void Cheat_OpenBuildingMenu()
    {
        PlayerData player = players[currentPlayerIndex];
        if (player.ownedProperties.Count == 0)
        {
            Debug.LogWarning("[CHEAT F2] No properties — press F1 first.");
            return;
        }
        waitingForDiceRoll = false;
        StopAllCoroutines();
        TileData target = player.ownedProperties[0];
        player.currentTileIndex = target.tileIndex;
        player.movementController?.TeleportToTile(target.tileIndex, boardManager.allTiles);
        if (BuildingMenuUI.Instance != null)
            BuildingMenuUI.Instance.ShowBuildingMenu(player, target);
        else
            Debug.LogError("[CHEAT F2] BuildingMenuUI.Instance is null!");
    }

    private void Cheat_GiveMoney()
    {
        players[currentPlayerIndex].AddMoney(5000);
        Debug.Log("[CHEAT F3] +5000 DT");
    }

    private void Cheat_TestRent()
    {
        PlayerData player = players[currentPlayerIndex];
        int otherIdx = (currentPlayerIndex + 1) % numberOfPlayers;
        PlayerData other = players[otherIdx];
        TileData first = null;

        foreach (var tile in boardManager.allTiles)
        {
            if (tile.tileType != TileType.Property || tile.ownerId == player.playerId) continue;
            if (!other.ownedPropertyIndices.Contains(tile.tileIndex)) other.AddProperty(tile);
            if (first == null) first = tile;
        }
        if (first == null) { Debug.LogWarning("[CHEAT F4] No property tiles found."); return; }

        waitingForDiceRoll = false;
        StopAllCoroutines();
        player.currentTileIndex = first.tileIndex;
        player.movementController?.TeleportToTile(first.tileIndex, boardManager.allTiles);
        HandleProperty(player, first);
    }

    private void Cheat_BuyAllProperties()
    {
        PlayerData player = players[currentPlayerIndex];
        int bought = 0;
        foreach (var tile in boardManager.allTiles)
        {
            if (tile.tileType == TileType.Property && !tile.IsOwned())
            {
                player.AddProperty(tile);
                bought++;
            }
        }
        player.AddMoney(99999);
        Debug.Log($"[CHEAT F5] Bought {bought} properties + 99999 DT");
    }

    private void Cheat_TestTrain_Station()
    {
        PlayerData player = players[currentPlayerIndex];
        waitingForDiceRoll = false;
        StopAllCoroutines();
        player.currentTileIndex = 5;
        player.movementController?.TeleportToTile(5, boardManager.allTiles);
        TileData station = boardManager.GetTile(5);
        if (station == null) { Debug.LogError("[CHEAT F6] Tile 5 not found."); return; }
        HandleRailroad(player, station);
    }

    private void Cheat_TestMinigame()
    {
        if (!IsServer) return;

        PlayerData player = players[currentPlayerIndex];

        // Find the first unowned property tile on the board
        TileData target = null;
        foreach (var tile in boardManager.allTiles)
        {
            if (tile.tileType == TileType.Property && !tile.IsOwned())
            {
                target = tile;
                break;
            }
        }

        if (target == null)
        {
            Debug.LogWarning("[CHEAT F7] No unowned property tiles left.");
            return;
        }

        waitingForDiceRoll = false;
        StopAllCoroutines();

        player.currentTileIndex = target.tileIndex;
        player.movementController?.TeleportToTile(target.tileIndex, boardManager.allTiles);

        Debug.Log($"[CHEAT F7] Teleporting {player.playerName} to '{target.tileName}' → triggering minigame.");
        HandleProperty(player, target);
    }

    private void Cheat_TestMinigameRent()
    {
        PlayerData player = players[currentPlayerIndex];
        waitingForDiceRoll = false;
        StopAllCoroutines();
        TileData dummy = new TileData(99, "Rent Test Tile", TileType.Property, Vector3.zero);
        dummy.propertyColor = PropertyColor.Orange;
        dummy.purchasePrice = 200;
        // Rent context: challenger wins → rent waived; another player wins → nonChallengerReward DT
        TriggerMinigameChallenge(player, dummy, 3, 150, isRentContext: true);
    }
}