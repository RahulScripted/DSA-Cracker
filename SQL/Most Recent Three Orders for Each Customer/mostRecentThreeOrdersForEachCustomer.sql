-- We have two tables: Customers and Orders.

-- Table: Customers
-- ╔═════════════╦═════════╗
-- ║ Column Name ║  Type   ║
-- ╠═════════════╬═════════╣
-- ║ customer_id ║   int   ║
-- ║─────────────┼─────────║
-- ║    name     ║ varchar ║
-- ╚═════════════╩═════════╝
--     1 - customer_id is the primary key for this table. It contains information about the customers.

-- Table: Orders
-- ╔═════════════╦════════╗
-- ║ Column Name ║  Type  ║
-- ╠═════════════╬════════╣
-- ║  order_id   ║  int   ║
-- ║─────────────┼────────║
-- ║ order_date  ║  date  ║
-- ║─────────────┼────────║
-- ║ customer_id ║  int   ║
-- ║─────────────┼────────║
-- ║    cost     ║  int   ║
-- ╚═════════════╩════════╝

--     1 - order_id is the primary key for this table. It contains the orders made by customers.
--     2 - customer_id references the customer who placed the order.
--     3 - Each customer has only one order per day.

-- Write a solution to find the most recent three orders for each customer. If a customer has less than three orders, return all of their orders. Return the result table ordered by customer_name in ascending order. In case of a tie, order by customer_id in ascending order. If there is still a tie, order them by order_date in descending order.







WITH RankedOrders AS (
    SELECT 
        c.name AS customer_name,
        c.customer_id,
        o.order_id,
        o.order_date,
        ROW_NUMBER() OVER (
            PARTITION BY c.customer_id 
            ORDER BY o.order_date DESC
        ) AS rnk
    FROM Customers c
    JOIN Orders o 
        ON c.customer_id = o.customer_id
)
SELECT 
    customer_name,
    customer_id,
    order_id,
    order_date
FROM RankedOrders
WHERE rnk <= 3
ORDER BY 
    customer_name ASC, 
    customer_id ASC, 
    order_date DESC;