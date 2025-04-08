CREATE DATABASE SQL_ASSIGNMENT5;
USE SQL_ASSIGNMENT5;


-- Create tables
CREATE TABLE STUDENT (
    SNUM INT PRIMARY KEY,
    SNAME VARCHAR(50),
    MAJOR VARCHAR(50),
    LEVEL VARCHAR(10),
    AGE INT
);

CREATE TABLE CLASS (
    NAME VARCHAR(50),
    MEETS_AT VARCHAR(50),
    ROOM VARCHAR(10),
    FID INT
);

CREATE TABLE ENROLLED (
    SNUM INT,
    CNAME VARCHAR(50)
);

CREATE TABLE FACULTY (
    FID INT PRIMARY KEY,
    FNAME VARCHAR(50),
    DEPTID INT
);

-- Insert sample data into STUDENT
INSERT INTO STUDENT VALUES
(1, 'Rohit Das', 'CS', 'FR', 18),
(2, 'Sneha Roy', 'EE', 'SO', 19),
(3, 'Arijit Sen', 'CS', 'JR', 20),
(4, 'Moumita Ghosh', 'BIO', 'SR', 21),
(5, 'Debraj Dey', 'MATH', 'FR', 18),
(6, 'Sayani Pal', 'EE', 'SO', 20),
(7, 'Aniket Mondal', 'CS', 'SR', 22);

-- Insert sample data into FACULTY
INSERT INTO FACULTY VALUES
(101, 'Dr. S. Mukherjee', 1),
(102, 'Dr. A. Banerjee', 2),
(103, 'Dr. T. Bhattacharya', 3);

-- Insert sample data into CLASS
INSERT INTO CLASS VALUES
('DBMS', 'MWF 9AM', 'R128', 101),
('Networks', 'TTh 10AM', 'R128', 101),
('Maths', 'MWF 10AM', 'R130', 102),
('Physics', 'TTh 9AM', 'R128', 103);

-- Insert sample data into ENROLLED
INSERT INTO ENROLLED VALUES
(1, 'DBMS'),
(2, 'DBMS'),
(3, 'Networks'),
(4, 'Physics'),
(5, 'Maths'),
(6, 'Physics'),
(7, 'Maths');


select * from STUDENT;
select * from CLASS;
select * from ENROLLED;
select * from FACULTY;

-- Query 1: Faculty with combined enrollment less than 5
SELECT DISTINCT F.FNAME
FROM FACULTY F
JOIN CLASS C ON F.FID = C.FID
LEFT JOIN ENROLLED E ON C.NAME = E.CNAME
GROUP BY F.FNAME
HAVING COUNT(E.SNUM) < 5;

-- Query 2: Level-wise average age
SELECT LEVEL, AVG(AGE) AS AVG_AGE
FROM STUDENT
GROUP BY LEVEL;

-- Query 3: Average age for levels except JR
SELECT LEVEL, AVG(AGE) AS AVG_AGE
FROM STUDENT
WHERE LEVEL <> 'JR'
GROUP BY LEVEL;

-- Query 4: Faculty teaching only in R128
SELECT F.FNAME, COUNT(*) AS TOTAL_CLASSES
FROM FACULTY F
JOIN CLASS C ON F.FID = C.FID
GROUP BY F.FNAME
HAVING SUM(CASE WHEN C.ROOM = 'R128' THEN 0 ELSE 1 END) = 0;

-- Query 5: Students enrolled in the maximum number of classes
SELECT S.SNAME
FROM STUDENT S
JOIN ENROLLED E ON S.SNUM = E.SNUM
GROUP BY S.SNUM, S.SNAME
HAVING COUNT(*) = (
    SELECT MAX(CLASS_COUNT)
    FROM (
        SELECT COUNT(*) AS CLASS_COUNT
        FROM ENROLLED
        GROUP BY SNUM
    ) AS CLASS_COUNTS
);
