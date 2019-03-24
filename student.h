#ifndef STUDENT_H
#include <string>
#include <course.h>
#include <iostream>
#include <iomanip>
#define STUDENT_H

using namespace std;
class Student
{
private:
    string name;
    string familly;
    string major;
    string studentNumber;
public:
    int coursesNumber=0;
public:
    Student* next;
    Student* prev;

public:
    Course* courses;

public:
    Student();
    void setFeatures(string,string,string,string);
    string getStudentNumber();
    void printFeatures();
    string getName();
    string getFamilly();
    string getMajor();
    void printTable();

};

#endif // STUDENT_H
