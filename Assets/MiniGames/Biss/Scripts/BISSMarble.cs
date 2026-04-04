using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;

namespace BISS
{
    /// <summary>
    /// Handles marble grab and throw physics for the BISS minigame.
    ///
    /// SETUP:
    /// 1. Create a Sphere GameObject (scale ~0.03 for marble size).
    /// 2. Add Rigidbody (mass=0.05, drag=0.5, angular drag=0.5).
    /// 3. Add Sphere Collider.
    /// 4. Add XRGrabInteractable component.
    /// 5. Add this script.
    /// 6. Assign the XRGrabInteractable reference in the Inspector.
    ///
    /// The marble can be grabbed with either hand. When released,
    /// the Rigidbody velocity from the throw gesture is preserved,
    /// so it flies and rolls naturally with real physics.
    /// </summary>
    [RequireComponent(typeof(Rigidbody))]
    public class BISSMarble : MonoBehaviour
    {
        // ── Inspector ────────────────────────────────────────────────────
        [Header("References")]
        [Tooltip("The XRGrabInteractable on this marble")]
        [SerializeField] private UnityEngine.XR.Interaction.Toolkit.Interactables.XRGrabInteractable grabInteractable;

        [Header("Throw Settings")]
        [Tooltip("Multiplier applied to the throw velocity (increase for stronger throws)")]
        [SerializeField] private float throwForceMultiplier = 1.5f;

        [Tooltip("Max speed the marble can be thrown at (m/s)")]
        [SerializeField] private float maxThrowSpeed = 15f;

        [Header("Rolling")]
        [Tooltip("Physics material drag applied once marble is rolling on ground")]
        [SerializeField] private float rollingLinearDrag = 0.8f;

        [Tooltip("Linear drag while marble is in the air (low value)")]
        [SerializeField] private float airLinearDrag = 0.05f;

        // ── Private state ────────────────────────────────────────────────
        private Rigidbody rb;
        private bool isHeld;
        private bool hasBeenThrown;

        // Raised when the marble stops moving after a throw
        public event System.Action OnMarbleStopped;

        // Raised as soon as the marble is released (thrown)
        public event System.Action OnMarbleThrown;

        // ── Lifecycle ────────────────────────────────────────────────────
        private void Awake()
        {
            rb = GetComponent<Rigidbody>();
            rb.interpolation = RigidbodyInterpolation.Interpolate;
            rb.collisionDetectionMode = CollisionDetectionMode.Continuous;
        }

        private void OnEnable()
        {
            if (grabInteractable == null)
                grabInteractable = GetComponent<UnityEngine.XR.Interaction.Toolkit.Interactables.XRGrabInteractable>();

            grabInteractable.selectEntered.AddListener(OnGrabbed);
            grabInteractable.selectExited.AddListener(OnReleased);
        }

        private void OnDisable()
        {
            grabInteractable.selectEntered.RemoveListener(OnGrabbed);
            grabInteractable.selectExited.RemoveListener(OnReleased);
        }

        private void FixedUpdate()
        {
            if (isHeld || !hasBeenThrown) return;

            // Switch drag based on whether we're touching the ground
            rb.linearDamping = IsGrounded() ? rollingLinearDrag : airLinearDrag;

            // Detect stopped: very low velocity after being thrown
            if (rb.linearVelocity.magnitude < 0.05f && rb.angularVelocity.magnitude < 0.05f)
            {
                rb.linearVelocity = Vector3.zero;
                rb.angularVelocity = Vector3.zero;
                hasBeenThrown = false;
                OnMarbleStopped?.Invoke();
            }
        }

        // ── Grab / Release callbacks ─────────────────────────────────────
        private void OnGrabbed(SelectEnterEventArgs args)
        {
            isHeld = true;
            hasBeenThrown = false;
            rb.isKinematic = false;  // XRGrabInteractable handles this, but make sure
        }

        private void OnReleased(SelectExitEventArgs args)
        {
            isHeld = false;
            hasBeenThrown = true;

            // Clamp throw speed
            if (rb.linearVelocity.magnitude > maxThrowSpeed)
                rb.linearVelocity = rb.linearVelocity.normalized * maxThrowSpeed;

            // Apply multiplier
            rb.linearVelocity *= throwForceMultiplier;

            OnMarbleThrown?.Invoke();
            Debug.Log($"[BISS] Marble thrown at speed: {rb.linearVelocity.magnitude:F2} m/s");
        }

        // ── Helpers ──────────────────────────────────────────────────────
        private bool IsGrounded()
        {
            // Small sphere cast downward from marble center
            return Physics.CheckSphere(
                transform.position + Vector3.down * (transform.localScale.x * 0.5f),
                transform.localScale.x * 0.55f,
                Physics.AllLayers,
                QueryTriggerInteraction.Ignore);
        }

        /// <summary>Resets marble to a new position (called at start of each turn).</summary>
        public void ResetToPosition(Vector3 position)
        {
            rb.linearVelocity = Vector3.zero;
            rb.angularVelocity = Vector3.zero;
            transform.position = position;
            hasBeenThrown = false;
            isHeld = false;
        }

        /// <summary>Returns true if the marble is currently being held by the player.</summary>
        public bool IsHeld => isHeld;

        /// <summary>Returns true if the marble has come to a full stop after being thrown.</summary>
        public bool IsStopped => !isHeld && !hasBeenThrown;
    }
}
