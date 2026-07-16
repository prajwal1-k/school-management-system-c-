#include "../include/TeacherDashboard.h"
#include "../include/Student.h"
#include "../include/Attendence.h"
#include "../include/Teacher.h"
#include <iostream>

using namespace std;

void TeacherDashboard::dashboard()
{
    Student student;
    Teacher teacher;
    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "          TEACHER DASHBOARD\n";
        cout << "=========================================\n";

        cout << "1. View Students\n";
        // cout << "2. Search Student\n";
        cout << "2. Take Attendance\n";
        cout << "3. View Attendance\n";
        cout << "4. Add Marks\n";
        cout << "5. View Marks\n";
        cout << "6. My Profile\n";
        cout << "0. Logout\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                student.viewStudent();
                break;

            // case 2:
            //     student.searchStudent();
            //     break;

            case 2:
                Attendence attendence;
                attendence.takeAttendence();

                break;

            case 3:
                attendence.viewAttendence();
                break;

            case 4:
                cout << "\nMarks Module Coming Soon...\n";
                break;

            case 5:
                cout << "\nView Marks Module Coming Soon...\n";
                break;

            case 6:
                teacher.viewMyProfile();
                break;

            case 0:
                cout << "\nLogged Out Successfully.\n";
                break;

            default:
                cout << "\nInvalid Choice.\n";
        }

    } while(choice != 0);
}