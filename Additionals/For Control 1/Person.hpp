#pragma once

#include <iostream>
#include <cstring>
#include <cassert>
#include <new>

using std::ostream;
using std::nothrow;

class Person{

    public:
        Person() = delete;
        Person(char const *, unsigned const, unsigned const);
        Person(Person const &);
        ~Person();

        Person &operator =(Person const &);

        void setName(char const * const);
        void setAge(unsigned const);
        void setFN(unsigned const);

        char const *getName() const;
        unsigned const getAge() const;
        unsigned const getFN() const;

        friend ostream &operator <<(ostream &, Person const &);

    private:
        void copyFrom(Person const &);
        void free();

        char *name;
        unsigned age;
        unsigned fn;

};