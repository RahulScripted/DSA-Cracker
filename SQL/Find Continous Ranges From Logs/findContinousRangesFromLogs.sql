-- We have a table named Logs that contains log IDs.

-- Table: Logs
-- ╔═══════════════╦═════════╗
-- ║ Column Name   ║  Type   ║
-- ╠═══════════════╬═════════╣
-- ║    log_id     ║   int   ║
-- ╚═══════════════╩═════════╝

--     1 - log_id is the primary key and contains unique values for this table.
--     2 - Each row in this table represents a log with a unique log_id.

-- Write a query to find the start and end number of continuous ranges in the Logs table. Return the result table ordered by start_id.







WITH GroupedLogs AS (
    SELECT 
        log_id,
        log_id - ROW_NUMBER() OVER (ORDER BY log_id) AS group_id
    FROM Logs
)
SELECT 
    MIN(log_id) AS start_id,
    MAX(log_id) AS end_id
FROM GroupedLogs
GROUP BY group_id
ORDER BY start_id;