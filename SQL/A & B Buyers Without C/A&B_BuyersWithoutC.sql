-- Your company wants to promote product C to customers who have already shown interest in related products A and B, but have not purchased C yet. These customers are potential buyers for C, and you'd like to target them for marketing campaigns.

-- You are given two tables:

-- Customers:
-- ╔═══════════════╦══════════╗
-- ║  Column Name  ║   Type   ║
-- ╠═══════════════╬══════════╣
-- ║  customer_id  ║   int    ║
-- ║───────────────┼──────────║
-- ║ customer_name ║ varchar  ║
-- ╚═══════════════╩══════════╝
--     1 - customer_id is primary key above table(Customers).
--     2 -customer_name is the name of the customer.

-- Orders:
-- ╔══════════════╦══════════╗
-- ║ Column Name  ║   Type   ║
-- ╠══════════════╬══════════╣
-- ║   order_id   ║   int    ║
-- ║──────────────┼──────────║
-- ║ customer_id  ║   int    ║
-- ║──────────────┼──────────║
-- ║ product_name ║ varchar  ║
-- ╚══════════════╩══════════╝

--     1 - order_id is primary key above table(Orders)
--     2 - customer_id is a foreign key that references the Customers table.
--     3 - product_name is the name of the product.

-- Write an SQL query to return the customer_id and customer_name of customers who have:
--     1 - Purchased both 'A' and 'B',
--     2 - Not purchased 'C'.
-- Return the result ordered by customer_id.






SELECT 
    c.customer_id, 
    c.customer_name
FROM Customers c
JOIN Orders o
    ON c.customer_id = o.customer_id
GROUP BY 
    c.customer_id, 
    c.customer_name
HAVING 
    SUM(CASE WHEN o.product_name = 'A' THEN 1 ELSE 0 END) > 0
    AND SUM(CASE WHEN o.product_name = 'B' THEN 1 ELSE 0 END) > 0
    AND SUM(CASE WHEN o.product_name = 'C' THEN 1 ELSE 0 END) = 0
ORDER BY c.customer_id;