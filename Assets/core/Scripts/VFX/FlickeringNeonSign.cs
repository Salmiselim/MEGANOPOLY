using UnityEngine;
using System.Collections;

namespace Meganopoly.VFX
{
    public class FlickeringNeonSign : MonoBehaviour
    {
        [Header("Target Components")]
        [Tooltip("The Light component to flicker. Leave empty if no light source exists.")]
        public Light targetLight;
        [Tooltip("The Renderer containing the emissive material.")]
        public Renderer targetRenderer;
        public int materialIndex = 0;
        
        [Header("Flicker Settings")]
        public float minIntensity = 0.5f;
        public float maxIntensity = 2.0f;
        public float flickerSpeed = 0.1f;
        [Tooltip("If true, flickers randomly like a broken neon. If false, pulses smoothly.")]
        public bool randomFlicker = true;

        [Header("Material Settings")]
        [ColorUsage(true, true)]
        public Color emissiveColor = Color.white;
        
        private Material neonMaterial;
        private float baseIntensity;
        private Color baseEmissiveColor;

        private void Start()
        {
            if (targetLight != null)
            {
                baseIntensity = targetLight.intensity;
            }

            if (targetRenderer != null && targetRenderer.materials.Length > materialIndex)
            {
                // Create a material instance so we don't modify the shared material asset
                neonMaterial = targetRenderer.materials[materialIndex];
                if (neonMaterial.HasProperty("_EmissionColor"))
                {
                    baseEmissiveColor = emissiveColor;
                    neonMaterial.EnableKeyword("_EMISSION");
                }
            }
            
            StartCoroutine(FlickerRoutine());
        }

        private IEnumerator FlickerRoutine()
        {
            while (true)
            {
                float intensityMultiplier = 1f;

                if (randomFlicker)
                {
                    // Simulate broken neon flicker (on/off randomly)
                    if (Random.value > 0.8f)
                    {
                        intensityMultiplier = Random.Range(minIntensity, maxIntensity);
                    }
                    else
                    {
                        intensityMultiplier = Random.value > 0.1f ? maxIntensity : minIntensity;
                    }
                    
                    yield return new WaitForSeconds(Random.Range(flickerSpeed * 0.5f, flickerSpeed * 2f));
                }
                else
                {
                    // Smooth sine wave pulse
                    intensityMultiplier = Mathf.Lerp(minIntensity, maxIntensity, (Mathf.Sin(Time.time * flickerSpeed) + 1f) / 2f);
                    yield return null;
                }

                if (targetLight != null)
                {
                    targetLight.intensity = intensityMultiplier;
                }

                if (neonMaterial != null && neonMaterial.HasProperty("_EmissionColor"))
                {
                    neonMaterial.SetColor("_EmissionColor", baseEmissiveColor * intensityMultiplier);
                }
            }
        }
    }
}
