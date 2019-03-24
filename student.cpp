#include "student.h"

Student::Student()
{
    this->courses = new Theoritical("hich",3,"-12");
}
void Student::setFeatures(string name, string familly,string major, string studentNumber){
    this->name = name;
    this->familly = familly ;
    this->studentNumber = studentNumber;
    this->major=major;
}

void Student::printFeatures(){
    cout<<"\tName : "<<this->name<<endl;
    cout<<"\tFamilly : "<<this->familly<<endl;
    cout<<"\tStudent Number : "<<this->studentNumber<<endl;
}
void Student::printTable(){
    int d=0;
    int f=0;
    int m=0;
    if(this->name.length()<=8)
        d=8;
    if(this->familly.length()<=8)
        f=8;
    if(this->major.length()<=8)
        m=8;
    //cout<<this->name.length();
    cout<<"\t|"<<this->name<<setw(d)<<"\t|"<<this->familly<<setw(f)<<"\t|"<<this->major<<setw(m)<<"\t|"<<this->studentNumber<<"\t|"<<endl;

}

string Student::getStudentNumber(){
    return this->studentNumber;
}

string Student::getFamilly(){
    return this->familly;
}

string Student::getName(){
    return this->name;
}

string Student::getMajor(){
    return this->major;
}
