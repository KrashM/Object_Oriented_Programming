#include <iostream>

using std::cin;
using std::cout;

struct complexNumber{

    int a, b;

    void toString();

};

void complexNumber::toString(){

    cout << a << ((b >= 0) ? " + " : " - ") << ((b >= 0) ? b : -b) << "i\n";

}

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
    m.toString();

    cin >> n.a >> n.b;
    n.toString();

    complexNumber addition = add(m, n);
    addition.toString();
    
    complexNumber subtraction = subtract(m, n);
    subtraction.toString();

}