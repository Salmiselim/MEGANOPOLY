using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.UI;

namespace Ghomidha
{
    /// <summary>
    /// HidingSpot v3 — works in XR Simulator and on device.
    ///
    /// HOW TELEPORT WORKS:
    ///   Instead of moving the player root once (which the simulator fights because it
    ///   accumulates its own XR Origin local offset), we apply a DELTA to xrOriginTransform
    ///   every frame to keep Camera.main X/Z pinned to hidePosition.
    ///   This wins the battle against the locomotion system regardless of hierarchy.
    ///
    /// SETUP:
    ///   1. Add this to your hiding object root.
    ///   2. Create an empty child (e.g. HidePosition_Table) at eye level or floor — anywhere
    ///      you want the CAMERA to be when hiding. Drag it into Hide Position.
    ///   3. HIDE / EXIT buttons auto-created at runtime.
    /// </summary>
    public class HidingSpot : MonoBehaviour
    {
        // ── Inspector ─────────────────────────────────────────────────────
        [Header("Hiding Position")]
        [Tooltip("The camera will be pinned to this transform's X/Z while hiding.")]
        [SerializeField] private Transform hidePosition;

        [Header("Button Settings")]
        [SerializeField] private float proximityRadius = 2.5f;
        [SerializeField] private float buttonHeight    = 1.3f;
        [SerializeField] private float fadeDuration    = 0.25f;

        // ── Global state ──────────────────────────────────────────────────
        public static bool IsHiding { get; private set; } = false;
        private static HidingSpot s_activeSpot = null;

        // ── Private refs ──────────────────────────────────────────────────
        private Transform playerRoot;           // topmost ancestor of XROrigin
        private Transform xrOriginTf;           // the XROrigin transform itself
        private bool      playerInRange = false;

        // Cameras/locking
        private bool    locked = false;

        // Saved state for EXIT restore
        private Vector3    savedPlayerPos;
        private Quaternion savedPlayerRot;
        private Vector3    savedXROriginLocalPos;
        private Quaternion savedXROriginLocalRot;

        // Buttons
        private Canvas hideCvs; private CanvasGroup hideCvg; private float hideAlpha;
        private Canvas exitCvs; private CanvasGroup exitCvg; private float exitAlpha;
        private float  hideBtnCooldown = 0f;  // delay before HIDE button is clickable

        // ── Lifecycle ──────────────────────────────────────────────────────
        private void Start()
        {
            FindRefs();
            BuildButtons();
            AddProximityCollider();
        }

        private void Update()
        {
            FadeCvg(hideCvg, hideAlpha);
            FadeCvg(exitCvg, exitAlpha);
            if (hideBtnCooldown > 0f) hideBtnCooldown -= Time.deltaTime;

            // ── Per-frame position lock ──────────────────────────────────
            // We correct xrOriginTf every frame so Camera.main X/Z stays at hidePosition X/Z.
            // This defeats any locomotion or simulator system that tries to fight our teleport.
            if (locked && s_activeSpot == this && Camera.main != null && xrOriginTf != null)
            {
                float errX = hidePosition.position.x - Camera.main.transform.position.x;
                float errY = hidePosition.position.y - Camera.main.transform.position.y;
                float errZ = hidePosition.position.z - Camera.main.transform.position.z;
                xrOriginTf.position += new Vector3(errX, errY, errZ);
            }

            // Button facing
            if (playerInRange && hideCvs != null && Camera.main != null)
            {
                hideCvs.transform.LookAt(Camera.main.transform);
                hideCvs.transform.Rotate(0f, 180f, 0f);
            }
            if (locked && s_activeSpot == this && exitCvs != null && Camera.main != null)
            {
                // Keep exit button glued very close to player every frame
                Vector3 camFwd = Camera.main.transform.forward;
                Vector3 btnPos = Camera.main.transform.position + camFwd * 0.5f;
                exitCvs.transform.position = btnPos;
                exitCvs.transform.localScale = Vector3.one * 0.002f;
                exitCvs.transform.LookAt(Camera.main.transform);
                exitCvs.transform.Rotate(0f, 180f, 0f);
            }
        }

        private void LateUpdate()
        {
            // HIDE button only becomes interactable after the cooldown (prevents auto-fire on walk-in)
            bool hideReady = hideCvg != null && hideCvg.alpha > 0.5f && hideBtnCooldown <= 0f;
            SetInteractable(hideCvg, hideReady);
            SetInteractable(exitCvg, exitCvg != null && exitCvg.alpha > 0.5f);
        }

        // ── Trigger ────────────────────────────────────────────────────────
        private void OnTriggerEnter(Collider other)
        {
            if (!IsPlayer(other) || playerInRange || IsHiding) return;
            playerInRange = true;
            hideAlpha = 1f;
            hideBtnCooldown = 1.5f;   // player must be in range 1.5s before button is clickable

            Vector3 spot = hidePosition != null ? hidePosition.position : transform.position;
            Vector3 cam  = Camera.main  != null ? Camera.main.transform.position : other.transform.position;
            Vector3 mid  = Vector3.Lerp(spot, cam, 0.5f);
            mid.y = spot.y + buttonHeight;

            if (hideCvs != null)
            {
                // Place 0.5m in front of camera at eye level — close and easy to click
                Vector3 camFwd = Camera.main != null ? Camera.main.transform.forward : Vector3.forward;
                Vector3 camPos = Camera.main != null ? Camera.main.transform.position : other.transform.position;
                camFwd.y = 0f;
                if (camFwd.sqrMagnitude < 0.001f) camFwd = Vector3.forward;
                Vector3 btnPos = camPos + camFwd.normalized * 0.5f;
                btnPos.y = camPos.y;  // eye level

                hideCvs.transform.SetParent(null);
                hideCvs.transform.position   = btnPos;
                hideCvs.transform.localScale = Vector3.one * 0.002f;
            }
        }

        private void OnTriggerExit(Collider other)
        {
            if (!IsPlayer(other)) return;
            playerInRange = false;
            hideAlpha = 0f;
            if (hideCvs != null) hideCvs.transform.SetParent(transform);
        }

        // ── HIDE ───────────────────────────────────────────────────────────
        private void OnHideClicked()
        {
            if (IsHiding || hidePosition == null || xrOriginTf == null) return;

            // Save full state for restore
            savedPlayerPos          = playerRoot != null ? playerRoot.position          : Vector3.zero;
            savedPlayerRot          = playerRoot != null ? playerRoot.rotation          : Quaternion.identity;
            savedXROriginLocalPos   = xrOriginTf.localPosition;
            savedXROriginLocalRot   = xrOriginTf.localRotation;

            // Initial teleport: move xrOriginTf by the error delta so camera lands at hidePosition X/Z
            if (Camera.main != null)
            {
                float dx = hidePosition.position.x - Camera.main.transform.position.x;
                float dz = hidePosition.position.z - Camera.main.transform.position.z;
                xrOriginTf.position += new Vector3(dx, 0f, dz);
            }

            // Apply Y rotation (facing direction from hidePosition)
            float yaw = hidePosition.eulerAngles.y;
            if (playerRoot != null)
                playerRoot.rotation = Quaternion.Euler(0f, yaw, 0f);
            else
                xrOriginTf.rotation = Quaternion.Euler(0f, yaw, 0f);

            // Activate per-frame lock
            locked       = true;
            IsHiding     = true;
            s_activeSpot = this;

            // Swap buttons
            hideAlpha     = 0f;
            playerInRange = false;
            if (hideCvs != null) hideCvs.transform.SetParent(transform);
            PlaceExitButton();
            exitAlpha = 1f;

            Debug.Log($"[HidingSpot v3] Hiding at '{gameObject.name}'. Camera should be at hidePos X/Z.");
        }

        // ── EXIT ───────────────────────────────────────────────────────────
        private void OnExitClicked()
        {
            if (!IsHiding || s_activeSpot != this) return;

            locked       = false;
            IsHiding     = false;
            s_activeSpot = null;

            // Restore to pre-hide state
            if (playerRoot != null)
            {
                playerRoot.position = savedPlayerPos;
                playerRoot.rotation = savedPlayerRot;
            }
            xrOriginTf.localPosition = savedXROriginLocalPos;
            xrOriginTf.localRotation = savedXROriginLocalRot;

            exitAlpha = 0f;
            if (exitCvs != null) exitCvs.transform.SetParent(transform);

            Debug.Log($"[HidingSpot v3] Exited '{gameObject.name}'. Restored pre-hide position.");
        }

        // ── Exit button placement ──────────────────────────────────────────
        private void PlaceExitButton()
        {
            if (exitCvs == null || hidePosition == null) return;

            // Place in front of hidePosition at eye level — camera may not have settled yet
            // so we use hidePosition as the anchor, not Camera.main
            Vector3 fwd = hidePosition.forward;
            fwd.y = 0f;
            if (fwd.sqrMagnitude < 0.001f) fwd = Vector3.forward;

            Vector3 pos = hidePosition.position + fwd.normalized * 0.6f;
            // Use camera Y for eye-level placement (hidePosition.y may be at floor level)
            pos.y = Camera.main != null ? Camera.main.transform.position.y : hidePosition.position.y + 1.5f;

            exitCvs.transform.SetParent(null);
            exitCvs.transform.position   = pos;
            exitCvs.transform.localScale = Vector3.one * 0.004f;
        }

        // ── Find refs ──────────────────────────────────────────────────────
        private void FindRefs()
        {
            XROrigin origin = FindFirstObjectByType<XROrigin>();
            if (origin == null) { Debug.LogWarning("[HidingSpot] No XROrigin!"); return; }

            xrOriginTf = origin.transform;

            // Walk to topmost parent
            Transform root = xrOriginTf;
            while (root.parent != null) root = root.parent;
            playerRoot = root;

            Debug.Log($"[HidingSpot v3] XROrigin='{xrOriginTf.name}'  PlayerRoot='{playerRoot.name}'");
        }

        // ── Helpers ────────────────────────────────────────────────────────
        private bool IsPlayer(Collider c)
            => c.CompareTag("Player") || c.GetComponentInParent<XROrigin>() != null;

        private void FadeCvg(CanvasGroup g, float target)
        {
            if (g != null)
                g.alpha = Mathf.MoveTowards(g.alpha, target, Time.deltaTime / fadeDuration);
        }

        private void SetInteractable(CanvasGroup g, bool v)
        {
            if (g == null) return;
            g.interactable = v; g.blocksRaycasts = v;
        }

        // ── Collider ───────────────────────────────────────────────────────
        private void AddProximityCollider()
        {
            foreach (var c in GetComponents<SphereCollider>())
                if (c.isTrigger) return;

            SphereCollider sc = gameObject.AddComponent<SphereCollider>();
            sc.isTrigger = true;
            sc.radius    = proximityRadius / Mathf.Max(transform.lossyScale.x, 0.001f);
            if (hidePosition != null)
                sc.center = transform.InverseTransformPoint(hidePosition.position);
        }

        // ── UI ─────────────────────────────────────────────────────────────
        private void BuildButtons()
        {
            Vector3 init = hidePosition != null
                ? hidePosition.position + Vector3.up * buttonHeight
                : transform.position    + Vector3.up * buttonHeight;

            hideCvs = MakeCvs($"Hide_{name}", init, out hideCvg);
            MakePanel(hideCvs.gameObject, new Color(0.05f, 0.05f, 0.05f, 0.8f), "[ HIDE ]")
                .onClick.AddListener(OnHideClicked);

            exitCvs = MakeCvs($"Exit_{name}", init, out exitCvg);
            MakePanel(exitCvs.gameObject, new Color(0.55f, 0.05f, 0.05f, 0.8f), "[ EXIT ]")
                .onClick.AddListener(OnExitClicked);
        }

        private Canvas MakeCvs(string n, Vector3 pos, out CanvasGroup cvg)
        {
            var go = new GameObject(n);
            go.transform.SetParent(transform);
            go.transform.position   = pos;
            go.transform.localScale = Vector3.one * 0.004f;

            var cv       = go.AddComponent<Canvas>();
            cv.renderMode  = RenderMode.WorldSpace;
            cv.worldCamera = Camera.main;
            go.AddComponent<UnityEngine.UI.CanvasScaler>();
            go.AddComponent<TrackedDeviceGraphicRaycaster>();

            cvg                = go.AddComponent<CanvasGroup>();
            cvg.alpha          = 0f;
            cvg.interactable   = false;
            cvg.blocksRaycasts = false;
            return cv;
        }

        private Button MakePanel(GameObject cvs, Color col, string lbl)
        {
            var p = new GameObject("Panel");
            p.transform.SetParent(cvs.transform, false);
            var rt = p.AddComponent<RectTransform>();
            // Exit button is smaller so it fits in tight hiding spaces
            bool isExit = lbl == "[ EXIT ]";
            rt.sizeDelta = isExit ? new Vector2(140f, 50f) : new Vector2(220f, 70f);
            p.AddComponent<Image>().color = col;

            var btn = p.AddComponent<Button>();
            var cb  = btn.colors;
            cb.normalColor      = Color.white;
            cb.highlightedColor = new Color(1f, 1f, 0.7f);
            cb.pressedColor     = new Color(0.6f, 1f, 0.6f);
            btn.colors = cb;

            var lgo = new GameObject("Label");
            lgo.transform.SetParent(p.transform, false);
            var lr = lgo.AddComponent<RectTransform>();
            lr.anchorMin = Vector2.zero; lr.anchorMax = Vector2.one;
            lr.offsetMin = lr.offsetMax = Vector2.zero;
            var tmp       = lgo.AddComponent<TextMeshProUGUI>();
            tmp.text      = lbl;
            tmp.fontSize  = 26f;
            tmp.fontStyle = FontStyles.Bold;
            tmp.color     = Color.white;
            tmp.alignment = TextAlignmentOptions.Center;
            return btn;
        }

        // ── Gizmos ─────────────────────────────────────────────────────────
        private void OnDrawGizmosSelected()
        {
            Vector3 c = hidePosition != null ? hidePosition.position : transform.position;
            Gizmos.color = new Color(0f, 1f, 0f, 0.18f);
            Gizmos.DrawSphere(c, proximityRadius);
            if (hidePosition != null)
            {
                Gizmos.color = Color.cyan;
                Gizmos.DrawSphere(hidePosition.position, 0.12f);
            }
        }
    }
}
