using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.Interactors;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using Unity.Netcode;
using XRMultiplayer;

public class Sheep : NetworkBehaviour
{
    [SerializeField] private XRGrabInteractable grabInteractable;
    [SerializeField] private float holdTimeLimit = 4f; // Auto-drop after this
    [SerializeField] private float wanderSpeed = 2f;
    [SerializeField] private float wanderForce = 5f;
    [SerializeField] private float wanderChangeDist = 3f;

    [Header("Audio")]
    [SerializeField] private AudioSource sfxSource;
    [SerializeField] private AudioClip pickupSfx;
    [SerializeField] private AudioClip randomBaaSfx;

    [Header("Animation")]
    [SerializeField] private Animator animator;
    [SerializeField] private string isWalkingBool = "IsWalking";

    public NetworkVariable<int> ownerIndex = new NetworkVariable<int>(-1, NetworkVariableReadPermission.Everyone, NetworkVariableWritePermission.Server);
    public Rigidbody rb { get; private set; }
    private SheepManager manager;
    private Vector3 wanderTarget;
    private Coroutine autoDropCoroutine;
    
    private NetworkPhysicsInteractable networkInteractable;
    private NetworkVariable<bool> isWandering = new NetworkVariable<bool>(false);

    private enum SheepState { Idle, Wandering }
    private SheepState currentState = SheepState.Idle;
    private float stateTimer = 0f;

    void Awake()
    {
        manager = FindObjectOfType<SheepManager>();
        rb = GetComponent<Rigidbody>();
        rb.useGravity = true; // Enforce gravity so they don't float
        
        // Ensure Y-position is FREE to fall, but prevent sheep from tipping over
        rb.constraints = RigidbodyConstraints.FreezeRotationX | RigidbodyConstraints.FreezeRotationZ;
        
        if (grabInteractable == null) grabInteractable = GetComponent<XRGrabInteractable>();
        networkInteractable = GetComponent<NetworkPhysicsInteractable>();
        
        wanderTarget = transform.position;
        stateTimer = Random.Range(0f, 2f); // Randomize initial state timer
    }

    public override void OnNetworkSpawn()
    {
        base.OnNetworkSpawn();
        if (IsServer)
        {
            StartCoroutine(RandomBaaRoutine());
        }
    }

    void OnEnable()
    {
        grabInteractable.selectEntered.AddListener(OnGrabbed);
        grabInteractable.selectExited.AddListener(OnReleased);
    }

    void OnDisable()
    {
        grabInteractable.selectEntered.RemoveListener(OnGrabbed);
        grabInteractable.selectExited.RemoveListener(OnReleased);
    }

    public void SetOwnerServer(int idx, int colorIdx)
    {
        if (!IsServer) return;
        ownerIndex.Value = idx;
        SetColorRpc(colorIdx);
    }

    [Rpc(SendTo.Everyone)]
    void SetColorRpc(int colorIdx)
    {
        if (colorIdx >= 0 && manager != null && colorIdx < manager.playerSheepMaterials.Length)
        {
            Material playerMat = manager.playerSheepMaterials[colorIdx];
            var renderer = GetComponentInChildren<Renderer>();
            if (renderer != null && playerMat != null)
            {
                renderer.material = playerMat; 
            }
        }
        else
        {
            // Neutral material logic here if needed
        }
    }

    void OnGrabbed(SelectEnterEventArgs args)
    {
        int myClientId = -1;
        if (NetworkManager.Singleton != null) myClientId = (int)NetworkManager.Singleton.LocalClientId;
        int myAssignedIndex = myClientId % 4;

        if (myClientId != -1 && ownerIndex.Value == myAssignedIndex)
        {
            manager.CheckWinServerRpc(myAssignedIndex);
        }

        // Auto-drop timer
        if (autoDropCoroutine != null) StopCoroutine(autoDropCoroutine);
        autoDropCoroutine = StartCoroutine(AutoDrop());

        if (sfxSource != null && pickupSfx != null)
        {
            sfxSource.PlayOneShot(pickupSfx);
        }
    }

    void OnReleased(SelectExitEventArgs args)
    {
        if (autoDropCoroutine != null)
        {
            StopCoroutine(autoDropCoroutine);
            autoDropCoroutine = null;
        }
    }

    IEnumerator AutoDrop()
    {
        yield return new WaitForSeconds(holdTimeLimit);
        if (grabInteractable.isSelected)
        {
            grabInteractable.enabled = false;
            yield return new WaitForSeconds(0.05f);
            grabInteractable.enabled = true;
        }
    }

    void Update()
    {
        if (animator != null)
        {
            // Sync animation from NetworkVariable
            animator.SetBool(isWalkingBool, isWandering.Value);
        }
    }

    bool IsBeingInteracted()
    {
        if (grabInteractable.isSelected) return true;
        if (networkInteractable != null && networkInteractable.isInteracting) return true;
        return false;
    }

    void FixedUpdate()
    {
        if (!IsServer)
        {
            return;
        }

        if (IsBeingInteracted())
        {
            if (isWandering.Value) isWandering.Value = false;
            return;
        }

        stateTimer -= Time.fixedDeltaTime;

        if (currentState == SheepState.Idle)
        {
            if (isWandering.Value) isWandering.Value = false;

            if (stateTimer <= 0f)
            {
                currentState = SheepState.Wandering;
                stateTimer = Random.Range(3f, 7f);
                
                Vector2 randomCircle = Random.insideUnitCircle * 5f;
                wanderTarget = transform.position + new Vector3(randomCircle.x, 0, randomCircle.y);
            }
        }
        else if (currentState == SheepState.Wandering)
        {
            if (!isWandering.Value) isWandering.Value = true;

            Vector3 flatPos = new Vector3(transform.position.x, 0, transform.position.z);
            Vector3 flatTarget = new Vector3(wanderTarget.x, 0, wanderTarget.z);

            if (stateTimer <= 0f || Vector3.Distance(flatPos, flatTarget) < 0.5f)
            {
                currentState = SheepState.Idle;
                stateTimer = Random.Range(2f, 5f);
                isWandering.Value = false;
            }
            else
            {
                Vector3 dir = (flatTarget - flatPos).normalized;
                
                Vector3 targetVelocity = dir * wanderSpeed;
                rb.linearVelocity = new Vector3(targetVelocity.x, rb.linearVelocity.y, targetVelocity.z);

                if (dir != Vector3.zero)
                {
                    Quaternion targetRot = Quaternion.LookRotation(dir);
                    transform.rotation = Quaternion.Slerp(transform.rotation, targetRot, Time.fixedDeltaTime * 10f);
                }
            }
        }

        Vector3 flatVelocity = new Vector3(rb.linearVelocity.x, 0, rb.linearVelocity.z);
        if (flatVelocity.magnitude > wanderSpeed)
        {
            Vector3 limitedVelocity = flatVelocity.normalized * wanderSpeed;
            rb.linearVelocity = new Vector3(limitedVelocity.x, rb.linearVelocity.y, limitedVelocity.z);
        }
    }

    IEnumerator RandomBaaRoutine()
    {
        while (true)
        {
            float waitTime = Random.Range(3f, 7f);
            yield return new WaitForSeconds(waitTime);

            if (gameObject.activeInHierarchy && !IsBeingInteracted())
            {
                BaaClientRpc();
            }
        }
    }

    [Rpc(SendTo.Everyone)]
    void BaaClientRpc()
    {
        if (sfxSource != null && randomBaaSfx != null)
        {
            sfxSource.PlayOneShot(randomBaaSfx);
        }
    }
}