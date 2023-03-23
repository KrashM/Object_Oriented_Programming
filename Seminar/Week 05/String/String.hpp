#pragma once

#include <cstddef>

using std::size_t;

class String{

    public:
        String();
        String(char const *);
        String(String const &);
        ~String();

        String &operator =(String const &);

        char const *c_str() const;
        size_t length() const;

    private:
        void free();
        void copyFrom(String const &);

        char *str;

};