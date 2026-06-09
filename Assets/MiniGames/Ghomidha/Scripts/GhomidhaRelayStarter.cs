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

namespace Ghomidha
{
    /// <summary>
    /// Relay + Unity Lobby connection starter for the Ghomidha lobby scene.
    /// Replaces SimpleNetworkStarter — wire the two public methods to your
    /// "Create Match" and "Find Match" buttons in the Inspector.
    ///
    /// Once the connection is established the existing GhomidhaLobbyManager
    /// takes over automatically (role assignment → wheel spin → start game).
    /// Nothing in GhomidhaLobbyManager needs to change.
    /// </summary>
    public class GhomidhaRelayStarter : MonoBehaviour
    {
        // ── Inspector ─────────────────────────────────────────────────────────

        [Header("UI")]
        [Tooltip("Text that shows connection status to the player.")]
        [SerializeField] private TextMeshProUGUI statusText;

        [Header("Lobby Settings")]
        [Tooltip("Tag stored in the lobby — prevents this client from accidentally " +
                 "joining an RPS or other game session on the same UGS project.")]
        [SerializeField] private string lobbyGameTag = "GHOMIDHA_SESSION";

        [Tooltip("How many times the client retries the lobby query (2 s between each).")]
        [SerializeField] private int clientRetries = 5;

        // ── Private state ─────────────────────────────────────────────────────

        private bool   _ugsReady;
        private Lobby  _currentLobby;
        private Coroutine _heartbeatRoutine;

        private const string RelayCodeKey = "RelayCode";
        private const string GameTypeKey  = "GameType";

        // ── Lifecycle ─────────────────────────────────────────────────────────

        private void OnDestroy()
        {
            if (_heartbeatRoutine != null)
                StopCoroutine(_heartbeatRoutine);

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
                SetStatus("Creating match...");
                await EnsureUGS();

                // Relay allocation
                var allocation = await RelayService.Instance.CreateAllocationAsync(1, null);
                var joinCode   = await RelayService.Instance.GetJoinCodeAsync(allocation.AllocationId);

                // Unity Lobby — join code stored silently as custom data
                var options = new CreateLobbyOptions
                {
                    IsPrivate = false,
                    Data = new Dictionary<string, DataObject>
                    {
                        {
                            RelayCodeKey,
                            new DataObject(DataObject.VisibilityOptions.Public, joinCode)
                        },
                        {
                            GameTypeKey,
                            new DataObject(DataObject.VisibilityOptions.Public,
                                lobbyGameTag, DataObject.IndexOptions.S1)
                        }
                    }
                };
                _currentLobby = await LobbyService.Instance.CreateLobbyAsync("Ghomidha Game", 2, options);

                _heartbeatRoutine = StartCoroutine(LobbyHeartbeat(_currentLobby.Id));

                // Start host
                var transport = NetworkManager.Singleton.GetComponent<UnityTransport>();
                transport.SetRelayServerData(BuildHostRelayData(allocation));
                NetworkManager.Singleton.StartHost();

                SetStatus("Waiting for your opponent...");
                Debug.Log($"[GhomidhaRelay] Host up. LobbyId={_currentLobby.Id}  Code={joinCode}");
            }
            catch (Exception e)
            {
                SetStatus("Couldn't create match. Please try again.");
                Debug.LogError($"[GhomidhaRelay] StartRelayHost: {e}");
            }
        }

        public async void StartRelayClient()
        {
            try
            {
                await EnsureUGS();

                // Query lobbies filtered by game tag
                var queryOptions = new QueryLobbiesOptions
                {
                    Count = 5,
                    Filters = new List<QueryFilter>
                    {
                        new QueryFilter(QueryFilter.FieldOptions.S1,
                            lobbyGameTag, QueryFilter.OpOptions.EQ),
                        new QueryFilter(QueryFilter.FieldOptions.AvailableSlots,
                            "0", QueryFilter.OpOptions.GT)
                    }
                };

                SetStatus("Looking for a match...");
                QueryResponse results = null;
                int attempts = clientRetries;

                while (attempts > 0)
                {
                    results = await LobbyService.Instance.QueryLobbiesAsync(queryOptions);
                    if (results.Results.Count > 0) break;

                    attempts--;
                    if (attempts > 0)
                    {
                        SetStatus("Still looking...");
                        await Task.Delay(2000);
                    }
                }

                if (results == null || results.Results.Count == 0)
                {
                    SetStatus("No match found.\nAsk your opponent to create one first!");
                    return;
                }

                // Join lobby, grab relay code
                SetStatus("Joining...");
                var lobby    = await LobbyService.Instance.JoinLobbyByIdAsync(results.Results[0].Id);
                string code  = lobby.Data[RelayCodeKey].Value;

                // Join relay, start client
                var joinAlloc = await RelayService.Instance.JoinAllocationAsync(code);
                var transport = NetworkManager.Singleton.GetComponent<UnityTransport>();
                transport.SetRelayServerData(BuildClientRelayData(joinAlloc));
                NetworkManager.Singleton.StartClient();

                Debug.Log($"[GhomidhaRelay] Client joined. RelayCode={code}");
            }
            catch (Exception e)
            {
                SetStatus("Couldn't join. Please try again.");
                Debug.LogError($"[GhomidhaRelay] StartRelayClient: {e}");
            }
        }

        // ── UGS init ──────────────────────────────────────────────────────────

        private async Task EnsureUGS()
        {
            if (_ugsReady) return;
            if (UnityServices.State == ServicesInitializationState.Uninitialized)
                await UnityServices.InitializeAsync();
            if (!AuthenticationService.Instance.IsSignedIn)
                await AuthenticationService.Instance.SignInAnonymouslyAsync();
            _ugsReady = true;
        }

        // ── Lobby heartbeat ───────────────────────────────────────────────────

        private IEnumerator LobbyHeartbeat(string lobbyId)
        {
            var wait = new WaitForSeconds(15f);
            while (true)
            {
                yield return wait;
                try { LobbyService.Instance.SendHeartbeatPingAsync(lobbyId); }
                catch { /* session already gone */ }
            }
        }

        // ── Status text ───────────────────────────────────────────────────────

        private void SetStatus(string msg)
        {
            Debug.Log($"[GhomidhaRelay] {msg}");
            if (statusText != null) statusText.text = msg;
        }

        // ── Relay data builders ───────────────────────────────────────────────

        private static RelayServerData BuildHostRelayData(Allocation a)
        {
            var ep = a.ServerEndpoints.First(e => e.ConnectionType == "dtls");
            return new RelayServerData(ep.Host, (ushort)ep.Port,
                a.AllocationIdBytes, a.ConnectionData,
                a.ConnectionData, a.Key, isSecure: true);
        }

        private static RelayServerData BuildClientRelayData(JoinAllocation a)
        {
            var ep = a.ServerEndpoints.First(e => e.ConnectionType == "dtls");
            return new RelayServerData(ep.Host, (ushort)ep.Port,
                a.AllocationIdBytes, a.ConnectionData,
                a.HostConnectionData, a.Key, isSecure: true);
        }
    }
}
