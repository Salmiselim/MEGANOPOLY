using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.UI;

namespace Ghomidha
{
    /// <summary>
    /// SeekerController — attach to any persistent GO in the scene (e.g. "SeekerManager").
    ///
    /// WHAT IT DOES:
    /// - Every frame, scans all HidingSpot instances for occupied ones.
    /// - When the seeker's camera is within tagRadius of an occupied spot,
    ///   a floating "FOUND!" button appears in front of the seeker.
    /// - Clicking it calls HidingSpot.Reveal() — forcing the hider back out.
    /// - Tracks how many players have been found (foundCount).
    ///
    /// STATIC TESTING (no multiplayer):
    /// - Hide as the player using the HidingSpot mechanic.
    /// - The spot's OccupiedByPlayer flag becomes true automatically.
    /// - Walk toward it as the "seeker" — the FOUND button will appear.
    ///
    /// SETUP:
    /// 1. Create an empty GO named "SeekerManager".
    /// 2. Add this component.
    /// 3. Done — no extra references needed.
    /// </summary>
    public class SeekerController : MonoBehaviour
    {
        // ── Inspector ──────────────────────────────────────────────────────
        [Header("Detection")]
        [Tooltip("How close (meters) the seeker must be to an occupied spot to see FOUND button")]
        [SerializeField] private float tagRadius   = 1.5f;

        [Tooltip("Seconds after appearing before the FOUND button is clickable (prevents accidental click)")]
        [SerializeField] private float tagCooldown = 1.0f;

        [Header("Button")]
        [SerializeField] private float fadeDuration = 0.2f;

        // ── Runtime ────────────────────────────────────────────────────────
        private List<HidingSpot> allSpots = new List<HidingSpot>();
        private HidingSpot       targetSpot;        // nearest occupied spot in range

        private Canvas      btnCanvas;
        private CanvasGroup btnGroup;
        private Button      tagBtn;
        private float       targetAlpha  = 0f;
        private float       cooldownLeft = 0f;

        // Stats
        public int FoundCount { get; private set; } = 0;

        // ── Lifecycle ──────────────────────────────────────────────────────
        private void Start()
        {
            BuildTagButton();
            RefreshSpotList();
        }

        private void Update()
        {
            RefreshSpotList();      // re-scan in case spots were added late
            ScanForHiders();
            UpdateButton();
            if (cooldownLeft > 0f) cooldownLeft -= Time.deltaTime;
        }

        private void LateUpdate()
        {
            if (btnGroup == null) return;
            bool ready = btnGroup.alpha > 0.5f && cooldownLeft <= 0f;
            btnGroup.interactable   = ready;
            btnGroup.blocksRaycasts = ready;
        }

        // ── Scan ───────────────────────────────────────────────────────────
        private void ScanForHiders()
        {
            if (Camera.main == null) return;
            Vector3 seekerPos = Camera.main.transform.position;

            HidingSpot closest  = null;
            float      closestD = float.MaxValue;

            foreach (var spot in allSpots)
            {
                if (spot == null || !spot.OccupiedByPlayer) continue;
                float dist = Vector3.Distance(seekerPos, spot.transform.position);
                if (dist < tagRadius && dist < closestD)
                {
                    closestD = dist;
                    closest  = spot;
                }
            }

            // Entered range of a new spot
            if (closest != null && closest != targetSpot)
            {
                targetSpot   = closest;
                targetAlpha  = 1f;
                cooldownLeft = tagCooldown;
                PositionButton();
            }
            // Left range / spot no longer occupied
            else if (closest == null && targetSpot != null)
            {
                targetSpot  = null;
                targetAlpha = 0f;
            }
        }

        // ── Button update ─────────────────────────────────────────────────
        private void UpdateButton()
        {
            if (btnGroup == null) return;
            btnGroup.alpha = Mathf.MoveTowards(btnGroup.alpha, targetAlpha, Time.deltaTime / fadeDuration);

            // Keep button glued in front of seeker while visible
            if (targetSpot != null && btnCanvas != null && Camera.main != null)
            {
                PositionButton();
                btnCanvas.transform.LookAt(Camera.main.transform);
                btnCanvas.transform.Rotate(0f, 180f, 0f);
            }
        }

        private void PositionButton()
        {
            if (btnCanvas == null || Camera.main == null) return;
            Vector3 fwd = Camera.main.transform.forward;
            Vector3 pos = Camera.main.transform.position + fwd * 0.6f;
            pos.y = Camera.main.transform.position.y;

            btnCanvas.transform.position   = pos;
            btnCanvas.transform.localScale = Vector3.one * 0.002f;
        }

        // ── Tag action ────────────────────────────────────────────────────
        private void OnTagClicked()
        {
            if (targetSpot == null || !targetSpot.OccupiedByPlayer) return;

            targetSpot.Reveal();
            FoundCount++;
            Debug.Log($"[Seeker] Found {FoundCount} player(s)! Tagged '{targetSpot.gameObject.name}'");

            targetSpot  = null;
            targetAlpha = 0f;
        }

        // ── Helpers ────────────────────────────────────────────────────────
        private void RefreshSpotList()
        {
            // Only do a full scan if the count changed (cheap guard)
            var found = FindObjectsByType<HidingSpot>(FindObjectsSortMode.None);
            if (found.Length != allSpots.Count)
            {
                allSpots.Clear();
                allSpots.AddRange(found);
            }
        }

        // ── UI ─────────────────────────────────────────────────────────────
        private void BuildTagButton()
        {
            var go = new GameObject("SeekerTagButton_Canvas");
            go.transform.SetParent(transform);
            go.transform.localScale = Vector3.one * 0.002f;

            var cv       = go.AddComponent<Canvas>();
            cv.renderMode  = RenderMode.WorldSpace;
            cv.worldCamera = Camera.main;
            go.AddComponent<UnityEngine.UI.CanvasScaler>();
            go.AddComponent<TrackedDeviceGraphicRaycaster>();

            btnGroup              = go.AddComponent<CanvasGroup>();
            btnGroup.alpha        = 0f;
            btnGroup.interactable = false;
            btnGroup.blocksRaycasts = false;

            btnCanvas = cv;

            // Panel
            var panel = new GameObject("Panel");
            panel.transform.SetParent(go.transform, false);
            var rt = panel.AddComponent<RectTransform>();
            rt.sizeDelta = new Vector2(180f, 60f);
            panel.AddComponent<Image>().color = new Color(0.8f, 0.1f, 0.1f, 0.85f);

            tagBtn = panel.AddComponent<Button>();
            var cb = tagBtn.colors;
            cb.normalColor      = Color.white;
            cb.highlightedColor = new Color(1f, 0.8f, 0.2f);
            cb.pressedColor     = new Color(0.5f, 1f, 0.5f);
            tagBtn.colors       = cb;
            tagBtn.onClick.AddListener(OnTagClicked);

            // Label
            var lgo = new GameObject("Label");
            lgo.transform.SetParent(panel.transform, false);
            var lr = lgo.AddComponent<RectTransform>();
            lr.anchorMin = Vector2.zero; lr.anchorMax = Vector2.one;
            lr.offsetMin = lr.offsetMax = Vector2.zero;

            var tmp       = lgo.AddComponent<TextMeshProUGUI>();
            tmp.text      = "FOUND!";
            tmp.fontSize  = 26f;
            tmp.fontStyle = FontStyles.Bold;
            tmp.color     = Color.white;
            tmp.alignment = TextAlignmentOptions.Center;
        }
    }
}
