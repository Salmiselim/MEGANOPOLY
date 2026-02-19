using System.Collections;
using UnityEngine;
using UnityEngine.Events;

/// <summary>
/// ULTRA SIMPLE Dice Controller - Guaranteed to work!
/// No dependencies, just pure basics
/// </summary>
public class SimpleDiceController : MonoBehaviour
{
    [Header("Settings")]
    public int diceNumber = 1;
    public float throwForce = 300f;
    public KeyCode rollKey = KeyCode.Space;
    public bool showDebugLogs = true;
    
    // Internal
    private Rigidbody myRigidbody;
    private bool rolling = false;
    private bool determining = false;
    private int lastResult = 0;
    
    // Event
    public UnityEvent<int> OnDiceRolled = new UnityEvent<int>();
    
    void Start()
    {
        // Find or add Rigidbody
        myRigidbody = gameObject.GetComponent<Rigidbody>();
        
        if (myRigidbody == null)
        {
            Debug.LogError($"[SimpleDice {diceNumber}] ❌ NO RIGIDBODY! Adding one now...");
            myRigidbody = gameObject.AddComponent<Rigidbody>();
        }
        
        // Configure it
        myRigidbody.mass = 10f;
        myRigidbody.linearDamping = 0.5f;
        myRigidbody.angularDamping = 0.5f;
        myRigidbody.useGravity = true;
        myRigidbody.isKinematic = false;
        
        if (showDebugLogs)
        {
            Debug.Log($"[SimpleDice {diceNumber}] ✓ Started!");
            Debug.Log($"[SimpleDice {diceNumber}] Rigidbody OK: {myRigidbody != null}");
        }
    }
    
    void Update()
    {
        // Roll on key press
        if (Input.GetKeyDown(rollKey) && !rolling)
        {
            RollDice();
        }
        
        // Check if stopped
        if (rolling && myRigidbody != null)
        {
            if (myRigidbody.linearVelocity.magnitude < 0.5f && myRigidbody.angularVelocity.magnitude < 0.5f)
            {
                StartCoroutine(DetermineResult());
            }
        }
    }
    
    public void RollDice()
    {
        if (myRigidbody == null)
        {
            Debug.LogError($"[SimpleDice {diceNumber}] Can't roll - no Rigidbody!");
            return;
        }
        
        // Random throw
        Vector3 force = new Vector3(
            Random.Range(-1f, 1f),
            Random.Range(1f, 2f),
            Random.Range(-1f, 1f)
        ).normalized * throwForce;
        
        Vector3 torque = Random.insideUnitSphere * throwForce;
        
        myRigidbody.AddForce(force, ForceMode.Impulse);
        myRigidbody.AddTorque(torque, ForceMode.Impulse);
        
        rolling = true;
        
        if (showDebugLogs)
            Debug.Log($"[SimpleDice {diceNumber}] 🎲 Rolling...");
    }
    
    IEnumerator DetermineResult()
    {
        determining = true;
        rolling = false;
        
        yield return new WaitForSeconds(0.5f);
        
        // Simple detection: which local axis points up most?
        Vector3[] axes = new Vector3[]
        {
            transform.up,
            -transform.up,
            transform.forward,
            -transform.forward,
            transform.right,
            -transform.right
        };
        
        int[] values = new int[] { 1, 6, 2, 5, 3, 4 };
        
        int bestIndex = 0;
        float bestDot = -1f;
        
        for (int i = 0; i < 6; i++)
        {
            float dot = Vector3.Dot(axes[i], Vector3.up);
            if (dot > bestDot)
            {
                bestDot = dot;
                bestIndex = i;
            }
        }
        
        lastResult = values[bestIndex];
        
        if (showDebugLogs)
            Debug.Log($"[SimpleDice {diceNumber}] ✓ Result: {lastResult}");
        
        // Fire event
        OnDiceRolled?.Invoke(lastResult);
        
        determining = false;
    }
    
    public void ResetDice()
    {
        if (myRigidbody != null)
        {
            myRigidbody.linearVelocity = Vector3.zero;
            myRigidbody.angularVelocity = Vector3.zero;
        }
        
        rolling = false;
        lastResult = 0;
        
        if (showDebugLogs)
            Debug.Log($"[SimpleDice {diceNumber}] Reset");
    }
    
    public int GetResult()
    {
        return lastResult;
    }
    
    public bool HasResult()
    {
        return lastResult > 0 && !rolling;
    }
    
    public bool IsRolling()
    {
        return rolling;
    }
}
