#include <iostream>

using std::cin;
using std::cout;

struct complex{
    int real, imag;
};

complex add(const complex &a, const complex &b){

    complex result;

    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;

    return result;

}

complex subtract(const complex &a, const complex &b){

    complex result;

    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;

    return result;

}

complex multiply(const complex &a, const complex &b){

    complex result;

    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + b.real * a.imag;

    return result;

}

void print(const complex &a){

    if(a.real) cout << a.real;
    if(a.imag > 0) cout << '+';
    if(a.imag != 0) cout << a.imag << 'i';
    cout << '\n';

}

int main(){

    complex a, b;

    cin >> a.real >> a.imag >> b.real >> b.imag;

    print(add(a, b));
    print(subtract(a, b));
    print(multiply(a, b));

}