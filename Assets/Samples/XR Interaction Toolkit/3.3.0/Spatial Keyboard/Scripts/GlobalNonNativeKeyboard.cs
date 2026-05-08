#if TEXT_MESH_PRO_PRESENT || (UGUI_2_0_PRESENT && UNITY_6000_0_OR_NEWER)
using TMPro;
using UnityEngine.XR.Interaction.Toolkit.Utilities;

namespace UnityEngine.XR.Interaction.Toolkit.Samples.SpatialKeyboard
{
    /// <summary>
    /// Manages spawning and positioning of the global keyboard.
    /// </summary>
    public class GlobalNonNativeKeyboard : MonoBehaviour
    {
        public static GlobalNonNativeKeyboard instance { get; private set; }

        [SerializeField, Tooltip("The prefab with the XR Keyboard component to automatically instantiate.")]
        GameObject m_KeyboardPrefab;

        /// <summary>
        /// The prefab with the XR Keyboard component to automatically instantiate.
        /// </summary>
        public GameObject keyboardPrefab
        {
            get => m_KeyboardPrefab;
            set => m_KeyboardPrefab = value;
        }

        [SerializeField, Tooltip("The parent Transform to instantiate the Keyboard Prefab under.")]
        Transform m_PlayerRoot;

        /// <summary>
        /// The parent Transform to instantiate the Keyboard Prefab under.
        /// </summary>
        public Transform playerRoot
        {
            get => m_PlayerRoot;
            set => m_PlayerRoot = value;
        }

        [HideInInspector]
        [SerializeField]
        XRKeyboard m_Keyboard;

        /// <summary>
        /// Global keyboard instance.
        /// </summary>
        public XRKeyboard keyboard
        {
            get => m_Keyboard;
            set => m_Keyboard = value;
        }

        [SerializeField, Tooltip("Position offset from the camera to place the keyboard.")]
        Vector3 m_KeyboardOffset;

        /// <summary>
        /// Position offset from the camera to place the keyboard.
        /// </summary>
        public Vector3 keyboardOffset
        {
            get => m_KeyboardOffset;
            set => m_KeyboardOffset = value;
        }

        [SerializeField, Tooltip("Transform of the camera. If left empty, this will default to Camera.main.")]
        Transform m_CameraTransform;

        /// <summary>
        /// Transform of the camera. If left empty, this will default to Camera.main.
        /// </summary>
        public Transform cameraTransform
        {
            get => m_CameraTransform;
            set => m_CameraTransform = value;
        }

        [SerializeField, Tooltip("If true, the keyboard will be repositioned to the starting position if it is out of view when Show Keyboard is called.")]
        bool m_RepositionOutOfViewKeyboardOnOpen = true;

        /// <summary>
        /// If true, the keyboard will be repositioned to the starting position if it is out of view when Show Keyboard is called.
        /// </summary>
        public bool repositionOutOfViewKeyboardOnOpen
        {
            get => m_RepositionOutOfViewKeyboardOnOpen;
            set => m_RepositionOutOfViewKeyboardOnOpen = value;
        }

        [SerializeField, Tooltip("Threshold for the dot product when determining if the keyboard is out of view and should be repositioned. The lower the threshold, the wider the field of view."), Range(0f, 1f)]
        float m_FacingKeyboardThreshold = 0.15f;

        /// <summary>
        /// Threshold for the dot product when determining if the keyboard is out of view and should be repositioned. The lower the threshold, the wider the field of view.
        /// </summary>
        public float facingKeyboardThreshold
        {
            get => m_FacingKeyboardThreshold;
            set => m_FacingKeyboardThreshold = value;
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        void Awake()
        {
            if (instance != null && instance != this)
            {
                Destroy(this);
                return;
            }

            instance = this;

            if (m_CameraTransform == null)
            {
                var mainCamera = Camera.main;
                if (mainCamera != null)
                    m_CameraTransform = mainCamera.transform;
                else
                    Debug.LogWarning("Could not find main camera to assign the missing Camera Transform property.", this);
            }

            // Fallback: if no player root was assigned in the Inspector, derive one from
            // the camera hierarchy (XR Origin → Camera Offset → Main Camera).
            // This keeps the keyboard parented inside the XR rig so it moves with the player.
            if (m_PlayerRoot == null && m_CameraTransform != null)
            {
                // Camera Offset is the typical parent of the XR camera; XR Origin is its parent.
                // Either makes a good anchor — prefer Camera Offset (one level up from camera).
                m_PlayerRoot = m_CameraTransform.parent != null
                    ? m_CameraTransform.parent   // Camera Offset
                    : m_CameraTransform;          // camera itself as last resort
                Debug.Log($"[GlobalNonNativeKeyboard] m_PlayerRoot not assigned — using '{m_PlayerRoot.name}' derived from camera hierarchy.", this);
            }

            if (m_KeyboardPrefab != null)
            {
                var keyboardObj = Instantiate(m_KeyboardPrefab, m_PlayerRoot);
                keyboard = keyboardObj.GetComponent<XRKeyboard>();
                
                // 1. Force the XR Keyboard Canvas to WorldSpace and attach the Camera.
                var keyboardCanvas = keyboardObj.GetComponent<Canvas>();
                if (keyboardCanvas == null) keyboardCanvas = keyboardObj.GetComponentInChildren<Canvas>();

                if (keyboardCanvas != null)
                {
                    keyboardCanvas.renderMode = RenderMode.WorldSpace;
                    keyboardCanvas.worldCamera = m_CameraTransform != null ? m_CameraTransform.GetComponent<Camera>() : Camera.main;
                }
                
                // 2. Restore the original scale of the prefab instead of hardcoding 0.001. 
                // If the prefab natively uses Vector3.one but acts as a Canvas, we give it a safe 0.002 fallback.
                Vector3 originalScale = m_KeyboardPrefab.transform.localScale;
                if (originalScale == Vector3.one && keyboardObj.GetComponent<Canvas>() != null)
                {
                     keyboardObj.transform.localScale = new Vector3(0.002f, 0.002f, 0.002f);
                }
                else
                {
                     keyboardObj.transform.localScale = originalScale;
                }
                
                // 3. Disable the root Image component if it exists so it doesn't block vision.
                var rootImage = keyboardObj.GetComponent<UnityEngine.UI.Image>();
                if (rootImage != null)
                {
                    rootImage.enabled = false;
                }

                keyboardObj.SetActive(false);
            }
        }


        /// <summary>
        /// Opens the global keyboard with a <see cref="TMP_InputField"/> to monitor.
        /// </summary>
        /// <remarks>This will update the keyboard with <see cref="TMP_InputField.text"/> as the existing string for the keyboard.</remarks>
        /// <param name="inputField">The input field for the global keyboard to monitor</param>
        /// <param name="observeCharacterLimit">If true, the global keyboard will respect the character limit of the
        /// <see cref="inputField"/>. This is false by default.</param>
        public virtual void ShowKeyboard(TMP_InputField inputField, bool observeCharacterLimit = false)
        {
            if (keyboard == null)
                return;

            // Check if keyboard is already open or should be repositioned
            var shouldPositionKeyboard = !keyboard.isOpen || (m_RepositionOutOfViewKeyboardOnOpen && IsKeyboardOutOfView());

            // Open keyboard
            keyboard.Open(inputField, observeCharacterLimit);

            // Position keyboard in front of user if the keyboard is closed
            if (shouldPositionKeyboard)
                PositionKeyboard(m_CameraTransform);
        }

        /// <summary>
        /// Opens the global keyboard with the option to populate it with existing text.
        /// </summary>
        /// <remarks>This will update the keyboard with <see cref="text"/> as the existing string for the keyboard.</remarks>
        /// <param name="text">The existing text string to populate the keyboard with on open.</param>
        public virtual void ShowKeyboard(string text)
        {
            if (keyboard == null)
                return;

            // Check if keyboard is already open or should be repositioned
            var shouldPositionKeyboard = !keyboard.isOpen || (m_RepositionOutOfViewKeyboardOnOpen && IsKeyboardOutOfView());

            // Open keyboard
            keyboard.Open(text);

            // Position keyboard in front of user if the keyboard is closed
            if (shouldPositionKeyboard)
                PositionKeyboard(m_CameraTransform);
        }

        /// <summary>
        /// Opens the global keyboard with the option to clear any existing keyboard text.
        /// </summary>
        /// <param name="clearKeyboardText">If true, the keyboard will open with no string populated in the keyboard. If false,
        /// the existing text will be maintained. This is false by default.</param>
        public void ShowKeyboard(bool clearKeyboardText = false)
        {
            if (keyboard == null)
                return;

            ShowKeyboard(clearKeyboardText ? string.Empty : keyboard.text);
        }

        /// <summary>
        /// Closes the global keyboard.
        /// </summary>
        public virtual void HideKeyboard()
        {
            if (keyboard == null)
                return;

            keyboard.Close();
        }

        /// <summary>
        /// Reposition <see cref="keyboard"/> to starting position if it is out of view. Keyboard will only reposition if is active and enabled.
        /// </summary>
        /// <remarks>
        /// Field if view is defined by the <see cref="facingKeyboardThreshold"/>, and the starting position
        /// is defined by the <see cref="keyboardOffset"/> in relation to the camera.
        /// </remarks>
        public void RepositionKeyboardIfOutOfView()
        {
            if (IsKeyboardOutOfView())
            {
                if (keyboard.isOpen)
                    PositionKeyboard(m_CameraTransform);
            }
        }

        void PositionKeyboard(Transform target)
        {
            // UPDATE CAMERA REFERENCE: Camera.main can change in a networked game
            if (target == null && Camera.main != null) 
                target = Camera.main.transform;
                
            if (target == null) return;

            // Force a comfortable VR reading/typing distance if the offset is zero or too far
            Vector3 offset = m_KeyboardOffset;
            if (offset == Vector3.zero || offset.z > 1.5f) 
            {
                offset = new Vector3(0f, -0.3f, 0.6f); // 0.6m in front, 0.3m down
            }
            
            var position = target.position +
                target.right * offset.x +
                target.forward * offset.z +
                target.up * offset.y; 
                
            keyboard.transform.position = position;
            FaceKeyboardAtTarget(target);
        }

        void FaceKeyboardAtTarget(Transform target)
        {
            if (target == null) return;
            
            var forward = (keyboard.transform.position - target.position).normalized;
            BurstMathUtility.OrthogonalLookRotation(forward, Vector3.up, out var newTarget);
            
            // INVERT the forward vector so the keyboard faces the camera instead of facing away from it
            keyboard.transform.rotation = newTarget * Quaternion.Euler(0, 180, 0);
        }

        bool IsKeyboardOutOfView()
        {
            // UPDATE CAMERA REFERENCE (network fallback)
            if (m_CameraTransform == null && Camera.main != null)
                m_CameraTransform = Camera.main.transform;
                
            if (m_CameraTransform == null || keyboard == null)
            {
                Debug.LogWarning("Camera or keyboard reference is null. Unable to determine if keyboard is out of view.", this);
                return false;
            }

            var dotProduct = Vector3.Dot(m_CameraTransform.forward, (keyboard.transform.position - m_CameraTransform.position).normalized);
            return dotProduct < m_FacingKeyboardThreshold;
        }
    }
}
#endif
