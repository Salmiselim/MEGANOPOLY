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

    [SerializeField] private Transform keyboardParent;
    [SerializeField] private int playerIndex;

    [Header("Audio")]
    [SerializeField] private AudioSource sfxSource;
    [SerializeField] private AudioClip buttonSfx;

    public int PlayerIndex => playerIndex;

    private BentWaladManager manager;
    private TMP_Text[] fieldTexts = new TMP_Text[5];
    private Category currentCategory;

    void Awake()
    {
        manager = FindObjectOfType<BentWaladManager>();
    }

    public void Init(int index)
    {
        this.playerIndex = index;
        fieldTexts[0] = boyField;
        fieldTexts[1] = girlField;
        fieldTexts[2] = objectField;
        fieldTexts[3] = foodField;
        fieldTexts[4] = countryField;

        for (int i = 0; i < 5; i++)
        {
            if (fieldTexts[i] == null) { Debug.LogError($"Field {i} is not assigned on Player {playerIndex} board!"); continue; }
            
            fieldTexts[i].text = "";
            
            var btn = fieldTexts[i].GetComponent<Button>(); 
            int capturedIndex = i; 
            if (btn) btn.onClick.AddListener(() => SetCurrentCategory((Category)capturedIndex));
        }
        
        SetCurrentCategory(Category.BoysName); 

        if (backspaceBtn) backspaceBtn.onClick.AddListener(Backspace);
        if (clearBtn) clearBtn.onClick.AddListener(ClearCurrent);
        
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
        TrySubmit();
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

        string[] currentWords = new string[5];

        if (sfxSource != null && buttonSfx != null)
        {
            sfxSource.PlayOneShot(buttonSfx);
        }

        for (int i = 0; i < 5; i++)
        {
            currentWords[i] = GetTextFromField(fieldTexts[i]);
        }

        bool allFilled = currentWords.All(w => !string.IsNullOrEmpty(w?.Trim()));
        
        if (allFilled)
        {
            // Trigger the global end game sequence instead of just submitting local words
            manager.EndRoundServerRpc();
        }
        else
        {
            Debug.Log($"Player {playerIndex + 1} tried to submit but fields are incomplete.");
        }
    }

    public void SendMyWordsToServer()
    {
        string[] currentWords = new string[5];
        for (int i = 0; i < 5; i++)
        {
            currentWords[i] = GetTextFromField(fieldTexts[i]);
        }
        manager.ReportWordsServerRpc(playerIndex, currentWords[0], currentWords[1], currentWords[2], currentWords[3], currentWords[4]);
    }

    private string GetTextFromField(TMP_Text field)
    {
        if (field == null) return "";
        
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
