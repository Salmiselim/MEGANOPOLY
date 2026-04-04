using UnityEngine;

namespace BISS
{
    /// <summary>
    /// Represents the target hole (marked by a red X on the ground).
    /// Detects when the marble enters the hole radius and measures distance.
    ///
    /// SETUP:
    /// 1. Create an empty GameObject at the hole position on the ground.
    /// 2. Add this script.
    /// 3. Add a Sphere Collider → set Is Trigger = true → Radius ~0.15 (hole radius).
    /// 4. Optionally place a red X quad/decal as a child for visuals.
    /// 5. Reference this object in BISSTurnManager.
    /// </summary>
    public class BISSHoleTarget : MonoBehaviour
    {
        // ── Inspector ────────────────────────────────────────────────────
        [Header("Hole Settings")]
        [Tooltip("Radius within which a marble counts as 'scored' (should match trigger collider radius)")]
        [SerializeField] private float holeRadius = 0.15f;

        [Header("Visuals")]
        [Tooltip("The red X visual child object — used for scale/glow effects")]
        [SerializeField] private Renderer targetRenderer;

        [Tooltip("Color when no marble is nearby")]
        [SerializeField] private Color normalColor = Color.red;

        [Tooltip("Color when a marble is close (proximity glow)")]
        [SerializeField] private Color nearColor = Color.yellow;

        [Tooltip("Color when a marble has scored")]
        [SerializeField] private Color scoredColor = Color.green;

        [Header("Proximity Feedback")]
        [Tooltip("Distance at which the target starts glowing yellow")]
        [SerializeField] private float proximityGlowDistance = 1.0f;

        // ── Events ───────────────────────────────────────────────────────
        /// <summary>Fired when a marble enters the hole. Passes the marble GameObject.</summary>
        public event System.Action<GameObject> OnMarbleScored;

        // ── Private state ────────────────────────────────────────────────
        private static readonly int s_ColorProp = Shader.PropertyToID("_BaseColor");
        private MaterialPropertyBlock mpb;

        // ── Lifecycle ────────────────────────────────────────────────────
        private void Awake()
        {
            mpb = new MaterialPropertyBlock();
            SetTargetColor(normalColor);
        }

        private void OnTriggerEnter(Collider other)
        {
            if (!other.CompareTag("BISSMarble")) return;

            SetTargetColor(scoredColor);
            Debug.Log($"[BISS] Marble scored! Object: {other.gameObject.name}");
            OnMarbleScored?.Invoke(other.gameObject);
        }

        private void OnTriggerExit(Collider other)
        {
            if (!other.CompareTag("BISSMarble")) return;
            SetTargetColor(normalColor);
        }

        // ── Public API ───────────────────────────────────────────────────

        /// <summary>
        /// Returns the straight-line distance from the marble to this hole.
        /// Call this every frame while marble is stopped to show on UI.
        /// </summary>
        public float GetDistanceTo(Vector3 marblePosition)
        {
            return Vector3.Distance(
                new Vector3(marblePosition.x, transform.position.y, marblePosition.z),
                transform.position);
        }

        /// <summary>
        /// Updates proximity glow based on marble distance.
        /// Called by BISSTurnManager each frame after marble stops.
        /// </summary>
        public void UpdateProximityFeedback(Vector3 marblePosition)
        {
            float dist = GetDistanceTo(marblePosition);

            if (dist <= holeRadius)
                SetTargetColor(scoredColor);
            else if (dist <= proximityGlowDistance)
                SetTargetColor(Color.Lerp(nearColor, normalColor, dist / proximityGlowDistance));
            else
                SetTargetColor(normalColor);
        }

        /// <summary>Resets the visual to the default red state.</summary>
        public void ResetVisual()
        {
            SetTargetColor(normalColor);
        }

        // ── Helpers ──────────────────────────────────────────────────────
        private void SetTargetColor(Color color)
        {
            if (targetRenderer == null) return;
            targetRenderer.GetPropertyBlock(mpb);
            mpb.SetColor(s_ColorProp, color);
            targetRenderer.SetPropertyBlock(mpb);
        }

        private void OnDrawGizmosSelected()
        {
            Gizmos.color = Color.red;
            Gizmos.DrawWireSphere(transform.position, holeRadius);
            Gizmos.color = new Color(1, 1, 0, 0.2f);
            Gizmos.DrawWireSphere(transform.position, proximityGlowDistance);
        }
    }
}
