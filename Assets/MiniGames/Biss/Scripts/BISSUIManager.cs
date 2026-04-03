using UnityEngine;
using TMPro;

namespace BISS
{
    /// <summary>
    /// Manages all BISS HUD elements:
    ///   • Turn indicator (Player X – Attempt Y/Z)
    ///   • Countdown timer
    ///   • Distance to hole (updates live)
    ///   • Scored / Winner announcement panels
    ///
    /// SETUP:
    /// 1. Create a World Space Canvas in the scene (so it floats in VR space).
    /// 2. Add the following Text (TextMeshPro) children and assign them below:
    ///      - TurnLabel       e.g. "Player 1 – Attempt 1/5"
    ///      - TimerLabel      e.g. "⏱ 30.0s"
    ///      - DistanceLabel   e.g. "📏 Distance: 2.34m"
    ///      - AnnouncementLabel (large, hidden by default)
    /// 3. Assign this script to the Canvas root.
    /// 4. Reference BISSUIManager in BISSTurnManager.
    /// </summary>
    public class BISSUIManager : MonoBehaviour
    {
        // ── Inspector ────────────────────────────────────────────────────
        [Header("HUD Text Elements")]
        [SerializeField] private TextMeshProUGUI turnLabel;
        [SerializeField] private TextMeshProUGUI timerLabel;
        [SerializeField] private TextMeshProUGUI distanceLabel;
        [SerializeField] private TextMeshProUGUI announcementLabel;

        [Header("Panel References (optional)")]
        [Tooltip("Root panel to show on game over")]
        [SerializeField] private GameObject winnerPanel;

        [Header("Colors")]
        [SerializeField] private Color normalTimerColor = Color.white;
        [SerializeField] private Color urgentTimerColor = Color.red;
        [Tooltip("Timer turns red below this many seconds")]
        [SerializeField] private float urgentTimerThreshold = 10f;

        [SerializeField] private Color closeFarColor = Color.red;
        [SerializeField] private Color closeNearColor = Color.green;
        [Tooltip("Distance at which the label turns fully green")]
        [SerializeField] private float closeDistanceThreshold = 0.5f;
        [Tooltip("Distance at which the label is fully red")]
        [SerializeField] private float farDistanceThreshold = 3f;

        // ── Lifecycle ────────────────────────────────────────────────────
        private void Awake()
        {
            if (announcementLabel != null) announcementLabel.gameObject.SetActive(false);
            if (winnerPanel != null) winnerPanel.SetActive(false);
        }

        // ── Public API ───────────────────────────────────────────────────

        /// <summary>Updates the turn/attempt indicator.</summary>
        /// <param name="playerNumber">1-based player number</param>
        /// <param name="attempt">Current attempt number</param>
        /// <param name="maxAttempts">Max attempts allowed</param>
        public void UpdateTurn(int playerNumber, int attempt, int maxAttempts)
        {
            if (turnLabel == null) return;
            turnLabel.text = $"Player {playerNumber}  |  Attempt {attempt} / {maxAttempts}";
        }

        /// <summary>Updates the countdown timer display.</summary>
        public void UpdateTimer(float secondsRemaining)
        {
            if (timerLabel == null) return;
            timerLabel.text = $"⏱  {Mathf.Ceil(secondsRemaining):0}s";
            timerLabel.color = secondsRemaining <= urgentTimerThreshold
                ? urgentTimerColor
                : normalTimerColor;
        }

        /// <summary>
        /// Updates the distance label.
        /// Pass -1 to show "---" (no data yet).
        /// </summary>
        public void UpdateDistance(float distanceMeters)
        {
            if (distanceLabel == null) return;

            if (distanceMeters < 0f)
            {
                distanceLabel.text = "📏  Distance: ---";
                distanceLabel.color = normalTimerColor;
                return;
            }

            distanceLabel.text = $"📏  Distance: {distanceMeters:F2} m";

            // Color: green when very close, red when far
            float t = Mathf.InverseLerp(closeDistanceThreshold, farDistanceThreshold, distanceMeters);
            distanceLabel.color = Color.Lerp(closeNearColor, closeFarColor, t);
        }

        /// <summary>Shows a big "SCORED!" flash for the given player.</summary>
        public void ShowScoredFeedback(int playerNumber)
        {
            if (announcementLabel == null) return;
            announcementLabel.gameObject.SetActive(true);
            announcementLabel.text = $"🎯  Player {playerNumber} SCORED!";
            announcementLabel.color = Color.green;

            // Hide after 2 seconds
            CancelInvoke(nameof(HideAnnouncement));
            Invoke(nameof(HideAnnouncement), 2f);
        }

        /// <summary>Shows the final winner screen.</summary>
        public void ShowWinner(int playerNumber, float bestDistance, int attempts)
        {
            if (winnerPanel != null) winnerPanel.SetActive(true);

            if (announcementLabel != null)
            {
                announcementLabel.gameObject.SetActive(true);

                string distText = Mathf.Approximately(bestDistance, 0f)
                    ? "scored in the hole!"
                    : $"closest at {bestDistance:F2}m";

                announcementLabel.text =
                    $"🏆  Player {playerNumber} Wins!\n" +
                    $"{distText}  ({attempts} throws)";

                announcementLabel.color = Color.yellow;
            }
        }

        // ── Helpers ──────────────────────────────────────────────────────
        private void HideAnnouncement()
        {
            if (announcementLabel != null)
                announcementLabel.gameObject.SetActive(false);
        }
    }
}
