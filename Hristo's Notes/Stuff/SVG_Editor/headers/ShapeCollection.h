#pragma once

#include "Shape.h"
#include "Vector.h"

class ShapeCollection{

	public:
		ShapeCollection();
		ShapeCollection(const ShapeCollection &);
		~ShapeCollection();

		ShapeCollection& operator=(const ShapeCollection &);

		Shape *operator [](const size_t);
		const Shape *operator [](const size_t) const;

		void addShape(const Shape * const);

		void translateShapes(const double, const double);
		void translateShapeByIndex(const size_t, const double, const double);
		void removeShape(size_t);
		void clear();

		double getPerOfFigureByIndex(const size_t) const;
		double getAreaOfFigureByIndex(const size_t) const;
		double getIfPointInShapeByIndex(const size_t, const double, const double) const;

		size_t size() const;

	private:
		Vector<Shape*> shapes;

        void copy(const ShapeCollection &);
        void free();


};
