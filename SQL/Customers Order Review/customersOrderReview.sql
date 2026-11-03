-- An e-commerce platform stores information about its customers and their purchase history. Some customers may have registered on the platform but have not placed any orders yet. You are given two tables:

-- Customers
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║ customer_id ║   int    ║
-- ║─────────────┼──────────║
-- ║    name     ║ varchar  ║
-- ╚═════════════╩══════════╝

--     1 - customer_id is the primary key. Each row represents a registered customer.

-- Orders
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║  order_id   ║   int    ║
-- ║─────────────┼──────────║
-- ║ customer_id ║   int    ║
-- ║─────────────┼──────────║
-- ║   amount    ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - order_id is the primary key.
--     2 - customer_id references Customers.customer_id.

-- Write an SQL query to return all customers, along with their order details. If a customer has not placed any orders, display NULL for order-related columns.







SELECT c.customer_id, c.name, o.order_id, o.amount
FROM Customers c
LEFT JOIN Orders o ON c.customer_id = o.customer_id;