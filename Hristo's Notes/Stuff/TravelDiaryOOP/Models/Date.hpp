#pragma once

#include <fstream>

using std::istream;
using std::ostream;

class Date{

    private:
        unsigned short year, day, mounth;

        void copy(const Date &);

    public:
        Date();
        Date(unsigned short, unsigned short, unsigned short);
        Date(const Date &);

        Date &operator =(const Date &);
        friend bool operator >(const Date &, const Date &);
        friend ostream &operator <<(ostream &, const Date &);
        friend istream &operator >>(istream &, Date &);

        void setDay(unsigned short);
        void setMounth(unsigned short);
        void setYear(unsigned short);

        unsigned short getDay() const;
        unsigned short getMounth() const;
        unsigned short getYear() const;

        const char *toString() const;

};