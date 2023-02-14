#include "Quadratic.h"
#include <cmath>

void Quadratic::findRoots(){

    this->discriminant = this->b * this->b - 4 * this->a * this->c;

    if(this->a == 0) return;

    if(this->discriminant > 0){

        this->x_1 = (-this->b + sqrt(discriminant)) / (2 * this->a);
        this->x_2 = (-this->b - sqrt(discriminant)) / (2 * this->a);

    }
    else if(this->discriminant == 0){

        this->x_1 = (-this->b) / (2 * this->a);
        this->x_2 = (-this->b) / (2 * this->a);

    }

}