#pragma once

#include "Shape.h"

class Circle: public Shape{

	public:
		Circle();
		Circle(const Circle &);
		Circle(const double, const double, const double, const String &);
		double getArea() const override;
		double getPer() const override;
		bool isPointIn(const double, const double) const override;
		Shape* clone() const override;
		String toString() const override;
		void serialize(ostream &) const override;
		void deserialize(istream &) override;

		bool isInsideRectangle(const double, const double, const double, const double) const override;
		bool isInsideCircle(const double, const double, const double) const override;
	
	private:
		double radius;

};