#include "../include/Student.h"
#include "../include/StudentDashboard.h"
#include "../include/Attendence.h"

#include <iostream>
using namespace std;

void StudentDashboard::dashboard(){
    Student student;

    int choice;

    do{
        cout << "\n=====================================\n";
        cout << "      STUDENT DASHBOARD\n";
        cout << "=====================================\n";
       
        cout << "1. View My Profile\n";
        cout << "2. View My Attendence\n";
        cout << "3. View My Marks\n";
        cout << "4. Change Password\n";
        cout << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                student.viewStudent();
                break;
            case 2:
                Attendence attendence;
                attendence.searchAttendence();
                break;
            case 3:
                cout << "View My Marks (Coming Soon)" << endl;
                break;
            case 4:
                cout << "Change Password (Coming Soon)" << endl;
                break;  
            case 0:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }while(choice != 0);
}

