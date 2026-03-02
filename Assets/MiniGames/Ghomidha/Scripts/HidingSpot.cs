using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.UI;

namespace Ghomidha
{
    /// <summary>
    /// Attach this to any hiding spot object (e.g. a tree).
    ///
    /// HOW IT WORKS:
    /// - A World Space Canvas with a transparent "HIDE" button floats in front of the object.
    /// - When the player enters the proximity trigger, the button fades in.
    /// - When the player leaves, the button fades out.
    /// - Clicking the button teleports the XR Origin to the hidePosition.
    ///
    /// SETUP:
    /// 1. Place this script on the hiding object (e.g. Tree).
    /// 2. Add a Sphere Collider set to Is Trigger — this is the proximity zone.
    /// 3. Set hidePosition: an empty child GameObject placed BEHIND the tree.
    /// 4. The script auto-creates the UI button canvas at runtime — no manual UI needed.
    ///    OR assign an existing canvas/button if you want full visual control.
    /// </summary>
    public class HidingSpot : MonoBehaviour
    {
        // ── Inspector ────────────────────────────────────────────────────
        [Header("Hiding Position")]
        [Tooltip("Empty child GO placed where the player will teleport to (e.g. behind the tree)")]
        [SerializeField] private Transform hidePosition;

        [Header("Button Appearance")]
        [Tooltip("Button background color (semi-transparent)")]
        [SerializeField] private Color buttonColor = new Color(0f, 0f, 0f, 0.55f);

        [Tooltip("Text shown on the button")]
        [SerializeField] private string buttonText = "👁  HIDE";

        [Tooltip("How fast the button fades in/out")]
        [SerializeField] private float fadeDuration = 0.25f;

        [Tooltip("Fixed height (Y-axis) for the button so it's comfortable to click")]
        [SerializeField] private float buttonHeight = 1.3f;

        [Header("Proximity")]
        [Tooltip("Trigger collider radius — player must be within this range to see the button")]
        [SerializeField] private float proximityRadius = 2.5f;

        // ── Runtime references ───────────────────────────────────────────
        private Canvas buttonCanvas;
        private CanvasGroup canvasGroup;
        private Button hideButton;
        private Transform xrOriginTransform;   // the XR Origin root (what we actually move)

        private bool playerInRange = false;
        private float targetAlpha = 0f;

        // ── Lifecycle ────────────────────────────────────────────────────
        private void Start()
        {
            FindXROrigin();
            BuildButtonUI();
            EnsureProximityCollider();
        }

        private void Update()
        {
            // Smooth fade
            if (canvasGroup == null) return;
            canvasGroup.alpha = Mathf.MoveTowards(
                canvasGroup.alpha, targetAlpha, Time.deltaTime / fadeDuration);

            // Always face the player camera
            if (playerInRange && Camera.main != null)
            {
                buttonCanvas.transform.LookAt(Camera.main.transform);
                buttonCanvas.transform.Rotate(0f, 180f, 0f); // flip to face camera
            }
        }

        // ── Trigger Detection ────────────────────────────────────────────
        private void OnTriggerEnter(Collider other)
        {
            if (!IsPlayerCollider(other) || playerInRange) return;
            
            playerInRange = true;
            targetAlpha = 1f;

            // Optional: get camera position directly if available
            Vector3 playerPos = Camera.main != null ? Camera.main.transform.position : other.transform.position;
            
            // Calculate a point EXACTLY halfway between the player and the hiding object
            Vector3 halfwayPoint = Vector3.Lerp(transform.position, playerPos, 0.5f);
            
            // Override the Y height so it's always at a comfortable clicking height
            halfwayPoint.y = transform.position.y + buttonHeight;

            // Unparent the canvas while active so it stays frozen in world space
            if (buttonCanvas != null)
            {
                buttonCanvas.transform.SetParent(null);
                buttonCanvas.transform.position = halfwayPoint;
                // Force world scale back — tree's large scale would otherwise inflate the button
                buttonCanvas.transform.localScale = Vector3.one * 0.004f;
            }
        }

        private void OnTriggerExit(Collider other)
        {
            if (!IsPlayerCollider(other)) return;
            playerInRange = false;
            targetAlpha = 0f;

            // Re-parent to keep the hierarchy clean when hidden
            if (buttonCanvas != null)
            {
                buttonCanvas.transform.SetParent(transform);
            }
        }

        // ── Hide Action ──────────────────────────────────────────────────
        private void OnHideButtonClicked()
        {
            if (xrOriginTransform == null || hidePosition == null)
            {
                Debug.LogWarning("[HidingSpot] Missing XR Origin or hidePosition!");
                return;
            }

            // Teleport the XR Origin to the hide position (same Y as hide point)
            xrOriginTransform.position = new Vector3(
                hidePosition.position.x,
                xrOriginTransform.position.y,   // preserve player height
                hidePosition.position.z);

            // Face toward the hiding object (so the player looks at what they're hiding behind)
            Vector3 lookDir = transform.position - hidePosition.position;
            lookDir.y = 0f;
            if (lookDir.sqrMagnitude > 0.001f)
                xrOriginTransform.rotation = Quaternion.LookRotation(lookDir);

            // Hide the button after teleporting
            targetAlpha = 0f;
            playerInRange = false;

            Debug.Log($"[HidingSpot] Player hid behind '{gameObject.name}'");
        }

        // ── UI Builder ───────────────────────────────────────────────────
        private void BuildButtonUI()
        {
            // Create the World Space Canvas
            GameObject canvasGO = new GameObject($"HideButton_Canvas_{gameObject.name}");
            canvasGO.transform.SetParent(transform);
            // Default position, will be overridden on trigger enter
            canvasGO.transform.localPosition = new Vector3(0f, buttonHeight, 0f);
            canvasGO.transform.localScale = Vector3.one * 0.004f;

            buttonCanvas = canvasGO.AddComponent<Canvas>();
            buttonCanvas.renderMode = RenderMode.WorldSpace;
            buttonCanvas.worldCamera = Camera.main;

            canvasGO.AddComponent<UnityEngine.UI.CanvasScaler>();
            // TrackedDeviceGraphicRaycaster is required for XR ray interactors to click UI
            canvasGO.AddComponent<TrackedDeviceGraphicRaycaster>();

            canvasGroup = canvasGO.AddComponent<CanvasGroup>();
            canvasGroup.alpha = 0f;               // start invisible
            canvasGroup.interactable = false;     // only interactable when visible
            canvasGroup.blocksRaycasts = false;

            // Background image (button panel)
            GameObject panelGO = new GameObject("Panel");
            panelGO.transform.SetParent(canvasGO.transform, false);
            RectTransform panelRect = panelGO.AddComponent<RectTransform>();
            panelRect.sizeDelta = new Vector2(200f, 70f);
            Image panelImage = panelGO.AddComponent<Image>();
            panelImage.color = buttonColor;

            // The actual Button component
            hideButton = panelGO.AddComponent<Button>();

            // Button hover tint
            ColorBlock colors = hideButton.colors;
            colors.normalColor = Color.white;
            colors.highlightedColor = new Color(0.8f, 1f, 0.8f, 1f);
            colors.pressedColor = new Color(0.5f, 1f, 0.5f, 1f);
            hideButton.colors = colors;

            hideButton.onClick.AddListener(OnHideButtonClicked);

            // Label
            GameObject labelGO = new GameObject("Label");
            labelGO.transform.SetParent(panelGO.transform, false);
            RectTransform labelRect = labelGO.AddComponent<RectTransform>();
            labelRect.anchorMin = Vector2.zero;
            labelRect.anchorMax = Vector2.one;
            labelRect.offsetMin = labelRect.offsetMax = Vector2.zero;

            TextMeshProUGUI label = labelGO.AddComponent<TextMeshProUGUI>();
            label.text = buttonText;
            label.fontSize = 28f;
            label.fontStyle = FontStyles.Bold;
            label.color = Color.white;
            label.alignment = TextAlignmentOptions.Center;
        }

        private void EnsureProximityCollider()
        {
            // Auto-add a sphere trigger if none exists
            SphereCollider[] cols = GetComponents<SphereCollider>();
            bool hasTrigger = false;
            foreach (var c in cols) if (c.isTrigger) { hasTrigger = true; break; }

            if (!hasTrigger)
            {
                SphereCollider sc = gameObject.AddComponent<SphereCollider>();
                sc.isTrigger = true;
                sc.radius = proximityRadius;
                Debug.Log("[HidingSpot] Auto-added SphereCollider trigger.");
            }
        }

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
            // Match anything tagged Player, or with XROrigin component in parent
            return other.CompareTag("Player") ||
                   other.GetComponentInParent<XROrigin>() != null;
        }

        // ── Enables button interactability when visible ──────────────────
        private void LateUpdate()
        {
            if (canvasGroup == null) return;
            bool visible = canvasGroup.alpha > 0.5f;
            canvasGroup.interactable = visible;
            canvasGroup.blocksRaycasts = visible;
        }

        private void OnDrawGizmosSelected()
        {
            Gizmos.color = new Color(0f, 1f, 0f, 0.2f);
            Gizmos.DrawSphere(transform.position, proximityRadius);

            if (hidePosition != null)
            {
                Gizmos.color = Color.cyan;
                Gizmos.DrawSphere(hidePosition.position, 0.15f);
                Gizmos.DrawLine(transform.position, hidePosition.position);
            }
        }
    }
}
