using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.UI;

namespace Ghomidha
{
    /// <summary>
    /// Attach this to any hiding spot object (table, box, tree, etc.)
    ///
    /// FEATURES:
    /// - HIDE button appears when player enters proximity (only if not already hiding)
    /// - Player teleports to hidePosition (X/Z only, Y frozen)
    /// - Player movement is locked while hiding (head rotation still free)
    /// - UNHIDE button appears in front of the player while hiding
    /// - UNHIDE restores free movement and hides the button
    /// - Static IsHiding flag shared across all HidingSpot instances
    ///
    /// SETUP:
    /// 1. Place this script on the hiding object root.
    /// 2. Create an empty child GO (e.g. HidePosition_Table) where the player should stand.
    /// 3. Assign it to the Hide Position field.
    /// 4. Done — all colliders and buttons are auto-created.
    /// </summary>
    public class HidingSpot : MonoBehaviour
    {
        // ── Inspector ────────────────────────────────────────────────────
        [Header("Hiding Position")]
        [Tooltip("Empty child GO placed where the player will teleport to")]
        [SerializeField] private Transform hidePosition;

        [Header("Button Appearance")]
        [SerializeField] private Color hideButtonColor   = new Color(0.05f, 0.05f, 0.05f, 0.75f);
        [SerializeField] private Color unhideButtonColor = new Color(0.6f,  0.1f,  0.1f,  0.75f);
        [SerializeField] private string hideText   = "👁  HIDE";
        [SerializeField] private string unhideText = "✖  UNHIDE";
        [SerializeField] private float fadeDuration  = 0.25f;
        [SerializeField] private float buttonHeight  = 1.3f;

        [Header("Proximity")]
        [SerializeField] private float proximityRadius = 2.5f;

        // ── Global hiding state (shared across all HidingSpot instances) ─
        public static bool IsHiding { get; private set; } = false;
        private static HidingSpot s_activeSpot = null;

        // ── Runtime references ───────────────────────────────────────────
        private Canvas     hideCanvas,   unhideCanvas;
        private CanvasGroup hideGroup,   unhideGroup;
        private float      hideAlpha,    unhideAlpha;          // target alphas

        private Transform xrOriginTransform;

        private bool  playerInRange  = false;
        private bool  positionLocked = false;
        private Vector3 lockedXZ;          // world X/Z the player is locked to while hiding

        // Snapshot of where the player was BEFORE hiding — restored on UNHIDE
        private Vector3    preHideOriginPosition;
        private Quaternion preHideOriginRotation;

        // ── Lifecycle ────────────────────────────────────────────────────
        private void Start()
        {
            FindXROrigin();
            BuildHideButton();
            BuildUnhideButton();
            EnsureProximityCollider();
        }

        private void Update()
        {
            // ── Smooth fade for both canvases ──
            FadeCanvas(hideGroup,   ref hideAlpha);
            FadeCanvas(unhideGroup, ref unhideAlpha);

            // ── Lock movement while hiding at THIS spot ──
            if (positionLocked && xrOriginTransform != null)
            {
                xrOriginTransform.position = new Vector3(
                    lockedXZ.x,
                    xrOriginTransform.position.y,   // Y always free (gravity / floor)
                    lockedXZ.z);
            }

            // ── HIDE button always faces the camera ──
            if (playerInRange && Camera.main != null && hideCanvas != null)
            {
                hideCanvas.transform.LookAt(Camera.main.transform);
                hideCanvas.transform.Rotate(0f, 180f, 0f);
            }

            // ── UNHIDE button always faces the camera ──
            if (positionLocked && Camera.main != null && unhideCanvas != null)
            {
                unhideCanvas.transform.LookAt(Camera.main.transform);
                unhideCanvas.transform.Rotate(0f, 180f, 0f);
            }
        }

        private void LateUpdate()
        {
            SetInteractable(hideGroup,   hideAlpha   > 0.5f);
            SetInteractable(unhideGroup, unhideAlpha > 0.5f);
        }

        // ── Trigger Detection ────────────────────────────────────────────
        private void OnTriggerEnter(Collider other)
        {
            if (!IsPlayerCollider(other) || playerInRange) return;
            if (IsHiding) return;    // already hiding somewhere — don't show another button

            playerInRange = true;
            hideAlpha = 1f;

            // Place HIDE button halfway between the player and the hiding spot
            Vector3 spotPos   = hidePosition != null ? hidePosition.position : transform.position;
            Vector3 playerPos = Camera.main  != null ? Camera.main.transform.position : other.transform.position;
            Vector3 midPoint  = Vector3.Lerp(spotPos, playerPos, 0.5f);
            midPoint.y = spotPos.y + buttonHeight;

            if (hideCanvas != null)
            {
                hideCanvas.transform.SetParent(null);
                hideCanvas.transform.position   = midPoint;
                hideCanvas.transform.localScale = Vector3.one * 0.004f;
            }
        }

        private void OnTriggerExit(Collider other)
        {
            if (!IsPlayerCollider(other)) return;
            playerInRange = false;
            hideAlpha = 0f;

            if (hideCanvas != null)
                hideCanvas.transform.SetParent(transform);
        }

        // ── Hide Action ──────────────────────────────────────────────────
        private void OnHideButtonClicked()
        {
            if (IsHiding)                            return;  // already hiding
            if (xrOriginTransform == null || hidePosition == null) return;

            // ── Teleport: camera lands at hidePosition X/Z ──
            Vector3 camOffset = Vector3.zero;
            if (Camera.main != null)
            {
                camOffset.x = Camera.main.transform.position.x - xrOriginTransform.position.x;
                camOffset.z = Camera.main.transform.position.z - xrOriginTransform.position.z;
            }

            // ── Save pre-hide position so we can restore it on UNHIDE ──
            preHideOriginPosition = xrOriginTransform.position;
            preHideOriginRotation = xrOriginTransform.rotation;

            float targetX = hidePosition.position.x - camOffset.x;
            float targetZ = hidePosition.position.z - camOffset.z;

            xrOriginTransform.position = new Vector3(targetX, xrOriginTransform.position.y, targetZ);
            xrOriginTransform.rotation = hidePosition.rotation;

            // ── Lock movement at this position ──
            lockedXZ      = new Vector3(targetX, 0f, targetZ);
            positionLocked = true;

            // ── Update global state ──
            IsHiding    = true;
            s_activeSpot = this;

            // ── Hide the HIDE button, show the UNHIDE button ──
            hideAlpha   = 0f;
            playerInRange = false;
            if (hideCanvas != null) hideCanvas.transform.SetParent(transform);

            PlaceUnhideButton();
            unhideAlpha = 1f;

            Debug.Log($"[HidingSpot] Player hid at '{gameObject.name}'");
        }

        // ── Unhide Action ────────────────────────────────────────────────
        private void OnUnhideButtonClicked()
        {
            if (!IsHiding || s_activeSpot != this) return;   // not hiding here

            // ── Release movement lock ──
            positionLocked = false;

            // ── Teleport back to where the player was before hiding ──
            xrOriginTransform.position = preHideOriginPosition;
            xrOriginTransform.rotation = preHideOriginRotation;

            // ── Update global state ──
            IsHiding    = false;
            s_activeSpot = null;

            // ── Hide the UNHIDE button ──
            unhideAlpha = 0f;
            if (unhideCanvas != null) unhideCanvas.transform.SetParent(transform);

            Debug.Log($"[HidingSpot] Player left hiding spot '{gameObject.name}'");
        }

        // ── UNHIDE button positioning ────────────────────────────────────
        private void PlaceUnhideButton()
        {
            if (unhideCanvas == null) return;

            // Place it slightly in front of the camera at a comfortable height
            Vector3 camPos     = Camera.main != null ? Camera.main.transform.position : xrOriginTransform.position;
            Vector3 camForward = Camera.main != null ? Camera.main.transform.forward  : xrOriginTransform.forward;
            camForward.y = 0f;
            if (camForward.sqrMagnitude < 0.001f) camForward = Vector3.forward;
            camForward.Normalize();

            Vector3 buttonPos = camPos + camForward * 0.6f;
            buttonPos.y = camPos.y - 0.1f;   // slightly below eye level

            unhideCanvas.transform.SetParent(null);
            unhideCanvas.transform.position   = buttonPos;
            unhideCanvas.transform.localScale = Vector3.one * 0.004f;
        }

        // ── UI Builders ──────────────────────────────────────────────────
        private void BuildHideButton()
        {
            hideCanvas = CreateCanvas($"HideButton_Canvas_{gameObject.name}", out hideGroup);
            Vector3 initPos = hidePosition != null
                ? hidePosition.position + Vector3.up * buttonHeight
                : transform.position    + Vector3.up * buttonHeight;
            hideCanvas.transform.position = initPos;

            Button btn = CreateButtonPanel(hideCanvas.gameObject, hideButtonColor, hideText);
            btn.onClick.AddListener(OnHideButtonClicked);
        }

        private void BuildUnhideButton()
        {
            unhideCanvas = CreateCanvas($"UnhideButton_Canvas_{gameObject.name}", out unhideGroup);
            unhideCanvas.transform.position = transform.position + Vector3.up * buttonHeight;

            Button btn = CreateButtonPanel(unhideCanvas.gameObject, unhideButtonColor, unhideText);
            btn.onClick.AddListener(OnUnhideButtonClicked);
        }

        private Canvas CreateCanvas(string name, out CanvasGroup group)
        {
            GameObject go = new GameObject(name);
            go.transform.SetParent(transform);
            go.transform.localScale = Vector3.one * 0.004f;

            Canvas canvas = go.AddComponent<Canvas>();
            canvas.renderMode  = RenderMode.WorldSpace;
            canvas.worldCamera = Camera.main;

            go.AddComponent<UnityEngine.UI.CanvasScaler>();
            go.AddComponent<TrackedDeviceGraphicRaycaster>();

            group           = go.AddComponent<CanvasGroup>();
            group.alpha     = 0f;
            group.interactable   = false;
            group.blocksRaycasts = false;

            return canvas;
        }

        private Button CreateButtonPanel(GameObject canvasGO, Color color, string label)
        {
            GameObject panel = new GameObject("Panel");
            panel.transform.SetParent(canvasGO.transform, false);
            RectTransform rt = panel.AddComponent<RectTransform>();
            rt.sizeDelta = new Vector2(220f, 70f);

            Image img = panel.AddComponent<Image>();
            img.color = color;

            Button btn    = panel.AddComponent<Button>();
            ColorBlock cb = btn.colors;
            cb.normalColor      = Color.white;
            cb.highlightedColor = new Color(1f, 1f, 0.7f, 1f);
            cb.pressedColor     = new Color(0.7f, 1f, 0.7f, 1f);
            btn.colors          = cb;

            GameObject labelGO = new GameObject("Label");
            labelGO.transform.SetParent(panel.transform, false);
            RectTransform lr = labelGO.AddComponent<RectTransform>();
            lr.anchorMin = Vector2.zero;
            lr.anchorMax = Vector2.one;
            lr.offsetMin = lr.offsetMax = Vector2.zero;

            TextMeshProUGUI tmp = labelGO.AddComponent<TextMeshProUGUI>();
            tmp.text      = label;
            tmp.fontSize  = 26f;
            tmp.fontStyle = FontStyles.Bold;
            tmp.color     = Color.white;
            tmp.alignment = TextAlignmentOptions.Center;

            return btn;
        }

        // ── Collider ─────────────────────────────────────────────────────
        private void EnsureProximityCollider()
        {
            SphereCollider[] cols = GetComponents<SphereCollider>();
            bool hasTrigger = false;
            foreach (var c in cols) if (c.isTrigger) { hasTrigger = true; break; }

            if (!hasTrigger)
            {
                SphereCollider sc = gameObject.AddComponent<SphereCollider>();
                sc.isTrigger = true;
                float worldScale = Mathf.Max(transform.lossyScale.x, 0.001f);
                sc.radius = proximityRadius / worldScale;

                if (hidePosition != null)
                    sc.center = transform.InverseTransformPoint(hidePosition.position);

                Debug.Log("[HidingSpot] Auto-added SphereCollider trigger.");
            }
        }

        // ── Helpers ──────────────────────────────────────────────────────
        private void FindXROrigin()
        {
            XROrigin origin = FindFirstObjectByType<XROrigin>();
            if (origin != null)
                xrOriginTransform = origin.transform;
            else
                Debug.LogWarning("[HidingSpot] No XROrigin found in scene!");
        }

        private bool IsPlayerCollider(Collider other)
        {
            return other.CompareTag("Player") ||
                   other.GetComponentInParent<XROrigin>() != null;
        }

        private void FadeCanvas(CanvasGroup group, ref float target)
        {
            if (group == null) return;
            group.alpha = Mathf.MoveTowards(group.alpha, target, Time.deltaTime / fadeDuration);
        }

        private void SetInteractable(CanvasGroup group, bool state)
        {
            if (group == null) return;
            group.interactable   = state;
            group.blocksRaycasts = state;
        }

        // ── Gizmos ───────────────────────────────────────────────────────
        private void OnDrawGizmosSelected()
        {
            Vector3 center = hidePosition != null ? hidePosition.position : transform.position;

            Gizmos.color = new Color(0f, 1f, 0f, 0.2f);
            Gizmos.DrawSphere(center, proximityRadius);

            if (hidePosition != null)
            {
                Gizmos.color = Color.cyan;
                Gizmos.DrawSphere(hidePosition.position, 0.15f);
            }
        }
    }
}
