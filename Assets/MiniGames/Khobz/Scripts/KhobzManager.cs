using System.Collections;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;


public class KhobzManager : MonoBehaviour
{
    [Header("UI")]
    public TextMeshProUGUI goalText;
    public TextMeshProUGUI introTimerText;
    public TextMeshProUGUI winnerText;
    public GameObject resultsPanel; // Parent of winnerText, set inactive initially

    [Header("Game")]
    public PlayerBread[] playerBreads = new PlayerBread[4];
    public float minGoalTime = 5f;
    public float maxGoalTime = 25f;
    public float introDuration = 3f;
    public float maxGameDuration = 30f;

    private float goalTime;
    private float gameStartTime;
    private List<float> pullTimes = new List<float> { 0f, 0f, 0f, 0f };
    private List<bool> pulledPlayers = new List<bool> { false, false, false, false };
    private Coroutine introCoroutine;
    private Coroutine gameCoroutine;

    void Start()
    {
        GenerateGoalTime();
        goalText.text = $"Goal: {goalTime:F2}s";
        introTimerText.gameObject.SetActive(true);
        resultsPanel.SetActive(false);
        ResetGame();
        introCoroutine = StartCoroutine(IntroCountdown());
    }

    void GenerateGoalTime()
    {
        goalTime = Random.Range(minGoalTime, maxGoalTime);
        goalTime = Mathf.Round(goalTime * 100f) / 100f; // 2 decimal precision
    }

    public void RegisterPull(int playerIndex, float pullTime)
    {
        pullTimes[playerIndex] = pullTime;
        pulledPlayers[playerIndex] = true;
        Debug.Log($"Player {playerIndex} pulled at {pullTime:F2}s");
    }

    public float GetCurrentGameTime()
    {
        return Time.time - gameStartTime;
    }

    IEnumerator IntroCountdown()
    {
        float elapsed = 0f;
        while (elapsed < introDuration)
        {
            elapsed += Time.deltaTime;
            introTimerText.text = $"{elapsed:F2}";
            yield return null;
        }
        introTimerText.gameObject.SetActive(false);
        gameStartTime = Time.time;
        gameCoroutine = StartCoroutine(GameLoop());
    }

    IEnumerator GameLoop()
    {
        float elapsed = 0f;
        int remainingPlayers = 4;
        while (elapsed < maxGameDuration && remainingPlayers > 0)
        {
            elapsed += Time.deltaTime;
            remainingPlayers = pulledPlayers.Where(p => !p).Count();
            yield return null;
        }
        DetermineWinner();
    }

    void DetermineWinner()
    {
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
        winnerText.text = $"Player {winnerIndex + 1} Wins!\nDiff: {bestDiff:F2}s\nGoal: {goalTime:F2}s";
        resultsPanel.SetActive(true);
    }

    public void ResetGame() // Call from Monopoly main game or button
    {
        for (int i = 0; i < 4; i++)
        {
            pullTimes[i] = 0f;
            pulledPlayers[i] = false;
            if (playerBreads[i]) playerBreads[i].ResetPull();
        }
        
        // Add null checks before stopping coroutines
        if (introCoroutine != null) StopCoroutine(introCoroutine);
        if (gameCoroutine != null) StopCoroutine(gameCoroutine);
        
        introTimerText.gameObject.SetActive(false);
        resultsPanel.SetActive(false);
    }
}