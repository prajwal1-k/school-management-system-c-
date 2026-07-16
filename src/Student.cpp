#include "../include/Student.h"
#include <cstdio>

// constructors
Student::Student(){
    Studentid = "";
    name = "";
    StudentClass = "";  
    section = "";
    gender = "";
    phone = "";
    address = "";
}

// setter

void Student::setStudentid(string id){
    Studentid = id;
}

void Student::setName(string n){
    name = n;
}

void Student::setStudentClass(string c){
    StudentClass = c;
}

void Student::setSection(string s){
    section = s;
}

void Student::setGender(string g){
    gender = g;
}

void Student::setPhone(string p){
    phone = p;
}

void Student::setAddress(string a){
    address = a;
}

// getter


string Student::getStudentid(){
    return Studentid;
}

string Student::getName(){
    return name;
}

string Student::getStudentClass(){
    return StudentClass;
}

string Student::getSection(){
    return section;
}

string Student::getGender(){
    return gender;
}

string Student::getPhone(){
    return phone;
}

string Student::getAddress(){
    return address;
}


//check the duplicate id
bool Student::StudentExists(string id)
{
    ifstream file("data/students.txt");

    if (!file)
        return false;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string sid;

        getline(ss, sid, ',');

        if (sid == id)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

//----------------------
// Display One Student
//----------------------

void Student::displayStudent(
    string id,
    string name,
    string cls,
    string sec,
    string gender,
    string phone,
    string address)
{
    cout << left
         << setw(10) << id
         << setw(25) << name
         << setw(10) << cls
         << setw(10) << sec
         << setw(10) << gender
         << setw(15) << phone
         << setw(30) << address
         << endl;
}
    
// Add Student
void Student::addStudent(){
    ofstream file("./data/students.txt", ios::app);

    if(!file){
        cout << "Error opening file!" << endl;
        return;
    }

    cin.ignore(); // Clear the input buffer

    cout<<"----------------- ADD STUDENT ------------------";

    cout<<"Student ID: ";
    getline(cin, Studentid);

    if(StudentExists(Studentid)){
        cout << "Student with ID " << Studentid << " already exists!" << endl;
        return;
    }

    cout<<"Name: ";
    getline(cin, name);

    cout<<"Class: ";
    getline(cin, StudentClass);

    cout<<"Section: ";
    getline(cin, section);

    cout<<"Gender: ";
    getline(cin, gender);

    cout<<"Phone: ";
    getline(cin, phone);

    cout<<"Address: ";
    getline(cin, address);

    file << Studentid << "," << name << "," << StudentClass << "," << section << "," << gender << "," << phone << "," << address << endl;

    file.close();
    cout<<"Student added successfully!" << endl;
}

// View Students
void Student::viewStudent(){
    ifstream file("./data/students.txt");

    if(!file){
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    cout<<"\n----------------- VIEW STUDENTS ------------------\n";
    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Class"
         << setw(10) << "Section"
         << setw(10) << "Gender"
         << setw(15) << "Phone"
         << setw(30) << "Address"
         << endl;
    cout<<string(120, '-') << endl;

    while(getline(file, line)){
        stringstream ss(line);

        string id;
        string nm;
        string cls;
        string sec;
        string gen;
        string ph;
        string addr;

        getline(ss, id, ',');
        getline(ss, nm, ',');
        getline(ss, cls, ',');
        getline(ss, sec, ',');
        getline(ss, gen, ',');
        getline(ss, ph, ',');
        getline(ss, addr, ',');

        displayStudent(id, nm, cls, sec, gen, ph, addr);

    }
    file.close();
}

// update student
void Student::updateStudent(){
    string updateId;

    cout<<"Enter the student ID to update: ";
    cin>>updateId;

    ifstream file("./data/students.txt");

    if(!file){
        cout<<"\n Unable to open file. \n";
    }

    ofstream temp("./data/temp.txt");
    string line;
    bool found = false;

    cin.ignore(); // Clear the input buffer

    while(getline(file, line)){
        stringstream ss(line);

        string id, nm, cls, sec, gen, ph, addr;
        getline(ss, id, ',');
        getline(ss, nm, ',');
        getline(ss, cls, ',');
        getline(ss, sec, ',');
        getline(ss, gen, ',');
        getline(ss, ph, ',');       
        getline(ss, addr, ',');
        

        if(id == updateId){
            found = true;
            cout<<"Student found. Please enter the updated information:\n";

            cout<<"\n ------------------ UPDATE STUDENT ------------------\n";

            cout<<"Name: ";
            getline(cin, nm);

            cout<<"Class: ";
            getline(cin, cls);

            cout<<"Section: ";
            getline(cin, sec);

            cout<<"Gender: ";
            getline(cin, gen);

            cout<<"Phone: ";
            getline(cin, ph);

            cout<<"Address: ";
            getline(cin, addr);
        }

        temp << id << "," << nm << "," << cls << "," << sec << "," << gen << "," << ph << "," << addr << endl;
    }

    if(!found){
        cout<<"Student with ID " << updateId << " not found!" << endl;
    }

    file.close();
    temp.close();

    // Replace the original file with the updated one
    remove("./data/students.txt");
    rename("./data/temp.txt", "./data/students.txt");
}


// Delete Function
void Student::deleteStudent(){
    string deleteId;

    cout<<"Enter the student ID to Delete: ";
    cin>>deleteId;

    ifstream file("./data/students.txt");

    if(!file){
        cout<<"\n Unable to open file. \n";
    }
    ofstream temp("./data/temp.txt");
    string line;

    bool found = false;

    while(getline(file, line)){
        stringstream ss(line);

        string id, nm, cls, sec, gen, ph, addr;
        getline(ss, id, ',');
        getline(ss, nm, ',');
        getline(ss, cls, ',');
        getline(ss, sec, ',');
        getline(ss, gen, ',');
        getline(ss, ph, ',');       
        getline(ss, addr, ',');

        if(id == deleteId){
            found = true;
            cout<<"Student with ID " << deleteId << " deleted successfully!" << endl;
            continue; // Skip writing this student to the temp file
        }

        temp << id << "," << nm << "," << cls << "," << sec << "," << gen << "," << ph << "," << addr << endl;
    }
    file.close();
    temp.close();

    remove("./data/student.txt");
    rename("./data/temp.txt", "./data/students.txt");

    if(found){
        cout<<"\n Student Details succesfully Deleted";
    } else{
        cout<<"\n Student with ID " << deleteId << " not found!" << endl;
    }

}
bool Student::getStudentByID(string id)
{
    ifstream file("./data/students.txt");

    if (!file)
    {
        cout << "\nUnable to open students file.\n";
        return false;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string sid, nm, cls, sec, gen, ph, addr;

        getline(ss, sid, ',');
        getline(ss, nm, ',');
        getline(ss, cls, ',');
        getline(ss, sec, ',');
        getline(ss, gen, ',');
        getline(ss, ph, ',');
        getline(ss, addr);

        if (sid == id)
        {
            Studentid = sid;
            name = nm;
            StudentClass = cls;
            section = sec;
            gender = gen;
            phone = ph;
            address = addr;

            file.close();
            return true;
        }
    }

    file.close();
    return false;
}