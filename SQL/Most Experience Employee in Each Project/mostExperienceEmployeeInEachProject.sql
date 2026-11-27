-- We have two tables: Project and Employee.

-- Table: Project
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | project_id  | int     |
-- | employee_id | int     |
-- +-------------+---------+

--     1 - (project_id, employee_id) is the primary key for this table.
--     2 - employee_id is a foreign key that references the Employee table.
--     3 - Each row of this table indicates that the employee with employee_id is working on the project with project_id.

-- Table: Employee
-- +------------------+---------+
-- | Column Name      | Type    |
-- +------------------+---------+
-- | employee_id      | int     |
-- | name             | varchar |
-- | experience_years | int     |
-- +------------------+---------+
--     1 - employee_id is the primary key for this table.
--     2 - Each row of this table contains information about one employee, including their employee_id, name, and the experience_years they have.

-- Write a query to find the most experienced employees for each project. In case of a tie, report all employees with the maximum number of experience years for that project. Return the result ordered by project_id in ascending order. If multiple employees are returned for the same project, order them by employee_id in ascending order.







WITH RankedEmployees AS (
    SELECT 
        p.project_id,
        p.employee_id,
        RANK() OVER (
            PARTITION BY p.project_id 
            ORDER BY e.experience_years DESC
        ) AS exp_rank
    FROM Project p
    JOIN Employee e 
        ON p.employee_id = e.employee_id
)
SELECT 
    project_id, 
    employee_id
FROM RankedEmployees
WHERE exp_rank = 1
ORDER BY 
    project_id ASC, 
    employee_id ASC;