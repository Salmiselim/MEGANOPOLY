using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Manages property purchases and building construction
/// </summary>
public class PropertyManager : MonoBehaviour
{
    public static PropertyManager Instance { get; private set; }

    [Header("References")]
    [SerializeField] private BoardManager boardManager;

    // Track spawned buildings per tile
    private Dictionary<int, List<GameObject>> spawnedHouses = new Dictionary<int, List<GameObject>>();
    private Dictionary<int, GameObject> spawnedHotels = new Dictionary<int, GameObject>();

    private void Awake()
    {
        if (Instance == null)
            Instance = this;
        else
            Destroy(gameObject);

        if (boardManager == null)
            boardManager = FindObjectOfType<BoardManager>();
    }

    /// <summary>
    /// Attempt to buy a property
    /// </summary>
    public bool TryBuyProperty(PlayerData player, TileData property)
    {
        if (player == null || property == null) return false;
        if (property.IsOwned()) return false;
        if (!player.CanAfford(property.purchasePrice)) return false;

        if (player.RemoveMoney(property.purchasePrice))
        {
            player.AddProperty(property);
            Debug.Log($"🏠 {player.playerName} bought {property.tileName} for ${property.purchasePrice}");
            return true;
        }

        return false;
    }

    /// <summary>
    /// Attempt to buy a house on a property
    /// </summary>
    public bool TryBuyHouse(PlayerData player, TileData property)
    {
        if (player == null || property == null) return false;
        if (property.ownerId != player.playerId) return false;
        if (property.houseCount >= 4) return false; // Max 4 houses before hotel
        if (!player.CanAfford(property.houseCost)) return false;

        // Check if player has monopoly (owns all properties of this color)
        if (!player.HasMonopoly(property.propertyColor, boardManager.allTiles))
        {
            Debug.Log($"❌ Need monopoly on {property.propertyColor} to build!");
            return false;
        }

        if (player.RemoveMoney(property.houseCost))
        {
            property.AddHouse();

            // Spawn visual house
            GameObject house = boardManager.SpawnHouse(property.tileIndex, property.houseCount);
            
            if (!spawnedHouses.ContainsKey(property.tileIndex))
                spawnedHouses[property.tileIndex] = new List<GameObject>();
            
            if (house != null)
                spawnedHouses[property.tileIndex].Add(house);

            Debug.Log($"🏠 {player.playerName} built house #{property.houseCount} on {property.tileName}");
            Debug.Log($"💰 New rent: ${property.GetCurrentRent()}");
            return true;
        }

        return false;
    }

    /// <summary>
    /// Attempt to buy a hotel (requires 4 houses)
    /// </summary>
    public bool TryBuyHotel(PlayerData player, TileData property)
    {
        if (player == null || property == null) return false;
        if (property.ownerId != player.playerId) return false;
        if (property.houseCount != 4) return false; // Need exactly 4 houses
        
        int hotelCost = property.hotelCost > 0 ? property.hotelCost : property.houseCost;
        if (!player.CanAfford(hotelCost)) return false;

        if (player.RemoveMoney(hotelCost))
        {
            // Remove houses visually
            if (spawnedHouses.ContainsKey(property.tileIndex))
            {
                foreach (var house in spawnedHouses[property.tileIndex])
                {
                    if (house != null) Destroy(house);
                }
                spawnedHouses[property.tileIndex].Clear();
            }

            // Add hotel (houseCount = 5 means hotel)
            property.houseCount = 5;

            // Spawn visual hotel
            GameObject hotel = boardManager.SpawnHotel(property.tileIndex);
            spawnedHotels[property.tileIndex] = hotel;

            Debug.Log($"🏨 {player.playerName} built a HOTEL on {property.tileName}!");
            Debug.Log($"💰 New rent: ${property.GetCurrentRent()}");
            return true;
        }

        return false;
    }

    /// <summary>
    /// Get building status for UI
    /// </summary>
    public string GetBuildingStatus(TileData property)
    {
        if (property.houseCount == 0) return "No buildings";
        if (property.houseCount == 5) return "🏨 Hotel";
        return $"🏠 {property.houseCount} house(s)";
    }
}