-- supplier(s_id,sname, address)
-- parts(pid,pname,colour) 
-- catalogue( sid,pid,cost) 
-- the catalogue relation list the price charged for part by supplier
-- write down the following queries in SQL 
-- 1. find the sname who supplies only red parts 
-- 2. find the sname who supplies the different parts in minimum rate show the parts with their rate.
-- 3. find the suppliers who charged less for some part than the average cost of that part 
-- 4. find the pnames of blue parts for which there is some suppliers.
CREATE DATABASE SQL_ASSIGNMENT7;
USE SQL_ASSIGNMENT7;
CREATE TABLE supplier (
    s_id INT PRIMARY KEY,
    sname VARCHAR(50),
    address VARCHAR(100)
);

INSERT INTO supplier (s_id, sname, address) VALUES
(1, 'Raj Suppliers', 'Kolkata'),
(2, 'Das Distributors', 'Howrah'),
(3, 'Mondal Traders', 'Delhi'),
(4, 'Archi Parts Co.', 'Mumbai'),
(5, 'Manab Supplies', 'Chennai'),
(6, 'Kumar Hardware', 'Bangalore');

CREATE TABLE parts (
    p_id INT PRIMARY KEY,
    pname VARCHAR(50),
    colour VARCHAR(20)
);

INSERT INTO parts (p_id, pname, colour) VALUES
(101, 'Bolt', 'red'),
(102, 'Nut', 'blue'),
(103, 'Screw', 'green'),
(104, 'Washer', 'red'),
(105, 'Pin', 'blue'),
(106, 'Cap', 'red');


CREATE TABLE catalogue (
    s_id INT,
    p_id INT,
    cost INT,
    FOREIGN KEY (s_id) REFERENCES supplier(s_id),
    FOREIGN KEY (p_id) REFERENCES parts(p_id)
);

INSERT INTO catalogue (s_id, p_id, cost) VALUES
(1, 101, 15),
(1, 104, 20),
(2, 101, 18),
(2, 102, 25),
(3, 103, 30),
(4, 105, 22),
(5, 106, 17),
(6, 102, 19),
(6, 105, 21);

-- 1. find the sname who supplies only red parts.
SELECT s.sname
FROM supplier s
WHERE s.s_id IN (
    SELECT c.s_id
    FROM catalogue c
    JOIN parts p ON c.p_id = p.p_id
    WHERE p.colour = 'red'
);

-- 2. find the sname who supplies the different parts in minimum rate show the parts with their rate.
SELECT s.sname, p.pname, c.cost
FROM catalogue c
JOIN (
    SELECT p_id, MIN(cost) AS min_cost
    FROM catalogue
    GROUP BY p_id
) min_costs ON c.p_id = min_costs.p_id AND c.cost = min_costs.min_cost
JOIN supplier s ON c.s_id = s.s_id
JOIN parts p ON c.p_id = p.p_id;

-- 3. find the suppliers who charged less for some part than the average cost of that part 
SELECT DISTINCT s.sname
FROM catalogue c
JOIN parts p ON c.p_id = p.p_id
JOIN supplier s ON c.s_id = s.s_id
WHERE c.cost < (
    SELECT AVG(c2.cost)
    FROM catalogue c2
    WHERE c2.p_id = c.p_id
);

-- 4. find the pnames of blue parts for which there is some suppliers.
SELECT DISTINCT p.pname
FROM parts p
JOIN catalogue c ON p.p_id = c.p_id
WHERE p.colour = 'blue';