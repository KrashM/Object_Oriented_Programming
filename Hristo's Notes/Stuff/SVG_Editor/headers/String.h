#pragma once

#include <iostream>

using std::istream;
using std::ostream;

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
        String &operator +=(const char);
        String &operator +=(const char *);
        String &operator +=(const String &);
        String &operator +=(const size_t);
        String &operator +=(const double);
        char &operator [](const size_t);
        const char &operator [](const size_t) const;

        size_t length() const;
        const char *c_str() const;
        bool contains(const char) const;
        bool contains(const char *) const;
        bool contains(const String &) const;
        int find(const char) const;
        int find(const char *) const;
        int find(const String &) const;
        String substring(const size_t) const;
        String substring(const size_t, const size_t) const;

        friend ostream &operator <<(ostream &, const String &);
	    friend istream &operator >>(istream &, String &);

        friend bool operator ==(const String &, const String &);
        friend bool operator ==(const String &, const char *);
        friend bool operator !=(const String &, const String &);
        friend bool operator !=(const String &, const char *);

        friend String operator +(const String &, const String &);

    private:
        size_t size;
        char *str;

        void free();
        void copy(const String &);

};