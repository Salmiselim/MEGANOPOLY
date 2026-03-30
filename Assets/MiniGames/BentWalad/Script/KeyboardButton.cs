using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.UI;

public class KeyboardButton : MonoBehaviour
{
    [SerializeField] private char letter; // A-Z in Inspector
    private PlayerInputBoard board;
    private XRSimpleInteractable interactable;
    private Button interactableComponent;

    // Renamed property to avoid conflict with field
    public bool IsInteractable
    {
        get => interactableComponent != null ? interactableComponent.interactable : false;
        set { if (interactableComponent != null) interactableComponent.interactable = value; }
    }

    public void Init(PlayerInputBoard b) => board = b;

    private void Awake()
    {
        interactableComponent = GetComponent<Button>();
        interactable = GetComponent<XRSimpleInteractable>();
        
        if (interactableComponent != null)
        {
            interactableComponent.onClick.AddListener(OnClick);
        }
        
        if (interactable != null)
        {
            interactable.selectEntered.AddListener(OnSelectEntered);
        }
        
        IsInteractable = interactableComponent != null ? interactableComponent.interactable : true;
    }

    void OnClick() => board?.AppendLetter(char.ToLower(letter)); // Lowercase for matching

    // XR Ray select
    void OnSelectEntered(SelectEnterEventArgs args)
    {
        var identifier = args.interactorObject.transform.GetComponentInParent<PlayerIdentifier>();
        // Only allow if no identifier is present (testing) or if it matches the assigned board
        if (board != null && (identifier == null || identifier.playerIndex == board.PlayerIndex))
        {
            OnClick();
        }
    }
}