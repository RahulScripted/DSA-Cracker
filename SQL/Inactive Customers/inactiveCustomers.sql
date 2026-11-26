-- You are managing an e-commerce platform and want to identify customers who have never placed an order. This can help your marketing or sales team target those users with special promotions or reminders. You are given two tables:

-- Customers:
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║    name     ║  vachar  ║
-- ╚═════════════╩══════════╝

--     1 - id: Unique id of the customer.
--     2 - name: name of each customer.

-- Orders:
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║ customerid  ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - id: Unique id of the order
--     2 - customerId: customerId is a foreign key, which is taking reference from Customer table

-- Write an SQL query to return the names of all customers who do not appear in the Orders table. The result should be ordered by customer name in ascending order.







SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customerId
WHERE o.id IS NULL
ORDER BY c.name ASC;