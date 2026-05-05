using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AchievementPopupUI : MonoBehaviour
{
    public static AchievementPopupUI Instance { get; private set; }

    [Header("UI References")]
    [SerializeField] private GameObject popupContainer;
    [SerializeField] private TextMeshProUGUI titleText;
    [SerializeField] private TextMeshProUGUI descriptionText;
    // [SerializeField] private Image iconImage; // Optional for later
    
    [Header("Settings")]
    [SerializeField] private float displayDuration = 4f;
    [SerializeField] private float followSpeed = 5f;
    [SerializeField] private Vector3 positionOffset = new Vector3(0, -0.1f, 1.5f); // Slightly below eye level, 1.5m in front
    [SerializeField] private bool lookAtCamera = true;

    private Camera mainCamera;


    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            mainCamera = Camera.main;
            if (popupContainer != null)
            {
                popupContainer.SetActive(false);
            }
        }
        else if (Instance != this)
        {
            // IMPORTANT: Only destroy the script, NOT the gameObject!
            // Otherwise we delete the entire HUD Canvas!
            Destroy(this);
        }
    }

    public void ShowPopup(AchievementData data)
    {
        Debug.Log($"[AchievementPopupUI] ShowPopup called for {data.title}");
        if (popupContainer == null) 
        {
            Debug.LogWarning("[AchievementPopupUI] Popup Container is NULL! Please assign it in the Inspector.");
            return;
        }
        
        if (titleText != null) titleText.text = data.title;
        if (descriptionText != null) descriptionText.text = data.description;

        // Ensure this GameObject AND its parents are active so we can run coroutines
        if (!gameObject.activeInHierarchy)
        {
            Transform t = transform;
            while (t != null)
            {
                if (!t.gameObject.activeSelf)
                    t.gameObject.SetActive(true);
                t = t.parent;
            }
        }

        StopAllCoroutines();
        StartCoroutine(DisplayRoutine());
    }

    private void LateUpdate()
    {
        if (mainCamera == null) mainCamera = Camera.main;
        if (mainCamera == null || popupContainer == null || !popupContainer.activeInHierarchy) return;

        // Calculate target position: Camera position + offset in camera's space
        Vector3 targetPos = mainCamera.transform.position + mainCamera.transform.TransformDirection(positionOffset);
        
        // Smoothly move to target position
        transform.position = Vector3.Lerp(transform.position, targetPos, Time.deltaTime * followSpeed);

        if (lookAtCamera)
        {
            // Make it face the camera
            Quaternion targetRotation = Quaternion.LookRotation(transform.position - mainCamera.transform.position);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.deltaTime * followSpeed);
        }
    }



    private IEnumerator DisplayRoutine()
    {
        popupContainer.SetActive(true);
        
        // Basic animation scale up (can be replaced with fancy Tween later)
        popupContainer.transform.localScale = Vector3.zero;
        float time = 0;
        while (time < 0.3f)
        {
            popupContainer.transform.localScale = Vector3.Lerp(Vector3.zero, Vector3.one, time / 0.3f);
            time += Time.deltaTime;
            yield return null;
        }
        popupContainer.transform.localScale = Vector3.one;

        // Wait for the display duration
        yield return new WaitForSeconds(displayDuration);

        // Scale down
        time = 0;
        while (time < 0.3f)
        {
            popupContainer.transform.localScale = Vector3.Lerp(Vector3.one, Vector3.zero, time / 0.3f);
            time += Time.deltaTime;
            yield return null;
        }
        popupContainer.transform.localScale = Vector3.zero;

        popupContainer.SetActive(false);
    }
}
