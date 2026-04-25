using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// World-space VR keyboard that types into the currently focused TMP_InputField.
/// Spawned automatically by VRKeyboardSpawner when an input field is selected.
///
/// Attach to: a prefab or let VRKeyboardSpawner build it procedurally.
/// </summary>
public class VRKeyboard : MonoBehaviour
{
    [Header("Key Settings")]
    [SerializeField] private float keySize = 0.07f;   // metres
    [SerializeField] private float keySpacing = 0.005f;  // metres between keys
    [SerializeField] private float keyDepth = 0.01f;

    [Header("Colors")]
    [SerializeField] private Color keyNormal = new Color(0.15f, 0.15f, 0.20f, 1f);
    [SerializeField] private Color keyHighlight = new Color(0.30f, 0.50f, 0.80f, 1f);
    [SerializeField] private Color keySpecial = new Color(0.10f, 0.10f, 0.14f, 1f);
    [SerializeField] private Color keyText = Color.white;

    // The input field currently being typed into
    public TMP_InputField TargetField { get; set; }

    private bool _capsLock = false;
    private bool _shiftHeld = false;

    // ── Keyboard layout ───────────────────────────────────────────────────────

    private static readonly string[][] _rows = new string[][]
    {
        new[] { "1","2","3","4","5","6","7","8","9","0",  "⌫" },
        new[] { "q","w","e","r","t","y","u","i","o","p"       },
        new[] { "a","s","d","f","g","h","j","k","l",     "⏎" },
        new[] { "⇧","z","x","c","v","b","n","m",",",".", "⇧" },
        new[] { "@","_","-",    "SPACE",    ".com","!","?"    }
    };

    // ── Build ─────────────────────────────────────────────────────────────────

    private void Awake()
    {
        BuildKeyboard();
    }

    private void BuildKeyboard()
    {
        float step = keySize + keySpacing;

        for (int r = 0; r < _rows.Length; r++)
        {
            string[] row = _rows[r];

            // Calculate total row width to centre it
            float rowWidth = 0f;
            foreach (string k in row)
                rowWidth += (k == "SPACE" ? keySize * 4f : keySize) + keySpacing;
            rowWidth -= keySpacing;

            float x = -rowWidth / 2f;
            float y = -r * step;

            foreach (string label in row)
            {
                bool isSpace = label == "SPACE";
                float w = isSpace ? keySize * 4f : keySize;
                bool isSpecial = label is "⌫" or "⏎" or "⇧" or ".com";

                Vector3 pos = new Vector3(x + w / 2f, y, 0f);
                CreateKey(label, pos, w, isSpecial);
                x += w + keySpacing;
            }
        }
    }

    private void CreateKey(string label, Vector3 localPos, float width, bool isSpecial)
    {
        // ── 3D backing cube ───────────────────────────────────────────────
        GameObject key = GameObject.CreatePrimitive(PrimitiveType.Cube);
        key.name = $"Key_{label}";
        key.transform.SetParent(transform, false);
        key.transform.localPosition = localPos;
        key.transform.localScale = new Vector3(width, keySize, keyDepth);

        // Collider needed for XR ray interaction
        BoxCollider col = key.GetComponent<BoxCollider>();
        col.isTrigger = false;

        // Material / colour
        Renderer rend = key.GetComponent<Renderer>();
        Material mat = new Material(Shader.Find("Universal Render Pipeline/Lit"));
        if (mat.shader.name == "Standard" || mat.shader == null)
            mat = new Material(Shader.Find("Standard")); // fallback
        mat.color = isSpecial ? keySpecial : keyNormal;
        rend.material = mat;

        // ── Label canvas on front face ────────────────────────────────────
        GameObject labelGO = new GameObject("Label");
        labelGO.transform.SetParent(key.transform, false);
        labelGO.transform.localPosition = new Vector3(0f, 0f, -0.55f); // front face
        labelGO.transform.localRotation = Quaternion.identity;
        labelGO.transform.localScale = Vector3.one * (1f / keySize) * 0.08f;

        Canvas c = labelGO.AddComponent<Canvas>();
        c.renderMode = RenderMode.WorldSpace;

        RectTransform rt = labelGO.GetComponent<RectTransform>();
        rt.sizeDelta = new Vector2(100f, 100f);

        TextMeshProUGUI tmp = labelGO.AddComponent<TextMeshProUGUI>();
        tmp.text = label == "SPACE" ? "" : label;
        tmp.fontSize = label.Length > 1 ? 28f : 36f;
        tmp.alignment = TextAlignmentOptions.Center;
        tmp.color = keyText;

        // ── Key press handler ─────────────────────────────────────────────
        VRKeyButton btn = key.AddComponent<VRKeyButton>();
        btn.Setup(label, this);
    }

    // ── Input processing ──────────────────────────────────────────────────────

    public void PressKey(string label)
    {
        if (TargetField == null) return;

        switch (label)
        {
            case "⌫":   // backspace
                if (TargetField.text.Length > 0)
                    TargetField.text = TargetField.text[..^1];
                break;

            case "⏎":   // enter — deactivate keyboard
                gameObject.SetActive(false);
                break;

            case "⇧":   // shift / caps
                _shiftHeld = !_shiftHeld;
                UpdateKeyLabels();
                break;

            case "SPACE":
                TargetField.text += " ";
                break;

            default:
                string ch = (_shiftHeld || _capsLock)
                    ? label.ToUpper()
                    : label.ToLower();
                TargetField.text += ch;

                // Auto-release shift after one key
                if (_shiftHeld && !_capsLock)
                {
                    _shiftHeld = false;
                    UpdateKeyLabels();
                }
                break;
        }

        // Move caret to end
        TargetField.caretPosition = TargetField.text.Length;
    }

    private void UpdateKeyLabels()
    {
        bool upper = _shiftHeld || _capsLock;
        foreach (var tmp in GetComponentsInChildren<TextMeshProUGUI>())
        {
            if (tmp.text.Length == 1 && char.IsLetter(tmp.text[0]))
                tmp.text = upper ? tmp.text.ToUpper() : tmp.text.ToLower();
        }
    }
}

/// <summary>
/// Attached to each key cube. Handles XR ray pointer click and physical press.
/// </summary>
public class VRKeyButton : MonoBehaviour
{
    private string _label;
    private VRKeyboard _keyboard;
    private Renderer _rend;
    private Color _originalColor;
    private bool _pressed = false;

    private static readonly Color s_PressColor = new Color(0.30f, 0.50f, 0.80f, 1f);
    private const float CooldownTime = 0.15f;
    private float _cooldown = 0f;

    public void Setup(string label, VRKeyboard keyboard)
    {
        _label = label;
        _keyboard = keyboard;
        _rend = GetComponent<Renderer>();
        _originalColor = _rend.material.color;
    }

    private void Update()
    {
        if (_cooldown > 0f) _cooldown -= Time.deltaTime;
    }

    // Called by XR Ray Interactor (add UnityEvent via XRSimpleInteractable or trigger on pointer click)
    public void OnPress()
    {
        if (_cooldown > 0f) return;
        _cooldown = CooldownTime;

        _keyboard.PressKey(_label);
        StartCoroutine(FlashColor());
    }

    // Physical trigger — finger collision
    private void OnTriggerEnter(Collider other)
    {
        if (_cooldown > 0f) return;
        // Only react to hand/finger colliders tagged properly
        if (other.CompareTag("Finger") || other.CompareTag("Hand"))
            OnPress();
    }

    private System.Collections.IEnumerator FlashColor()
    {
        _rend.material.color = s_PressColor;
        yield return new WaitForSeconds(0.08f);
        _rend.material.color = _originalColor;
    }
}