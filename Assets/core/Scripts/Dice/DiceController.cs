using System.Collections;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

/// <summary>
/// FIXED Dice Controller V2 - Properly handles Rigidbody assignment
/// Auto-detects dice faces without manual setup
/// </summary>
[RequireComponent(typeof(Rigidbody))]
public class DiceControllerV2 : MonoBehaviour
{
    [Header("Dice Settings")]
    [SerializeField] private int diceNumber = 1;
    // Public accessor for other systems to read the dice number without exposing the field
    public int DiceNumber => diceNumber;
    [SerializeField] private float throwForceMultiplier = 300f;
    [SerializeField] private float torqueMultiplier = 100f;
    [SerializeField] private float settleTime = 1f;
    [SerializeField] private float velocityThreshold = 0.05f;

    [Header("Face Detection Method")]
    [Tooltip("Auto: Use raycast (recommended). Manual: Use face center transforms")]
    [SerializeField] private FaceDetectionMode detectionMode = FaceDetectionMode.Auto;

    [Header("Manual Face Centers (Optional)")]
    [SerializeField] private Transform[] faceCenters = new Transform[6];
    [SerializeField] private int[] faceValues = new int[6] { 1, 6, 2, 5, 3, 4 };

    [Header("Physics Settings")]
    [SerializeField] private float mass = 10f;
    [SerializeField] private float drag = 0.5f;
    [SerializeField] private float angularDrag = 0.5f;

    [Header("Testing")]
    [SerializeField] private bool enableDebugLogs = true;
    [SerializeField] private KeyCode testRollKey = KeyCode.Space;

    // Components
    private Rigidbody rb;
    private XRGrabInteractable grabInteractable;
    private AudioSource audioSource;

    // State
    private bool isRolling = false;
    private bool hasResult = false;
    private int resultValue = 0;
    private Vector3 initialPosition;
    private Quaternion initialRotation;
    private float timeSinceReleased = 0f;

    // Events
    public UnityEvent<int> OnDiceRolled = new UnityEvent<int>();

    public enum FaceDetectionMode
    {
        Auto,       // Use transform orientation
        Manual      // Use face center transforms
    }

    private void Awake()
    {
        // CRITICAL: Get Rigidbody first!
        rb = GetComponent<Rigidbody>();

        if (rb == null)
        {
            Debug.LogError($"[Dice {diceNumber}] ❌ CRITICAL: No Rigidbody found! Adding one now...");
            rb = gameObject.AddComponent<Rigidbody>();
        }

        SetupComponents();
        ConfigurePhysics();

        initialPosition = transform.position;
        initialRotation = transform.rotation;

        if (enableDebugLogs)
            Debug.Log($"[Dice {diceNumber}] ✓ Awake complete - Rigidbody assigned: {rb != null}");
    }

    private void SetupComponents()
    {
        // Audio
        audioSource = GetComponent<AudioSource>();
        if (audioSource == null)
            audioSource = gameObject.AddComponent<AudioSource>();

        // XR (optional)
        grabInteractable = GetComponent<XRGrabInteractable>();
        if (grabInteractable != null)
        {
            grabInteractable.selectExited.AddListener(OnReleased);
            if (enableDebugLogs)
                Debug.Log($"[Dice {diceNumber}] ✓ XR Grab Interactable found");
        }
    }

    private void ConfigurePhysics()
    {
        if (rb == null)
        {
            Debug.LogError($"[Dice {diceNumber}] ❌ Cannot configure physics - Rigidbody is null!");
            return;
        }

        rb.mass = mass;
        rb.linearDamping = drag;
        rb.angularDamping = angularDrag;
        rb.interpolation = RigidbodyInterpolation.Interpolate;
        rb.collisionDetectionMode = CollisionDetectionMode.Continuous;
        rb.useGravity = true;

        // IMPORTANT: Make sure Is Kinematic is OFF
        rb.isKinematic = false;

        if (enableDebugLogs)
            Debug.Log($"[Dice {diceNumber}] ✓ Physics configured: Mass={mass}, IsKinematic={rb.isKinematic}");
    }

    private void Start()
    {
        if (rb == null)
        {
            Debug.LogError($"[Dice {diceNumber}] ❌ CRITICAL ERROR: Rigidbody still null in Start!");
            rb = GetComponent<Rigidbody>();
        }

        ResetDice();

        if (detectionMode == FaceDetectionMode.Manual)
        {
            ValidateFaceCenters();
        }

        if (enableDebugLogs)
            Debug.Log($"[Dice {diceNumber}] ✓ Ready! Detection mode: {detectionMode}");
    }

    private void ValidateFaceCenters()
    {
        if (faceCenters == null || faceCenters.Length < 6)
        {
            Debug.LogWarning($"[Dice {diceNumber}] ⚠️ Face centers array not properly set up!");
            return;
        }

        int missingCount = 0;
        for (int i = 0; i < 6; i++)
        {
            if (faceCenters[i] == null)
            {
                missingCount++;
            }
        }

        if (missingCount > 0)
        {
            Debug.LogWarning($"[Dice {diceNumber}] ⚠️ {missingCount} face centers not assigned!");
        }
    }

    private void Update()
    {
        // Test roll with keyboard
        if (Input.GetKeyDown(testRollKey) && !isRolling)
        {
            SimulateThrow();
        }

        // Check if dice has settled
        if (isRolling && !hasResult && rb != null)
        {
            timeSinceReleased += Time.deltaTime;

            if (timeSinceReleased > settleTime)
            {
                // Use linearVelocity (newer Unity) or velocity (older Unity)
                Vector3 currentVelocity = rb.linearVelocity;
                Vector3 currentAngularVelocity = rb.angularVelocity;

                if (currentVelocity.magnitude < velocityThreshold && currentAngularVelocity.magnitude < velocityThreshold)
                {
                    StartCoroutine(CheckDiceResult());
                }
            }
        }
    }

    public void SimulateThrow()
    {
        if (rb == null)
        {
            Debug.LogError($"[Dice {diceNumber}] ❌ Cannot throw - Rigidbody is null!");
            return;
        }

        if (isRolling)
        {
            if (enableDebugLogs)
                Debug.Log($"[Dice {diceNumber}] Already rolling, ignoring throw");
            return;
        }

        Vector3 randomForce = new Vector3(
            Random.Range(-1f, 1f),
            Random.Range(0.5f, 1f),
            Random.Range(-1f, 1f)
        ).normalized * throwForceMultiplier;

        Vector3 randomTorque = Random.insideUnitSphere * torqueMultiplier;

        rb.AddForce(randomForce, ForceMode.Impulse);
        rb.AddTorque(randomTorque, ForceMode.Impulse);

        isRolling = true;
        hasResult = false;
        timeSinceReleased = 0f;

        if (enableDebugLogs)
            Debug.Log($"[Dice {diceNumber}] 🎲 Thrown! Force: {randomForce.magnitude:F1}");
    }

    private void OnReleased(SelectExitEventArgs args)
    {
        if (rb == null) return;

        // Don't multiply existing velocity — just add a small random spin for variety
        rb.AddTorque(Random.insideUnitSphere * torqueMultiplier, ForceMode.Impulse);

        isRolling = true;
        hasResult = false;
        timeSinceReleased = 0f;

        if (enableDebugLogs)
            Debug.Log($"[Dice {diceNumber}] Released from XR controller");
    }

    private IEnumerator CheckDiceResult()
    {
        yield return new WaitForSeconds(0.3f);

        if (hasResult) yield break;

        // Confirm still stopped — bounce may have restarted movement
        if (rb.linearVelocity.magnitude  > velocityThreshold ||
            rb.angularVelocity.magnitude > velocityThreshold)
        {
            // Not settled yet — keep waiting
            yield break;
        }

        // Determine top face
        if (detectionMode == FaceDetectionMode.Auto)
        {
            resultValue = GetTopFaceAuto();
        }
        else
        {
            resultValue = GetTopFaceManual();
        }

        hasResult = true;
        isRolling = false;

        // Trigger event
        OnDiceRolled?.Invoke(resultValue);

        if (enableDebugLogs)
        {
            Debug.Log($"[Dice {diceNumber}] ✓ RESULT: {resultValue}");
        }
    }

    /// <summary>
    /// AUTO DETECTION: Use transform orientation to detect top face
    /// </summary>
    private int GetTopFaceAuto()
    {
        // Get all 6 local axis directions in world space
        Vector3[] faceNormals = new Vector3[6]
        {
            transform.up,       // Top face (local +Y)
            -transform.up,      // Bottom face (local -Y)
            transform.forward,  // Front face (local +Z)
            -transform.forward, // Back face (local -Z)
            transform.right,    // Right face (local +X)
            -transform.right    // Left face (local -X)
        };

        // Standard dice: opposite faces sum to 7
        int[] faceValuesAuto = new int[6] { 1, 6, 2, 5, 3, 4 };

        // Find which face is most aligned with world up
        int topFaceIndex = 0;
        float maxDot = -1f;

        for (int i = 0; i < 6; i++)
        {
            float dot = Vector3.Dot(faceNormals[i], Vector3.up);

            if (enableDebugLogs)
                Debug.Log($"[Dice {diceNumber}] Face {i} (Value {faceValuesAuto[i]}): dot = {dot:F3}");

            if (dot > maxDot)
            {
                maxDot = dot;
                topFaceIndex = i;
            }
        }

        if (enableDebugLogs)
        {
            Debug.Log($"[Dice {diceNumber}] → Top face: Index {topFaceIndex}, Value {faceValuesAuto[topFaceIndex]}, Alignment {maxDot:F3}");
        }

        return faceValuesAuto[topFaceIndex];
    }

    /// <summary>
    /// MANUAL DETECTION: Use face center transforms
    /// </summary>
    private int GetTopFaceManual()
    {
        if (faceCenters == null || faceCenters.Length < 6)
        {
            Debug.LogError($"[Dice {diceNumber}] Face centers not set! Using random value.");
            return Random.Range(1, 7);
        }

        int topFaceIndex = 0;
        float highestY = float.MinValue;

        for (int i = 0; i < faceCenters.Length; i++)
        {
            if (faceCenters[i] == null) continue;

            float y = faceCenters[i].position.y;

            if (y > highestY)
            {
                highestY = y;
                topFaceIndex = i;
            }
        }

        if (enableDebugLogs)
        {
            Debug.Log($"[Dice {diceNumber}] Manual: Top face {topFaceIndex}, Value {faceValues[topFaceIndex]}");
        }

        return faceValues[topFaceIndex];
    }

    public void ResetDice()
    {
        if (rb == null)
        {
            Debug.LogError($"[Dice {diceNumber}] ❌ Cannot reset - Rigidbody is null!");
            rb = GetComponent<Rigidbody>();
            if (rb == null) return;
        }

        transform.position = initialPosition;
        transform.rotation = initialRotation;

        rb.linearVelocity = Vector3.zero;
        rb.angularVelocity = Vector3.zero;

        isRolling = false;
        hasResult = false;
        resultValue = 0;
        timeSinceReleased = 0f;

        if (enableDebugLogs)
            Debug.Log($"[Dice {diceNumber}] ↻ Reset");
    }

    public int GetResult()
    {
        return resultValue;
    }

    public bool HasResult()
    {
        return hasResult;
    }

    public bool IsRolling()
    {
        return isRolling;
    }

    private void OnDestroy()
    {
        if (grabInteractable != null)
        {
            grabInteractable.selectExited.RemoveListener(OnReleased);
        }
    }

    // Visual debugging
    private void OnDrawGizmos()
    {
        if (!enableDebugLogs) return;

        // Draw dice orientation axes
        Gizmos.color = Color.green;
        Gizmos.DrawLine(transform.position, transform.position + transform.up * 30);

        Gizmos.color = Color.blue;
        Gizmos.DrawLine(transform.position, transform.position + transform.forward * 20);

        Gizmos.color = Color.red;
        Gizmos.DrawLine(transform.position, transform.position + transform.right * 20);
    }
}