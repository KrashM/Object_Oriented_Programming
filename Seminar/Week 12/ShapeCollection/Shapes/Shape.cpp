#include "Shape.hpp"

Shape::Shape(std::size_t const pointsCount): pointsCount(pointsCount), points(new point[pointsCount]){}

Shape::Shape(Shape const &other){
	copy(other);
}

Shape &Shape::operator =(Shape const &other){

	if(this == &other) return *this;

	free();
	copy(other);

	return *this;

}

Shape::~Shape(){
	free();
}

Shape::point const &Shape::getPointAtIndex(std::size_t const index) const{

	if(index >= pointsCount) throw std::out_of_range("Invalid point index!");
	return  points[index];

}

void Shape::setPoint(std::size_t const pointIndex, int const x, int const y){

	if(pointIndex >= pointsCount) throw std::out_of_range("Invalid point index!");
	points[pointIndex] = point(x, y);

}

Shape::point::point(): x(0), y(0){}

Shape::point::point(int const x, int const y): x(x), y(y){}

double Shape::point::getDist(point const &other) const{

	int dx = x - other.x;
	int dy = y - other.y;

	return sqrt(dx * dx + dy * dy);

}

void Shape::copy(Shape const &other){

	points = new point[other.pointsCount];

	for(std::size_t i = 0; i < other.pointsCount; i++)
		points[i] = other.points[i];

	pointsCount = other.pointsCount;

}

void Shape::free(){
	delete[] points;
}