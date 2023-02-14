#include "Student.h"
#include "Group.h"
#include <iostream>

using std::cin;
using std::cout;

int studentsToTakeScolarship(Group group, float minimalGrade){

    int counter = 0;
    for(int i = 0; i < group.size; i++)
        if(group.students[i].grade >= minimalGrade)
            counter++;

    return counter;

}

int main(){

    unsigned fn, year, numberOfStudents;
    float grade;

    cin >> numberOfStudents;
    Student students[numberOfStudents];

    for(int i = 0; i < numberOfStudents; i++){

        cin >> fn >> year >> grade;
        students[i].initStudent(fn, year, grade);
        
    }

    Group myGroup;

    myGroup.initGroup(students, numberOfStudents);

    cout << myGroup.grade << '\n';

    float minimalGrade;
    cin >> minimalGrade;

    cout << "Number of students to take scolarship is: " << studentsToTakeScolarship(myGroup, minimalGrade) << '\n';

}