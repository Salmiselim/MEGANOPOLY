using System.Threading.Tasks;
using UnityEngine;
using Unity.Services.Core;
using Unity.Services.Authentication;

public class AuthManager : MonoBehaviour
{
    public static AuthManager Instance { get; private set; }

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
            Debug.Log("Unity Services initialized.");

            // Auto sign-in if already cached
            if (AuthenticationService.Instance.IsSignedIn)
                Debug.Log($"Already signed in as: {AuthenticationService.Instance.PlayerId}");
        }
        catch (System.Exception e)
        {
            Debug.LogError($"Unity Services init failed: {e.Message}");
        }
    }

    // ── REGISTER ──────────────────────────────────────────────
    public async Task<bool> RegisterAsync(string username, string password)
    {
        try
        {
            await AuthenticationService.Instance.SignUpWithUsernamePasswordAsync(username, password);
            Debug.Log($"Registered & signed in: {AuthenticationService.Instance.PlayerId}");
            return true;
        }
        catch (AuthenticationException e)
        {
            Debug.LogError($"Register failed [{e.ErrorCode}]: {e.Message}");
            return false;
        }
        catch (RequestFailedException e)
        {
            Debug.LogError($"Request failed [{e.ErrorCode}]: {e.Message}");
            return false;
        }
    }

    // ── LOGIN ─────────────────────────────────────────────────
    public async Task<bool> LoginAsync(string username, string password)
    {
        try
        {
            await AuthenticationService.Instance.SignInWithUsernamePasswordAsync(username, password);
            Debug.Log($"Logged in: {AuthenticationService.Instance.PlayerId}");
            return true;
        }
        catch (AuthenticationException e)
        {
            Debug.LogError($"Login failed [{e.ErrorCode}]: {e.Message}");
            return false;
        }
        catch (RequestFailedException e)
        {
            Debug.LogError($"Request failed [{e.ErrorCode}]: {e.Message}");
            return false;
        }
    }

    // ── SIGN OUT ──────────────────────────────────────────────
    public void SignOut()
    {
        AuthenticationService.Instance.SignOut();
        Debug.Log("Signed out.");
    }

    // ── HELPERS ───────────────────────────────────────────────
    public bool IsSignedIn => AuthenticationService.Instance.IsSignedIn;
    public string PlayerId => AuthenticationService.Instance.PlayerId;
    public string PlayerName => AuthenticationService.Instance.PlayerName;
}