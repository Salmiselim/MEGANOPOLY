using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using System.Collections;
using System.Collections.Generic;

public class PlayerInputBoard : MonoBehaviour
{
    [Header("Category Fields")]
    [SerializeField] private TMP_Text boyField;
    [SerializeField] private TMP_Text girlField;
    [SerializeField] private TMP_Text objectField;
    [SerializeField] private TMP_Text foodField;
    [SerializeField] private TMP_Text countryField;

    [Header("Controls")]
    [SerializeField] private Button backspaceBtn;
    [SerializeField] private Button clearBtn;
    
    [Tooltip("Can be a UI Button or a 3D XR Interactable object")]
    [SerializeField] private GameObject redButton; 

    [SerializeField] private Transform keyboardParent; // Optional: Only if using my KeyboardButton script
    [SerializeField] private int playerIndex;

    public int PlayerIndex => playerIndex;

    private BentWaladManager manager;
    private TMP_Text[] fieldTexts = new TMP_Text[5];
    private Category currentCategory;

    void Awake()
    {
        manager = FindObjectOfType<BentWaladManager>();
    }

    public void Init()
    {
        // Explicitly map fields to array for easier indexing
        fieldTexts[0] = boyField;
        fieldTexts[1] = girlField;
        fieldTexts[2] = objectField;
        fieldTexts[3] = foodField;
        fieldTexts[4] = countryField;

        // Setup fields
        for (int i = 0; i < 5; i++)
        {
            if (fieldTexts[i] == null) { Debug.LogError($"Field {i} is not assigned on Player {playerIndex} board!"); continue; }
            
            fieldTexts[i].text = "";
            
            var btn = fieldTexts[i].GetComponent<Button>(); 
            int index = i; // Closure
            if (btn) btn.onClick.AddListener(() => SetCurrentCategory((Category)index));
        }
        
        SetCurrentCategory(Category.BoysName); // Default

        // Controls
        if (backspaceBtn) backspaceBtn.onClick.AddListener(Backspace);
        if (clearBtn) clearBtn.onClick.AddListener(ClearCurrent);
        
        // Setup Red Button (Handles both UI Button and 3D XR Interactable)
        if (redButton != null)
        {
            var uiBtn = redButton.GetComponent<Button>();
            if (uiBtn != null) uiBtn.onClick.AddListener(TrySubmit);

            var xrBtn = redButton.GetComponent<XRBaseInteractable>();
            if (xrBtn != null) xrBtn.selectEntered.AddListener(OnRedButtonXRSelect);
        }
    }

    private void OnRedButtonXRSelect(SelectEnterEventArgs args)
    {
        // Check if the interactor belongs to the correct player
        var identifier = args.interactorObject.transform.GetComponentInParent<PlayerIdentifier>();
        if (identifier != null && identifier.playerIndex == playerIndex)
        {
            TrySubmit();
        }
        else if (identifier == null)
        {
            // If no identifier system is found, allow it (for testing/simplicity)
            TrySubmit();
        }
    }

    public void AppendLetter(char letter)
    {
        if (manager.GameEnded) return;
        if (fieldTexts[(int)currentCategory] != null)
            fieldTexts[(int)currentCategory].text += letter;
    }

    void Backspace()
    {
        if (manager.GameEnded) return;
        string currentText = fieldTexts[(int)currentCategory].text;
        if (currentText.Length > 0)
            fieldTexts[(int)currentCategory].text = currentText[..^1];
    }

    void ClearCurrent()
    {
        if (manager.GameEnded) return;
        if (fieldTexts[(int)currentCategory] != null)
            fieldTexts[(int)currentCategory].text = "";
    }

    void SetCurrentCategory(Category cat)
    {
        currentCategory = cat;
    }

    void TrySubmit()
    {
        if (manager.GameEnded) return;

        // Collect current text from fields
        string[] currentWords = new string[5];
        for (int i = 0; i < 5; i++)
        {
            currentWords[i] = GetTextFromField(fieldTexts[i]);
        }

        // "the first to input all his words makes the game end"
        bool allFilled = currentWords.All(w => !string.IsNullOrEmpty(w?.Trim()));
        
        if (allFilled)
        {
            manager.OnPlayerSubmit(playerIndex, currentWords);
        }
        else
        {
            Debug.Log($"Player {playerIndex + 1} tried to submit but fields are incomplete.");
        }
    }

    private string GetTextFromField(TMP_Text field)
    {
        if (field == null) return "";
        
        // Check if this text component is part of an InputField (common in user hierarchy)
        var inputField = field.GetComponentInParent<TMP_InputField>();
        if (inputField != null) return inputField.text;
        
        return field.text;
    }

    public void LockInput(bool lockIt)
    {
        if (backspaceBtn) backspaceBtn.interactable = !lockIt;
        if (clearBtn) clearBtn.interactable = !lockIt;
        
        if (redButton != null)
        {
            var uiBtn = redButton.GetComponent<Button>();
            if (uiBtn != null) uiBtn.interactable = !lockIt;

            var xrBtn = redButton.GetComponent<XRBaseInteractable>();
            if (xrBtn != null) xrBtn.enabled = !lockIt;
        }
    }

    public void Reset()
    {
        foreach (var t in fieldTexts) if (t != null) t.text = "";
        SetCurrentCategory(Category.BoysName);
        LockInput(false);
    }
}
