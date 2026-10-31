-- In any gaming platform, it's important to know when each player first started using the platform. This helps in tracking user lifecycle, cohort analysis, and retention strategies. You are given a table named Activity:

-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║  player_id  ║   int    ║
-- ║─────────────┼──────────║
-- ║  device_id  ║   int    ║
-- ║─────────────┼──────────║
-- ║ event_date  ║   date   ║
-- ║─────────────┼──────────║
-- ║games_played ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - player_id: the unique ID of the player
--     2 - device_id: the device used to play
--     3 - event_date: the date of the login
--     4 - games_played: how many games the player played on that day.

-- The primary key is (player_id, event_date). A player can appear only once per day in this table. A player may use multiple devices, but per day only one row is recorded. Write a query to get the earliest (first) login date for each player. Return the result ordered by player_id.







SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id
ORDER BY player_id;
