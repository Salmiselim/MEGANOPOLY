using Unity.Netcode;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

namespace BISS
{
    /// <summary>
    /// Network wrapper for BISSMarble. Add this alongside BISSMarble on the marble prefab.
    ///
    /// Required components on the prefab:
    ///   BISSMarble, NetworkObject, NetworkTransform, XRGrabInteractable,
    ///   Rigidbody, SphereCollider, MeshRenderer (sphere mesh)
    ///
    /// Server spawns this with SpawnWithOwnership(clientId).
    /// Only the owner can grab/throw — all other clients see it move via NetworkTransform.
    /// Color is determined by playerIndex NetworkVariable (set by server right after spawn).
    /// </summary>
    [RequireComponent(typeof(BISSMarble))]
    [RequireComponent(typeof(NetworkObject))]
    public class NetworkBISSMarble : NetworkBehaviour
    {
        // ── Shared color palette — same order on every client ────────────
        public static readonly Color[] PlayerColors =
        {
            new Color(0.95f, 0.22f, 0.18f),  // 0 — Red
            new Color(0.18f, 0.48f, 0.95f),  // 1 — Blue
            new Color(0.15f, 0.80f, 0.22f),  // 2 — Green
            new Color(0.95f, 0.76f, 0.08f),  // 3 — Yellow
        };

        // ── Network state (server writes, all read) ───────────────────────
        public NetworkVariable<int> playerIndex = new NetworkVariable<int>(
            0, NetworkVariableReadPermission.Everyone, NetworkVariableWritePermission.Server);

        // ── Local refs ────────────────────────────────────────────────────
        private BISSMarble _marble;
        private Renderer   _rend;

        private void Awake()
        {
            _marble = GetComponent<BISSMarble>();
            _rend   = GetComponent<Renderer>();
        }

        public override void OnNetworkSpawn()
        {
            // Apply color now and whenever server updates it
            ApplyColor(playerIndex.Value);
            playerIndex.OnValueChanged += (_, v) => ApplyColor(v);

            if (IsOwner)
            {
                // Only the owner can throw — subscribe to local marble events
                _marble.OnMarbleThrown  += HandleThrown;
                _marble.OnMarbleStopped += HandleStopped;
            }
            else
            {
                // Disable grab so only the owner can pick this up.
                // Setting interactionLayers = 0 is belt-and-suspenders: even if the
                // interactable somehow stays enabled, no XR interactor can select it
                // because it belongs to no interaction layer.
                var grab = GetComponent<XRGrabInteractable>();
                if (grab != null)
                {
                    grab.interactionLayers = 0; // remove from ALL layers first
                    grab.enabled = false;
                }

                // Make Rigidbody kinematic on non-owners so NetworkTransform
                // drives the position without local physics fighting it.
                // Without this, gravity + physics simulate locally and the marble
                // immediately falls/teleports instead of following the owner's throw.
                var rb = GetComponent<Rigidbody>();
                if (rb != null) rb.isKinematic = true;
            }
        }

        public override void OnNetworkDespawn()
        {
            _marble.OnMarbleThrown  -= HandleThrown;
            _marble.OnMarbleStopped -= HandleStopped;
        }

        // ── Owner-side event handlers → ServerRpcs ─────────────────────
        private void HandleThrown()
        {
            if (IsOwner) MarbleThrownServerRpc();
        }

        private void HandleStopped()
        {
            if (IsOwner) MarbleStoppedServerRpc(transform.position);
        }

        [ServerRpc]
        private void MarbleThrownServerRpc()
        {
            NetworkBISSTurnManager.Instance?.OnMarbleThrownByOwner();
        }

        [ServerRpc]
        private void MarbleStoppedServerRpc(Vector3 finalPos)
        {
            NetworkBISSTurnManager.Instance?.OnMarbleStoppedByOwner(finalPos);
        }

        // ── Color ─────────────────────────────────────────────────────────
        private void ApplyColor(int idx)
        {
            if (_rend == null) return;
            idx = Mathf.Clamp(idx, 0, PlayerColors.Length - 1);
            // material (not sharedMaterial) creates an instance so we don't affect other marbles
            _rend.material.color = PlayerColors[idx];
        }
    }
}
