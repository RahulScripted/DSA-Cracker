-- A company’s HR system keeps track of employees and their reporting structure. The management wants to identify managers who have at least 5 employees directly reporting to them. The company maintains an Employee table that stores:

-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║    name     ║ varchar  ║
-- ║─────────────┼──────────║
-- ║ department  ║ varchar  ║
-- ║─────────────┼──────────║
-- ║  managerld  ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - id: A unique identifier (primary key) for each employee.
--     2 - name: The name of the employee.
--     3 - department: The department in which the employee works.
--     4 - managerId: The id of the employee’s direct manager (NULL if the employee has no manager).

-- Your task is to find all managers who have 5 or more employees directly reporting to them. The result should be returned in any order.







SELECT name
FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(id) >= 5
);
