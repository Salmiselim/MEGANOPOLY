using UnityEngine;
using TMPro;

/// <summary>
/// Attach this to any TMP_InputField that needs keyboard input in XR.
///
/// Root cause: TMP_InputField in a World Space Canvas with XR UIInputModule gets
/// SELECTED by the event system when ray-clicked, but is NOT automatically
/// ACTIVATED for typing. This script calls ActivateInputField() on select to fix that.
///
/// On Quest device:  also opens the Meta Quest system keyboard overlay.
/// In Editor:        just type with your physical keyboard after clicking.
///
/// Setup:
///   1. Select your TMP_InputField GameObject
///   2. Add Component → XRKeyboardBridge
///   Done.
/// </summary>
[RequireComponent(typeof(TMP_InputField))]
public class XRKeyboardBridge : MonoBehaviour
{
    private TMP_InputField _field;
    private TouchScreenKeyboard _keyboard;

    private void Start()
    {
        _field = GetComponent<TMP_InputField>();

        // onSelect fires when the EventSystem selects this field (ray click, mouse click, etc.)
        _field.onSelect.AddListener(OnFieldSelected);

        Debug.Log("[XRKeyboardBridge] Registered on: " + gameObject.name);
    }

    private void OnFieldSelected(string currentText)
    {
        Debug.Log("[XRKeyboardBridge] Field selected — activating for input");

        // Force the field into typing mode.
        // Without this call, the field is "selected" but not "active" — no cursor, no typing.
        _field.ActivateInputField();

#if !UNITY_EDITOR
        // On Quest / Android device: also open the system keyboard overlay
        OpenSystemKeyboard();
#endif
    }

    // ── System keyboard (Quest device only) ───────────────────────────────────

    private void OpenSystemKeyboard()
    {
        _keyboard = TouchScreenKeyboard.Open(
            _field.text,
            TouchScreenKeyboardType.Default,
            autocorrection:  false,
            multiline:       false,
            secure:          false,
            alert:           false,
            textPlaceholder: "",
            characterLimit:  _field.characterLimit
        );
    }

    private void Update()
    {
#if UNITY_EDITOR
        return; // In Editor: field is active, type with your physical keyboard
#else
        if (_keyboard == null) return;

        switch (_keyboard.status)
        {
            case TouchScreenKeyboard.Status.Visible:
                _field.text = _keyboard.text;
                break;

            case TouchScreenKeyboard.Status.Done:
                _field.text = _keyboard.text;
                _keyboard = null;
                break;

            case TouchScreenKeyboard.Status.Canceled:
            case TouchScreenKeyboard.Status.LostFocus:
                _keyboard = null;
                break;
        }
#endif
    }

    private void OnDestroy()
    {
        if (_field != null)
            _field.onSelect.RemoveListener(OnFieldSelected);
    }
}
