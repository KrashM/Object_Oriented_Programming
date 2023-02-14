#include "../headers/Circle.h"

#define PI 3.1415

Circle::Circle(): Shape(1, "black"), radius(0){ this -> setPoint(0, point()); }
Circle::Circle(const Circle &other): Shape(1, other.getColor()){

	point p = other.getPointAtIndex(0);
	this -> setPoint(0, point(p.x, p.y));
	this -> radius = other.radius;

}
Circle::Circle(double x, double y, double radius, const String &color): Shape(1, color), radius(radius){ this -> setPoint(0, point(x, y)); }

double Circle::getArea() const{ return PI * radius * radius; }
double Circle::getPer() const{ return 2 * PI * radius; }

bool Circle::isPointIn(const double x, const double y) const{
	
	point p(x, y);
	return p.getDist(getPointAtIndex(0)) <= radius;

}

Shape* Circle::clone() const{ return new Circle(*this); }

void Circle::serialize(ostream &os) const{

	point center = getPointAtIndex(0);
	os << "\t<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << this -> radius << "\" fill=\"" << this -> getColor() << "\" />\n";

}

void Circle::deserialize(istream &is){

	double x, y, r;
	String color;

	while(is.get() != '\"');
	is >> x;
	is.ignore();

	while(is.get() != '\"');
	is >> y;
	is.ignore();

	while(is.get() != '\"');
	is >> r;
	is.ignore();

	while(is.get() != '\"');

	size_t i;
	char *inp = new char[2];
	inp[1] = '\0';
	
	for(i = 0; (inp[0] = is.get()) != '\"'; i++) color += inp;

	this -> setPoint(0, point(x, y));
	this -> radius = r;
	this -> setColor(color);

}


String Circle::toString() const{

	point center = getPointAtIndex(0);
	String result("circle x=");

	result += center.x;
	result += " y=";
	result += center.y;
	result += " radius=";
	result += this -> radius;
	result += " color=";
	result += this -> getColor();
	
	return result;

}

bool Circle::isInsideRectangle(const double x, const double y, const double width, const double height) const{

	point center = getPointAtIndex(0);
	point left(center.x - radius, center.y);
	point right(center.x + radius, center.y);
	point top(center.x, center.y - radius);
	point bottom(center.x, center.y + radius);
	point rectPoint1(x, y);
	point rectPoint4(x + width, y + height);

	return left.x >= rectPoint1.x && left.x <= rectPoint4.x && right.x >= rectPoint1.x && right.x <= rectPoint4.x
		&& top.y >= rectPoint4.y && top.y <= rectPoint1.y && bottom.y >= rectPoint4.y && bottom.y <= rectPoint1.y;

}

bool Circle::isInsideCircle(const double x, const double y, const double r) const{

	point centerSmall = getPointAtIndex(0);
	point centerBig = getPointAtIndex(0);

	return centerBig.getDist(centerSmall) + r <= radius;
	

}