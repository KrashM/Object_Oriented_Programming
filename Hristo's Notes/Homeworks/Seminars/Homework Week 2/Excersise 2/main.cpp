#include "Student.h"
#include <iostream>

using std::cin;

int main(){

    unsigned fn, year;
    float grade;

    cin >> fn >> year >> grade;

    Student newStudent;
    newStudent.initStudent(fn, year, grade);

    newStudent.print();

}