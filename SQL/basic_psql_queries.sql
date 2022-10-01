-- for delete example

-- DELETE FROM table_name
-- WHERE condition;

-- check weather exits or not
DROP TABLE IF EXISTS links_table;

-- create sample table

CREATE TABLE links_table (
    id serial PRIMARY KEY,
    url varchar(255) NOT NULL,
    name varchar(255) NOT NULL,
    description varchar(255),
    rel varchar(10),
    last_update date DEFAULT now()
);

-- insert example 

('1', 'https://www.postgresqltutorial.com', 'PostgreSQL Tutorial', 'Learn PostgreSQL fast and easy', 'follow', '2013-06-02'),

-- delete example
DELETE FROM links_table
WHERE id = 1;


-- to return the delete rows
DELETE FROM links_table
WHERE id = 1
RETURNING *;

-- update table 

-- UPDATE table_name
-- SET column1 = value1,
--     column2 = value2,
--     ...
-- WHERE condition;


-- update table example
UPDATE links_table
SET last_update = '2020-08-01' 
WHERE id = 1;


-- update table return
UPDATE links_table
SET last_update = '2020-07-01'
WHERE id = 2
RETURNING *;

-- USE of SQL CASE STATEMENT

SELECT url, name,
CASE
    WHEN url LIKE 'https://%' THEN 'The Website is secure.'
    WHEN url LIKE 'http://%' THEN 'The Wesbite is not secure.'
    ELSE 'NO DATA FOUND'
END AS url_text
FROM links_table;

-- for delete example

-- DELETE FROM table_name
-- WHERE condition;

-- check weather exits or not
DROP TABLE IF EXISTS links_table;

-- create sample table

CREATE TABLE links_table (
    id serial PRIMARY KEY,
    url varchar(255) NOT NULL,
    name varchar(255) NOT NULL,
    description varchar(255),
    rel varchar(10),
    last_update date DEFAULT now()
);

-- insert example 

('1', 'https://www.postgresqltutorial.com', 'PostgreSQL Tutorial', 'Learn PostgreSQL fast and easy', 'follow', '2013-06-02'),

-- delete example
DELETE FROM links_table
WHERE id = 1;


-- to return the delete rows
DELETE FROM links_table
WHERE id = 1
RETURNING *;

-- update table 

-- UPDATE table_name
-- SET column1 = value1,
--     column2 = value2,
--     ...
-- WHERE condition;


-- update table example
UPDATE links_table
SET last_update = '2020-08-01' 
WHERE id = 1;


-- update table return
UPDATE links_table
SET last_update = '2020-07-01'
WHERE id = 2
RETURNING *;

-- USE of SQL CASE STATEMENT

SELECT url, name,
CASE
    WHEN url LIKE 'https://%' THEN 'The Website is secure.'
    WHEN url LIKE 'http://%' THEN 'The Wesbite is not secure.'
    ELSE 'NO DATA FOUND'
END AS url_text
FROM links_table;
