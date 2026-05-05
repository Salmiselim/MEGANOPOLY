using System.Collections;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using Unity.Netcode;

public class PlayerBread : NetworkBehaviour
{
    [SerializeField] private XRGrabInteractable grabInteractable;
    [SerializeField] private float pullThresholdDistance = 0.3f; // World-space metres
    [SerializeField] private int playerIndex;
    [SerializeField] private Transform ovenParent;

    [Header("Audio")]
    [SerializeField] private AudioSource sfxSource;
    [SerializeField] private AudioClip pullSfx;

    private Vector3 initialWorldPosition;
    private bool isGrabbed;
    private bool hasPulled;
    private KhobzManager manager;

    void Awake()
    {
        manager = FindObjectOfType<KhobzManager>();
        if (grabInteractable == null) grabInteractable = GetComponent<XRGrabInteractable>();
        if (ovenParent == null) ovenParent = transform.parent;
        initialWorldPosition = transform.position;
    }

    public void Init(int index)
    {
        this.playerIndex = index;
    }

    void OnEnable()
    {
        grabInteractable.selectEntered.AddListener(OnSelectEntered);
        grabInteractable.selectExited.AddListener(OnSelectExited);
    }

    void OnDisable()
    {
        grabInteractable.selectEntered.RemoveListener(OnSelectEntered);
        grabInteractable.selectExited.RemoveListener(OnSelectExited);
    }

    void OnSelectEntered(SelectEnterEventArgs args)
    {
        if (NetworkManager.Singleton != null)
        {
            int myClientId = (int)NetworkManager.Singleton.LocalClientId;
            int myAssignedIndex = myClientId % 4;

            if (playerIndex != myAssignedIndex)
            {
                // Force drop by temporarily disabling the interactable so opposing players can't steal bread
                grabInteractable.enabled = false;
                Invoke(nameof(ReenableGrab), 0.5f);
                return;
            }
        }

        isGrabbed = true;
        hasPulled = false;
    }

    void ReenableGrab()
    {
        if (grabInteractable != null) grabInteractable.enabled = true;
    }

    void Update()
    {
        if (isGrabbed && !hasPulled)
        {
            float distancePulled = Vector3.Distance(transform.position, initialWorldPosition);
            if (distancePulled >= pullThresholdDistance)
            {
                hasPulled = true;
                if (manager != null)
                {
                    manager.RegisterPullServerRpc(playerIndex, manager.GetCurrentGameTime());
                }

                if (sfxSource != null && pullSfx != null)
                {
                    sfxSource.PlayOneShot(pullSfx);
                }

                Debug.Log($"[PlayerBread {playerIndex}] Pulled at world distance {distancePulled:F2}m");
            }
        }
    }

    void OnSelectExited(SelectExitEventArgs args)
    {
        if (isGrabbed)
        {
            isGrabbed = false;
            if (!hasPulled)
            {
                StartCoroutine(SnapBack());
            }
        }
    }

    IEnumerator SnapBack()
    {
        float duration = 0.5f;
        Vector3 startPos = transform.position;
        float elapsed = 0f;
        
        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            transform.position = Vector3.Lerp(startPos, initialWorldPosition, elapsed / duration);
            yield return null;
        }
        transform.position = initialWorldPosition;
    }

    public void ResetPull()
    {
        hasPulled = false;
        transform.position = initialWorldPosition;
        isGrabbed = false;
    }
}