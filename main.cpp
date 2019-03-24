#include <iostream>
#include <representation.h>
#include <stdlib.h>
#include <string>
//#include <iomanip>
#define Y 3
#define X 20
using namespace std;
int Portal::StudentsNumber ;
int Portal::CourseNumber ;

void gotoxy(int x,int y){
printf("%c[%d;%df",0x1B,y,x);
}

void menu(string*,int);
bool switchFucntion(Representation*);

void studentTable(Representation*);
void coursesTable(Representation*);
void studentPortal(Representation*);
void print(Representation*);


int main()
{
    Representation rep;
    rep.readFromFile();
    rep.readCourses();
    rep.readStudentsCourses();
    bool condition=true;
    while(condition){
        string table[6];
        table[0]="   MENU   ";
        table[1]="Students            ";
        table[2]="Courses             ";
        table[3]="Course Registeration";
        table[4]="Reports             ";
        table[5]="Exit                ";
        menu(table,5);
        condition=switchFucntion(&rep);
    }
    return 0;
}



void menu(string* table,int count){
    system("clear");
    gotoxy(X,Y);
    cout<<"************** "<<*table<<" *************"<<endl;
    for(int i=0;i<count;i++){
        gotoxy(X,Y+1+i);
        cout<<'*'<<i+1<<")"<<*(table+i+1)<<"\t\t"<<"**"<<endl;
    }
    gotoxy(X,count+Y+1);
    cout<<"***************************************"<<endl;
    gotoxy(X,count+Y+3);
    cout<<"Enter your choice: ";

}



void print(Representation* rep){
    string table[6];
    int a;
    table[0]=" Reports  ";
    table[1]="Students Reports        ";
    table[2]="Courses Reports         ";
    table[3]="Course's Students       ";
    table[4]="Students For all Courses";
    table[5]="Back                    ";
    bool condition=true;
    while(condition){
        menu(table,5);
        cin>>a;
        switch(a){
        case 1:
            rep->printStudentList();
            break;
        case 2:
            rep->printCoursesList();
            break;
        case 3:
            rep->CourseStudents();
            break;
        case 4:
            rep->printAllCourse();
            break;
        case 5:
            condition=false;
            break;
        }
    }
}


void studentPortal(Representation* rep){
    string table[5];
    int a;
    table[0]="Registeration";
    table[1]="Add a Course    \t";
    table[2]="Remove a Course \t";
    table[3]="Set a Grade     \t";
    table[4]="Back            \t";
    bool condition=true;
    while(condition){
        menu(table,4);
        cin>>a;
        switch(a){
        case 1:
            rep->addcoursesForStudent();
            break;
        case 2:
            rep->removeCourseForStudent();
            break;
        case 3:
            rep->setGrade();
            break;
        case 4:
            condition=false;
            break;
        }
    }
}


void coursesTable(Representation* rep){
    string table[5];
    int a;
    table[0]=" Courses  ";
    table[1]="Add a Course    \t";
    table[2]="Remove a Course \t";
    table[3]="Search a Course \t";
    table[4]="Back            \t";
    bool condition=true;
    while(condition){
        menu(table,4);
        cin>>a;
        switch(a){
        case 1:
            rep->courseAppend();
            break;
        case 2:
            rep->removeCourse();
            break;
        case 3:
            rep->searchCourse();
            break;
        case 4:
            condition=false;
            break;
        }
    }
}

void studentTable(Representation* rep){
    string table[5];
    int a;
    table[0]=" Students ";
    table[1]="Add a student   \t";
    table[2]="Remove a student\t";
    table[3]="Search a student\t";
    table[4]="Back            \t";
    bool condition=true;
    while(condition){
        menu(table,4);
        cin>>a;
        switch(a){
        case 1:
            rep->appendStudents();
            break;
        case 2:
            rep->deleteStudents();
            break;
        case 3:
            rep->searchStudents();
            break;
        case 4:
            condition=false;
            break;
        }
    }
}

bool switchFucntion( Representation* rep){
    int a;
    cin>>a;
    switch (a) {
    case 1:
        studentTable(rep);
        //rep->appendStudents();
        break;
    case 2:
        coursesTable(rep);
        break;
    case 3:
        studentPortal(rep);
        break;
    case 4:
        print(rep);
        break;
    case 5:
        rep->writeInFile();
        rep->writeCourses();
        rep->writeStudentsCourses();
        return false;
        break;
    }
    return true;
}
