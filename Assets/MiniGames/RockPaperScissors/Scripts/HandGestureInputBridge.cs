using UnityEngine;
using TMPro;

namespace RockPaperScissors
{
    /// <summary>
    /// Bridges HandShapeDetector → MultiplayerRPSGameManager + FlintCharacterAnimator.
    ///
    /// How it works:
    ///   1. Reads the local player's hand gesture every frame (local only — no networking needed)
    ///   2. Updates the Flint character animation immediately (rock/paper/scissors pose)
    ///   3. When player HOLDS a gesture for [holdDuration] seconds → submits it as their choice
    ///   4. After submitting, locks input until the round resets
    ///
    /// SETUP:
    ///   - Attach to the GameManager (same object as MultiplayerRPSGameManager)
    ///   - Assign HandShapeDetector, MultiplayerRPSGameManager, FlintCharacterAnimator in Inspector
    /// </summary>
    public class HandGestureInputBridge : MonoBehaviour
    {
        [Header("References")]
        [SerializeField] private HandShapeDetector handDetector;
        [SerializeField] private MultiplayerRPSGameManager gameManager;
        [SerializeField] private FlintCharacterAnimator flintAnimator;

        [Header("Hold to Confirm")]
        [Tooltip("How long player must hold the gesture before it's submitted as their choice")]
        [SerializeField] private float holdDuration = 1.5f;

        [Header("UI Feedback")]
        [Tooltip("Optional — shows 'Hold Rock... 1.2s' progress to player")]
        [SerializeField] private TextMeshProUGUI holdProgressText;

        // ── State ─────────────────────────────────────────────────────────────
        private HandShapeDetector.HandShape _lastShape = HandShapeDetector.HandShape.None;
        private float _holdTimer = 0f;
        private bool _hasSubmitted = false;   // lock after submitting until round resets

        // ── Gesture → Choice mapping ──────────────────────────────────────────
        private static MultiplayerRPSGameManager.Choice ShapeToChoice(HandShapeDetector.HandShape shape)
        {
            switch (shape)
            {
                case HandShapeDetector.HandShape.Rock:     return MultiplayerRPSGameManager.Choice.Rock;
                case HandShapeDetector.HandShape.Paper:    return MultiplayerRPSGameManager.Choice.Paper;
                case HandShapeDetector.HandShape.Scissors: return MultiplayerRPSGameManager.Choice.Scissors;
                default:                                   return MultiplayerRPSGameManager.Choice.None;
            }
        }

        // ── Animator gesture int mapping ──────────────────────────────────────
        private static int ShapeToGestureInt(HandShapeDetector.HandShape shape)
        {
            switch (shape)
            {
                case HandShapeDetector.HandShape.Rock:     return 1;
                case HandShapeDetector.HandShape.Paper:    return 2;
                case HandShapeDetector.HandShape.Scissors: return 3;
                default:                                   return 0;
            }
        }

        // ─────────────────────────────────────────────────────────────────────
        private void Update()
        {
            if (handDetector == null || _hasSubmitted) return;

            HandShapeDetector.HandShape currentShape = handDetector.RightHandShape;

            // Update character animation immediately — mirrors your hand in real time
            if (flintAnimator != null)
                flintAnimator.SetGesture(ShapeToGestureInt(currentShape));

            // No gesture — reset hold timer
            if (currentShape == HandShapeDetector.HandShape.None)
            {
                ResetHold();
                return;
            }

            // Gesture changed — restart hold timer
            if (currentShape != _lastShape)
            {
                _holdTimer = 0f;
                _lastShape = currentShape;
                Debug.Log($"[HandGesture] Gesture changed to: {currentShape} — hold for {holdDuration}s to confirm");
            }

            // Accumulate hold time
            _holdTimer += Time.deltaTime;

            // Show hold progress
            UpdateProgressUI(currentShape, _holdTimer);

            // Held long enough — submit!
            if (_holdTimer >= holdDuration)
            {
                SubmitGesture(currentShape);
            }
        }

        private void SubmitGesture(HandShapeDetector.HandShape shape)
        {
            MultiplayerRPSGameManager.Choice choice = ShapeToChoice(shape);
            if (choice == MultiplayerRPSGameManager.Choice.None) return;

            _hasSubmitted = true;
            ResetHold();

            Debug.Log($"[HandGesture] Submitting choice: {choice}");

            // Call the game manager's public submit method
            if (gameManager != null)
                gameManager.SubmitChoiceFromHand(choice);
        }

        // ── Called by MultiplayerRPSGameManager when a new round starts ───────
        public void OnRoundReset()
        {
            _hasSubmitted = false;
            _holdTimer = 0f;
            _lastShape = HandShapeDetector.HandShape.None;

            if (flintAnimator != null)
                flintAnimator.SetGesture(0);   // back to no hand pose

            UpdateProgressUI(HandShapeDetector.HandShape.None, 0f);
            Debug.Log("[HandGesture] Round reset — hand input unlocked");
        }

        private void ResetHold()
        {
            _holdTimer = 0f;
            _lastShape = HandShapeDetector.HandShape.None;
            UpdateProgressUI(HandShapeDetector.HandShape.None, 0f);
        }

        private void UpdateProgressUI(HandShapeDetector.HandShape shape, float timer)
        {
            if (holdProgressText == null) return;

            if (shape == HandShapeDetector.HandShape.None || _hasSubmitted)
            {
                holdProgressText.text = _hasSubmitted ? "Choice submitted!" : "";
                return;
            }

            float progress = Mathf.Clamp01(timer / holdDuration);
            int bar = Mathf.RoundToInt(progress * 10);
            string filled = new string('|', bar);
            string empty  = new string('-', 10 - bar);

            holdProgressText.text = $"Hold {shape}... [{filled}{empty}] {timer:F1}s";
        }
    }
}
