using UnityEngine;

public class DiceEventTester : MonoBehaviour
{
    public DiceControllerV2 dice1;
    public DiceControllerV2 dice2;

    private void Start()
    {
        if (dice1 != null)
        {
            dice1.OnDiceRolled.AddListener(OnDice1Result);
            Debug.Log("✓ Dice 1 event connected");
        }

        if (dice2 != null)
        {
            dice2.OnDiceRolled.AddListener(OnDice2Result);
            Debug.Log("✓ Dice 2 event connected");
        }
    }

    private void OnDice1Result(int value)
    {
        Debug.Log($"🎲 DICE 1 EVENT RECEIVED: {value}");
    }

    private void OnDice2Result(int value)
    {
        Debug.Log($"🎲 DICE 2 EVENT RECEIVED: {value}");
    }
}