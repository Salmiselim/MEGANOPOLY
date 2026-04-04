using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.UI;

namespace Ghomidha
{
    /// <summary>
    /// Ensures the scene has everything needed for XR hand/controller
    /// ray interaction with World Space UI Canvas buttons.
    ///
    /// SETUP:
    /// 1. Add this script to any persistent GameObject in the scene (e.g. "SceneSetup").
    /// 2. It auto-adds an EventSystem and XRUIInputModule if missing.
    /// 3. Make sure your XR Origin's Ray Interactors have
    ///    "XR Ray Interactor" + "XR Interactor Line Visual" components.
    ///
    /// NOTE: World Space Canvas buttons need a GraphicRaycaster
    ///       AND the XRUIInputModule to work in XR — this handles that.
    /// </summary>
    public class HidingSceneSetup : MonoBehaviour
    {
        private void Awake()
        {
            EnsureEventSystem();
        }

        private void EnsureEventSystem()
        {
            EventSystem existing = FindFirstObjectByType<EventSystem>();
            if (existing != null)
            {
                // Make sure it has XRUIInputModule
                if (existing.GetComponent<XRUIInputModule>() == null)
                {
                    existing.gameObject.AddComponent<XRUIInputModule>();
                    Debug.Log("[HidingSceneSetup] Added XRUIInputModule to existing EventSystem.");
                }
                return;
            }

            // Create a fresh one
            GameObject esGO = new GameObject("EventSystem");
            esGO.AddComponent<EventSystem>();
            esGO.AddComponent<XRUIInputModule>();
            Debug.Log("[HidingSceneSetup] Created EventSystem with XRUIInputModule.");
        }
    }
}
