#include "../headers/ShapeCollection.h"
#include <stdexcept>

ShapeCollection::ShapeCollection(){}
ShapeCollection::ShapeCollection(const ShapeCollection& other){ this -> copy(other); }
ShapeCollection::~ShapeCollection(){ this -> free(); }

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other){
	
    if(this != &other){

		this -> free();
		this -> copy(other);
	
    }

	return *this;

}

void ShapeCollection::addShape(const Shape * const shape){ this -> shapes.pushBack(shape -> clone()); }

void ShapeCollection::removeShape(size_t index){ delete this -> shapes.removeAt(index); }

void ShapeCollection::clear(){

	size_t numOfElements = this -> shapes.size();

	for(int i = 0; i < numOfElements; i++)
		delete this -> shapes.popBack();

}

void ShapeCollection::translateShapes(const double x, const double y){

	for(size_t i = 0; i < this -> shapes.size(); i++)
        shapes[i] -> translate(x, y);

}

void ShapeCollection::translateShapeByIndex(const size_t index, const double x, const double y){ shapes[index] -> translate(x, y); }

double ShapeCollection::getPerOfFigureByIndex(const size_t ind) const{ return shapes[ind] -> getPer(); }
double ShapeCollection::getAreaOfFigureByIndex(const size_t ind) const{ return shapes[ind]->getArea(); }
double ShapeCollection::getIfPointInShapeByIndex(const size_t ind, const double x, const double y) const{ return shapes[ind] -> isPointIn(x, y); }

size_t ShapeCollection::size() const{ return this -> shapes.size(); }

Shape *ShapeCollection::operator [](const size_t index){ return this -> shapes[index]; }
const Shape *ShapeCollection::operator [](const size_t index) const{ return this -> shapes[index]; }

void ShapeCollection::free(){

	for (size_t i = 0; i < this -> shapes.size(); i++)
		delete shapes[i];

}

void ShapeCollection::copy(const ShapeCollection& other){

    this -> shapes = other.shapes;

	for (size_t i = 0; i < other.shapes.size(); i++)
        this -> shapes[i] = other.shapes[i]->clone();

}