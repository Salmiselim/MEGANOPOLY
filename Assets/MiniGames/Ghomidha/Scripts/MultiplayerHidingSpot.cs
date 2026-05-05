using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.UI;
using Unity.Netcode;

namespace Ghomidha
{
    public class MultiplayerHidingSpot : NetworkBehaviour
    {
        [Header("Hiding Position")]
        [Tooltip("The camera will be pinned to this transform's X/Z while hiding.")]
        [SerializeField] private Transform hidePosition;

        [Header("Button Settings")]
        [SerializeField] private float proximityRadius = 2.5f;
        [SerializeField] private float buttonHeight    = 1.3f;
        [SerializeField] private float fadeDuration    = 0.25f;

        // ── Network state ─────────────────────────────────────────────────
        // MaxValue means empty. Otherwise, it holds the client ID of the hider.
        public NetworkVariable<ulong> occupyingClientId = new NetworkVariable<ulong>(ulong.MaxValue);

        /// <summary>World position of the actual hide point (used by seeker for distance checks).</summary>
        public Vector3 HideWorldPosition => hidePosition != null ? hidePosition.position : transform.position;

        // ── Global local state ────────────────────────────────────────────
        public static bool LocalPlayerIsHiding { get; private set; } = false;
        private static MultiplayerHidingSpot s_activeSpot = null;

        // ── Private refs ──────────────────────────────────────────────────
        private Transform playerRoot;           
        private Transform xrOriginTf;           
        private bool      playerInRange = false;
        private bool      locked = false;

        // Saved state for EXIT restore
        private Vector3    savedPlayerPos;
        private Quaternion savedPlayerRot;
        private Vector3    savedXROriginLocalPos;
        private Quaternion savedXROriginLocalRot;

        // Buttons
        private Canvas hideCvs; private CanvasGroup hideCvg; private float hideAlpha;
        private Canvas exitCvs; private CanvasGroup exitCvg; private float exitAlpha;
        private float  hideBtnCooldown = 0f;

        // Role helper — uses lobby-assigned role when available, falls back to IsHost for direct testing
        private bool LocalPlayerIsSeeker =>
            GhomidhaRoleManager.Instance != null
                ? GhomidhaRoleManager.Instance.IsSeeker
                : IsHost;

        private void Start()
        {
            FindRefs();
            BuildButtons();
            AddProximityCollider();

            // Apply seeker/hider button visibility here — after buttons are built.
            // OnNetworkSpawn can fire before Start in Netcode scene loading, so
            // hideCvs/exitCvs would be null if we put this check in OnNetworkSpawn.
            if (IsSpawned)
                ApplyRoleVisibility();
        }

        public override void OnNetworkSpawn()
        {
            // Only apply if Start has already run (buttons exist).
            // If Start hasn't run yet it will call ApplyRoleVisibility() itself.
            if (hideCvs != null || exitCvs != null)
                ApplyRoleVisibility();
        }

        private void ApplyRoleVisibility()
        {
            // The seeker should NEVER see hide/exit buttons.
            if (LocalPlayerIsSeeker)
            {
                if (hideCvs != null) hideCvs.gameObject.SetActive(false);
                if (exitCvs != null) exitCvs.gameObject.SetActive(false);
            }
        }

        private void Update()
        {
            // Do not process hiding mechanics for the seeker
            if (IsSpawned && LocalPlayerIsSeeker) return;

            FadeCvg(hideCvg, hideAlpha);
            FadeCvg(exitCvg, exitAlpha);
            if (hideBtnCooldown > 0f) hideBtnCooldown -= Time.deltaTime;

            if (locked && s_activeSpot == this && Camera.main != null && xrOriginTf != null)
            {
                float errX = hidePosition.position.x - Camera.main.transform.position.x;
                float errY = hidePosition.position.y - Camera.main.transform.position.y;
                float errZ = hidePosition.position.z - Camera.main.transform.position.z;
                xrOriginTf.position += new Vector3(errX, errY, errZ);
            }

            if (playerInRange && hideCvs != null && Camera.main != null)
            {
                hideCvs.transform.LookAt(Camera.main.transform);
                hideCvs.transform.Rotate(0f, 180f, 0f);
            }
            if (locked && s_activeSpot == this && exitCvs != null && Camera.main != null)
            {
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
            if (IsSpawned && LocalPlayerIsSeeker) return;

            bool hideReady = hideCvg != null && hideCvg.alpha > 0.5f && hideBtnCooldown <= 0f;
            SetInteractable(hideCvg, hideReady);
            SetInteractable(exitCvg, exitCvg != null && exitCvg.alpha > 0.5f);
        }

        private void OnTriggerEnter(Collider other)
        {
            if (!IsSpawned || LocalPlayerIsSeeker) return; // Seeker never sees hide buttons
            if (!IsPlayer(other) || playerInRange || LocalPlayerIsHiding) return;
            
            // If someone else is in the spot, don't show the button
            if (occupyingClientId.Value != ulong.MaxValue && occupyingClientId.Value != NetworkManager.Singleton.LocalClientId) return;

            playerInRange = true;
            hideAlpha = 1f;
            hideBtnCooldown = 1.5f;

            Vector3 spot = hidePosition != null ? hidePosition.position : transform.position;
            Vector3 cam  = Camera.main  != null ? Camera.main.transform.position : other.transform.position;
            
            if (hideCvs != null)
            {
                Vector3 camFwd = Camera.main != null ? Camera.main.transform.forward : Vector3.forward;
                Vector3 camPos = Camera.main != null ? Camera.main.transform.position : other.transform.position;
                camFwd.y = 0f;
                if (camFwd.sqrMagnitude < 0.001f) camFwd = Vector3.forward;
                Vector3 btnPos = camPos + camFwd.normalized * 0.5f;
                btnPos.y = camPos.y; 

                hideCvs.transform.SetParent(null);
                hideCvs.transform.position   = btnPos;
                hideCvs.transform.localScale = Vector3.one * 0.002f;
            }
        }

        private void OnTriggerExit(Collider other)
        {
            if (!IsSpawned || LocalPlayerIsSeeker) return;
            if (!IsPlayer(other)) return;
            playerInRange = false;
            hideAlpha = 0f;
            if (hideCvs != null) hideCvs.transform.SetParent(transform);
        }

        private void OnHideClicked()
        {
            if (LocalPlayerIsHiding || hidePosition == null || xrOriginTf == null) return;
            if (occupyingClientId.Value != ulong.MaxValue) return; // Already occupied by someone

            savedPlayerPos          = playerRoot != null ? playerRoot.position          : Vector3.zero;
            savedPlayerRot          = playerRoot != null ? playerRoot.rotation          : Quaternion.identity;
            savedXROriginLocalPos   = xrOriginTf.localPosition;
            savedXROriginLocalRot   = xrOriginTf.localRotation;

            if (Camera.main != null)
            {
                float dx = hidePosition.position.x - Camera.main.transform.position.x;
                float dz = hidePosition.position.z - Camera.main.transform.position.z;
                xrOriginTf.position += new Vector3(dx, 0f, dz);
            }

            float yaw = hidePosition.eulerAngles.y;
            if (playerRoot != null)
                playerRoot.rotation = Quaternion.Euler(0f, yaw, 0f);
            else
                xrOriginTf.rotation = Quaternion.Euler(0f, yaw, 0f);

            locked             = true;
            LocalPlayerIsHiding = true;
            s_activeSpot       = this;

            hideAlpha     = 0f;
            playerInRange = false;
            if (hideCvs != null) hideCvs.transform.SetParent(transform);
            PlaceExitButton();
            exitAlpha = 1f;

            // Notify server that we took the spot
            ClaimSpotServerRpc(NetworkManager.Singleton.LocalClientId);

            Debug.Log($"[MultiplayerHidingSpot] Hiding at '{gameObject.name}'.");
        }

        [ServerRpc(RequireOwnership = false)]
        private void ClaimSpotServerRpc(ulong clientId)
        {
            occupyingClientId.Value = clientId;
        }

        private void OnExitClicked()
        {
            if (!LocalPlayerIsHiding || s_activeSpot != this) return;

            locked             = false;
            LocalPlayerIsHiding = false;
            s_activeSpot       = null;

            if (playerRoot != null)
            {
                playerRoot.position = savedPlayerPos;
                playerRoot.rotation = savedPlayerRot;
            }
            xrOriginTf.localPosition = savedXROriginLocalPos;
            xrOriginTf.localRotation = savedXROriginLocalRot;

            exitAlpha = 0f;
            if (exitCvs != null) exitCvs.transform.SetParent(transform);

            // Notify server we left
            ExitSpotServerRpc();

            Debug.Log($"[MultiplayerHidingSpot] Exited '{gameObject.name}'.");
        }

        [ServerRpc(RequireOwnership = false)]
        private void ExitSpotServerRpc()
        {
            occupyingClientId.Value = ulong.MaxValue;
        }

        // Called by MultiplayerSeekerController — works regardless of whether seeker is host or client
        public void RevealHiderBySeeker()
        {
            if (IsServer)
                DoReveal();
            else
                RevealSpotServerRpc();
        }

        [ServerRpc(RequireOwnership = false)]
        private void RevealSpotServerRpc()
        {
            DoReveal();
        }

        private void DoReveal()
        {
            ulong hiderId = occupyingClientId.Value;
            if (hiderId != ulong.MaxValue)
            {
                occupyingClientId.Value = ulong.MaxValue;
                ForceExitClientRpc(hiderId);
            }
        }

        [ClientRpc]
        private void ForceExitClientRpc(ulong hiderId)
        {
            // Only the targeted hider processes this
            if (NetworkManager.Singleton.LocalClientId == hiderId)
            {
                Debug.Log($"[MultiplayerHidingSpot] Spot '{gameObject.name}' revealed by seeker!");
                OnExitClicked();
            }
        }

        private void PlaceExitButton()
        {
            if (exitCvs == null || hidePosition == null) return;
            Vector3 fwd = hidePosition.forward;
            fwd.y = 0f;
            if (fwd.sqrMagnitude < 0.001f) fwd = Vector3.forward;

            Vector3 pos = hidePosition.position + fwd.normalized * 0.6f;
            pos.y = Camera.main != null ? Camera.main.transform.position.y : hidePosition.position.y + 1.5f;

            exitCvs.transform.SetParent(null);
            exitCvs.transform.position   = pos;
            exitCvs.transform.localScale = Vector3.one * 0.004f;
        }

        private void FindRefs()
        {
            XROrigin origin = FindFirstObjectByType<XROrigin>();
            if (origin == null) return;

            xrOriginTf = origin.transform;
            Transform root = xrOriginTf;
            while (root.parent != null) root = root.parent;
            playerRoot = root;
        }

        private bool IsPlayer(Collider c) => c.CompareTag("Player") || c.GetComponentInParent<XROrigin>() != null;

        private void FadeCvg(CanvasGroup g, float target)
        {
            if (g != null) g.alpha = Mathf.MoveTowards(g.alpha, target, Time.deltaTime / fadeDuration);
        }

        private void SetInteractable(CanvasGroup g, bool v)
        {
            if (g == null) return;
            g.interactable = v; g.blocksRaycasts = v;
        }

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

        private void BuildButtons()
        {
            Vector3 init = hidePosition != null ? hidePosition.position + Vector3.up * buttonHeight : transform.position + Vector3.up * buttonHeight;
            hideCvs = MakeCvs($"Hide_{name}", init, out hideCvg);
            MakePanel(hideCvs.gameObject, new Color(0.05f, 0.05f, 0.05f, 0.8f), "[ HIDE ]").onClick.AddListener(OnHideClicked);

            exitCvs = MakeCvs($"Exit_{name}", init, out exitCvg);
            MakePanel(exitCvs.gameObject, new Color(0.55f, 0.05f, 0.05f, 0.8f), "[ EXIT ]").onClick.AddListener(OnExitClicked);
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
            go.AddComponent<GraphicRaycaster>(); // Enables standard PC mouse clicking

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
    }
}
