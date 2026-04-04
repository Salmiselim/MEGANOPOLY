using UnityEngine;

/// <summary>
/// Core enumerations for MEGANOPOLY game systems
/// </summary>
public class GameEnums : MonoBehaviour
{
    // Empty MonoBehaviour to allow script attachment if needed
}

/// <summary>
/// Types of tiles on the Monopoly board
/// </summary>
public enum TileType
{
    Property,       // Standard buyable property
    Railroad,       // Train station properties
    Utility,        // Water/Electric company
    GO,             // Start tile - collect money when passing
    Jail,           // Just visiting (not in jail)
    FreeParking,    // Free parking / chill zone
    GoToJail,       // Sends player to jail
    Chance,         // Mostly positive card effects
    Trap,           // Mostly negative card effects
    Item,           // Get strategic items
    Swap,           // Random swap effects
    Tax             // Pay tax to bank
}

/// <summary>
/// Property color groups - each tied to specific mini-game
/// </summary>
public enum PropertyColor
{
    Brown,      // BISS mini-game
    LightBlue,  // Khobz mini-game
    Pink,       // Rock Paper Scissors mini-game
    Orange,     // Bent Walad mini-game
    Red,        // Pottery Balance mini-game
    Yellow,     // Hide and Seek (Ghomidha) mini-game
    Green,      // 3allouch El Eid mini-game
    DarkBlue,   // Fass3a mini-game
    None        // For non-property tiles
}

/// <summary>
/// Current state of a player in the game
/// </summary>
public enum PlayerState
{
    Idle,           // Waiting for turn
    WaitingToRoll,  // Player's turn, can roll dice
    Rolling,        // Dice are being rolled
    Moving,         // Player is moving across tiles
    OnTile,         // Landed on tile, processing action
    ChoosingAction, // Deciding to buy or play mini-game
    InMiniGame,     // Currently playing mini-game
    InJail,         // Stuck in jail
    Trading,        // Negotiating trade with another player
    Bankrupt        // Out of the game
}

/// <summary>
/// Game phase states
/// </summary>
public enum GameState
{
    Setup,          // Game initialization
    Playing,        // Active gameplay
    Paused,         // Game paused
    GameOver,       // Winner determined
    MainMenu        // In menu
}

/// <summary>
/// Types of cards in the game
/// </summary>
public enum CardType
{
    Chance,     // Positive effects
    Trap,       // Negative effects
    Item        // Strategic items
}

/// <summary>
/// Mini-game difficulty levels
/// </summary>
public enum DifficultyLevel
{
    Easy = 1,
    Medium = 2,
    Hard = 3
}

/// <summary>
/// Types of animations for tile events
/// </summary>
public enum TileAnimation
{
    None,
    MoneyRain,
    PoliceEscort,
    Fireworks,
    Confetti,
    BuildingDrop,
    TrainPass
}
