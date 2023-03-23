#include <iostream>
#include "String.hpp"

using std::cin;
using std::cout;

int main(){

    String s("Hello World");

    String s1(s), s2;

    cout << s2.length() << '\n';

    s2 = s;

    cout << s.c_str() << '\n';
    cout << s1.c_str() << '\n';
    cout << s2.c_str() << '\n';

}