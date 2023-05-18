#pragma once
#include <stdexcept>
#include <cstddef>
#include <cmath>

class Shape{

public:
	Shape(std::size_t);
	Shape(Shape const &);
	virtual ~Shape(); //!!!!!!

	Shape &operator =(Shape const &);

	void setPoint(std::size_t const, int const, int const);

	virtual double getArea() const = 0;
	virtual double getPer()  const = 0;
	virtual bool intersectsWith(Shape const *) const = 0;
	virtual bool intersectsWithCircle(Shape const *) const = 0;
	virtual bool intersectsWithTriangle(Shape const *) const = 0;
	virtual bool intersectsWithRectangle(Shape const *) const = 0;
	virtual bool isPointIn(int const, int const) const = 0;
	virtual Shape *clone() const = 0; //!!!

protected:
	struct point{

		point();
		point(int const, int const);

		double getDist(point const &) const;

		int x;
		int y;

	};

	point const &getPointAtIndex(std::size_t const) const;

private:
	void copy(Shape const &);
	void free();

private:
	point *points;
	std::size_t pointsCount;

};