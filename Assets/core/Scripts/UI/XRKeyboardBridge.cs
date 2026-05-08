using UnityEngine;
using TMPro;
using UnityEngine.XR.Interaction.Toolkit.Samples.SpatialKeyboard;

/// <summary>
/// Attach to any TMP_InputField that needs XR keyboard input.
///
/// On select: forces the field active (cursor/caret), blocks the native Quest/Android
/// system keyboard, and opens GlobalNonNativeKeyboard (the XR spatial keyboard).
/// If GlobalNonNativeKeyboard is not in the scene a warning is logged.
/// </summary>
[RequireComponent(typeof(TMP_InputField))]
public class XRKeyboardBridge : MonoBehaviour
{
    private TMP_InputField _field;

    private void Start()
    {
        _field = GetComponent<TMP_InputField>();

        // shouldHideSoftKeyboard is the property TMP_InputField.ActivateInputFieldInternal()
        // checks before calling TouchScreenKeyboard.Open(). shouldHideMobileInput is a
        // different property that does NOT prevent the keyboard from opening on Quest.
        _field.shouldHideSoftKeyboard = true;
        _field.resetOnDeActivation = false;

        _field.onSelect.AddListener(OnFieldSelected);
    }

    private void OnFieldSelected(string currentText)
    {
        // Ensure the field is in "active" (typing) mode so the XR keyboard can write to it.
        _field.ActivateInputField();

        if (GlobalNonNativeKeyboard.instance != null)
        {
            GlobalNonNativeKeyboard.instance.ShowKeyboard(_field);
        }
        else
        {
            Debug.LogWarning("[XRKeyboardBridge] GlobalNonNativeKeyboard instance not found. " +
                             "Add a GlobalNonNativeKeyboard component to your XR Rig.", this);
        }
    }

    private void OnDestroy()
    {
        if (_field != null)
            _field.onSelect.RemoveListener(OnFieldSelected);
    }
}
