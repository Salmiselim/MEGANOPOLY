using UnityEngine;
using UnityEngine.UI;


public class MinigameIntegration : MonoBehaviour
{
    [SerializeField] private Button returnToBoardButton;

    private void Start()
    {
        if (returnToBoardButton != null)
            returnToBoardButton.onClick.AddListener(ReturnToBoard);
    }

    public void EndMinigame(int winnerId, int prizeAmount)
    {
        Debug.Log($"[Minigame] Winner: {winnerId}, Prize: {prizeAmount}");
        MinigameOrchestrator.FinishMinigame(winnerId, prizeAmount);
    }

    private void ReturnToBoard()
    {
        MinigameOrchestrator.FinishMinigame(-1, 0);
    }

    public void OnGameFinishedNaturally(int winnerIndex)
    {
        EndMinigame(winnerIndex, 300);
    }
}
