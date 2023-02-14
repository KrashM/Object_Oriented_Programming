#include "Student.h"
#include <iostream>

using std::cout;

void Student::initStudent(unsigned fn, unsigned year, float grade){

    this->fn = fn;
    this->year = year;
    this->grade = grade;

}

void Student::print(){

    cout << "Facluty number: " << fn << "\nYear of studying: " << year << "\nGrade: " << grade << '\n';

}