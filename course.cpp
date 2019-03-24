#include "course.h"
#include <string>
Course::Course(string name , int units , string id )
{
    this->name = name;
    this->unit = units;
    this->id = id;
}
Theoritical::Theoritical(string name , int units , string id ):Course::Course(name,units,id){
    this->Detection = "Theoritical";

}
Practical::Practical(string name , int units , string id ):Course::Course(name,units,id){
    this->Detection ="Practical";

}
string Course::getDetection(){
    return this->Detection;
}
string Course::getExplain(){
    return this->explain;
}
void Practical::setExplain(string str){
    this->explain = "Practical: ";
    this->explain += str;
}

void Theoritical::setExplain(string str){
    this->explain = "Theoritical: ";
    this->explain += str;
}
string Course::getName(){
    return this->name;
}

string Course::getId(){
    return this->id;
}

int Course::getUnits(){
    return this->unit;
}

void Course::printCourse(){
    cout<<"\tName is : "<<this->name<<endl;
    cout<<"\tUnits : "<<this->unit<<endl;
    cout<<"\tid is : "<<this->id<<endl;
    cout<<"\t"<<this->getExplain()<<endl;
}

void Course::setGrade(int grade){
    this->grade = grade;
}
int Course::getGrade(){
    return this->grade;
}
void Practical::printTable(){
    int d=0;
    int m=0;
    if(this->name.length() <=16)
        d=8;
    if(this->name.length()<=8)
        d=16;

    if(this->getId().length()<=8)
        m=8;
    //cout<<this->name.length();
    //this->name.
    //cout<<this->getExplain()<<endl;
    cout<<"\t|"<<this->name<<setw(d)<<"\t|"<<this->unit<<"\t|"<<this->getId()<<setw(m)<<"\t|"<<this->getExplain()<<endl;
}
void Theoritical::printTable(){
    int d=0;
    int m=0;
    if(this->name.length() <=16)
        d=8;
    if(this->name.length()<=8)
        d=16;
    if(this->getId().length()<=8)
        m=8;
    //cout<<this->name.length();
    //this->name.
    //cout<<this->getExplain()<<endl;
    cout<<"\t|"<<this->name<<setw(d)<<"\t|"<<this->unit<<"\t|"<<this->getId()<<setw(m)<<"\t|"<<this->getExplain()<<endl;
}


