#include "../headers/Line.h"

Line::Line(): Shape(2, "black"){

	this -> setPoint(0, point());
	this -> setPoint(1, point());

}
Line::Line(const double x1, const double y1, const double x2, const double y2, const String &color): Shape(2, color){

	this -> setPoint(0, point(x1, y1));
	this -> setPoint(1, point(x2, y2));

}

Line::Line(const Line &other): Shape(2, other.getColor()){

	this -> setPoint(0, other.getPointAtIndex(0));
	this -> setPoint(1, other.getPointAtIndex(1));

}

double Line::getPer() const{ return this -> getPointAtIndex(0).getDist(this -> getPointAtIndex(1)); }
double Line:: getArea() const{ return 0; }

bool Line::isPointIn(const double x, const double y) const{

	point p(x, y);
	
	point p1 = getPointAtIndex(0);
	point p2 = getPointAtIndex(1);

	return p.getDist(p1) + p.getDist(p2) == p1.getDist(p2);

}

Shape* Line:: clone() const{ return new Line(*this); }

void Line::serialize(ostream &os) const{

	point p1 = getPointAtIndex(0);
	point p2 = getPointAtIndex(1);
	os << "\t<line x1=\"" << p1.x << "\" y1=\"" << p1.y << "\" x2=\"" << p2.x << "\" y2=\"" << p2.y << "\" stroke=\"" << this -> getColor() << "\" stroke-width=\"5\" />\n";

}

void Line::deserialize(istream &is){

	size_t x1, y1, x2, y2;
	String color;
	char character;

	while(is.get() != '\"');
	is >> x1;
	is.ignore();

	while(is.get() != '\"');
	is >> y1;
	is.ignore();

	while(is.get() != '\"');
	is >> x2;
	is.ignore();


	while(is.get() != '\"');
	is >> y2;
	is.ignore();

	while(is.get() != '\"');
	while((character = is.get()) != '\"') color += character;

	this -> setPoint(0, point(x1, y1));
	this -> setPoint(1, point(x2, y2));
	this -> setColor(color);

}

String Line::toString() const{

	point p1 = getPointAtIndex(0);
	point p2 = getPointAtIndex(1);
	String result("line x1=");

	result += p1.x;
	result += " y1=";
	result += p1.y;
	result += " x2=";
	result += p2.x;
	result += " y2=";
	result += p2.y;
	result += " color=";
	result += this -> getColor();
	
	return result;

}


bool Line::isInsideRectangle(const double x, const double y, const double width, const double height) const{

	point A = getPointAtIndex(0);
	point B = getPointAtIndex(1);

	point rectPoint1(x, y);
	point rectPoint4(x + width, y + height);

	return A.x >= rectPoint1.x && A.x <= rectPoint4.x && B.x >= rectPoint1.x && B.x <= rectPoint4.x
		&& A.y >= rectPoint4.y && A.y <= rectPoint1.y && B.y >= rectPoint4.y && B.y <= rectPoint1.y;

}

bool Line::isInsideCircle(const double x, const double y, const double r) const{

	point center = getPointAtIndex(0);
	point A = getPointAtIndex(0);
	point B = getPointAtIndex(1);

	return center.getDist(A) <= r && center.getDist(B) <= r;
	

}