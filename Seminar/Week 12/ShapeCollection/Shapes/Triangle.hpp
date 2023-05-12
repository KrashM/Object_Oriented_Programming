#pragma once

#include "Shape.hpp"

class Triangle: public Shape{

public:
	Triangle(int const, int const, int const, int const, int const, int const);

	double  getArea() const override;
	double getPer() const override;
	bool isPointIn(int const, int const) const override;
	Shape* clone() const override;

};