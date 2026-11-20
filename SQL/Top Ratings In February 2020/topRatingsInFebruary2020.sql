-- You run a movie review system where users submit ratings for movies. You are given three tables:

-- Movies Table:
-- ╔══════════╦════════════╗
-- ║ Column   ║ Type       ║
-- ╠══════════╬════════════╣
-- ║ movie_id ║ int        ║
-- ║ title    ║ varchar    ║
-- ╚══════════╩════════════╝

-- Users Table:
-- ╔══════════╦════════════╗
-- ║ Column   ║ Type       ║
-- ╠══════════╬════════════╣
-- ║ user_id  ║ int        ║
-- ║ name     ║ varchar    ║
-- ╚══════════╩════════════╝

-- MovieRating Table:
-- ╔════════════╦══════════╗
-- ║   Column   ║   Type   ║
-- ╠════════════╬══════════╣
-- ║  movie_id  ║   int    ║
-- ║────────────┼──────────║
-- ║  user_id   ║   int    ║
-- ║────────────┼──────────║
-- ║   rating   ║   int    ║
-- ║────────────┼──────────║
-- ║ created_at ║   date   ║
-- ╚════════════╩══════════╝


-- Return the name of the user who rated the most movies. Break ties by lexicographically smallest name. Return the title of the movie with the highest average rating in February 2020. Break ties by lexicographically smallest title.








(
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating mr ON u.user_id = mr.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(mr.movie_id) DESC, u.name ASC
    LIMIT 1
)
UNION ALL
(
    SELECT m.title AS results
    FROM Movies m
    JOIN MovieRating mr ON m.movie_id = mr.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id, m.title
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1
);