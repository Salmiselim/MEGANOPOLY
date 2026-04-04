using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.Video; // Added for VideoPlayer

namespace RockPaperScissors
{
    /// <summary>
    /// Simple Rock Paper Scissors game manager
    /// Player clicks buttons, computer chooses randomly, winner is displayed
    /// </summary>
    public class RPSGameManager : MonoBehaviour
    {
        [Header("UI References")]
        [SerializeField] private Button rockButton;
        [SerializeField] private Button paperButton;
        [SerializeField] private Button scissorsButton;
        [SerializeField] private TextMeshProUGUI resultText;
        [SerializeField] private TextMeshProUGUI playerChoiceText;
        [SerializeField] private TextMeshProUGUI computerChoiceText;
        

        
        [Header("Video")]
        [SerializeField] private VideoPlayer backgroundVideo;

        [Header("Timer")]
        [SerializeField] private TextMeshProUGUI timerText;
        [SerializeField] private float gameDuration = 60f;
        
        private float currentTime;
        private bool isGameActive = false;

        // Enum for choices
        public enum Choice
        {
            Rock,
            Paper,
            Scissors
        }
        
        private Choice playerChoice;
        private Choice computerChoice;
        
        void Start()
        {
            // Setup button listeners
            if (rockButton != null)
                rockButton.onClick.AddListener(() => OnPlayerChoice(Choice.Rock));
            
            if (paperButton != null)
                paperButton.onClick.AddListener(() => OnPlayerChoice(Choice.Paper));
            
            if (scissorsButton != null)
                scissorsButton.onClick.AddListener(() => OnPlayerChoice(Choice.Scissors));
            
            // Start Background Video
            if (backgroundVideo != null)
            {
                backgroundVideo.isLooping = true;
                backgroundVideo.Play();
            }

            // Initialize UI and Timer
            ResetGame();
            StartTimer();
            
            Debug.Log("[RPS] Game initialized. Click Rock, Paper, or Scissors to play!");
        }

        void Update()
        {
            if (isGameActive)
            {
                currentTime -= Time.deltaTime;
                UpdateTimerDisplay();

                if (currentTime <= 0)
                {
                    EndGame();
                }
            }
        }

        void StartTimer()
        {
            currentTime = gameDuration;
            isGameActive = true;
            UpdateTimerDisplay();
        }

        void UpdateTimerDisplay()
        {
            if (timerText != null)
            {
                // Format time as 00:00
                int minutes = Mathf.FloorToInt(currentTime / 60F);
                int seconds = Mathf.FloorToInt(currentTime % 60F);
                timerText.text = string.Format("{0:00}:{1:00}", minutes, seconds);

                // Optional: Change color when running low
                if (currentTime <= 10f)
                    timerText.color = Color.red;
                else
                    timerText.color = Color.white;
            }
        }

        void EndGame()
        {
            isGameActive = false;
            currentTime = 0;
            UpdateTimerDisplay();

            if (resultText != null)
            {
                resultText.text = "TIME'S UP!";
                resultText.color = Color.red;
            }
            
            // Disable buttons
            if (rockButton != null) rockButton.interactable = false;
            if (paperButton != null) paperButton.interactable = false;
            if (scissorsButton != null) scissorsButton.interactable = false;

            // Stop Video
            if (backgroundVideo != null)
            {
                backgroundVideo.Pause();
            }

            Debug.Log("[RPS] Time's up! Game Over.");
        }
        
        /// <summary>
        /// Called when player clicks a choice button
        /// </summary>
        public void OnPlayerChoice(Choice choice)
        {
            if (!isGameActive) return;

            playerChoice = choice;
            
            // Computer makes random choice
            computerChoice = GetRandomChoice();
            
            // Update UI
            UpdateChoiceDisplay();
            
            // Determine winner
            string result = DetermineWinner();
            
            // Display result
            DisplayResult(result);
            
            Debug.Log($"[RPS] Player: {playerChoice} | Computer: {computerChoice} | Result: {result}");
        }
        
        /// <summary>
        /// Get random choice for computer
        /// </summary>
        Choice GetRandomChoice()
        {
            int randomValue = Random.Range(0, 3);
            return (Choice)randomValue;
        }
        
        /// <summary>
        /// Determine who wins
        /// </summary>
        string DetermineWinner()
        {
            // Tie
            if (playerChoice == computerChoice)
            {
                return "It's a Tie!";
            }
            
            // Player wins
            if ((playerChoice == Choice.Rock && computerChoice == Choice.Scissors) ||
                (playerChoice == Choice.Paper && computerChoice == Choice.Rock) ||
                (playerChoice == Choice.Scissors && computerChoice == Choice.Paper))
            {
                return "YOU WIN!";
            }
            
            // Computer wins
            return "COMPUTER WINS!";
        }
        
        /// <summary>
        /// Update the choice display text
        /// </summary>
        void UpdateChoiceDisplay()
        {
            if (playerChoiceText != null)
                playerChoiceText.text = $"You chose: {playerChoice.ToString().ToUpper()}";
            
            if (computerChoiceText != null)
                computerChoiceText.text = $"Computer chose: {computerChoice.ToString().ToUpper()}";
        }
        
        /// <summary>
        /// Display the result
        /// </summary>
        void DisplayResult(string result)
        {
            if (resultText != null)
            {
                resultText.text = result;
                
                // Change color based on result
                if (result.Contains("WIN")) // Changed from "Win" to "WIN" to match new string
                    resultText.color = Color.green;
                else if (result.Contains("Tie"))
                    resultText.color = Color.yellow;
                else
                    resultText.color = Color.red;
            }
        }
        
        /// <summary>
        /// Reset the game
        /// </summary>
        public void ResetGame()
        {
            if (resultText != null)
            {
                resultText.text = "Choose your move!";
                resultText.color = Color.white;
            }
            
            if (playerChoiceText != null)
                playerChoiceText.text = "Your choice: ?";
            
            if (computerChoiceText != null)
                computerChoiceText.text = "Computer choice: ?";
        }
        
        // Public methods for button clicks (alternative to using listeners)
        public void OnRockClicked() => OnPlayerChoice(Choice.Rock);
        public void OnPaperClicked() => OnPlayerChoice(Choice.Paper);
        public void OnScissorsClicked() => OnPlayerChoice(Choice.Scissors);
    }
}
