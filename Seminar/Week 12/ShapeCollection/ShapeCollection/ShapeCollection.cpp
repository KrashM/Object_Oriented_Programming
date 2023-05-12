#include "ShapeCollection.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"

ShapeCollection::ShapeCollection(): capacity(4), size(0), shapes(new Shape *[capacity]){}

ShapeCollection::ShapeCollection(ShapeCollection const &other){
	copy(other);
}

ShapeCollection &ShapeCollection::operator =(ShapeCollection const &other){

	if(this == &other) return *this;

	free();
	copy(other);

	return *this;

}

ShapeCollection::~ShapeCollection(){
	free();
}

void ShapeCollection::addShape(Shape * const shape){

	if(size == capacity) resize();
	shapes[size++] = shape -> clone();

}

void ShapeCollection::addRectangle(int const x1, int const y1, int const x3, int const y3){
	addShape(new Rectangle(x1, y1, x3, y3));
}

void ShapeCollection::addCircle(int const x1, int const y1, int const r){
	addShape(new Circle(x1, y1, r));
}

void ShapeCollection::addTriangle(int const x1, int const y1, int const x2, int const y2, int const x3, int const y3){
	addShape(new Triangle(x1, y1,x2,y2, x3, y3));
}

double ShapeCollection::getPerOfFigureByIndex(std::size_t const ind) const{

	if(ind >= size) throw std::out_of_range("Out of range in shapes collection");
	return shapes[ind] -> getPer();

}

double ShapeCollection::getAreaOfFigureByIndex(std::size_t const ind) const{
	
	if(ind >= size) throw std::out_of_range("Out of range in shapes collection");
	return shapes[ind] -> getArea();

}

double ShapeCollection::getIfPointInShapeByIndex(std::size_t const ind, int const x, int const y) const{

	if(ind >= size) throw std::out_of_range("Out of range in shapes collection");
	return shapes[ind] -> isPointIn(x, y);

}

void ShapeCollection::resize(){

	Shape **newCollection = new Shape *[capacity *= 2];

	for(std::size_t i = 0; i < size; i++)
		newCollection[i] = shapes[i];

	delete[] shapes;
	shapes = newCollection;

}

void ShapeCollection::copy(ShapeCollection const &other){

	shapes = new Shape *[other.capacity];
	capacity = other.capacity;
	size = other.size;

	for(std::size_t i = 0; i < size; i++)
		shapes[i] = other.shapes[i] -> clone();

}

void ShapeCollection::free(){

	for(std::size_t i = 0; i < size; i++)
		delete shapes[i];
	delete[] shapes;
	shapes = nullptr;

}