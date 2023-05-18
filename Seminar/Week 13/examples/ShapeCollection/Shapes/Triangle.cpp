#include "Triangle.hpp"
#include <limits>
#include <iostream>

Triangle::Triangle(int const x1, int const y1, int const x2, int const y2, int const x3, int const y3): Shape(3){

	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);

}

double Triangle::getArea() const{

	Shape::point p1 = getPointAtIndex(0);
	Shape::point p2 = getPointAtIndex(1);
	Shape::point p3 = getPointAtIndex(2);

	return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x) / 2.00;

}

double Triangle::getPer() const{

	Shape::point p1 = getPointAtIndex(0);
	Shape::point p2 = getPointAtIndex(1);
	Shape::point p3 = getPointAtIndex(2);

	return p1.getDist(p2) + p2.getDist(p3) + p3.getDist(p1);

}

bool Triangle::intersectsWith(Shape const *other) const{
	other -> intersectsWithTriangle(this);
}

bool Triangle::intersectsWithCircle(Shape const *) const{

	std::cout << "Intersect with circle\n";
	return true;

}

bool Triangle::intersectsWithTriangle(Shape const *) const{


	std::cout << "Intersect with triangle\n";
	return true;

}

bool Triangle::intersectsWithRectangle(Shape const *) const{


	std::cout << "Intersect with rectangle\n";
	return true;

}

bool Triangle::isPointIn(int const x, int const y) const{

	Shape::point p(x, y);

	Triangle t1(getPointAtIndex(0).x, getPointAtIndex(0).y, getPointAtIndex(1).x, getPointAtIndex(1).y, p.x, p.y);
	Triangle t2(getPointAtIndex(2).x, getPointAtIndex(2).y, getPointAtIndex(1).x, getPointAtIndex(1).y, p.x, p.y);
	Triangle t3(getPointAtIndex(2).x, getPointAtIndex(2).y, getPointAtIndex(0).x, getPointAtIndex(0).y, p.x, p.y);

	return abs(t1.getArea() + t2.getArea() + t3.getArea() - getArea()) <= std::numeric_limits<double>::epsilon();


}


Shape *Triangle::clone() const{
	return new Triangle(*this);
}

