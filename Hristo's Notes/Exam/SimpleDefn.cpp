#include "SimpleDefn.h"

SimpleDefn::SimpleDefn(): varName(new char[1]), varValue(new char[1]){
    
    this -> varName[0] = '\0';
    this -> varValue[0] = '\0';
    
}
SimpleDefn::SimpleDefn(const char *varName, const char *varValue){

    if(!nameIsValid(varName)) throw invalid_argument("Variable name is incorrect");

    this -> varName = new char[strlen(varName) + 1];
    this -> varValue = new char[strlen(varValue) + 1];

    strcpy(this -> varName, varName);
    strcpy(this -> varValue, varValue);

}
SimpleDefn::SimpleDefn(const SimpleDefn &other){ this -> copy(other); }
SimpleDefn::SimpleDefn(SimpleDefn &&other){

    this -> varName = new char[strlen(other.varName) + 1];
    this -> varValue = new char[strlen(other.varValue) + 1];

    strcpy(this -> varName, other.varName);
    strcpy(this -> varValue, other.varValue);

    other.varName = nullptr;
    other.varValue = nullptr;

}
SimpleDefn::~SimpleDefn(){ this -> free(); }

SimpleDefn &SimpleDefn::operator =(const SimpleDefn &other){

    if(this != &other){

        this -> free();
        this -> copy(other);

    }

    return *this;

}
SimpleDefn &SimpleDefn::operator =(SimpleDefn &&other){

    if(this != &other){

        this -> free();

        this -> varName = new char[strlen(other.varName) + 1];
        this -> varValue = new char[strlen(other.varValue) + 1];

        strcpy(this -> varName, other.varName);
        strcpy(this -> varValue, other.varValue);

        other.varName = nullptr;
        other.varValue = nullptr;

    }

    return *this;

}

void SimpleDefn::copy(const SimpleDefn &other){

    this -> varName = other.varName;
    this -> varValue = other.varValue;

}

void SimpleDefn::free(){

    delete[] this -> varName;
    delete[] this -> varValue;

}

bool SimpleDefn::nameIsValid(const char *name){

    size_t size = strlen(name);
    for(size_t i = 0; i < size; i++)
        if(!((name[i] >= 'a' && name[i] <= 'z') || name[i] == '_')) return false;
    return true;

}

bool SimpleDefn::valueIsValid(const char *){ return true; }