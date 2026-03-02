using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

namespace BISS
{
    /// <summary>
    /// Core BISS game manager: handles turn flow, 30-second timer,
    /// attempt counting per player, distance tracking, and winner detection.
    ///
    /// SETUP:
    /// 1. Create an empty GameObject named "BISSTurnManager" in the scene.
    /// 2. Add this script to it.
    /// 3. Assign BISSHoleTarget, marble spawn point, marble prefab,
    ///    and BISSUIManager in the Inspector.
    /// 4. Set playerCount (2–4).
    ///
    /// HOW A TURN WORKS:
    ///   • A marble spawns at MarbleSpawnPoint.
    ///   • Player has 30 seconds to grab and throw it.
    ///   • Once the marble stops, distance is measured and recorded.
    ///   • If marble scored → player wins the round immediately.
    ///   • Timer runs out → turn ends, next player's turn begins.
    ///   • After all players have had their turn, winner is the player
    ///     whose marble is closest to the hole (fewest attempts tie-break).
    /// </summary>
    public class BISSTurnManager : MonoBehaviour
    {
        // ── Inspector ────────────────────────────────────────────────────
        [Header("Game Setup")]
        [Tooltip("How many players are playing (1 for solo test, up to 4)")]
        [SerializeField] private int playerCount = 1;

        [Tooltip("Seconds each player has per throw attempt")]
        [SerializeField] private float turnDuration = 30f;

        [Tooltip("Maximum throws allowed per player before auto-advancing to next player")]
        [SerializeField] private int maxAttemptsPerPlayer = 5;

        [Header("Scene References")]
        [Tooltip("The BISSHoleTarget in the scene (the red X)")]
        [SerializeField] private BISSHoleTarget holeTarget;

        [Tooltip("Where the marble spawns at the start of each turn")]
        [SerializeField] private Transform marbleSpawnPoint;

        [Tooltip("The marble prefab (Sphere with BISSMarble + XRGrabInteractable + Rigidbody)")]
        [SerializeField] private GameObject marblePrefab;

        [Header("UI")]
        [SerializeField] private BISSUIManager uiManager;

        // ── Game State ───────────────────────────────────────────────────
        private int currentPlayerIndex = 0;
        private float turnTimer;
        private bool turnActive;
        private bool waitingForMarbleToStop;

        // Per-player records
        private int[] attemptCounts;       // how many throws each player made
        private float[] bestDistances;     // closest marble-to-hole distance per player
        private bool[] hasScored;          // true if player's marble entered the hole

        private BISSMarble currentMarble;

        // ── Game State Enum ──────────────────────────────────────────────
        public enum GameState { WaitingToStart, TurnActive, WaitingMarble, TurnEnded, GameOver }
        public GameState State { get; private set; } = GameState.WaitingToStart;

        // ── Lifecycle ────────────────────────────────────────────────────
        private void Start()
        {
            // Wire hole target event
            if (holeTarget != null)
                holeTarget.OnMarbleScored += OnMarbleScoredInHole;

            InitializeGame();
        }

        private void OnDestroy()
        {
            if (holeTarget != null)
                holeTarget.OnMarbleScored -= OnMarbleScoredInHole;
        }

        private void Update()
        {
            if (State == GameState.TurnActive)
            {
                // Countdown timer
                turnTimer -= Time.deltaTime;
                uiManager?.UpdateTimer(turnTimer);

                // Update distance display if marble is stopped
                if (currentMarble != null && currentMarble.IsStopped)
                {
                    float dist = holeTarget.GetDistanceTo(currentMarble.transform.position);
                    uiManager?.UpdateDistance(dist);
                    holeTarget.UpdateProximityFeedback(currentMarble.transform.position);
                }

                // Timer ran out
                if (turnTimer <= 0f)
                {
                    turnTimer = 0f;
                    OnTurnTimerExpired();
                }
            }
        }

        // ── Initialization ───────────────────────────────────────────────
        private void InitializeGame()
        {
            playerCount = Mathf.Max(1, playerCount);
            attemptCounts = new int[playerCount];
            bestDistances = new float[playerCount];
            hasScored = new bool[playerCount];

            for (int i = 0; i < playerCount; i++)
            {
                bestDistances[i] = float.MaxValue;
                hasScored[i] = false;
                attemptCounts[i] = 0;
            }

            currentPlayerIndex = 0;
            StartTurn();
        }

        // ── Turn Flow ────────────────────────────────────────────────────

        /// <summary>Starts the turn for the current player.</summary>
        private void StartTurn()
        {
            State = GameState.TurnActive;
            turnTimer = turnDuration;

            // Destroy any previous marble
            if (currentMarble != null)
                Destroy(currentMarble.gameObject);

            // Spawn a fresh marble
            GameObject marbleObj = Instantiate(marblePrefab, marbleSpawnPoint.position, Quaternion.identity);
            currentMarble = marbleObj.GetComponent<BISSMarble>();
            currentMarble.OnMarbleThrown += OnMarbleThrown;
            currentMarble.OnMarbleStopped += OnMarbleStopped;

            holeTarget.ResetVisual();
            uiManager?.UpdateTurn(currentPlayerIndex + 1, attemptCounts[currentPlayerIndex] + 1, maxAttemptsPerPlayer);
            uiManager?.UpdateTimer(turnTimer);
            uiManager?.UpdateDistance(-1f); // -1 = no data yet

            Debug.Log($"[BISS] Player {currentPlayerIndex + 1} turn started. Attempt {attemptCounts[currentPlayerIndex] + 1}");
        }

        /// <summary>Called when the marble is thrown (released by player).</summary>
        private void OnMarbleThrown()
        {
            attemptCounts[currentPlayerIndex]++;
            State = GameState.WaitingMarble;
            Debug.Log($"[BISS] Player {currentPlayerIndex + 1} threw marble (attempt {attemptCounts[currentPlayerIndex]})");
        }

        /// <summary>Called when the marble comes to a full stop.</summary>
        private void OnMarbleStopped()
        {
            if (currentMarble == null) return;

            float distance = holeTarget.GetDistanceTo(currentMarble.transform.position);
            Debug.Log($"[BISS] Marble stopped. Distance to hole: {distance:F2}m");

            // Track best distance
            if (distance < bestDistances[currentPlayerIndex])
                bestDistances[currentPlayerIndex] = distance;

            uiManager?.UpdateDistance(distance);
            holeTarget.UpdateProximityFeedback(currentMarble.transform.position);

            State = GameState.TurnActive;

            // Check if max attempts reached
            if (attemptCounts[currentPlayerIndex] >= maxAttemptsPerPlayer)
            {
                AdvanceToNextPlayer();
            }
            // Otherwise player can grab & throw again within remaining timer
        }

        /// <summary>Called by BISSHoleTarget when a marble enters the hole trigger.</summary>
        public void OnMarbleScoredInHole(GameObject marbleObj)
        {
            if (marbleObj != currentMarble?.gameObject) return;

            hasScored[currentPlayerIndex] = true;
            bestDistances[currentPlayerIndex] = 0f;
            Debug.Log($"[BISS] 🎯 Player {currentPlayerIndex + 1} SCORED!");

            uiManager?.ShowScoredFeedback(currentPlayerIndex + 1);

            // Give a short pause then advance
            StartCoroutine(DelayedAdvance(2f));
        }

        private void OnTurnTimerExpired()
        {
            Debug.Log($"[BISS] Player {currentPlayerIndex + 1} turn timer expired.");
            AdvanceToNextPlayer();
        }

        private void AdvanceToNextPlayer()
        {
            State = GameState.TurnEnded;

            // If only 1 player (solo test), just restart their turn
            if (playerCount == 1)
            {
                StartCoroutine(DelayedRestart(1.5f));
                return;
            }

            currentPlayerIndex++;

            // All players have had their turn — determine winner
            if (currentPlayerIndex >= playerCount)
            {
                DetermineWinner();
            }
            else
            {
                StartCoroutine(DelayedNextTurn(1.5f));
            }
        }

        // ── Winner Detection ─────────────────────────────────────────────
        private void DetermineWinner()
        {
            State = GameState.GameOver;

            // First check: any player who scored in the hole wins
            for (int i = 0; i < playerCount; i++)
            {
                if (hasScored[i])
                {
                    // Multiple scorers → fewest attempts wins
                    int winner = i;
                    for (int j = i + 1; j < playerCount; j++)
                    {
                        if (hasScored[j] && attemptCounts[j] < attemptCounts[winner])
                            winner = j;
                    }
                    uiManager?.ShowWinner(winner + 1, bestDistances[winner], attemptCounts[winner]);
                    Debug.Log($"[BISS] 🏆 Winner: Player {winner + 1} (scored in hole in {attemptCounts[winner]} attempts)");
                    return;
                }
            }

            // No one scored → closest marble wins
            int closestPlayer = 0;
            for (int i = 1; i < playerCount; i++)
            {
                if (bestDistances[i] < bestDistances[closestPlayer])
                    closestPlayer = i;
                else if (Mathf.Approximately(bestDistances[i], bestDistances[closestPlayer])
                         && attemptCounts[i] < attemptCounts[closestPlayer])
                    closestPlayer = i; // Tie break: fewer attempts
            }

            uiManager?.ShowWinner(closestPlayer + 1, bestDistances[closestPlayer], attemptCounts[closestPlayer]);
            Debug.Log($"[BISS] 🏆 Winner: Player {closestPlayer + 1} (closest at {bestDistances[closestPlayer]:F2}m)");
        }

        // ── Public API ───────────────────────────────────────────────────

        /// <summary>Returns current player's best distance to hole.</summary>
        public float GetCurrentPlayerBestDistance() =>
            currentPlayerIndex < playerCount ? bestDistances[currentPlayerIndex] : 0f;

        /// <summary>Returns attempt count for all players (for UI/debug).</summary>
        public int[] GetAllAttemptCounts() => attemptCounts;

        /// <summary>Returns best distance for all players.</summary>
        public float[] GetAllBestDistances() => bestDistances;

        // ── Coroutines ───────────────────────────────────────────────────
        private IEnumerator DelayedNextTurn(float delay)
        {
            yield return new WaitForSeconds(delay);
            StartTurn();
        }

        private IEnumerator DelayedAdvance(float delay)
        {
            yield return new WaitForSeconds(delay);
            AdvanceToNextPlayer();
        }

        private IEnumerator DelayedRestart(float delay)
        {
            yield return new WaitForSeconds(delay);
            // Solo mode: reset attempts and restart
            attemptCounts[0] = 0;
            bestDistances[0] = float.MaxValue;
            hasScored[0] = false;
            StartTurn();
        }
    }
}
