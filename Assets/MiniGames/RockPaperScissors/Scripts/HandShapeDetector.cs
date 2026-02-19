using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Hands; // Requires XR Hands package
using TMPro;

namespace RockPaperScissors
{
    /// <summary>
    /// Detects Rock, Paper, Scissors gestures using XR Hands data.
    /// Attaches to an object in the scene (e.g., GameManager).
    /// </summary>
    public class HandShapeDetector : MonoBehaviour
    {
        [Header("UI Feedback")]
        [SerializeField] private TextMeshProUGUI leftHandText;
        [SerializeField] private TextMeshProUGUI rightHandText;
        

        // Current detected shapes
        public enum HandShape { None, Rock, Paper, Scissors }
        public HandShape LeftHandShape { get; private set; }
        public HandShape RightHandShape { get; private set; }

        private XRHandSubsystem handSubsystem;
        private List<XRHandSubsystem> subsystems = new List<XRHandSubsystem>();

        void Start()
        {
            GetHandSubsystem();
        }

        void Update()
        {
            if (handSubsystem == null || !handSubsystem.running)
            {
                GetHandSubsystem();
                return;
            }

            // Update Left Hand
            LeftHandShape = DetectShape(handSubsystem.leftHand);
            UpdateUI(leftHandText, "Left", LeftHandShape);

            // Update Right Hand
            RightHandShape = DetectShape(handSubsystem.rightHand);
            UpdateUI(rightHandText, "Right", RightHandShape);
        }

        void GetHandSubsystem()
        {
            SubsystemManager.GetSubsystems(subsystems);
            if (subsystems.Count > 0)
            {
                handSubsystem = subsystems[0];
            }
        }

        HandShape DetectShape(XRHand hand)
        {
            if (!hand.isTracked) return HandShape.None;

            // Get finger curls (simplified logic)
            // Note: XRHand doesn't have a direct "curl" property, so we estimate based on joint angles or pre-calculated data
            // For simplicity in this robust script, we'll check joint vs root dot products or similar, 
            // BUT XR Hands usually requires more complex math for precise curl.
            // HOWEVER, we can use a simpler heuristic: Tip distance to wrist.
            
            // Let's use a robust approximation: counting extended fingers.
            bool thumbExtended = IsFingerExtended(hand, XRHandJointID.ThumbTip, XRHandJointID.ThumbProximal);
            bool indexExtended = IsFingerExtended(hand, XRHandJointID.IndexTip, XRHandJointID.IndexProximal);
            bool middleExtended = IsFingerExtended(hand, XRHandJointID.MiddleTip, XRHandJointID.MiddleProximal);
            bool ringExtended = IsFingerExtended(hand, XRHandJointID.RingTip, XRHandJointID.RingProximal);
            bool pinkyExtended = IsFingerExtended(hand, XRHandJointID.LittleTip, XRHandJointID.LittleProximal);

            int extendedCount = 0;
            if (indexExtended) extendedCount++;
            if (middleExtended) extendedCount++;
            if (ringExtended) extendedCount++;
            if (pinkyExtended) extendedCount++;

            // Rock: 0 fingers extended (Thumb can be flexible)
            if (extendedCount == 0) return HandShape.Rock;

            // Paper: 4 or 5 fingers extended
            if (extendedCount >= 4) return HandShape.Paper;

            // Scissors: Index & Middle extended, Ring & Pinky curled
            if (indexExtended && middleExtended && !ringExtended && !pinkyExtended) return HandShape.Scissors;

            return HandShape.None;
        }

        bool IsFingerExtended(XRHand hand, XRHandJointID tipId, XRHandJointID baseId)
        {
            if (!hand.GetJoint(tipId).TryGetPose(out Pose tipPose) ||
                !hand.GetJoint(baseId).TryGetPose(out Pose basePose) ||
                !hand.GetJoint(XRHandJointID.Wrist).TryGetPose(out Pose wristPose))
            {
                return false;
            }

            // 1. Distance Check: Tip should be further from wrist than the base joint
            float tipDist = Vector3.Distance(tipPose.position, wristPose.position);
            float baseDist = Vector3.Distance(basePose.position, wristPose.position);
            
            // Use a threshold: extended finger should be noticeably further
            bool distanceCheck = tipDist > baseDist * 1.3f;

            // 2. Direction Check (Optional but good): Tip should point away from palm
            // For now, distance is usually enough for R/P/S
            
            return distanceCheck;
        }

        void UpdateUI(TextMeshProUGUI text, string handName, HandShape shape)
        {
            if (text != null)
            {
                text.text = $"{handName}: {shape}";
                
                // Color coding
                switch (shape)
                {
                    case HandShape.Rock: text.color = Color.red; break;
                    case HandShape.Paper: text.color = Color.green; break;
                    case HandShape.Scissors: text.color = Color.yellow; break;
                    default: text.color = Color.white; break;
                }
            }
        }
    }
}
