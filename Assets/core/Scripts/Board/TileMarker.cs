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
        {
            gameObject.name = $"Tile_{tileIndex:D2}_{tileNames[tileIndex].Replace(" ", "")}";
        }

        // Auto-find card if not assigned
        if (propertyCard == null)
        {
            propertyCard = transform.Find("Card")?.gameObject;
            if (propertyCard == null)
                propertyCard = transform.Find("PropertyCard")?.gameObject;
        }
    }

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

#if UNITY_EDITOR
        if (showTileNumber || showTileName)
        {
            string label = "";
            if (showTileNumber)
                label += $"[{tileIndex}]";
            if (showTileNumber && showTileName)
                label += " ";
            if (showTileName && tileIndex < tileNames.Length)
                label += tileNames[tileIndex];

            GUIStyle style = new GUIStyle();
            style.normal.textColor = displayColor;
            style.fontSize = 12;
            style.fontStyle = FontStyle.Bold;

            UnityEditor.Handles.Label(
                transform.position + Vector3.up * (gizmoSize * 2),
                label,
                style
            );
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