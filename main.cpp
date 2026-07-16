#include <iostream>

#include "include/Login.h"
#include "include/Admin.h"
#include "include/Menu.h"
#include "include/StudentDashboard.h"
#include "include/TeacherDashboard.h"


using namespace std;

int main()
{
    Menu::welcome();

    Login login;

    User user = login.authenticate();

    if(user.getRole() == "Admin")
    {
        Admin admin;
        admin.dashboard();
    }
    else if(user.getRole() == "Teacher")
    {
        cout << "\nWelcome Teacher: " << user.getUsername() << endl;

        TeacherDashboard dashboard;
        dashboard.dashboard();
    }
    else if(user.getRole() == "Student")
    {
        cout << "\nWelcome Student: " << user.getUsername() << endl;

    StudentDashboard dashboard;
    dashboard.dashboard();
    }
    else
    {
        cout << "\nLogin Failed.\n";
    }

    return 0;
}