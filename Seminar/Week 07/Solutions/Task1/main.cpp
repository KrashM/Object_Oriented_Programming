#define TEST
#include "Dictionary.hpp"
#include <iostream>

#ifdef DOCTEST_CONFIG_IMPLEMENT
#define test doctest::Context().run()
#else
#define test
#endif

using std::cout;

int main(){

#ifdef TEST

    test;

#else

    // Този код трябва да го конвертираме в unit тестове.
    Record *records[3];

    records[0] = new Record("Table", "Masa");
    records[1] = new Record("Hello", "There");
    records[2] = new Record("Maze", "Labirinth");

    Dictionary dict(records, 3);
    cout << dict << '\n';
    cout << '\n';

    dict.add(Record("Zdravei", "Hello"));

    cout << dict << '\n';
    cout << '\n';
    
    cout << dict["Maze"] << '\n';
    cout << dict[3] << '\n';
    cout << '\n';

    cout << dict["Mazalo"] << '\n';
    cout << dict[4] << '\n';
    cout << '\n';

    dict.remove("Maze");

    cout << dict << '\n';
    cout << '\n';

    dict.sort();

    cout << dict << '\n';

#endif

}