#pragma once

#include "SimpleDefn.h"
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::setw;

class ParamDefn: public SimpleDefn{

    public:
        ParamDefn(const char *, const char *);

        void print();
        void insert(const size_t, const size_t, const char *);

    private:
        bool valueIsValid(const char *) override;
    
};