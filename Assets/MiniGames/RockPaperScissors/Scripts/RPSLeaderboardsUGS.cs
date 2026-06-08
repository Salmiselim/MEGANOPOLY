using System;
using System.Text;
using System.Threading.Tasks;
using TMPro;
using Unity.Services.Authentication;
using Unity.Services.Core;
using Unity.Services.Leaderboards;
using Unity.Services.Leaderboards.Models;
using UnityEngine;

namespace RockPaperScissors
{
    public class RPSLeaderboardsUGS : MonoBehaviour
    {
        [Header("Leaderboard")]
        [Tooltip("Leaderboard ID created in the Unity Dashboard (UGS Leaderboards).")]
        [SerializeField] private string leaderboardId = "rps_match_wins";

        [Tooltip("How many top entries to show.")]
        [SerializeField] private int topLimit = 10;

        [Header("References")]
        [Tooltip("Match manager that runs the 3 rounds.")]
        [SerializeField] private MultiplayerRPSGameManager rpsGameManager;

        [Tooltip("Where to print leaderboard/status output. If empty, logs only.")]
        [SerializeField] private TextMeshProUGUI outputText;

        [Header("Behavior")]
        [Tooltip("If true, submits your score automatically when the 3-round match ends.")]
        [SerializeField] private bool autoSubmitOnMatchEnd = true;

        private bool _ugsReady;
        private bool _submittedThisMatch;

        private async void Start()
        {
            await EnsureUGSAsync();

            if (_ugsReady)
                await RefreshTopAsync();
        }

        private async void Update()
        {
            if (!autoSubmitOnMatchEnd) return;
            if (!_ugsReady) return;
            if (_submittedThisMatch) return;
            if (rpsGameManager == null) return;

            if (rpsGameManager.IsMatchOver)
            {
                _submittedThisMatch = true;
                await SubmitMyMatchWinsAsync();
                await RefreshTopAsync();
            }
        }

        public async void SubmitMyMatchWins()
        {
            await EnsureUGSAsync();
            if (!_ugsReady) return;
            await SubmitMyMatchWinsAsync();
        }

        public async void RefreshTop()
        {
            await EnsureUGSAsync();
            if (!_ugsReady) return;
            await RefreshTopAsync();
        }

        private async Task EnsureUGSAsync()
        {
            if (_ugsReady) return;

            try
            {
                if (UnityServices.State == ServicesInitializationState.Uninitialized)
                    await UnityServices.InitializeAsync();

                if (!AuthenticationService.Instance.IsSignedIn)
                    await AuthenticationService.Instance.SignInAnonymouslyAsync();

                _ugsReady = true;
                WriteLine($"UGS ready. PlayerId: {ShortId(AuthenticationService.Instance.PlayerId)}");
            }
            catch (Exception e)
            {
                _ugsReady = false;
                WriteLine($"UGS init failed: {e.Message}");
                Debug.LogError($"[RPS Leaderboards] UGS init failed: {e}");
            }
        }

        private async Task SubmitMyMatchWinsAsync()
        {
            if (rpsGameManager == null)
            {
                WriteLine("No MultiplayerRPSGameManager reference set.");
                return;
            }

            int score = Mathf.Clamp(rpsGameManager.LocalMatchWins, 0, rpsGameManager.TotalRounds);
            WriteLine($"Submitting score {score} to '{leaderboardId}'...");

            try
            {
                await LeaderboardsService.Instance.AddPlayerScoreAsync(leaderboardId, score);
                WriteLine("Score submitted.");
            }
            catch (Exception e)
            {
                WriteLine($"Submit failed: {e.Message}");
                Debug.LogError($"[RPS Leaderboards] Submit failed: {e}");
            }
        }

        private async Task RefreshTopAsync()
        {
            try
            {
                var scores = await LeaderboardsService.Instance.GetScoresAsync(
                    leaderboardId,
                    new GetScoresOptions { Limit = topLimit, Offset = 0 }
                );

                RenderLeaderboard(scores);
            }
            catch (Exception e)
            {
                WriteLine($"Refresh failed: {e.Message}");
                Debug.LogError($"[RPS Leaderboards] Refresh failed: {e}");
            }
        }

        private void RenderLeaderboard(LeaderboardScoresPage page)
        {
            var sb = new StringBuilder();
            sb.AppendLine("Leaderboard:");
            sb.AppendLine($"{leaderboardId} (Top {topLimit})");

            if (page == null || page.Results == null || page.Results.Count == 0)
            {
                sb.AppendLine("(no scores yet)");
                WriteBlock(sb.ToString());
                return;
            }

            for (int i = 0; i < page.Results.Count; i++)
            {
                var e = page.Results[i];
                // Rank is 1-based in the service response.
                // (Type differs by SDK version; in this project it's an int.)
                var rank = e.Rank > 0 ? e.Rank.ToString() : (i + 1).ToString();
                var pid = ShortId(e.PlayerId);
                sb.AppendLine($"#{rank}  {pid}  -  {e.Score}");
            }

            WriteBlock(sb.ToString());
        }

        private void WriteLine(string msg)
        {
            Debug.Log($"[RPS Leaderboards] {msg}");
            if (outputText == null) return;

            if (string.IsNullOrWhiteSpace(outputText.text))
                outputText.text = msg;
            else
                outputText.text += "\n" + msg;
        }

        private void WriteBlock(string block)
        {
            Debug.Log($"[RPS Leaderboards]\n{block}");
            if (outputText != null)
                outputText.text = block;
        }

        private static string ShortId(string playerId)
        {
            if (string.IsNullOrEmpty(playerId)) return "unknown";
            return playerId.Length <= 6 ? playerId : playerId.Substring(0, 6);
        }
    }
}

