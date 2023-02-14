#include "Quadratic.h"
#include <cmath>

void Quadratic::findRoots(){

    discriminant = b * b - 4 * a * c;

    if(a == 0) return;

    if(discriminant > 0){

        x1.setValue((-b + sqrt(discriminant)) / (2 * a), 0);
        x2.setValue((-b - sqrt(discriminant)) / (2 * a), 0);

    }
    else if(discriminant == 0){

        x1.setValue((-b) / (2 * a), 0);
        x2.setValue((-b) / (2 * a), 0);

    }
    else{

        x1.setValue(-b / (2 * a), sqrt(-discriminant) / (2 * a));
        x2.setValue(-b / (2 * a), -sqrt(-discriminant) / (2 * a));

    }

}