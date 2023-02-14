#pragma once

#include "Includes.hpp"

class String{

    public:
        String();
        String(const char *);
        String(const size_t);
        String(const String &);
        String(String &&);
        ~String();
        String &operator =(const String &);
        String &operator =(String &&);
        String &operator +=(const char *);
        String &operator +=(const String &);
        String &operator +=(size_t);
        char &operator [](const size_t);
        const char &operator [](const size_t) const;

        size_t length() const;
        const char *c_str() const;

        friend ostream &operator <<(ostream &, const String &);
	    friend istream &operator >>(istream &, String &);

        friend bool operator ==(const String &, const String &);
        friend bool operator !=(const String &, const String &);

        friend constexpr String &operator +(const String &, const String &);

    private:
        size_t size;
        char *str;

        void free();
        void copy(const String &);

};