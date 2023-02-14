#include "Vector.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){

    Vector v;
    int x;

    cout << ((v.isEmpty()) ? "true" : "false") << '\n';

    while(cin >> x) v.pushBack(x);

    cout << v.toString() << '\n';
    v.removeAt(4);
    cout << v.toString() << '\n';
    v.insert(4, 10);
    cout << v.toString() << '\n';
    v.erase(50);
    cout << v.toString() << '\n';

    cout << v.getCapacity() << '\n';
    cout << v.getSize() << '\n';
    cout << ((v.isEmpty()) ? "true" : "false") << '\n';
    cout << v.getAt(4) << '\n';
    cout << v.getLast() << '\n';
    cout << v.getFirst() << '\n';
    v.assign(5, 10);
    cout << v.toString() << '\n';

}
///1 5 6 7 8 1 50 0 13 45 6 10 1 2 3 7 8 50 36 5 6 8 9 1 4 50 ^Z