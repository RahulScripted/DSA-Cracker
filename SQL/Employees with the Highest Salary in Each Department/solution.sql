-- We have two tables: Employee and Department.

-- Table: Employee
-- ╔══════════════╦═════════╗
-- ║ Column Name  ║  Type   ║
-- ╠══════════════╬═════════╣
-- ║      id      ║   int   ║
-- ║──────────────┼─────────║
-- ║     name     ║ varchar ║
-- ║──────────────┼─────────║
-- ║    salary    ║   int   ║
-- ║──────────────┼─────────║
-- ║ departmentId ║   int   ║
-- ╚══════════════╩═════════╝

--     1 - id is the primary key for the Employee table.
--     2 - departmentId is a foreign key that references the id of the Department table.
    
-- Table: Department
-- ╔═════════════╦═════════╗
-- ║ Column Name ║  Type   ║
-- ╠═════════════╬═════════╣
-- ║     id      ║   int   ║
-- ║─────────────┼─────────║
-- ║    name     ║ varchar ║
-- ╚═════════════╩═════════╝
--     1 - id is the primary key for the Department table. It is guaranteed that the department name is not NULL.
--     2 - Each row in this table contains the id and name of a department.

-- Your task is to find the employees who have the highest salary in each department. The result should be ordered by salary in descending order. If two or more employees have the same salary, order them by employee name in ascending order.







SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
FROM Employee e
JOIN Department d ON e.departmentId = d.id
WHERE e.salary = (
    SELECT MAX(e2.salary)
    FROM Employee e2
    WHERE e2.departmentId = e.departmentId
)
ORDER BY Salary DESC, Employee ASC;