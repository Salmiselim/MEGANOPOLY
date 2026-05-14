using UnityEngine;
using System.Collections;

namespace Meganopoly.Audio
{
    [RequireComponent(typeof(AudioSource))]
    public class CityAmbientManager : MonoBehaviour
    {
        [Header("Ambient Settings")]
        public float fadeDuration = 3f;
        [Range(0f, 1f)]
        public float maxVolume = 1f;

        private AudioSource audioSource;

        private void Start()
        {
            audioSource = GetComponent<AudioSource>();
            audioSource.loop = true;
            audioSource.volume = 0f;
            audioSource.spatialBlend = 0f; // Ensure it's 2D globally
            audioSource.Play();
            
            StartCoroutine(FadeIn());
        }

        private IEnumerator FadeIn()
        {
            float currentTime = 0;
            while (currentTime < fadeDuration)
            {
                currentTime += Time.deltaTime;
                audioSource.volume = Mathf.Lerp(0, maxVolume, currentTime / fadeDuration);
                yield return null;
            }
            audioSource.volume = maxVolume;
        }
    }
}
