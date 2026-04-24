using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class AchievementData
{
    public string id;
    public string title;
    public string description;
    public bool isUnlocked;

    public AchievementData(string id, string title, string description)
    {
        this.id = id;
        this.title = title;
        this.description = description;
        this.isUnlocked = false;
    }
}

public class AchievementManager : MonoBehaviour
{
    public static AchievementManager Instance { get; private set; }

    private Dictionary<string, AchievementData> achievements = new Dictionary<string, AchievementData>();

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            gameObject.name = "AchievementManager"; // Force name for GameObject.Find
            DontDestroyOnLoad(gameObject);
            InitializeAchievements();
            LoadAchievements();
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void InitializeAchievements()
    {
        AddAchievement("first_property", "Real Estate Tycoon", "Bought your very first property!");
        AddAchievement("pass_go", "Payday!", "Passed GO and collected your salary.");
        AddAchievement("jailbird", "Jailbird", "Sent to jail for the first time.");
        AddAchievement("first_minigame_win", "Champion", "Won a minigame for the first time.");
        AddAchievement("friendship", "Friendship", "Joined a lobby with another player.");
    }

    private void AddAchievement(string id, string title, string description)
    {
        achievements.Add(id, new AchievementData(id, title, description));
    }

    public void UnlockAchievement(string achievementId)
    {
        if (achievements.TryGetValue(achievementId, out AchievementData data))
        {
            if (!data.isUnlocked)
            {
                data.isUnlocked = true;
                SaveAchievement(achievementId);
                Debug.Log($"[AchievementManager] Unlocked: {data.title} - {data.description}");

                AchievementPopupUI popupUI = AchievementPopupUI.Instance;
                if (popupUI == null)
                {
                    // If Instance is null, it might be on an inactive GameObject, so we try to find it
                    popupUI = FindObjectOfType<AchievementPopupUI>(true);
                    
                    // If found, we can force-initialize its singleton instance for future use
                    // But for now, just use the found reference
                }

                if (popupUI != null)
                {
                    popupUI.ShowPopup(data);
                }
                else
                {
                    Debug.LogWarning("[AchievementManager] AchievementPopupUI not found in scene. Falling back to PlayerHudNotification.");
                    if (XRMultiplayer.PlayerHudNotification.Instance != null)
                    {
                        XRMultiplayer.PlayerHudNotification.Instance.ShowText($"🏆 Achievement Unlocked: {data.title} 🏆\n<color=yellow>{data.description}</color>", 5f);
                    }
                }
            }
        }
        else
        {
            Debug.LogWarning($"[AchievementManager] Achievement ID '{achievementId}' not found.");
        }
    }

    private void SaveAchievement(string id)
    {
        PlayerPrefs.SetInt($"achievement_{id}", 1);
        PlayerPrefs.Save();
    }

    private void LoadAchievements()
    {
        foreach (var kvp in achievements)
        {
            if (PlayerPrefs.GetInt($"achievement_{kvp.Key}", 0) == 1)
            {
                kvp.Value.isUnlocked = true;
            }
        }
        Debug.Log("[AchievementManager] Achievements loaded.");
    }
    
    public void ResetAllAchievements()
    {
        foreach (var kvp in achievements)
        {
            kvp.Value.isUnlocked = false;
            PlayerPrefs.DeleteKey($"achievement_{kvp.Key}");
        }
        PlayerPrefs.Save();
        Debug.Log("[AchievementManager] All achievements reset.");
    }

    private void Update()
    {
        // Debug cheat to reset achievements quickly
        if (Input.GetKeyDown(KeyCode.F10))
        {
            ResetAllAchievements();
        }
    }
}
