# School Management System in C++

## Project Title
**School Management System using C++**

---

# 1. Introduction

The School Management System is a console-based application developed in C++ that helps manage student records efficiently. It allows administrators to perform operations such as adding, viewing, searching, updating, and deleting student information. The project demonstrates Object-Oriented Programming (OOP) concepts and basic file handling in C++.

---

# 2. Objectives

- Manage student records efficiently.
- Perform CRUD (Create, Read, Update, Delete) operations.
- Store student data permanently using files.
- Apply Object-Oriented Programming concepts.
- Provide a user-friendly menu-driven interface.

---

# 3. Features

- Add Student Record
- Display All Students
- Search Student by Roll Number
- Update Student Information
- Delete Student Record
- Save Data to File
- Load Data from File
- Exit Program

---

# 4. Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | Programming Language |
| OOP | Code Organization |
| File Handling | Permanent Data Storage |
| STL (Vector) | Store Student Objects |

---

# 5. System Requirements

## Hardware Requirements

- Processor: Intel i3 or above
- RAM: 4 GB minimum
- Storage: 100 MB free space

## Software Requirements

- Windows/Linux/macOS
- Code::Blocks / Dev-C++ / Visual Studio Code
- GCC Compiler

---

# 6. Functional Requirements

### Student Module

- Add new student
- Display all students
- Search student
- Update student details
- Delete student

### File Module

- Save records
- Read records
- Maintain persistent storage

---

# 7. Class Design

```text
+----------------------+
|      Student         |
+----------------------+
| rollNo               |
| name                 |
| age                  |
| className            |
| marks                |
+----------------------+
| input()              |
| display()            |
| update()             |
+----------------------+

            |
            |

+----------------------+
| SchoolManagement     |
+----------------------+
| vector<Student>      |
+----------------------+
| addStudent()         |
| displayStudents()    |
| searchStudent()      |
| updateStudent()      |
| deleteStudent()      |
| saveToFile()         |
| loadFromFile()       |
+----------------------+
```

# 8. Algorithm

## Algorithm: Add Student

1. Start
2. Enter student details.
3. Store the student data in a vector.
4. Save the updated records to the file.
5. Display **"Student Added Successfully."**
6. End.

---

## Algorithm: Search Student

1. Start
2. Enter the student's Roll Number.
3. Compare the entered Roll Number with the stored records.
4. If the student is found:
   - Display the student's details.
5. Otherwise:
   - Display **"Student Not Found."**
6. End.

---

## Algorithm: Update Student

1. Start
2. Enter the Roll Number of the student to update.
3. Search for the student record.
4. If the student is found:
   - Update the required details.
   - Save the updated records to the file.
   - Display **"Student Record Updated Successfully."**
5. Otherwise:
   - Display **"Student Not Found."**
6. End.

---

## Algorithm: Delete Student

1. Start
2. Enter the Roll Number of the student to delete.
3. Search for the student record.
4. If the student is found:
   - Remove the student record from the vector.
   - Save the updated records to the file.
   - Display **"Student Record Deleted Successfully."**
5. Otherwise:
   - Display **"Student Not Found."**
6. End.

---

## To Compile Use
```bash
g++ main.cpp src/User.cpp src/Login.cpp src/Student.cpp src/Teacher.cpp src/Attendence.cpp src/Admin.cpp src/Menu.cpp src/TeacherDashboard.cpp src/StudentDashboard.cpp -Iinclude -std=c++17 -o sms
```

## To Run 
```bash
./sms
```

