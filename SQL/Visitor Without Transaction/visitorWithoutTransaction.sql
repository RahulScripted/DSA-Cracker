-- A shopping mall management system tracks customer visits and transactions. Some customers visit the mall but do not make any purchases during their visit. The mall’s management wants to identify these customers and determine how many times they visited without making a transaction. Your task is to find all customers who visited without making any transactions and count the number of such visits per customer. The company maintains two tables:

-- Visits table, which contains:
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║  visit_id   ║   int    ║
-- ║─────────────┼──────────║
-- ║ customer_id ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - visit_id: A unique identifier for each visit.
--     2 - customer_id: The ID of the customer who visited the mall.

-- Transactions table, which contains:
-- ╔════════════════╦══════════╗
-- ║  Column Name   ║   Type   ║
-- ╠════════════════╬══════════╣
-- ║ transaction_id ║   int    ║
-- ║────────────────┼──────────║
-- ║    visit_id    ║   int    ║
-- ║────────────────┼──────────║
-- ║     amount     ║   int    ║
-- ╚════════════════╩══════════╝

--     1 - transaction_id: A unique identifier for each transaction.
--     2 - visit_id: A reference to the visit in which the transaction occurred.
--     3 - amount: The amount spent during the transaction.

-- Your task is to find customers who visited but did not make any transactions. Count how many times each customer made such visits. Return the result in sorted by count_no_trans in descending order.








SELECT customer_id, COUNT(visit_id) AS count_no_trans
FROM Visits 
where visit_id NOT IN (SELECT visit_id FROM Transactions)
GROUP BY customer_id
ORDER BY count_no_trans DESC;