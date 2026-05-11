using UnityEngine;
using TMPro;
using System.Collections.Generic;

public class PlayerCardUI : MonoBehaviour
{
    public static PlayerCardUI Instance { get; private set; }

    [Header("UI References")]
    public TextMeshProUGUI playerNameText;
    public TextMeshProUGUI moneyText;
    public TextMeshProUGUI tileText;
    public Transform propertiesContainer;
    public GameObject propertyChipPrefab;
    public GameObject emptyPropertiesLabel;

    [Header("Card Root")]
    public GameObject cardRoot;

    [Header("Optional")]
    [Tooltip("If left empty, will be resolved at runtime via FindFirstObjectByType.")]
    public BoardManager boardManager;

    private bool isVisible = false;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        // Detach from any parent so DontDestroyOnLoad works (only top-level objects qualify).
        transform.SetParent(null, worldPositionStays: true);
        DontDestroyOnLoad(gameObject);
    }

    public void ToggleCard()
    {
        isVisible = !isVisible;
        if (cardRoot != null)
            cardRoot.SetActive(isVisible);
    }

    public void PopulateFromCloudData(string profileJson, List<int> ownedPropertyIndices)
    {
        if (string.IsNullOrEmpty(profileJson))
        {
            Debug.LogWarning("[PlayerCardUI] Empty profile JSON — nothing to display.");
            return;
        }

        var profile = JsonUtility.FromJson<PlayerProfileData>(profileJson);
        if (profile == null)
        {
            Debug.LogWarning("[PlayerCardUI] Failed to parse profile JSON.");
            return;
        }

        if (playerNameText != null) playerNameText.text = profile.playerName;
        if (moneyText != null)      moneyText.text = $"${profile.money:N0}";
        if (tileText != null)       tileText.text = $"Tile #{profile.currentTile}";

        if (propertiesContainer != null)
        {
            foreach (Transform child in propertiesContainer)
                Destroy(child.gameObject);
        }

        bool hasProps = ownedPropertyIndices != null && ownedPropertyIndices.Count > 0;
        if (emptyPropertiesLabel != null) emptyPropertiesLabel.SetActive(!hasProps);

        if (!hasProps)
        {
            Debug.Log("[PlayerCardUI] No properties to display.");
            return;
        }
        if (propertiesContainer == null)
        {
            Debug.LogWarning("[PlayerCardUI] propertiesContainer is NULL — assign it on the PlayerCardUI component.");
            return;
        }
        if (propertyChipPrefab == null)
        {
            Debug.LogWarning("[PlayerCardUI] propertyChipPrefab is NULL — assign a chip prefab on the PlayerCardUI component.");
            return;
        }

        if (boardManager == null)
            boardManager = Object.FindFirstObjectByType<BoardManager>();

        Debug.Log($"[PlayerCardUI] Spawning {ownedPropertyIndices.Count} property chips into '{propertiesContainer.name}'.");
        foreach (var index in ownedPropertyIndices)
        {
            string label = ResolvePropertyLabel(boardManager, index);
            var chip = Instantiate(propertyChipPrefab, propertiesContainer);
            var chipText = chip.GetComponentInChildren<TextMeshProUGUI>();
            if (chipText != null) chipText.text = label;
        }
    }

    private static string ResolvePropertyLabel(BoardManager board, int tileIndex)
    {
        if (board == null || board.allTiles == null) return $"Tile #{tileIndex}";
        if (tileIndex < 0 || tileIndex >= board.allTiles.Length) return $"Tile #{tileIndex}";
        var tile = board.allTiles[tileIndex];
        return tile != null && !string.IsNullOrEmpty(tile.tileName)
            ? tile.tileName
            : $"Tile #{tileIndex}";
    }
}
