#ifndef PORTAL_H
#include <course.h>
#include <student.h>
#include <iostream>
#define PORTAL_H


class Portal
{
public:
    Student* students;
    Course* course;
public:
    static int StudentsNumber;
    static int CourseNumber;

public:
    Portal();
    void addStudent(string,string,string,string);
    Student* searchStudent(string);
    void addCourse(string,int,string,int,string);
    Course* searchCourse(string);
    void removeCourse(string);
    void addCourseForStudent(string , string);
    Course* removeCourseForStudent(string,string);
    void setGrade(int,string,string);
    void printStudents(string);
    void studentsForAllCourses();
};

#endif // PORTAL_H
