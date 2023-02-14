#include "Point.h"
#include <cmath>

Point::Point(){ this -> x = 0; this -> y = 0; }
Point::Point(int x, int y){ this -> x = x; this -> y = y; }
int Point::getX(){ return this -> x; }
int Point::getY(){ return this -> y; }
double Point::distance(const Point &a, const Point &b){ return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }