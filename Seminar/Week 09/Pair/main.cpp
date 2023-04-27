#include "pair.hpp"
#include <iostream>

int main(){

    pair<int, int> p(3, 4);
    pair<int, int> p1;
    pair<int, double> p2;

    std::cout << p.get_first() << ' ' << p.get_second() << '\n';
    std::cout << p1.get_first() << ' ' << p1.get_second() << '\n';

    p1 = p;

    std::cout << p1.get_first() << ' ' << p1.get_second() << '\n';

    p1 = pair<int, int>(5, 7);

    std::cout << p1.get_first() << ' ' << p1.get_second() << '\n';

}