using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.UI;
using Unity.Netcode;

namespace Ghomidha
{
    public class MultiplayerSeekerController : NetworkBehaviour
    {
        [Header("Detection")]
        [Tooltip("How close (meters) the seeker must be to *any* spot to see the INSPECT button")]
        [SerializeField] private float tagRadius   = 1.5f;

        [Tooltip("Seconds the result (FOUND/EMPTY) stays on screen before resetting")]
        [SerializeField] private float resultDisplayDuration = 2.0f;

        [Header("Button")]
        [SerializeField] private float fadeDuration = 0.2f;

        // ── Runtime ────────────────────────────────────────────────────────
        private List<MultiplayerHidingSpot> allSpots = new List<MultiplayerHidingSpot>();
        private MultiplayerHidingSpot       targetSpot;

        private Canvas      btnCanvas;
        private CanvasGroup btnGroup;
        private Button      tagBtn;
        private TextMeshProUGUI btnText;
        private Image       btnImage;

        private float       targetAlpha  = 0f;
        private bool        isDisplayingResult = false; // true if showing FOUND or EMPTY

        public int FoundCount { get; private set; } = 0;

        private void Start()
        {
            BuildTagButton();
            RefreshSpotList();
        }

        private void Update()
        {
            if (!IsSpawned || !IsHost) return; // Only the Seeker (Host) runs this logic

            RefreshSpotList();
            ScanForSpots();
            UpdateButton();
        }

        private void LateUpdate()
        {
            if (!IsSpawned || !IsHost) return;

            if (btnGroup == null) return;
            // Only clickable if fully visible and not currently showing a result
            bool ready = btnGroup.alpha > 0.5f && !isDisplayingResult;
            btnGroup.interactable   = ready;
            btnGroup.blocksRaycasts = ready;
        }

        private void ScanForSpots()
        {
            if (isDisplayingResult) return; // Pause scanning while reading result
            if (Camera.main == null) return;

            Vector3 seekerPos = Camera.main.transform.position;
            MultiplayerHidingSpot closest = null;
            float closestD = float.MaxValue;

            // Find closest spot within radius
            foreach (var spot in allSpots)
            {
                if (spot == null) continue;
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
                ResetButtonToInspect();
                PositionButton();
            }
            // Left range of the spot
            else if (closest == null && targetSpot != null)
            {
                targetSpot  = null;
                targetAlpha = 0f;
            }
        }

        private void UpdateButton()
        {
            if (btnGroup == null) return;
            btnGroup.alpha = Mathf.MoveTowards(btnGroup.alpha, targetAlpha, Time.deltaTime / fadeDuration);

            // Keep glued to seeker
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

        private void OnInspectClicked()
        {
            if (targetSpot == null || isDisplayingResult) return;

            isDisplayingResult = true;

            // Check if occupied
            bool isOccupied = targetSpot.occupyingClientId.Value != ulong.MaxValue;

            if (isOccupied)
            {
                // FOUND!
                btnText.text = "FOUND!";
                btnImage.color = new Color(0.1f, 0.8f, 0.1f, 0.9f); // Green
                
                targetSpot.RevealHiderBySeeker();
                FoundCount++;
                Debug.Log($"[Seeker] Found {FoundCount} player(s)! Tagged '{targetSpot.gameObject.name}'");
            }
            else
            {
                // EMPTY!
                btnText.text = "EMPTY";
                btnImage.color = new Color(0.4f, 0.4f, 0.4f, 0.9f); // Gray
                Debug.Log($"[Seeker] Inspected '{targetSpot.gameObject.name}'... nobody is there.");
            }

            // Hide and reset after a delay
            StartCoroutine(ResultWaitRoutine());
        }

        private IEnumerator ResultWaitRoutine()
        {
            yield return new WaitForSeconds(resultDisplayDuration);
            targetSpot = null;
            targetAlpha = 0f;
            isDisplayingResult = false;
        }

        private void ResetButtonToInspect()
        {
            if (btnText != null) btnText.text = "INSPECT";
            if (btnImage != null) btnImage.color = new Color(0.8f, 0.5f, 0.1f, 0.85f); // Orange
        }

        private void RefreshSpotList()
        {
            var found = FindObjectsByType<MultiplayerHidingSpot>(FindObjectsSortMode.None);
            if (found.Length != allSpots.Count)
            {
                allSpots.Clear();
                allSpots.AddRange(found);
            }
        }

        private void BuildTagButton()
        {
            var go = new GameObject("SeekerInspectButton_Canvas");
            go.transform.SetParent(transform);
            go.transform.localScale = Vector3.one * 0.002f;

            var cv       = go.AddComponent<Canvas>();
            cv.renderMode  = RenderMode.WorldSpace;
            cv.worldCamera = Camera.main;
            go.AddComponent<UnityEngine.UI.CanvasScaler>();
            go.AddComponent<TrackedDeviceGraphicRaycaster>();
            go.AddComponent<GraphicRaycaster>(); // Enables standard PC mouse clicking

            btnGroup              = go.AddComponent<CanvasGroup>();
            btnGroup.alpha        = 0f;
            btnGroup.interactable = false;
            btnGroup.blocksRaycasts = false;

            btnCanvas = cv;

            var panel = new GameObject("Panel");
            panel.transform.SetParent(go.transform, false);
            var rt = panel.AddComponent<RectTransform>();
            rt.sizeDelta = new Vector2(200f, 70f);
            btnImage = panel.AddComponent<Image>();
            btnImage.color = new Color(0.8f, 0.5f, 0.1f, 0.85f); // Default orange for INSPECT

            tagBtn = panel.AddComponent<Button>();
            var cb = tagBtn.colors;
            cb.normalColor      = Color.white;
            cb.highlightedColor = new Color(1f, 0.8f, 0.8f);
            cb.pressedColor     = new Color(0.5f, 0.5f, 0.5f);
            tagBtn.colors       = cb;
            tagBtn.onClick.AddListener(OnInspectClicked);

            var lgo = new GameObject("Label");
            lgo.transform.SetParent(panel.transform, false);
            var lr = lgo.AddComponent<RectTransform>();
            lr.anchorMin = Vector2.zero; lr.anchorMax = Vector2.one;
            lr.offsetMin = lr.offsetMax = Vector2.zero;

            btnText       = lgo.AddComponent<TextMeshProUGUI>();
            btnText.text      = "INSPECT";
            btnText.fontSize  = 28f;
            btnText.fontStyle = FontStyles.Bold;
            btnText.color     = Color.white;
            btnText.alignment = TextAlignmentOptions.Center;
        }
    }
}
