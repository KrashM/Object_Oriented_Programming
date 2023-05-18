#include "Circle.hpp"
#include <iostream>

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

bool Circle::intersectsWith(Shape const *other) const{
	other -> intersectsWithCircle(this);
}

bool Circle::intersectsWithCircle(Shape const *) const{

	std::cout << "Intersect with circle\n";
	return true;

}

bool Circle::intersectsWithTriangle(Shape const *) const{


	std::cout << "Intersect with triangle\n";
	return true;

}

bool Circle::intersectsWithRectangle(Shape const *) const{


	std::cout << "Intersect with rectangle\n";
	return true;

}


bool Circle::isPointIn(int const x, int const y) const{

	Shape::point p(x, y);
	return p.getDist(getPointAtIndex(0)) <= radius;

}

Shape *Circle::clone() const{
	return new Circle(*this);
}
