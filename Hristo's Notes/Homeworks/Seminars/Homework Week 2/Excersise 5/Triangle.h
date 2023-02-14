#ifndef TRIANGLE
#define TRIANGLE

#include "Point.h"

struct Triangle{

    Point A, B, C;
    double AB, AC, BC, perimeter, area;

    double findEdges();
    double findPerimeter();
    double findArea();

    void initTriangle();
    
    void print();

};


#endif