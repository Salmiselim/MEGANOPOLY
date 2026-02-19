using UnityEngine;

/// <summary>
/// Holds a manual spawn point for a player
/// Place 4 of these in your scene where you want players to spawn
/// </summary>
public class PlayerSpawnPoint : MonoBehaviour
{
    [Header("Spawn Point Info")]
    [Tooltip("Which player spawns here (0-3)")]
    public int playerIndex = 0;
    
    [Header("Visual Gizmo")]
    public Color gizmoColor = Color.green;
    public float gizmoSize = 20f;
    public bool showPlayerNumber = true;
    
    private void OnDrawGizmos()
    {
        // Draw sphere at spawn position
        Gizmos.color = gizmoColor;
        Gizmos.DrawSphere(transform.position, gizmoSize);
        
        // Draw wireframe sphere for better visibility
        Gizmos.DrawWireSphere(transform.position, gizmoSize * 1.2f);
        
        // Draw player number
#if UNITY_EDITOR
        if (showPlayerNumber)
        {
            UnityEditor.Handles.Label(
                transform.position + Vector3.up * (gizmoSize * 2), 
                $"Player {playerIndex + 1} Spawn",
                new GUIStyle()
                {
                    normal = new GUIStyleState() { textColor = gizmoColor },
                    fontSize = 14,
                    fontStyle = FontStyle.Bold
                }
            );
        }
#endif
    }
    
    private void OnDrawGizmosSelected()
    {
        // Draw larger gizmo when selected
        Gizmos.color = Color.yellow;
        Gizmos.DrawWireSphere(transform.position, gizmoSize * 1.5f);
    }
}
