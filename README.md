# 🎓 Student Result Management System
### VTU DBMS Mini Project | Scheme 2022 | Subject Code: BCS403

---

## 📌 Project Overview
A **Database Management System** mini project that manages student academic records including marks, grades, and SGPA using MySQL.

---

## 🗃️ Database Tables

| Table | Description |
|-------|-------------|
| `DEPARTMENT` | Stores department details |
| `STUDENT` | Stores student personal details |
| `SUBJECT` | Stores subject and credit details |
| `RESULT` | Stores marks and grades per subject |
| `SEMESTER` | Stores SGPA and pass/fail status |

---

## 🔗 Entity Relationships

```
DEPARTMENT  ──(1:N)──  STUDENT  ──(1:N)──  RESULT  ──(N:1)──  SUBJECT
                           |
                        (1:N)
                           |
                        SEMESTER
```

---

## 📋 Features
- ✅ Normalized database design (1NF → 2NF → 3NF)
- ✅ Primary key and foreign key constraints
- ✅ Inner joins across multiple tables
- ✅ Aggregate functions (AVG, MAX, COUNT)
- ✅ Subqueries to find failed students
- ✅ Views for result summary
- ✅ UPDATE and DELETE operations

---

## 🚀 How to Run

1. Open [DB Fiddle](https://www.db-fiddle.com) or MySQL Workbench
2. Select **MySQL 8.0**
3. Copy everything from `student_result.sql`
4. Paste into the query window and click **Run**

---

## 📁 Files in this Repository

| File | Description |
|------|-------------|
| `student_result.sql` | Complete SQL script (DDL + DML + Queries) |
| `VTU_DBMS_MiniProject_Report_v2.docx` | Full project report (12-14 pages) |
| `README.md` | Project description |

---

## 🛠️ Technologies Used
- **Database:** MySQL 8.0
- **Concepts:** ER Modeling, Normalization, SQL Joins, Views
- **Tool:** DB Fiddle / MySQL Workbench

---

## 👨‍🎓 Submitted By
- **Name:** Rakesh
- **College:** Shridevi Institute of Engineering & Technology, Tumkur
- **University:** Visvesvaraya Technological University (VTU)
- **Academic Year:** 2024–25
