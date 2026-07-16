#include "../include/User.h"

User::User()
{
    username="";
    password="";
    role="";
}

User::User(string uname,string pass,string r)
{
    username=uname;
    password=pass;
    role=r;
}

string User::getUsername()
{
    return username;
}

string User::getPassword()
{
    return password;
}

string User::getRole()
{
    return role;
}

void User::setUsername(string uname)
{
    username=uname;
}

void User::setPassword(string pass)
{
    password=pass;
}

void User::setRole(string r)
{
    role=r;
}