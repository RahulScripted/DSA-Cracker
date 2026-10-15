-- A weather monitoring system tracks daily temperatures in a database. The meteorological team wants to identify days when the temperature was higher than the specific day. Your task is to find all dates where the temperature was higher than the day before. The company maintains a table named Weather with the following schema:

-- Table: Weather
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║ recordDate  ║   date   ║
-- ║─────────────┼──────────║
-- ║ temperature ║   int    ║
-- ╚═════════════╩══════════╝
-- id: A unique identifier (primary key) for each record.
-- recordDate: The date when the temperature was recorded.
-- temperature: The temperature recorded on that date.


-- You need to find the id of all dates where the temperature was higher than the previous day's temperature. The result can be returned in any order.







SELECT w1.id
FROM Weather w1
JOIN Weather w2 
ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE w1.temperature > w2.temperature;