-- A company wants to identify customers who have purchased all available products in their catalog. This helps the company target promotions and understand customer engagement. You are given two tables:

-- Customer Table
-- ╔═════════════╦══════════╗
-- ║ Column name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║ customer_id ║   int    ║
-- ║─────────────┼──────────║
-- ║ product_key ║   int    ║
-- ╚═════════════╩══════════╝

-- Product Table
-- ╔═════════════╦══════════╗
-- ║ Column name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║ product_key ║   int    ║
-- ╚═════════════╩══════════╝

-- customer_id: Unique ID of the customer. product_key: The ID of the product purchased by the customer or listed in the catalog.

-- Write an SQL query to find the customer_ids of customers who have bought all products from the Product table. The result should be returned in ascending order of customer_id.







SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product)
ORDER BY customer_id ASC;