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
    /// 2. Assign the Animator and HandShapeDetector in the Inspector
    /// 3. Player Root = assign the XR Origin GameObject (NOT the Camera/Head)
    /// 4. In the Animator Controller add these Int parameters:
    ///      "State"   → 0=Idle, 1=Walk
    ///      "Gesture" → 0=None, 1=Rock, 2=Paper, 3=Scissors
    /// </summary>
    public class FlintCharacterAnimator : MonoBehaviour
    {
        [Header("References")]
        [Tooltip("The Animator on the Flint character")]
        [SerializeField] private Animator animator;

        [Tooltip("The HandShapeDetector in the scene")]
        [SerializeField] private HandShapeDetector handDetector;

        [Tooltip("XR Origin root GameObject — NOT the Camera or Head. " +
                 "This only moves when the player physically walks, not when they look around.")]
        [SerializeField] private Transform playerRoot;

        [Header("Walk Settings")]
        [Tooltip("Minimum speed (m/s) before switching to Walk animation")]
        [SerializeField] private float walkThreshold = 0.05f;

        // ── Animator parameter hashes ─────────────────────────────────────────
        private static readonly int ParamState   = Animator.StringToHash("State");
        private static readonly int ParamGesture = Animator.StringToHash("Gesture");

        // ── State values ──────────────────────────────────────────────────────
        private const int STATE_IDLE      = 0;
        private const int STATE_WALK      = 1;
        private const int GESTURE_NONE     = 0;
        private const int GESTURE_ROCK     = 1;
        private const int GESTURE_PAPER    = 2;
        private const int GESTURE_SCISSORS = 3;

        // ── Runtime ───────────────────────────────────────────────────────────
        private Vector3 _lastRootPosition;
        private bool _hasStateParam;
        private bool _hasGestureParam;
        private int _lastGesture = -1;

        // ─────────────────────────────────────────────────────────────────────
        private void Start()
        {
            if (animator == null)
                animator = GetComponent<Animator>();

            // Check which parameters actually exist in the Animator Controller
            // so we don't spam errors every frame if they're missing
            _hasStateParam   = HasAnimatorParam("State");
            _hasGestureParam = HasAnimatorParam("Gesture");

            if (!_hasStateParam)
                Debug.LogWarning("[FlintAnimator] Animator Controller is missing 'State' Int parameter. " +
                                 "Add it in the Animator window.");
            if (!_hasGestureParam)
                Debug.LogWarning("[FlintAnimator] Animator Controller is missing 'Gesture' Int parameter. " +
                                 "Add it in the Animator window (Hand Layer).");

            if (playerRoot != null)
                _lastRootPosition = playerRoot.position;
        }

        private void Update()
        {
            UpdateMovementState();
            UpdateGestureState();
        }

        // ── Movement — uses XR Origin root so head rotation doesn't trigger walk ──

        private void UpdateMovementState()
        {
            if (!_hasStateParam || animator == null || playerRoot == null) return;

            // Only use X and Z — ignore Y so crouching/jumping doesn't trigger walk
            Vector3 currentXZ = new Vector3(playerRoot.position.x, 0f, playerRoot.position.z);
            Vector3 lastXZ    = new Vector3(_lastRootPosition.x,   0f, _lastRootPosition.z);

            float speed = Vector3.Distance(currentXZ, lastXZ) / Time.deltaTime;
            _lastRootPosition = playerRoot.position;

            int state = speed > walkThreshold ? STATE_WALK : STATE_IDLE;
            animator.SetInteger(ParamState, state);
        }

        // ── Gesture — mirrors real-time hand shape onto character ─────────────

        private void UpdateGestureState()
        {
            if (!_hasGestureParam || animator == null) return;

            int gesture = GESTURE_NONE;

            if (handDetector != null)
            {
                switch (handDetector.RightHandShape)
                {
                    case HandShapeDetector.HandShape.Rock:     gesture = GESTURE_ROCK;     break;
                    case HandShapeDetector.HandShape.Paper:    gesture = GESTURE_PAPER;    break;
                    case HandShapeDetector.HandShape.Scissors: gesture = GESTURE_SCISSORS; break;
                    default:                                   gesture = GESTURE_NONE;     break;
                }
            }

            // Only set when changed — avoids unnecessary Animator calls every frame
            if (gesture != _lastGesture)
            {
                animator.SetInteger(ParamGesture, gesture);
                _lastGesture = gesture;
                Debug.Log($"[FlintAnimator] Gesture → {gesture} ({(HandShapeDetector.HandShape)(gesture == 0 ? 0 : gesture)})");
            }
        }

        // ── Public API ────────────────────────────────────────────────────────

        /// <summary>Force a specific gesture (0=None 1=Rock 2=Paper 3=Scissors).
        /// Called by HandGestureInputBridge.</summary>
        public void SetGesture(int gestureId)
        {
            if (!_hasGestureParam || animator == null) return;
            if (gestureId == _lastGesture) return;
            animator.SetInteger(ParamGesture, gestureId);
            _lastGesture = gestureId;
        }

        public void PlayVictory()  { if (_hasStateParam && animator) animator.SetInteger(ParamState, 2); }
        public void PlayDefeated() { if (_hasStateParam && animator) animator.SetInteger(ParamState, 3); }
        public void PlayIdle()
        {
            if (_hasStateParam   && animator) animator.SetInteger(ParamState,   STATE_IDLE);
            if (_hasGestureParam && animator) animator.SetInteger(ParamGesture, GESTURE_NONE);
        }

        // ── Helpers ───────────────────────────────────────────────────────────

        private bool HasAnimatorParam(string paramName)
        {
            if (animator == null) return false;
            foreach (AnimatorControllerParameter p in animator.parameters)
                if (p.name == paramName) return true;
            return false;
        }
    }
}
