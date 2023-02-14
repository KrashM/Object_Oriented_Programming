#include "Group.h"

void Group::initGroup(Student students[], unsigned size){

    this->size = size;

    for(int i = 0; i < size; i++){

        this->students[i] = students[i];
        grade += students[i].grade;

    }

    grade /= size;

}