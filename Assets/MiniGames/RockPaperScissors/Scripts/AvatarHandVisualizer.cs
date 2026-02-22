using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Hands;

namespace RockPaperScissors
{
    /// <summary>
    /// Maps XR Hand joint rotations onto an avatar's finger bones in real time.
    ///
    /// HOW TO USE:
    /// 1. Attach this to your avatar GameObject (or any GO in the scene).
    /// 2. Assign the avatar's Animator (it needs a Humanoid rig).
    /// 3. The script auto-maps XR joint rotations to HumanBodyBone transforms.
    ///
    /// This works alongside LocalAvatarController (which handles head/body IK).
    /// Both scripts read from the same XRHandSubsystem so there is no conflict.
    ///
    /// NOTE: This only drives finger joints. Head/body is done by LocalAvatarController + Animation Rigging.
    /// </summary>
    public class AvatarHandVisualizer : MonoBehaviour
    {
        [Header("Avatar Animator (must be Humanoid rig)")]
        [SerializeField] private Animator avatarAnimator;

        [Header("Mirroring")]
        [Tooltip("When true, the joint rotations are mirrored for natural look")]
        [SerializeField] private bool mirrorFingers = true;

        [Header("Blend Speed")]
        [Tooltip("How quickly fingers follow hand tracking data (lerp speed)")]
        [SerializeField] private float fingerBlendSpeed = 20f;

        // ──────────────────────────────────────────────────────────────────
        //  XR Hands subsystem
        // ──────────────────────────────────────────────────────────────────

        private XRHandSubsystem handSubsystem;
        private List<XRHandSubsystem> subsystems = new List<XRHandSubsystem>();

        // ──────────────────────────────────────────────────────────────────
        //  Joint → HumanBodyBone mappings
        // ──────────────────────────────────────────────────────────────────

        // Left hand mapping: XRHandJointID → HumanBodyBones
        private static readonly (XRHandJointID joint, HumanBodyBones bone)[] k_LeftMapping = new[]
        {
            // Thumb
            (XRHandJointID.ThumbProximal,   HumanBodyBones.LeftThumbProximal),
            (XRHandJointID.ThumbDistal,     HumanBodyBones.LeftThumbIntermediate),
            (XRHandJointID.ThumbTip,        HumanBodyBones.LeftThumbDistal),
            // Index
            (XRHandJointID.IndexProximal,   HumanBodyBones.LeftIndexProximal),
            (XRHandJointID.IndexIntermediate, HumanBodyBones.LeftIndexIntermediate),
            (XRHandJointID.IndexDistal,     HumanBodyBones.LeftIndexDistal),
            // Middle
            (XRHandJointID.MiddleProximal,  HumanBodyBones.LeftMiddleProximal),
            (XRHandJointID.MiddleIntermediate, HumanBodyBones.LeftMiddleIntermediate),
            (XRHandJointID.MiddleDistal,    HumanBodyBones.LeftMiddleDistal),
            // Ring
            (XRHandJointID.RingProximal,    HumanBodyBones.LeftRingProximal),
            (XRHandJointID.RingIntermediate, HumanBodyBones.LeftRingIntermediate),
            (XRHandJointID.RingDistal,      HumanBodyBones.LeftRingDistal),
            // Little
            (XRHandJointID.LittleProximal,  HumanBodyBones.LeftLittleProximal),
            (XRHandJointID.LittleIntermediate, HumanBodyBones.LeftLittleIntermediate),
            (XRHandJointID.LittleDistal,    HumanBodyBones.LeftLittleDistal),
        };

        // Right hand mapping
        private static readonly (XRHandJointID joint, HumanBodyBones bone)[] k_RightMapping = new[]
        {
            (XRHandJointID.ThumbProximal,   HumanBodyBones.RightThumbProximal),
            (XRHandJointID.ThumbDistal,     HumanBodyBones.RightThumbIntermediate),
            (XRHandJointID.ThumbTip,        HumanBodyBones.RightThumbDistal),
            (XRHandJointID.IndexProximal,   HumanBodyBones.RightIndexProximal),
            (XRHandJointID.IndexIntermediate, HumanBodyBones.RightIndexIntermediate),
            (XRHandJointID.IndexDistal,     HumanBodyBones.RightIndexDistal),
            (XRHandJointID.MiddleProximal,  HumanBodyBones.RightMiddleProximal),
            (XRHandJointID.MiddleIntermediate, HumanBodyBones.RightMiddleIntermediate),
            (XRHandJointID.MiddleDistal,    HumanBodyBones.RightMiddleDistal),
            (XRHandJointID.RingProximal,    HumanBodyBones.RightRingProximal),
            (XRHandJointID.RingIntermediate, HumanBodyBones.RightRingIntermediate),
            (XRHandJointID.RingDistal,      HumanBodyBones.RightRingDistal),
            (XRHandJointID.LittleProximal,  HumanBodyBones.RightLittleProximal),
            (XRHandJointID.LittleIntermediate, HumanBodyBones.RightLittleIntermediate),
            (XRHandJointID.LittleDistal,    HumanBodyBones.RightLittleDistal),
        };

        // Runtime bone transform cache
        private Transform[] leftBoneTransforms;
        private Transform[] rightBoneTransforms;

        // ──────────────────────────────────────────────────────────────────
        //  Unity lifecycle
        // ──────────────────────────────────────────────────────────────────

        private void Start()
        {
            // Cache bone transforms from the Animator
            if (avatarAnimator != null)
            {
                leftBoneTransforms  = new Transform[k_LeftMapping.Length];
                rightBoneTransforms = new Transform[k_RightMapping.Length];

                for (int i = 0; i < k_LeftMapping.Length; i++)
                    leftBoneTransforms[i] = avatarAnimator.GetBoneTransform(k_LeftMapping[i].bone);

                for (int i = 0; i < k_RightMapping.Length; i++)
                    rightBoneTransforms[i] = avatarAnimator.GetBoneTransform(k_RightMapping[i].bone);
            }
            else
            {
                Debug.LogWarning("[AvatarHandVisualizer] No Animator assigned — finger tracking will not work.");
            }

            AcquireHandSubsystem();
        }

        private void Update()
        {
            if (handSubsystem == null || !handSubsystem.running)
            {
                AcquireHandSubsystem();
                return;
            }

            if (avatarAnimator == null) return;

            ApplyHandJoints(handSubsystem.leftHand,  k_LeftMapping,  leftBoneTransforms,  false);
            ApplyHandJoints(handSubsystem.rightHand, k_RightMapping, rightBoneTransforms, mirrorFingers);
        }

        // ──────────────────────────────────────────────────────────────────
        //  XR Hands acquisition
        // ──────────────────────────────────────────────────────────────────

        private void AcquireHandSubsystem()
        {
            SubsystemManager.GetSubsystems(subsystems);
            if (subsystems.Count > 0)
                handSubsystem = subsystems[0];
        }

        // ──────────────────────────────────────────────────────────────────
        //  Joint application
        // ──────────────────────────────────────────────────────────────────

        private void ApplyHandJoints(
            XRHand hand,
            (XRHandJointID joint, HumanBodyBones bone)[] mapping,
            Transform[] boneCache,
            bool mirror)
        {
            if (!hand.isTracked || boneCache == null) return;

            for (int i = 0; i < mapping.Length; i++)
            {
                Transform bone = boneCache[i];
                if (bone == null) continue;

                XRHandJoint xrJoint = hand.GetJoint(mapping[i].joint);
                if (!xrJoint.TryGetPose(out Pose pose)) continue;

                Quaternion targetRot = pose.rotation;

                // Mirror X-axis rotation for natural look on symmetrical avatar
                if (mirror)
                {
                    Vector3 euler = targetRot.eulerAngles;
                    euler.y = -euler.y;
                    euler.z = -euler.z;
                    targetRot = Quaternion.Euler(euler);
                }

                bone.rotation = Quaternion.Slerp(
                    bone.rotation,
                    targetRot,
                    Time.deltaTime * fingerBlendSpeed);
            }
        }
    }
}
