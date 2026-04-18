using System;
using System.Linq;
using System.Threading.Tasks;
using TMPro;
using Unity.Netcode;
using Unity.Netcode.Transports.UTP;
using Unity.Networking.Transport.Relay;
using Unity.Services.Authentication;
using Unity.Services.Core;
using Unity.Services.Relay;
using Unity.Services.Relay.Models;
using UnityEngine;

namespace RockPaperScissors
{
    public class RPSRelayNetworkStarter : MonoBehaviour
    {
        [Header("Relay")]
        [SerializeField] private int maxConnections = 1; // 1 client joins host = 2 players total
        [SerializeField] private string region = null;   // null = best region

        [Header("UI (Optional)")]
        [SerializeField] private TMP_InputField joinCodeInput;
        [SerializeField] private TextMeshProUGUI statusText;
        [SerializeField] private TextMeshProUGUI joinCodeText;

        private bool _ugsReady;

        private void SetStatus(string msg)
        {
            Debug.Log($"[Relay] {msg}");
            if (statusText != null) statusText.text = msg;
        }

        private async Task EnsureUGSAsync()
        {
            if (_ugsReady) return;

            try
            {
                if (UnityServices.State == ServicesInitializationState.Uninitialized)
                    await UnityServices.InitializeAsync();

                if (!AuthenticationService.Instance.IsSignedIn)
                    await AuthenticationService.Instance.SignInAnonymouslyAsync();

                _ugsReady = true;
                SetStatus($"UGS ready. PlayerId: {AuthenticationService.Instance.PlayerId}");
            }
            catch (Exception e)
            {
                _ugsReady = false;
                SetStatus($"UGS init failed: {e.Message}");
                throw;
            }
        }

        public async void StartRelayHost()
        {
            try
            {
                await EnsureUGSAsync();

                var allocation = await RelayService.Instance.CreateAllocationAsync(maxConnections, region);
                var joinCode = await RelayService.Instance.GetJoinCodeAsync(allocation.AllocationId);

                if (joinCodeText != null) joinCodeText.text = joinCode;
                SetStatus($"Relay host ready. JoinCode: {joinCode}");

                var transport = NetworkManager.Singleton.GetComponent<UnityTransport>();
                if (transport == null)
                {
                    SetStatus("UnityTransport missing on NetworkManager.");
                    return;
                }

                transport.SetRelayServerData(BuildRelayServerData(allocation));

                NetworkManager.Singleton.StartHost();
                SetStatus($"Host started (Relay). JoinCode: {joinCode}");
            }
            catch (Exception e)
            {
                SetStatus($"StartRelayHost failed: {e.Message}");
                Debug.LogError($"[Relay] StartRelayHost failed: {e}");
            }
        }

        public async void StartRelayClient()
        {
            string joinCode = joinCodeInput != null ? joinCodeInput.text : null;
            if (string.IsNullOrWhiteSpace(joinCode))
            {
                SetStatus("Join code is empty.");
                return;
            }

            try
            {
                await EnsureUGSAsync();

                var joinAllocation = await RelayService.Instance.JoinAllocationAsync(joinCode.Trim());

                var transport = NetworkManager.Singleton.GetComponent<UnityTransport>();
                if (transport == null)
                {
                    SetStatus("UnityTransport missing on NetworkManager.");
                    return;
                }

                transport.SetRelayServerData(BuildRelayServerData(joinAllocation));

                NetworkManager.Singleton.StartClient();
                SetStatus("Client started (Relay).");
            }
            catch (Exception e)
            {
                SetStatus($"StartRelayClient failed: {e.Message}");
                Debug.LogError($"[Relay] StartRelayClient failed: {e}");
            }
        }

        private static RelayServerData BuildRelayServerData(Allocation allocation)
        {
            var endpoint = allocation.ServerEndpoints.First(e => e.ConnectionType == "dtls");
            return new RelayServerData(
                endpoint.Host, (ushort)endpoint.Port,
                allocation.AllocationIdBytes,
                allocation.ConnectionData,
                allocation.ConnectionData,
                allocation.Key,
                isSecure: true);
        }

        private static RelayServerData BuildRelayServerData(JoinAllocation allocation)
        {
            var endpoint = allocation.ServerEndpoints.First(e => e.ConnectionType == "dtls");
            return new RelayServerData(
                endpoint.Host, (ushort)endpoint.Port,
                allocation.AllocationIdBytes,
                allocation.ConnectionData,
                allocation.HostConnectionData,
                allocation.Key,
                isSecure: true);
        }
    }
}

