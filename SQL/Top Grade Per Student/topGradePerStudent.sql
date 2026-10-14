-- You are analyzing student performance data and want to identify, for each student highest grade they received, the course in which they received it, which can be useful for reporting academic strengths or awarding student honors. You are given a table Enrollments with:

-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║ student_id  ║   int    ║
-- ║─────────────┼──────────║
-- ║  course_id  ║   int    ║
-- ║─────────────┼──────────║
-- ║    grade    ║   int    ║
-- ╚═════════════╩══════════╝

-- 1 - student_id: The ID of the student.
-- 2 - course_id: The ID of the course the student is enrolled in.
-- 3 - grade: The grade received in that course.

-- Write a query to retrieve each student's highest grade along with the corresponding course. If there is a tie in grades, select the course with the smallest course_id. The final result should be sorted in ascending order by student_id.









SELECT e.student_id, e.course_id, e.grade
FROM Enrollments e
WHERE (e.grade, e.course_id) = (
    SELECT grade, course_id
    FROM Enrollments
    WHERE student_id = e.student_id
    ORDER BY grade DESC, course_id ASC
    LIMIT 1
)
ORDER BY e.student_id;
