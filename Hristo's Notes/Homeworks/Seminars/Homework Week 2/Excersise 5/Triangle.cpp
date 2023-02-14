#include "Triangle.h"
#include "Point.h"
#include <iostream>
#include <cmath>

using std::cout;

void Triangle::initTriangle(){

    findEdges();
    findPerimeter();
    findArea();

}

double Triangle::findEdges(){

    this->AB = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
    this->AC = sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y));
    this->BC = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));

}

double Triangle::findPerimeter(){

    this->perimeter = this->AB + this->AC + this->BC;

}

double Triangle::findArea(){

    double halfPerimeter = this->perimeter / 2;
    this->area = sqrt(halfPerimeter * (halfPerimeter - this->AB) * (halfPerimeter - this->AC) * (halfPerimeter - this->BC));

}

void Triangle::print(){

    cout << "Triangle with points:\n"
        << "A: (" << this->A.x << ", " << this->A.y << ")\n"
        << "B: (" << this->B.x << ", " << this->B.y << ")\n"
        << "C: (" << this->C.x << ", " << this->C.y << ")\n"
        << "Triangle perimeter is: " << this->perimeter << '\n'
        << "Triangle area is: " << this->area << '\n';

}