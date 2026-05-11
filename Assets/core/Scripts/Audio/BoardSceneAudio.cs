using UnityEngine;

/// <summary>
/// Drop on a persistent GameObject in the Board scene. Holds music + gameplay SFX.
/// Music loops, fades in. Other scripts call methods like PlayDiceRoll() to fire SFX.
/// </summary>
public class BoardSceneAudio : MonoBehaviour
{
    public static BoardSceneAudio Instance { get; private set; }

    [Header("Music")]
    [Tooltip("Upbeat/playful background loop for the board scene.")]
    public AudioClip musicClip;
    [Range(0f, 1f)] public float musicVolume = 0.3f;
    public bool playMusicOnStart = true;
    public float musicFadeSeconds = 1.5f;

    [Header("Music — Special Moments")]
    [Tooltip("Optional sting played when a player wins.")]
    public AudioClip musicVictorySting;
    [Tooltip("Optional sting played when a player goes bankrupt / loses.")]
    public AudioClip musicDefeatSting;

    [Header("SFX — UI")]
    public AudioClip sfxButtonClick;
    public AudioClip sfxButtonHover;
    public AudioClip sfxNotification;
    public AudioClip sfxError;

    [Header("SFX — Dice & Movement")]
    public AudioClip sfxDiceShake;
    public AudioClip sfxDiceRoll;
    public AudioClip sfxDiceLand;
    [Tooltip("Single tile-step sound. Plays per step as the piece moves.")]
    public AudioClip sfxStepMove;
    public AudioClip sfxArrivedOnTile;

    [Header("SFX — Money & Property")]
    public AudioClip sfxPropertyBuy;
    public AudioClip sfxPropertySell;
    public AudioClip sfxRentPay;
    public AudioClip sfxRentReceive;
    public AudioClip sfxCashReward;
    public AudioClip sfxBankrupt;

    [Header("SFX — Special Events")]
    public AudioClip sfxJailIn;
    public AudioClip sfxJailEscape;
    public AudioClip sfxChanceCard;
    public AudioClip sfxMinigameStart;
    public AudioClip sfxTurnStart;
    public AudioClip sfxTurnEnd;

    [Header("SFX — Player Card")]
    [Tooltip("Plays when the palm-gesture card pops in.")]
    public AudioClip sfxCardPop;

    private AudioSource _musicSource;
    private AudioSource _sfxSource;
    private AudioSource _stingSource;
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

        _stingSource = gameObject.AddComponent<AudioSource>();
        _stingSource.loop = false;
        _stingSource.playOnAwake = false;
        _stingSource.spatialBlend = 0f;
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

    /// <summary>Duck the loop and play a one-shot sting (victory/defeat).</summary>
    public void PlaySting(AudioClip sting, float duckTo = 0.1f, float duckSeconds = 0.4f)
    {
        if (sting == null) return;
        _stingSource.PlayOneShot(sting);
        StopAllCoroutines();
        StartCoroutine(DuckAndRestore(duckTo, duckSeconds, sting.length));
    }

    private System.Collections.IEnumerator DuckAndRestore(float duckTo, float duckSeconds, float holdSeconds)
    {
        float startVol = _musicSource.volume;
        float t = 0f;
        while (t < duckSeconds) { t += Time.deltaTime; _musicSource.volume = Mathf.Lerp(startVol, duckTo, t / duckSeconds); yield return null; }
        yield return new WaitForSeconds(holdSeconds);
        t = 0f;
        while (t < duckSeconds) { t += Time.deltaTime; _musicSource.volume = Mathf.Lerp(duckTo, _targetMusicVolume, t / duckSeconds); yield return null; }
        _musicSource.volume = _targetMusicVolume;
    }

    private void Update()
    {
        if (_musicSource.isPlaying && _musicSource.volume < _targetMusicVolume && _stingSource != null && !_stingSource.isPlaying)
            _musicSource.volume = Mathf.MoveTowards(_musicSource.volume, _targetMusicVolume, Time.deltaTime / Mathf.Max(0.01f, musicFadeSeconds));
    }

    public void PlaySfx(AudioClip clip, float volume = 1f)
    {
        if (clip != null) _sfxSource.PlayOneShot(clip, volume);
    }

    // UI
    public void PlayButtonClick()    => PlaySfx(sfxButtonClick);
    public void PlayButtonHover()    => PlaySfx(sfxButtonHover, 0.5f);
    public void PlayNotification()   => PlaySfx(sfxNotification);
    public void PlayError()          => PlaySfx(sfxError);
    // Dice & movement
    public void PlayDiceShake()      => PlaySfx(sfxDiceShake);
    public void PlayDiceRoll()       => PlaySfx(sfxDiceRoll);
    public void PlayDiceLand()       => PlaySfx(sfxDiceLand);
    public void PlayStepMove()       => PlaySfx(sfxStepMove, 0.6f);
    public void PlayArrivedOnTile() => PlaySfx(sfxArrivedOnTile);
    // Money & property
    public void PlayPropertyBuy()    => PlaySfx(sfxPropertyBuy);
    public void PlayPropertySell()   => PlaySfx(sfxPropertySell);
    public void PlayRentPay()        => PlaySfx(sfxRentPay);
    public void PlayRentReceive()    => PlaySfx(sfxRentReceive);
    public void PlayCashReward()     => PlaySfx(sfxCashReward);
    public void PlayBankrupt()       => PlaySfx(sfxBankrupt);
    // Special
    public void PlayJailIn()         => PlaySfx(sfxJailIn);
    public void PlayJailEscape()     => PlaySfx(sfxJailEscape);
    public void PlayChanceCard()     => PlaySfx(sfxChanceCard);
    public void PlayMinigameStart()  => PlaySfx(sfxMinigameStart);
    public void PlayTurnStart()      => PlaySfx(sfxTurnStart);
    public void PlayTurnEnd()        => PlaySfx(sfxTurnEnd);
    public void PlayCardPop()        => PlaySfx(sfxCardPop, 0.7f);
    // Stings
    public void PlayVictorySting()   => PlaySting(musicVictorySting);
    public void PlayDefeatSting()    => PlaySting(musicDefeatSting);

    private void OnDestroy() { if (Instance == this) Instance = null; }
}
