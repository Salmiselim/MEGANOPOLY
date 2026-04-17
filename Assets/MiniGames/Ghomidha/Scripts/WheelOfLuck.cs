using System;
using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

namespace Ghomidha
{
    /// <summary>
    /// Slot-machine style role randomiser — no image assets required.
    /// Builds its own UI in Awake() and cycles SEEKER/HIDER text rapidly,
    /// decelerates, then stops on the server-decided result.
    ///
    /// Attach to any empty GameObject inside your LobbyCanvas.
    /// GhomidhaLobbyManager calls:  wheelOfLuck.Spin(iAmSeeker, onComplete);
    /// </summary>
    [RequireComponent(typeof(RectTransform))]
    public class WheelOfLuck : MonoBehaviour
    {
        // ── Tuning ──────────────────────────────────────────────────────────
        [Header("Spin Settings")]
        [Tooltip("Total spin duration in seconds.")]
        [SerializeField] private float spinDuration = 3.5f;

        [Tooltip("Starting interval between flips (seconds) — fast at start.")]
        [SerializeField] private float startInterval = 0.06f;

        [Tooltip("Ending interval between flips (seconds) — slow at end.")]
        [SerializeField] private float endInterval = 0.55f;

        // ── Runtime refs (built procedurally) ───────────────────────────────
        private TextMeshProUGUI _roleLabel;   // big centre text: SEEKER / HIDER
        private Image           _background;  // coloured backing panel
        private bool            _isSpinning;

        // ── Colours ──────────────────────────────────────────────────────────
        private static readonly Color SeekerColor = new Color(0.90f, 0.35f, 0.10f); // orange-red
        private static readonly Color HiderColor  = new Color(0.10f, 0.45f, 0.85f); // blue
        private static readonly Color DarkBg      = new Color(0.08f, 0.08f, 0.12f, 0.92f);

        // ── Build UI in Awake ────────────────────────────────────────────────
        private void Awake()
        {
            BuildVisual();
        }

        private void BuildVisual()
        {
            var rt = GetComponent<RectTransform>();
            rt.sizeDelta = new Vector2(420f, 160f);

            // ── Outer dark panel ────────────────────────────────────────────
            var bgGo = new GameObject("SlotBackground");
            bgGo.transform.SetParent(transform, false);
            var bgRt = bgGo.AddComponent<RectTransform>();
            bgRt.anchorMin = Vector2.zero;
            bgRt.anchorMax = Vector2.one;
            bgRt.offsetMin = bgRt.offsetMax = Vector2.zero;
            _background = bgGo.AddComponent<Image>();
            _background.color = DarkBg;

            // ── Separator lines (top & bottom of slot window) ───────────────
            MakeLine("LineTop",    new Vector2(0f, 0.75f), new Vector2(1f, 0.80f));
            MakeLine("LineBottom", new Vector2(0f, 0.20f), new Vector2(1f, 0.25f));

            // ── Role label ──────────────────────────────────────────────────
            var lblGo = new GameObject("RoleLabel");
            lblGo.transform.SetParent(transform, false);
            var lblRt = lblGo.AddComponent<RectTransform>();
            lblRt.anchorMin = new Vector2(0.05f, 0.25f);
            lblRt.anchorMax = new Vector2(0.95f, 0.75f);
            lblRt.offsetMin = lblRt.offsetMax = Vector2.zero;
            _roleLabel              = lblGo.AddComponent<TextMeshProUGUI>();
            _roleLabel.text         = "???";
            _roleLabel.fontSize     = 52f;
            _roleLabel.fontStyle    = FontStyles.Bold;
            _roleLabel.color        = Color.white;
            _roleLabel.alignment    = TextAlignmentOptions.Center;
            _roleLabel.textWrappingMode = TextWrappingModes.NoWrap;

            // ── Small "ROLE" header ──────────────────────────────────────────
            var hdrGo = new GameObject("Header");
            hdrGo.transform.SetParent(transform, false);
            var hdrRt = hdrGo.AddComponent<RectTransform>();
            hdrRt.anchorMin = new Vector2(0f, 0.80f);
            hdrRt.anchorMax = new Vector2(1f, 1.00f);
            hdrRt.offsetMin = hdrRt.offsetMax = Vector2.zero;
            var hdr         = hdrGo.AddComponent<TextMeshProUGUI>();
            hdr.text        = "ROLE ASSIGNMENT";
            hdr.fontSize    = 18f;
            hdr.fontStyle   = FontStyles.Bold;
            hdr.color       = new Color(1f, 1f, 1f, 0.55f);
            hdr.alignment   = TextAlignmentOptions.Center;

            SetSlot("???", DarkBg);
        }

        private void MakeLine(string name, Vector2 anchorMin, Vector2 anchorMax)
        {
            var go = new GameObject(name);
            go.transform.SetParent(transform, false);
            var rt = go.AddComponent<RectTransform>();
            rt.anchorMin = anchorMin;
            rt.anchorMax = anchorMax;
            rt.offsetMin = rt.offsetMax = Vector2.zero;
            var img = go.AddComponent<Image>();
            img.color = new Color(1f, 1f, 1f, 0.25f);
        }

        // ── Public API ────────────────────────────────────────────────────────

        /// <summary>
        /// Spin the slot. The result is server-decided; pass it so the animation
        /// always lands correctly. onComplete fires when the spin finishes.
        /// </summary>
        public void Spin(bool localPlayerIsSeeker, Action onComplete = null)
        {
            if (_isSpinning) return;
            StartCoroutine(SpinRoutine(localPlayerIsSeeker, onComplete));
        }

        public void ResetSlot()
        {
            StopAllCoroutines();
            _isSpinning = false;
            SetSlot("???", DarkBg);
        }

        // ── Coroutine ─────────────────────────────────────────────────────────

        private IEnumerator SpinRoutine(bool localPlayerIsSeeker, Action onComplete)
        {
            _isSpinning = true;

            float elapsed  = 0f;
            bool  showSeeker = true;   // alternates each flip

            while (elapsed < spinDuration)
            {
                // Ease interval from fast → slow using a squared curve
                float t        = elapsed / spinDuration;            // 0 → 1
                float interval = Mathf.Lerp(startInterval, endInterval, t * t);

                // Flip the displayed role
                showSeeker = !showSeeker;
                SetSlot(showSeeker ? "SEEKER" : "HIDER",
                        showSeeker ? SeekerColor : HiderColor);

                yield return new WaitForSeconds(interval);
                elapsed += interval;
            }

            // Final result — guaranteed to match server decision
            string finalLabel = localPlayerIsSeeker ? "SEEKER" : "HIDER";
            Color  finalColor = localPlayerIsSeeker ? SeekerColor : HiderColor;
            SetSlot(finalLabel, finalColor);

            _isSpinning = false;
            onComplete?.Invoke();
        }

        private void SetSlot(string label, Color bgColor)
        {
            if (_roleLabel != null)   _roleLabel.text   = label;
            if (_background != null)  _background.color = bgColor;
        }
    }
}
