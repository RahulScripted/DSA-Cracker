-- ou run a web store and want to identify sellers who were inactive in 2020. These sellers had no sales during the year, and may need to be contacted for re-engagement or deactivation. You are given the following tables:

-- Customer:
-- ╔═══════════════╦══════════╗
-- ║  Column Name  ║   Type   ║
-- ╠═══════════════╬══════════╣
-- ║  cutomer_id   ║   int    ║
-- ║───────────────┼──────────║
-- ║ customer_name ║ varchar  ║
-- ╚═══════════════╩══════════╝
--     1 - customer_id: A unique number assigned to each customer. It's the primary key, meaning it uniquely identifies every row. 
--     2 - customer_name: The name of the customer, stored as text.

-- Orders:
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║  order_id   ║   int    ║
-- ║─────────────┼──────────║
-- ║  sale_date  ║   date   ║
-- ║─────────────┼──────────║
-- ║ order_cost  ║   int    ║
-- ║─────────────┼──────────║
-- ║ customer_id ║   int    ║
-- ║─────────────┼──────────║
-- ║  seller_id  ║   int    ║
-- ╚═════════════╩══════════╝
--     1 - order_id: Unique ID for each order. This is the primary key.
--     2 - sale_date: The date when the order was placed
--     3 - order_cost: The total cost of the order, stored as an integer
--     4 - customer_id: The ID of the customer who made the purchase. Refers to the customer_id in the Customer table.
--     5 - seller_id: The ID of the seller who sold the product. It links to a Seller table.

-- Seller:
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║  seller_id  ║   int    ║
-- ║─────────────┼──────────║
-- ║ seller_name ║ varchar  ║
-- ╚═════════════╩══════════╝
--     1 - seller_id: A unique identifier for each seller. It’s the primary key of this table.
--     2 - seller_name: The name of the seller, stored as text.

-- Write a query to get the names of all sellers who made no sales during the year 2020. The result should be sorted by seller_name in ascending order.







SELECT s.seller_name
FROM Seller s
LEFT JOIN Orders o 
    ON s.seller_id = o.seller_id 
    AND YEAR(o.sale_date) = 2020
WHERE o.order_id IS NULL
ORDER BY s.seller_name ASC;