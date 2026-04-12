using System.Collections;
using UnityEngine;
using UnityEngine.Events;
using Unity.Netcode;

/// <summary>
/// Networked dice controller.
/// - Server/host is the only one who physically rolls and reads the result.
/// - Result is broadcast to all clients via ClientRpc so everyone sees the same number.
/// - The visual roll (Rigidbody physics) plays on ALL machines for feel,
///   but only the server's reading counts.
/// </summary>
public class SimpleDiceController : NetworkBehaviour
{
    [Header("Settings")]
    public int diceNumber = 1;
    public float throwForce = 300f;
    //public KeyCode rollKey = KeyCode.Space;
    public bool showDebugLogs = true;

    private Rigidbody myRigidbody;
    private bool rolling = false;
    private bool determining = false;
    private int lastResult = 0;

    public UnityEvent<int> OnDiceRolled = new UnityEvent<int>();

    // ── Unity lifecycle ───────────────────────────────────────────────────────

    void Start()
    {
        myRigidbody = GetComponent<Rigidbody>();
        if (myRigidbody == null)
        {
            myRigidbody = gameObject.AddComponent<Rigidbody>();
            Debug.LogWarning($"[SimpleDice {diceNumber}] No Rigidbody found — added one.");
        }

        myRigidbody.mass = 10f;
        myRigidbody.linearDamping = 0.5f;
        myRigidbody.angularDamping = 0.5f;
        myRigidbody.useGravity = true;
        myRigidbody.isKinematic = false;

        if (showDebugLogs)
            Debug.Log($"[SimpleDice {diceNumber}] Ready. IsServer={IsServer}");
    }

    void Update()
    {
        // Only the server/host can trigger a roll via keyboard (for testing)
      //  if (IsServer && Input.GetKeyDown(rollKey) && !rolling)
         //   RollDice();

        // Only the server reads the physics result
        if (IsServer && rolling && !determining && myRigidbody != null)
        {
            bool stopped = myRigidbody.linearVelocity.magnitude < 0.05f
                        && myRigidbody.angularVelocity.magnitude < 0.05f;
            if (stopped)
                StartCoroutine(DetermineResult());
        }
    }

    // ── Public API (call only on server) ─────────────────────────────────────

    /// <summary>Called by CompleteGameManager (server side) to start a roll.</summary>
    public void RollDice()
    {
        if (!IsServer)
        {
            Debug.LogWarning($"[SimpleDice {diceNumber}] RollDice() called on client — ignored.");
            return;
        }

        if (myRigidbody == null) return;

        // Apply physics on server
        Vector3 force = new Vector3(Random.Range(-1f, 1f), Random.Range(1f, 2f), Random.Range(-1f, 1f)).normalized * throwForce;
        Vector3 torque = Random.insideUnitSphere * throwForce;
        myRigidbody.AddForce(force, ForceMode.Impulse);
        myRigidbody.AddTorque(torque, ForceMode.Impulse);

        rolling = true;

        // Tell all clients to play the visual roll too
        PlayRollVisualClientRpc(force, torque);

        if (showDebugLogs)
            Debug.Log($"[SimpleDice {diceNumber}] Rolling...");
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
        determining = false;
    }

    public int GetResult() => lastResult;
    public bool HasResult() => lastResult > 0 && !rolling;
    public bool IsRolling() => rolling;

    // ── Server: read result, then broadcast ──────────────────────────────────

    private IEnumerator DetermineResult()
    {
        determining = true;
        rolling = false;

        yield return new WaitForSeconds(0.3f);

        // If it moved again, wait for next settle
        if (myRigidbody.linearVelocity.magnitude > 0.05f ||
            myRigidbody.angularVelocity.magnitude > 0.05f)
        {
            rolling = true;
            determining = false;
            yield break;
        }

        // Read which face is up
        Vector3[] axes = { transform.up, -transform.up, transform.forward, -transform.forward, transform.right, -transform.right };
        int[] values = { 1, 6, 2, 5, 3, 4 };

        int bestIndex = 0;
        float bestDot = -1f;
        for (int i = 0; i < 6; i++)
        {
            float dot = Vector3.Dot(axes[i], Vector3.up);
            if (dot > bestDot) { bestDot = dot; bestIndex = i; }
        }

        lastResult = values[bestIndex];
        determining = false;

        if (showDebugLogs)
            Debug.Log($"[SimpleDice {diceNumber}] Server result: {lastResult}");

        // Broadcast the result to ALL clients (including host)
        BroadcastResultClientRpc(lastResult);
    }

    // ── ClientRpcs ────────────────────────────────────────────────────────────

    /// <summary>
    /// Plays the visual roll on every client using the same force/torque
    /// the server used — purely cosmetic, result comes from BroadcastResultClientRpc.
    /// </summary>
    [ClientRpc]
    private void PlayRollVisualClientRpc(Vector3 force, Vector3 torque)
    {
        if (IsServer) return; // Server already applied it

        if (myRigidbody == null) return;
        myRigidbody.AddForce(force, ForceMode.Impulse);
        myRigidbody.AddTorque(torque, ForceMode.Impulse);
    }

    /// <summary>
    /// Delivers the authoritative result to all clients and fires OnDiceRolled.
    /// </summary>
    [ClientRpc]
    private void BroadcastResultClientRpc(int result)
    {
        lastResult = result;
        rolling = false;

        if (showDebugLogs)
            Debug.Log($"[SimpleDice {diceNumber}] Result received: {result}");

        OnDiceRolled?.Invoke(result);
    }
}