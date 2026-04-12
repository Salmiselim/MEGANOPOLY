using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.SceneManagement;

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

    [Header("Scene")]
    public string nextScene = "Lobby"; // your multiplayer scene

    private void Start()
    {
        loginButton.onClick.AddListener(() => _ = OnLoginClicked());
        registerButton.onClick.AddListener(() => _ = OnRegisterClicked());
        SetLoading(false);
    }

    private async Task OnLoginClicked()
    {
        if (!ValidateInputs()) return;
        SetLoading(true);

        bool success = await AuthManager.Instance.LoginAsync(
            usernameInput.text.Trim(),
            passwordInput.text
        );

        SetLoading(false);

        if (success)
        {
            feedbackText.text = "Login successful!";
            await Task.Delay(500);
            SceneManager.LoadScene(nextScene);
        }
        else
        {
            feedbackText.text = "Login failed. Check your credentials.";
        }
    }

    private async Task OnRegisterClicked()
    {
        if (!ValidateInputs()) return;
        SetLoading(true);

        bool success = await AuthManager.Instance.RegisterAsync(
            usernameInput.text.Trim(),
            passwordInput.text
        );

        SetLoading(false);

        feedbackText.text = success
            ? "Account created! You are now signed in."
            : "Registration failed. Username may already exist.";

        if (success)
        {
            await Task.Delay(800);
            SceneManager.LoadScene(nextScene);
        }
    }

    private bool ValidateInputs()
    {
        if (string.IsNullOrWhiteSpace(usernameInput.text) ||
            string.IsNullOrWhiteSpace(passwordInput.text))
        {
            feedbackText.text = "Username and password cannot be empty.";
            return false;
        }
        if (passwordInput.text.Length < 8)
        {
            feedbackText.text = "Password must be at least 8 characters.";
            return false;
        }
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