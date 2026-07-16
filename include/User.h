#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
private:
    string username;
    string password;
    string role;

public:
    User();

    User(string uname, string pass, string r);

    string getUsername();

    string getPassword();

    string getRole();

    void setUsername(string uname);

    void setPassword(string pass);

    void setRole(string r);
};

#endif