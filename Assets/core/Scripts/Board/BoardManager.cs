using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// BoardManager with Manual Tile Positioning System
/// Uses TileMarker objects placed in the scene for exact tile positions
/// </summary>
public class BoardManager : MonoBehaviour
{
    [Header("Tile Marker System")]
    [Tooltip("Auto-find all TileMarker objects in scene")]
    [SerializeField] private bool autoFindTileMarkers = true;
    
    [Tooltip("Or manually assign 40 TileMarker objects")]
    [SerializeField] private TileMarker[] manualTileMarkers = new TileMarker[40];
    
    [Header("Visualization")]
    [SerializeField] private bool showTileGizmos = true;
    [SerializeField] private float gizmoSize = 15f;
    
    [Header("Board Data")]
    public TileData[] allTiles = new TileData[40];
    
    // Tile organization
    private Dictionary<TileType, List<TileData>> tilesByType = new Dictionary<TileType, List<TileData>>();
    private Dictionary<PropertyColor, List<TileData>> tilesByColor = new Dictionary<PropertyColor, List<TileData>>();
    
    private Dictionary<int, TileMarker> tileMarkersByIndex = new Dictionary<int, TileMarker>();
    
    [Header("Building Prefabs")]
    [SerializeField] private GameObject housePrefab;
    [SerializeField] private GameObject hotelPrefab;
    
    private void Awake()
    {
        if (allTiles == null || allTiles.Length != 40)
            allTiles = new TileData[40];
        
        InitializeBoard();
    }
    
    public void InitializeBoard()
    {
        Debug.Log("═══════════════════════════════════");
        Debug.Log("   MEGANOPOLY BOARD INITIALIZATION");
        Debug.Log("═══════════════════════════════════");
        
        // Get tile markers
        TileMarker[] markers = GetTileMarkers();
        
        if (markers == null || markers.Length < 40)
        {
            Debug.LogError($"❌ Need 40 tile markers, found {(markers?.Length ?? 0)}!");
            Debug.LogError("Please place 40 TileMarker objects on your board!");
            return;
        }
        
        // Create tile data from markers
        for (int i = 0; i < 40; i++)
        {
            if (markers[i] != null)
            {
                Vector3 position = markers[i].transform.position;
                allTiles[i] = new TileData(i, markers[i].GetTileName(), TileType.Property, position);
            }
            else
            {
                Debug.LogError($"❌ Tile marker {i} is missing!");
                allTiles[i] = new TileData(i, $"Missing_{i}", TileType.Property, Vector3.zero);
            }
        }
        
        // Set up tile properties
        SetupTileData();
        
        // Organize
        OrganizeTiles();
        
        Debug.Log($"✓ Board initialized with {allTiles.Length} tiles!");
        Debug.Log($"✓ GO Position: {allTiles[0].worldPosition}");
        Debug.Log($"✓ Jail Position: {allTiles[10].worldPosition}");
        Debug.Log("═══════════════════════════════════\n");
    }
    
    /// <summary>
    /// Get tile markers from scene
    /// </summary>
    private TileMarker[] GetTileMarkers()
    {
        TileMarker[] markers = new TileMarker[40];
        
        if (autoFindTileMarkers)
        {
            Debug.Log("🔍 Auto-finding tile markers...");
            
            TileMarker[] foundMarkers = FindObjectsOfType<TileMarker>();
            
            Debug.Log($"Found {foundMarkers.Length} TileMarker objects in scene");
            
            // Sort by tile index
            foreach (TileMarker marker in foundMarkers)
            {
                if (marker.tileIndex >= 0 && marker.tileIndex < 40)
                {
                    if (markers[marker.tileIndex] != null)
                    {
                        Debug.LogWarning($"⚠️ Duplicate tile marker for index {marker.tileIndex}!");
                      }
                    markers[marker.tileIndex] = marker;
                }
                else
                {
                    Debug.LogWarning($"⚠️ TileMarker has invalid index: {marker.tileIndex}");
                }
            }
            
            // Store markers for later use
            tileMarkersByIndex.Clear();
            foreach (TileMarker marker in foundMarkers)
            {
                if (marker != null && marker.tileIndex >= 0 && marker.tileIndex < 40)
                {
                    tileMarkersByIndex[marker.tileIndex] = marker;
                }
            }
            
            // Check for missing markers
            int missingCount = 0;
            for (int i = 0; i < 40; i++)
            {
                if (markers[i] == null)
                {
                    Debug.LogWarning($"⚠️ Missing tile marker for index {i}");
                    missingCount++;
                }
            }
            
            if (missingCount == 0)
            {
                Debug.Log($"✓ Found all 40 tile markers!");
            }
            else
            {
                Debug.LogWarning($"⚠️ Missing {missingCount} tile markers");
            }
        }
        else
        {
            Debug.Log("Using manually assigned tile markers");
            markers = manualTileMarkers;
        }
        
        return markers;
    }
    
    /// <summary>
    /// Set up tile properties based on your Tunisian board layout
    /// </summary>
    private void SetupTileData()
    {
        // CORNERS
        SetupTile(0, "GO", TileType.GO, PropertyColor.None, 0, 0);
        SetupTile(10, "Jail", TileType.Jail, PropertyColor.None, 0, 0);
        SetupTile(20, "Jackpot", TileType.FreeParking, PropertyColor.None, 0, 0);
        SetupTile(30, "Go To Jail", TileType.GoToJail, PropertyColor.None, 0, 0);
        
        // BROWN PROPERTIES (Tiles 1, 3)
        SetupTile(1, "Korbus", TileType.Property, PropertyColor.Brown, 60, 2, new int[] { 10, 30, 90, 160, 250 }, 50);
        SetupTile(3, "Testour", TileType.Property, PropertyColor.Brown, 60, 4, new int[] { 20, 60, 180, 320, 450 }, 50);
        
        // LIGHT BLUE PROPERTIES (Tiles 6, 8, 9)
        SetupTile(6, "Beja", TileType.Property, PropertyColor.LightBlue, 100, 6, new int[] { 30, 90, 270, 400, 550 }, 50);
        SetupTile(8, "El Kef", TileType.Property, PropertyColor.LightBlue, 100, 6, new int[] { 30, 90, 270, 400, 550 }, 50);
        SetupTile(9, "Jendouba", TileType.Property, PropertyColor.LightBlue, 120, 8, new int[] { 40, 100, 300, 450, 600 }, 50);
        
        // PINK PROPERTIES (Tiles 11, 13, 14)
        SetupTile(11, "Gafsa", TileType.Property, PropertyColor.Pink, 140, 10, new int[] { 50, 150, 450, 625, 750 }, 100);
        SetupTile(13, "Kasserine", TileType.Property, PropertyColor.Pink, 140, 10, new int[] { 50, 150, 450, 625, 750 }, 100);
        SetupTile(14, "El Mahdia", TileType.Property, PropertyColor.Pink, 160, 12, new int[] { 60, 180, 500, 700, 900 }, 100);
        
        // ORANGE PROPERTIES (Tiles 16, 18, 19)
        SetupTile(16, "Touzeur", TileType.Property, PropertyColor.Orange, 180, 14, new int[] { 70, 200, 550, 750, 950 }, 100);
        SetupTile(18, "Nefta", TileType.Property, PropertyColor.Orange, 180, 14, new int[] { 70, 200, 550, 750, 950 }, 100);
        SetupTile(19, "Douz", TileType.Property, PropertyColor.Orange, 200, 16, new int[] { 80, 220, 600, 800, 1000 }, 100);
        
        // RED PROPERTIES (Tiles 21, 23, 24)
        SetupTile(21, "Kaourouan", TileType.Property, PropertyColor.Red, 220, 18, new int[] { 90, 250, 700, 875, 1050 }, 150);
        SetupTile(23, "Tataouine", TileType.Property, PropertyColor.Red, 220, 18, new int[] { 90, 250, 700, 875, 1050 }, 150);
        SetupTile(24, "Ksar ghilane", TileType.Property, PropertyColor.Red, 240, 20, new int[] { 100, 300, 750, 925, 1100 }, 150);
        
        // YELLOW PROPERTIES (Tiles 26, 27, 29)
        SetupTile(26, "Zarzis", TileType.Property, PropertyColor.Yellow, 260, 22, new int[] { 110, 330, 800, 975, 1150 }, 150);
        SetupTile(27, "Ben Gardane", TileType.Property, PropertyColor.Yellow, 260, 22, new int[] { 110, 330, 800, 975, 1150 }, 150);
        SetupTile(29, "Houmt EL Souk", TileType.Property, PropertyColor.Yellow, 280, 24, new int[] { 120, 360, 850, 1025, 1200 }, 150);
        
        // GREEN PROPERTIES (Tiles 31, 32, 34)
        SetupTile(31, "Hammamet Beach", TileType.Property, PropertyColor.Green, 300, 26, new int[] { 130, 390, 900, 1100, 1275 }, 200);
        SetupTile(32, "El Kantaoui", TileType.Property, PropertyColor.Green, 300, 26, new int[] { 130, 390, 900, 1100, 1275 }, 200);
        SetupTile(34, "Sousse Medina", TileType.Property, PropertyColor.Green, 320, 28, new int[] { 150, 450, 1000, 1200, 1400 }, 200);
        
        // DARK BLUE PROPERTIES (Tiles 37, 39)
        SetupTile(37, "Carthage", TileType.Property, PropertyColor.DarkBlue, 350, 35, new int[] { 175, 500, 1100, 1300, 1500 }, 200);
        SetupTile(39, "Medina Tunis", TileType.Property, PropertyColor.DarkBlue, 400, 50, new int[] { 200, 600, 1400, 1700, 2000 }, 200);
        
        // RAILROADS/STATIONS (Tiles 5, 15, 25, 35)
        SetupTile(5, "Bizerte Station", TileType.Railroad, PropertyColor.None, 200, 25);
        SetupTile(15, "Gafsa Station", TileType.Railroad, PropertyColor.None, 200, 25);
        SetupTile(25, "Sfax Metro", TileType.Railroad, PropertyColor.None, 200, 25);
        SetupTile(35, "Tunis Station", TileType.Railroad, PropertyColor.None, 200, 25);
        
        // SPECIAL TILES
        SetupTile(2, "Item Space", TileType.Item, PropertyColor.None, 0, 0);
        SetupTile(4, "Tax", TileType.Tax, PropertyColor.None, 0, 200);
        SetupTile(7, "Chance", TileType.Chance, PropertyColor.None, 0, 0);
        SetupTile(12, "Item Space", TileType.Item, PropertyColor.None, 0, 0);
        SetupTile(17, "Swap Space", TileType.Swap, PropertyColor.None, 0, 0);
        SetupTile(22, "Chance", TileType.Chance, PropertyColor.None, 0, 0);
        SetupTile(28, "Swap Space", TileType.Swap, PropertyColor.None, 0, 0);
        SetupTile(33, "Trap Space", TileType.Trap, PropertyColor.None, 0, 0);
        SetupTile(36, "Chance", TileType.Chance, PropertyColor.None, 0, 0);
        SetupTile(38, "Tax", TileType.Tax, PropertyColor.None, 0, 100);
    }
    
    /// <summary>
    /// Helper method to set up individual tile data
    /// </summary>
    private void SetupTile(int index, string name, TileType type, PropertyColor color,
                           int price, int rent, int[] rentWithHouses = null, int houseCost = 0)
    {
        if (allTiles[index] == null) return;
        
        allTiles[index].tileName = name;
        allTiles[index].tileType = type;
        allTiles[index].propertyColor = color;
        allTiles[index].purchasePrice = price;
        allTiles[index].baseRent = rent;
        allTiles[index].rentWithHouses = rentWithHouses;
        allTiles[index].houseCost = houseCost;
        allTiles[index].allowsMiniGame = (type == TileType.Property);
    }
    
    /// <summary>
    /// Organize tiles by type and color for quick lookup
    /// </summary>
    private void OrganizeTiles()
    {
        tilesByType.Clear();
        tilesByColor.Clear();
        
        foreach (TileData tile in allTiles)
        {
            if (tile == null) continue;
            
            // By type
            if (!tilesByType.ContainsKey(tile.tileType))
                tilesByType[tile.tileType] = new List<TileData>();
            tilesByType[tile.tileType].Add(tile);
            
            // By color
            if (tile.propertyColor != PropertyColor.None)
            {
                if (!tilesByColor.ContainsKey(tile.propertyColor))
                    tilesByColor[tile.propertyColor] = new List<TileData>();
                tilesByColor[tile.propertyColor].Add(tile);
            }
        }
    }
    
    /// <summary>
    /// Get tile by index
    /// </summary>
    public TileData GetTile(int index)
    {
        if (index >= 0 && index < 40)
            return allTiles[index];
        return null;
    }
    
    /// <summary>
    /// Get all tiles of a specific type
    /// </summary>
    public List<TileData> GetTilesByType(TileType type)
    {
        return tilesByType.ContainsKey(type) ? tilesByType[type] : new List<TileData>();
    }
    
    /// <summary>
    /// Get all tiles of a specific color
    /// </summary>
    public List<TileData> GetTilesByColor(PropertyColor color)
    {
        return tilesByColor.ContainsKey(color) ? tilesByColor[color] : new List<TileData>();
    }
    
    /// <summary>
    /// Debug visualization
    /// </summary>
    private void OnDrawGizmos()
    {
        if (!showTileGizmos || allTiles == null)
            return;
        
        for (int i = 0; i < allTiles.Length; i++)
        {
            if (allTiles[i] == null) continue;
            
            // Color based on tile type
            switch (allTiles[i].tileType)
            {
                case TileType.GO:
                    Gizmos.color = Color.green;
                    break;
                case TileType.Property:
                    Gizmos.color = GetColorForPropertyColor(allTiles[i].propertyColor);
                    break;
                case TileType.Jail:
                    Gizmos.color = Color.gray;
                    break;
                case TileType.Chance:
                    Gizmos.color = Color.cyan;
                    break;
                case TileType.Trap:
                    Gizmos.color = Color.red;
                    break;
                case TileType.Item:
                    Gizmos.color = Color.magenta;
                    break;
                case TileType.Swap:
                    Gizmos.color = Color.white;
                    break;
                default:
                    Gizmos.color = Color.yellow;
                    break;
            }
            
            Gizmos.DrawSphere(allTiles[i].worldPosition, gizmoSize);
        }
    }
    
    /// <summary>
    /// Get visual color for property color groups
    /// </summary>
    private Color GetColorForPropertyColor(PropertyColor color)
    {
        switch (color)
        {
            case PropertyColor.Brown: return new Color(0.6f, 0.3f, 0.1f);
            case PropertyColor.LightBlue: return Color.cyan;
            case PropertyColor.Pink: return Color.magenta;
            case PropertyColor.Orange: return new Color(1f, 0.5f, 0f);
            case PropertyColor.Red: return Color.red;
            case PropertyColor.Yellow: return Color.yellow;
            case PropertyColor.Green: return Color.green;
            case PropertyColor.DarkBlue: return Color.blue;
            default: return Color.white;
        }
    }
    
    /// <summary>
    /// Spawn a house on a property tile
    /// </summary>
    public GameObject SpawnHouse(int tileIndex, int houseNumber)
    {
        if (housePrefab == null)
        {
            Debug.LogWarning("[BoardManager] housePrefab is not assigned! Assign it in the Inspector.");
            return null;
        }
        if (tileIndex < 0 || tileIndex >= 40) return null;

        TileData tile = allTiles[tileIndex];
        if (tile == null) return null;

        // Use the TileMarker spawn point if available, otherwise fall back
        Vector3 spawnPos;
        TileMarker marker = GetTileMarker(tileIndex);
        if (marker != null)
          spawnPos = marker.GetHouseSpawnPosition(houseNumber - 1); // houseNumber is 1-based
        else
     spawnPos = tile.worldPosition + Vector3.right * ((houseNumber - 1) * 3f) + Vector3.up * 0.5f;

        GameObject house = Instantiate(housePrefab, spawnPos, Quaternion.identity);
        house.name = $"House_{tile.tileName}_{houseNumber}";
        Debug.Log($"[BoardManager] Spawned house #{houseNumber} on {tile.tileName} at {spawnPos}");
        return house;
    }
    
    /// <summary>
    /// Spawn a hotel (replaces houses)
    /// </summary>
    public GameObject SpawnHotel(int tileIndex)
    {
        if (hotelPrefab == null)
        {
            Debug.LogWarning("[BoardManager] hotelPrefab is not assigned! Assign it in the Inspector.");
            return null;
        }
        if (tileIndex < 0 || tileIndex >= 40) return null;

        TileData tile = allTiles[tileIndex];
        if (tile == null) return null;

        // Use the TileMarker spawn point if available, otherwise fall back
      Vector3 spawnPos;
        TileMarker marker = GetTileMarker(tileIndex);
        if (marker != null)
   spawnPos = marker.GetHotelSpawnPosition();
        else
   spawnPos = tile.worldPosition + Vector3.up * 0.5f;

 GameObject hotel = Instantiate(hotelPrefab, spawnPos, Quaternion.identity);
        hotel.name = $"Hotel_{tile.tileName}";
        Debug.Log($"[BoardManager] Spawned hotel on {tile.tileName} at {spawnPos}");
        return hotel;
    }
    
    /// <summary>
    /// Get the TileMarker for a specific tile index
    /// </summary>
    public TileMarker GetTileMarker(int tileIndex)
    {
        if (tileMarkersByIndex.ContainsKey(tileIndex))
            return tileMarkersByIndex[tileIndex];
        return null;
    }
}
