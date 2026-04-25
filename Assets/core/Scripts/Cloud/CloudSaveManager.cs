using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using Unity.Services.CloudSave;
using Unity.Services.CloudSave.Models;
using Unity.Services.Authentication;

/// <summary>
/// Handles all Unity Cloud Save operations for player persistence.
/// Attach to: AuthManager GameObject (persists via DontDestroyOnLoad)
/// </summary>
public class CloudSaveManager : MonoBehaviour
{
    public static CloudSaveManager Instance { get; private set; }

    // ── Cloud Save Keys ───────────────────────────────────────────────────────
    private const string KEY_PLAYER_PROFILE = "player_profile";
    private const string KEY_GAME_STATS = "game_stats";
    private const string KEY_PROPERTIES = "owned_properties";
    private const string KEY_ITEMS = "held_items";

    private void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    // =========================================================================
    // SAVE
    // =========================================================================

    /// <summary>
    /// Saves the full state of a PlayerData to the cloud.
    /// Call this: after every turn end, after buying property, after money changes.
    /// </summary>
    public async Task SavePlayerDataAsync(PlayerData player)
    {
        if (!AuthenticationService.Instance.IsSignedIn)
        {
            Debug.LogWarning("[CloudSave] Not signed in — skipping save.");
            return;
        }

        try
        {
            // ── Build serialisable snapshots ──────────────────────────────
            var profile = new PlayerProfileData
            {
                playerId = player.playerId,
                playerName = player.playerName,
                money = player.money,
                currentTile = player.currentTileIndex,
                isInJail = player.isInJail,
                jailTurns = player.jailTurnsRemaining,
                hasJailCard = player.hasGetOutOfJailCard,
                totalWealth = player.GetTotalWealth()
            };

            var stats = new PlayerStatsData
            {
                propertyCount = player.ownedProperties.Count,
                isBankrupt = player.IsBankrupt()
            };

            var propIndices = new PropertySaveData
            {
                ownedIndices = new List<int>(player.ownedPropertyIndices)
            };

            var itemsSave = new ItemsSaveData();
            foreach (var item in player.heldItems)
                itemsSave.items.Add(new ItemSaveEntry
                {
                    itemName = item.itemName,
                    description = item.description,
                    type = (int)item.type
                });

            // ── Write to Cloud Save ───────────────────────────────────────
            var data = new Dictionary<string, object>
            {
                { KEY_PLAYER_PROFILE, JsonUtility.ToJson(profile)    },
                { KEY_GAME_STATS,     JsonUtility.ToJson(stats)       },
                { KEY_PROPERTIES,     JsonUtility.ToJson(propIndices) },
                { KEY_ITEMS,          JsonUtility.ToJson(itemsSave)   }
            };

            await CloudSaveService.Instance.Data.Player.SaveAsync(data);
            Debug.Log($"[CloudSave] ✓ Saved data for '{player.playerName}'");
        }
        catch (CloudSaveException e)
        {
            Debug.LogError($"[CloudSave] Save failed: {e.Message}");
        }
        catch (Exception e)
        {
            Debug.LogError($"[CloudSave] Unexpected error during save: {e.Message}");
        }
    }

    // =========================================================================
    // LOAD
    // =========================================================================

    /// <summary>
    /// Loads cloud data and applies it to an existing PlayerData object.
    /// Call this: after auth login, before game starts.
    /// Returns true if data was found and applied.
    /// </summary>
    public async Task<bool> LoadPlayerDataAsync(PlayerData player)
    {
        if (!AuthenticationService.Instance.IsSignedIn)
        {
            Debug.LogWarning("[CloudSave] Not signed in — skipping load.");
            return false;
        }

        try
        {
            var keys = new HashSet<string>
            {
                KEY_PLAYER_PROFILE,
                KEY_GAME_STATS,
                KEY_PROPERTIES,
                KEY_ITEMS
            };

            var results = await CloudSaveService.Instance.Data.Player.LoadAsync(keys);

            if (results == null || results.Count == 0)
            {
                Debug.Log("[CloudSave] No existing save data found — using defaults.");
                return false;
            }

            // ── Apply profile ─────────────────────────────────────────────
            if (results.TryGetValue(KEY_PLAYER_PROFILE, out var profileEntry))
            {
                var profile = JsonUtility.FromJson<PlayerProfileData>(profileEntry.Value.GetAsString());
                player.money = profile.money;
                player.currentTileIndex = profile.currentTile;
                player.isInJail = profile.isInJail;
                player.jailTurnsRemaining = profile.jailTurns;
                player.hasGetOutOfJailCard = profile.hasJailCard;
                Debug.Log($"[CloudSave] ✓ Loaded profile — Money: {profile.money} | Tile: {profile.currentTile}");
            }

            // ── Apply property indices ────────────────────────────────────
            if (results.TryGetValue(KEY_PROPERTIES, out var propEntry))
            {
                var propData = JsonUtility.FromJson<PropertySaveData>(propEntry.Value.GetAsString());
                player.ownedPropertyIndices = propData.ownedIndices ?? new List<int>();
                Debug.Log($"[CloudSave] ✓ Loaded {player.ownedPropertyIndices.Count} property indices");
            }

            // ── Apply items ───────────────────────────────────────────────
            if (results.TryGetValue(KEY_ITEMS, out var itemsEntry))
            {
                var itemsData = JsonUtility.FromJson<ItemsSaveData>(itemsEntry.Value.GetAsString());
                player.heldItems.Clear();
                foreach (var entry in itemsData.items)
                    player.heldItems.Add(new ItemData(entry.itemName, entry.description, (ItemType)entry.type));
                Debug.Log($"[CloudSave] ✓ Loaded {player.heldItems.Count} items");
            }

            return true;
        }
        catch (CloudSaveException e)
        {
            Debug.LogError($"[CloudSave] Load failed: {e.Message}");
            return false;
        }
        catch (Exception e)
        {
            Debug.LogError($"[CloudSave] Unexpected error during load: {e.Message}");
            return false;
        }
    }

    // =========================================================================
    // SAVE QUICK — single field (e.g. just money after a transaction)
    // =========================================================================

    /// <summary>
    /// Lightweight save of only the player profile (money, tile, jail state).
    /// Use this after every turn instead of the full save to reduce API calls.
    /// </summary>
    public async Task SaveProfileOnlyAsync(PlayerData player)
    {
        if (!AuthenticationService.Instance.IsSignedIn) return;

        try
        {
            var profile = new PlayerProfileData
            {
                playerId = player.playerId,
                playerName = player.playerName,
                money = player.money,
                currentTile = player.currentTileIndex,
                isInJail = player.isInJail,
                jailTurns = player.jailTurnsRemaining,
                hasJailCard = player.hasGetOutOfJailCard,
                totalWealth = player.GetTotalWealth()
            };

            var data = new Dictionary<string, object>
            {
                { KEY_PLAYER_PROFILE, JsonUtility.ToJson(profile) }
            };

            await CloudSaveService.Instance.Data.Player.SaveAsync(data);
            Debug.Log($"[CloudSave] ✓ Quick-saved profile for '{player.playerName}'");
        }
        catch (Exception e)
        {
            Debug.LogError($"[CloudSave] Quick-save failed: {e.Message}");
        }
    }

    /// <summary>
    /// Saves only the properties list (call after buy/sell).
    /// </summary>
    public async Task SavePropertiesOnlyAsync(PlayerData player)
    {
        if (!AuthenticationService.Instance.IsSignedIn) return;

        try
        {
            var propData = new PropertySaveData
            {
                ownedIndices = new List<int>(player.ownedPropertyIndices)
            };

            var data = new Dictionary<string, object>
            {
                { KEY_PROPERTIES, JsonUtility.ToJson(propData) }
            };

            await CloudSaveService.Instance.Data.Player.SaveAsync(data);
            Debug.Log($"[CloudSave] ✓ Saved properties for '{player.playerName}'");
        }
        catch (Exception e)
        {
            Debug.LogError($"[CloudSave] Properties save failed: {e.Message}");
        }
    }

    // =========================================================================
    // DELETE (reset save)
    // =========================================================================

    public async Task DeleteSaveDataAsync()
    {
        if (!AuthenticationService.Instance.IsSignedIn) return;

        try
        {
            var keys = new HashSet<string>
            {
                KEY_PLAYER_PROFILE,
                KEY_GAME_STATS,
                KEY_PROPERTIES,
                KEY_ITEMS
            };

            await CloudSaveService.Instance.Data.Player.DeleteAsync(KEY_PLAYER_PROFILE);
            await CloudSaveService.Instance.Data.Player.DeleteAsync(KEY_GAME_STATS);
            await CloudSaveService.Instance.Data.Player.DeleteAsync(KEY_PROPERTIES);
            await CloudSaveService.Instance.Data.Player.DeleteAsync(KEY_ITEMS);

            Debug.Log("[CloudSave] ✓ All save data deleted.");
        }
        catch (Exception e)
        {
            Debug.LogError($"[CloudSave] Delete failed: {e.Message}");
        }
    }
}

// =============================================================================
// SERIALISABLE DATA MODELS (internal to cloud save)
// =============================================================================

[Serializable]
public class PlayerProfileData
{
    public int playerId;
    public string playerName;
    public int money;
    public int currentTile;
    public bool isInJail;
    public int jailTurns;
    public bool hasJailCard;
    public int totalWealth;
}

[Serializable]
public class PlayerStatsData
{
    public int propertyCount;
    public bool isBankrupt;
}

[Serializable]
public class PropertySaveData
{
    public List<int> ownedIndices = new List<int>();
}

[Serializable]
public class ItemsSaveData
{
    public List<ItemSaveEntry> items = new List<ItemSaveEntry>();
}

[Serializable]
public class ItemSaveEntry
{
    public string itemName;
    public string description;
    public int type;
}