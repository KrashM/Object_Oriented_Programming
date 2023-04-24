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

    String s3("Az sum gosho"), s4;

    s += s3;

    cout << s << '\n';

    cin >> s4;

    cout << s4 << '\n';

    cout << s4[5] << '\n';

    String s5 = s + s4;

    cout << s5 << '\n';

}