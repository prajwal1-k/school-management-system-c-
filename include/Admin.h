#ifndef ADMIN_H
#define ADMIN_H

class Admin
{
    public:
        void dashboard();
    
    private:
        void addStudent();
        void viewStudent();
        void updateStudent();
        void deleteStudent();
        void addTeacher();
        void viewTeacher();
        void updateTeacher();
        void deleteTeacher();

         void createUser();
        // void reports();

};

#endif