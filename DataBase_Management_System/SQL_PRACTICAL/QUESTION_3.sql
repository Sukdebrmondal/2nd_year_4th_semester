-- Step 1: Create Database and Use it
CREATE DATABASE SQL_ASSIGNMENT3;
USE SQL_ASSIGNMENT3;

drop database sql_assignment3;

-- Step 2: Create Department Table
CREATE TABLE DEPARTMENT (
    DEPT_ID INT PRIMARY KEY,
    DEPT_NAME VARCHAR(50),
    MGR_ID INT,
    FLOOR_NO INT
);

-- Step 3: Insert Modified Data into DEPARTMENT
INSERT INTO DEPARTMENT (DEPT_ID, DEPT_NAME, MGR_ID, FLOOR_NO) 
VALUES
(1, 'DATA SCIENCE', 301, 10),
(2, 'ASTROPHYSICS', 302, 9),
(3, 'ELECTRICAL', 303, 10),
(4, 'BIOLOGY', 304, 8),
(5, 'STATISTICS', 305, 9),
(6, 'ENVIRONMENTAL SCIENCE', 306, 10),
(7, 'STATISTICS', 306, 7),
(8, 'ENVIRONMENTAL SCIENCE', 307, 10); -- Changed DEPT_ID from duplicate '6' to '8'

-- Step 4: Create EMPLOYEE Table
CREATE TABLE EMPLOYEE (
    EMP_ID INT PRIMARY KEY,
    EMP_NAME VARCHAR(50),
    SALARY INT,
    DEPT_ID INT,
    FOREIGN KEY (DEPT_ID) REFERENCES DEPARTMENT(DEPT_ID)
);

-- Step 5: Insert Modified Data into EMPLOYEE
INSERT INTO EMPLOYEE (EMP_ID, EMP_NAME, SALARY, DEPT_ID) 
VALUES
(101, 'ANIKET SENGUPTA', 32000, 1),       -- In DEPT_ID 1
(102, 'SOURAV PAL', 28000, 2),            -- In DEPT_ID 2
(103, 'TAMAL DAS', 9500, 3),              -- In DEPT_ID 3, salary < 10,000 & floor_no = 10
(104, 'BISWAJIT ROY', 45000, 4),          -- In DEPT_ID 4
(105, 'PRIYANKA MUKHERJEE', 48000, 5),    -- In DEPT_ID 5
(106, 'RAHUL NANDI', 52000, 6),           -- In DEPT_ID 6
(107, 'DEBAYAN SARKAR', 8500, 3),         -- In DEPT_ID 3, salary < 10,000 & floor_no = 10
(108, 'ANANYA BASU', 7200, 6),            -- In DEPT_ID 6
(109, 'ARPITA SARKAR', 56000, 1),         
(110, 'AVIK MAJUMDER', 67000, 5);      

select * from employee;
select * from department;   

-- 1.Display the names of all employees who work on 10th floor and earn less than Rs. 10,000.
SELECT e.emp_name, d.floor_no, e.salary
FROM employee AS e
JOIN department AS d ON e.dept_id = d.dept_id
WHERE d.floor_no = 10 AND e.salary < 10000;


-- 2.List names of all managers who manage two or more departments on the same floor.
SELECT mgr_id
FROM department
GROUP BY mgr_id
HAVING COUNT(*) >= 2;


-- 3.Give 10% hike to the salary to every employee who works in computer science department and display the appropriate record.
SELECT e.emp_name, e.salary, e.salary * 1.10 AS hiked_salary
FROM employee e
JOIN department d ON e.dept_id = d.dept_id
WHERE d.dept_name = 'DATA SCIENCE';

UPDATE employee
SET salary = salary * 1.10
WHERE dept_id IN (
    SELECT dept_id FROM department WHERE dept_name = 'DATA SCIENCE'
);

SELECT e.emp_name, e.salary, d.dept_name
FROM employee e
JOIN department d ON e.dept_id = d.dept_id
WHERE d.dept_name = 'DATA SCIENCE';


-- 4.Display the names of employee who earn more than every employee of IT department.
SELECT emp_name
FROM employee
WHERE salary = (SELECT MAX(salary) FROM employee);


-- 5.Print the names of employees who earn more than Rs. 50,000 and work in either sales or marketing departments.
SELECT e.emp_name, e.salary, d.dept_name
FROM employee e
JOIN department d ON e.dept_id = d.dept_id
WHERE e.salary > 50000 AND d.dept_name IN ('BIOLOGY', 'STATISTICS');
