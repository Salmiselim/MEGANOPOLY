using System.Collections;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit;

public class SheepManager : MonoBehaviour
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
    public Sheep[] allSheep; // Drag 24 inactive sheep here
    public Material[] playerSheepMaterials = new Material[4]; // Red, Green, Blue, Yellow
    [Space]
    public Vector3 spawnCenter = Vector3.zero;
    public float spawnRadius = 15f;
    public float spawnHeightOffset = 0.5f;
    public LayerMask groundLayer = 1; // Default layer for ground raycast
    public float introDuration = 3f;
    public float maxGameDuration = 60f; // Failsafe

    private float gameStartTime;
    private bool gameEnded = false;
    private int winnerIndex = -1;
    private Coroutine introCoroutine;
    private Coroutine gameCoroutine;
    private int[] playerColors = new int[4] { 0, 1, 2, 3 };

    void Start()
    {
        goalText.text = "Grab YOUR sheep first!";
        introTimerText.gameObject.SetActive(true);
        resultsPanel.SetActive(false);
        ResetGame();
        
        if (bgmSource != null && bgmClip != null)
        {
            bgmSource.clip = bgmClip;
            bgmSource.loop = true;
            bgmSource.Play();
        }
        
        introCoroutine = StartCoroutine(IntroCountdown());
    }

    public void CheckWin(int playerIndex)
    {
        if (gameEnded) return;
        winnerIndex = playerIndex;
        gameEnded = true;
        winnerText.text = $"Player {playerIndex + 1} Wins!\n(Their sheep: {ColorToName(playerIndex)})";
        resultsPanel.SetActive(true);
        
        // Stop specific coroutines instead of all
        if (introCoroutine != null) StopCoroutine(introCoroutine);
        if (gameCoroutine != null) StopCoroutine(gameCoroutine);

        if (bgmSource != null)
        {
            bgmSource.Stop();
        }
    }

    string ColorToName(int idx)
    {
        if (idx < 0 || idx >= 4) return "???";
        int colorIdx = playerColors[idx];
        return colorIdx switch { 0 => "Red", 1 => "Green", 2 => "Blue", 3 => "Purple", _ => "???" };
    }

    IEnumerator IntroCountdown()
    {
        float elapsed = 0f;
        while (elapsed < introDuration)
        {
            elapsed += Time.deltaTime;
            introTimerText.text = $"{elapsed:F1}";
            yield return null;
        }
        introTimerText.gameObject.SetActive(false);
        gameStartTime = Time.time;
        SpawnSheep();
        gameCoroutine = StartCoroutine(GameLoop());
    }

    IEnumerator GameLoop()
    {
        yield return new WaitForSeconds(maxGameDuration);
        if (!gameEnded)
        {
            winnerIndex = -1; // Tie/no win
            winnerText.text = "Time's up! No winner.";
            resultsPanel.SetActive(true);
        }
    }

    void SpawnSheep()
    {
        List<int> owners = new List<int> { 0, 1, 2, 3 };
        for (int i = 0; i < allSheep.Length - 4; i++) owners.Add(-1);
        owners = owners.OrderBy(x => Random.value).ToList(); // Shuffle

        for (int i = 0; i < allSheep.Length; i++)
        {
            var sheep = allSheep[i];
            sheep.gameObject.SetActive(true);
            // Pass null material for neutral sheep (owner index -1)
            Material mat = owners[i] >= 0 ? playerSheepMaterials[playerColors[owners[i]]] : null;
            sheep.SetOwner(owners[i], mat);
            Vector3 randPos = spawnCenter + Random.insideUnitSphere * spawnRadius;
            randPos.y = 100f; // High for raycast
            if (Physics.Raycast(randPos, Vector3.down, out RaycastHit hit, 200f, groundLayer))
            {
                randPos.y = hit.point.y + spawnHeightOffset;
            }
            sheep.transform.position = randPos;
            sheep.rb.linearVelocity = Vector3.zero;
            sheep.rb.angularVelocity = Vector3.zero;
        }

        if (bgmSource != null && whistleClip != null)
        {
            bgmSource.PlayOneShot(whistleClip);
        }
    }

    public void ResetGame()
    {
        gameEnded = false;
        winnerIndex = -1;
        
        // Randomize player colors
        List<int> colors = new List<int> { 0, 1, 2, 3 };
        colors = colors.OrderBy(x => Random.value).ToList();
        for (int i = 0; i < 4; i++) playerColors[i] = colors[i];
        
        // Stop specific coroutines with null checks
        if (introCoroutine != null) StopCoroutine(introCoroutine);
        if (gameCoroutine != null) StopCoroutine(gameCoroutine);
        
        introTimerText.gameObject.SetActive(false);
        resultsPanel.SetActive(false);
        foreach (var sheep in allSheep) sheep.gameObject.SetActive(false);

        if (bgmSource != null)
        {
            bgmSource.Stop();
        }
    }

    // For Monopoly: public int GetWinner() => winnerIndex;
}