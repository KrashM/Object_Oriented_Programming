#pragma once

#include <iostream>

using std::istream;
using std::ostream;

class string{

    public:
        string();
        string(const char *);
        string(const size_t);
        string(const string &);
        string(string &&);
        ~string();

        string &operator =(const string &);
        string &operator =(string &&);

        string &operator +=(const char *);
        string &operator +=(const string &);
        string &operator +=(size_t);

        char &operator [](const size_t);
        const char &operator [](const size_t) const;

        size_t length() const;
        const char *c_str() const;

        bool contains(const char) const;
        bool contains(const string &) const;

        int find(const char) const;
        int find(const string &) const;

        string substring(const size_t) const;
        string substring(const size_t, const size_t) const;

        friend ostream &operator <<(ostream &, const string &);
	    friend istream &operator >>(istream &, string &);

        friend bool operator ==(const string &, const string &);
        friend bool operator !=(const string &, const string &);

        friend string operator +(const string &, const string &);

    private:
        size_t size;
        char *str;

        void free();
        void copy(const string &);

};