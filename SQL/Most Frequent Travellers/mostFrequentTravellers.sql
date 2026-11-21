-- A ride-sharing company wants to identify which users have traveled the most distance overall. This data can be used to reward the most frequent travellers, understand usage patterns, and improve customer retention strategies. You're given two tables:

-- Users:
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║    name     ║ varchar  ║
-- ╚═════════════╩══════════╝
--     1 - user_id: Unique identifier for each user (Primary Key).
--     2 - name: The name of the user, stored as a string.

-- Rides:
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║   user_id   ║   int    ║
-- ║─────────────┼──────────║
-- ║  distance   ║   int    ║
-- ╚═════════════╩══════════╝
--     1 - id: Unique ID for the ride (Primary Key).
--     2 - user_id: Refers to the id of the user who took this ride.
--     3 - distance: Distance traveled during this ride.

-- Write a query to find the total distance traveled by each user. Sort the result by travelled_distance in descending order. If multiple users have the same distance, sort them by name in ascending order.






SELECT 
    u.name,
    COALESCE(SUM(r.distance), 0) AS travelled_distance
FROM Users u
LEFT JOIN Rides r 
    ON u.id = r.user_id
GROUP BY u.id, u.name
ORDER BY travelled_distance DESC, u.name ASC;