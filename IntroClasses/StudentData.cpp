#include <iostream>
#include <string>

using namespace std;

#define MAX_STUDENTS 32

struct Student {
    int id;
    string name;
    float score;

};

struct Course {
    int course_number;
    Student students[MAX_STUDENTS];
    int num_students;

};

void PrintStudent(Student& s) {
    cout<<s.name<<" "<<s.id<<" "<<s.score<<endl;
}

void PrintAllStudents(Course& c) {
    for(int i=0;i<c.num_students;i++){
        PrintStudent(c.students[i]);
    }
}

void AddStudent(int id, string name, Course& c) {
    if (c.num_students<MAX_STUDENTS){
        c.students[c.num_students].id = id;
        c.students[c.num_students].name = name;
        c.students[c.num_students].score = 0;
        c.num_students++;
    }
}

void RemoveStudent(int id, Course& c) {
    for(int i=0;i<c.num_students;i++){
        if(c.students[i].id==id){
            c.num_students=c.num_students-1;
            c.students[i].id = c.students[c.num_students].id;
            c.students[i].name = c.students[c.num_students].name;
            c.students[i].score = c.students[c.num_students].score;
        }
    }
}

//Sample Main Code to test functions
int main() {
    Course C1;
    C1.course_number = 16542;
    C1.num_students = 0;
    Course C2;
    C2.course_number = 78920;
    C2.num_students = 0;
    AddStudent(14972, "Albert", C1);
    AddStudent(54631, "Ben", C1);
    AddStudent(67220, "Cole", C1);
    AddStudent(23229, "Derrick", C1);
    AddStudent(81706, "Elise", C1);
    C1.students[0].score = 98.5;
    C1.students[1].score = 75.0;
    C1.students[2].score = 80.2;
    C1.students[3].score = 60.9;
    C1.students[4].score = 90.0;
    PrintAllStudents(C1);
    cout << "Removing" << endl;
    RemoveStudent(54631, C1);
    PrintAllStudents(C1);
    cout << "Course C2" << endl;
    AddStudent(325556, "Fred", C2);
    AddStudent(889742, "Glen", C2);
    C2.students[0].score = 60.7;
    C2.students[1].score = 94.8;
    PrintAllStudents(C2);
    return 0;
}
