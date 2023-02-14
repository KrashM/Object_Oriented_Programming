#include "Date.hpp"
#include <iostream>

void Date::copy(const Date &other){

    this -> day = other.day;
    this -> mounth = other.mounth;
    this -> year = other.year;

}

Date::Date(): day(0), mounth(0), year(0){}
Date::Date(unsigned short day, unsigned short mounth, unsigned short year): day(day), mounth(mounth), year(year){}
Date::Date(const Date &other){ copy(other); }

Date &Date::operator =(const Date &other){

    if(this != &other) copy(other);
    return *this;

}

bool operator >(const Date &lhs, const Date &rhs){ return lhs.getYear() > rhs.getYear() && lhs.getMounth() > rhs.getMounth() && lhs.getDay() > rhs.getDay(); }

ostream &operator <<(ostream &os, const Date &obj){

    os << obj.toString();
    return os;

}

istream &operator >>(istream &is, Date &obj){

    char separator;

    is >> obj.day >> obj.mounth >> obj.year;
    return is;

}

void Date::setDay(unsigned short day){ this -> day = day; }
void Date::setMounth(unsigned short mounth){ this -> mounth = mounth; }
void Date::setYear(unsigned short year){ this -> year = year; }

unsigned short Date::getDay() const{ return this -> day; }
unsigned short Date::getMounth() const{ return this -> mounth; }
unsigned short Date::getYear() const{ return this -> year; }

unsigned short pow(unsigned short n, unsigned char power){ return !power ? 1 : pow(n, power - 1) * n; }
unsigned short digitsInYear(unsigned short year){

    if(!year) return 1;
    unsigned short digits = 0;
    do ++digits; while(year /= 10);
    return digits;

}

const char *Date::toString() const{

    char *result = new char[12];
    result[0] = '\0';

    result[0] = '0' + this -> day / 10;
    result[1] = '0' + this -> day % 10;
    result[2] = ':';
    result[3] = '0' + this -> mounth / 10;
    result[4] = '0' + this -> mounth % 10;
    result[5] = ':';

    unsigned short index = 6;
    unsigned short digits = digitsInYear(this -> year);
    unsigned short powTen = pow(10, digits - 1);
    do result[index++] = '0' + (this -> year / powTen) % 10; while(powTen /= 10);
    result[index] = '\0';

    return result;

}