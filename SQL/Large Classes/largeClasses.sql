-- A school wants to identify popular classes that have at least 5 students enrolled. This helps the administration in allocating resources, such as assigning larger classrooms or more teaching assistants. You are given a Courses table with two columns:

-- ╔═════════════╦══════════╗
-- ║ Column name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║   student   ║ varchar  ║
-- ║─────────────┼──────────║
-- ║    class    ║ varchar  ║
-- ╚═════════════╩══════════╝

--     1 - student: The name of a student.
--     2 - class: The name of the class the student is enrolled in.
--     3 - Each (student, class) pair is unique.

-- Write an SQL query to find the names of classes where the number of enrolled students is at least 5. Return the result ordered by class in ascending order.









SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5
ORDER BY class ASC;