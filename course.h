#ifndef COURSE_H
#include <string>
#include <iostream>
#include <iomanip>
#define COURSE_H
using namespace std;

class Course
{
protected:
    string name;
    string id;
    int unit;
    int grade = -1;
    string explain;
    string Detection;
public:
    Course* next;
    Course* prev;
//private:
//    Student studentsList;

public:
    Course(string,int,string);
    string getName();
    string getId();
    int getUnits();
    void printCourse();
    int getGrade();
    void setGrade(int);
    virtual void printTable()=0;
    string getExplain();
    string getDetection();
    virtual void setExplain(string)=0;
};
class Theoritical :public Course {

public:
    Theoritical(string,int ,string);
    void printTable();
    void setExplain(string);
};

class Practical : public Course{
public:
    Practical(string , int ,string);
    void printTable();
    void setExplain(string);

};

#endif // COURSE_H
