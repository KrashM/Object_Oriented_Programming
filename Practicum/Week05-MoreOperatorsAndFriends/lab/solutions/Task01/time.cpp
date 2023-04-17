#include "time.h"
#include <cassert>
#include <iostream>

Time::Time(unsigned int hours, unsigned int minutes)
{
    assert(hours < 60 && minutes < 60);  

    this->hours = hours;
    this->minutes = minutes;  
}

Time::Time() : Time(0, 0) {}

Time Time::operator + (const Time& other) const
{
    Time result = *this;

    result += other;

    return result;
}

Time& Time::operator += (const Time& other)
{
    this->hours += other.hours;
    this->minutes += other.minutes;

    this->hours += (this->minutes / 60);
    this->minutes %= 60;

    this->hours %= 24;

    return *this;
}

Time Time::operator + (unsigned int hours) const
{
    return *this + Time(hours, 0);
}

Time operator + (unsigned int hours, const Time& time)
{
    return time + hours;
}

Time& Time::operator ++ ()
{
    *this = *this + 1;

    return *this;
}

Time Time::operator ++ (int)
{
    Time old = *this;

    ++(*this);

    return old;
}

bool Time::operator < (const Time& other) const
{
    return this->hours < other.hours || 
    (this->hours == other.hours && this->minutes < other.minutes);
}

std::ostream& operator << (std::ostream& out, const Time& time)
{
    out << time.hours << "." << time.minutes;

    return out;
}