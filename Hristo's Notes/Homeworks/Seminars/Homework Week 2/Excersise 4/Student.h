#ifndef STUDENT
#define STUDENT

struct Student{

    float grade;
    unsigned fn, year;

    void initStudent(unsigned fn, unsigned year, float grade);
    void print();

};


#endif