using UnityEngine;
using UnityEngine.XR;
using UnityEngine.Animations.Rigging;

namespace RockPaperScissors
{
    /// <summary>
    /// Drives an IK-rigged humanoid avatar from the local player's
    /// HMD (head) and XR hand tracking — no multiplayer required.
    ///
    /// HOW TO USE:
    /// 1. Import a Ready Player Me .glb avatar → Rig > Humanoid > Apply.
    /// 2. Add an Animation Rigging "Rig Builder" component to the avatar root.
    /// 3. Under the Rig, add:
    ///      • MultiParentConstraint  → "HeadRig"  (constrained = Head bone)
    ///      • TwoBoneIKConstraint    → "LeftArmRig"  (tip = LeftHand bone)
    ///      • TwoBoneIKConstraint    → "RightArmRig" (tip = RightHand bone)
    /// 4. Create three empty GameObjects as IK targets and assign them in
    ///    the constraint "Source Objects" fields.
    /// 5. Drag those same target transforms into this script's fields below.
    /// 6. Attach this script to any GameObject in the scene (e.g., "AvatarManager").
    /// </summary>
    public class LocalAvatarController : MonoBehaviour
    {
        // ──────────────────────────────────────────────────────────────────
        //  Inspector fields
        // ──────────────────────────────────────────────────────────────────

        [Header("IK Target Transforms (moved each frame to match XR data)")]
        [Tooltip("Empty GameObject that drives the Head constraint target")]
        [SerializeField] private Transform headTarget;

        [Tooltip("Empty GameObject that drives the Left Arm IK target")]
        [SerializeField] private Transform leftHandTarget;

        [Tooltip("Empty GameObject that drives the Right Arm IK target")]
        [SerializeField] private Transform rightHandTarget;

        [Header("Avatar Root")]
        [Tooltip("Root transform of the RPM avatar GameObject")]
        [SerializeField] private Transform avatarRoot;

        [Tooltip("Renderer(s) on the head that should be hidden so it doesn't block the camera")]
        [SerializeField] private Renderer[] headRenderers;

        [Header("Body Estimation")]
        [Tooltip("How far below the HMD the avatar's hip/root sits (negative = downward)")]
        [SerializeField] private float bodyOffsetY = -0.85f;

        [Tooltip("How smoothly the body root follows the head's horizontal position (higher = snappier)")]
        [SerializeField] private float bodyFollowSpeed = 12f;

        // ──────────────────────────────────────────────────────────────────
        //  Private state
        // ──────────────────────────────────────────────────────────────────

        private InputDevice hmd;
        private InputDevice leftController;
        private InputDevice rightController;

        private bool hmdReady;
        private bool leftReady;
        private bool rightReady;

        // ──────────────────────────────────────────────────────────────────
        //  Unity lifecycle
        // ──────────────────────────────────────────────────────────────────

        private void OnEnable()
        {
            InputDevices.deviceConnected += OnDeviceConnected;
            RefreshDevices();
            HideHeadMesh();
        }

        private void OnDisable()
        {
            InputDevices.deviceConnected -= OnDeviceConnected;
        }

        private void OnDeviceConnected(InputDevice device)
        {
            RefreshDevices();
        }

        private void Update()
        {
            // Try to acquire devices if not ready yet
            if (!hmdReady || !leftReady || !rightReady)
                RefreshDevices();

            UpdateHeadTarget();
            UpdateHandTargets();
            UpdateAvatarBodyRoot();
        }

        // ──────────────────────────────────────────────────────────────────
        //  Device management
        // ──────────────────────────────────────────────────────────────────

        private void RefreshDevices()
        {
            hmd             = InputDevices.GetDeviceAtXRNode(XRNode.Head);
            leftController  = InputDevices.GetDeviceAtXRNode(XRNode.LeftHand);
            rightController = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);

            hmdReady   = hmd.isValid;
            leftReady  = leftController.isValid;
            rightReady = rightController.isValid;
        }

        // ──────────────────────────────────────────────────────────────────
        //  IK Target Driving
        // ──────────────────────────────────────────────────────────────────

        private void UpdateHeadTarget()
        {
            if (headTarget == null || !hmdReady) return;

            if (hmd.TryGetFeatureValue(CommonUsages.devicePosition, out Vector3 pos))
                headTarget.position = pos;

            if (hmd.TryGetFeatureValue(CommonUsages.deviceRotation, out Quaternion rot))
                headTarget.rotation = rot;
        }

        private void UpdateHandTargets()
        {
            // Left hand
            if (leftHandTarget != null && leftReady)
            {
                if (leftController.TryGetFeatureValue(CommonUsages.devicePosition, out Vector3 lPos))
                    leftHandTarget.position = lPos;
                if (leftController.TryGetFeatureValue(CommonUsages.deviceRotation, out Quaternion lRot))
                    leftHandTarget.rotation = lRot;
            }

            // Right hand
            if (rightHandTarget != null && rightReady)
            {
                if (rightController.TryGetFeatureValue(CommonUsages.devicePosition, out Vector3 rPos))
                    rightHandTarget.position = rPos;
                if (rightController.TryGetFeatureValue(CommonUsages.deviceRotation, out Quaternion rRot))
                    rightHandTarget.rotation = rRot;
            }
        }

        /// <summary>
        /// Moves the avatar root so the body stays under the player's head.
        /// The horizontal (X/Z) position follows the head, the Y is offset downward.
        /// </summary>
        private void UpdateAvatarBodyRoot()
        {
            if (avatarRoot == null || headTarget == null) return;

            Vector3 targetPos = new Vector3(
                headTarget.position.x,
                headTarget.position.y + bodyOffsetY,
                headTarget.position.z);

            avatarRoot.position = Vector3.Lerp(
                avatarRoot.position,
                targetPos,
                Time.deltaTime * bodyFollowSpeed);

            // Make body face the same direction as the head (yaw only)
            Vector3 headForwardFlat = Vector3.ProjectOnPlane(headTarget.forward, Vector3.up);
            if (headForwardFlat.sqrMagnitude > 0.001f)
            {
                Quaternion targetRot = Quaternion.LookRotation(headForwardFlat, Vector3.up);
                avatarRoot.rotation = Quaternion.Slerp(
                    avatarRoot.rotation,
                    targetRot,
                    Time.deltaTime * bodyFollowSpeed);
            }
        }

        // ──────────────────────────────────────────────────────────────────
        //  Helpers
        // ──────────────────────────────────────────────────────────────────

        /// <summary>
        /// Hides the head mesh so it doesn't clip through the player's camera.
        /// </summary>
        private void HideHeadMesh()
        {
            if (headRenderers == null) return;
            foreach (var r in headRenderers)
            {
                if (r != null) r.enabled = false;
            }
        }
    }
}
