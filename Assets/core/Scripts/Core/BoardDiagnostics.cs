using UnityEngine;

/// <summary>
/// Diagnostic tool to visualize board and help fix player spawning
/// Attach this to _Board object temporarily
/// </summary>
public class BoardDiagnostics : MonoBehaviour
{
    [Header("Board Reference")]
    public BoardManager boardManager;
    
    [Header("Visualization")]
    public bool showTilePositions = true;
    public bool showTileNumbers = true;
    public bool showTileNames = true;
    public float gizmoSize = 20f;
    public Color goTileColor = Color.green;
    public Color regularTileColor = Color.cyan;
    
    private void Start()
    {
        if (boardManager == null)
            boardManager = GetComponent<BoardManager>();
        
        if (boardManager != null)
        {
            DiagnoseBoardSetup();
        }
    }
    
    private void DiagnoseBoardSetup()
    {
        Debug.Log("═══════════════════════════════════");
        Debug.Log("   BOARD DIAGNOSTICS");
        Debug.Log("═══════════════════════════════════");
        
        if (boardManager.allTiles == null || boardManager.allTiles.Length == 0)
        {
            Debug.LogError("❌ No tiles found!");
            return;
        }
        
        // Check GO tile
        TileData goTile = boardManager.GetTile(0);
        if (goTile != null)
        {
            Debug.Log($"\n✓ GO TILE (Index 0):");
            Debug.Log($"  Name: {goTile.tileName}");
            Debug.Log($"  Position: {goTile.worldPosition}");
            Debug.Log($"  Type: {goTile.tileType}");
        }
        else
        {
            Debug.LogError("❌ GO tile is NULL!");
        }
        
        // Check corner tiles
        Debug.Log($"\n📍 CORNER TILES:");
        Debug.Log($"  GO (0): {boardManager.GetTile(0)?.worldPosition}");
        Debug.Log($"  Jail (10): {boardManager.GetTile(10)?.worldPosition}");
        Debug.Log($"  Free Parking (20): {boardManager.GetTile(20)?.worldPosition}");
        Debug.Log($"  Go To Jail (30): {boardManager.GetTile(30)?.worldPosition}");
        
        // Calculate board bounds
        Vector3 minPos = Vector3.one * float.MaxValue;
        Vector3 maxPos = Vector3.one * float.MinValue;
        
        foreach (TileData tile in boardManager.allTiles)
        {
            if (tile == null) continue;
            
            minPos = Vector3.Min(minPos, tile.worldPosition);
            maxPos = Vector3.Max(maxPos, tile.worldPosition);
        }
        
        Vector3 boardCenter = (minPos + maxPos) / 2f;
        Vector3 boardSize = maxPos - minPos;
        
        Debug.Log($"\n📐 BOARD BOUNDS:");
        Debug.Log($"  Min: {minPos}");
        Debug.Log($"  Max: {maxPos}");
        Debug.Log($"  Center: {boardCenter}");
        Debug.Log($"  Size: {boardSize}");
        
        // Tile spacing
        float bottomRowSpacing = Vector3.Distance(
            boardManager.GetTile(0).worldPosition,
            boardManager.GetTile(1).worldPosition
        );
        
        Debug.Log($"\n📏 TILE SPACING:");
        Debug.Log($"  Between tiles: {bottomRowSpacing}");
        
        Debug.Log("\n═══════════════════════════════════\n");
    }
    
    private void OnDrawGizmos()
    {
        if (boardManager == null || boardManager.allTiles == null)
            return;
        
        if (!showTilePositions)
            return;
        
        // Draw all tiles
        for (int i = 0; i < boardManager.allTiles.Length; i++)
        {
            TileData tile = boardManager.allTiles[i];
            if (tile == null) continue;
            
            // Color based on tile type
            if (i == 0)
                Gizmos.color = goTileColor;
            else
                Gizmos.color = regularTileColor;
            
            // Draw sphere
            Gizmos.DrawSphere(tile.worldPosition, gizmoSize);
            
            // Draw index and name
#if UNITY_EDITOR
            if (showTileNumbers || showTileNames)
            {
                string label = "";
                if (showTileNumbers)
                    label += $"{i}";
                if (showTileNumbers && showTileNames)
                    label += ": ";
                if (showTileNames)
                    label += tile.tileName;
                
                UnityEditor.Handles.Label(tile.worldPosition + Vector3.up * (gizmoSize * 2), label);
            }
#endif
        }
        
        // Draw board bounds
        if (boardManager.allTiles.Length > 0)
        {
            Vector3 minPos = Vector3.one * float.MaxValue;
            Vector3 maxPos = Vector3.one * float.MinValue;
            
            foreach (TileData tile in boardManager.allTiles)
            {
                if (tile == null) continue;
                minPos = Vector3.Min(minPos, tile.worldPosition);
                maxPos = Vector3.Max(maxPos, tile.worldPosition);
            }
            
            Vector3 boardCenter = (minPos + maxPos) / 2f;
            Vector3 boardSize = maxPos - minPos;
            
            Gizmos.color = Color.yellow;
            Gizmos.DrawWireCube(boardCenter, boardSize);
        }
    }
}
