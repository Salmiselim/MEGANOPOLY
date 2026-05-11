using UnityEngine;

namespace BISS
{
    /// <summary>
    /// Plays a sparkle burst when a marble result is recorded.
    /// Called directly by NetworkBISSTurnManager.MarbleResultClientRpc.
    ///
    /// SETUP:
    /// 1. Add this script to any GameObject in the scene (e.g. the HoleTarget).
    /// 2. Create a child ParticleSystem and assign it in the Inspector.
    /// 3. Assign this component to NetworkBISSTurnManager's "Sparkle" field.
    /// </summary>
    public class BISSSparkle : MonoBehaviour
    {
        [SerializeField] private ParticleSystem sparkleParticles;

        private void Start()
        {
            if (sparkleParticles != null)
            {
                var main = sparkleParticles.main;
                main.simulationSpace = ParticleSystemSimulationSpace.World;
            }
        }

        public void PlayScore()
        {
            if (sparkleParticles == null) return;
            sparkleParticles.Stop(true, ParticleSystemStopBehavior.StopEmittingAndClear);
            sparkleParticles.Play();
        }
    }
}
