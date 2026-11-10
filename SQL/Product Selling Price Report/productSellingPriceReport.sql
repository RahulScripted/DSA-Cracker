-- A retail system maintains price history for products over defined time periods and tracks sales by date. Management wants to calculate the average price at which each product was sold, using actual units sold and corresponding prices. There are two tables:

-- Prices Table
-- ╔═════════════╦══════════╗
-- ║ Column Name ║ Type     ║
-- ╠═════════════╬══════════╣
-- ║ product_id  ║ int      ║
-- ║ start_date  ║ date     ║
-- ║ end_date    ║ date     ║
-- ║ price       ║ int      ║
-- ╚═════════════╩══════════╝
--     1 - product_id: ID of the product.
--     2 - start_date: The date when this price period begins.
--     3 - end_date: The date when this price period ends.
--     4 - price: The product price during this date range.

-- UnitsSold Table
-- ╔═══════════════╦══════════╗
-- ║ Column Name   ║ Type     ║
-- ╠═══════════════╬══════════╣
-- ║ product_id    ║ int      ║
-- ║ purchase_date ║ date     ║
-- ║ units         ║ int      ║
-- ╚═══════════════╩══════════╝
--     1 - product_id: ID of the product sold.
--     2 - purchase_date: Date the product was purchased.
--     3 - units: Number of units sold on that day.

-- Write an SQL query to return the product_id and average_price for each product. Round average_price to 2 decimal places. Return 0 for average_price if the product has no sales. The result can be returned in any order.








SELECT 
    p.product_id,
    ROUND(
        COALESCE(SUM(u.units * p.price) / SUM(u.units), 0), 
        2
    ) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u 
ON 
    p.product_id = u.product_id 
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;
