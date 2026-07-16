#include "../include/Teacher.h"

#include<cstdio>

// Constructor
Teacher::Teacher() {
    teacherId = "";
    name = "";
    department = "";
    subject = "";
    phone = "";
    email = "";
};

// ===============================
// Setter methods
// ===============================

void Teacher::setTeacherID(string id) {
    teacherId = id;
}

void Teacher::setName(string name) {
    name = name;
}

void Teacher::setDepartment(string department) {
    department = department;
}

void Teacher::setSubject(string subject) {
    subject = subject;
}

void Teacher::setPhone(string phone) {
    phone = phone;
}

void Teacher::setEmail(string email) {
    email = email;
}

// ===============================
// Getter methods
// ===============================

string Teacher::getTeacherID() {
    return teacherId;
}

string Teacher::getName() {
    return name;
}

string Teacher::getDepartment() {
    return department;
}

string Teacher::getSubject() {
    return subject;
}

string Teacher::getPhone() {
    return phone;
}

string Teacher::getEmail() {
    return email;
}

// Check the teacher exists
bool Teacher::teacherExists(string id){
    ifstream file("./data/teachers.txt");

    if(!file){
        return false; // File doesn't exist, so teacher doesn't exist
    }

    string line;

    while(getline(file, line)){
        stringstream ss(line);

        string tid;
        getline(ss, tid, ',');

        if(tid == id){
            file.close();
            return true; // Teacher exists
        }
    }
    file.close();
    return false; // Teacher doesn't exist
}

// Display the one teacher details
void Teacher::displayTeacher(
    string id,
    string name,
    string department,
    string subject,
    string phone,
    string email
){
    cout << left << setw(15) << id
         << left << setw(20) << name
         << left << setw(20) << department
         << left << setw(20) << subject
         << left << setw(15) << phone
        << left << setw(30) << email << endl;
}

// Add a new teacher
void Teacher::addTeacher() {
    ofstream file("./data/teachers.txt", ios::app);

    if(!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }
    cin.ignore(); // Clear the input buffer

    cout<<"\n============= ADD TEACHER =============\n";
    cout<<"Enter Teacher ID: ";
    getline(cin, teacherId);

    if(teacherExists(teacherId)){
        cout << "Teacher with ID " << teacherId << " already exists." << endl;
        return;
    }

    cout<<"Enter Name: ";
    getline(cin, name);

    cout<<"Enter Department: ";
    getline(cin, department);

    cout<<"Enter Subject: ";
    getline(cin, subject);

    cout<<"Enter Phone: ";
    getline(cin, phone);

    cout<<"Enter Email: ";
    getline(cin, email);

    file<< teacherId << "," << name << "," << department << "," << subject << "," << phone << "," << email << endl;
    file.close();

    cout << "Teacher added successfully!" << endl;


}

// View all teachers
void Teacher::viewTeacher() {
    ifstream file("./data/teachers.txt");

    if(!file) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    string line;

    cout<<"\n============= TEACHER LIST =============\n";
    cout << left << setw(15) << "Teacher ID"
         << left << setw(20) << "Name"
         << left << setw(20) << "Department"
         << left << setw(20) << "Subject"
         << left << setw(15) << "Phone"
         << left << setw(30) << "Email" << endl;
    cout<<"---------------------------------------------------------------------------------------------\n";

    while(getline(file, line)){
        stringstream ss(line);
        string tid, tname, tdepartment, tsubject, tphone, temail;

        getline(ss, tid, ',');
        getline(ss, tname, ',');
        getline(ss, tdepartment, ',');
        getline(ss, tsubject, ',');
        getline(ss, tphone, ',');
        getline(ss, temail);

        displayTeacher(tid, tname, tdepartment, tsubject, tphone, temail);
    }
    file.close();
}

// Search for a teacher by ID
void Teacher::searchTeacher() {

    string searchId;
    cout<<"\n============= SEARCH TEACHER =============\n";
    cout<<"Enter Teacher ID to search: ";
    cin >> searchId;

    ifstream file("./data/teachers.txt");

    if(!file) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    string line;
    bool found = false;

    while(getline(file, line)){
        stringstream ss(line);

          string id, nm, dept, sub, ph, em;

        getline(ss, id, ',');
        getline(ss, nm, ',');
        getline(ss, dept, ',');
        getline(ss, sub, ',');
        getline(ss, ph, ',');
        getline(ss, em);

        if(id == searchId){
            found = true;

            cout<<"\n============= TEACHER DETAILS =============\n";
            cout << left << setw(15) << "Teacher ID"
                    << left << setw(20) << "Name"   
                    << left << setw(20) << "Department"
                    << left << setw(20) << "Subject"
                    << left << setw(15) << "Phone"
                    << left << setw(30) << "Email" << endl;
            break;
        }
    }
    file.close();
}

// Update a teacher's details
void Teacher::updateTeacher() {
    string updateId;

    cout<<"\n Enter the Teacher ID to update: ";
    cin >> updateId;

    ifstream file("./data/teachers.txt");
    
if(!file) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    ofstream tempFile("./data/temp.txt");

    string line;
    bool found = false;

    cin.ignore(); // Clear the input buffer

    while(getline(file, line)){
        stringstream ss(line);

        string id, nm, dept, sub, ph, em;

        getline(ss, id, ',');
        getline(ss, nm, ',');
        getline(ss, dept, ',');
        getline(ss, sub, ',');
        getline(ss, ph, ',');
        getline(ss, em);

        if(id == updateId){
            found = true;

            cout<<"\n============= UPDATE TEACHER =============\n";
            cout<<"Enter new Name (current: " << nm << "): ";
            getline(cin, nm);

            cout<<"Enter new Department (current: " << dept << "): ";
            getline(cin, dept);

            cout<<"Enter new Subject (current: " << sub << "): ";
            getline(cin, sub);

            cout<<"Enter new Phone (current: " << ph << "): ";
            getline(cin, ph);

            cout<<"Enter new Email (current: " << em << "): ";
            getline(cin, em);
        }

        tempFile<< id << "," << nm << "," << dept << "," << sub << "," << ph << "," << em << endl;
    }
    file.close();
    tempFile.close();

    // Replace the original file with the updated one
    remove("./data/teachers.txt");
    rename("./data/temp.txt", "./data/teachers.txt");

    if(found){
        cout << "Teacher details updated successfully!" << endl;
    } else {
        cout << "Teacher with ID " << updateId << " not found." << endl;
    }
}

// Delete a teacher by ID

void Teacher::deleteTeacher()
{
    string deleteID;

    cout << "\nEnter Teacher ID to Delete : ";
    cin >> deleteID;

    ifstream file("data/teachers.txt");

    if(!file)
    {
        cout << "\nUnable to open file.\n";
        return;
    }

    ofstream temp("data/temp.txt");

    string line;

    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string id;
        string nm;
        string dept;
        string sub;
        string ph;
        string em;

        getline(ss,id,',');
        getline(ss,nm,',');
        getline(ss,dept,',');
        getline(ss,sub,',');
        getline(ss,ph,',');
        getline(ss,em);

        if(id == deleteID)
        {
            found = true;
            continue;
        }

        temp << id << ","
             << nm << ","
             << dept << ","
             << sub << ","
             << ph << ","
             << em << endl;
    }

    file.close();
    temp.close();

    remove("data/teachers.txt");
    rename("data/temp.txt","data/teachers.txt");

    if(found)
        cout << "\nTeacher Deleted Successfully.\n";
    else
        cout << "\nTeacher ID Not Found.\n";
}

bool Teacher::getTeacherById(string id){
    ifstream file("./data/teachers.txt");

    if(!file){
        cout<<"\n Unable to open teacher file\n";
        return false;
    }

    string line;

    while(getline(file, line)){
        stringstream ss(line);

        string tid, nm, dept, sub,ph, em;

        getline(ss, tid, ',');
        getline(ss, nm, ',');
        getline(ss, dept, ',');
        getline(ss, sub, ',');
        getline(ss, ph, ',');
        getline(ss, em);

        if (tid == id)
        {
            teacherId = tid;
            name = nm;
            department = dept;
            subject = sub;
            phone = ph;
            email = em;

            file.close();
            return true;
        }

    }
    file.close();
    return false;
}

void Teacher::viewMyProfile(){
    string id;

      cout << "\nEnter Teacher ID : ";
    cin >> id;

    if (!getTeacherById(id))
    {
        cout << "\nTeacher Not Found.\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "          MY PROFILE\n";
    cout << "====================================\n";

    cout << "Teacher ID : " << teacherId << endl;
    cout << "Name       : " << name << endl;
    cout << "Department : " << department << endl;
    cout << "Subject    : " << subject << endl;
    cout << "Phone      : " << phone << endl;
    cout << "Email      : " << email << endl;
}