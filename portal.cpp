#include "portal.h"


Portal::Portal()
{
    this->students = new Student();
    this->course = new Theoritical("init",1,"0");
    //cout<<this->students<<endl;
    //cout<<this->students->prev<<endl;

}
///****************************************************************************
// these one just for append Student Or courses

void Portal::addStudent(string name,string familly,string major,string studentNumber){
    StudentsNumber ++;
    Student* next;
    Student** cur;

    next=this->students;
    //cout <<"StudentsNumber : "<<StudentsNumber<<endl;
    for(int count=1 ; count < StudentsNumber ; count ++ ){
        next=next->next;
    }
    cur = &next;
    (*cur)->next=new Student();
    (*(*cur)->next).setFeatures(name,familly,major,studentNumber);
    (*cur)->next->prev=next;
}

void Portal::addCourse(string name , int units , string id,int choose , string explanation){
    CourseNumber ++;
    Course* next;
    Course** cur;
    next=this->course;
    //cout <<"StudentsNumber : "<<StudentsNumber<<endl;
    for(int count=1 ; count < CourseNumber ; count ++ ){
        next=next->next;
    }
    cur = &next;
    if(choose == 1){
        (*cur)->next=new Practical(name,units,id);
        (*cur)->next->setExplain(explanation);
    }
    else{
        (*cur)->next=new Theoritical(name,units,id);
        (*cur)->next->setExplain(explanation);
            }
    (*cur)->next->prev=next;
}

void Portal::addCourseForStudent(string studentId,string id){
    Course* course;
    Student* student;
    Course* next;
    Course** cur;

    student = this->searchStudent(studentId);

    course = this->searchCourse(id);
   // cout<<"studentId : "<<studentId<<"\t student : "<<student<<endl;
   // cout<<"id : "<<id<<"\t course : " <<course<<endl;
    if((student != 0) && ( course != 0)){
        student->coursesNumber ++;
        next=student->courses;
        for(int count=1 ; count < student->coursesNumber ; count ++){
        next=next->next;
        }
        cur = &next;
        (*cur)->next=new Theoritical(course->getName(),course->getUnits(),course->getId());
        (*cur)->next->prev=next;
    }else
        cout<<"NOT FOUND"<<endl;

}

///************************************************************************************

// these states just for Search

Student* Portal::searchStudent(string studentNumber){
    Student* next;
    next=this->students->next;
    bool condition = true;
    if(next != 0){
        while(condition){
            if(next->getStudentNumber()==studentNumber)
            {

                return next;
                break;
            }
            //cout<<"next : "<<next<<endl;
            next=next->next;
            if(next == 0){
                return 0;
                break;
            }
        }
    }
    return 0;
}

Course* Portal::searchCourse(string id){
    Course* next;
    next=this->course->next;
    bool condition = true;
    while(condition){

        if(next->getId()== id)
        {

            return next;
            break;
        }
        //cout<<"next : "<<next<<endl;
        next=next->next;
        if(next == 0){
            return 0;
            break;
        }
    }
}
Course* Portal::removeCourseForStudent(string studentId,string id){
    Course* course;
    Student* student;
    Course* next;

    student = this->searchStudent(studentId);
    next=student->courses->next;
    for(int count=1;count <= student->coursesNumber;count++){
        if(next->getId()==id){
            next->prev->next=next->next;
            if(next->next != 0)
                next->next->prev = next->prev;
            student->coursesNumber --;
            return next;
            break;
        }
        //cout<<next->getName()<<endl;
        next=next->next;


    }
    return 0;
}
void Portal::removeCourse(string id){
    Course* course;
    course=this->searchCourse(id);
    //cout<<"course : "<<course;
    if(!course==0)
    {
        CourseNumber --;
    if(!(course->next == 0)){
        course->next->prev=course->prev;
        //cout<<"student->next->prev : "<<course->next->prev<<endl;
        course->prev->next=course->next;

              }
    course->prev->next=0;
    cout<<"mission Complete :) "<<endl;
    }
    //cout<<"student->prev->next : "<<student->prev->next<<endl;
}

void Portal::setGrade(int grade , string studentId,string id){
    //this->course->setGrade(grade);
    Course* course;
    Student* student;
    Course* next;

    student = this->searchStudent(studentId);
    if(student != 0){
        next=student->courses->next;
        for(int count=1;count <= student->coursesNumber;count++){
            if(next->getId()==id){
                next->setGrade(grade);
                break;
            }
            next=next->next;
        }
    }else
        cout<<"NOT FOUND\n";
}
void Portal::studentsForAllCourses(){
    Student* student;
    Course* course;
    Course* next;
    course=this->course;
    cout<<"\t\t"<<"---------------------------------"<<endl;

    while(true){
        course=course->next;
        if(course == 0)
            break;
        string s="| Course : "+course->getName();
        int f=0;

        if(course->getName().length() <=16)
            f=8;
        if(course->getName().length() <=8)
            f=11;

       cout<<"\t\t| Course : "<<course->getName()<<setw(f)<<"\t|"<<endl;
        student=this->students;
        while(true)
        {
            student=student->next;
            if(student == 0)
                break;
            next=student->courses;
            while(true){
                next=next->next;
                if(next == 0)
                    break;
                if(next->getId() == course->getId()){
                    int d;
                    if(student->getName().length()>= 8)
                        d=8;
                    cout<<"\t\t|\t\t"<<student->getName()<<setw(d)<<"\t|"<<endl;
                    break;
                }
            }

        }
        cout<<"\t\t"<<"---------------------------------"<<endl;


    }
}
void Portal::printStudents(string id){
    Student* student;
    Course* next;
    student = this->students;
    cout<<"\t\t|"<<"\tName\t"<<"   Grade  |"<<endl;
    for(int count=1 ; count <= StudentsNumber ; count ++){
        student=student->next;
        next=student->courses->next;
        for(int count=1;count <= student->coursesNumber;count++){
            if(next->getId()==id){
                int d=0;
                string s;

                if(student->getName().length() <=8)
                    d=8;
                if(next->getGrade() == -1 )
                    cout<<"\t\t|"<<student->getName()<<setw(d)<<"\t->\t"<<"- "<<"|"<<endl;
                else
                    cout<<"\t\t|"<<student->getName()<<setw(d)<<"\t->\t"<<next->getGrade()<<"|"<<endl;

                break;
            }
            next=next->next;
        }
    }

}

