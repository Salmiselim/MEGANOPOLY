using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Stores all data for a single player in the game
/// </summary>
[System.Serializable]
public class PlayerData
{
    [Header("Identity")]
    public string unityPlayerId;
    public int playerId;               // Unique ID (0-3)
    public string playerName;          // Display name
    public Color playerColor;          // Visual color theme
    
    [Header("Game State")]
    public PlayerState currentState = PlayerState.Idle;
    public int currentTileIndex = 0;   // Current position on board
    public int money = 1500;           // Starting money (classic Monopoly default)
    
    [Header("Properties")]
    public List<int> ownedPropertyIndices = new List<int>(); // List of owned tile indices
    public List<TileData> ownedProperties = new List<TileData>(); // Direct references
    
    [Header("Jail")]
    public bool isInJail = false;
    public int jailTurnsRemaining = 0;
    public bool hasGetOutOfJailCard = false;
    
    [Header("Items")]
    public List<ItemData> heldItems = new List<ItemData>(); // Strategic items
    
    [Header("References")]
    public GameObject playerAvatar;     // 3D avatar in scene
    public Transform avatarTransform;   // For movement
    public PlayerMovement movementController;
    
    /// <summary>
    /// Constructor
    /// </summary>
    public PlayerData(int id, string name, Color color)
    {
        playerId = id;
        playerName = name;
        playerColor = color;
        money = 1500; // Classic starting money
    }
    
    /// <summary>
    /// Add money to player account with visual feedback trigger
    /// </summary>
    public void AddMoney(int amount)
    {
        money += amount;
        // TODO: Trigger money gain animation
        Debug.Log($"{playerName} gained ${amount}. New balance: ${money}");
    }
    
    /// <summary>
    /// Remove money from player account
    /// Returns false if player can't afford it
    /// </summary>
    public bool RemoveMoney(int amount)
    {
        if (money >= amount)
        {
            money -= amount;
            Debug.Log($"{playerName} spent ${amount}. New balance: ${money}");
            return true;
        }
        else
        {
            Debug.LogWarning($"{playerName} cannot afford ${amount}. Current: ${money}");
            return false;
        }
    }
    
    /// <summary>
    /// Check if player can afford a purchase
    /// </summary>
    public bool CanAfford(int amount)
    {
        return money >= amount;
    }
    
    /// <summary>
    /// Add a property to player's portfolio
    /// </summary>
    public void AddProperty(TileData property)
    {
        if (!ownedPropertyIndices.Contains(property.tileIndex))
        {
            ownedPropertyIndices.Add(property.tileIndex);
            ownedProperties.Add(property);
            property.SetOwner(playerId);
            Debug.Log($"{playerName} now owns {property.tileName}");
        }
    }
    
    /// <summary>
    /// Remove a property from player's portfolio
    /// </summary>
    public void RemoveProperty(TileData property)
    {
        ownedPropertyIndices.Remove(property.tileIndex);
        ownedProperties.Remove(property);
        property.ResetOwnership();
    }
    
    /// <summary>
    /// Send player to jail
    /// </summary>
    public void SendToJail()
    {
        isInJail = true;
        jailTurnsRemaining = 2; // Wait 2 full turns before playing again
        currentState = PlayerState.InJail;
        currentTileIndex = 10; // Jail tile
        Debug.Log($"{playerName} sent to jail! Waiting {jailTurnsRemaining} turns.");
    }
    
    /// <summary>
    /// Release player from jail
    /// </summary>
    public void ReleaseFromJail()
    {
        isInJail = false;
        jailTurnsRemaining = 0;
        currentState = PlayerState.Idle;
        Debug.Log($"{playerName} released from jail!");
    }
    
    /// <summary>
    /// Calculate total wealth (money + property values)
    /// </summary>
    public int GetTotalWealth()
    {
        int total = money;
        foreach (TileData property in ownedProperties)
        {
            total += property.purchasePrice;
            total += property.houseCount * property.houseCost;
        }
        return total;
    }
    
    /// <summary>
    /// Check if player is bankrupt
    /// </summary>
    public bool IsBankrupt()
    {
        return money <= 0 && ownedProperties.Count == 0;
    }
    
    /// <summary>
    /// Check if player owns all properties of a color group (monopoly)
    /// </summary>
    public bool HasMonopoly(PropertyColor color, TileData[] allTiles)
    {
        // Count properties of this color on the board
        int totalInColor = 0;
        int playerOwns = 0;
        
        foreach (TileData tile in allTiles)
        {
            if (tile.propertyColor == color && tile.tileType == TileType.Property)
            {
                totalInColor++;
                if (tile.ownerId == playerId)
                    playerOwns++;
            }
        }
        
        return totalInColor > 0 && playerOwns == totalInColor;
    }
}

/// <summary>
/// Data class for strategic items
/// </summary>
[System.Serializable]
public class ItemData
{
    public string itemName;
    public string description;
    public ItemType type;
    
    public ItemData(string name, string desc, ItemType itemType)
    {
        itemName = name;
        description = desc;
        type = itemType;
    }
}

/// <summary>
/// Types of strategic items
/// </summary>
public enum ItemType
{
    CustomDice,         // Choose specific dice value
    DoubleRent,         // Collect double rent
    FreeHouse,          // Build house for free
    TeleportToProperty, // Jump to any owned property
    GetOutOfJail        // Jail free card
}
