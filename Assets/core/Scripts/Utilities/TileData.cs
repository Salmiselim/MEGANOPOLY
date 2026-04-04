using UnityEngine;

/// <summary>
/// Data container for individual board tiles
/// Stores all information about a tile's properties, position, and ownership
/// </summary>
[System.Serializable]
public class TileData
{
    [Header("Basic Info")]
    public int tileIndex;           // Position on board (0-39)
    public string tileName;         // Display name
    public TileType tileType;       // What kind of tile
    
    [Header("Property Info")]
    public PropertyColor propertyColor = PropertyColor.None;
    public int purchasePrice;       // Cost to buy
    public int baseRent;           // Rent without houses
    public int[] rentWithHouses;   // Rent for 1, 2, 3, 4 houses, hotel
    public int houseCost;          // Cost to build house
    public int hotelCost;          // Cost to build hotel
    
    [Header("Ownership")]
    public int ownerId = -1;       // Player ID (-1 = unowned, 0-3 = player)
    public int houseCount = 0;     // 0-4 houses, 5 = hotel
    
    [Header("Position")]
    public Vector3 worldPosition;  // 3D position in scene
    public Quaternion worldRotation = Quaternion.identity;
    
    [Header("Visual")]
    public GameObject tileObject;  // Reference to tile GameObject in scene
    public Material tileMaterial;  // Visual material
    
    [Header("Mini-Game")]
    public bool allowsMiniGame;    // Can trigger mini-game on this tile
    public DifficultyLevel miniGameDifficulty = DifficultyLevel.Easy;
    
    /// <summary>
    /// Constructor for creating a new tile
    /// </summary>
    public TileData(int index, string name, TileType type, Vector3 position)
    {
        tileIndex = index;
        tileName = name;
        tileType = type;
        worldPosition = position;
        allowsMiniGame = (type == TileType.Property);
    }
    
    /// <summary>
    /// Check if this tile is owned by any player
    /// </summary>
    public bool IsOwned()
    {
        return ownerId >= 0;
    }
    
    /// <summary>
    /// Get current rent value based on house count
    /// </summary>
    public int GetCurrentRent()
    {
        if (!IsOwned() || tileType != TileType.Property)
            return 0;
            
        if (houseCount == 0)
            return baseRent;
        else if (houseCount <= 4 && rentWithHouses != null && houseCount <= rentWithHouses.Length)
            return rentWithHouses[houseCount - 1];
        else if (houseCount == 5) // Hotel
            return rentWithHouses != null && rentWithHouses.Length > 4 ? rentWithHouses[4] : baseRent * 10;
            
        return baseRent;
    }
    
    /// <summary>
    /// Set owner of this property
    /// </summary>
    public void SetOwner(int playerId)
    {
        ownerId = playerId;
    }
    
    /// <summary>
    /// Add a house to this property
    /// </summary>
    public bool AddHouse()
    {
        if (houseCount < 5 && IsOwned())
        {
            houseCount++;
            return true;
        }
        return false;
    }
    
    /// <summary>
    /// Remove a house from this property
    /// </summary>
    public bool RemoveHouse()
    {
        if (houseCount > 0)
        {
            houseCount--;
            return true;
        }
        return false;
    }
    
    /// <summary>
    /// Reset tile to unowned state
    /// </summary>
    public void ResetOwnership()
    {
        ownerId = -1;
        houseCount = 0;
    }
}
