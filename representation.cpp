#include "representation.h"

Representation::Representation()
{}

///*****************************************************************************
///***************** this state for Searching Function *************************
///*****************************************************************************

void Representation::searchStudents(){
    string studentNumber;
    Student* student;
    cout<<"please insert the Student Number : ";
    cin>>studentNumber;
    student=this->portal.searchStudent(studentNumber);
    if(student == 0)
        cout<<"NOT FOUND"<<endl;
    else
        student->printFeatures();
    string a;
    cout<<endl<<"\t Please enter c to CONTINUE : ";
    cin>>a;

}



void Representation::searchCourse(){
    string name;
    Course* course;
    cout<<"please enter your course name : ";
    cin>>name;
    course = this->portal.searchCourse(name);
    if(course == 0)
        cout<<"NOT FOUND"<<endl;
    else
        course->printCourse();
    string a;
    cout<<endl<<"\t Please enter c to CONTINUE : ";
    cin>>a;

}

void Representation::CourseStudents(){
    string id;
    cout<<"courses ID : ";
    cin>>id;
    this->portal.printStudents(id);
    string a;
    cout<<endl<<"\t Please enter c to CONTINUE : ";
    cin>>a;
}




///*****************************************************************************
///********************* this state for Append STH *****************************
///*****************************************************************************

void Representation::appendStudents(){
    string name;
    string familly;
    string studentNumber;
    string major;
    cin.ignore();
    cout<<"Please insert the name : ";
    getline(cin,name);
    cout<<"Please insert the familly : ";
    getline(cin,familly);
    cout<<"please insrt the major : ";
    getline(cin,major);
    cout<<"please insert the Student Number : ";
    getline(cin,studentNumber);
    this->portal.addStudent(name,familly,major,studentNumber);
}


void Representation::courseAppend(){
    string name;
    int units;
    string id;
    int choose;
    string explain;
    cin.ignore();
    cout<<"please enter your course name : ";
    getline(cin,name);
    //getline(cin,name);
    cout<<"please enter your units : ";
    cin>>units;
    cout<<"please enter the ID : ";
    cin.ignore();
    getline(cin,id);
    cout<<"if Course is Practical Write 1 Or Theoritical write 0 :";
    cin>>choose;
    cout<<"please enter the explanation: ";
    cin.ignore();
    getline(cin,explain);
    this->portal.addCourse(name,units,id,choose,explain);

    }

void Representation::addcoursesForStudent(){
    string studentId;
    string id;
    cout<<"please insert your Student Id : ";
    cin>>studentId;
    cout<<"please insert your courses Id : ";
    cin>>id;
    this->portal.addCourseForStudent(studentId,id);
}


///*****************************************************************************
///********************* this state for Remove STH *****************************
///*****************************************************************************


void Representation::deleteStudents(){
    string studentNumber;
    Student* student;

    cout<<"please insert the student Number that you want to remove it : ";
    cin>>studentNumber;
    student=this->portal.searchStudent(studentNumber);

    if(!(student==0)){
        Portal::StudentsNumber --;
        if(!(student->next == 0)){
            student->next->prev=student->prev;
            cout<<"student->next->prev : "<<student->next->prev<<endl;
            student->prev->next=student->next;
        }
        student->prev->next=0;

    }
}

void Representation::removeCourse(){
    string name;
    cout<<"please insert the course's name that you want to remove it : ";
    cin>>name;
    this->portal.removeCourse(name);

}
void Representation::removeCourseForStudent(){
    string studentId;
    string id;
    Course* course;
    cout<<"please insert your Student Id : ";
    cin>>studentId;
    cout<<"please insert your courses Id for you want to remove : ";
    cin>>id;
    course=this->portal.removeCourseForStudent(studentId,id);
    if(course != 0)
        course->printCourse();
    else
        cout<<"Not Found"<<endl;
}

void Representation::setGrade(){
    string studentId;
    string id;
    int grade;
    cout<<"Student Id : ";
    cin>>studentId;
    cout<<"Courses Id : ";
    cin>>id;
    cout<<"Insert Grade : ";
    cin>>grade;
    this->portal.setGrade(grade,studentId,id);
}

///*****************************************************************************
///********************* this state for Print STH ******************************
///*****************************************************************************



void Representation::printStudentList(){
    Student* student;
    student=this->portal.students->next;
    cout<<"\n\n";
    cout<<"\t|      NAME     |    FAMILLY    |     MAJOR     |  ID   |"<<endl;
    cout<<"\t\t-----------------------------------------"<<endl;
    while(true){
        if(student == 0)
            break;
        student->printTable();
        student=student->next;
        //cout<<"\t\t-----------------------------------------"<<endl;

    }
    cout<<"\t\t-----------------------------------------"<<endl;

    string a;
    cout<<endl<<"\t Please enter c to CONTINUE : ";
    cin>>a;
}

void Representation::printCoursesList(){
    Course* course;
    course = this->portal.course->next;
    cout<<"\t|          NAME         | Units |      ID       |    Explanation  "<<endl;
    cout<<"\t----------------------------------------------------------------"<<endl;

    while(true){
        if(course == 0)
            break;
        course->printTable();
        course=course->next;
    }
    cout<<"\t-----------------------------------------"<<endl;
    string a;
    cout<<endl<<"\t Please enter c to CONTINUE : ";
    cin>>a;
}
///*****************************************************************************
///***************** this state for write in File ******************************
///*****************************************************************************
void Representation::writeStudentsCourses(){
    fstream file("../studentsCourses.txt",ios::out | ios::trunc);
    Student* student;
    Course* course;
    student = this->portal.students->next;
    if(file.is_open() && (student != 0)){
        while(true){
            file <<"StudentId: "<<student->getStudentNumber()<<endl;
            course=student->courses->next;
            while(true){
                if(course == 0)
                    break;
                file <<"Id: "<<course->getId()<<endl;
                if(course->getGrade() != -1)
                    file <<"Grade: "<<course->getGrade()<<endl;
                course=course->next;
            }
            student=student->next;
            if(student == 0)
                break;
            file <<"***************"<<endl;
        }
        file.close();
    }else
        cout<<"file doesn't open"<<endl;

}
void Representation::writeInFile(){
    fstream file("../students.txt",ios::out | ios::trunc);
    Student* student;
    student=this->portal.students->next;
    cout<<"name is"<<student->getName()<<endl;
    if(file.is_open()){
        while(true){

            if(student == 0)
                break;
            file <<"Name: " <<student->getName() << endl;
            file <<"Familly: "<<student->getFamilly()<<endl;
            file <<"Mojor: "<<student->getMajor()<<endl;
            file <<"StudentId: "<<student->getStudentNumber()<<endl;
            //cout <<"Name: " <<student->getName() << endl;
            //cout <<"Familly: "<<student->getFamilly()<<endl;
            //cout <<"StudentId: "<<student->getStudentNumber()<<endl;

            student=student->next;
        }
        file.close();
    }else
        cout<<"file doesn't open"<<endl;
}
void Representation::writeCourses(){
Course* course;
fstream files("../courses.txt",ios::out | ios::trunc);
course = this->portal.course->next;
if(files.is_open()){
    while(true){

        if(course == 0)
            break;
        files <<"CourseName: " <<course->getName() << endl;
        files <<"Units: "<<course->getUnits()<<endl;
        files <<"Id: "<<course->getId()<<endl;
        files <<"Detection: "<<course->getDetection()<<endl;
        files <<"Explanation: "<<course->getExplain()<<endl;
        files <<"******************************************"<<endl;
        course=course->next;
    }
    files.close();
}else
    cout<<"file doesn't open"<<endl;
}
void Representation::readStudentsCourses(){
    string line;
    string studentId;
    string id;
    fstream file("../studentsCourses.txt",ios::in | ios :: app);
    if(file.is_open()){
        while( getline( file, line ) )
            {
                switch (line[0]) {
                case 'S':
                    line.erase(0,11);
                    cout<<line<<endl;
                    studentId=line;
                    break;
                case 'G':
                    line.erase(0,7);
                    cout<<line<<endl;
                    this->portal.setGrade(stoi(line),studentId,id);
                case 'I':
                    line.erase(0,4);
                    cout<<line<<endl;
                    id=line;
                    this->portal.addCourseForStudent(studentId,id);
                    break;

                }

            }
    }


}
void Representation::readFromFile(){
    string line;
    string name;
    string familly;
    string major;
    fstream files("../students.txt",ios::in | ios :: app);
    if(files.is_open()){
        while( getline( files, line ) )
            {
                switch (line[0]) {
                case 'N':
                    //cout<<line<<endl;
                    line.erase(0,6);
                    cout<<line<<endl;
                    name=line;
                    break;
                case 'F':
                    line.erase(0,9);
                    cout<<line<<endl;
                    familly=line;
                    break;
                case 'M':
                    line.erase(0,7);
                    cout<<line<<endl;
                    major=line;
                    break;
                case 'S':
                    line.erase(0,11);
                    cout<<line<<endl;
                    this->portal.addStudent(name,familly,major,line);
                    break;
                }

            }
        files.close();
    }else
        cout<<"Not FOUND"<<endl;
}
void Representation::readCourses(){
    string name;
    string line;
    string s;
    string id;
    int Detection;
    string Explanation;
    int units;
    fstream files("../courses.txt",ios::in | ios :: app);
    if(files.is_open()){
        while( getline( files, line ) )
            {
                switch (line[0]) {
                case 'C':
                    //cout<<line<<endl;
                    line.erase(0,12);
                    cout<<line<<endl;
                    name=line;
                    break;
                case 'U':
                    line.erase(0,7);
                    cout<<line<<endl;
                    units=stoi(line);
                    break;
                case 'D':
                    line.erase(0,11);
                    cout<<line<<endl;
                    if(line[0] == 'P')
                        Detection= 1;
                    else
                        Detection = 0;
                    cout<<Detection<<endl;
                    break;
                case 'E':
                    line.erase(0,13);
                    s="Theoritical";
                    if(Detection == 0)
                        line.erase(0,s.length()+2);
                    else
                    {
                        s="Practical";
                        line.erase(0,s.length()+2);
                    }
                    cout<<line<<endl;
                    Explanation=line;
                    this->portal.addCourse(name,units,id,Detection,Explanation);

                    break;
                case 'I':
                    line.erase(0,4);
                    cout<<line<<endl;
                    id=line;

                    break;
                }
            }
        files.close();
    }
}

void Representation::printAllCourse(){
    this->portal.studentsForAllCourses();

    string a;
    cout<<endl<<"\t Please enter c to CONTINUE : ";
    cin>>a;

}
