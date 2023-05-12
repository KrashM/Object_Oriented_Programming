#include "Circle.hpp"

const double PI = 3.1415;
Circle::Circle(int const x, int const y, double const radius) : Shape(1), radius(radius){
	setPoint(0, x, y);
}

double Circle::getArea() const{
	return PI * radius * radius;
}

double Circle::getPer() const{
	return 2 * PI * radius;
}

bool Circle::isPointIn(int const x, int const y) const{

	Shape::point p(x, y);
	return p.getDist(getPointAtIndex(0)) <= radius;

}

Shape *Circle::clone() const{
	return new Circle(*this);
}
