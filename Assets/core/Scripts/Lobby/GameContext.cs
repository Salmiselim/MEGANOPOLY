using Unity.Services.Relay.Models;

/// <summary>
/// Cross-scene memory that carries the board session's relay info from the
/// Lobby scene into the SampleScene. Populated by LobbyRelayManager just
/// before the scene transition, consumed by BoardSessionStarter on the
/// other side.
///
/// All fields are static — they survive scene loads because static state is
/// part of the assembly, not any GameObject.
/// </summary>
public static class GameContext
{
    /// <summary>True if this client should host the new board NGO session.</summary>
    public static bool IsHost;

    /// <summary>Relay join code shared with every peer for the board session.</summary>
    public static string JoinCode;

    /// <summary>
    /// Host's pre-created Relay allocation. Only set on the host. Avoids the
    /// host having to allocate again in SampleScene (saves a round trip and
    /// keeps the join code stable across the transition).
    /// </summary>
    public static Allocation HostAllocation;

    /// <summary>
    /// Number of players that were ready in the lobby when Start was pressed.
    /// CompleteGameManager waits until this many clients are connected on the
    /// fresh board NGO session before spawning avatars, so no player is left
    /// without an avatar due to relay-join timing.
    /// </summary>
    public static int ExpectedPlayerCount;

    /// <summary>Reset state — call after the board session finishes.</summary>
    public static void Clear()
    {
        IsHost = false;
        JoinCode = null;
        HostAllocation = null;
        ExpectedPlayerCount = 0;
    }
}
