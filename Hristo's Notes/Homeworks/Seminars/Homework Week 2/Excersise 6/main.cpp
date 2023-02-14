#include "Quadratic.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){

    Quadratic myEquation;
    cin >> myEquation.a >> myEquation.b >> myEquation.c;

    myEquation.findRoots();

    if(myEquation.discriminant > 0) cout << "x1 = " << myEquation.x_1 << "\nx2 = " << myEquation.x_2 << '\n';
    else if(myEquation.discriminant == 0) cout << "x1 = x2 = " << myEquation.x_1 << '\n';
    else cout << "The equation does not have real solutions!\n";

}