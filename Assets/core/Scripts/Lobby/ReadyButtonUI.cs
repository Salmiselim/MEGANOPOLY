using UnityEngine;
using XRMultiplayer;

public class ReadyButtonUI : MonoBehaviour
{
    public void ToggleLocalPlayerReady()
    {
        if (XRINetworkPlayer.LocalPlayer != null)
        {
            XRINetworkPlayer.LocalPlayer.ToggleReady();
        }
    }
}
