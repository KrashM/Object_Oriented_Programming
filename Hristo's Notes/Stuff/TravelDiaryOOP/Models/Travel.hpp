#pragma once

#include "Date.hpp"
#include "StringChecker.hpp"
#include "InvalidFormatException.hpp"
#include "Vector.hpp"

using std::ifstream;
using std::ofstream;
using std::ios;

class Travel{

    private:
        char *destination, *comment, *photos;
        Date from, to;
        unsigned char grade;

        void erase();
        void copy(const Travel &);

    public:
        Travel();
        Travel(const char *, const Date &, const Date &, const unsigned char, const char *, const char *);
        Travel(const Travel &);
        ~Travel();

        Travel &operator =(const Travel &);
        friend ostream &operator <<(ostream &, const Travel &);

        void write(ofstream &) const;
        void read(ifstream &);

        void setDestination(const char *);
        void setFromDate(const Date &);
        void setToDate(const Date &);
        void setGrade(const unsigned short);
        void setComment(const char *);
        void setPhotos(const char *);

        char *getDestination() const;
        Date getFromDate() const;
        Date getToDate() const;
        unsigned char getGrade() const;
        char *getComment() const;
        char * getPhotos() const;

};