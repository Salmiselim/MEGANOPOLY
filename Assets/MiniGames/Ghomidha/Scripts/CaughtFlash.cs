using System.Collections;
using UnityEngine;
using UnityEngine.UI;

namespace Ghomidha
{
    /// <summary>
    /// Full-screen red flash shown to the hider when they are caught.
    ///
    /// SETUP:
    /// 1. Create a World Space Canvas, set it as a child of your XR Camera.
    /// 2. Add a full-screen Image child (stretch to fill, red color, alpha 0).
    /// 3. Place this script on the Canvas root.
    /// 4. Assign the Image in the Inspector.
    /// 5. Position the Canvas 0.3m in front of the camera (Z = 0.3).
    /// </summary>
    public class CaughtFlash : MonoBehaviour
    {
        public static CaughtFlash Instance { get; private set; }

        [SerializeField] private Image flashImage;
        [SerializeField] private float peakAlpha    = 0.65f;
        [SerializeField] private float fadeInTime   = 0.15f;
        [SerializeField] private float holdTime     = 0.3f;
        [SerializeField] private float fadeOutTime  = 0.6f;

        private void Awake()
        {
            Instance = this;
            if (flashImage != null)
                flashImage.color = new Color(1f, 0f, 0f, 0f);
        }

        /// <summary>Call this when the local player is caught by the seeker.</summary>
        public static void TriggerFlash()
        {
            if (Instance != null)
                Instance.StartCoroutine(Instance.DoFlash());
        }

        private IEnumerator DoFlash()
        {
            // Fade in
            yield return Fade(0f, peakAlpha, fadeInTime);
            // Hold
            yield return new WaitForSeconds(holdTime);
            // Fade out
            yield return Fade(peakAlpha, 0f, fadeOutTime);
        }

        private IEnumerator Fade(float from, float to, float duration)
        {
            float elapsed = 0f;
            while (elapsed < duration)
            {
                elapsed += Time.deltaTime;
                float a = Mathf.Lerp(from, to, elapsed / duration);
                if (flashImage != null)
                    flashImage.color = new Color(1f, 0f, 0f, a);
                yield return null;
            }
        }
    }
}
