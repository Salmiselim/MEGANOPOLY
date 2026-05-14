using UnityEngine;

public class AchievementVFXManager : MonoBehaviour
{
    public static AchievementVFXManager Instance { get; private set; }

    [Header("VFX Prefabs")]
    [SerializeField] private GameObject confettiPrefab;
    [SerializeField] private GameObject starsPrefab;

    [Header("Settings")]
    [SerializeField] private float autoDestroyTime = 3f;

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else Destroy(gameObject);
    }

    public void TriggerAchievementVFX(Vector3 position)
    {
        if (confettiPrefab != null)
        {
            GameObject vfx = Instantiate(confettiPrefab, position, Quaternion.identity);
            Destroy(vfx, autoDestroyTime);
        }

        if (starsPrefab != null)
        {
            GameObject vfx = Instantiate(starsPrefab, position + Vector3.up * 0.5f, Quaternion.identity);
            Destroy(vfx, autoDestroyTime);
        }
    }

    /// <summary>
    /// Triggers VFX near the player's head/camera.
    /// </summary>
    public void TriggerVFXAtPlayer()
    {
        if (Camera.main != null)
        {
            Vector3 spawnPos = Camera.main.transform.position + Camera.main.transform.forward * 1.5f;
            TriggerAchievementVFX(spawnPos);
        }
    }
}
