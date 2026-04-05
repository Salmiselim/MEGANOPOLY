using System.Text;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

namespace BISS
{
    /// <summary>
    /// Multiplayer HUD for BISS. Wire all fields in the Inspector.
    ///
    /// CANVAS SETUP:
    ///   World Space Canvas  (BISSCanvas)
    ///   ├── WaitingPanel
    ///   │     └── WaitingText          (TMP)
    ///   ├── HUDPanel
    ///   │     ├── TurnLabel            (TMP) — "Player 1 | Marble 2/3"
    ///   │     ├── TimerLabel           (TMP) — "⏱ 28s"
    ///   │     ├── NotificationLabel    (TMP) — "YOUR TURN!" / "Player 2's turn..."
    ///   │     └── DistanceLabel        (TMP) — "📏 Marble 1: 1.43m"
    ///   └── LeaderboardPanel
    ///         └── LeaderboardText      (TMP, auto-sized, rich-text ON)
    ///
    /// Add TrackedDeviceGraphicRaycaster + GraphicRaycaster to the Canvas
    /// if you have any clickable buttons on it.
    /// </summary>
    public class BISSMultiplayerUI : MonoBehaviour
    {
        // ── Inspector ─────────────────────────────────────────────────────
        [Header("Waiting Panel")]
        [SerializeField] private GameObject       waitingPanel;
        [SerializeField] private TextMeshProUGUI  waitingText;

        [Header("HUD Panel")]
        [SerializeField] private GameObject       hudPanel;
        [SerializeField] private TextMeshProUGUI  turnLabel;
        [SerializeField] private TextMeshProUGUI  timerLabel;
        [SerializeField] private TextMeshProUGUI  notificationLabel;
        [SerializeField] private TextMeshProUGUI  distanceLabel;

        [Header("Leaderboard Panel")]
        [SerializeField] private GameObject       leaderboardPanel;
        [SerializeField] private TextMeshProUGUI  leaderboardText;

        [Header("Timer Colors")]
        [SerializeField] private Color normalTimerColor  = Color.white;
        [SerializeField] private Color urgentTimerColor  = Color.red;
        [SerializeField] private float urgentThreshold   = 10f;

        // ── Lifecycle ─────────────────────────────────────────────────────

        private void Awake()
        {
            SetActive(waitingPanel,     true);
            SetActive(hudPanel,         false);
            SetActive(leaderboardPanel, false);
            SetActive(notificationLabel?.gameObject, false);
        }

        // ── Public API (called by NetworkBISSTurnManager via ClientRpc) ───

        /// <summary>Shows/hides waiting screen based on connected player count.</summary>
        public void ShowWaitingMessage(int connectedCount)
        {
            bool waiting = connectedCount < 2;
            SetActive(waitingPanel, waiting);
            SetActive(hudPanel,     !waiting);
            if (waitingText != null)
                waitingText.text = $"Waiting for players...\n{connectedCount} / 2 connected";
        }

        /// <summary>Called at the start of each marble throw.</summary>
        public void ShowTurnNotification(int playerIdx, int attemptNum, int maxAttempts, bool isMyTurn)
        {
            // TurnLabel: "Player 1  |  Marble 2 / 3"  colored in the player's color
            if (turnLabel != null)
            {
                string hex = PlayerHex(playerIdx);
                turnLabel.text = $"<color=#{hex}>Player {playerIdx + 1}</color>  |  Marble {attemptNum} / {maxAttempts}";
            }

            // Big notification that auto-hides after 3 s
            if (notificationLabel != null)
            {
                notificationLabel.gameObject.SetActive(true);
                notificationLabel.text  = isMyTurn ? "YOUR TURN!" : $"Player {playerIdx + 1}'s turn...";
                notificationLabel.color = isMyTurn ? Color.yellow : Color.white;
                CancelInvoke(nameof(HideNotification));
                Invoke(nameof(HideNotification), 3f);
            }

            if (distanceLabel != null)
                distanceLabel.text = "Throw your marble!";
        }

        /// <summary>Updates the countdown timer display.</summary>
        public void UpdateTimer(float secondsLeft)
        {
            if (timerLabel == null) return;
            timerLabel.text  = $"Time: {Mathf.Ceil(secondsLeft):0}s";
            timerLabel.color = secondsLeft <= urgentThreshold ? urgentTimerColor : normalTimerColor;
        }

        /// <summary>Shows the result of a single marble throw.</summary>
        public void ShowAttemptResult(int playerIdx, int attemptIdx, float dist)
        {
            if (distanceLabel == null) return;

            string attemptLabel = $"Marble {attemptIdx + 1}";

            if (dist < 0f)
            {
                // dist == -1 means timer expired
                distanceLabel.text  = $"{attemptLabel}: timed out";
                distanceLabel.color = Color.gray;
            }
            else if (Mathf.Approximately(dist, 0f))
            {
                distanceLabel.text  = $"{attemptLabel}: SCORED!";
                distanceLabel.color = Color.green;
            }
            else
            {
                distanceLabel.text  = $"{attemptLabel}: {dist:F2}m";
                distanceLabel.color = dist < 0.5f ? Color.green
                                    : dist < 1.5f ? Color.yellow
                                    : Color.white;
            }
        }

        /// <summary>Shows the final ranked leaderboard to all players.</summary>
        public void ShowLeaderboard(int[] rankedPlayerIndices, float[] sortedBestDistances)
        {
            SetActive(hudPanel,          false);
            SetActive(leaderboardPanel,  true);
            SetActive(notificationLabel?.gameObject, false);

            if (leaderboardText == null) return;

            var sb = new StringBuilder();
            sb.AppendLine("<b>-- FINAL RESULTS --</b>\n");

            string[] medals = { "1st", "2nd", "3rd", "4th" };

            for (int r = 0; r < rankedPlayerIndices.Length; r++)
            {
                int   pIdx    = rankedPlayerIndices[r];
                float dist    = sortedBestDistances[r];
                string hex    = PlayerHex(pIdx);
                string medal  = r < medals.Length ? medals[r] : $"{r + 1}.";

                string distText;
                if (Mathf.Approximately(dist, 0f))
                    distText = "Scored in the hole!";
                else if (dist >= float.MaxValue / 3f)
                    distText = "No valid throw";
                else
                    distText = $"Best: {dist:F2}m";

                sb.AppendLine($"{medal}  <color=#{hex}>Player {pIdx + 1}</color>  —  {distText}");
            }

            if (rankedPlayerIndices.Length > 0)
            {
                int    winner = rankedPlayerIndices[0];
                string wHex   = PlayerHex(winner);
                sb.AppendLine($"\n<size=130%><b><color=#{wHex}>*** Player {winner + 1} Wins! ***</color></b></size>");
            }

            leaderboardText.text = sb.ToString();
        }

        // ── Helpers ───────────────────────────────────────────────────────

        private static string PlayerHex(int playerIdx)
        {
            int clamped = Mathf.Clamp(playerIdx, 0, NetworkBISSMarble.PlayerColors.Length - 1);
            return ColorUtility.ToHtmlStringRGB(NetworkBISSMarble.PlayerColors[clamped]);
        }

        private static void SetActive(GameObject go, bool state)
        {
            if (go != null) go.SetActive(state);
        }

        private void HideNotification()
        {
            SetActive(notificationLabel?.gameObject, false);
        }
    }
}
