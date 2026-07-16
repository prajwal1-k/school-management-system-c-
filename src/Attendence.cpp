#include "../include/Attendence.h"
#include "../include/Student.h"

#include<string>

using namespace std;

void Attendence::takeAttendence()
{
    ofstream file("./data/attendance.txt", ios::app);

    if (!file)
    {
        cout << "\nUnable to open the Attendance file.\n";
        return;
    }

    Student student;

    string id;
    string date;
    string status;

    cout << "\n------------- TAKE ATTENDANCE -----------------\n";

    cout << "Student ID : ";
    cin >> id;

    // Search student
    if (!student.getStudentByID(id))
    {
        cout << "\nStudent Not Found.\n";
        file.close();
        return;
    }

    // Display student details
    cout << "\n========== STUDENT DETAILS ==========\n";

    cout << "Student ID : " << student.getStudentid() << endl;
    cout << "Name       : " << student.getName() << endl;
    cout << "Class      : " << student.getStudentClass() << endl;
    cout << "Section    : " << student.getSection() << endl;
    cout << "Gender     : " << student.getGender() << endl;
    cout << "Phone      : " << student.getPhone() << endl;
    cout << "Address    : " << student.getAddress() << endl;

    cin.ignore();

    cout << "\nDate (YYYY-MM-DD) : ";
    getline(cin, date);

    cout << "Status (P/A) : ";
    getline(cin, status);

    file << student.getStudentid() << ","
         << student.getName() << ","
         << student.getStudentClass() << ","
         << student.getSection() << ","
         << date << ","
         << status << endl;

    file.close();

    cout << "\nAttendance Saved Successfully.\n";
}

// View Attendence

void Attendence::viewAttendence()
{
    ifstream file("data/attendance.txt");

    if(!file)
    {
        cout<<"\nAttendance File Not Found.\n";
        return;
    }

    string line;

    cout<<"\n================ ATTENDANCE ================\n\n";

    cout<<left
        <<setw(10)<<"ID"
        <<setw(25)<<"NAME"
        <<setw(10)<<"CLASS"
        <<setw(15)<<"DATE"
        <<setw(10)<<"STATUS"
        <<endl;

    cout<<string(75,'-')<<endl;

    while(getline(file,line))
    {
        stringstream ss(line);

        string id,name,cls,date,status;

        getline(ss,id,',');
        getline(ss,name,',');
        getline(ss,cls,',');
        getline(ss,date,',');
        getline(ss,status);

        cout<<left
            <<setw(10)<<id
            <<setw(25)<<name
            <<setw(10)<<cls
            <<setw(15)<<date
            <<setw(10)<<status
            <<endl;
    }

    file.close();
}

//Search Attendence
void Attendence::searchAttendence()
{
    string id;

    cout<<"\nEnter Student ID : ";
    cin>>id;

    ifstream file("data/attendance.txt");

    if(!file)
    {
        cout<<"\nFile Not Found.\n";
        return;
    }

    string line;

    bool found=false;

    while(getline(file,line))
    {
        stringstream ss(line);

        string sid,name,cls,date,status;

        getline(ss,sid,',');
        getline(ss,name,',');
        getline(ss,cls,',');
        getline(ss,date,',');
        getline(ss,status);

        if(sid==id)
        {
            found=true;

            cout<<"\nStudent : "<<name<<endl;
            cout<<"Class : "<<cls<<endl;
            cout<<"Date : "<<date<<endl;
            cout<<"Status : "<<status<<endl;
            cout<<"-----------------------------"<<endl;
        }
    }

    if(!found)
        cout<<"\nNo Attendance Found.\n";

    file.close();
}