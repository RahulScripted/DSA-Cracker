-- A company wants to identify employees whose salary is higher than their direct manager’s salary to review compensation structure.

-- Table: Employees
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║ employee_id ║   int    ║
-- ║─────────────┼──────────║
-- ║    name     ║ varchar  ║
-- ║─────────────┼──────────║
-- ║   salary    ║   int    ║
-- ║─────────────┼──────────║
-- ║ manager_id  ║   int    ║
-- ╚═════════════╩══════════╝

-- 1 - employee_id is the primary key.
-- 2 - manager_id refers to another employee.
-- 3 - The top manager has manager_id = NULL.

-- Write an SQL query to return the names of employees whose salary is strictly greater than their manager’s salary. Return the result in any order.







SELECT e1.name
FROM Employees e1, Employees e2
WHERE e1.manager_id = e2.employee_id AND e1.salary > e2.salary;