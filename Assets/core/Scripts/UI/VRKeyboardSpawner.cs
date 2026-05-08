using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;
using UnityEngine.XR.Interaction.Toolkit.Samples.SpatialKeyboard;

/// <summary>
/// Central keyboard manager for the scene.
///
/// When GlobalNonNativeKeyboard is present:
///   Adds XRKeyboardDisplay to every TMP_InputField at runtime. XRKeyboardDisplay is
///   the toolkit's official bridge — it already handles the "already observing" guard
///   (preventing ShowKeyboard from being called on every re-select/key-press), text
///   sync, and keyboard repositioning. No manual onSelect wiring needed.
///
/// When GlobalNonNativeKeyboard is absent:
///   Falls back to the custom VRKeyboard, subscribing to onSelect manually.
///
/// Also sets shouldHideSoftKeyboard = true on every field (the property
/// TMP_InputField.ActivateInputFieldInternal() actually checks before calling
/// TouchScreenKeyboard.Open) and resetOnDeActivation = false (prevents caret
/// position from being lost when XR keyboard interaction deselects the field).
/// </summary>
public class VRKeyboardSpawner : MonoBehaviour
{
    [Header("Keyboard Offset (relative to input field)")]
    [SerializeField] private Vector3 keyboardOffset = new Vector3(0f, -0.45f, 0f);

    [Header("Keyboard Scale")]
    [SerializeField] private float keyboardScale = 1f;

    private VRKeyboard _keyboard;
    private TMP_InputField[] _allFields;

    // ── Unity lifecycle ───────────────────────────────────────────────────────

    private void Start()
    {
        _allFields = FindObjectsOfType<TMP_InputField>(includeInactive: true);
        bool hasGlobalKeyboard = GlobalNonNativeKeyboard.instance != null;

        foreach (var field in _allFields)
        {
            // shouldHideSoftKeyboard is the property TMP checks in ActivateInputFieldInternal()
            // before calling TouchScreenKeyboard.Open(). shouldHideMobileInput is different
            // and does NOT block the keyboard from opening on Quest.
            field.shouldHideSoftKeyboard = true;

            // Prevent the caret position from resetting when XR keyboard interaction
            // causes the EventSystem to deselect the input field momentarily.
            field.resetOnDeActivation = false;

            if (hasGlobalKeyboard)
            {
                // XRKeyboardDisplay is the toolkit's correct bridge between TMP_InputField
                // and GlobalNonNativeKeyboard. It guards against calling ShowKeyboard() on
                // every re-selection (which would reset XRKeyboard state and cause freezes).
                if (field.GetComponent<XRKeyboardDisplay>() == null)
                {
                    var display = field.gameObject.AddComponent<XRKeyboardDisplay>();
                    // Setting via the property triggers the setter which subscribes onSelect
                    // and also enforces resetOnDeActivation = false.
                    display.inputField = field;
                }
            }
            else
            {
                // Fallback: subscribe manually since there is no XRKeyboardDisplay to do it
                var f = field;
                field.onSelect.AddListener((_) => OnFieldSelected(f));
                field.onDeselect.AddListener((_) => OnFieldDeselected());
            }
        }

        if (hasGlobalKeyboard)
        {
            Debug.Log($"[VRKeyboardSpawner] GlobalNonNativeKeyboard found — " +
                      $"added XRKeyboardDisplay to {_allFields.Length} TMP_InputField(s).");
        }
        else
        {
            BuildKeyboard();
        }
    }

    private void BuildKeyboard()
    {
        GameObject kbGO = new GameObject("VRKeyboard");
        kbGO.transform.SetParent(null);
        kbGO.transform.localScale = Vector3.one * keyboardScale;
        _keyboard = kbGO.AddComponent<VRKeyboard>();
        kbGO.SetActive(false);
        Debug.Log("[VRKeyboardSpawner] Fallback VRKeyboard built and hidden.");
    }

    // ── Field events (fallback path only — only reached when GlobalNonNativeKeyboard absent) ──

    private void OnFieldSelected(TMP_InputField field)
    {
        field.ActivateInputField();
        _keyboard.TargetField = field;
        RepositionKeyboard(field);
        _keyboard.gameObject.SetActive(true);
        Debug.Log($"[VRKeyboardSpawner] VRKeyboard (fallback) shown for '{field.name}'");
    }

    private void OnFieldDeselected()
    {
        Invoke(nameof(HideIfNoFieldActive), 0.15f);
    }

    private void HideIfNoFieldActive()
    {
        if (EventSystem.current != null &&
            EventSystem.current.currentSelectedGameObject != null)
        {
            GameObject sel = EventSystem.current.currentSelectedGameObject;
            if (sel.GetComponent<TMP_InputField>() != null) return;
            if (_keyboard != null && sel.transform.IsChildOf(_keyboard.transform)) return;
        }
        _keyboard.gameObject.SetActive(false);
    }

    private void RepositionKeyboard(TMP_InputField field)
    {
        _keyboard.transform.position = field.transform.position + keyboardOffset;
        _keyboard.transform.rotation = field.transform.rotation;
    }
}
