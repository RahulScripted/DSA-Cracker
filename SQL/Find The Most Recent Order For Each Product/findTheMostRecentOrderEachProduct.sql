-- We have three tables: Customers, Orders, and Products.

-- Table: Customers
-- +-------------+-----------+
-- | Column Name | Type      |
-- +-------------+-----------+
-- | customer_id | int       |
-- | name        | varchar   |
-- +-------------+-----------+
-- customer_id is the primary key for this table and contains information about each customer.

-- Table: Orders
-- +-------------+------------+
-- | Column      | Type       | 
-- +-------------+------------+
-- | order_id    | int        |
-- | order_date  | date       |
-- | customer_id | int        |
-- | product_id  | int        |
-- +-------------+------------+
--     1 -  order_id is the primary key for this table.
--     2 - customer_id references the customer who placed the order.
--     3 - product_id references the product that was ordered.

-- Table: Products
-- +--------------+--------------+
-- | Column       | Type         |
-- +--------------+--------------+
-- | product_id   | int          |
-- | product_name | varchar      |
-- | price        | int          |
-- +--------------+--------------+
--     1 - product_id is the primary key for this table.
--     2 - product_name refers to the name of the product.
--     3 - price refers to the price of the product.


-- Write a query to find the most recent order(s) for each product. Order the results by product_name, then product_id, and then order_id, all in ascending order.










SELECT 
    p.product_name,
    o.product_id,
    o.order_id,
    o.order_date
FROM Orders o
JOIN Products p ON o.product_id = p.product_id
WHERE (o.product_id, o.order_date) IN (
    SELECT product_id, MAX(order_date)
    FROM Orders
    GROUP BY product_id
)
ORDER BY 
    p.product_name ASC, 
    o.product_id ASC, 
    o.order_id ASC;
