#include <iostream>
#include "Vector.hpp"

using std::cin;
using std::cout;

int main(){

    Vector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    cout << v << '\n'; // alternative

}