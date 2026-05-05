using UnityEngine;

namespace RockPaperScissors
{
    /// <summary>
    /// Plays win / defeat / tie / round SFX for the RPS minigame.
    ///
    /// SETUP:
    ///   1. Add this component to the same GameObject as MultiplayerRPSGameManager
    ///   2. Assign your AudioClips in the Inspector
    ///   3. In MultiplayerRPSGameManager Inspector, wire the RPSSoundManager reference
    ///      (or let it auto-find via GetComponent)
    /// </summary>
    [RequireComponent(typeof(AudioSource))]
    public class RPSSoundManager : MonoBehaviour
    {
        [Header("Match SFX")]
        [Tooltip("Played when THIS player wins the full match")]
        [SerializeField] private AudioClip matchWinClip;

        [Tooltip("Played when THIS player loses the full match")]
        [SerializeField] private AudioClip matchDefeatClip;

        [Tooltip("Played when the match ends in a draw")]
        [SerializeField] private AudioClip matchTieClip;

        [Header("Round SFX")]
        [Tooltip("Played when THIS player wins a single round")]
        [SerializeField] private AudioClip roundWinClip;

        [Tooltip("Played when THIS player loses a single round")]
        [SerializeField] private AudioClip roundLoseClip;

        [Tooltip("Played when a single round is a tie")]
        [SerializeField] private AudioClip roundTieClip;

        [Header("UI / Countdown SFX")]
        [Tooltip("Tick played when the hold-gesture progress bar advances (optional)")]
        [SerializeField] private AudioClip holdTickClip;

        [Tooltip("Confirm sound when a gesture is locked in")]
        [SerializeField] private AudioClip gestureConfirmClip;

        [Header("Volume")]
        [SerializeField] [Range(0f, 1f)] private float roundVolume  = 0.7f;
        [SerializeField] [Range(0f, 1f)] private float matchVolume  = 1.0f;
        [SerializeField] [Range(0f, 1f)] private float uiVolume     = 0.5f;

        private AudioSource _src;

        private void Awake()
        {
            _src = GetComponent<AudioSource>();
            _src.playOnAwake  = false;
            _src.spatialBlend = 0f; // 2-D (non-positional) — UI sounds shouldn't have 3-D falloff
        }

        // ── Public API ────────────────────────────────────────────────────────

        /// <summary>Call after a single round resolves (from ShowResultsClientRpc).</summary>
        public void PlayRoundResult(bool didIWin, bool isTie)
        {
            AudioClip clip;
            if (isTie)          clip = roundTieClip;
            else if (didIWin)   clip = roundWinClip;
            else                clip = roundLoseClip;

            Play(clip, roundVolume);
        }

        /// <summary>Call when the full match ends (from MatchOverClientRpc).</summary>
        public void PlayMatchResult(bool didIWin, bool isTie)
        {
            AudioClip clip;
            if (isTie)          clip = matchTieClip;
            else if (didIWin)   clip = matchWinClip;
            else                clip = matchDefeatClip;

            Play(clip, matchVolume);
        }

        /// <summary>Short confirm beep when a hand gesture is submitted.</summary>
        public void PlayGestureConfirm() => Play(gestureConfirmClip, uiVolume);

        /// <summary>Optional tick during the hold-progress bar.</summary>
        public void PlayHoldTick() => Play(holdTickClip, uiVolume);

        // ── Internal ──────────────────────────────────────────────────────────

        private void Play(AudioClip clip, float volume)
        {
            if (clip == null || _src == null) return;
            _src.PlayOneShot(clip, volume);
        }
    }
}
