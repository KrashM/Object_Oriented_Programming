#include "Line.h"

Line::Line(){

    Point a(0, 0), b(0, 1);
    this -> a = a;
    this -> b = b;

}

Line::Line(const Point &a, const Point &b){

    this -> a = a;
    this -> b = b;

}

double Line::getLength(){ return Point::distance(this -> a, this -> b); }