using System.Threading.Tasks;
using UnityEngine;
using Unity.Services.Core;
using Unity.Services.Authentication;

/// <summary>
/// Handles Unity Authentication (username + password).
/// Also triggers cloud save load after successful login.
/// Attach to: AuthManager GameObject in AuthScene (DontDestroyOnLoad)
/// </summary>
public class AuthManager : MonoBehaviour
{
    public static AuthManager Instance { get; private set; }

    // Loaded from cloud after login — used in Board scene
    public PlayerProfileData LoadedProfile { get; private set; }
    public bool HasCloudSave { get; private set; } = false;

    private void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    private async void Start()
    {
        await InitializeUnityServices();
    }

    private async Task InitializeUnityServices()
    {
        try
        {
            await UnityServices.InitializeAsync();
            Debug.Log("[Auth] Unity Services initialized.");

            if (AuthenticationService.Instance.IsSignedIn)
                Debug.Log($"[Auth] Already signed in: {AuthenticationService.Instance.PlayerId}");
        }
        catch (System.Exception e)
        {
            Debug.LogError($"[Auth] Init failed: {e.Message}");
        }
    }

    // ── REGISTER ──────────────────────────────────────────────────────────────

    public async Task<bool> RegisterAsync(string username, string password)
    {
        try
        {
            await AuthenticationService.Instance.SignUpWithUsernamePasswordAsync(username, password);
            Debug.Log($"[Auth] Registered: {AuthenticationService.Instance.PlayerId}");

            // ── Immediately write default save so player appears in dashboard ──
            await CreateDefaultCloudSave(username);

            HasCloudSave = false; // new account — no prior progress to resume
            return true;
        }
        catch (AuthenticationException e)
        {
            Debug.LogError($"[Auth] Register failed [{e.ErrorCode}]: {e.Message}");
            return false;
        }
        catch (RequestFailedException e)
        {
            Debug.LogError($"[Auth] Request failed [{e.ErrorCode}]: {e.Message}");
            return false;
        }
    }

    // ── LOGIN ─────────────────────────────────────────────────────────────────

    public async Task<bool> LoginAsync(string username, string password)
    {
        try
        {
            await AuthenticationService.Instance.SignInWithUsernamePasswordAsync(username, password);
            Debug.Log($"[Auth] Logged in: {AuthenticationService.Instance.PlayerId}");

            // Load existing save, or create default one if this is a first login
            await TryLoadProfileFromCloud(username);
            return true;
        }
        catch (AuthenticationException e)
        {
            Debug.LogError($"[Auth] Login failed [{e.ErrorCode}]: {e.Message}");
            return false;
        }
        catch (RequestFailedException e)
        {
            Debug.LogError($"[Auth] Request failed [{e.ErrorCode}]: {e.Message}");
            return false;
        }
    }

    // ── Load profile summary after login ─────────────────────────────────────

    private async Task TryLoadProfileFromCloud(string username)
    {
        if (CloudSaveManager.Instance == null)
        {
            Debug.LogWarning("[Auth] CloudSaveManager not found — skipping cloud check.");
            return;
        }

        // Use a temporary PlayerData to probe the cloud
        var tempPlayer = new PlayerData(0, username, UnityEngine.Color.white);
        tempPlayer.unityPlayerId = AuthenticationService.Instance.PlayerId;

        bool found = await CloudSaveManager.Instance.LoadPlayerDataAsync(tempPlayer);

        if (found)
        {
            HasCloudSave = true;
            LoadedProfile = new PlayerProfileData
            {
                playerName = tempPlayer.playerName,
                money = tempPlayer.money,
                currentTile = tempPlayer.currentTileIndex,
                isInJail = tempPlayer.isInJail,
                totalWealth = tempPlayer.GetTotalWealth()
            };
            Debug.Log($"[Auth] Cloud save found — Money: {LoadedProfile.money} | Tile: {LoadedProfile.currentTile}");
        }
        else
        {
            // Account exists but no save yet (e.g. old account before this system)
            // Write defaults now so they appear in dashboard immediately
            Debug.Log("[Auth] No cloud save found — creating default save.");
            await CreateDefaultCloudSave(username);
            HasCloudSave = false;
        }
    }

    // ── Create default save ───────────────────────────────────────────────────

    /// <summary>
    /// Writes a fresh default PlayerData to the cloud immediately.
    /// Called on: Register (new account) + Login with no existing save.
    /// Makes the player visible in the Unity Dashboard right away with:
    /// money=1500, tile=0, no properties, no items.
    /// </summary>
    private async Task CreateDefaultCloudSave(string username)
    {
        if (CloudSaveManager.Instance == null)
        {
            Debug.LogWarning("[Auth] CloudSaveManager not found — cannot create default save.");
            return;
        }

        var defaultPlayer = new PlayerData(0, username, UnityEngine.Color.white);
        // PlayerData constructor already sets:
        //   money               = 1500
        //   currentTileIndex    = 0
        //   isInJail            = false
        //   ownedProperties     = empty list
        //   ownedPropertyIndices = empty list
        //   heldItems           = empty list
        defaultPlayer.unityPlayerId = AuthenticationService.Instance.PlayerId;

        await CloudSaveManager.Instance.SavePlayerDataAsync(defaultPlayer);
        Debug.Log($"[Auth] ✓ Default cloud save created for '{username}' " +
                  $"— Money: 1500 | Tile: 0 | Properties: 0 | Items: 0");
    }

    // ── SIGN OUT ──────────────────────────────────────────────────────────────

    public void SignOut()
    {
        AuthenticationService.Instance.SignOut();
        HasCloudSave = false;
        LoadedProfile = null;
        Debug.Log("[Auth] Signed out.");
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    public bool IsSignedIn => AuthenticationService.Instance.IsSignedIn;
    public string PlayerId => AuthenticationService.Instance.PlayerId;
    public string PlayerName => AuthenticationService.Instance.PlayerName;
}