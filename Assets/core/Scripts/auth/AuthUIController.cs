using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.SceneManagement;

/// <summary>
/// Controls the Auth scene UI — login, register, and cloud save resume prompt.
/// Attach to: Panel_Auth in AuthScene
/// </summary>
public class AuthUIController : MonoBehaviour
{
    [Header("Input Fields")]
    public TMP_InputField usernameInput;
    public TMP_InputField passwordInput;

    [Header("Buttons")]
    public Button loginButton;
    public Button registerButton;

    [Header("Feedback")]
    public TMP_Text feedbackText;
    public GameObject loadingSpinner;

    [Header("Resume Panel (optional)")]
    [Tooltip("Panel shown when a cloud save is detected after login")]
    public GameObject resumePanel;
    public TMP_Text resumeSummaryText;
    public Button resumeButton;
    public Button newGameButton;

    [Header("Scene")]
    public string nextScene = "Lobby";

    private void Start()
    {
        if (loginButton != null)
            loginButton.onClick.AddListener(() => _ = OnLoginClicked());
        else
            Debug.LogError("[AuthUI] loginButton is not assigned in the Inspector!", this);

        if (registerButton != null)
            registerButton.onClick.AddListener(() => _ = OnRegisterClicked());
        else
            Debug.LogError("[AuthUI] registerButton is not assigned in the Inspector!", this);

        if (resumePanel != null) resumePanel.SetActive(false);
        if (resumeButton != null) resumeButton.onClick.AddListener(OnResumeClicked);
        if (newGameButton != null) newGameButton.onClick.AddListener(OnNewGameClicked);

        SetLoading(false);
    }

    // ── XR Ray Wrappers ───────────────────────────────────────────────────────
    // Wire these to XRSimpleInteractable → Select Entered on each button GO.
    // XR events require public void — async Task cannot be wired in Inspector.

    /// <summary>XR Simple Interactable → Select Entered → Login button</summary>
    public void LoginButtonPressed() => _ = OnLoginClicked();

    /// <summary>XR Simple Interactable → Select Entered → Register button</summary>
    public void RegisterButtonPressed() => _ = OnRegisterClicked();

    /// <summary>XR Simple Interactable → Select Entered → Resume button</summary>
    public void ResumeButtonPressed() => OnResumeClicked();

    /// <summary>XR Simple Interactable → Select Entered → New Game button</summary>
    public void NewGameButtonPressed() => OnNewGameClicked();

    // ── Login ─────────────────────────────────────────────────────────────────

    private async Task OnLoginClicked()
    {
        if (!ValidateInputs()) return;
        SetLoading(true);

        bool success = await AuthManager.Instance.LoginAsync(
            usernameInput.text.Trim(),
            passwordInput.text
        );

        SetLoading(false);

        if (!success) { feedbackText.text = "Login failed. Check your credentials."; return; }

        feedbackText.text = "Login successful!";

        if (AuthManager.Instance.HasCloudSave && resumePanel != null)
        {
            ShowResumePanel();
        }
        else
        {
            await Task.Delay(400);
            LoadNextScene();
        }
    }

    // ── Register ──────────────────────────────────────────────────────────────

    private async Task OnRegisterClicked()
    {
        if (!ValidateInputs()) return;
        SetLoading(true);

        bool success = await AuthManager.Instance.RegisterAsync(
            usernameInput.text.Trim(),
            passwordInput.text
        );

        SetLoading(false);

        if (!success) { feedbackText.text = "Registration failed. Username may already exist."; return; }

        feedbackText.text = "Account created!";
        await Task.Delay(400);
        LoadNextScene();
    }

    // ── Resume panel ──────────────────────────────────────────────────────────

    private void ShowResumePanel()
    {
        if (resumePanel == null) { LoadNextScene(); return; }

        var profile = AuthManager.Instance.LoadedProfile;
        if (resumeSummaryText != null && profile != null)
        {
            resumeSummaryText.text =
                $"Welcome back!\n\n" +
                $"💰 Money: {profile.money} DT\n" +
                $"📍 Tile: {profile.currentTile}\n" +
                $"🏠 Wealth: {profile.totalWealth} DT\n" +
                $"{(profile.isInJail ? "🔒 In Jail" : "")}";
        }

        resumePanel.SetActive(true);
    }

    private void OnResumeClicked()
    {
        PlayerPrefs.SetInt("ResumeCloudSave", 1);
        LoadNextScene();
    }

    private void OnNewGameClicked()
    {
        PlayerPrefs.SetInt("ResumeCloudSave", 0);
        if (resumePanel != null) resumePanel.SetActive(false);
        LoadNextScene();
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private void LoadNextScene()
    {
        if (string.IsNullOrEmpty(nextScene))
        {
            Debug.LogError("[AuthUI] nextScene is empty — set it in the Inspector.");
            return;
        }
        Debug.Log($"[AuthUI] Loading scene: {nextScene}");
        SceneManager.LoadScene(nextScene);
    }

    private bool ValidateInputs()
    {
        if (string.IsNullOrWhiteSpace(usernameInput.text) ||
            string.IsNullOrWhiteSpace(passwordInput.text))
        { feedbackText.text = "Username and password cannot be empty."; return false; }

        if (passwordInput.text.Length < 8)
        { feedbackText.text = "Password must be at least 8 characters."; return false; }

        return true;
    }

    private void SetLoading(bool state)
    {
        if (loginButton != null) loginButton.interactable = !state;
        if (registerButton != null) registerButton.interactable = !state;
        if (loadingSpinner) loadingSpinner.SetActive(state);
        if (!state) return;
        if (feedbackText != null) feedbackText.text = "";
    }
}