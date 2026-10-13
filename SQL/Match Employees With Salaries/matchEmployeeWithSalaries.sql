-- A company stores employee details and salary information in two separate tables. Only employees who have a corresponding salary record should appear in the final report.

-- Table: Employees
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║ employee_id ║   int    ║
-- ║─────────────┼──────────║
-- ║    name     ║ varchar  ║
-- ╚═════════════╩══════════╝
-- employee_id is the primary key.
-- Each row represents one employee.

-- Table: Salaries
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║ employee_id ║   int    ║
-- ║─────────────┼──────────║
-- ║   salary    ║   int    ║
-- ╚═════════════╩══════════╝
-- employee_id is the primary key.
-- Each row represents a salary record.

-- Write an SQL query using ONLY IMPLICIT JOIN syntax to return employees who have salary records.
-- Return:

--     employee_id
--     name
--     salary
-- The result can be returned in any order.








SELECT E.employee_id, E.name, S.salary
FROM Employees E, Salaries S
WHERE E.employee_id = S.employee_id;