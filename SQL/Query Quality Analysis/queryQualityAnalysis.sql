-- A search engine system logs query data including results, position in the search, and user ratings. Analysts want to evaluate query performance.

-- Given a Queries table with:
-- ╔═════════════╦══════════╦══════════╦═════════╗
-- ║ query_name  ║ result   ║ position ║ rating  ║
-- ╠═════════════╬══════════╬══════════╬═════════╣
-- ║ varchar     ║ varchar  ║ int      ║ int     ║
-- ╚═════════════╩══════════╩══════════╩═════════╝
-- query_name: The name of the search query.
-- result: The search result returned.
-- position: The rank of the result (1 to 500).
-- rating: A rating score from 1 to 5 (rating < 3 is considered poor).
-- This table might contain duplicate rows.

-- You are required to calculate:

--     1 - Query Quality: This is calculated as the average of (query rating / query position).
--     2 - Poor Query Percentage: This is the percentage of queries where the rating is less than 3.

-- The result should display:

-- 1 - query_name
-- 2 - quality (rounded to 2 decimal places)
-- 3 - poor_query_percentage (rounded to 2 decimal places)

-- The result can be returned in any order.







SELECT
    query_name,
    ROUND(AVG(rating * 1.0 / position), 2) AS quality,
    ROUND(AVG(CASE WHEN rating < 3 THEN 1.0 ELSE 0 END) * 100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;