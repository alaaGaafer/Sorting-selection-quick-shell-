#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class Student
{
public:
    string name;
    string  id ;
    double gpa;
public:
    Student(string NAME,string ID,double GPA)            //parametrized constructor
    {

        name =NAME ;
        id=ID;
        gpa=GPA;

    }
    void print ()                                       //to print the arrays on the consolo
    {
        cout<< "Name: "<<name<<endl;
        cout<< "ID: "<<id<<endl;
        cout <<"GPA: "<<gpa<<endl;
    }
    /*getters*/
    string get_name()
    {
        return name;
    }
    string get_id()
    {
        return id ;
    }
    double get_gpa()
    {
        return gpa;
    }
    //operator overloading to compare 2 names from type student
    bool operator <(const Student& obj)
    {
        if (name<obj.name)
            return true;
        else
            return false;
    }

};

#endif // STUDENT_H_INCLUDED
