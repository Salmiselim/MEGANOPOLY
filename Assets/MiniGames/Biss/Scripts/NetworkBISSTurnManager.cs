using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Netcode;

namespace BISS
{
    /// <summary>
    /// Server-authoritative turn manager for multiplayer BISS.
    ///
    /// FLOW:
    ///  • Waits for 2 players to connect.
    ///  • Player 1 throws 3 marbles one at a time (marbles stay on the ground).
    ///  • Then Player 2 throws their 3 marbles.
    ///  • Each player's BEST distance (closest marble to hole) is their score.
    ///  • Leaderboard shown to all at the end.
    ///
    /// SETUP IN UNITY:
    ///  1. Create empty GameObject "NetworkBISSTurnManager", add this script + NetworkObject.
    ///  2. Assign BISSHoleTarget, marbleSpawnPoint (Transform), marblePrefab, and UI in Inspector.
    ///  3. marblePrefab must have: Sphere mesh + BISSMarble + NetworkBISSMarble +
    ///     NetworkObject + NetworkTransform + XRGrabInteractable + Rigidbody + SphereCollider.
    ///     Tag the prefab "BISSMarble".
    /// </summary>
    public class NetworkBISSTurnManager : NetworkBehaviour
    {
        public static NetworkBISSTurnManager Instance { get; private set; }

        // ── Inspector ─────────────────────────────────────────────────────
        [Header("Game Settings")]
        [Tooltip("How many marble throws each player gets per round")]
        [SerializeField] private int marblesPerPlayer = 3;

        [Tooltip("Seconds per throw before the turn auto-advances")]
        [SerializeField] private float throwTimeLimit = 30f;

        [Header("Scene References")]
        [SerializeField] private BISSHoleTarget   holeTarget;
        [SerializeField] private Transform        marbleSpawnPoint;
        [SerializeField] private GameObject       marblePrefab;

        [Header("UI")]
        [SerializeField] private BISSMultiplayerUI ui;

        [Header("VFX")]
        [SerializeField] private BISSSparkle sparkle;

        // ── Network state ──────────────────────────────────────────────────
        // Read by all clients so UI can react to turn/attempt changes
        private NetworkVariable<int>  _currentPlayerIdx = new(0);
        private NetworkVariable<int>  _currentAttempt   = new(0);
        private NetworkVariable<bool> _gameActive       = new(false);
        private NetworkVariable<bool> _gameOver         = new(false);

        // ── Server-only state ─────────────────────────────────────────────
        private readonly List<ulong> _playerOrder = new();
        private float[]   _bestDistances;          // per player
        private float     _throwTimer;
        private int       _lastTimerInt = -1;
        private bool      _waitingForThrow;
        private bool      _waitingForStop;
        private NetworkBISSMarble _activeMarble;   // marble currently in play

        // ── Lifecycle ─────────────────────────────────────────────────────

        private void Awake()
        {
            Instance = this;
        }

        public override void OnNetworkSpawn()
        {
            if (IsServer)
            {
                NetworkManager.Singleton.OnClientConnectedCallback += RegisterPlayer;
                // Host is already connected — register immediately
                RegisterPlayer(NetworkManager.Singleton.LocalClientId);
            }
        }

        public override void OnNetworkDespawn()
        {
            if (IsServer && NetworkManager.Singleton != null)
                NetworkManager.Singleton.OnClientConnectedCallback -= RegisterPlayer;
        }

        private void Update()
        {
            if (!IsServer || !_gameActive.Value || _gameOver.Value) return;
            if (!_waitingForThrow && !_waitingForStop) return;

            _throwTimer -= Time.deltaTime;

            // Send timer to clients at most once per second
            int tInt = Mathf.CeilToInt(_throwTimer);
            if (tInt != _lastTimerInt)
            {
                _lastTimerInt = tInt;
                UpdateTimerClientRpc(Mathf.Max(_throwTimer, 0f));
            }

            if (_throwTimer <= 0f)
            {
                _throwTimer = 0f;
                OnTimerExpired();
            }
        }

        // ── Player Registration ───────────────────────────────────────────

        private void RegisterPlayer(ulong clientId)
        {
            if (_playerOrder.Contains(clientId)) return;
            _playerOrder.Add(clientId);
            Debug.Log($"[BISS] Player {clientId} connected. Total: {_playerOrder.Count}");
            PlayerCountClientRpc(_playerOrder.Count);

            if (_playerOrder.Count == 2 && !_gameActive.Value)
            {
                _gameActive.Value = true;
                StartCoroutine(StartGameAfterDelay(1.5f));
            }
        }

        // ── Game Initialization ───────────────────────────────────────────

        private IEnumerator StartGameAfterDelay(float delay)
        {
            yield return new WaitForSeconds(delay);

            _bestDistances        = new float[_playerOrder.Count];
            for (int i = 0; i < _bestDistances.Length; i++)
                _bestDistances[i] = float.MaxValue;

            _currentPlayerIdx.Value = 0;
            _currentAttempt.Value   = 0;
            BeginTurn();
        }

        // ── Turn Flow ─────────────────────────────────────────────────────

        private void BeginTurn()
        {
            int   pIdx  = _currentPlayerIdx.Value;
            int   aIdx  = _currentAttempt.Value;
            ulong owner = _playerOrder[pIdx];

            // Spawn a new marble owned by the current player
            var marbleObj = Instantiate(marblePrefab, marbleSpawnPoint.position, Quaternion.identity);
            var netObj    = marbleObj.GetComponent<NetworkObject>();
            netObj.SpawnWithOwnership(owner);

            _activeMarble = marbleObj.GetComponent<NetworkBISSMarble>();
            _activeMarble.playerIndex.Value = pIdx;

            // Reset timer
            _throwTimer     = throwTimeLimit;
            _lastTimerInt   = -1;
            _waitingForThrow = true;
            _waitingForStop  = false;

            NotifyTurnClientRpc(pIdx, aIdx + 1, marblesPerPlayer, owner);
            Debug.Log($"[BISS] Player {pIdx + 1} turn — marble {aIdx + 1}/{marblesPerPlayer}");
        }

        // Called by NetworkBISSMarble.MarbleThrownServerRpc
        public void OnMarbleThrownByOwner()
        {
            if (!IsServer) return;
            _waitingForThrow = false;
            _waitingForStop  = true;
            // Timer keeps running — player has remaining time until marble stops
        }

        // Called by NetworkBISSMarble.MarbleStoppedServerRpc
        public void OnMarbleStoppedByOwner(Vector3 finalPos)
        {
            if (!IsServer) return;
            _waitingForThrow = false;
            _waitingForStop  = false;

            float dist = holeTarget != null ? holeTarget.GetDistanceTo(finalPos) : 999f;
            RecordBestDistance(dist);

            int pIdx = _currentPlayerIdx.Value;
            int aIdx = _currentAttempt.Value;
            MarbleResultClientRpc(pIdx, aIdx, dist);

            StartCoroutine(AdvanceAfterDelay(1.5f));
        }

        private void OnTimerExpired()
        {
            _waitingForThrow = false;
            _waitingForStop  = false;

            // If marble was never thrown it's sitting at the spawn point —
            // despawn it so it doesn't block the next marble.
            if (_activeMarble != null)
            {
                bool wasThrown = !_activeMarble.GetComponent<BISSMarble>().IsStopped
                                 || _waitingForThrow; // still at spawn = never thrown
                // If it was never thrown (still at spawn), remove it
                var bm = _activeMarble.GetComponent<BISSMarble>();
                if (bm != null && bm.IsStopped)
                {
                    // IsStopped = true AND never thrown = it's just sitting there
                    _activeMarble.GetComponent<NetworkObject>().Despawn(true);
                    _activeMarble = null;
                }
            }

            // Record worst-case distance for this attempt
            RecordBestDistance(float.MaxValue / 2f);
            MarbleResultClientRpc(_currentPlayerIdx.Value, _currentAttempt.Value, -1f); // -1 = timed out

            StartCoroutine(AdvanceAfterDelay(0.5f));
        }

        private void RecordBestDistance(float dist)
        {
            int pIdx = _currentPlayerIdx.Value;
            if (dist < _bestDistances[pIdx])
                _bestDistances[pIdx] = dist;
        }

        private IEnumerator AdvanceAfterDelay(float delay)
        {
            yield return new WaitForSeconds(delay);

            int nextAttempt = _currentAttempt.Value + 1;

            if (nextAttempt < marblesPerPlayer)
            {
                // Same player, next marble
                _currentAttempt.Value = nextAttempt;
                BeginTurn();
            }
            else
            {
                // Move to next player
                int nextPlayer = _currentPlayerIdx.Value + 1;
                if (nextPlayer >= _playerOrder.Count)
                {
                    StartCoroutine(EndGameAfterDelay(2f));
                }
                else
                {
                    _currentPlayerIdx.Value = nextPlayer;
                    _currentAttempt.Value   = 0;
                    BeginTurn();
                }
            }
        }

        private IEnumerator EndGameAfterDelay(float delay)
        {
            yield return new WaitForSeconds(delay);

            _gameOver.Value = true;

            int count = _playerOrder.Count;

            // Sort player indices by best distance (ascending = best first)
            int[] ranking = new int[count];
            for (int i = 0; i < count; i++) ranking[i] = i;
            System.Array.Sort(ranking, (a, b) => _bestDistances[a].CompareTo(_bestDistances[b]));

            float[] sortedDists = new float[count];
            for (int r = 0; r < count; r++)
                sortedDists[r] = _bestDistances[ranking[r]];

            ulong winnerClientId = _playerOrder[ranking[0]];
            ShowLeaderboardClientRpc(ranking, sortedDists, winnerClientId);
            Debug.Log($"[BISS] Game over. Winner: Player {ranking[0] + 1}");
        }

        // ── ClientRpcs ─────────────────────────────────────────────────────

        [ClientRpc]
        private void PlayerCountClientRpc(int count)
        {
            ui?.ShowWaitingMessage(count);
        }

        [ClientRpc]
        private void NotifyTurnClientRpc(int playerIdx, int attemptNum, int maxAttempts, ulong ownerClientId)
        {
            bool isMyTurn = NetworkManager.Singleton.LocalClientId == ownerClientId;
            ui?.ShowTurnNotification(playerIdx, attemptNum, maxAttempts, isMyTurn);
        }

        [ClientRpc]
        private void UpdateTimerClientRpc(float secondsLeft)
        {
            ui?.UpdateTimer(secondsLeft);
        }

        [ClientRpc]
        private void MarbleResultClientRpc(int playerIdx, int attemptIdx, float dist)
        {
            ui?.ShowAttemptResult(playerIdx, attemptIdx, dist);
        }

        [ClientRpc]
        private void ShowLeaderboardClientRpc(int[] rankedPlayerIndices, float[] sortedBestDistances, ulong winnerClientId)
        {
            ui?.ShowLeaderboard(rankedPlayerIndices, sortedBestDistances);
            if (NetworkManager.Singleton.LocalClientId == winnerClientId)
                sparkle?.PlayScore();
        }
    }
}
