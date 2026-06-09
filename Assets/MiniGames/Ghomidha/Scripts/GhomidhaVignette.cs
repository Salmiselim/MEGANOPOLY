using System.Collections;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;

namespace Ghomidha
{
    /// <summary>
    /// Drives the URP Post-Processing Vignette on a Volume in the scene.
    ///
    /// SETUP:
    /// 1. In the scene add a GameObject → name it "PostProcessVolume".
    /// 2. Add a Volume component → check "Is Global" = true.
    /// 3. Create a new Volume Profile → click "New".
    /// 4. Add override → Vignette → check Color, Intensity, Smoothness.
    ///    Set Intensity = 0.35, Smoothness = 0.5, Color = black. This is the
    ///    permanent ambient spooky vignette (always on).
    /// 5. Add this script to the same GameObject.
    /// 6. Assign the Volume component in the Inspector.
    ///
    /// The script also pulses the vignette darker when the hider is caught.
    /// Call GhomidhaVignette.TriggerCaughtPulse() from CaughtFlash or anywhere.
    /// </summary>
    public class GhomidhaVignette : MonoBehaviour
    {
        public static GhomidhaVignette Instance { get; private set; }

        [SerializeField] private Volume postProcessVolume;

        [Header("Ambient (always-on) vignette")]
        [SerializeField] private float ambientIntensity = 0.35f;

        [Header("Caught pulse")]
        [SerializeField] private float pulseIntensity  = 0.75f;
        [SerializeField] private float pulseInTime     = 0.1f;
        [SerializeField] private float pulseHoldTime   = 0.25f;
        [SerializeField] private float pulseOutTime    = 0.8f;

        private Vignette _vignette;

        private void Awake()
        {
            Instance = this;

            if (postProcessVolume == null)
                postProcessVolume = GetComponent<Volume>();

            if (postProcessVolume != null &&
                postProcessVolume.profile.TryGet(out _vignette))
            {
                _vignette.intensity.Override(ambientIntensity);
            }
            else
            {
                Debug.LogWarning("[GhomidhaVignette] No Vignette override found on the Volume Profile. " +
                                 "Add a Vignette override in the Volume Profile and enable Intensity.");
            }
        }

        /// <summary>Pulse the vignette dark — call when the hider is caught.</summary>
        public static void TriggerCaughtPulse()
        {
            if (Instance != null)
                Instance.StartCoroutine(Instance.DoPulse());
        }

        private IEnumerator DoPulse()
        {
            if (_vignette == null) yield break;

            yield return AnimateIntensity(ambientIntensity, pulseIntensity, pulseInTime);
            yield return new WaitForSeconds(pulseHoldTime);
            yield return AnimateIntensity(pulseIntensity, ambientIntensity, pulseOutTime);
        }

        private IEnumerator AnimateIntensity(float from, float to, float duration)
        {
            float elapsed = 0f;
            while (elapsed < duration)
            {
                elapsed += Time.deltaTime;
                _vignette.intensity.Override(Mathf.Lerp(from, to, elapsed / duration));
                yield return null;
            }
            _vignette.intensity.Override(to);
        }
    }
}
