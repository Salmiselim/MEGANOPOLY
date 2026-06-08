using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// Self-contained soundboard — drop it anywhere, wire up clips + buttons in the Inspector.
/// No dependencies on any game manager or scene.
/// </summary>
[RequireComponent(typeof(AudioSource))]
public class Soundboard : MonoBehaviour
{
    [System.Serializable]
    public class SoundEntry
    {
        public string      label;      // text shown on the button
        public AudioClip   clip;       // sound to play
        [Range(0f, 1f)]
        public float       volume = 1f;
        public Button      button;     // drag the matching UI Button here
    }

    [Header("Sounds (4 slots)")]
    [SerializeField] private SoundEntry[] entries = new SoundEntry[4];

    [Header("Settings")]
    [Tooltip("Stop the current sound before playing a new one")]
    [SerializeField] private bool exclusive = true;

    private AudioSource _src;

    private void Awake()
    {
        _src = GetComponent<AudioSource>();
        _src.playOnAwake  = false;
        _src.spatialBlend = 0f; // 2-D — soundboard is always full volume
    }

    private void Start()
    {
        for (int i = 0; i < entries.Length; i++)
        {
            var e = entries[i];
            if (e == null || e.button == null) continue;

            // Update button label if provided
            if (!string.IsNullOrEmpty(e.label))
            {
                var tmp = e.button.GetComponentInChildren<TextMeshProUGUI>();
                if (tmp != null) tmp.text = e.label;

                var legacyText = e.button.GetComponentInChildren<Text>();
                if (legacyText != null) legacyText.text = e.label;
            }

            // Capture index for lambda
            var captured = e;
            e.button.onClick.AddListener(() => Play(captured));
        }
    }

    private void Play(SoundEntry e)
    {
        if (e.clip == null) return;

        if (exclusive)
            _src.Stop();

        _src.PlayOneShot(e.clip, e.volume);
    }
}
