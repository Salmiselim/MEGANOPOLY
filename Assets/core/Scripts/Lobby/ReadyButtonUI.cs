using UnityEngine;
using XRMultiplayer;
using UnityEngine.UI;

public class ReadyButtonUI : MonoBehaviour
{
    [SerializeField] private VRButtonJuice buttonJuice;
    [SerializeField] private string readyText = "READY!";
    [SerializeField] private string notReadyText = "READY?";
    
    [Header("Color/Material Settings")]
    [SerializeField] private Color readyColor = Color.green;
    [SerializeField] private Color notReadyColor = Color.red;
    [SerializeField] private Material readyMaterial; // Optional: use this for 3D buttons
    [SerializeField] private Material notReadyMaterial; // Optional: use this for 3D buttons
    [SerializeField] private Graphic targetGraphic; // For UI buttons
    [SerializeField] private Renderer targetRenderer; // For 3D buttons

    private void Start()
    {
        if (buttonJuice == null) buttonJuice = GetComponent<VRButtonJuice>();
        
        // Automatically hook up the click event for XR interactables
        var interactable = GetComponent<UnityEngine.XR.Interaction.Toolkit.Interactables.XRBaseInteractable>();
        if (interactable != null)
        {
            interactable.selectEntered.AddListener((args) => ToggleLocalPlayerReady());
        }

        // Also hook up standard UI Buttons
        var uiButton = GetComponent<Button>();
        if (uiButton != null)
        {
            uiButton.onClick.AddListener(ToggleLocalPlayerReady);
        }

        if (XRINetworkPlayer.LocalPlayer != null)
        {
            InitializeReadyState(XRINetworkPlayer.LocalPlayer);
        }
        else
        {
            // If local player isn't spawned yet, wait for it
            if (XRINetworkGameManager.Instance != null)
            {
                XRINetworkGameManager.Instance.OnPlayerStateChanged += OnPlayerStateChanged;
            }
        }
    }

    private void OnPlayerStateChanged(ulong id, bool joined)
    {
        if (joined && XRINetworkPlayer.LocalPlayer != null && XRINetworkPlayer.LocalPlayer.NetworkObject.OwnerClientId == id)
        {
            InitializeReadyState(XRINetworkPlayer.LocalPlayer);
            XRINetworkGameManager.Instance.OnPlayerStateChanged -= OnPlayerStateChanged;
        }
    }

    private void InitializeReadyState(XRINetworkPlayer player)
    {
        player.onReadyUpdated += UpdateButtonText;
        UpdateButtonText(player.isReady.Value);
    }

    private void UpdateButtonText(bool isReady)
    {
        if (buttonJuice != null)
        {
            buttonJuice.SetText(isReady ? readyText : notReadyText);
        }

        // Apply color/material change
        if (targetGraphic != null)
        {
            targetGraphic.color = isReady ? readyColor : notReadyColor;
        }
        if (targetRenderer != null)
        {
            if (readyMaterial != null && notReadyMaterial != null)
            {
                targetRenderer.material = isReady ? readyMaterial : notReadyMaterial;
            }
            else
            {
                targetRenderer.material.color = isReady ? readyColor : notReadyColor;
            }
        }
    }

    public void ToggleLocalPlayerReady()
    {
        Debug.Log("[ReadyButtonUI] ToggleLocalPlayerReady clicked!");
        if (XRINetworkPlayer.LocalPlayer != null)
        {
            Debug.Log($"[ReadyButtonUI] Toggling ready state. Current state: {XRINetworkPlayer.LocalPlayer.isReady.Value}");
            XRINetworkPlayer.LocalPlayer.ToggleReady();
        }
        else
        {
            Debug.LogWarning("[ReadyButtonUI] LocalPlayer is NULL! Cannot toggle ready.");
        }
    }

    private void OnDestroy()
    {
        if (XRINetworkPlayer.LocalPlayer != null)
        {
            XRINetworkPlayer.LocalPlayer.onReadyUpdated -= UpdateButtonText;
        }
        if (XRINetworkGameManager.Instance != null)
        {
            XRINetworkGameManager.Instance.OnPlayerStateChanged -= OnPlayerStateChanged;
        }
    }
}
