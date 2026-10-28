-- A company has a customer referral program, where existing customers can refer new customers to the platform. Each customer record includes the referee_id, which indicates who referred them. The company maintains a table named Customer to store customer details.

-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║    name     ║  varchar ║
-- ║─────────────┼──────────║
-- ║ referee_id  ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - id: A unique identifier (primary key) for the customer table.
--     2 - name: The name of the customer.
--     3 - referee_id: The id of the customer who referred them (can be NULL if they were not referred).

-- You need to retrieve the names of customers who were NOT referred by customer id = 2. The output can be in any order.








SELECT name
FROM Customer
WHERE referee_id <> 2 OR referee_id IS NULL;