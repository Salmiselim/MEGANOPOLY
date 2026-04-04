using System.Collections;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using Unity.Netcode;
using XRMultiplayer;

public class SheepManager : NetworkBehaviour
{
    [Header("UI")]
    public TextMeshProUGUI goalText;
    public TextMeshProUGUI introTimerText;
    public TextMeshProUGUI winnerText;
    public GameObject resultsPanel;
    
    [Header("Audio")]
    public AudioSource bgmSource;
    public AudioClip bgmClip;
    public AudioClip whistleClip;

    [Header("Game")]
    public Sheep[] allSheep; // Should be loaded with Sheep objects containing NetworkObjects
    public Material[] playerSheepMaterials = new Material[4]; // Red, Green, Blue, Yellow
    [Space]
    public Vector3 spawnCenter = Vector3.zero;
    public float spawnRadius = 15f;
    public float spawnHeightOffset = 0.5f;
    public LayerMask groundLayer = 1;
    public float introDuration = 3f;
    public float maxGameDuration = 60f; // Failsafe

    private float gameStartTime;
    private NetworkVariable<bool> gameEnded = new NetworkVariable<bool>(false);
    private NetworkVariable<int> winnerIndex = new NetworkVariable<int>(-1);
    
    private Coroutine introCoroutine;
    private Coroutine gameCoroutine;
    
    private int[] playerColors = new int[4] { 0, 1, 2, 3 };

    void Start()
    {
        goalText.text = "Grab YOUR sheep first!";
        introTimerText.gameObject.SetActive(false);
        resultsPanel.SetActive(false);
    }
    
    public override void OnNetworkSpawn()
    {
        base.OnNetworkSpawn();
        
        if (IsServer)
        {
            ResetGameServer();
        }
    }

    [ServerRpc(RequireOwnership = false)]
    public void CheckWinServerRpc(int playerIndex)
    {
        if (gameEnded.Value) return;
        winnerIndex.Value = playerIndex;
        gameEnded.Value = true;
        
        EndGameClientRpc(playerIndex);
    }

    [Rpc(SendTo.Everyone)]
    void EndGameClientRpc(int playerIndex)
    {
        winnerText.text = $"Player {playerIndex + 1} Wins!\n(Their sheep: {ColorToName(playerIndex)})";
        resultsPanel.SetActive(true);
        
        if (introCoroutine != null) StopCoroutine(introCoroutine);
        if (gameCoroutine != null) StopCoroutine(gameCoroutine);

        if (bgmSource != null)
        {
            bgmSource.Stop();
        }
    }
    
    [Rpc(SendTo.Everyone)]
    void TimeoutClientRpc()
    {
        winnerText.text = "Time's up! No winner.";
        resultsPanel.SetActive(true);
    }

    string ColorToName(int idx)
    {
        if (idx < 0 || idx >= 4) return "???";
        int colorIdx = playerColors[idx];
        return colorIdx switch { 0 => "Red", 1 => "Green", 2 => "Blue", 3 => "Purple", _ => "???" };
    }

    // Called by UI button or other systems locally, sent to Server
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
        winnerIndex.Value = -1;
        
        // Randomize player colors
        List<int> colors = new List<int> { 0, 1, 2, 3 };
        colors = colors.OrderBy(x => Random.value).ToList();
        for (int i = 0; i < 4; i++) playerColors[i] = colors[i];
        
        SyncColorsClientRpc(playerColors[0], playerColors[1], playerColors[2], playerColors[3]);
        
        // Disable sheep (NGO does not forbid SetActive, but typically teleporting is safer. Doing SetActive for simplicity unless NGO complains)
        foreach (var sheep in allSheep) 
        {
            sheep.gameObject.SetActive(false);
        }
        
        StartIntroClientRpc();
        
        if (introCoroutine != null) StopCoroutine(introCoroutine);
        if (gameCoroutine != null) StopCoroutine(gameCoroutine);
        
        introCoroutine = StartCoroutine(IntroCountdownServer());
    }

    [Rpc(SendTo.Everyone)]
    void SyncColorsClientRpc(int p0, int p1, int p2, int p3)
    {
        playerColors[0] = p0;
        playerColors[1] = p1;
        playerColors[2] = p2;
        playerColors[3] = p3;
    }

    [Rpc(SendTo.Everyone)]
    void StartIntroClientRpc()
    {
        resultsPanel.SetActive(false);
        introTimerText.gameObject.SetActive(true);
        foreach (var sheep in allSheep) sheep.gameObject.SetActive(false);
        
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
        while (elapsed < introDuration)
        {
            elapsed += Time.deltaTime;
            UpdateIntroTimerClientRpc(elapsed);
            yield return null;
        }
        
        HideIntroClientRpc();
        
        gameStartTime = Time.time;
        SpawnSheepServer();
        gameCoroutine = StartCoroutine(GameLoopServer());
    }
    
    [Rpc(SendTo.Everyone)]
    void UpdateIntroTimerClientRpc(float elapsed)
    {
        introTimerText.text = $"{elapsed:F1}";
    }
    
    [Rpc(SendTo.Everyone)]
    void HideIntroClientRpc()
    {
        introTimerText.gameObject.SetActive(false);
    }

    IEnumerator GameLoopServer()
    {
        yield return new WaitForSeconds(maxGameDuration);
        if (!gameEnded.Value)
        {
            winnerIndex.Value = -1; // Tie/no win
            gameEnded.Value = true;
            TimeoutClientRpc();
        }
    }

    void SpawnSheepServer()
    {
        List<int> owners = new List<int> { 0, 1, 2, 3 };
        for (int i = 0; i < allSheep.Length - 4; i++) owners.Add(-1);
        owners = owners.OrderBy(x => Random.value).ToList(); // Shuffle

        for (int i = 0; i < allSheep.Length; i++)
        {
            var sheep = allSheep[i];
            
            // ClientRpc will enable gameobject on clients
            EnableSheepClientRpc(i);

            Vector3 randPos = spawnCenter + Random.insideUnitSphere * spawnRadius;
            randPos.y = 100f; // High for raycast
            if (Physics.Raycast(randPos, Vector3.down, out RaycastHit hit, 200f, groundLayer))
            {
                randPos.y = hit.point.y + spawnHeightOffset;
            }
            sheep.transform.position = randPos;
            sheep.rb.linearVelocity = Vector3.zero;
            sheep.rb.angularVelocity = Vector3.zero;
            
            int owner = owners[i];
            int matIdx = owner >= 0 ? playerColors[owner] : -1;
            sheep.SetOwnerServer(owner, matIdx);
        }

        PlayWhistleClientRpc();
    }
    
    [Rpc(SendTo.Everyone)]
    void EnableSheepClientRpc(int sheepIndex)
    {
        if (sheepIndex >= 0 && sheepIndex < allSheep.Length)
        {
            allSheep[sheepIndex].gameObject.SetActive(true);
        }
    }

    [Rpc(SendTo.Everyone)]
    void PlayWhistleClientRpc()
    {
        if (bgmSource != null && whistleClip != null)
        {
            bgmSource.PlayOneShot(whistleClip);
        }
    }
}