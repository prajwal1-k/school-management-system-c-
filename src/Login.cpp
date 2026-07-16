#include "../include/Login.h"

#include<fstream>
#include <iostream>
#include <sstream>

using namespace std;

User Login::authenticate(){
    string username, password;

    cout<<"\n --------------- LOGIN ------------\n";
    cout<<"Enter username: ";
    cin>>username;

    cout<<"Enter password: ";
    cin>>password;

    ifstream file("./data/users.txt");

    if(!file){
        cout<<"Error opening file!"<<endl;
        return User();
    }

    string line;
    while(getline(file, line)){
        string uname;
        string pass;
        string role;

        stringstream ss(line);
        getline(ss, uname, ',');
        getline(ss, pass, ',');
        getline(ss, role, ',');

        if(username==uname && password==pass)
        {
            cout << "\nLogin Successful!\n";

            return User(uname,pass,role);
        }
    }  

     
    cout<<"Invalid username or password!"<<endl;

    return User();
}