#include "Grade.h"
#include "../../../../includes/Converter.h"
#include <cstring>

Grade::Grade(){

    this -> subject = Subject();
    this -> grade = 0;

}

Grade::Grade(const Subject subject, const short grade){

    this -> subject = subject;
    this -> grade = grade;

}

Grade::Grade(const Grade &other){

    this -> subject = other.subject;
    this -> grade = other.grade;

}

Grade &Grade::operator =(const Grade &other){

    if(this != &other){

        this -> subject = other.subject;
        this -> grade = other.grade;

    }

    return *this;

}

const char *Grade::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    strcat(result, "Subject: ");
    strcat(result, this -> subject.getName());
    strcat(result, " ---> ");

    strcat(result, "Grade: ");
    strcat(result, Converter::intToString(this -> grade));
    
    return result;
}