SELECT user_id
FROM ActiveUsers

UNION

SELECT user_id
FROM ArchivedUsers;