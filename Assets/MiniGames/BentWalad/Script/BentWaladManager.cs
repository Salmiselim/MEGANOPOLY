using System.Collections.Generic;
using System.Linq;
using TMPro;
using Unity.Android.Gradle.Manifest;
using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class BentWaladManager : MonoBehaviour
{
    [Header("UI")]
    public TextMeshProUGUI letterText;
    public TextMeshProUGUI introTimerText;
    public TextMeshProUGUI winnerText;
    public GameObject resultsPanel;

    [Header("Audio")]
    public AudioSource bgmSource;
    public AudioClip bgmClip;

    [Header("Players")]
    public PlayerInputBoard[] playerBoards = new PlayerInputBoard[4]; // Drag 4

    [Header("Game")]
    public string letters = "abcdefghijklmnopqrstuvwxyz";
    public float introDuration = 3f;

    private char currentLetter;
    private Dictionary<char, Dictionary<Category, HashSet<string>>> validWords = new();
    private Dictionary<int, string[]> submissions = new();
    private bool gameEnded = false;
    private Coroutine gameCoroutine;

    public bool GameEnded => gameEnded;

    void Start()
    {
        LoadData();
        PickLetter();
        introTimerText.gameObject.SetActive(true);
        resultsPanel.SetActive(false);
        foreach (var board in playerBoards) board.Init();

        if (bgmSource != null && bgmClip != null)
        {
            bgmSource.clip = bgmClip;
            bgmSource.loop = true;
            bgmSource.Play();
        }

        StartCoroutine(IntroCountdown());
    }

    void LoadData()
    {
        // Path adjusted to match Assets/Resources/BentWaladData.csv (no extension needed for Resources.Load)
        TextAsset csv = Resources.Load<TextAsset>("BentWaladData");
        if (csv == null) { Debug.LogError("Missing BentWaladData in Resources!"); return; }

        string[] lines = csv.text.Split(new[] { '\r', '\n' }, System.StringSplitOptions.RemoveEmptyEntries);
        int entryCount = 0;
        for (int i = 1; i < lines.Length; i++) // Skip header
        {
            string[] parts = lines[i].Split(',');
            if (parts.Length < 3) continue;
            
            char let = parts[0].Trim().ToLowerInvariant()[0];
            
            // Clean category name from CSV to match Enum
            string categoryClean = parts[1].Replace("'", "").Replace(" ", "").ToLowerInvariant();
            Category cat;
            
            if (categoryClean.Contains("boy")) cat = Category.BoysName;
            else if (categoryClean.Contains("girl")) cat = Category.GirlsName;
            else if (categoryClean.Contains("object")) cat = Category.Object;
            else if (categoryClean.Contains("food")) cat = Category.Food;
            else if (categoryClean.Contains("country")) cat = Category.Country;
            else continue;

            string word = CleanWord(parts[2]);

            if (!validWords.ContainsKey(let)) validWords[let] = new();
            if (!validWords[let].ContainsKey(cat)) validWords[let][cat] = new HashSet<string>();
            validWords[let][cat].Add(word);
            entryCount++;
        }
        Debug.Log($"BentWalad: Loaded {entryCount} words for {validWords.Count} letters.");
    }

    private string CleanWord(string word)
    {
        if (string.IsNullOrEmpty(word)) return "";
        // Remove Zero-Width Space (often added by TMP) and trim/lowercase
        return word.Replace("\u200b", "").Trim().ToLowerInvariant();
    }

    void PickLetter()
    {
        currentLetter = letters[Random.Range(0, letters.Length)];
        letterText.text = $"Letter: {char.ToUpper(currentLetter)}";
    }

    public char GetLetter() => currentLetter;

    public bool IsValidWord(char let, Category cat, string word)
    {
        string cleanedInput = CleanWord(word);
        
        Debug.Log($"BentWalad Validating: Category={cat}, Letter={let}, Input='{word}', Cleaned='{cleanedInput}'");

        if (string.IsNullOrEmpty(cleanedInput)) return false;
        
        if (cleanedInput[0] != let) 
        {
            Debug.Log($"BentWalad Fail: Word '{cleanedInput}' does not start with '{let}'");
            return false;
        }
        
        bool found = validWords.ContainsKey(let) && validWords[let].ContainsKey(cat) &&
                     validWords[let][cat].Contains(cleanedInput);
                     
        if (!found)
        {
            Debug.Log($"BentWalad Fail: '{cleanedInput}' not found in dictionary for letter '{let}' and category '{cat}'");
        }
        else
        {
            Debug.Log($"BentWalad Pass: '{cleanedInput}' is valid!");
        }
        
        return found;
    }

    IEnumerator IntroCountdown()
    {
        float elapsed = 0f;
        while (elapsed < introDuration)
        {
            elapsed += Time.deltaTime;
            introTimerText.text = $"Starting in: {Mathf.Ceil(introDuration - elapsed)}";
            yield return null;
        }
        introTimerText.gameObject.SetActive(false);
        gameCoroutine = StartCoroutine(GameLoop());
    }

    IEnumerator GameLoop()
    {
        while (!gameEnded)
        {
            yield return null; 
        }
    }

    public void OnPlayerSubmit(int playerIndex, string[] words)
    {
        if (gameEnded) return;

        // The first one to press the button ends the game for everyone
        submissions[playerIndex] = (string[])words.Clone();
        gameEnded = true;

        foreach (var board in playerBoards) 
        {
            if (board != null) board.LockInput(true);
        }

        CalculateScores();
    }

    void CalculateScores()
    {
        int[] scores = new int[4];
        
        // Ensure all players are in submissions dictionary if you want to show their scores (even 0)
        // But here we only score the one who submitted and anyone else who might have partial data?
        // Actually, in a real game, you'd probably want to capture everyone's current text.
        // For now, let's just score the ones who submitted or just the one who ended the game.
        
        foreach (var kvp in submissions)
        {
            int p = kvp.Key;
            string[] words = kvp.Value;
            for (int c = 0; c < 5; c++)
            {
                string word = words[c]?.Trim() ?? "";
                if (IsValidWord(currentLetter, (Category)c, word))
                    scores[p]++;
            }
        }

        int maxScore = scores.Max();
        int winnerIndex = System.Array.IndexOf(scores, maxScore);
        
        winnerText.text = $"Winner: Player {winnerIndex + 1}!\nScore: {scores[winnerIndex]}/5";
        resultsPanel.SetActive(true);

        if (bgmSource != null)
        {
            bgmSource.Stop();
        }
    }

    public void ResetGame()
    {
        gameEnded = false;
        submissions.Clear();
        StopCoroutine(gameCoroutine);
        foreach (var board in playerBoards) board.Reset();
        introTimerText.gameObject.SetActive(false);
        resultsPanel.SetActive(false);
        
        if (bgmSource != null)
        {
            bgmSource.Stop();
        }

        PickLetter();
        StartCoroutine(IntroCountdown());
    }
}