using Unity.Netcode;
using UnityEngine;

namespace RockPaperScissors
{
    /// <summary>
    /// Randomly positions the player on spawn so they don't overlap.
    /// </summary>
    public class RandomSpawn : NetworkBehaviour
    {
        [SerializeField] private float range = 1.5f;

        public override void OnNetworkSpawn()
        {
            // Server decides where players spawn to avoid conflicts
            // This works even with default Server Authoritative NetworkTransform
            if (IsServer)
            {
                // Create a random offset (X axis mostly)
                Vector3 randomOffset = new Vector3(
                    Random.Range(-range, range), 
                    0f, 
                    0f // Keep them on the same Z line usually
                );

                transform.position += randomOffset;
            }
        }
    }
}
