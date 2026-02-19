using System.Collections;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class PlayerBread : MonoBehaviour
{
    [SerializeField] private XRGrabInteractable grabInteractable;
    [SerializeField] private float pullThresholdDistance = 0.4f;
    [SerializeField] private int playerIndex;
    [SerializeField] private Transform ovenParent; // Drag oven transform here for relative pos

    private Vector3 initialLocalPosition;
    private bool isGrabbed;
    private bool hasPulled;
    private KhobzManager manager;

    void Awake()
    {
        manager = FindObjectOfType<KhobzManager>();
        if (grabInteractable == null) grabInteractable = GetComponent<XRGrabInteractable>();
        if (ovenParent == null) ovenParent = transform.parent;
        initialLocalPosition = transform.localPosition;
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
        hasPulled = false; // Reset per grab if needed
    }

    void OnSelectExited(SelectExitEventArgs args)
    {
        if (isGrabbed)
        {
            isGrabbed = false;
            if (!hasPulled)
            {
                Vector3 currentLocal = transform.localPosition;
                float distancePulled = Vector3.Distance(currentLocal, initialLocalPosition);
                if (distancePulled >= pullThresholdDistance)
                {
                    hasPulled = true;
                    manager.RegisterPull(playerIndex, manager.GetCurrentGameTime());
                    // Visual feedback: e.g., play particle, change color
                    // Optional: Snap bread out fully
                }
                else
                {
                    // Snap back
                    StartCoroutine(SnapBack());
                }
            }
        }
    }

    IEnumerator SnapBack()
    {
        float duration = 0.5f;
        Vector3 startPos = transform.localPosition;
        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            transform.localPosition = Vector3.Lerp(startPos, initialLocalPosition, elapsed / duration);
            yield return null;
        }
        transform.localPosition = initialLocalPosition;
    }

    public void ResetPull()
    {
        hasPulled = false;
        transform.localPosition = initialLocalPosition;
        isGrabbed = false;
    }
}