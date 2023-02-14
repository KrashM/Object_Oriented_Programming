#ifndef QUADRATIC
#define QUADRATIC

#include "complexNumber.h"

struct Quadratic{

    double a, b, c, discriminant;
    complexNumber x1, x2;

    void findRoots();

};


#endif