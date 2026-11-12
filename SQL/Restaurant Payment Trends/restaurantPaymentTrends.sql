-- As the owner of a restaurant, you're interested in tracking how much your customers are spending on average over the past 7 days. This moving average will help you analyze customer behavior and plan for possible restaurant expansion. You are given a Customer table with:

-- ╔═════════════╦═════════╗
-- ║ Column Name ║  Type   ║
-- ╠═════════════╬═════════╣
-- ║ customer_id ║   int   ║
-- ║─────────────┼─────────║
-- ║    name     ║ varchar ║
-- ║─────────────┼─────────║
-- ║ visited_on  ║  date   ║
-- ║─────────────┼─────────║
-- ║   amount    ║   int   ║
-- ╚═════════════╩═════════╝

--     1 - customer_id: Unique ID & primary key of the customer.
--     2 - name: Name of the customer.
--     3 - visited_on: The date the customer visited the restaurant & primary key.
--     4 - amount: The amount spent by the customer on that day.

-- You need to calculate the moving average for each customer's spending, considering the total amount paid in the last 7 days, including the current day. The moving average should be rounded to two decimal places.







SELECT 
    a.visited_on,
    (
        SELECT SUM(b.amount)
        FROM Customer b
        WHERE b.visited_on BETWEEN DATE_SUB(a.visited_on, INTERVAL 6 DAY) AND a.visited_on
    ) AS amount,
    ROUND((
        SELECT SUM(b.amount) / 7
        FROM Customer b
        WHERE b.visited_on BETWEEN DATE_SUB(a.visited_on, INTERVAL 6 DAY) AND a.visited_on
    ), 2) AS average_amount
FROM (SELECT DISTINCT visited_on FROM Customer) a
WHERE a.visited_on >= (
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY) 
    FROM Customer
)
ORDER BY a.visited_on;