#include "../headers/Rectangle.h"

Rectangle::Rectangle(): Shape(1, "black"), height(0), width(0){ setPoint(0, point()); }
Rectangle::Rectangle(const Rectangle &other): Shape(1, other.getColor()){

	point p = other.getPointAtIndex(0);
	setPoint(0, point(p.x, p.y));

	this -> width = other.width;
	this -> height = other.height;

}
Rectangle::Rectangle(const double x, const double y, const double height, const double width, const String &color): Shape(1, color){

	setPoint(0, point(x, y));
	this -> height = height;
	this -> width = width;

}

double Rectangle::getArea() const{ return this -> width * this -> height; }
double Rectangle::getPer() const{ return 2 * (this -> height + this -> width); }

bool Rectangle::isPointIn(const double x, const double y) const{

	point rectPoint = getPointAtIndex(0);
	return x >= rectPoint.x && x <= rectPoint.x + this -> width &&
		y >= rectPoint.y && y <= rectPoint.y + this -> height;

}

Shape* Rectangle::clone() const{ return new Rectangle(*this); }

void Rectangle::serialize(ostream &os) const{

	point p = getPointAtIndex(0);
	os << "\t<rect x=\"" << p.x << "\" y=\"" << p.y << "\" width=\"" << this -> width << "\" height=\"" << this -> height << "\" fill=\"" << this -> getColor() << "\" />\n";

}

void Rectangle::deserialize(istream &is){

	double x, y;
	String color;

	while(is.get() != '\"');
	is >> x;
	is.ignore();

	while(is.get() != '\"');
	is >> y;
	is.ignore();

	while(is.get() != '\"');
	is >> this -> width;
	is.ignore();

	while(is.get() != '\"');
	is >> this -> height;
	is.ignore();

	while(is.get() != '\"');
	
	size_t i;
	char *inp = new char[2];
	inp[1] = '\0';

	for(i = 0; (inp[0] = is.get()) != '\"'; i++) color += inp;

	delete inp;

	this -> setPoint(0, point(x, y));
	this -> setColor(color);

}

String Rectangle::toString() const{

	point rectPoint = getPointAtIndex(0);
	String result("rectangle x=");

	result += rectPoint.x;
	result += " y=";
	result += rectPoint.y;
	result += " width=";
	result += this -> width;
	result += " height=";
	result += this -> height;
	result += " color=";
	result += this -> getColor();

	return result;

}

bool Rectangle::isInsideRectangle(const double x, const double y, const double width, const double height) const{

	point smallRecPoint = getPointAtIndex(0);

	return smallRecPoint.x >= x && smallRecPoint.x + this -> width <= x + width
		&& smallRecPoint.y >= y && smallRecPoint.y + this -> height <= y + height;

}

bool Rectangle::isInsideCircle(const double x, const double y, const double r) const{

	point recPoint1 = getPointAtIndex(0);
	point recPoint2(recPoint1.x + width, recPoint1.y);
	point recPoint3(recPoint1.x, recPoint1.y + height);
	point recPoint4(recPoint1.x + width, recPoint1.y + height);
	point circlePoint(x, y);

	return circlePoint.getDist(recPoint1) <= r && circlePoint.getDist(recPoint2) <= r
		&& circlePoint.getDist(recPoint3) <= r && circlePoint.getDist(recPoint4) <= r;

}