-- ============================================================
--  STUDENT RESULT MANAGEMENT SYSTEM
--  VTU DBMS Mini Project | Scheme 2022
--  Subject Code: BCS403
-- ============================================================

-- ─────────────────────────────────────────
--  STEP 1: CREATE DATABASE
-- ─────────────────────────────────────────
CREATE DATABASE IF NOT EXISTS StudentResultDB;
USE StudentResultDB;

-- ─────────────────────────────────────────
--  STEP 2: CREATE TABLES (DDL)
-- ─────────────────────────────────────────

-- Table 1: DEPARTMENT
CREATE TABLE DEPARTMENT (
    Dept_ID   VARCHAR(5)  PRIMARY KEY,
    Dept_Name VARCHAR(50) NOT NULL,
    HOD       VARCHAR(40) NOT NULL
);

-- Table 2: STUDENT
CREATE TABLE STUDENT (
    USN     VARCHAR(10) PRIMARY KEY,
    Name    VARCHAR(50) NOT NULL,
    DOB     DATE        NOT NULL,
    Gender  CHAR(1)     CHECK(Gender IN ('M','F')),
    Phone   VARCHAR(10) UNIQUE NOT NULL,
    Dept_ID VARCHAR(5),
    FOREIGN KEY (Dept_ID) REFERENCES DEPARTMENT(Dept_ID)
);

-- Table 3: SUBJECT
CREATE TABLE SUBJECT (
    Sub_Code VARCHAR(8)  PRIMARY KEY,
    Sub_Name VARCHAR(60) NOT NULL,
    Credits  INT         NOT NULL,
    Dept_ID  VARCHAR(5),
    Semester INT         NOT NULL,
    FOREIGN KEY (Dept_ID) REFERENCES DEPARTMENT(Dept_ID)
);

-- Table 4: RESULT
CREATE TABLE RESULT (
    Result_ID INT         PRIMARY KEY AUTO_INCREMENT,
    USN       VARCHAR(10),
    Sub_Code  VARCHAR(8),
    Internal  INT  CHECK(Internal  BETWEEN 0 AND 50),
    External  INT  CHECK(External  BETWEEN 0 AND 100),
    Total     INT,
    Grade     VARCHAR(2) NOT NULL,
    FOREIGN KEY (USN)      REFERENCES STUDENT(USN),
    FOREIGN KEY (Sub_Code) REFERENCES SUBJECT(Sub_Code)
);

-- Table 5: SEMESTER
CREATE TABLE SEMESTER (
    Sem_ID INT          PRIMARY KEY AUTO_INCREMENT,
    USN    VARCHAR(10),
    Sem_No INT          NOT NULL,
    SGPA   DECIMAL(4,2) NOT NULL,
    Status VARCHAR(10)  NOT NULL,
    FOREIGN KEY (USN) REFERENCES STUDENT(USN)
);

-- ─────────────────────────────────────────
--  STEP 3: INSERT SAMPLE DATA (DML)
-- ─────────────────────────────────────────

-- Insert Departments
INSERT INTO DEPARTMENT VALUES ('CS', 'Computer Science',  'Dr. Sharma');
INSERT INTO DEPARTMENT VALUES ('EC', 'Electronics',       'Dr. Rao');
INSERT INTO DEPARTMENT VALUES ('ME', 'Mechanical Engg',   'Dr. Patil');

-- Insert Students
INSERT INTO STUDENT VALUES ('1VT22CS001','Rakesh Kumar','2004-05-10','M','9876543210','CS');
INSERT INTO STUDENT VALUES ('1VT22CS002','Suresh Patil','2004-08-22','M','9876543211','CS');
INSERT INTO STUDENT VALUES ('1VT22CS003','Anita Reddy', '2003-11-15','F','9876543212','CS');
INSERT INTO STUDENT VALUES ('1VT22EC001','Meena Singh', '2004-03-30','F','9876543213','EC');

-- Insert Subjects
INSERT INTO SUBJECT VALUES ('BCS301','Mathematics-3',         4,'CS',3);
INSERT INTO SUBJECT VALUES ('BCS302','Analog & Digital Elec', 4,'CS',3);
INSERT INTO SUBJECT VALUES ('BCS303','DBMS',                  4,'CS',3);
INSERT INTO SUBJECT VALUES ('BCS304','OOPs with C++',         4,'CS',3);

-- Insert Results
INSERT INTO RESULT(USN,Sub_Code,Internal,External,Total,Grade) VALUES
('1VT22CS001','BCS301',40,68,108,'A'),
('1VT22CS001','BCS302',38,72,110,'A+'),
('1VT22CS001','BCS303',45,80,125,'O'),
('1VT22CS001','BCS304',42,75,117,'O'),
('1VT22CS002','BCS301',30,55, 85,'B'),
('1VT22CS002','BCS302',28,40, 68,'C'),
('1VT22CS003','BCS301',48,90,138,'O'),
('1VT22CS003','BCS303',45,88,133,'O');

-- Insert Semester Records
INSERT INTO SEMESTER(USN,Sem_No,SGPA,Status) VALUES
('1VT22CS001',3,8.75,'PASS'),
('1VT22CS002',3,6.20,'PASS'),
('1VT22CS003',3,9.50,'PASS');

-- ─────────────────────────────────────────
--  STEP 4: SELECT QUERIES
-- ─────────────────────────────────────────

-- Q1: All students with department name
SELECT S.USN, S.Name, S.Gender, D.Dept_Name, S.Phone
FROM   STUDENT S
JOIN   DEPARTMENT D ON S.Dept_ID = D.Dept_ID;

-- Q2: Complete result of a specific student
SELECT S.Name, R.Sub_Code, SB.Sub_Name,
       R.Internal, R.External, R.Total, R.Grade
FROM   RESULT R
JOIN   STUDENT  S  ON R.USN      = S.USN
JOIN   SUBJECT  SB ON R.Sub_Code = SB.Sub_Code
WHERE  R.USN = '1VT22CS001';

-- Q3: Count students per department
SELECT D.Dept_Name, COUNT(S.USN) AS Total_Students
FROM   STUDENT S
JOIN   DEPARTMENT D ON S.Dept_ID = D.Dept_ID
GROUP  BY D.Dept_Name;

-- Q4: Subject-wise average marks
SELECT SB.Sub_Name,
       ROUND(AVG(R.Internal),2) AS Avg_Internal,
       ROUND(AVG(R.External),2) AS Avg_External,
       ROUND(AVG(R.Total),2)    AS Avg_Total
FROM   RESULT R
JOIN   SUBJECT SB ON R.Sub_Code = SB.Sub_Code
GROUP  BY SB.Sub_Name;

-- Q5: Students with SGPA above 8.0
SELECT S.USN, S.Name, SE.Sem_No, SE.SGPA, SE.Status
FROM   SEMESTER SE
JOIN   STUDENT  S ON SE.USN = S.USN
WHERE  SE.SGPA > 8.0
ORDER  BY SE.SGPA DESC;

-- Q6: Students who failed in any subject (Subquery)
SELECT USN, Name FROM STUDENT
WHERE  USN IN (
    SELECT USN FROM RESULT WHERE Grade = 'F'
);

-- Q7: Highest marks per subject
SELECT SB.Sub_Name, MAX(R.Total) AS Highest_Total
FROM   RESULT R
JOIN   SUBJECT SB ON R.Sub_Code = SB.Sub_Code
GROUP  BY SB.Sub_Name;

-- Q8: Students with O grade
SELECT DISTINCT S.USN, S.Name, R.Sub_Code, R.Grade
FROM   STUDENT S
JOIN   RESULT R ON S.USN = R.USN
WHERE  R.Grade = 'O';

-- ─────────────────────────────────────────
--  STEP 5: UPDATE AND DELETE
-- ─────────────────────────────────────────

-- Update phone number
UPDATE STUDENT SET Phone = '9999988888'
WHERE  USN = '1VT22CS001';

-- Update marks after revaluation
UPDATE RESULT SET External = 60, Total = 88, Grade = 'A'
WHERE  USN = '1VT22CS002' AND Sub_Code = 'BCS302';

-- Delete a result record
DELETE FROM RESULT
WHERE  USN = '1VT22CS002' AND Sub_Code = 'BCS302';

-- ─────────────────────────────────────────
--  STEP 6: CREATE VIEW
-- ─────────────────────────────────────────

CREATE VIEW Result_Summary AS
SELECT S.USN, S.Name, D.Dept_Name,
       R.Sub_Code, SB.Sub_Name,
       R.Internal, R.External, R.Total, R.Grade
FROM   STUDENT S
JOIN   DEPARTMENT D  ON S.Dept_ID  = D.Dept_ID
JOIN   RESULT R      ON S.USN      = R.USN
JOIN   SUBJECT SB    ON R.Sub_Code = SB.Sub_Code;

-- Use the view
SELECT * FROM Result_Summary WHERE USN = '1VT22CS001';

-- ============================================================
--  END OF SCRIPT
-- ============================================================
