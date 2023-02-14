#pragma once

#include "ISerializable.h"
#include "Point.h"
#include "String.h"

class Shape: public ISerializable{

	public:
		Shape(size_t, const String &);
		Shape(const Shape &);
		virtual ~Shape();

		Shape& operator=(const Shape &);

		void translate(double, double);
		String getColor() const;

		virtual double getArea() const = 0;
		virtual double getPer()  const = 0;
		virtual bool isPointIn(const double, const double) const = 0;
		virtual Shape* clone() const = 0;
		virtual String toString() const = 0;
		virtual bool isInsideRectangle(const double, const double, const double, const double) const = 0;
		virtual bool isInsideCircle(const double, const double, const double) const = 0;

	protected:
		const point& getPointAtIndex(size_t) const;
		void setPoint(size_t, const point &);
		void setColor(const String &);

	private: 
		point* points;
		size_t pointsCount;
		String color;

		void copy(const Shape &);
		void free();

};
