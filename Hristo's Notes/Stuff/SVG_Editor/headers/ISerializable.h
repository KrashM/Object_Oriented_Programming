#pragma once

#include <iostream>
#include <fstream>

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::cin;
using std::cout;

class ISerializable{

    public:
        virtual void serialize(ostream &) const = 0;
        virtual void deserialize(istream &) = 0;

};