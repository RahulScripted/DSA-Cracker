-- We have two tables: Tasks and Executed.

-- Table: Tasks
-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | task_id        | int     |
-- | subtasks_count | int     |
-- +----------------+---------+
--     1 - task_id is the primary key for this table and contains unique values.
--     2 - subtasks_count is the number of subtasks assigned to each task, with values ranging from 2 to 20.

-- Table: Executed
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | task_id       | int     |
-- | subtask_id    | int     |
-- +---------------+---------+
--     1 - (task_id, subtask_id) is the combination of columns with unique values in this table.
--     2 - Each row in this table represents an executed subtask for a given task.

-- Write a query to find the missing subtasks for each task in the Tasks table. A missing subtask is a subtask that has not been executed for the task. Return the task_id and subtask_id for each missing subtask.








WITH RECURSIVE AllSubtasks AS (
    SELECT 
        task_id, 
        1 AS subtask_id, 
        subtasks_count
    FROM Tasks
    
    UNION ALL
    SELECT 
        task_id, 
        subtask_id + 1, 
        subtasks_count
    FROM AllSubtasks
    WHERE subtask_id < subtasks_count
)
SELECT 
    a.task_id, 
    a.subtask_id
FROM AllSubtasks a
LEFT JOIN Executed e 
    ON a.task_id = e.task_id 
    AND a.subtask_id = e.subtask_id
WHERE e.subtask_id IS NULL
ORDER BY a.task_id, a.subtask_id;