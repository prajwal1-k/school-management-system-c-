#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Student
{
    private:
        string Studentid;
        string name;
        string StudentClass;
        string section;
        string gender;
        string phone;
        string address;

    public:
        //constructors
        Student();

        // setters
        void setStudentid(string id);
        void setName(string n);
        void setStudentClass(string c);
        void setSection(string s);
        void setGender(string g);
        void setPhone(string p);
        void setAddress(string a);

        // getters
        string getStudentid();
        string getName();
        string getStudentClass();
        string getSection();
        string getGender();
        string getPhone();
        string getAddress();

        //CRUD Operations
        void addStudent();
        void viewStudent();
        void updateStudent();
        void deleteStudent();
        void searchStudent();

        // Utility functions
        bool StudentExists(string id);
        void displayStudent(
            string id,
            string name,
            string cls,
            string sec,
            string gender,
            string phone,
            string address
        );
        bool getStudentByID(string id);

};
#endif