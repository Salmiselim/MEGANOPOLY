using UnityEngine;

[CreateAssetMenu(menuName = "Monopoly/Minigame Data")]
public class MinigameData : ScriptableObject
{
    [System.Serializable]
    public class MinigameState
    {
        public string propertyName;
        public string currentPlayerName;
        public int minigameType;
        public int winner = -1;
        public int winnerMoney = 0;
        public bool isCompleted = false;
    }

    public MinigameState currentMinigame = new MinigameState();

    public void Reset()
    {
        currentMinigame = new MinigameState();
    }

    public void SetMinigameResult(int winnerId, int prizeAmount)
    {
        currentMinigame.winner = winnerId;
        currentMinigame.winnerMoney = prizeAmount;
        currentMinigame.isCompleted = true;
    }
}
