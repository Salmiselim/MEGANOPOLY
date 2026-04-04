using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.Interactors;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Sheep : MonoBehaviour
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

    public int ownerIndex = -1;
    public Rigidbody rb { get; private set; }
    private SheepManager manager;
    private Vector3 wanderTarget;
    private Coroutine autoDropCoroutine;
    
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
        wanderTarget = transform.position;

        stateTimer = Random.Range(0f, 2f); // Randomize initial state timer
        StartCoroutine(RandomBaaRoutine());
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

    public void SetOwner(int idx, Material playerMat)
    {
        ownerIndex = idx;
        var renderer = GetComponentInChildren<Renderer>();
        if (idx >= 0 && playerMat != null && renderer != null)
        {
            renderer.material = playerMat; // Mark with color
            // Optional: Add glow - e.g. sheep.transform.Find("Glow").gameObject.SetActive(true);
        }
        else
        {
            // Neutral material (set in prefab)
        }
    }

    void OnGrabbed(SelectEnterEventArgs args)
    {
        // Get grabber playerIndex
        var interactor = args.interactorObject as XRBaseInteractor;
        var playerId = interactor?.transform.GetComponentInParent<PlayerIdentifier>()?.playerIndex;
        if (playerId.HasValue && playerId.Value == ownerIndex)
        {
            manager.CheckWin(playerId.Value);
        }

        // Auto-drop timer
        if (autoDropCoroutine != null) StopCoroutine(autoDropCoroutine);
        autoDropCoroutine = StartCoroutine(AutoDrop());

        if (sfxSource != null && pickupSfx != null)
        {
            sfxSource.PlayOneShot(pickupSfx);
        }

        if (animator != null) animator.SetBool(isWalkingBool, false);
        // Pause wander (kinematic handled by XR)
    }

    void OnReleased(SelectExitEventArgs args)
    {
        if (autoDropCoroutine != null)
        {
            StopCoroutine(autoDropCoroutine);
            autoDropCoroutine = null;
        }
        // Wander resumes in FixedUpdate
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

    void FixedUpdate()
    {
        if (grabInteractable.isSelected)
        {
            return;
        }

        stateTimer -= Time.fixedDeltaTime;

        if (currentState == SheepState.Idle)
        {
            if (animator != null) animator.SetBool(isWalkingBool, false);

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
            if (animator != null) animator.SetBool(isWalkingBool, true);

            Vector3 flatPos = new Vector3(transform.position.x, 0, transform.position.z);
            Vector3 flatTarget = new Vector3(wanderTarget.x, 0, wanderTarget.z);

            if (stateTimer <= 0f || Vector3.Distance(flatPos, flatTarget) < 0.5f)
            {
                currentState = SheepState.Idle;
                stateTimer = Random.Range(2f, 5f);
            }
            else
            {
                Vector3 dir = (flatTarget - flatPos).normalized;
                
                // Instead of adding a tiny force against friction, set the velocity directly 
                // for consistent movement speed across different floor physics materials.
                Vector3 targetVelocity = dir * wanderSpeed;
                rb.linearVelocity = new Vector3(targetVelocity.x, rb.linearVelocity.y, targetVelocity.z);

                if (dir != Vector3.zero)
                {
                    Quaternion targetRot = Quaternion.LookRotation(dir);
                    transform.rotation = Quaternion.Slerp(transform.rotation, targetRot, Time.fixedDeltaTime * 10f); // Sped up rotation slightly
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
            // Randomly wait 3 to 7 seconds
            float waitTime = Random.Range(3f, 7f);
            yield return new WaitForSeconds(waitTime);

            if (gameObject.activeInHierarchy && !grabInteractable.isSelected)
            {
                if (sfxSource != null && randomBaaSfx != null)
                {
                    sfxSource.PlayOneShot(randomBaaSfx);
                }
            }
        }
    }
}