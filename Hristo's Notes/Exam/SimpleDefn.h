#pragma once

#include <stdexcept>
#include <cstring>

using std::invalid_argument;

class SimpleDefn{

    public:
        SimpleDefn();
        SimpleDefn(const char *, const char *);
        SimpleDefn(const SimpleDefn &);
        SimpleDefn(SimpleDefn &&);
        ~SimpleDefn();

        SimpleDefn &operator =(const SimpleDefn &);
        SimpleDefn &operator =(SimpleDefn &&);

    protected:
        char *varName, *varValue;

        virtual bool nameIsValid(const char *);
        virtual bool valueIsValid(const char *);

    private:
        void copy(const SimpleDefn &);
        void free();

};