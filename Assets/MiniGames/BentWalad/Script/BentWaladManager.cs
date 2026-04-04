using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using System.Collections;
using Unity.Netcode;

public class BentWaladManager : NetworkBehaviour
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

    private NetworkVariable<char> currentLetter = new NetworkVariable<char>('a');
    private NetworkVariable<bool> gameEnded = new NetworkVariable<bool>(false);

    private Dictionary<char, Dictionary<Category, HashSet<string>>> validWords = new();
    private Dictionary<int, string[]> submissions = new();
    private Coroutine gameCoroutine;

    public bool GameEnded => gameEnded.Value;

    void Start()
    {
        LoadData();
        introTimerText.gameObject.SetActive(false);
        resultsPanel.SetActive(false);
        foreach (var board in playerBoards) board.Init();
    }
    
    public override void OnNetworkSpawn()
    {
        base.OnNetworkSpawn();
        
        currentLetter.OnValueChanged += (oldL, newL) => {
            letterText.text = $"Letter: {char.ToUpper(newL)}";
        };
        
        if (IsServer)
        {
            ResetGameServer();
        }
        else
        {
            // Initial sync for late joiners
            letterText.text = $"Letter: {char.ToUpper(currentLetter.Value)}";
        }
    }

    void LoadData()
    {
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
        return word.Replace("\u200b", "").Trim().ToLowerInvariant();
    }

    void PickLetterServer()
    {
        if (!IsServer) return;
        currentLetter.Value = letters[Random.Range(0, letters.Length)];
    }

    public char GetLetter() => currentLetter.Value;

    public bool IsValidWord(char let, Category cat, string word)
    {
        string cleanedInput = CleanWord(word);
        
        if (string.IsNullOrEmpty(cleanedInput)) return false;
        
        if (cleanedInput[0] != let) 
        {
            return false;
        }
        
        bool found = validWords.ContainsKey(let) && validWords[let].ContainsKey(cat) &&
                     validWords[let][cat].Contains(cleanedInput);
                     
        return found;
    }

    [ServerRpc(RequireOwnership = false)]
    public void SubmitWordsServerRpc(int playerIndex, string w0, string w1, string w2, string w3, string w4)
    {
        if (gameEnded.Value) return;

        submissions[playerIndex] = new string[] { w0, w1, w2, w3, w4 };
        gameEnded.Value = true;
        
        LockAllBoardsClientRpc();

        CalculateScoresServer();
    }

    [Rpc(SendTo.Everyone)]
    void LockAllBoardsClientRpc()
    {
        foreach (var board in playerBoards) 
        {
            if (board != null) board.LockInput(true);
        }
    }

    void CalculateScoresServer()
    {
        int[] scores = new int[4];
        
        foreach (var kvp in submissions)
        {
            int p = kvp.Key;
            string[] words = kvp.Value;
            for (int c = 0; c < 5; c++)
            {
                string word = words[c]?.Trim() ?? "";
                if (IsValidWord(currentLetter.Value, (Category)c, word))
                    scores[p]++;
            }
        }

        int maxScore = scores.Max();
        int winnerIndex = System.Array.IndexOf(scores, maxScore);
        
        ShowWinnerClientRpc(winnerIndex, scores[winnerIndex]);
    }
    
    [Rpc(SendTo.Everyone)]
    void ShowWinnerClientRpc(int winnerIndex, int score)
    {
        winnerText.text = $"Winner: Player {winnerIndex + 1}!\nScore: {score}/5";
        resultsPanel.SetActive(true);

        if (bgmSource != null)
        {
            bgmSource.Stop();
        }
    }

    public void ResetGame()
    {
        ResetGameServerRpc();
    }
    
    [ServerRpc(RequireOwnership = false)]
    public void ResetGameServerRpc()
    {
        ResetGameServer();
    }

    void ResetGameServer()
    {
        if (!IsServer) return;
        
        gameEnded.Value = false;
        submissions.Clear();
        
        if (gameCoroutine != null) StopCoroutine(gameCoroutine);
        
        ResetUIClientRpc();
        PickLetterServer();
        
        StartCoroutine(IntroCountdownServer());
    }
    
    [Rpc(SendTo.Everyone)]
    void ResetUIClientRpc()
    {
        foreach (var board in playerBoards) board.Reset();
        introTimerText.gameObject.SetActive(false);
        resultsPanel.SetActive(false);
        
        if (bgmSource != null && bgmClip != null)
        {
            bgmSource.clip = bgmClip;
            bgmSource.loop = true;
            bgmSource.Play();
        }
    }

    IEnumerator IntroCountdownServer()
    {
        float elapsed = 0f;
        ShowIntroTextClientRpc(true);
        while (elapsed < introDuration)
        {
            elapsed += Time.deltaTime;
            UpdateIntroTextClientRpc(Mathf.Ceil(introDuration - elapsed));
            yield return null;
        }
        ShowIntroTextClientRpc(false);
        
        gameCoroutine = StartCoroutine(GameLoopServer());
    }

    [Rpc(SendTo.Everyone)]
    void ShowIntroTextClientRpc(bool show)
    {
        introTimerText.gameObject.SetActive(show);
    }
    
    [Rpc(SendTo.Everyone)]
    void UpdateIntroTextClientRpc(float remaining)
    {
        introTimerText.text = $"Starting in: {remaining}";
    }

    IEnumerator GameLoopServer()
    {
        while (!gameEnded.Value)
        {
            yield return null; 
        }
    }
}