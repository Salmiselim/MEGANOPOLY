using System.Collections;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class PlayerBread : MonoBehaviour
{
    [SerializeField] private XRGrabInteractable grabInteractable;
    [SerializeField] private float pullThresholdDistance = 0.3f; // World-space metres
    [SerializeField] private int playerIndex;
    [SerializeField] private Transform ovenParent; // Drag oven transform here for relative pos

    private Vector3 initialWorldPosition;
    private bool isGrabbed;
    private bool hasPulled;
    private KhobzManager manager;

    void Awake()
    {
        manager = FindObjectOfType<KhobzManager>();
        if (grabInteractable == null) grabInteractable = GetComponent<XRGrabInteractable>();
        if (ovenParent == null) ovenParent = transform.parent;
        // Use world position for reliable cross-scale detection
        initialWorldPosition = transform.position;
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
        isGrabbed = true;
        hasPulled = false;
    }

    void Update()
    {
        // Check distance in world space while grabbed so detection happens in real-time
        if (isGrabbed && !hasPulled)
        {
            float distancePulled = Vector3.Distance(transform.position, initialWorldPosition);
            if (distancePulled >= pullThresholdDistance)
            {
                hasPulled = true;
                if (manager != null)
                    manager.RegisterPull(playerIndex, manager.GetCurrentGameTime());
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
                // Snap back to original world position
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