#ifndef GROUP
#define GROUP
#include "Student.h"

struct Group{
    
    Student students[20];
    unsigned size;
    float grade;

    void initGroup(Student students[], unsigned lenght);

};


#endif