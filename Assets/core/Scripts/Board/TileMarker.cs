using UnityEngine;

/// <summary>
/// Manual Tile Marker - Place 40 of these on your board tiles
/// Updated with correct Tunisian board tile names
/// </summary>
public class TileMarker : MonoBehaviour
{
    [Header("Tile Info")]
    [Tooltip("Tile index (0-39). 0=GO, 10=Jail, 20=Jackpot, 30=Go To Jail")]
    public int tileIndex = 0;

    [Header("Property Card")]
    [Tooltip("The 3D card object for this property (child of this tile)")]
    public GameObject propertyCard;

    [Header("Building Spawn Points")]
    [Tooltip("Assign 4 child GameObjects — one for each house slot (left to right)")]
    public Transform[] houseSpawnPoints = new Transform[4];

    [Tooltip("Assign 1 child GameObject for the hotel spawn position")]
    public Transform hotelSpawnPoint;

    [Header("Visual Gizmo")]
    public Color gizmoColor = Color.cyan;
    public float gizmoSize = 15f;
    public bool showTileNumber = true;
    public bool showTileName = true;

    [Header("Auto-Naming")]
    [Tooltip("Automatically name this GameObject based on tile index")]
    public bool autoRename = true;

    // Updated tile names for your board
    private static readonly string[] tileNames = new string[40]
    {
        "GO", "Korbus", "Item Space", "Testour", "Tax",
        "Bizerte Station", "Beja", "Chance", "El Kef",
        "Jendouba", "Jail", "Gafsa", "Item Space", "Kasserine",
        "El Mahdia", "Gafsa Station", "Touzeur", "Swap Space", "Nefta",
        "Douz", "Jackpot", "Kaourouan", "Chance", "Tataouine",
        "Ksar ghilane", "Sfax Metro", "Zarzis", "Ben Gardane", "Swap Space",
        "Houmt EL Souk", "Go To Jail", "Hammamet Beach","El Kantaoui", "Trap Space", "Sousse Medina",
        "Tunis Station", "Chance", "Carthage", "Tax", "Medina Tunis"
    };

    private void OnValidate()
    {
        tileIndex = Mathf.Clamp(tileIndex, 0, 39);

        if (autoRename && tileIndex >= 0 && tileIndex < 40)
            gameObject.name = $"Tile_{tileIndex:D2}_{tileNames[tileIndex].Replace(" ", "")}";

        // Auto-find card if not assigned
        if (propertyCard == null)
        {
            propertyCard = transform.Find("Card")?.gameObject;
            if (propertyCard == null)
                propertyCard = transform.Find("PropertyCard")?.gameObject;
        }

        // Auto-find spawn points by name if not assigned
        AutoFindSpawnPoints();
    }

    /// <summary>
    /// Tries to find child GameObjects named HouseSpawn_1..4 and HotelSpawn automatically.
    /// </summary>
    private void AutoFindSpawnPoints()
    {
        if (houseSpawnPoints == null || houseSpawnPoints.Length != 4)
            houseSpawnPoints = new Transform[4];

        for (int i = 0; i < 4; i++)
        {
            if (houseSpawnPoints[i] == null)
                houseSpawnPoints[i] = transform.Find($"HouseSpawn_{i + 1}");
        }

        if (hotelSpawnPoint == null)
            hotelSpawnPoint = transform.Find("HotelSpawn");
    }

    /// <summary>
    /// Returns the world position for house slot (0-3).
    /// Falls back to an automatic offset if no spawn point is assigned.
    /// </summary>
    public Vector3 GetHouseSpawnPosition(int houseSlot)
    {
        if (houseSpawnPoints != null && houseSlot < houseSpawnPoints.Length
            && houseSpawnPoints[houseSlot] != null)
            return houseSpawnPoints[houseSlot].position;

        // Fallback: offset along the tile's local right axis
        return transform.position + transform.right * (houseSlot * 3f) + Vector3.up * 0.5f;
    }

    /// <summary>
    /// Returns the world position for the hotel.
    /// Falls back to the tile centre if no spawn point is assigned.
    /// </summary>
    public Vector3 GetHotelSpawnPosition()
    {
        if (hotelSpawnPoint != null)
            return hotelSpawnPoint.position;

        return transform.position + Vector3.up * 0.5f;
    }

    // ?? Gizmos ???????????????????????????????????????????????????????????????

    private void OnDrawGizmos()
    {
        Color displayColor = gizmoColor;

        if (tileIndex == 0) displayColor = Color.green;
        else if (tileIndex == 10) displayColor = Color.gray;
        else if (tileIndex == 20) displayColor = Color.yellow;
        else if (tileIndex == 30) displayColor = Color.red;

        Gizmos.color = displayColor;
        Gizmos.DrawSphere(transform.position, gizmoSize);
        Gizmos.color = new Color(displayColor.r, displayColor.g, displayColor.b, 0.3f);
        Gizmos.DrawWireSphere(transform.position, gizmoSize * 1.5f);

        // Draw house spawn points in green
        if (houseSpawnPoints != null)
        {
            Gizmos.color = Color.green;
            foreach (Transform sp in houseSpawnPoints)
                if (sp != null) Gizmos.DrawWireCube(sp.position, Vector3.one * 2f);
        }

        // Draw hotel spawn point in red
        if (hotelSpawnPoint != null)
        {
            Gizmos.color = Color.red;
            Gizmos.DrawWireCube(hotelSpawnPoint.position, Vector3.one * 3f);
        }

#if UNITY_EDITOR
        if (showTileNumber || showTileName)
        {
            string label = "";
            if (showTileNumber) label += $"[{tileIndex}]";
            if (showTileNumber && showTileName) label += " ";
            if (showTileName && tileIndex < tileNames.Length) label += tileNames[tileIndex];

            GUIStyle style = new GUIStyle();
            style.normal.textColor = displayColor;
            style.fontSize = 12;
            style.fontStyle = FontStyle.Bold;
            UnityEditor.Handles.Label(transform.position + Vector3.up * (gizmoSize * 2), label, style);
        }
#endif
    }

    private void OnDrawGizmosSelected()
    {
        Gizmos.color = Color.yellow;
        Gizmos.DrawWireSphere(transform.position, gizmoSize * 2f);
    }

    public string GetTileName()
    {
        if (tileIndex >= 0 && tileIndex < tileNames.Length)
            return tileNames[tileIndex];
        return "Unknown";
    }
}