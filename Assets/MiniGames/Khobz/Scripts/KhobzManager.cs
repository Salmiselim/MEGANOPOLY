using System.Collections;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using Unity.Netcode;

public class KhobzManager : NetworkBehaviour
{
    [Header("UI")]
    public TextMeshProUGUI goalText;
    public TextMeshProUGUI introTimerText;
    public TextMeshProUGUI winnerText;
    public TextMeshProUGUI[] playerTimeTexts = new TextMeshProUGUI[4];
    public GameObject resultsPanel;

    [Header("Audio")]
    public AudioSource bgmSource;
    public AudioClip bgmClip;

    [Header("Spawn Points")]
    public Transform[] playerSpawnPoints = new Transform[4];

    [Header("Game")]
    public PlayerBread[] playerBreads = new PlayerBread[4];
    public float minGoalTime = 5f;
    public float maxGoalTime = 25f;
    public float introDuration = 4f;
    public float maxGameDuration = 60f;

    private NetworkVariable<float> goalTime = new NetworkVariable<float>(0f);
    private NetworkVariable<bool> gameRunning = new NetworkVariable<bool>(false);
    private float gameStartTime;

    private List<float> pullTimes = new List<float> { 0f, 0f, 0f, 0f };
    private List<bool> pulledPlayers = new List<bool> { false, false, false, false };

    private Coroutine introCoroutine;
    private Coroutine gameCoroutine;

    void Start()
    {
        goalText.gameObject.SetActive(true);
        goalText.text = "Waiting for Game to Start...";

        for (int i = 0; i < playerTimeTexts.Length; i++)
        {
            if (playerTimeTexts[i] != null) playerTimeTexts[i].text = "";
            if (i < playerBreads.Length && playerBreads[i] != null) playerBreads[i].Init(i);
        }

        resultsPanel.SetActive(false);
        introTimerText.gameObject.SetActive(false);
    }

    public override void OnNetworkSpawn()
    {
        base.OnNetworkSpawn();

        if (playerSpawnPoints != null && playerSpawnPoints.Length > 0)
        {
            int clientId = (int)NetworkManager.Singleton.LocalClientId;
            int spawnIndex = clientId % playerSpawnPoints.Length;
            
            if (playerSpawnPoints[spawnIndex] != null)
            {
                var xrOrigin = FindFirstObjectByType<Unity.XR.CoreUtils.XROrigin>();
                if (xrOrigin != null)
                {
                    xrOrigin.transform.position = playerSpawnPoints[spawnIndex].position;
                    xrOrigin.transform.rotation = playerSpawnPoints[spawnIndex].rotation;
                }
            }
        }
        
        goalTime.OnValueChanged += (oldVal, newVal) => {
            goalText.text = $"Goal: {newVal:F2}s";
        };

        // If late joined, update immediately
        if (goalTime.Value > 0f)
        {
            goalText.text = $"Goal: {goalTime.Value:F2}s";
        }

        if (IsServer)
        {
            ResetGameServer();
        }
    }

    void GenerateGoalTimeServer()
    {
        float target = Random.Range(minGoalTime, maxGoalTime);
        goalTime.Value = Mathf.Round(target * 100f) / 100f;
    }

    [ServerRpc(RequireOwnership = false)]
    public void RegisterPullServerRpc(int playerIndex, float pullTime)
    {
        if (!gameRunning.Value) return;

        pullTimes[playerIndex] = pullTime;
        pulledPlayers[playerIndex] = true;
        
        UpdatePlayerTimeClientRpc(playerIndex, pullTime);

        if (pulledPlayers.All(p => p))
        {
            if (gameCoroutine != null) StopCoroutine(gameCoroutine);
            DetermineWinnerServer();
        }
    }

    [Rpc(SendTo.Everyone)]
    void UpdatePlayerTimeClientRpc(int playerIndex, float pullTime)
    {
        if (playerIndex >= 0 && playerIndex < playerTimeTexts.Length && playerTimeTexts[playerIndex] != null)
        {
            playerTimeTexts[playerIndex].text = $"P{playerIndex + 1}: {pullTime:F2}s";
        }
    }

    public float GetCurrentGameTime()
    {
        return Time.time - gameStartTime;
    }

    // Usually called from a UI button to retry
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

        gameRunning.Value = false;
        GenerateGoalTimeServer();

        for (int i = 0; i < 4; i++)
        {
            pullTimes[i] = 0f;
            pulledPlayers[i] = false;
        }
        
        ResetBreadsClientRpc();

        if (introCoroutine != null) StopCoroutine(introCoroutine);
        if (gameCoroutine != null) StopCoroutine(gameCoroutine);

        StartIntroClientRpc();
        
        introCoroutine = StartCoroutine(IntroCountdownServer());
    }

    [Rpc(SendTo.Everyone)]
    void ResetBreadsClientRpc()
    {
        for (int i = 0; i < 4; i++)
        {
            if (playerTimeTexts[i] != null)
                playerTimeTexts[i].text = "";
                
            if (playerBreads[i]) playerBreads[i].ResetPull();
        }
    }

    [Rpc(SendTo.Everyone)]
    void StartIntroClientRpc()
    {
        resultsPanel.SetActive(false);
        introTimerText.gameObject.SetActive(true);
        
        if (bgmSource != null && bgmClip != null)
        {
            bgmSource.clip = bgmClip;
            bgmSource.loop = true;
            bgmSource.Play();
        }
    }

    IEnumerator IntroCountdownServer()
    {
        gameRunning.Value = false;
        float elapsed = 0f;

        while (elapsed < introDuration)
        {
            elapsed += Time.deltaTime;
            int remaining = Mathf.CeilToInt(introDuration - elapsed);
            UpdateIntroTextClientRpc(remaining);
            yield return null;
        }

        HideIntroClientRpc();
        SetGameStartTimeClientRpc(); // Ensures every client zeroes out their own Time.time
        
        gameRunning.Value = true;
        gameCoroutine = StartCoroutine(GameLoopServer());
    }
    
    [Rpc(SendTo.Everyone)]
    void SetGameStartTimeClientRpc()
    {
        gameStartTime = Time.time; 
    }

    [Rpc(SendTo.Everyone)]
    void UpdateIntroTextClientRpc(int remaining)
    {
        if (!introTimerText.gameObject.activeSelf) 
        {
            introTimerText.gameObject.SetActive(true);
        }
        introTimerText.text = remaining > 0 ? remaining.ToString() : "GO!";
    }

    [Rpc(SendTo.Everyone)]
    void HideIntroClientRpc()
    {
        introTimerText.gameObject.SetActive(false);
    }

    IEnumerator GameLoopServer()
    {
        float elapsed = 0f;
        while (elapsed < maxGameDuration)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        gameRunning.Value = false;
        bool anyonePulled = pulledPlayers.Any(p => p);

        if (!anyonePulled)
        {
            ShowEveryoneLosesClientRpc();
        }
        else
        {
            DetermineWinnerServer();
        }
    }

    void DetermineWinnerServer()
    {
        gameRunning.Value = false;

        float bestDiff = float.MaxValue;
        int winnerIndex = -1;

        for (int i = 0; i < 4; i++)
        {
            if (!pulledPlayers[i])
            {
                pullTimes[i] = 999f;
            }

            float diff = Mathf.Abs(pullTimes[i] - goalTime.Value);
            if (diff < bestDiff)
            {
                bestDiff = diff;
                winnerIndex = i;
            }
        }

        ShowWinnerClientRpc(winnerIndex, pullTimes[winnerIndex], goalTime.Value, bestDiff);
    }

    [Rpc(SendTo.Everyone)]
    void ShowWinnerClientRpc(int winnerIndex, float pullTime, float gTime, float bestDiff)
    {
        winnerText.text = $"Player {winnerIndex + 1} Wins!\nYour time: {pullTime:F2}s\nGoal: {gTime:F2}s\nDiff: {bestDiff:F2}s";
        resultsPanel.SetActive(true);

        if (bgmSource != null)
        {
            bgmSource.Stop();
        }
    }

    [Rpc(SendTo.Everyone)]
    void ShowEveryoneLosesClientRpc()
    {
        winnerText.text = "Everyone Loses!";
        resultsPanel.SetActive(true);

        if (bgmSource != null)
        {
            bgmSource.Stop();
        }
    }
}