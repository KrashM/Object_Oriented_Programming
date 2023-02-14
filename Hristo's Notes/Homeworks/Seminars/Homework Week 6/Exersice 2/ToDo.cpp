#include "ToDo.h"
#include "../../../Converter.h"
#include <cstring>

ToDo::ToDo(){

    this -> id = 0;
    this -> description = new char[1];
    this -> description[0] = '\0';
    this -> isDone = false;

}

ToDo::ToDo(const int id, const char *description, const bool isDone){

    this -> id = id;
    this -> description = new char[strlen(description) + 1];
    strcpy(this -> description, description);
    this -> isDone = isDone;

}

ToDo::ToDo(const ToDo &other){

    this -> id = other.id;
    this -> description = new char[strlen(other.description) + 1];
    strcpy(this -> description, other.description);
    this -> isDone = other.isDone;

}

ToDo::~ToDo(){

    delete[] this -> description;

}

const ToDo& ToDo::operator =(const ToDo &other){

    if(this != &other){

        this -> id = other.id;
        this -> isDone = other.isDone;
        this -> description = new char[strlen(other.description) + 1];
        strcpy(this -> description, other.description);

    }
    return *this;

}

void ToDo::markAsDone(){ this -> isDone = true; }

const char *ToDo::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    strcat(result, "Id: ");
    strcat(result, Converter::intToString(this -> id));
    strcat(result, "\nDescription:\n");
    strcat(result, this -> description);
    strcat(result, "\nDone: ");
    strcat(result, (this -> isDone ? "Yes" : "No"));

    return result;

}