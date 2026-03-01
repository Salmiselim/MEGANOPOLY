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

    public int ownerIndex = -1;
    public Rigidbody rb { get; private set; }
    private SheepManager manager;
    private Vector3 wanderTarget;
    private Coroutine autoDropCoroutine;

    void Awake()
    {
        manager = FindObjectOfType<SheepManager>();
        rb = GetComponent<Rigidbody>();
        if (grabInteractable == null) grabInteractable = GetComponent<XRGrabInteractable>();
        wanderTarget = transform.position;

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
        var renderer = GetComponent<Renderer>();
        if (idx >= 0 && playerMat != null)
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
        if (!grabInteractable.isSelected)
        {
            Wander();
        }
    }

    void Wander()
    {
        if (Vector3.Distance(transform.position, wanderTarget) < wanderChangeDist)
        {
            wanderTarget = transform.position + (Random.insideUnitSphere * 5f + Vector3.forward * 2f);
            wanderTarget.y = transform.position.y; // Flat
        }
        Vector3 dir = (wanderTarget - transform.position).normalized;
        rb.AddForce(dir * wanderForce);
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