-- As a restaurant owner, you want to understand how many orders are being processed immediately (on the same day the order is placed) compared to scheduled orders (set for a later day). This is useful for improving delivery logistics and understanding customer expectations. You are given a Delivery table where each record contains:

-- ╔════════════════════════════╦══════════╗
-- ║       Column Name          ║   Type   ║
-- ╠════════════════════════════╬══════════╣
-- ║       delivery_id          ║   int    ║
-- ║────────────────────────────┼──────────║
-- ║       customer_id          ║   int    ║
-- ║────────────────────────────┼──────────║
-- ║       order_date           ║   date   ║
-- ║────────────────────────────┼──────────║
-- ║customer_pref_delivery_date ║   date   ║
-- ╚════════════════════════════╩══════════╝

--     1 - delivery_id: Unique identifier for each delivery.
--     2 - customer_id: Identifier for the customer.
--     3 - order_date: Date the customer places the order.
--     4 - customer_pref_delivery_date: The preferred delivery date of the customer.
    
-- An order is considered immediate if the customer's preferred delivery date is the same as the order date; otherwise, it is considered scheduled. Write a query to calculate the percentage of immediate orders from the Delivery table. Round the result to 2 decimal places.






SELECT 
    ROUND(
        AVG(CASE WHEN order_date = customer_pref_delivery_date THEN 100.0 ELSE 0 END), 
        2
    ) AS immediate_percentage
FROM Delivery;
