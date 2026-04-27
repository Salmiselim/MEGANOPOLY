using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;

/// <summary>
/// Watches for TMP_InputField focus and spawns/repositions the VR keyboard below it.
/// Attach to: the same GO as AuthWorldSpaceUI, or any persistent GO in AuthScene.
/// </summary>
public class VRKeyboardSpawner : MonoBehaviour
{
    [Header("Keyboard Offset (relative to input field)")]
    [SerializeField] private Vector3 keyboardOffset = new Vector3(0f, -0.45f, 0f);

    [Header("Keyboard Scale")]
    [SerializeField] private float keyboardScale = 1f;

    // Internal state
    private VRKeyboard _keyboard;
    private TMP_InputField _activeField;
    private TMP_InputField[] _allFields;

    // ── Unity lifecycle ───────────────────────────────────────────────────────

    private void Start()
    {
        // Find all input fields in scene (username + password)
        _allFields = FindObjectsOfType<TMP_InputField>(includeInactive: true);

        // Subscribe to focus events
        foreach (var field in _allFields)
        {
            var f = field; // capture for lambda
            field.onSelect.AddListener((_) => OnFieldSelected(f));
            field.onDeselect.AddListener((_) => OnFieldDeselected());
        }

        // Build keyboard GO (starts hidden)
        BuildKeyboard();
    }

    private void BuildKeyboard()
    {
        GameObject kbGO = new GameObject("VRKeyboard");
        kbGO.transform.SetParent(null); // world space, not parented to canvas
        kbGO.transform.localScale = Vector3.one * keyboardScale;

        _keyboard = kbGO.AddComponent<VRKeyboard>();
        kbGO.SetActive(false);

        Debug.Log("[VRKeyboardSpawner] Keyboard built and hidden.");
    }

    // ── Field events ──────────────────────────────────────────────────────────

    private void OnFieldSelected(TMP_InputField field)
    {
        _activeField = field;
        _keyboard.TargetField = field;

        // Position keyboard just below the selected input field
        RepositionKeyboard(field);
        _keyboard.gameObject.SetActive(true);

        Debug.Log($"[VRKeyboardSpawner] Keyboard shown for '{field.name}'");
    }

    private void OnFieldDeselected()
    {
        // Small delay — if another field gets selected, keyboard stays open
        Invoke(nameof(HideIfNoFieldActive), 0.15f);
    }

    private void HideIfNoFieldActive()
    {
        if (EventSystem.current != null &&
            EventSystem.current.currentSelectedGameObject != null)
        {
            GameObject sel = EventSystem.current.currentSelectedGameObject;

            // A TMP_InputField gained focus — keep keyboard open
            if (sel.GetComponent<TMP_InputField>() != null) return;

            // A keyboard button was clicked — keep keyboard open
            // (clicking a Button deselects the field, but we should not close)
            if (_keyboard != null && sel.transform.IsChildOf(_keyboard.transform)) return;
        }
        _keyboard.gameObject.SetActive(false);
    }

    private void RepositionKeyboard(TMP_InputField field)
    {
        // Place keyboard in world space below the input field
        Vector3 fieldWorldPos = field.transform.position;
        _keyboard.transform.position = fieldWorldPos + keyboardOffset;

        // Match the input field's rotation so the keyboard is coplanar with the canvas wall
        // (avoids the keyboard clipping into the wall behind it)
        _keyboard.transform.rotation = field.transform.rotation;
    }
}