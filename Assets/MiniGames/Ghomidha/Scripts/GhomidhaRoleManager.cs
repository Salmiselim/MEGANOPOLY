using UnityEngine;

namespace Ghomidha
{
    /// <summary>
    /// Singleton that survives scene loads and carries the locally-assigned role
    /// (Seeker or Hider) from the GhomidhaLobby into the actual Ghomidha game scene.
    ///
    /// Usage in the game scene:
    ///   if (GhomidhaRoleManager.Instance.IsSeeker) { ... }
    ///
    /// Note: MultiplayerHidingSpot and MultiplayerSeekerController currently use
    /// IsHost to determine the seeker. With this manager you can override that check:
    ///   Replace  "if (IsHost)"  with  "if (GhomidhaRoleManager.Instance.IsSeeker)"
    /// </summary>
    public class GhomidhaRoleManager : MonoBehaviour
    {
        public static GhomidhaRoleManager Instance { get; private set; }

        /// <summary>True if the local player was assigned the Seeker role.</summary>
        public bool IsSeeker { get; private set; } = false;

        /// <summary>True if the local player was assigned the Hider role.</summary>
        public bool IsHider => !IsSeeker;

        private void Awake()
        {
            if (Instance != null && Instance != this)
            {
                Destroy(gameObject);
                return;
            }
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }

        /// <summary>Called by GhomidhaLobbyManager once the role is determined.</summary>
        public void SetRole(bool isSeeker)
        {
            IsSeeker = isSeeker;
            Debug.Log($"[GhomidhaRoleManager] Local player role set to: {(isSeeker ? "SEEKER" : "HIDER")}");
        }
    }
}
