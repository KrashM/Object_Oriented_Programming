#include "Date.hpp"

Date::Date(): time(0){}
Date::Date(const time_t time): time(time){ this -> setTime(); }
Date::Date(const Date &other){ this -> copy(other); }

Date &Date::operator =(const Date &other){

    if(this != &other) this -> copy(other);
    return *this;

}

bool isLeapYear(const size_t year){ return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0); }

const char *Date::toString() const{

    char *result = new char[20];

    result[0] = '0' + this -> day / 10;
    result[1] = '0' + this -> day % 10;
    result[2] = '/';
    result[3] = '0' + this -> month / 10;
    result[4] = '0' + this -> month % 10;
    result[5] = '/';
    result[6] = '0' + this -> year / 1000;
    result[7] = '0' + (this -> year / 100) % 10;
    result[8] = '0' + (this -> year / 10) % 10;
    result[9] = '0' + this -> year % 10;
    result[10] = ' ';
    result[11] = '0' + this -> hour / 10;
    result[12] = '0' + this -> hour % 10;
    result[13] = ':';
    result[14] = '0' + this -> minute / 10;
    result[15] = '0' + this -> minute % 10;
    result[16] = ':';
    result[17] = '0' + this -> second / 10;
    result[18] = '0' + this -> second % 10;
    result[19] = '\0';

    return result;

}

const char *Date::logFormatToString() const{

    char *result = new char[9];

    result[0] = '0' + this -> year / 1000;
    result[1] = '0' + (this -> year / 100) % 10;
    result[2] = '0' + (this -> year / 10) % 10;
    result[3] = '0' + this -> year % 10;
    result[4] = '0' + this -> month / 10;
    result[5] = '0' + this -> month % 10;
    result[6] = '0' + this -> day / 10;
    result[7] = '0' + this -> day % 10;
    result[8] = '\0';

    return result;

}

void Date::copy(const Date &other){
    
    this -> time = other.time;
    this -> year = other.year;
    this -> month = other.month;
    this -> day = other.day;
    this -> hour = other.hour;
    this -> minute = other.minute;
    this -> second = other.second;

}

void Date::setTime(){

    this -> year = 1970;
    this -> month = 0;
    
    const u_int secondsInDay = 24 * 60 * 60;
    const u_short secondsInHour = 60 * 60;
    u_short daysOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    size_t daysTillNow = this -> time / secondsInDay;
    size_t extraTime = this -> time % secondsInDay + 3 * secondsInHour;

    while(daysTillNow >= 365){

        daysTillNow -= isLeapYear(this -> year) ? 366 : 365;
        this -> year++;

    }

    s_int extraDays = daysTillNow + 1;
    bool flag = isLeapYear(this -> year);
    daysOfMonth[1] = flag ? daysOfMonth[1] + 1 : daysOfMonth[1];

    size_t index = 0;
    while(extraDays - daysOfMonth[index] >= 0){

        extraDays -= daysOfMonth[index];
        this -> month++;
        index++;

    }

    if(extraDays > 0){

        this -> month++;
        this -> day = extraDays;

    }
    else if(this -> month == 2 && flag) this -> day = 29;
        else this -> day = daysOfMonth[this -> month - 1];


    this -> hour = extraTime / secondsInHour % 24;
    this -> minute = (extraTime % secondsInHour) / 60;
    this -> second = (extraTime % secondsInHour) % 60;

}