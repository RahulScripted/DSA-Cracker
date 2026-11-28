-- A cinema manager wants to improve the booking experience for users who prefer sitting together. You are given a table named Cinema:

-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║   seat_id   ║   int    ║
-- ║─────────────┼──────────║
-- ║    free     ║   bool   ║
-- ╚═════════════╩══════════╝

--     1 - seat_id: Unique identifier for the seat (auto-incremented, meaning it increases automatically by 1 for each row)
--     2 - free: Indicates whether the seat is free (1) or occupied (0)

-- Write a query to identify all seats that are part of any group of consecutive available seats. Return the result ordered by seat_id in ascending order. The test cases are designed to ensure that there are at least three consecutive available seats.








SELECT seat_id
FROM (
    SELECT
        seat_id,
        free,
        LAG(free) OVER (ORDER BY seat_id) AS prev_seat,
        LEAD(free) OVER (ORDER BY seat_id) AS next_seat
    FROM Cinema
) c
WHERE free = 1
  AND (
      prev_seat = 1
      OR next_seat = 1
  )
ORDER BY seat_id;