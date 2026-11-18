-- In a football tournament, you want to compute total points earned by each team based on match outcomes. This scoring will determine rankings on the leaderboard. You're given two tables:

-- Teams
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║   team_id   ║   int    ║
-- ║─────────────┼──────────║
-- ║  team_name  ║ varchar  ║
-- ╚═════════════╩══════════╝
--     1 - team_id: Unique identifier for each team (Primary Key)
--     2 - team_name: Name of the football team

-- Matches
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║   match_id  ║   int    ║
-- ║─────────────┼──────────║
-- ║  host_team  ║   int    ║
-- ║─────────────┼──────────║
-- ║ guest_team  ║   int    ║
-- ║─────────────┼──────────║
-- ║ host_goals  ║   int    ║
-- ║─────────────┼──────────║
-- ║guest_goals  ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - match_id: Unique ID for the match (Primary Key)
--     2 - host_team: ID of the team that hosted the match (foreign key to Teams.team_id)
--     3 - guest_team: ID of the team that played as a guest (foreign key to Teams.team_id)
--     4 - host_goals: Number of goals scored by the host team
--     5 - guest_goals: Number of goals scored by the guest team

-- Write a query to calculate the total points of each team after all matches.

--     1 - A team gets 3 points for a win,
--     2 - 1 point for a draw, and
--     3 - 0 points for a loss.

-- Return the team_id, team_name, and num_points for each team, ordered by num_points in descending order. If two teams have the same points, order them by team_id in ascending order.








SELECT 
    t.team_id,
    t.team_name,
    COALESCE(SUM(
        CASE 
            WHEN t.team_id = m.host_team AND m.host_goals > m.guest_goals THEN 3
            WHEN t.team_id = m.guest_team AND m.guest_goals > m.host_goals THEN 3
            WHEN m.host_goals = m.guest_goals THEN 1
            ELSE 0
        END
    ), 0) AS num_points
FROM Teams t
LEFT JOIN Matches m 
    ON t.team_id = m.host_team OR t.team_id = m.guest_team
GROUP BY t.team_id, t.team_name
ORDER BY num_points DESC, t.team_id ASC;