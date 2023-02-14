#include <iostream>
#include "Point.h"
#include "Line.h"

using std::cin;
using std::cout;

int main(){

    Line line;
    cout << line.getLength() << '\n';

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Point a(x1, y1), b(x2, y2);
    Line line2(a, b);

    cout << line2.getLength() << '\n';

}