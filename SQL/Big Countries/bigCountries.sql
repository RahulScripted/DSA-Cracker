-- A global research organisation is analysing big countries based on either their land area or population size.  Your task is to identify and retrieve big countries based on some criteria. The company maintains a table named World, which stores data about different countries.

-- ╔═════════════╦══════════╗
-- ║ Column name ║   Type   ║
-- ╠═════════════╬══════════╣
-- ║    name     ║ varchar  ║
-- ║─────────────┼──────────║
-- ║  continent  ║ varchar  ║
-- ║─────────────┼──────────║
-- ║    area     ║   int    ║
-- ║─────────────┼──────────║
-- ║ population  ║   int    ║
-- ║─────────────┼──────────║
-- ║     gdp     ║  bigint  ║
-- ╚═════════════╩══════════╝
-- name: The name of the country, which is the primary key.
-- continent: The continent to which the country belongs.
-- area: The total land area of the country (in square kilometers).
-- population: The total population of the country.
-- gdp: The gross domestic product (GDP) of the country. 
-- A country is classified as big countries/ large nations if:

-- It has an area of at least 3,000,000 km², OR It has a population of at least 25,000,000. You need to return the name, population, and area of these big countries. The result can be returned in any order.









SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000;