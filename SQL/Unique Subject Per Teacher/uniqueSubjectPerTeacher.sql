-- At a university, teachers may teach the same subject in multiple departments, but for reporting purposes, the administration wants to know how many distinct subjects each teacher is responsible for, regardless of department. You are given a Teacher table with the following columns:

-- ╔═════════════╦══════════╗
-- ║ Column name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║ teacher_id  ║   int    ║
-- ║─────────────┼──────────║
-- ║ subject_id  ║   int    ║
-- ║─────────────┼──────────║
-- ║   dept_id   ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - teacher_id: The ID of the teacher.
--     2 - subject_id: The ID of the subject being taught.
--     3 - dept_id: The department in which the subject is being taught.

-- (subject_id, dept_id) is the primary key of this table. Each row shows that a teacher teaches a specific subject in a department. Write an SQL query to return the number of unique subjects taught by each teacher. The result can be returned in any order.









SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id;