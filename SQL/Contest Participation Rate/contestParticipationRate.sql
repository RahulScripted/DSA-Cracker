-- An online contest platform tracks user registrations for various contests. The analytics team wants to determine how popular each contest is by calculating what percentage of total users participated in each one. Two tables are provided:

-- Users:
-- ╔══════════╦════════════╗
-- ║ Column   ║ Type       ║
-- ╠══════════╬════════════╣
-- ║ user_id  ║ int        ║
-- ║ user_name║ varchar    ║
-- ╚══════════╩════════════╝
--     1 - user_id: Unique identifier for each user.
--     2 - user_name: Name of the user.

-- Register:
-- ╔════════════╦══════════╗
-- ║ Column     ║ Type     ║
-- ╠════════════╬══════════╣
-- ║ contest_id ║ int      ║
-- ║ user_id    ║ int      ║
-- ╚════════════╩══════════╝
--     1 - contest_id: Unique identifier for each contest.
--     2 - user_id: ID of the user who registered for the contest.
--     3 - (contest_id, user_id) is the primary key (combination of columns with unique values).

-- Write an SQL query to report the contest_id and the percentage of users registered for each contest, rounded to 2 decimal places. Sort the result by percentage in descending order, and in case of a tie, by contest_id in ascending order.








SELECT 
    contest_id,
    ROUND(COUNT(user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM 
    Register
GROUP BY 
    contest_id
ORDER BY 
    percentage DESC, 
    contest_id ASC;