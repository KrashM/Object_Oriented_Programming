#include "Rectangle.hpp"

Rectangle::Rectangle(int const x1, int const y1, int const x3, int const y3) : Shape(4){

	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y3);
	setPoint(3, x3, y1);

}

double Rectangle::getArea() const{

	Shape::point p0 = getPointAtIndex(0);
	Shape::point p1 = getPointAtIndex(1);
	Shape::point p3 = getPointAtIndex(3);

	return p0.getDist(p1) * p0.getDist(p3);

}

double Rectangle::getPer() const{

	Shape::point p0 = getPointAtIndex(0);
	Shape::point p1 = getPointAtIndex(1);
	Shape::point p3 = getPointAtIndex(3);

	return 2 * (p0.getDist(p1) + p0.getDist(p3));

}


bool Rectangle::isPointIn(int const x, int const y) const{

	Shape::point p(x, y);
	return p.x >= getPointAtIndex(0).x && p.y >= getPointAtIndex(1).x &&
		p.y <= getPointAtIndex(0).y && p.y >= getPointAtIndex(2).y;

}

Shape *Rectangle::clone() const{
	return new Rectangle(*this);
}

