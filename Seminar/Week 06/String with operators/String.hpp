#pragma once

#include <iostream>
#include <cstddef>

using std::size_t;
using std::istream;
using std::ostream;

class String{

    public:
        String();
        String(char const *);
        String(String const &);
        ~String();

        String &operator =(String const &);

        String &operator +=(String const &);
        String &operator +=(char const *);
        char &operator [](size_t const);
        char const operator [](size_t const) const;

        friend ostream &operator <<(ostream &, String const &);
        friend istream &operator >>(istream &, String &);

        friend String operator +(String const &, String const &);
        friend String operator +(String const &, char const *);
        friend String operator +(char const *, String const &);

        char const *c_str() const;
        size_t length() const;

    private:
        void free();
        void copyFrom(String const &);

        char *str;

};