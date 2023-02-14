#include <iostream>
#include "complexNumber.h"

using std::cin;
using std::cout;

struct complexNumber add(complexNumber m, complexNumber n){

    complexNumber sum;
    sum.a = m.a + n.a;
    sum.b = m.b + n.b;

    return sum;

}

struct complexNumber subtract(complexNumber m, complexNumber n){

    complexNumber sum;
    sum.a = m.a - n.a;
    sum.b = m.b - n.b;

    return sum;

}

int main(){

    complexNumber m, n;

    cin >> m.a >> m.b;
    cout << m.toString() << '\n';

    cin >> n.a >> n.b;
    cout << n.toString() << '\n';

    complexNumber addition = add(m, n);
    cout << addition.toString() << '\n';
    
    complexNumber subtraction = subtract(m, n);
    cout << subtraction.toString() << '\n';

}