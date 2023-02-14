#include <cmath>
#include "../headers/Point.h"

point::point(): x(0), y(0) {}
point::point(double x, double y): x(x), y(y){}
point::point(const point &other): x(other.x), y(other.y){}

double point::getDist(const point &other) const{

    double dx = this -> x - other.x;
    double dy = this -> y - other.y;

    return sqrt(dx * dx + dy * dy);

}