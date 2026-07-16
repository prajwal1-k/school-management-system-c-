#include "../include/Admin.h"
#include "../include/Student.h"
#include "../include/Teacher.h"

#include <iostream>
using namespace std;

void Admin::dashboard()
{
    int choice;
    do
    {
         cout << "\n=====================================\n";
        cout << "      ADMIN DASHBOARD\n";
        cout << "=====================================\n";
       
        cout << "1. Add Student\n";
        cout << "2. View Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Add Teacher\n";
        cout << "6. View Teacher\n";
        cout << "7. Update Teacher\n";
        cout << "8. Delete Teacher\n";
        cout << "9. Create User\n";
        cout << "10. Reports\n";
        cout << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                addTeacher();
                break;
            case 6:
                viewTeacher();
                break;
            case 7:
                updateTeacher();
                break;
            case 8:
                deleteTeacher();
                break;
            case 9:
                createUser();
                break;
            // case 10:
            //     reports();
            //     // break;
            case 0:
                cout << "\nLogging out...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 0);
}

void Admin::addStudent(){
        Student student;
        student.addStudent();
}

// for viewing students
void Admin::viewStudent(){
        Student student;
        student.viewStudent();
}

// Update Students
void Admin::updateStudent(){
    Student student;
    student.updateStudent();
}

// Delete Students
void Admin::deleteStudent(){
    Student student;
    student.deleteStudent();
}

void Admin::addTeacher()
{
    Teacher teacher;
    teacher.addTeacher();
}

void Admin::viewTeacher()
{
    Teacher teacher;
    teacher.viewTeacher();
}

void Admin::updateTeacher()
{
    Teacher teacher;
    teacher.updateTeacher();
}

void Admin::deleteTeacher()
{
    Teacher teacher;
    teacher.deleteTeacher();
}
void Admin::createUser()
{
    ofstream file("./data/users.txt", ios::app);

    if (!file)
    {
        cout << "\nUnable to open users file.\n";
        return;
    }

    string username;
    string password;
    string role;

    cin.ignore();

    cout << "\n========== CREATE USER ==========\n";

    cout << "Username : ";
    getline(cin, username);

    cout << "Password : ";
    getline(cin, password);

    cout << "Role (Admin/Teacher/Student) : ";
    getline(cin, role);

    file << username << ","
         << password << ","
         << role << endl;

    file.close();

    cout << "\nUser Created Successfully.\n";
}