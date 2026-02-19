using UnityEngine;
using TMPro;
using UnityEngine.Video;

namespace RockPaperScissors
{
    /// <summary>
    /// Hand-tracking based Rock Paper Scissors game.
    /// Player has 5 seconds to make a gesture with their right hand.
    /// </summary>
    public class RPSHandTrackingGame : MonoBehaviour
    {
        [Header("References")]
        [SerializeField] private HandShapeDetector handDetector;
        [SerializeField] private VideoPlayer backgroundVideo;
        
        [Header("UI")]
        [SerializeField] private TextMeshProUGUI timerText;
        [SerializeField] private TextMeshProUGUI instructionText;
        [SerializeField] private TextMeshProUGUI playerChoiceText;
        [SerializeField] private TextMeshProUGUI computerChoiceText;
        [SerializeField] private TextMeshProUGUI resultText;
        
        [Header("Settings")]
        [SerializeField] private float roundDuration = 5f;
        [SerializeField] private float resultDisplayTime = 3f;
        
        private float currentTime;
        private bool isRoundActive = false;
        private HandShapeDetector.HandShape playerChoice;
        private HandShapeDetector.HandShape computerChoice;
        
        void Start()
        {
            // Start Background Video
            if (backgroundVideo != null)
            {
                backgroundVideo.isLooping = true;
                backgroundVideo.Play();
            }
            
            // Validate hand detector
            if (handDetector == null)
            {
                Debug.LogError("[RPS] HandShapeDetector reference is missing!");
                return;
            }
            
            StartNewRound();
            Debug.Log("[RPS Hand Tracking] Game initialized!");
        }
        
        void Update()
        {
            if (!isRoundActive) return;
            
            // Countdown timer
            currentTime -= Time.deltaTime;
            UpdateTimerDisplay();
            
            // Round ends when timer hits 0
            if (currentTime <= 0)
            {
                EndRound();
            }
        }
        
        void StartNewRound()
        {
            isRoundActive = true;
            currentTime = roundDuration;
            
            // Reset UI
            if (instructionText != null)
                instructionText.text = "Make your move with your RIGHT HAND!";
            
            if (playerChoiceText != null)
                playerChoiceText.text = "Your choice: ?";
            
            if (computerChoiceText != null)
                computerChoiceText.text = "Computer choice: ?";
            
            if (resultText != null)
            {
                resultText.text = "";
                resultText.color = Color.white;
            }
            
            UpdateTimerDisplay();
            Debug.Log("[RPS] New round started!");
        }
        
        void UpdateTimerDisplay()
        {
            if (timerText != null)
            {
                timerText.text = Mathf.CeilToInt(currentTime).ToString();
                
                // Change color when running low
                if (currentTime <= 2f)
                    timerText.color = Color.red;
                else if (currentTime <= 3f)
                    timerText.color = Color.yellow;
                else
                    timerText.color = Color.white;
            }
        }
        
        void EndRound()
        {
            isRoundActive = false;
            
            // Capture player's RIGHT hand choice
            if (handDetector != null)
            {
                playerChoice = handDetector.RightHandShape;
            }
            else
            {
                playerChoice = HandShapeDetector.HandShape.None;
            }
            
            // Generate computer choice
            computerChoice = GetRandomChoice();
            
            // Display choices
            UpdateChoiceDisplay();
            
            // Determine and display winner
            string result = DetermineWinner();
            DisplayResult(result);
            
            Debug.Log($"[RPS] Round ended - Player: {playerChoice} | Computer: {computerChoice} | Result: {result}");
            
            // Start next round after delay
            Invoke(nameof(StartNewRound), resultDisplayTime);
        }
        
        HandShapeDetector.HandShape GetRandomChoice()
        {
            int randomValue = Random.Range(0, 3);
            // 0 = Rock, 1 = Paper, 2 = Scissors
            return (HandShapeDetector.HandShape)(randomValue + 1); // +1 to skip "None"
        }
        
        void UpdateChoiceDisplay()
        {
            if (playerChoiceText != null)
            {
                string choiceName = GetChoiceName(playerChoice);
                playerChoiceText.text = $"You chose: {choiceName}";
                playerChoiceText.color = GetChoiceColor(playerChoice);
            }
            
            if (computerChoiceText != null)
            {
                string choiceName = GetChoiceName(computerChoice);
                computerChoiceText.text = $"Computer chose: {choiceName}";
                computerChoiceText.color = GetChoiceColor(computerChoice);
            }
        }
        
        string GetChoiceName(HandShapeDetector.HandShape choice)
        {
            switch (choice)
            {
                case HandShapeDetector.HandShape.Rock: return "ROCK";
                case HandShapeDetector.HandShape.Paper: return "PAPER";
                case HandShapeDetector.HandShape.Scissors: return "SCISSORS";
                default: return "NONE";
            }
        }
        
        Color GetChoiceColor(HandShapeDetector.HandShape choice)
        {
            switch (choice)
            {
                case HandShapeDetector.HandShape.Rock: return Color.red;
                case HandShapeDetector.HandShape.Paper: return Color.green;
                case HandShapeDetector.HandShape.Scissors: return Color.yellow;
                default: return Color.white;
            }
        }
        
        string DetermineWinner()
        {
            // If player didn't make a choice
            if (playerChoice == HandShapeDetector.HandShape.None)
            {
                return "NO CHOICE - COMPUTER WINS!";
            }
            
            // Tie
            if (playerChoice == computerChoice)
            {
                return "IT'S A TIE!";
            }
            
            // Player wins
            if ((playerChoice == HandShapeDetector.HandShape.Rock && computerChoice == HandShapeDetector.HandShape.Scissors) ||
                (playerChoice == HandShapeDetector.HandShape.Paper && computerChoice == HandShapeDetector.HandShape.Rock) ||
                (playerChoice == HandShapeDetector.HandShape.Scissors && computerChoice == HandShapeDetector.HandShape.Paper))
            {
                return "YOU WIN!";
            }
            
            // Computer wins
            return "COMPUTER WINS!";
        }
        
        void DisplayResult(string result)
        {
            if (resultText != null)
            {
                resultText.text = result;
                
                // Change color based on result
                if (result.Contains("YOU WIN"))
                    resultText.color = Color.green;
                else if (result.Contains("TIE"))
                    resultText.color = Color.yellow;
                else
                    resultText.color = Color.red;
            }
            
            if (instructionText != null)
            {
                instructionText.text = result;
                instructionText.color = resultText.color;
            }
        }
    }
}
