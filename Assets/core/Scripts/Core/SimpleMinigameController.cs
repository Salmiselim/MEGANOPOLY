using UnityEngine;

public class SimpleMinigameController : MonoBehaviour
{
    [Header("Test Settings")]
    [Tooltip("Which playerId should be declared winner when we finish?")]
    public int winnerPlayerId = 0;

    [Tooltip("How much prize money to give the winner. If 0, the orchestrator's prizeAmount is still passed in.")]
    public int overridePrizeAmount = 0;

    public void CompleteMinigame()
    {
        int prize = overridePrizeAmount;
        MinigameOrchestrator.FinishMinigame(winnerPlayerId, prize);
    }
}