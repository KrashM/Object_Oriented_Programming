#pragma once

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../utils/doctest.h"

#include <cstdint>
#include <fstream>

using std::ostream;
using std::ifstream;
using std::ofstream;

enum class Position{

    JUNIOR_DEV,
    DEV,
    SENIOR_DEV,
    QA,
    MANAGER

};

class Developer{

    public:
        Developer();
        Developer(char const * const, char const * const, Position const);
        Developer(Developer const &);
        ~Developer();

        Developer &operator =(Developer const &);

        ofstream &save(ofstream &) const;
        ifstream &load(ifstream &);
        void addManager(Developer const &);

    #ifdef DOCTEST_LIBRARY_INCLUDED
        uint16_t getId() const;
    #endif

        friend ostream &operator <<(ostream &, Developer const &);

    private:
        void copyFrom(Developer const &);
        void free();

        char *_firstName, *_lastName;
        Developer *_manager;
        Position _position;
        uint16_t _id;

};