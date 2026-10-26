-- A movie streaming platform maintains a database of movies. The content curation team wants to feature movies that are more engaging and unique.The company maintains a Cinema table that contains:

-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║    movie    ║ varchar  ║
-- ║─────────────┼──────────║
-- ║ description ║ varchar  ║
-- ║─────────────┼──────────║
-- ║   rating    ║  float   ║
-- ╚═════════════╩══════════╝

--     1 - id: A unique (primary key) integer representing each movie.
--     2 - movie: The title of the movie.
--     3 - description: A short summary or keyword describing the movie.
--     4 - rating: A float (2 decimal places) from 0 to 10 indicating the movie's rating.

-- The task is to:

--     1 - Filter movies where the id is an odd number.
--     2 - Exclude any movie where the description is exactly 'boring'.
--     3 - Sort the results by rating in descending order.
--     4 - The sample output format is in the following example.






SELECT *
FROM Cinema
WHERE id % 2 = 1 AND description != 'boring'
ORDER BY rating DESC;