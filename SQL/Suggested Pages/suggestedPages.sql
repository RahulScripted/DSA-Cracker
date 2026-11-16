-- In a social media platform, personalized page recommendations improve user engagement. One common strategy is to suggest pages liked by a user's friends, excluding the ones the user already follows. You are given Tables:

-- Friendship Table
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║  user1_id   ║   int    ║
-- ║─────────────┼──────────║
-- ║  user2_id   ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - user1_id: ID of the first user in the friendship
--     2 - user2_id: ID of the second user in the friendship
--     3 - Primary Key: (user1_id, user2_id), each row indicates a mutual friendship between user1_id and user2_id.

-- Likes Table
-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║   user_id   ║   int    ║
-- ║─────────────┼──────────║
-- ║   page_id   ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - user_id: ID of the user who liked a page
--     2 - page_id: ID of the page that was liked
--     3 - Primary Key: (user_id, page_id), this ensures that a user likes a page only once.

-- Write a query to recommend pages to the user with user_id = 1 by using pages liked by their friends. Do not recommend pages the user has already liked. Ensure there are no duplicates in the result, and order the result by recommended_page in ascending order.







WITH Friends AS (
    SELECT user2_id AS friend_id
    FROM Friendship
    WHERE user1_id = 1
    
    UNION
    
    SELECT user1_id AS friend_id
    FROM Friendship
    WHERE user2_id = 1
)
SELECT DISTINCT l.page_id AS recommended_page
FROM Friends f
JOIN Likes l 
    ON f.friend_id = l.user_id
WHERE l.page_id NOT IN (
    SELECT page_id 
    FROM Likes 
    WHERE user_id = 1
)
ORDER BY recommended_page ASC;
