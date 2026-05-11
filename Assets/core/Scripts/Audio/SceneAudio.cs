using UnityEngine;

/// <summary>
/// Drop one of these on a persistent GameObject in each scene that needs music + SFX.
/// Assign clips in the Inspector. Calls PlayMusic() automatically on Start.
/// SFX methods are public so other scripts can trigger them by name.
/// </summary>
public class SceneAudio : MonoBehaviour
{
    [Header("Music")]
    [Tooltip("Background music for this scene. Loops automatically.")]
    public AudioClip musicClip;
    [Range(0f, 1f)] public float musicVolume = 0.4f;
    public bool playMusicOnStart = true;
    public bool fadeMusicIn = true;
    public float musicFadeSeconds = 1.5f;

    [Header("SFX — UI")]
    public AudioClip sfxButtonClick;
    public AudioClip sfxButtonHover;
    public AudioClip sfxNotification;
    public AudioClip sfxError;

    [Header("SFX — Auth Scene")]
    [Tooltip("Plays on successful login/register.")]
    public AudioClip sfxLoginSuccess;
    [Tooltip("Plays on auth failure / wrong password.")]
    public AudioClip sfxLoginFail;
    [Tooltip("Plays once when sign-in completes and the world fades in.")]
    public AudioClip sfxWelcome;

    [Header("SFX — Board Scene")]
    [Tooltip("Plays when the dice are thrown.")]
    public AudioClip sfxDiceRoll;
    [Tooltip("Plays when dice land and the result is read.")]
    public AudioClip sfxDiceLand;
    [Tooltip("Plays when the player piece moves a tile.")]
    public AudioClip sfxStepMove;
    [Tooltip("Plays when buying a property.")]
    public AudioClip sfxPropertyBuy;
    [Tooltip("Plays when paying / receiving rent.")]
    public AudioClip sfxMoneyTransfer;
    [Tooltip("Plays when collecting from GO / winning a prize.")]
    public AudioClip sfxCashReward;
    [Tooltip("Plays when going to or escaping jail.")]
    public AudioClip sfxJail;
    [Tooltip("Plays when the player card pops in via hand gesture.")]
    public AudioClip sfxCardPop;

    private AudioSource _musicSource;
    private AudioSource _sfxSource;
    private float _targetMusicVolume;

    private void Awake()
    {
        _musicSource = gameObject.AddComponent<AudioSource>();
        _musicSource.loop = true;
        _musicSource.playOnAwake = false;
        _musicSource.spatialBlend = 0f; // 2D — music shouldn't be positional

        _sfxSource = gameObject.AddComponent<AudioSource>();
        _sfxSource.loop = false;
        _sfxSource.playOnAwake = false;
        _sfxSource.spatialBlend = 0f;
    }

    private void Start()
    {
        if (playMusicOnStart) PlayMusic();
    }

    public void PlayMusic()
    {
        if (musicClip == null || _musicSource == null) return;
        _musicSource.clip = musicClip;
        _targetMusicVolume = musicVolume;
        _musicSource.volume = fadeMusicIn ? 0f : musicVolume;
        _musicSource.Play();
    }

    public void StopMusic() { if (_musicSource != null) _musicSource.Stop(); }

    private void Update()
    {
        if (_musicSource != null && fadeMusicIn && _musicSource.isPlaying && _musicSource.volume < _targetMusicVolume)
            _musicSource.volume = Mathf.MoveTowards(_musicSource.volume, _targetMusicVolume, Time.deltaTime / Mathf.Max(0.01f, musicFadeSeconds));
    }

    public void PlaySfx(AudioClip clip, float volume = 1f)
    {
        if (clip == null || _sfxSource == null) return;
        _sfxSource.PlayOneShot(clip, volume);
    }

    // Convenience wrappers — any other script can call these.
    public void PlayButtonClick()    => PlaySfx(sfxButtonClick);
    public void PlayButtonHover()    => PlaySfx(sfxButtonHover, 0.5f);
    public void PlayNotification()   => PlaySfx(sfxNotification);
    public void PlayError()          => PlaySfx(sfxError);
    public void PlayLoginSuccess()   => PlaySfx(sfxLoginSuccess);
    public void PlayLoginFail()      => PlaySfx(sfxLoginFail);
    public void PlayWelcome()        => PlaySfx(sfxWelcome);
    public void PlayDiceRoll()       => PlaySfx(sfxDiceRoll);
    public void PlayDiceLand()       => PlaySfx(sfxDiceLand);
    public void PlayStepMove()       => PlaySfx(sfxStepMove, 0.6f);
    public void PlayPropertyBuy()    => PlaySfx(sfxPropertyBuy);
    public void PlayMoneyTransfer() => PlaySfx(sfxMoneyTransfer);
    public void PlayCashReward()     => PlaySfx(sfxCashReward);
    public void PlayJail()           => PlaySfx(sfxJail);
    public void PlayCardPop()        => PlaySfx(sfxCardPop, 0.7f);
}
