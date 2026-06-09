using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using TMPro;
using Unity.Netcode;
using Unity.Netcode.Transports.UTP;
using Unity.Networking.Transport.Relay;
using Unity.Services.Authentication;
using Unity.Services.Core;
using Unity.Services.Lobbies;
using Unity.Services.Lobbies.Models;
using Unity.Services.Relay;
using Unity.Services.Relay.Models;
using UnityEngine;

namespace RockPaperScissors
{
    /// <summary>
    /// Handles relay host / client connection with automatic room discovery via Unity Lobby.
    ///
    /// HOST  — presses Start Host:
    ///   1. Creates a Relay allocation (1 extra connection slot).
    ///   2. Stores the relay join code inside a Unity Lobby so the client can
    ///      find it without any manual copy-paste.
    ///   3. Starts NetworkManager as Host.
    ///
    /// CLIENT — presses Start Client:
    ///   1. Queries Unity Lobby for an available RPS session.
    ///   2. Reads the relay join code from the lobby's custom data.
    ///   3. Joins the relay allocation and starts NetworkManager as Client.
    ///
    /// No join-code input field needed. Both players just press their button.
    /// </summary>
    public class RPSRelayNetworkStarter : MonoBehaviour
    {
        // ── Inspector ─────────────────────────────────────────────────────────

        [Header("Relay")]
        [Tooltip("Max extra connections (1 = host + 1 client = 2 players total).")]
        [SerializeField] private int maxConnections = 1;

        [Tooltip("Relay region (null = automatic best region).")]
        [SerializeField] private string region = null;

        [Header("UI")]
        [Tooltip("Optional text that shows connection status to the player.")]
        [SerializeField] private TextMeshProUGUI statusText;

        [Header("Lobby Settings")]
        [Tooltip("Tag stored in the lobby so the client only finds RPS sessions and " +
                 "never accidentally joins another game on the same UGS project.")]
        [SerializeField] private string lobbyGameTag = "RPS_SESSION";

        [Tooltip("How many times the client retries the lobby query before giving up " +
                 "(2 s between each attempt).")]
        [SerializeField] private int clientRetries = 5;

        // ── Private state ─────────────────────────────────────────────────────

        private bool   _ugsReady;
        private Lobby  _currentLobby;
        private Coroutine _heartbeatRoutine;

        private const string RelayCodeKey = "RelayCode";
        private const string GameTypeKey  = "GameType";

        // ── Unity lifecycle ───────────────────────────────────────────────────

        private void OnDestroy()
        {
            if (_heartbeatRoutine != null)
                StopCoroutine(_heartbeatRoutine);

            // Delete the lobby when the host leaves so stale rooms don't pile up.
            if (_currentLobby != null &&
                NetworkManager.Singleton != null &&
                NetworkManager.Singleton.IsHost)
            {
                LobbyService.Instance?.DeleteLobbyAsync(_currentLobby.Id);
            }
        }

        // ── Public buttons ────────────────────────────────────────────────────

        public async void StartRelayHost()
        {
            try
            {
                SetStatus("Getting ready...");
                await EnsureUGSAsync();

                // ── Step 1: Relay allocation ──────────────────────────────────
                SetStatus("Setting up your match...");
                var allocation = await RelayService.Instance
                    .CreateAllocationAsync(maxConnections, region);
                var joinCode   = await RelayService.Instance
                    .GetJoinCodeAsync(allocation.AllocationId);

                // ── Step 2: Unity Lobby (join code hidden inside) ─────────────
                SetStatus("Creating match room...");
                var options = new CreateLobbyOptions
                {
                    IsPrivate = false,
                    Data = new Dictionary<string, DataObject>
                    {
                        // Join code — public so the client can read it.
                        {
                            RelayCodeKey,
                            new DataObject(DataObject.VisibilityOptions.Public, joinCode)
                        },
                        // Game type tag — indexed (S1) so the client can filter by it.
                        {
                            GameTypeKey,
                            new DataObject(DataObject.VisibilityOptions.Public,
                                lobbyGameTag, DataObject.IndexOptions.S1)
                        }
                    }
                };
                _currentLobby = await LobbyService.Instance
                    .CreateLobbyAsync("RPS Game", 2, options);

                // ── Step 3: Keep lobby alive ──────────────────────────────────
                _heartbeatRoutine = StartCoroutine(LobbyHeartbeat(_currentLobby.Id));

                // ── Step 4: Start host ────────────────────────────────────────
                var transport = NetworkManager.Singleton.GetComponent<UnityTransport>();
                transport.SetRelayServerData(BuildHostRelayData(allocation));
                NetworkManager.Singleton.StartHost();

                SetStatus("Match room ready!\nWaiting for your opponent to join...");
                Debug.Log($"[Relay] Host up. LobbyId={_currentLobby.Id}  Code={joinCode}");
            }
            catch (Exception e)
            {
                SetStatus($"Host failed: {e.Message}");
                Debug.LogError($"[Relay] StartRelayHost: {e}");
            }
        }

        public async void StartRelayClient()
        {
            try
            {
                SetStatus("Getting ready...");
                await EnsureUGSAsync();

                // ── Step 1: Find the lobby ────────────────────────────────────
                var queryOptions = new QueryLobbiesOptions
                {
                    Count = 5,
                    Filters = new List<QueryFilter>
                    {
                        // Only RPS sessions.
                        new QueryFilter(QueryFilter.FieldOptions.S1,
                            lobbyGameTag, QueryFilter.OpOptions.EQ),
                        // At least one free slot.
                        new QueryFilter(QueryFilter.FieldOptions.AvailableSlots,
                            "0", QueryFilter.OpOptions.GT)
                    }
                };

                QueryResponse results = null;
                int attempts = clientRetries;

                while (attempts > 0)
                {
                    SetStatus(attempts == clientRetries
                        ? "Looking for a match..."
                        : $"Still searching... ({attempts} attempts left)");

                    results = await LobbyService.Instance.QueryLobbiesAsync(queryOptions);
                    if (results.Results.Count > 0) break;

                    attempts--;
                    if (attempts > 0)
                        await Task.Delay(2000);
                }

                if (results == null || results.Results.Count == 0)
                {
                    SetStatus("No match found.\nAsk your opponent to create one first!");
                    return;
                }

                // ── Step 2: Join lobby and read the hidden relay code ─────────
                SetStatus("Opponent found! Joining match...");
                var lobby    = await LobbyService.Instance
                    .JoinLobbyByIdAsync(results.Results[0].Id);
                string code  = lobby.Data[RelayCodeKey].Value;

                // ── Step 3: Join relay ────────────────────────────────────────
                SetStatus("Connecting...");
                var joinAlloc = await RelayService.Instance.JoinAllocationAsync(code);

                var transport = NetworkManager.Singleton.GetComponent<UnityTransport>();
                transport.SetRelayServerData(BuildClientRelayData(joinAlloc));
                NetworkManager.Singleton.StartClient();

                SetStatus("Almost there...");
                Debug.Log($"[Relay] Client joined. RelayCode={code}");
            }
            catch (Exception e)
            {
                SetStatus($"Join failed: {e.Message}");
                Debug.LogError($"[Relay] StartRelayClient: {e}");
            }
        }

        // ── Lobby heartbeat ───────────────────────────────────────────────────

        /// Unity Lobby expires after 30 s without a ping — send one every 15 s.
        private IEnumerator LobbyHeartbeat(string lobbyId)
        {
            var wait = new WaitForSeconds(15f);
            while (true)
            {
                yield return wait;
                try { LobbyService.Instance.SendHeartbeatPingAsync(lobbyId); }
                catch { /* session already gone — stop worrying */ }
            }
        }

        // ── UGS init ──────────────────────────────────────────────────────────

        private async Task EnsureUGSAsync()
        {
            if (_ugsReady) return;

            if (UnityServices.State == ServicesInitializationState.Uninitialized)
                await UnityServices.InitializeAsync();

            if (!AuthenticationService.Instance.IsSignedIn)
                await AuthenticationService.Instance.SignInAnonymouslyAsync();

            _ugsReady = true;
        }

        // ── Status text ───────────────────────────────────────────────────────

        private void SetStatus(string msg)
        {
            Debug.Log($"[Relay] {msg}");
            if (statusText != null) statusText.text = msg;
        }

        // ── Relay server data builders ────────────────────────────────────────

        private static RelayServerData BuildHostRelayData(Allocation a)
        {
            var ep = a.ServerEndpoints.First(e => e.ConnectionType == "dtls");
            return new RelayServerData(ep.Host, (ushort)ep.Port,
                a.AllocationIdBytes, a.ConnectionData,
                a.ConnectionData,   // host uses its own connection data for both fields
                a.Key, isSecure: true);
        }

        private static RelayServerData BuildClientRelayData(JoinAllocation a)
        {
            var ep = a.ServerEndpoints.First(e => e.ConnectionType == "dtls");
            return new RelayServerData(ep.Host, (ushort)ep.Port,
                a.AllocationIdBytes, a.ConnectionData,
                a.HostConnectionData, // client uses the host's connection data here
                a.Key, isSecure: true);
        }
    }
}
