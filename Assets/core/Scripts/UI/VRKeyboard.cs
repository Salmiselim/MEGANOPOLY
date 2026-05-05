using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.XR.Interaction.Toolkit.UI;

/// <summary>
/// World-space VR keyboard built entirely with UI Canvas + Buttons.
/// No 3-D cube primitives — colours and sizing work correctly in URP.
///
/// VRKeyboardSpawner creates and positions the root GameObject;
/// this script builds the entire canvas hierarchy inside it.
/// </summary>
public class VRKeyboard : MonoBehaviour
{
    [Header("Colors")]
    [SerializeField] private Color colNormal  = new Color(0.18f, 0.18f, 0.24f);
    [SerializeField] private Color colSpecial = new Color(0.08f, 0.08f, 0.12f);
    [SerializeField] private Color colPress   = new Color(0.28f, 0.48f, 0.78f);
    [SerializeField] private Color colText    = Color.white;
    [SerializeField] private Color colBg      = new Color(0.05f, 0.05f, 0.08f, 0.98f);

    // ── Public API ────────────────────────────────────────────────────────────

    /// <summary>The input field currently being typed into.</summary>
    public TMP_InputField TargetField { get; set; }

    // ── Internal state ────────────────────────────────────────────────────────

    private bool _shift;
    private bool _caps;
    private Canvas _canvas;
    private readonly List<TMP_Text> _letterLabels = new();

    // ── Keyboard layout ───────────────────────────────────────────────────────
    // All labels are plain ASCII — no Unicode glyphs that could be missing from the font.

    private static readonly string[][] _rows =
    {
        new[] { "1","2","3","4","5","6","7","8","9","0","Del" },
        new[] { "q","w","e","r","t","y","u","i","o","p"       },
        new[] { "a","s","d","f","g","h","j","k","l","Ent"     },
        new[] { "Shft","z","x","c","v","b","n","m",",",".","Shft" },
        new[] { "@","_","-","SPACE",".com","!","?"             }
    };

    // Relative width: 1 = normal square key.
    // HorizontalLayoutGroup.flexibleWidth distributes space proportionally.
    private static float RelWidth(string k) => k switch
    {
        "SPACE" => 4.5f,
        "Shft"  => 1.6f,
        "Del" or "Ent" => 1.4f,
        ".com"  => 1.5f,
        _       => 1f
    };

    private static bool IsSpecial(string k) =>
        k is "Del" or "Ent" or "Shft" or ".com" or "SPACE";

    // ── Lifecycle ─────────────────────────────────────────────────────────────

    private void Awake() => BuildCanvas();

    private void OnEnable()
    {
        // Assign world camera so clicks register correctly in XR
        if (_canvas != null && Camera.main != null)
            _canvas.worldCamera = Camera.main;
    }

    // ── Canvas construction ───────────────────────────────────────────────────

    private void BuildCanvas()
    {
        // ── Canvas child (so spawner can freely move/rotate the root GO) ──────
        //    Physical size = sizeDelta × localScale = (640, 290) × 0.001 = 0.64 m × 0.29 m
        GameObject canvasGO = new GameObject("KeyboardCanvas");
        canvasGO.transform.SetParent(transform, false);
        canvasGO.transform.localPosition = Vector3.zero;
        canvasGO.transform.localRotation = Quaternion.identity;
        canvasGO.transform.localScale    = Vector3.one * 0.001f;

        _canvas = canvasGO.AddComponent<Canvas>();
        _canvas.renderMode = RenderMode.WorldSpace;

        RectTransform crt = canvasGO.GetComponent<RectTransform>();
        crt.sizeDelta = new Vector2(640f, 290f);

        // XR ray interaction — same raycaster used by the auth canvas
        canvasGO.AddComponent<TrackedDeviceGraphicRaycaster>();

        // ── Full-size dark background ─────────────────────────────────────────
        GameObject bg = MakeRect("BG", canvasGO.transform);
        Stretch(bg.GetComponent<RectTransform>());
        bg.AddComponent<Image>().color = colBg;

        // ── Rows container ────────────────────────────────────────────────────
        GameObject rows = MakeRect("Rows", bg.transform);
        Stretch(rows.GetComponent<RectTransform>(), 8, 8, 8, 8); // 8 px padding

        VerticalLayoutGroup vlg = rows.AddComponent<VerticalLayoutGroup>();
        vlg.spacing            = 5f;
        vlg.childControlWidth  = true;
        vlg.childControlHeight = true;
        vlg.childForceExpandWidth  = true;
        vlg.childForceExpandHeight = true;

        foreach (string[] row in _rows)
            BuildRow(rows.transform, row);
    }

    private void BuildRow(Transform parent, string[] keys)
    {
        GameObject rowGO = MakeRect("Row", parent);
        rowGO.AddComponent<LayoutElement>(); // required for VLG to size it

        HorizontalLayoutGroup hlg = rowGO.AddComponent<HorizontalLayoutGroup>();
        hlg.spacing            = 5f;
        hlg.childControlWidth  = true;
        hlg.childControlHeight = true;
        hlg.childForceExpandWidth  = false;
        hlg.childForceExpandHeight = true;

        foreach (string label in keys)
            BuildKey(rowGO.transform, label);
    }

    private void BuildKey(Transform parent, string label)
    {
        bool spec    = IsSpecial(label);
        Color bgCol  = spec ? colSpecial : colNormal;

        GameObject keyGO = MakeRect($"Key_{label}", parent);

        // Proportional width
        LayoutElement le = keyGO.AddComponent<LayoutElement>();
        le.flexibleWidth = RelWidth(label);
        le.minWidth      = 10f;

        // Background image — this is what the Button tints
        Image img = keyGO.AddComponent<Image>();
        img.color = bgCol;

        // Button with colour feedback
        Button btn = keyGO.AddComponent<Button>();
        btn.targetGraphic = img;
        ColorBlock cb     = ColorBlock.defaultColorBlock;
        cb.normalColor      = bgCol;
        cb.highlightedColor = Color.Lerp(bgCol, Color.white, 0.12f);
        cb.pressedColor     = colPress;
        cb.selectedColor    = bgCol;
        cb.fadeDuration     = 0.05f;
        cb.colorMultiplier  = 1f;
        btn.colors = cb;

        string captured = label;
        btn.onClick.AddListener(() => PressKey(captured));

        // Text label — fills the whole button face
        GameObject lblGO = MakeRect("Lbl", keyGO.transform);
        Stretch(lblGO.GetComponent<RectTransform>());

        TextMeshProUGUI tmp = lblGO.AddComponent<TextMeshProUGUI>();
        tmp.text             = label;
        tmp.alignment        = TextAlignmentOptions.Center;
        tmp.color            = colText;
        tmp.enableAutoSizing = true;
        tmp.fontSizeMin      = 8f;
        tmp.fontSizeMax      = label.Length >= 4 ? 16f : 26f;
        tmp.fontStyle        = FontStyles.Bold;

        // Track single letter keys for Shift label flip
        if (label.Length == 1 && char.IsLetter(label[0]))
            _letterLabels.Add(tmp);
    }

    // ── Key press logic ───────────────────────────────────────────────────────

    public void PressKey(string label)
    {
        if (TargetField == null) return;

        switch (label)
        {
            case "Del":
                if (TargetField.text.Length > 0)
                    TargetField.text = TargetField.text[..^1];
                break;

            case "Ent":
                gameObject.SetActive(false);
                break;

            case "Shft":
                _shift = !_shift;
                RefreshLetterLabels();
                break;

            case "SPACE":
                TargetField.text += " ";
                break;

            default:
                string ch = (_shift || _caps) ? label.ToUpper() : label.ToLower();
                TargetField.text += ch;
                // Auto-release shift after one key
                if (_shift)
                {
                    _shift = false;
                    RefreshLetterLabels();
                }
                break;
        }

        TargetField.caretPosition = TargetField.text.Length;

        // Re-activate the field — clicking a Button deselects it in the EventSystem.
        // Without this, every keypress loses focus and the spawner hides the keyboard.
        TargetField.ActivateInputField();
    }

    private void RefreshLetterLabels()
    {
        bool up = _shift || _caps;
        foreach (TMP_Text t in _letterLabels)
            t.text = up ? t.text.ToUpper() : t.text.ToLower();
    }

    // ── Helpers ───────────────────────────────────────────────────────────────

    private static GameObject MakeRect(string name, Transform parent)
    {
        var go = new GameObject(name, typeof(RectTransform));
        go.transform.SetParent(parent, false);
        return go;
    }

    private static void Stretch(RectTransform rt,
        float left = 0, float right = 0, float bottom = 0, float top = 0)
    {
        rt.anchorMin = Vector2.zero;
        rt.anchorMax = Vector2.one;
        rt.offsetMin = new Vector2(left,   bottom);
        rt.offsetMax = new Vector2(-right, -top);
    }
}
