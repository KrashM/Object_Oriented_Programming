#include "../headers/Shape.h"
#include <stdexcept>

using std::out_of_range;

Shape::Shape(size_t pointsCount, const String &color): pointsCount(pointsCount), color(color){ points = new point[pointsCount]; }
Shape::Shape(const Shape& other){ this -> copy(other); }
Shape::~Shape(){ this -> free(); }

Shape& Shape::operator =(const Shape& other){
	
	if(this != &other){

		free();
		copy(other);
	
	}
	
	return *this;

}

const point &Shape::getPointAtIndex(size_t index) const{

	if (index >= pointsCount) throw out_of_range("Get point: index out of range");
	return  points[index];

}

void Shape::setPoint(size_t pointIndex, const point &p){

	if (pointIndex >= pointsCount) throw out_of_range("Set point: index out of range");
	points[pointIndex] = p;

}

String Shape::getColor() const{ return color; }

void Shape::setColor(const String &color){ this -> color = String(color); }

void Shape::translate(double xt, double yt){

	for (size_t i = 0; i < pointsCount; i++){

		points[i].x += xt;
		points[i].y += yt;
	
	}
	
}

void Shape::copy(const Shape& other){

	points = new point[other.pointsCount];

	for(int i = 0; i < other.pointsCount; i++) points[i] = other.points[i];
	pointsCount = other.pointsCount;

}

void Shape::free(){ delete[] points; }