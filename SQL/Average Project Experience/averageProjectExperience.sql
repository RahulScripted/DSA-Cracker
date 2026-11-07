-- A company tracks which employees are assigned to which projects and stores details about each employee, including their years of experience. The project managers want to analyze the average experience level of the employees assigned to each project to ensure a healthy skill mix. There are two tables:

-- Project
-- ╔═════════════╦══════════════╗
-- ║ Column Name ║ Type         ║
-- ╠═════════════╬══════════════╣
-- ║ project_id  ║ int          ║
-- ║ employee_id ║ int          ║
-- ╚═════════════╩══════════════╝

--     1 - project_id: The ID of the project.
--     2 - employee_id: The ID of the employee working on the project.

-- Employee
-- ╔══════════════════╦══════════════╗
-- ║ Column Name      ║ Type         ║
-- ╠══════════════════╬══════════════╣
-- ║ employee_id      ║ int          ║
-- ║ name             ║ varchar      ║
-- ║ experience_years ║ int          ║
-- ╚══════════════════╩══════════════╝

--     1 - employee_id: A unique ID (primary key) for each employee.
--     2 - name: The employee’s name.
--     3 - experience_years: Number of years the employee has worked (never NULL).

-- Write an SQL query to report the project_id and the average number of experience years (average_years) of all employees working on that project. Round the result to 2 decimal places.






SELECT p.project_id, ROUND(AVG(e.experience_years), 2) AS average_years
FROM Project p
JOIN Employee e ON p.employee_id = e.employee_id
GROUP BY p.project_id
ORDER BY p.project_id ASC;
