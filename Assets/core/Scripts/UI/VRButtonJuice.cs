using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.Interactors;
using System.Collections;

public class VRButtonJuice : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler, IPointerClickHandler
{
    [Header("UI Text")]
    [SerializeField] private TMP_Text buttonText;
    [SerializeField] private string defaultText = "";

    [Header("Animations")]
    [SerializeField] private Transform scaleTransform;
    [SerializeField] private float hoverScale = 1.1f;
    [SerializeField] private float clickScale = 0.9f;
    [SerializeField] private float animationSpeed = 10f;

    [Header("Haptics")]
    [SerializeField] private float hoverIntensity = 0.1f;
    [SerializeField] private float hoverDuration = 0.1f;
    [SerializeField] private float clickIntensity = 0.5f;
    [SerializeField] private float clickDuration = 0.1f;

    private XRBaseInteractable interactable;
    private Vector3 originalScale;
    private Coroutine scaleCoroutine;

    private void Awake()
    {
        // Check self and parent for interactable just in case the script is on a visual child object
        interactable = GetComponentInParent<XRBaseInteractable>();
        if (scaleTransform == null) scaleTransform = transform;
        originalScale = scaleTransform.localScale;

        if (buttonText != null && !string.IsNullOrEmpty(defaultText))
        {
            buttonText.text = defaultText;
        }

        if (interactable != null)
        {
            interactable.hoverEntered.AddListener(OnHoverEnter);
            interactable.hoverExited.AddListener(OnHoverExit);
            interactable.selectEntered.AddListener(OnClick);
        }
        else
        {
            Debug.LogWarning("[VRButtonJuice] No XRBaseInteractable found on this object or its parent! Animations will only trigger via UGUI Pointer events.");
        }
    }

    public void SetText(string text)
    {
        if (buttonText != null) buttonText.text = text;
    }

    // --- XR Interactable Events ---
    private void OnHoverEnter(HoverEnterEventArgs args)
    {
        TriggerHaptic(args.interactorObject, hoverIntensity, hoverDuration);
        StartScaleAnimation(originalScale * hoverScale);
    }

    private void OnHoverExit(HoverExitEventArgs args)
    {
        StartScaleAnimation(originalScale);
    }

    private void OnClick(SelectEnterEventArgs args)
    {
        TriggerHaptic(args.interactorObject, clickIntensity, clickDuration);
        StartCoroutine(ClickBounceEffect());
    }

    // --- UGUI Pointer Events ---
    public void OnPointerEnter(PointerEventData eventData)
    {
        StartScaleAnimation(originalScale * hoverScale);
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        StartScaleAnimation(originalScale);
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        StartCoroutine(ClickBounceEffect());
    }

    // --- Animations & Haptics ---
    private IEnumerator ClickBounceEffect()
    {
        yield return StartCoroutine(AnimateScale(originalScale * clickScale));
        yield return StartCoroutine(AnimateScale(originalScale * hoverScale));
    }

    private void StartScaleAnimation(Vector3 target)
    {
        if (scaleCoroutine != null) StopCoroutine(scaleCoroutine);
        
        if (gameObject.activeInHierarchy)
            scaleCoroutine = StartCoroutine(AnimateScale(target));
        else
            scaleTransform.localScale = target;
    }

    private IEnumerator AnimateScale(Vector3 target)
    {
        // Use an asymptotic lerp for that juicy ease-out feel
        while (Vector3.Distance(scaleTransform.localScale, target) > 0.01f)
        {
            scaleTransform.localScale = Vector3.Lerp(scaleTransform.localScale, target, Time.deltaTime * animationSpeed);
            yield return null;
        }
        scaleTransform.localScale = target;
    }

    private void TriggerHaptic(IXRInteractor interactor, float intensity, float duration)
    {
        if (interactor is XRBaseInputInteractor controllerInteractor)
        {
            controllerInteractor.xrController.SendHapticImpulse(intensity, duration);
        }
    }

    private void OnDestroy()
    {
        if (interactable != null)
        {
            interactable.hoverEntered.RemoveListener(OnHoverEnter);
            interactable.hoverExited.RemoveListener(OnHoverExit);
            interactable.selectEntered.RemoveListener(OnClick);
        }
    }
}
