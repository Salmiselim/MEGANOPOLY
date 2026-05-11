using UnityEngine;

/// <summary>
/// Drop on a persistent GameObject in the Auth scene. Holds music + UI/auth SFX.
/// Music loops, fades in. Other scripts call methods like PlayLoginSuccess() to fire SFX.
/// </summary>
public class AuthSceneAudio : MonoBehaviour
{
    public static AuthSceneAudio Instance { get; private set; }

    [Header("Music")]
    [Tooltip("Calm/welcoming background loop for the auth scene.")]
    public AudioClip musicClip;
    [Range(0f, 1f)] public float musicVolume = 0.35f;
    public bool playMusicOnStart = true;
    public float musicFadeSeconds = 1.5f;

    [Header("SFX — UI")]
    public AudioClip sfxButtonClick;
    public AudioClip sfxButtonHover;
    public AudioClip sfxFieldFocus;
    public AudioClip sfxKeystroke;

    [Header("SFX — Auth Flow")]
    [Tooltip("Plays once when the auth panel first appears in front of the player.")]
    public AudioClip sfxPanelAppear;
    [Tooltip("Plays on successful login or registration.")]
    public AudioClip sfxLoginSuccess;
    [Tooltip("Plays on auth failure (wrong password, network error, etc.).")]
    public AudioClip sfxLoginFail;
    [Tooltip("Plays once before the scene transitions to Lobby.")]
    public AudioClip sfxWelcome;
    [Tooltip("Plays during the fade/scene transition out.")]
    public AudioClip sfxSceneTransition;

    private AudioSource _musicSource;
    private AudioSource _sfxSource;
    private float _targetMusicVolume;

    private void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(this); return; }
        Instance = this;

        _musicSource = gameObject.AddComponent<AudioSource>();
        _musicSource.loop = true;
        _musicSource.playOnAwake = false;
        _musicSource.spatialBlend = 0f;

        _sfxSource = gameObject.AddComponent<AudioSource>();
        _sfxSource.loop = false;
        _sfxSource.playOnAwake = false;
        _sfxSource.spatialBlend = 0f;
    }

    private void Start() { if (playMusicOnStart) PlayMusic(); }

    public void PlayMusic()
    {
        if (musicClip == null) return;
        _musicSource.clip = musicClip;
        _targetMusicVolume = musicVolume;
        _musicSource.volume = 0f;
        _musicSource.Play();
    }

    public void StopMusic() => _musicSource.Stop();

    private void Update()
    {
        if (_musicSource.isPlaying && _musicSource.volume < _targetMusicVolume)
            _musicSource.volume = Mathf.MoveTowards(_musicSource.volume, _targetMusicVolume, Time.deltaTime / Mathf.Max(0.01f, musicFadeSeconds));
    }

    public void PlaySfx(AudioClip clip, float volume = 1f)
    {
        if (clip != null) _sfxSource.PlayOneShot(clip, volume);
    }

    public void PlayButtonClick()      => PlaySfx(sfxButtonClick);
    public void PlayButtonHover()      => PlaySfx(sfxButtonHover, 0.5f);
    public void PlayFieldFocus()       => PlaySfx(sfxFieldFocus, 0.6f);
    public void PlayKeystroke()        => PlaySfx(sfxKeystroke, 0.4f);
    public void PlayPanelAppear()      => PlaySfx(sfxPanelAppear);
    public void PlayLoginSuccess()     => PlaySfx(sfxLoginSuccess);
    public void PlayLoginFail()        => PlaySfx(sfxLoginFail);
    public void PlayWelcome()          => PlaySfx(sfxWelcome);
    public void PlaySceneTransition() => PlaySfx(sfxSceneTransition);

    private void OnDestroy() { if (Instance == this) Instance = null; }
}
