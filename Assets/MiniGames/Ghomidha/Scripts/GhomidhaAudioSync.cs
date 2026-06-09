using System.Collections;
using Unity.Netcode;
using UnityEngine;

namespace Ghomidha
{
    public class GhomidhaAudioSync : NetworkBehaviour
    {
        [SerializeField] private AudioSource backgroundMusic1;
        [SerializeField] private AudioSource backgroundMusic2;

        // How far ahead (in server-time seconds) we schedule playback.
        // Must be larger than the worst-case relay RTT (~300–500 ms).
        [SerializeField] private double playDelaySeconds = 2.0;

        private void Awake()
        {
            if (backgroundMusic1 != null) { backgroundMusic1.playOnAwake = false; backgroundMusic1.Stop(); }
            if (backgroundMusic2 != null) { backgroundMusic2.playOnAwake = false; backgroundMusic2.Stop(); }
        }

        public override void OnNetworkSpawn()
        {
            if (IsServer)
                StartCoroutine(ScheduleMusic());
        }

        private IEnumerator ScheduleMusic()
        {
            // Wait two frames so all clients finish their own OnNetworkSpawn.
            yield return null;
            yield return null;

            double playAt = NetworkManager.Singleton.ServerTime.Time + playDelaySeconds;
            StartMusicClientRpc(playAt);
        }

        [ClientRpc]
        private void StartMusicClientRpc(double targetServerTime)
        {
            StartCoroutine(PlayAtServerTime(targetServerTime));
        }

        private IEnumerator PlayAtServerTime(double targetTime)
        {
            // Spin until the synchronized server clock reaches the target.
            while (NetworkManager.Singleton != null &&
                   NetworkManager.Singleton.ServerTime.Time < targetTime)
                yield return null;

            if (backgroundMusic1 != null) backgroundMusic1.Play();
            if (backgroundMusic2 != null) backgroundMusic2.Play();
        }
    }
}
