#pragma once
#include "Shape.hpp"

class Rectangle: public Shape{

public:
	Rectangle(int const, int const, int const, int const);

	double getArea() const override;
	double getPer() const override;
	bool intersectsWith(Shape const *) const override;
	bool intersectsWithCircle(Shape const *) const override;
	bool intersectsWithTriangle(Shape const *) const override;
	bool intersectsWithRectangle(Shape const *) const override;
	bool isPointIn(int const, int const) const override;
	Shape* clone() const override;

};