#include <iostream>
#include "complexNumber.h"

using std::cin;
using std::cout;

int main(){

    int a, b;

    cin >> a >> b;
    complexNumber m(a, b);

    cin >> a >> b;
    complexNumber n(a, b);

    cout << m.toString() << '\n';
    cout << n.toString() << '\n';

    complexNumber addition = m + n;
    cout << addition.toString() << '\n';
    
    complexNumber subtraction = m * n;
    cout << subtraction.toString() << '\n';

}