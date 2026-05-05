using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.Netcode;
using UnityEngine.SceneManagement;

namespace Ghomidha
{
    /// <summary>
    /// Server-authoritative lobby manager for the Ghomidha minigame.
    ///
    /// SETUP IN UNITY EDITOR:
    ///   1. Create an empty GameObject "LobbyManager", add this script + NetworkObject component.
    ///   2. Wire all UI references in the Inspector.
    ///   3. Make sure a NetworkManager (with UnityTransport) exists in the scene.
    ///   4. Add a SimpleNetworkStarter (from RPS) with StartHost / StartClient buttons.
    ///
    /// FLOW:
    ///   Host starts  →  Client connects  →  Server detects 2 players
    ///   →  Randomly picks seeker  →  Sends AssignRolesClientRpc to all
    ///   →  Each client spins wheel  →  Shows role result panel
    ///   →  Host presses "Start Game"  →  All clients load game scene
    /// </summary>
    public class GhomidhaLobbyManager : NetworkBehaviour
    {
        // ── Inspector References ────────────────────────────────────────────

        [Header("Player Info UI")]
        [SerializeField] private TextMeshProUGUI player1IdText;
        [SerializeField] private TextMeshProUGUI player2IdText;

        [Header("Wheel")]
        [SerializeField] private WheelOfLuck wheelOfLuck;

        [Header("Status Text")]
        [Tooltip("Shown before spin: e.g. 'Waiting for players...' or 'Spinning!'")]
        [SerializeField] private TextMeshProUGUI statusText;

        [Header("Result Panel")]
        [Tooltip("The panel that is hidden until the wheel finishes spinning.")]
        [SerializeField] private GameObject resultPanel;
        [Tooltip("Shows the local player's role, e.g. 'You are: SEEKER'")]
        [SerializeField] private TextMeshProUGUI yourRoleText;
        [Tooltip("Shows the opponent's role, e.g. 'Opponent is: HIDER'")]
        [SerializeField] private TextMeshProUGUI opponentRoleText;

        [Header("Start Button (Host Only)")]
        [SerializeField] private Button startGameButton;

        [Header("Scene to Load")]
        [Tooltip("Exact name of the Ghomidha game scene to load after lobby.")]
        [SerializeField] private string ghomidhaGameScene = "GhomidhaNewEnvSetUpChanges";

        // ── Private State ───────────────────────────────────────────────────

        // Tracks all connected client IDs on the server
        private readonly List<ulong> _connectedClients = new();

        // ── Lifecycle ───────────────────────────────────────────────────────

        private void Awake()
        {
            // Ensure role manager singleton exists in this scene
            if (GhomidhaRoleManager.Instance == null)
            {
                var go = new GameObject("GhomidhaRoleManager");
                go.AddComponent<GhomidhaRoleManager>();
            }
        }

        public override void OnNetworkSpawn()
        {
            // Hide result panel and start button on spawn
            if (resultPanel != null) resultPanel.SetActive(false);
            if (startGameButton != null) startGameButton.gameObject.SetActive(false);

            UpdateStatus("Waiting for players...");

            if (IsServer)
            {
                NetworkManager.Singleton.OnClientConnectedCallback  += OnClientConnected;
                NetworkManager.Singleton.OnClientDisconnectCallback += OnClientDisconnected;

                // Host is already connected as client 0 — register them
                RegisterClient(NetworkManager.Singleton.LocalClientId);
            }
        }

        public override void OnNetworkDespawn()
        {
            if (IsServer && NetworkManager.Singleton != null)
            {
                NetworkManager.Singleton.OnClientConnectedCallback  -= OnClientConnected;
                NetworkManager.Singleton.OnClientDisconnectCallback -= OnClientDisconnected;
            }
        }

        // ── Server: Connection Handling ─────────────────────────────────────

        private void OnClientConnected(ulong clientId)
        {
            RegisterClient(clientId);
        }

        private void OnClientDisconnected(ulong clientId)
        {
            _connectedClients.Remove(clientId);
            UpdatePlayerDisplayClientRpc(
                _connectedClients.Count > 0 ? $"Player 1: {_connectedClients[0]}" : "Player 1: ---",
                _connectedClients.Count > 1 ? $"Player 2: {_connectedClients[1]}" : "Player 2: ---"
            );
        }

        private void RegisterClient(ulong clientId)
        {
            if (!_connectedClients.Contains(clientId))
                _connectedClients.Add(clientId);

            Debug.Log($"[GhomidhaLobbyManager] Player {clientId} connected. Total: {_connectedClients.Count}");

            // Update the displayed player IDs on all clients
            UpdatePlayerDisplayClientRpc(
                _connectedClients.Count > 0 ? $"Player 1: {_connectedClients[0]}" : "Player 1: ---",
                _connectedClients.Count > 1 ? $"Player 2: {_connectedClients[1]}" : "Player 2: ---"
            );

            // Once we have exactly 2 players, assign roles
            if (_connectedClients.Count == 2)
            {
                AssignRoles();
            }
        }

        // ── Server: Role Assignment ─────────────────────────────────────────

        private void AssignRoles()
        {
            // Pick seeker randomly from the two connected clients
            int seekerIndex = Random.Range(0, _connectedClients.Count);
            ulong seekerClientId = _connectedClients[seekerIndex];

            Debug.Log($"[GhomidhaLobbyManager] Seeker assigned to client {seekerClientId}");

            // Broadcast to all clients
            AssignRolesClientRpc(seekerClientId);
        }

        // ── ClientRpc: Role Reveal ──────────────────────────────────────────

        [ClientRpc]
        private void AssignRolesClientRpc(ulong seekerClientId)
        {
            bool iAmSeeker = NetworkManager.Singleton.LocalClientId == seekerClientId;

            // Store role in the persistent singleton so the game scene can read it
            GhomidhaRoleManager.Instance.SetRole(iAmSeeker);

            UpdateStatus("Spinning...");

            // Trigger the wheel spin — result is already decided server-side
            if (wheelOfLuck != null)
            {
                wheelOfLuck.Spin(localPlayerIsSeeker: iAmSeeker, onComplete: () => OnSpinComplete(iAmSeeker));
            }
            else
            {
                // No wheel assigned — skip straight to result
                OnSpinComplete(iAmSeeker);
            }
        }

        // ── Local: After Spin ───────────────────────────────────────────────

        private void OnSpinComplete(bool iAmSeeker)
        {
            UpdateStatus(iAmSeeker ? "You are the SEEKER!" : "You are the HIDER!");

            // Show result panel
            if (resultPanel != null) resultPanel.SetActive(true);

            if (yourRoleText != null)
                yourRoleText.text    = iAmSeeker ? "You are:\nSEEKER" : "You are:\nHIDER";

            if (opponentRoleText != null)
                opponentRoleText.text = iAmSeeker ? "Opponent is:\nHIDER" : "Opponent is:\nSEEKER";

            // Only the host gets the "Start Game" button
            if (IsHost && startGameButton != null)
            {
                startGameButton.gameObject.SetActive(true);
                startGameButton.onClick.RemoveAllListeners();
                startGameButton.onClick.AddListener(OnStartGameClicked);
            }
        }

        // ── Host: Start Game ────────────────────────────────────────────────

        private void OnStartGameClicked()
        {
            if (!IsHost) return;
            // Use NetworkManager's scene manager — this loads the scene on ALL clients
            // and ensures NetworkObjects in the new scene are properly spawned/synced.
            Debug.Log($"[GhomidhaLobbyManager] Loading game scene via NetworkManager: {ghomidhaGameScene}");
            NetworkManager.SceneManager.LoadScene(ghomidhaGameScene, LoadSceneMode.Single);
        }

        // ── Helpers ─────────────────────────────────────────────────────────

        private void UpdateStatus(string message)
        {
            if (statusText != null) statusText.text = message;
        }

        [ClientRpc]
        private void UpdatePlayerDisplayClientRpc(string p1Text, string p2Text)
        {
            if (player1IdText != null) player1IdText.text = p1Text;
            if (player2IdText != null) player2IdText.text = p2Text;
        }
    }
}
