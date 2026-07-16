#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include<iomanip>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Teacher{
private:
    string teacherId;
    string name;
    string department;
    string subject;
    string phone;
    string email;
public:
    Teacher();

    //setter
    void setTeacherID(string id);
    void setName(string name);
    void setDepartment(string department);
    void setSubject(string subject);
    void setPhone(string phone);
    void setEmail(string email);

    //Getter
    string getTeacherID();
    string getName();
    string getDepartment();
    string getSubject();
    string getPhone();
    string getEmail();

    // CRUD Operations
    void addTeacher();
    void viewTeacher();
    void searchTeacher();
    void updateTeacher();
    void deleteTeacher();
    void searchTeacher(string id);

    void viewMyProfile();
    bool getTeacherById(string id);
    bool teacherExists(string id);

    void displayTeacher(
        string id,
        string name,
        string department,      
        string subject,
        string phone,
        string email
    );
};

#endif // TEACHER_H