using UnityEngine;

namespace RockPaperScissors
{
    /// <summary>
    /// Drives the Flint character's Animator based on:
    ///   - Player movement (Idle / Walk) on the Base Layer
    ///   - Hand gesture detected by HandShapeDetector (Rock/Paper/Scissors) on the Hand Layer
    ///
    /// SETUP:
    /// 1. Attach this script to the Flint character GameObject in the RPS scene
    /// 2. Assign the Animator, HandShapeDetector, and the player Transform in the Inspector
    /// 3. In the Animator Controller make sure these Int parameters exist:
    ///      "State"   → 0=Idle, 1=Walk  (Base Layer)
    ///      "Gesture" → 0=None, 1=Rock, 2=Paper, 3=Scissors  (Hand Layer)
    /// </summary>
    public class FlintCharacterAnimator : MonoBehaviour
    {
        [Header("References")]
        [Tooltip("The Animator on the Flint character")]
        [SerializeField] private Animator animator;

        [Tooltip("The HandShapeDetector in the scene (on the GameManager or XR Rig)")]
        [SerializeField] private HandShapeDetector handDetector;

        [Tooltip("The player Transform — used to detect if player is walking")]
        [SerializeField] private Transform playerTransform;

        [Header("Walk Settings")]
        [Tooltip("Minimum speed before switching to Walk animation")]
        [SerializeField] private float walkThreshold = 0.05f;

        // ── Animator parameter names ──────────────────────────────────────────
        private static readonly int ParamState   = Animator.StringToHash("State");
        private static readonly int ParamGesture = Animator.StringToHash("Gesture");

        // ── State ─────────────────────────────────────────────────────────────
        private Vector3 _lastPosition;

        // ── Gesture int values ────────────────────────────────────────────────
        private const int GESTURE_NONE     = 0;
        private const int GESTURE_ROCK     = 1;
        private const int GESTURE_PAPER    = 2;
        private const int GESTURE_SCISSORS = 3;

        // ── State int values ──────────────────────────────────────────────────
        private const int STATE_IDLE = 0;
        private const int STATE_WALK = 1;

        // ─────────────────────────────────────────────────────────────────────
        private void Start()
        {
            if (playerTransform != null)
                _lastPosition = playerTransform.position;

            if (animator == null)
                animator = GetComponent<Animator>();
        }

        private void Update()
        {
            UpdateMovementState();
            UpdateGestureState();
        }

        // ── Movement (Base Layer) ─────────────────────────────────────────────

        private void UpdateMovementState()
        {
            if (playerTransform == null || animator == null) return;

            float speed = Vector3.Distance(playerTransform.position, _lastPosition) / Time.deltaTime;
            _lastPosition = playerTransform.position;

            int state = speed > walkThreshold ? STATE_WALK : STATE_IDLE;
            animator.SetInteger(ParamState, state);
        }

        // ── Gesture (Hand Layer) ──────────────────────────────────────────────

        private void UpdateGestureState()
        {
            if (animator == null) return;

            int gesture = GESTURE_NONE;

            if (handDetector != null)
            {
                // Use right hand gesture — change to LeftHandShape if needed
                switch (handDetector.RightHandShape)
                {
                    case HandShapeDetector.HandShape.Rock:     gesture = GESTURE_ROCK;     break;
                    case HandShapeDetector.HandShape.Paper:    gesture = GESTURE_PAPER;    break;
                    case HandShapeDetector.HandShape.Scissors: gesture = GESTURE_SCISSORS; break;
                    default:                                   gesture = GESTURE_NONE;     break;
                }
            }

            animator.SetInteger(ParamGesture, gesture);

            // Debug log when gesture changes
            int current = animator.GetInteger(ParamGesture);
            if (current != gesture)
                Debug.Log($"[FlintAnimator] Gesture changed to: {gesture}");
        }

        // ── Public API (called by buttons / game manager) ─────────────────────

        /// <summary>Force a specific gesture — used when player picks Rock/Paper/Scissors via button.</summary>
        public void SetGesture(int gestureId)
        {
            if (animator != null)
                animator.SetInteger(ParamGesture, gestureId);
        }

        /// <summary>Trigger Victory animation on the Base Layer.</summary>
        public void PlayVictory()
        {
            if (animator != null)
                animator.SetInteger(ParamState, 2);  // 2 = Victory
        }

        /// <summary>Trigger Defeated animation on the Base Layer.</summary>
        public void PlayDefeated()
        {
            if (animator != null)
                animator.SetInteger(ParamState, 3);  // 3 = Defeated
        }

        /// <summary>Return to Idle.</summary>
        public void PlayIdle()
        {
            if (animator != null)
            {
                animator.SetInteger(ParamState, STATE_IDLE);
                animator.SetInteger(ParamGesture, GESTURE_NONE);
            }
        }
    }
}
