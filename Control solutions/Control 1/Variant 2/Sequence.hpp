#pragma once

#include <iostream>
#include "Vector.hpp"

using std::ostream;

class Sequence{

    public:
        Sequence(); // 10т.
        Sequence(Sequence const &); // 10т.
        ~Sequence(); // 5т.

        Sequence &operator =(Sequence const &); // 10т.

        void addVector(Vector const &); // 15т.

        friend ostream &operator <<(ostream &, Sequence const &); // 15т.

    private:
        void resize(size_t const);
        void copyFrom(Sequence const &);
        void free();

        size_t _capacity, _size;
        double *_v;

};