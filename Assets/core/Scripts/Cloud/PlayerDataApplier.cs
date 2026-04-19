using System.Threading.Tasks;
using UnityEngine;

/// <summary>
/// Placed in the Board/Game scene.
/// After players are spawned by CompleteGameManager, this script applies
/// cloud save data to the local player's PlayerData.
///
/// Attach to: any persistent GameObject in the Board scene (e.g. GameManager GO)
/// It calls itself automatically via CompleteGameManager.OnGameStarted event.
/// </summary>
public class PlayerDataApplier : MonoBehaviour
{
    private bool _applied = false;

    private void Start()
    {
        // Wait for game to start, then apply cloud data
        if (CompleteGameManager.Instance != null)
            CompleteGameManager.Instance.OnGameStarted.AddListener(OnGameStarted);
        else
            Debug.LogError("[PlayerDataApplier] CompleteGameManager.Instance not found!");
    }

    private void OnGameStarted()
    {
        _ = ApplyCloudDataToLocalPlayer();
    }

    private async Task ApplyCloudDataToLocalPlayer()
    {
        if (_applied) return;

        // Only apply if user chose to resume
        bool shouldResume = PlayerPrefs.GetInt("ResumeCloudSave", 0) == 1;
        if (!shouldResume)
        {
            Debug.Log("[PlayerDataApplier] New game selected — skipping cloud restore.");
            _applied = true;
            return;
        }

        if (CloudSaveManager.Instance == null)
        {
            Debug.LogWarning("[PlayerDataApplier] CloudSaveManager not found.");
            return;
        }

        if (AuthManager.Instance == null || !AuthManager.Instance.IsSignedIn)
        {
            Debug.LogWarning("[PlayerDataApplier] Not signed in — skipping cloud restore.");
            return;
        }

        // Find the local player's PlayerData by Unity PlayerId
        string localUnityId = AuthManager.Instance.PlayerId;
        PlayerData localPlayer = CompleteGameManager.Instance.GetPlayerByUnityId(localUnityId);

        if (localPlayer == null)
        {
            Debug.LogWarning($"[PlayerDataApplier] Could not find PlayerData for PlayerId: {localUnityId}");
            return;
        }

        Debug.Log($"[PlayerDataApplier] Applying cloud save to '{localPlayer.playerName}'...");
        bool loaded = await CloudSaveManager.Instance.LoadPlayerDataAsync(localPlayer);

        if (loaded)
        {
            Debug.Log($"[PlayerDataApplier] ✓ Cloud data applied — Money: {localPlayer.money} | Tile: {localPlayer.currentTileIndex}");

            // Reposition avatar to saved tile
            if (localPlayer.movementController != null)
            {
                var board = FindObjectOfType<BoardManager>();
                if (board != null)
                    localPlayer.movementController.TeleportToTile(localPlayer.currentTileIndex, board.allTiles);
            }
        }
        else
        {
            Debug.Log("[PlayerDataApplier] No cloud save data to apply — using spawned defaults.");
        }

        _applied = true;

        // Clear flag so next game session starts fresh unless user logs in again
        PlayerPrefs.DeleteKey("ResumeCloudSave");
    }
}