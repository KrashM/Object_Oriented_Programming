#pragma once
#include "Shape.hpp"

class Circle: public Shape{

public:
	Circle(int const, int const, double radiuconst);

	double getArea() const override;
	double getPer() const override;
	bool intersectsWith(Shape const *) const override;
	bool intersectsWithCircle(Shape const *) const override;
	bool intersectsWithTriangle(Shape const *) const override;
	bool intersectsWithRectangle(Shape const *) const override;
	bool isPointIn(int const, int const) const override;
	Shape* clone() const override;

private:
	double radius;

};