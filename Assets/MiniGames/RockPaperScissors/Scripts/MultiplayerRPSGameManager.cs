using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.Netcode;
using UnityEngine.Video;
using System;

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
        [SerializeField] private TextMeshProUGUI roundText;
        [SerializeField] private TextMeshProUGUI scoreText;

        [Header("Video Setup (Optional)")]
        [SerializeField] private VideoPlayer backgroundVideo;

        [Header("Match Settings")]
        [SerializeField] private int totalRounds = 3;

        [Header("Hand Gesture Input")]
        [SerializeField] private HandGestureInputBridge handGestureBridge;

        [Header("Sound")]
        [SerializeField] private RPSSoundManager soundManager;

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
        private int _roundsPlayed = 0;
        private Dictionary<ulong, int> _winsByClientId = new Dictionary<ulong, int>();

        // Client-side cache for UI + future leaderboard submit
        private int _localWins = 0;
        private int _opponentWins = 0;
        private int _clientRoundsPlayed = 0;
        private bool _clientMatchOver = false;

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
            UpdateRoundAndScoreUI(0, 0, 0, totalRounds);
        }

        public override void OnNetworkSpawn()
        {
            if (IsServer)
            {
                isRoundActive = true;
                _roundsPlayed = 0;
                _winsByClientId.Clear();
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

            // Initialize win counters on the server for each connected player.
            if (IsServer)
            {
                if (!_winsByClientId.ContainsKey(clientId))
                    _winsByClientId[clientId] = 0;
            }
        }

        /// <summary>Called by HandGestureInputBridge when player holds a hand gesture.</summary>
        public void SubmitChoiceFromHand(Choice myChoice)
        {
            OnChoiceSelected(myChoice);
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
            clients.Sort(); // deterministic ordering across rounds
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

            // Update match stats on server
            _roundsPlayed = Mathf.Clamp(_roundsPlayed + 1, 0, Math.Max(1, totalRounds));
            if (winnerId != ulong.MaxValue)
            {
                if (!_winsByClientId.ContainsKey(winnerId))
                    _winsByClientId[winnerId] = 0;
                _winsByClientId[winnerId] += 1;
            }

            int p1Wins = _winsByClientId.TryGetValue(player1, out var a) ? a : 0;
            int p2Wins = _winsByClientId.TryGetValue(player2, out var b) ? b : 0;
            bool matchOver = _roundsPlayed >= Math.Max(1, totalRounds);

            // Broadcast results to all clients
            ShowResultsClientRpc(player1, p1Choice, player2, p2Choice, winnerId, _roundsPlayed, totalRounds, p1Wins, p2Wins, matchOver);

            if (matchOver)
            {
                // Lock inputs and show final match result.
                MatchOverClientRpc(player1, player2, p1Wins, p2Wins, totalRounds);
            }
            else
            {
                // Start coroutine to reset next round
                StartCoroutine(RoundResetRoutine());
            }
        }

        [ClientRpc]
        private void ShowResultsClientRpc(ulong p1Id, Choice p1Choice, ulong p2Id, Choice p2Choice, ulong winnerId, int roundsPlayed, int roundsTotal, int p1Wins, int p2Wins, bool matchOver)
        {
            ulong myId = NetworkManager.Singleton.LocalClientId;

            bool isPlayer1 = myId == p1Id;
            Choice myChoice = isPlayer1 ? p1Choice : p2Choice;
            Choice opponentChoice = isPlayer1 ? p2Choice : p1Choice;

            if (localPlayerChoiceText != null)
                localPlayerChoiceText.text = $"You chose: {myChoice.ToString().ToUpper()}";
            
            if (opponentChoiceText != null)
                opponentChoiceText.text = $"Opponent chose: {opponentChoice.ToString().ToUpper()}";

            UpdateRoundAndScoreUI(myId, p1Id, p1Wins, p2Wins, roundsPlayed, roundsTotal);

            if (resultText != null)
            {
                int myWins = _localWins;
                int oppWins = _opponentWins;
                string header = $"Round {Mathf.Clamp(roundsPlayed, 0, Math.Max(1, roundsTotal))}/{Math.Max(1, roundsTotal)}  |  Score {myWins}-{oppWins}\n";

                if (winnerId == ulong.MaxValue)
                {
                    resultText.text = header + "It's a TIE!";
                    resultText.color = Color.yellow;
                    if (!matchOver) soundManager?.PlayRoundResult(false, true);
                }
                else if (winnerId == myId)
                {
                    resultText.text = header + "YOU WIN!";
                    resultText.color = Color.green;
                    if (!matchOver) soundManager?.PlayRoundResult(true, false);
                }
                else
                {
                    resultText.text = header + "OPPONENT WINS!";
                    resultText.color = Color.red;
                    if (!matchOver) soundManager?.PlayRoundResult(false, false);
                }

                if (matchOver)
                    resultText.text += "\nMATCH OVER";
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
            if (handGestureBridge != null)
                handGestureBridge.OnRoundReset();
        }

        [ClientRpc]
        private void MatchOverClientRpc(ulong p1Id, ulong p2Id, int p1Wins, int p2Wins, int roundsTotal)
        {
            ulong myId = NetworkManager.Singleton.LocalClientId;
            UpdateRoundAndScoreUI(myId, p1Id, p1Wins, p2Wins, roundsTotal, roundsTotal);

            SetButtonsInteractable(false);

            if (resultText != null)
            {
                bool isPlayer1 = myId == p1Id;
                int myWins = isPlayer1 ? p1Wins : p2Wins;
                int oppWins = isPlayer1 ? p2Wins : p1Wins;

                if (myWins == oppWins)
                {
                    resultText.text = $"FINAL: {myWins} - {oppWins}\nIT'S A TIE!";
                    resultText.color = Color.yellow;
                    soundManager?.PlayMatchResult(false, true);
                }
                else if (myWins > oppWins)
                {
                    resultText.text = $"FINAL: {myWins} - {oppWins}\nYOU WIN THE MATCH!";
                    resultText.color = Color.green;
                    soundManager?.PlayMatchResult(true, false);
                }
                else
                {
                    resultText.text = $"FINAL: {myWins} - {oppWins}\nYOU LOSE THE MATCH!";
                    resultText.color = Color.red;
                    soundManager?.PlayMatchResult(false, false);
                }
            }
        }

        private void ResetUI()
        {
            if (resultText != null)
            {
                int shownTotal = Math.Max(1, totalRounds);
                resultText.text = $"Round 0/{shownTotal}  |  Score 0-0\nChoose your move!";
                resultText.color = Color.white;
            }
            if (localPlayerChoiceText != null) localPlayerChoiceText.text = "Your choice: ?";
            if (opponentChoiceText != null) opponentChoiceText.text = "Opponent choice: ?";
        }

        private void UpdateRoundAndScoreUI(ulong myId, ulong p1Id, int p1Wins, int p2Wins, int roundsPlayed, int roundsTotal)
        {
            if (roundText != null)
            {
                int shownPlayed = Mathf.Clamp(roundsPlayed, 0, Math.Max(1, roundsTotal));
                int shownTotal = Math.Max(1, roundsTotal);
                roundText.text = $"Round: {shownPlayed}/{shownTotal}";
            }

            if (scoreText != null && NetworkManager.Singleton != null)
            {
                bool isPlayer1 = myId == p1Id;
                int myWins = isPlayer1 ? p1Wins : p2Wins;
                int oppWins = isPlayer1 ? p2Wins : p1Wins;
                scoreText.text = $"Score: You {myWins} - {oppWins} Opp";
            }

            bool isP1 = myId == p1Id;
            _localWins = isP1 ? p1Wins : p2Wins;
            _opponentWins = isP1 ? p2Wins : p1Wins;
            _clientRoundsPlayed = roundsPlayed;
            _clientMatchOver = roundsPlayed >= Math.Max(1, roundsTotal);
        }

        // Overload for initial UI state (before we know ids)
        private void UpdateRoundAndScoreUI(int roundsPlayed, int p1Wins, int p2Wins, int roundsTotal)
        {
            if (roundText != null)
            {
                int shownPlayed = Mathf.Clamp(roundsPlayed, 0, Math.Max(1, roundsTotal));
                int shownTotal = Math.Max(1, roundsTotal);
                roundText.text = $"Round: {shownPlayed}/{shownTotal}";
            }

            if (scoreText != null)
                scoreText.text = $"Score: You {p1Wins} - {p2Wins} Opp";

            _localWins = p1Wins;
            _opponentWins = p2Wins;
            _clientRoundsPlayed = roundsPlayed;
            _clientMatchOver = roundsPlayed >= Math.Max(1, roundsTotal);
        }

        private void SetButtonsInteractable(bool state)
        {
            if (rockButton != null) rockButton.interactable = state;
            if (paperButton != null) paperButton.interactable = state;
            if (scissorsButton != null) scissorsButton.interactable = state;
        }

        public int LocalMatchWins => _localWins;
        public int OpponentMatchWins => _opponentWins;
        public int RoundsPlayed => _clientRoundsPlayed;
        public int TotalRounds => Math.Max(1, totalRounds);
        public bool IsMatchOver => _clientMatchOver;
    }
}
