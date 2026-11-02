-- A food delivery system keeps track of customer orders and their preferred delivery dates.

-- The company maintains a Delivery table that contains:

-- ╔══════════════════════════════╦════════╗
-- ║ Column Name                  ║ Type   ║
-- ╠══════════════════════════════╬════════╣
-- ║ delivery_id                  ║ int    ║
-- ║ customer_id                  ║ int    ║
-- ║ order_date                   ║ date   ║
-- ║ customer_pref_delivery_date  ║ date   ║
-- ╚══════════════════════════════╩════════╝

--     1 - delivery_id: A unique identifier for each delivery.
--     2 - customer_id: ID of the customer who placed the order.
--     3 - order_date: Date when the order was placed.
--     4 - customer_pref_delivery_date: Customer's preferred delivery date.

-- If a customer chooses the same date for delivery as the order date, the order is considered "immediate." If the delivery date is different, it is considered "scheduled." The first order of a customer is the one with the earliest order date. Every customer has exactly one first order. The task is to find the percentage of "immediate" orders among the first orders of all customers, rounded to two decimal places.








SELECT ROUND(SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 2) AS immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN (
    SELECT customer_id, MIN(order_date)
    FROM Delivery
    GROUP BY customer_id
);
