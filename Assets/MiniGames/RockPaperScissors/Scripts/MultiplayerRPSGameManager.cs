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

        [Header("Start Game (Host Only)")]
        [Tooltip("Assign a Button in the scene. Only the host can see/press it. " +
                 "It becomes interactable once both players are connected.")]
        [SerializeField] private Button startGameButton;
        [SerializeField] private TextMeshProUGUI startGameStatusText; // optional — shows "Waiting for player..." etc.

        [Header("Game UI (hidden until game starts)")]
        [Tooltip("Root GameObject of the RPS overlay canvas. Disabled at start, spawns in front of the player when the game begins.")]
        [SerializeField] private GameObject gameUIRoot;
        [Tooltip("Root GameObject of the Soundboard UI. Same behaviour as gameUIRoot.")]
        [SerializeField] private GameObject soundboardUIRoot;
        [Tooltip("How far in front of the camera (in metres) the panels appear.")]
        [SerializeField] private float uiSpawnDistance = 1.5f;

        [Header("Video Setup (Optional)")]
        [SerializeField] private VideoPlayer backgroundVideo;

        [Header("Match Settings")]
        [SerializeField] private int totalRounds = 3;

        [Header("Hand Gesture Input")]
        [SerializeField] private HandGestureInputBridge handGestureBridge;

        [Header("Sound")]
        [SerializeField] private RPSSoundManager soundManager;

        [Header("VFX")]
        [SerializeField] private RPSConfettiEffect confettiEffect;

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

            // Wire Start Game button — only the host will ever have it interactable,
            // but we register the listener on everyone so no null-check is needed later.
            if (startGameButton != null)
            {
                startGameButton.onClick.AddListener(BeginGame);
                startGameButton.interactable = false; // greyed out until both players connected
            }

            // Video does NOT auto-play here — both clients start it together via
            // BeginGameClientRpc so the playback is perfectly in sync from frame 0.
            // We still call Prepare() so the decoder is warm and Play() is instant.
            if (backgroundVideo != null)
            {
                backgroundVideo.isLooping = true;
                backgroundVideo.Prepare(); // decodes first frame silently, no playback
            }

            // RPS buttons are disabled until the game is officially started.
            SetButtonsInteractable(false);

            // Hide both game UIs — they appear in front of the player only when
            // BeginGameClientRpc fires (i.e. the host pressed Start Game).
            if (gameUIRoot     != null) gameUIRoot.SetActive(false);
            if (soundboardUIRoot != null) soundboardUIRoot.SetActive(false);

            ResetUI();
            UpdateRoundAndScoreUI(0, 0, 0, totalRounds);
        }

        public override void OnNetworkSpawn()
        {
            if (IsServer)
            {
                // isRoundActive intentionally NOT set here — the game only begins
                // when the host presses Start Game (BeginGame), which fires
                // BeginGameClientRpc on both clients simultaneously so the video
                // starts in perfect sync.
                _roundsPlayed = 0;
                _winsByClientId.Clear();
                NetworkManager.Singleton.OnClientConnectedCallback += OnClientConnected;
                SetStartGameButtonState(false);
                SetStatusText("Waiting for your opponent to join...");
            }
            else
            {
                // Clients never see or use the Begin button
                if (startGameButton != null) startGameButton.gameObject.SetActive(false);
                SetStatusText("Connected!\nWaiting for the match to begin...");
            }
        }

        public override void OnNetworkDespawn()
        {
            if (IsServer && NetworkManager.Singleton != null)
                NetworkManager.Singleton.OnClientConnectedCallback -= OnClientConnected;
        }

        private void OnClientConnected(ulong clientId)
        {
            Debug.Log($"<color=cyan>[RPS Multiplayer]</color> Player {clientId} has entered the game!");

            if (IsServer)
            {
                if (!_winsByClientId.ContainsKey(clientId))
                    _winsByClientId[clientId] = 0;

                // Enable Start Game only once both players are present
                int count = NetworkManager.Singleton.ConnectedClientsList.Count;
                if (count >= 2)
                {
                    Debug.Log("<color=green>[RPS Multiplayer]</color> Both players connected — host can now start!");
                    SetStartGameButtonState(true);
                    SetStatusText("Your opponent is here!\nPress Begin when ready.");
                }
            }
        }

        // ── Start Game (host presses button) ─────────────────────────────────

        /// <summary>
        /// Called when the host presses the Start Game button.
        /// Fires a ClientRpc that simultaneously starts the video and enables
        /// RPS buttons on BOTH machines — this is what keeps the video in sync.
        /// </summary>
        public void BeginGame()
        {
            if (!IsServer) return;

            isRoundActive = true;
            _roundsPlayed = 0;
            _winsByClientId.Clear();

            // Hide the start button so it can't be pressed again
            if (startGameButton != null) startGameButton.gameObject.SetActive(false);

            BeginGameClientRpc();
        }

        [ClientRpc]
        private void BeginGameClientRpc()
        {
            // Fires on both clients at the same instant — start the countdown coroutine
            // which will call video.Play() on both machines simultaneously at "GO!".
            StartCoroutine(CountdownThenStart());
        }

        private IEnumerator CountdownThenStart()
        {
            // Show UIs first so the player can see the countdown.
            SpawnUIInFrontOfCamera(gameUIRoot);
            SpawnUIInFrontOfCamera(soundboardUIRoot);

            // Hide connection status — the countdown takes over the result text.
            SetStatusText(string.Empty);

            // 3 … 2 … 1 … GO!
            if (resultText != null)
            {
                string[] steps  = { "3", "2", "1", "GO!" };
                Color[]  colors = { Color.white, Color.white, Color.white, Color.green };

                for (int i = 0; i < steps.Length; i++)
                {
                    resultText.text  = steps[i];
                    resultText.color = colors[i];
                    yield return new WaitForSeconds(1f);
                }
            }
            else
            {
                // No result text? Just wait 1 second before starting.
                yield return new WaitForSeconds(1f);
            }

            // Both clients hit this line at virtually the same moment —
            // this is what keeps the video in sync.
            if (backgroundVideo != null)
                backgroundVideo.Play();

            SetButtonsInteractable(true);
            ResetUI();
        }

        /// <summary>
        /// Enables a world-space canvas root and positions it directly in front of
        /// the local player's camera, upright and level.
        /// </summary>
        private void SpawnUIInFrontOfCamera(GameObject uiRoot)
        {
            if (uiRoot == null) return;

            Camera cam = Camera.main;
            if (cam == null)
            {
                // No camera found — just show it wherever it already is.
                uiRoot.SetActive(true);
                return;
            }

            // Project the camera's forward direction onto the horizontal plane so
            // the panel is always upright (never tilted with the player's head).
            Vector3 flatForward = Vector3.ProjectOnPlane(cam.transform.forward, Vector3.up).normalized;

            // Fallback if the player is looking straight up or down.
            if (flatForward.sqrMagnitude < 0.001f)
                flatForward = Vector3.forward;

            uiRoot.transform.position = cam.transform.position + flatForward * uiSpawnDistance;
            uiRoot.transform.rotation = Quaternion.LookRotation(flatForward, Vector3.up);
            uiRoot.SetActive(true);
        }

        // ── Helpers ──────────────────────────────────────────────────────────

        private void SetStartGameButtonState(bool interactable)
        {
            if (startGameButton == null) return;
            startGameButton.interactable = interactable;
        }

        private void SetStatusText(string msg)
        {
            if (startGameStatusText != null)
                startGameStatusText.text = msg;
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
                    confettiEffect?.PlayWin();
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
                resultText.text = $"Choose your move!";
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
                scoreText.text = $"Score: {myWins} - {oppWins}";
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
                scoreText.text = $"Score: {p1Wins} - {p2Wins}";

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
