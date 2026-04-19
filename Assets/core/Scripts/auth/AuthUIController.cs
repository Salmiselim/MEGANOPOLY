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
        loginButton.onClick.AddListener(() => _ = OnLoginClicked());
        registerButton.onClick.AddListener(() => _ = OnRegisterClicked());

        if (resumePanel != null) resumePanel.SetActive(false);
        if (resumeButton != null) resumeButton.onClick.AddListener(OnResumeClicked);
        if (newGameButton != null) newGameButton.onClick.AddListener(OnNewGameClicked);

        SetLoading(false);
    }

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

        // ── Show resume prompt if cloud save exists ───────────────────────
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
        // PlayerDataApplier in Board scene will apply the cloud save
        PlayerPrefs.SetInt("ResumeCloudSave", 1);
        LoadNextScene();
    }

    private void OnNewGameClicked()
    {
        // Signal board scene to ignore cloud save and use fresh defaults
        PlayerPrefs.SetInt("ResumeCloudSave", 0);
        if (resumePanel != null) resumePanel.SetActive(false);
        LoadNextScene();
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private void LoadNextScene() => SceneManager.LoadScene(nextScene);

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
        loginButton.interactable = !state;
        registerButton.interactable = !state;
        if (loadingSpinner) loadingSpinner.SetActive(state);
        if (!state) return;
        feedbackText.text = "";
    }
}