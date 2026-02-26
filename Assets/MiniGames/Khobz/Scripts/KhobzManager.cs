using System.Collections;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;


public class KhobzManager : MonoBehaviour
{
    [Header("UI")]
    public TextMeshProUGUI goalText;          // Always visible: shows the goal time
    public TextMeshProUGUI introTimerText;    // Shows for 4 seconds then hides
    public TextMeshProUGUI winnerText;
    public TextMeshProUGUI[] playerTimeTexts = new TextMeshProUGUI[4]; // Shows each player's pull time after they pull
    public GameObject resultsPanel;           // Parent of winnerText, set inactive initially

    [Header("Game")]
    public PlayerBread[] playerBreads = new PlayerBread[4];
    public float minGoalTime = 5f;
    public float maxGoalTime = 25f;
    public float introDuration = 4f;          // 4-second intro countdown
    public float maxGameDuration = 60f;       // 60-second game timeout

    private float goalTime;
    private float gameStartTime;
    private bool gameRunning = false;
    private List<float> pullTimes = new List<float> { 0f, 0f, 0f, 0f };
    private List<bool> pulledPlayers = new List<bool> { false, false, false, false };
    private Coroutine introCoroutine;
    private Coroutine gameCoroutine;

    void Start()
    {
        GenerateGoalTime();

        // Goal text is ALWAYS visible
        goalText.gameObject.SetActive(true);
        goalText.text = $"Goal: {goalTime:F2}s";

        // Hide player time texts at start
        for (int i = 0; i < playerTimeTexts.Length; i++)
        {
            if (playerTimeTexts[i] != null)
                playerTimeTexts[i].text = "";
        }

        resultsPanel.SetActive(false);
        introTimerText.gameObject.SetActive(true);
        introCoroutine = StartCoroutine(IntroCountdown());
    }

    void GenerateGoalTime()
    {
        goalTime = Random.Range(minGoalTime, maxGoalTime);
        goalTime = Mathf.Round(goalTime * 100f) / 100f; // 2 decimal precision
    }

    /// <summary>
    /// Called by PlayerBread when a player successfully pulls their bread.
    /// </summary>
    public void RegisterPull(int playerIndex, float pullTime)
    {
        if (!gameRunning) return; // Ignore pulls before game starts or after it ends

        pullTimes[playerIndex] = pullTime;
        pulledPlayers[playerIndex] = true;
        Debug.Log($"Player {playerIndex + 1} pulled at {pullTime:F2}s");

        // Show this player's achieved time immediately
        if (playerIndex < playerTimeTexts.Length && playerTimeTexts[playerIndex] != null)
        {
            playerTimeTexts[playerIndex].text = $"P{playerIndex + 1}: {pullTime:F2}s";
        }

        // If all players have pulled, end the game early
        if (pulledPlayers.All(p => p))
        {
            if (gameCoroutine != null) StopCoroutine(gameCoroutine);
            DetermineWinner();
        }
    }

    public float GetCurrentGameTime()
    {
        return Time.time - gameStartTime;
    }

    IEnumerator IntroCountdown()
    {
        gameRunning = false;
        float elapsed = 0f;

        while (elapsed < introDuration)
        {
            elapsed += Time.deltaTime;
            // Countdown: 4 → 3 → 2 → 1
            int remaining = Mathf.CeilToInt(introDuration - elapsed);
            introTimerText.text = remaining > 0 ? remaining.ToString() : "GO!";
            yield return null;
        }

        introTimerText.gameObject.SetActive(false);
        gameStartTime = Time.time;
        gameRunning = true;
        gameCoroutine = StartCoroutine(GameLoop());
    }

    IEnumerator GameLoop()
    {
        float elapsed = 0f;

        while (elapsed < maxGameDuration)
        {
            elapsed += Time.deltaTime;

            // If all players have pulled, the game ends inside RegisterPull
            // so this loop just handles the timeout
            yield return null;
        }

        // Timeout reached
        gameRunning = false;
        bool anyonePulled = pulledPlayers.Any(p => p);

        if (!anyonePulled)
        {
            // Nobody pulled — everyone loses
            ShowEveryoneLoses();
        }
        else
        {
            // At least one player pulled — determine the closest
            DetermineWinner();
        }
    }

    void DetermineWinner()
    {
        gameRunning = false;

        float bestDiff = float.MaxValue;
        int winnerIndex = -1;

        for (int i = 0; i < 4; i++)
        {
            if (!pulledPlayers[i])
            {
                pullTimes[i] = 999f; // Penalty for not pulling
            }

            float diff = Mathf.Abs(pullTimes[i] - goalTime);
            if (diff < bestDiff)
            {
                bestDiff = diff;
                winnerIndex = i;
            }
        }

        winnerText.text = $"Player {winnerIndex + 1} Wins!\nYour time: {pullTimes[winnerIndex]:F2}s\nGoal: {goalTime:F2}s\nDiff: {bestDiff:F2}s";
        resultsPanel.SetActive(true);
    }

    void ShowEveryoneLoses()
    {
        winnerText.text = "Everyone Loses!";
        resultsPanel.SetActive(true);
    }

    public void ResetGame()
    {
        gameRunning = false;

        for (int i = 0; i < 4; i++)
        {
            pullTimes[i] = 0f;
            pulledPlayers[i] = false;
            if (playerBreads[i]) playerBreads[i].ResetPull();

            if (i < playerTimeTexts.Length && playerTimeTexts[i] != null)
                playerTimeTexts[i].text = "";
        }

        if (introCoroutine != null) StopCoroutine(introCoroutine);
        if (gameCoroutine != null) StopCoroutine(gameCoroutine);

        introTimerText.gameObject.SetActive(false);
        resultsPanel.SetActive(false);

        // Goal text stays always visible
        goalText.gameObject.SetActive(true);
    }
}