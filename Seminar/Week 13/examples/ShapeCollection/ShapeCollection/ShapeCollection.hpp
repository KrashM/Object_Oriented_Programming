#pragma once
#include "../Shapes/Shape.hpp"

class ShapeCollection{

public:
	ShapeCollection();
	ShapeCollection(ShapeCollection const &);
	ShapeCollection &operator =(ShapeCollection const &);
	~ShapeCollection();

	Shape const * const operator [](std::size_t const) const;

	void addCircle(int const, int const, int const);
	void addRectangle(int const, int const, int const, int const);
	void addTriangle(int const, int const, int const, int const, int const, int const);

	double getPerOfFigureByIndex(std::size_t const) const;
	double getAreaOfFigureByIndex(std::size_t const) const;
	double getIfPointInShapeByIndex(std::size_t const, int const,int const) const;

private:
	void addShape(Shape * const shape);
	void resize();
	void copy(ShapeCollection const &);
	void free();

private:
	std::size_t size, capacity;
	Shape **shapes;

};