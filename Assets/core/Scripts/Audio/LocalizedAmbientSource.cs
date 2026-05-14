using UnityEngine;

namespace Meganopoly.Audio
{
    [RequireComponent(typeof(AudioSource))]
    public class LocalizedAmbientSource : MonoBehaviour
    {
        [Header("3D Sound Settings")]
        [Tooltip("The distance where the sound is at maximum volume.")]
        public float minDistance = 5f;
        [Tooltip("The distance where the sound completely fades out.")]
        public float maxDistance = 20f;
        [Range(0f, 1f)]
        [Tooltip("1 = Fully 3D, 0 = Fully 2D")]
        public float spatialBlend = 1f; 
        
        [Header("Playback")]
        [Tooltip("Randomize start time to prevent multiple similar sounds from phasing.")]
        public bool randomizeStartTime = true;

        private void Start()
        {
            AudioSource audioSource = GetComponent<AudioSource>();
            
            // Force 3D settings
            audioSource.spatialBlend = spatialBlend;
            audioSource.minDistance = minDistance;
            audioSource.maxDistance = maxDistance;
            audioSource.rolloffMode = AudioRolloffMode.Logarithmic;
            audioSource.loop = true;

            if (randomizeStartTime && audioSource.clip != null)
            {
                audioSource.time = Random.Range(0f, audioSource.clip.length);
            }

            if (!audioSource.isPlaying)
            {
                audioSource.Play();
            }
        }
    }
}
