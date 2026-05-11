using UnityEngine;

namespace RockPaperScissors
{
    /// <summary>
    /// Attach to a GameObject that has a child ParticleSystem.
    /// Wire the reference in MultiplayerRPSGameManager's Inspector.
    /// </summary>
    public class RPSConfettiEffect : MonoBehaviour
    {
        [SerializeField] private ParticleSystem confettiParticles;

        public void PlayWin()
        {
            if (confettiParticles == null) return;
            confettiParticles.Stop(true, ParticleSystemStopBehavior.StopEmittingAndClear);
            confettiParticles.Play();
        }
    }
}
