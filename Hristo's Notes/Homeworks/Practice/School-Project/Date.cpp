#include "Date.h"
#include "../../../../includes/Converter.h"
#include <cstring>

Date::Date(){

    this -> day = 0;
    this -> mounth = 0;
    this -> year = 0;

}

Date::Date(unsigned day, unsigned mounth, unsigned year){

    this -> day = day;
    this -> mounth = mounth;
    this -> year = year;

}

Date::Date(const Date &other){

    this -> day = other.day;
    this -> mounth = other.mounth;
    this -> year = other.year;
    
}

const Date &Date::operator =(const Date &other){

    if(this != &other){

        this -> day = other.day;
        this -> mounth = other.mounth;
        this -> year = other.year;

    }

    return *this;

}

const char *Date::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    strcat(result, Converter::intToString(this -> day));
    strcat(result, ".");
    strcat(result, Converter::intToString(this -> mounth));
    strcat(result, ".");
    strcat(result, Converter::intToString(this -> year));

    return result;

}