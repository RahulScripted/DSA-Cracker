-- In a company, the executives are interested in knowing the top three highest earners in each department. This information helps in understanding the top performers in each department based on salary. Given two tables:

-- Employee
-- ╔══════════════╦══════════╗
-- ║ Column Name  ║   Type   ║
-- ╠══════════════╬══════════╣
-- ║      id      ║   int    ║
-- ║──────────────┼──────────║
-- ║     name     ║  archer  ║
-- ║──────────────┼──────────║
-- ║    salary    ║   int    ║
-- ║──────────────┼──────────║
-- ║ departmentid ║   int    ║
-- ╚══════════════╩══════════╝

--     1 - Contains employee information such as id, name, salary, and departmentid.
--     2 - id is the primary key and departmentid is a foreign key.

-- Department 
-- ╔═════════════╦══════════╗
-- ║ Column name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║    name     ║  varchar ║
-- ╚═════════════╩══════════╝
--     1 - Contains department information such as id and name. Here, id is the primary key of department table.

-- Write an SQL query to find the employees earning the top three unique salaries in each department. The result should be ordered by name in ascending order, salary in descending order, and employee in ascending order.







WITH RankedSalaries AS (
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary AS salary,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) as salary_rank
    FROM Employee e
    JOIN Department d ON e.departmentId = d.id
)
SELECT Department, Employee, salary
FROM RankedSalaries
WHERE salary_rank <= 3
ORDER BY 
    Department ASC, 
    salary DESC, 
    Employee ASC;
