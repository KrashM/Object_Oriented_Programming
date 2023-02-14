#include "Student.h"
#include "Group.h"
#include <iostream>

using std::cin;
using std::cout;

void swap(Student &A, Student &B){

    Student C = A;
    A = B;
    B = C;

}

void sortStudentsByFN(Student students[], int size){

    // Basic Bubble Sort for simplicity sake
    for(int i = 0; i < size - 1; i++)
        for(int j = i + 1; j < size; j++)
            if(students[i].fn > students[j].fn)
                swap(students[i], students[j]);

}

void sortStudentsByGrade(Student students[], int size){

    // Basic Bubble Sort for simplicity sake
    for(int i = 0; i < size - 1; i++)
        for(int j = i + 1; j < size; j++)
            if(students[i].grade > students[j].grade)
                swap(students[i], students[j]);

}

void studentsToTakeScolarship(Group group, float minimalGrade){

    Student studentsToTakeScolarship[group.size];
    int index = 0;
    for(int i = 0; i < group.size; i++)
        if(group.students[i].grade >= minimalGrade){

            studentsToTakeScolarship[index] = group.students[i];
            index++;

        }

    cout << "Students which will take scolarship are:\n";
    sortStudentsByFN(studentsToTakeScolarship, index);
    for(int i = 0; i < index; i++)
        studentsToTakeScolarship[i].print();
    
    cout << "Students which will take scolarship are:\n";
    sortStudentsByGrade(studentsToTakeScolarship, index);
    for(int i = 0; i < index; i++)
        studentsToTakeScolarship[i].print();

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

    studentsToTakeScolarship(myGroup, minimalGrade);

}