#include "Quadratic.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){

    Quadratic myEquation;
    cin >> myEquation.a >> myEquation.b >> myEquation.c;

    myEquation.findRoots();

    if(myEquation.discriminant == 0) cout << "x1 = x2 = " << myEquation.x1.toString() << '\n';
    else cout << "x1 = " << myEquation.x1.toString() << "\nx2 = " << myEquation.x2.toString() << '\n';

}