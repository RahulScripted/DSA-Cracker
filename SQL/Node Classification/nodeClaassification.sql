-- Hierarchical structures like file systems, organizational charts, or comment threads in a forum often need to differentiate between root, inner, and leaf nodes. Proper classification helps in rendering or processing the hierarchy efficiently. You are given a table Tree:

-- ╔═════════════╦══════════╗
-- ║ Column Name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║     id      ║   int    ║
-- ║─────────────┼──────────║
-- ║    p_id     ║   int    ║
-- ╚═════════════╩══════════╝

--     1 - id: The unique ID of a node (Primary Key).
--     2 - p_id: The ID of the parent node for this node.

-- A node where p_id IS NULL represents the root of the tree (since it has no parent). The table forms a valid tree (i.e., it is connected and acyclic with one root).

-- Each node can be classified as:
-- ╔═══════╦═════════════════════════════════════════════════════════════════╗
-- ║ Type  ║                           Description                           ║
-- ╠═══════╬═════════════════════════════════════════════════════════════════╣
-- ║ Root  ║ If p_id IS NULL (i.e., no parent)                               ║
-- ║───────┼─────────────────────────────────────────────────────────────────║
-- ║ Leaf  ║ If the node does not appear as a parent of any other node       ║
-- ║───────┼─────────────────────────────────────────────────────────────────║
-- ║ Inner ║ If the node has a parent (p_id is not NULL) and is also a       ║
-- ║       ║ parent to at least one other node                               ║
-- ╚═══════╩═════════════════════════════════════════════════════════════════╝

-- Write a query to determine the type of each node in a tree structure. Each node should be labeled as one of the following:
--     1 - 'Root': if it has no parent
--     2 - 'Leaf': if it has no children
--     3 - 'Inner': if it has both a parent and children







SELECT id,
    CASE 
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree;