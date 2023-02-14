#pragma once

#include "Includes.hpp"

class Date{

    public:
        Date();
        Date(const time_t);
        Date(const Date &);
        Date &operator =(const Date &);

        const char *toString() const;
        const char *logFormatToString() const;

    private:
        time_t time;
        u_short year, month, day, hour, minute, second;

        void copy(const Date &);
        void setTime();

};