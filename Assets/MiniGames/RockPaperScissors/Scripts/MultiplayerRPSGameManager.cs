using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.Netcode;
using UnityEngine.Video;

namespace RockPaperScissors
{
    public class MultiplayerRPSGameManager : NetworkBehaviour
    {
        [Header("UI References")]
        [SerializeField] private Button rockButton;
        [SerializeField] private Button paperButton;
        [SerializeField] private Button scissorsButton;
        [SerializeField] private TextMeshProUGUI resultText;
        [SerializeField] private TextMeshProUGUI localPlayerChoiceText;
        [SerializeField] private TextMeshProUGUI opponentChoiceText;

        [Header("Video Setup (Optional)")]
        [SerializeField] private VideoPlayer backgroundVideo;

        public enum Choice
        {
            None = -1,
            Rock = 0,
            Paper = 1,
            Scissors = 2
        }

        // Server-side tracking
        private Dictionary<ulong, Choice> currentChoices = new Dictionary<ulong, Choice>();
        private bool isRoundActive = false;

        private void Start()
        {
            if (rockButton != null) rockButton.onClick.AddListener(() => OnChoiceSelected(Choice.Rock));
            if (paperButton != null) paperButton.onClick.AddListener(() => OnChoiceSelected(Choice.Paper));
            if (scissorsButton != null) scissorsButton.onClick.AddListener(() => OnChoiceSelected(Choice.Scissors));

            if (backgroundVideo != null)
            {
                backgroundVideo.isLooping = true;
                backgroundVideo.Play();
            }

            ResetUI();
        }

        public override void OnNetworkSpawn()
        {
            if (IsServer)
            {
                isRoundActive = true;
            }
            
            // Listen for players joining to log debug messages in console
            if (IsServer && NetworkManager.Singleton != null)
            {
                NetworkManager.Singleton.OnClientConnectedCallback += OnClientConnected;
            }
        }

        public override void OnNetworkDespawn()
        {
            if (IsServer && NetworkManager.Singleton != null)
            {
                NetworkManager.Singleton.OnClientConnectedCallback -= OnClientConnected;
            }
        }

        private void OnClientConnected(ulong clientId)
        {
            Debug.Log($"<color=cyan>[RPS Multiplayer]</color> Player {clientId} has entered the game!");
            if (clientId != NetworkManager.ServerClientId)
            {
                Debug.Log($"<color=green>[RPS Multiplayer]</color> PLAYER 2 (Client {clientId}) IS HERE! Game is ready.");
            }
        }

        private void OnChoiceSelected(Choice myChoice)
        {
            if (!IsClient) return;

            // Immediately update our own UI
            if (localPlayerChoiceText != null)
            {
                localPlayerChoiceText.text = $"You chose: {myChoice.ToString().ToUpper()}";
            }
            if (resultText != null)
            {
                resultText.text = "Waiting for opponent...";
                resultText.color = Color.yellow;
            }

            // Disable buttons so we don't spam
            SetButtonsInteractable(false);

            // Send choice to server
            SubmitChoiceServerRpc(myChoice);
        }

        [ServerRpc(RequireOwnership = false)]
        private void SubmitChoiceServerRpc(Choice choice, ServerRpcParams rpcParams = default)
        {
            if (!isRoundActive) return;

            ulong clientId = rpcParams.Receive.SenderClientId;
            
            // Record choice
            currentChoices[clientId] = choice;

            // Check if we have two players who made a choice
            // (Assuming exactly 2 players are playing)
            if (currentChoices.Count == 2)
            {
                isRoundActive = false;
                EvaluateWinner();
            }
        }

        private void EvaluateWinner()
        {
            List<ulong> clients = new List<ulong>(currentChoices.Keys);
            ulong player1 = clients[0];
            ulong player2 = clients[1];

            Choice p1Choice = currentChoices[player1];
            Choice p2Choice = currentChoices[player2];

            ulong winnerId = ulong.MaxValue; // Use max value to denote a tie
            
            if (p1Choice != p2Choice)
            {
                if ((p1Choice == Choice.Rock && p2Choice == Choice.Scissors) ||
                    (p1Choice == Choice.Paper && p2Choice == Choice.Rock) ||
                    (p1Choice == Choice.Scissors && p2Choice == Choice.Paper))
                {
                    winnerId = player1;
                }
                else
                {
                    winnerId = player2;
                }
            }

            // Broadcast results to all clients
            ShowResultsClientRpc(player1, p1Choice, player2, p2Choice, winnerId);

            // Start coroutine to reset next round
            StartCoroutine(RoundResetRoutine());
        }

        [ClientRpc]
        private void ShowResultsClientRpc(ulong p1Id, Choice p1Choice, ulong p2Id, Choice p2Choice, ulong winnerId)
        {
            ulong myId = NetworkManager.Singleton.LocalClientId;

            bool isPlayer1 = myId == p1Id;
            Choice myChoice = isPlayer1 ? p1Choice : p2Choice;
            Choice opponentChoice = isPlayer1 ? p2Choice : p1Choice;

            if (localPlayerChoiceText != null)
                localPlayerChoiceText.text = $"You chose: {myChoice.ToString().ToUpper()}";
            
            if (opponentChoiceText != null)
                opponentChoiceText.text = $"Opponent chose: {opponentChoice.ToString().ToUpper()}";

            if (resultText != null)
            {
                if (winnerId == ulong.MaxValue)
                {
                    resultText.text = "It's a TIE!";
                    resultText.color = Color.yellow;
                }
                else if (winnerId == myId)
                {
                    resultText.text = "YOU WIN!";
                    resultText.color = Color.green;
                }
                else
                {
                    resultText.text = "OPPONENT WINS!";
                    resultText.color = Color.red;
                }
            }
        }

        private IEnumerator RoundResetRoutine()
        {
            // Wait 4 seconds so players can see the result
            yield return new WaitForSeconds(4f);

            // Reset server state
            currentChoices.Clear();
            isRoundActive = true;

            // Tell clients to reset UI
            ResetRoundClientRpc();
        }

        [ClientRpc]
        private void ResetRoundClientRpc()
        {
            ResetUI();
            SetButtonsInteractable(true);
        }

        private void ResetUI()
        {
            if (resultText != null)
            {
                resultText.text = "Choose your move!";
                resultText.color = Color.white;
            }
            if (localPlayerChoiceText != null) localPlayerChoiceText.text = "Your choice: ?";
            if (opponentChoiceText != null) opponentChoiceText.text = "Opponent choice: ?";
        }

        private void SetButtonsInteractable(bool state)
        {
            if (rockButton != null) rockButton.interactable = state;
            if (paperButton != null) paperButton.interactable = state;
            if (scissorsButton != null) scissorsButton.interactable = state;
        }
    }
}
