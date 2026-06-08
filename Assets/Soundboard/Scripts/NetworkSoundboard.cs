using UnityEngine;
using UnityEngine.UI;
using Unity.Netcode;

public class NetworkSoundboard : NetworkBehaviour
{
    [Header("UI — assign your own buttons")]
    [SerializeField] private Button button1;
    [SerializeField] private Button button2;
    [SerializeField] private Button button3;

    [Header("Sounds — one per button")]
    [SerializeField] private AudioClip clip1;
    [SerializeField] private AudioClip clip2;
    [SerializeField] private AudioClip clip3;

    private AudioSource _audio;

    private void Start()
    {
        _audio              = gameObject.AddComponent<AudioSource>();
        _audio.playOnAwake  = false;
        _audio.spatialBlend = 0f;

        button1?.onClick.AddListener(() => OnSoundClicked(0));
        button2?.onClick.AddListener(() => OnSoundClicked(1));
        button3?.onClick.AddListener(() => OnSoundClicked(2));
    }

    private void OnSoundClicked(int index)
    {
        if (!IsSpawned) return;
        PlaySoundServerRpc(index);
    }

    [ServerRpc(RequireOwnership = false)]
    private void PlaySoundServerRpc(int index)
    {
        PlaySoundClientRpc(index);
    }

    [ClientRpc]
    private void PlaySoundClientRpc(int index)
    {
        AudioClip clip = null;
        if      (index == 0) clip = clip1;
        else if (index == 1) clip = clip2;
        else if (index == 2) clip = clip3;
        if (clip != null) _audio.PlayOneShot(clip);
    }
}
