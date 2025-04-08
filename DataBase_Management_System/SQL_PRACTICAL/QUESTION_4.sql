--  DEPOSIT (BR_NAME, ACC_NO, CUST_NAME, BALANCE)
--  CUSTOMER (CUST_NAME, STREET, CITY)
--  BRANCH (BR_NAME, ASSETS, CITY)
--  BORROW (BR_NAME, LOAN_NO, CUST_NAME, AMOUNT)
-- Write down the following SQL queries:
--  1. Find all customers who have either account or loan or both in SBI, Belur Math Branch
--  2. Find customers with names and cities in which they live who have taken loan from
--  SBI, Kolkata Branch.
--  3. Find customers name and amount including name of the branch for loan over
--  Rs.50,000.
--  4. Find customer having highest balance.
--  5. Find branch having highest loan.




CREATE DATABASE SQL_ASSIGNMENT4;
USE SQL_ASSIGNMENT4;

-- Table: CUSTOMER
CREATE TABLE CUSTOMER (
    CUST_NAME VARCHAR(50),
    STREET VARCHAR(50),
    CITY VARCHAR(50)
);

-- Table: BRANCH
CREATE TABLE BRANCH (
    BR_NAME VARCHAR(50),
    ASSETS INT,
    CITY VARCHAR(50)
);

-- Table: DEPOSIT
CREATE TABLE DEPOSIT (
    BR_NAME VARCHAR(50),
    ACC_NO INT,
    CUST_NAME VARCHAR(50),
    BALANCE INT
);

-- Table: BORROW
CREATE TABLE BORROW (
    BR_NAME VARCHAR(50),
    LOAN_NO INT,
    CUST_NAME VARCHAR(50),
    AMOUNT INT
);

-- Sample Data with Bengali-style Names

-- BRANCH
INSERT INTO BRANCH VALUES 
('SBI, Belur Math', 1000000, 'Howrah'),
('SBI, Kolkata', 2000000, 'Kolkata'),
('PNB, Durgapur', 800000, 'Durgapur'),
('UCO, Siliguri', 600000, 'Siliguri');

-- CUSTOMER
INSERT INTO CUSTOMER VALUES 
('SUKDEB MONDAL', 'Bally Road', 'Howrah'),
('ARITRA BANERJEE', 'BT Road', 'Kolkata'),
('RITWIKA CHOWDHURY', 'Shibpur', 'Howrah'),
('ANIRBAN DEY', 'Salt Lake', 'Kolkata'),
('PRIYANKA SARKAR', 'City Centre', 'Durgapur'),
('RAHUL HALDER', 'College Road', 'Siliguri');

-- DEPOSIT
INSERT INTO DEPOSIT VALUES 
('SBI, Belur Math', 1001, 'SUKDEB MONDAL', 58000),
('SBI, Belur Math', 1002, 'RITWIKA CHOWDHURY', 75000),
('SBI, Kolkata', 1003, 'ARITRA BANERJEE', 90000),
('PNB, Durgapur', 1004, 'PRIYANKA SARKAR', 30000);

-- BORROW
INSERT INTO BORROW VALUES 
('SBI, Belur Math', 201, 'ANIRBAN DEY', 40000),
('SBI, Belur Math', 202, 'SUKDEB MONDAL', 30000),
('SBI, Kolkata', 203, 'ARITRA BANERJEE', 60000),
('SBI, Kolkata', 204, 'RAHUL HALDER', 80000),
('UCO, Siliguri', 205, 'RAHUL HALDER', 20000);


select * from DEPOSIT;
select * from CUSTOMER;
select * from BRANCH;
select * from BORROW;

-- 1
SELECT DISTINCT CUST_NAME
FROM (
    SELECT CUST_NAME FROM DEPOSIT WHERE BR_NAME = 'SBI, Belur Math'
    UNION
    SELECT CUST_NAME FROM BORROW WHERE BR_NAME = 'SBI, Belur Math'
) AS RESULT;

-- 2
SELECT DISTINCT C.CUST_NAME, C.CITY
FROM CUSTOMER C
JOIN BORROW B ON C.CUST_NAME = B.CUST_NAME
WHERE B.BR_NAME = 'SBI, Kolkata';



-- 3


SELECT CUST_NAME, AMOUNT, BR_NAME
FROM BORROW
WHERE AMOUNT > 50000;

 -- 4
 
 
SELECT CUST_NAME, BALANCE
FROM DEPOSIT
WHERE BALANCE = (
    SELECT MAX(BALANCE) FROM DEPOSIT
);

 -- 5
SELECT BR_NAME, SUM(AMOUNT) AS TOTAL_LOAN
FROM BORROW
GROUP BY BR_NAME
ORDER BY TOTAL_LOAN DESC
LIMIT 1;

