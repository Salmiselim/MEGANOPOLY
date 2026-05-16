using UnityEngine;

namespace Meganopoly.Lobby
{
    /// <summary>
    /// Simple Audio Manager for the Lobby scene to play background music and ambient sounds.
    /// Attach this to an empty GameObject in the scene (e.g., "AudioManager").
    /// </summary>
    public class LobbyAudioManager : MonoBehaviour
    {
        [Header("Audio Sources")]
        [Tooltip("The AudioSource dedicated to background music.")]
        public AudioSource musicSource;
        
        [Tooltip("The AudioSource dedicated to ambient sounds (e.g., wind, crowd).")]
        public AudioSource ambientSource;

        [Header("Audio Clips")]
        [Tooltip("Background music clip.")]
        public AudioClip backgroundMusic;

        [Tooltip("Ambient background noise clip.")]
        public AudioClip ambientSound;

        [Header("Settings")]
        [Range(0f, 1f)]
        public float musicVolume = 0.5f;

        [Range(0f, 1f)]
        public float ambientVolume = 0.5f;

        private void Start()
        {
            // Auto-setup AudioSources if they aren't assigned
            if (musicSource == null)
            {
                musicSource = gameObject.AddComponent<AudioSource>();
            }

            if (ambientSource == null)
            {
                ambientSource = gameObject.AddComponent<AudioSource>();
            }

            // Configure and play Music
            if (backgroundMusic != null)
            {
                musicSource.clip = backgroundMusic;
                musicSource.volume = musicVolume;
                musicSource.loop = true;
                musicSource.playOnAwake = false;
                musicSource.Play();
            }
            else
            {
                Debug.LogWarning("LobbyAudioManager: No background music clip assigned.");
            }

            // Configure and play Ambient Sound
            if (ambientSound != null)
            {
                ambientSource.clip = ambientSound;
                ambientSource.volume = ambientVolume;
                ambientSource.loop = true;
                ambientSource.playOnAwake = false;
                ambientSource.Play();
            }
            else
            {
                Debug.LogWarning("LobbyAudioManager: No ambient sound clip assigned.");
            }
        }

        /// <summary>
        /// Update volumes if changed in the inspector at runtime.
        /// </summary>
        private void OnValidate()
        {
            if (musicSource != null)
                musicSource.volume = musicVolume;

            if (ambientSource != null)
                ambientSource.volume = ambientVolume;
        }

        // --- Optional helper methods to control audio during runtime ---

        public void SetMusicVolume(float volume)
        {
            musicVolume = Mathf.Clamp01(volume);
            if (musicSource != null) musicSource.volume = musicVolume;
        }

        public void SetAmbientVolume(float volume)
        {
            ambientVolume = Mathf.Clamp01(volume);
            if (ambientSource != null) ambientSource.volume = ambientVolume;
        }

        public void PlayMusic()
        {
            if (musicSource != null && !musicSource.isPlaying)
                musicSource.Play();
        }

        public void StopMusic()
        {
            if (musicSource != null && musicSource.isPlaying)
                musicSource.Stop();
        }
    }
}
