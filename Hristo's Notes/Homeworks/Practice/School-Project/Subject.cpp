#include "Subject.h"
#include <cstring>

Subject::Subject(){

    this -> name = new char[1];
    this -> name[0] = '\0';
    this -> description = new char[1];
    this -> description[0] = '\0';

}

Subject::Subject(const char *name, const char *description){

    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
    this -> description = new char[strlen(description) + 1];
    strcpy(this -> description, description);

}

Subject::Subject(const Subject &other){

    this -> name = new char[strlen(other.name) + 1];
    strcpy(this -> name, other.name);
    this -> description = new char[strlen(other.description) + 1];
    strcpy(this -> description, other.description);

}

const Subject& Subject::operator =(const Subject &other){

    if(this != &other){
        
        this -> name = new char[strlen(other.name) + 1];
        strcpy(this -> name, other.name);
        this -> description = new char[strlen(other.description) + 1];
        strcpy(this -> description, other.description);

    }

    return *this;
}


Subject::~Subject(){

    delete[] this -> name;
    delete[] this -> description;

}

const char *Subject::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    strcat(result, "Name: ");
    strcat(result, this -> name);
    strcat(result, "\n");

    strcat(result, "Description: ");
    strcat(result, this -> description);
    
    return result;
    
}

const char *Subject::getName() const{ return this -> name; }