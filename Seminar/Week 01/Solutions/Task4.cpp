#include <iostream>

using std::cin;
using std::cout;

struct student{

    int fn, course;
    double grade;

};

struct group{

    student *students;
    size_t size;
    double avgGrade;

};

student initStudent(const int &fn, const int &course, const double &grade){

    student newStudent;

    newStudent.fn = fn;
    newStudent.course = course;
    newStudent.grade = grade;

    return newStudent;

}

void findAverage(group &myGroup){

    for(size_t i = 0; i < myGroup.size; ++i)
        myGroup.avgGrade += myGroup.students[i].grade;
    
    myGroup.avgGrade /= myGroup.size;

}

size_t findMoreThanAvg(const group &myGroup){

    size_t counter = 0;

    for(size_t i = 0; i < myGroup.size; ++i)
        counter += myGroup.students[i].grade >= myGroup.avgGrade;
    
    return counter;

}

int main(){

    group myGroup;
    cin >> myGroup.size;
    myGroup.students = new student[myGroup.size];

    int fn, course;
    double grade;

    for(size_t i = 0; i < myGroup.size; ++i){

        cin >> fn >> course >> grade;
        myGroup.students[i] = initStudent(fn, course, grade);

    }
    
    cin >> grade;

    findAverage(myGroup);

    cout << myGroup.avgGrade << ' ' << findMoreThanAvg(myGroup) << '\n';

    delete[] myGroup.students;

}