-- A company maintains an employee database where each employee may receive a performance bonus. The company wants to identify employees whose bonus is less than a particular amount or those who have not received any bonus at all. Your task is to fetch the employee names and their respective bonuses from the system. The company maintains two tables: Write an SQL query to retrieve the name of each employee along with their bonus amount. If an employee has not received a bonus, display NULL for the bonus. Only include employees whose bonus is less than 1000 or who have not received any bonus. The result should be returned in any order.






SELECT e.name, b.bonus
FROM Employee e
LEFT JOIN Bonus b ON e.empId = b.empId
WHERE b.bonus < 1000 OR b.bonus IS NULL;