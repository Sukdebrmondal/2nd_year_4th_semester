
CREATE DATABASE IF NOT EXISTS PRACTICE;

USE PRACTICE;
CREATE TABLE CUSTOMERS (
ID INT PRIMARY KEY,
NAME VARCHAR(20),
AGE INT,
ADDRESS VARCHAR(30),
SALARY INT
);

INSERT INTO CUSTOMERS (ID,NAME,AGE,ADDRESS,SALARY)
VALUES
(  1,"Ramesh",32, "RAMPURHAT",2000.00 ),
(  2,"Khilan",25, "DELHI",1500.00 ),
(  3,"kaushik ",23, "KOTA",2000.00 ),
(  4,"Chaitali",27, "MUMBAI",6500.00 ),
(  5,"Hardik  ",25, "BHOPAL",8500.00 ),
(  6,"Komal ",22, "MP",4500.00 ),
(  7,"Muffy",24, "INDORE",10000.00 );

-- Add a new customer to the table
INSERT INTO CUSTOMERS (ID, NAME, AGE, ADDRESS, SALARY)
VALUES (8, 'Ramesh', 32, 'RAMPURHAT', 2000.00);

 -- 1
 SELECT * FROM CUSTOMERS;

-- 2
SELECT * FROM CUSTOMERS WHERE SALARY >5000;

-- 3
SELECT * FROM CUSTOMERS WHERE SALARY=2000;


-- 4
SELECT * FROM CUSTOMERS WHERE SALARY!=2000;

-- 5
SELECT * FROM CUSTOMERS WHERE SALARY >=6500;

-- 6
SELECT * FROM CUSTOMERS WHERE AGE >=25 AND SALARY >=6500;


-- 7
SELECT * FROM CUSTOMERS WHERE AGE >=25 OR SALARY >=6500;

-- 8
SELECT * FROM CUSTOMERS WHERE AGE IS NOT NULL;

-- 9
SELECT * FROM CUSTOMERS WHERE NAME LIKE 'RA%';

-- 10
SELECT * FROM CUSTOMERS WHERE AGE IN (25,32);

-- 11
SELECT * FROM CUSTOMERS WHERE AGE BETWEEN 25 AND 32 ;
 -- 12
 SELECT AGE FROM CUSTOMERS WHERE EXISTS (SELECT AGE FROM CUSTOMERS WHERE SALARY >6500);
--   SELECT AGE FROM CUSTOMERS WHERE EXISTS (SELECT AGE FROM CUSTOMERS WHERE SALARY >6500)

 SELECT * FROM CUSTOMERS  
WHERE AGE > ALL (SELECT AGE FROM CUSTOMERS WHERE SALARY > 6500);


SELECT * FROM CUSTOMERS  
WHERE AGE > ANY (SELECT AGE FROM CUSTOMERS WHERE SALARY > 6500); 


SELECT COUNT(*) AS "RECORDS" FROM CUSTOMERS;


SELECT CURRENT_TIMESTAMP; 

SELECT * FROM CUSTOMERS;
UPDATE CUSTOMERS SET ADDRESS = "RAMPURHAT" WHERE ID = 1;
SELECT * FROM CUSTOMERS;

DELETE FROM CUSTOMERS 
WHERE ID = 6; 

SELECT * FROM CUSTOMERS 
WHERE SALARY LIKE '%200%'; 

SELECT * FROM CUSTOMERS ORDER BY NAME ASC;
SELECT NAME ,ADDRESS, SUM(SALARY) FROM CUSTOMERS
GROUP BY NAME,ADDRESS;

SELECT SALARY FROM CUSTOMERS ORDER BY SALARY;
SELECT  DISTINCT SALARY FROM CUSTOMERS ORDER BY SALARY;

SELECT * FROM CUSTOMERS ORDER BY NAME DESC;

 SELECT * FROM CUSTOMERS 
    ORDER BY (CASE ADDRESS 
    WHEN 'DELHI'   THEN 1 
    WHEN 'BHOPAL'   THEN 2 
    WHEN 'KOTA'   THEN 3 
    WHEN 'RAMPURHAT' THEN 4 
    WHEN 'MP'  THEN 5 
    ELSE 100 END) ASC, ADDRESS ASC;