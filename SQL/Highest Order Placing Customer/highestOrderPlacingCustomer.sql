-- As a business, you want to identify which customer places the most orders. This is useful for targeting high-value customers with loyalty programs or marketing campaigns. You are given a table named Orders that tracks customer orders.

-- ╔═════════════════╦══════════╗
-- ║   Column Name   ║   Type   ║
-- ╠═════════════════╬══════════╣
-- ║   order_number  ║   int    ║
-- ║─────────────────┼──────────║
-- ║ customer_number ║   int    ║
-- ╚═════════════════╩══════════╝
-- order_number: Unique order ID (Primary Key) for each order placed.
-- customer_number: ID of the customer who placed the order.

-- Write a query to find the customer_number of the customer who has placed the most orders. It is guaranteed that exactly one customer will have placed more orders than any other.









SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(order_number) DESC
LIMIT 1;