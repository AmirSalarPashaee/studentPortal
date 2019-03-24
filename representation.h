#ifndef REPRESENTATION_H
#include <portal.h>
#include <iostream>
#include <string>
#include <fstream>
#define REPRESENTATION_H

using namespace std;
class Representation
{
private:
    Portal portal;
public:
    Representation();
    void appendStudents();
    void searchStudents();
    void deleteStudents();
    void courseAppend();
    void searchCourse();
    void removeCourse();
    void addcoursesForStudent();
    void removeCourseForStudent();
    void printStudentList();
    void printCoursesList();
    void writeInFile();
    void writeCourses();
    void writeStudentsCourses();
    void readStudentsCourses();
    void readFromFile();
    void readCourses();
    void setGrade();
    void CourseStudents();
    void printAllCourse();
};

#endif // REPRESENTATION_H
