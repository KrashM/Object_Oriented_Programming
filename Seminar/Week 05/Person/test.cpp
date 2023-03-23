#include <iostream>
#include "Person.hpp"

using std::cin;
using std::cout;

int main(){

    Person p("Hristo", "Kanev", 20), p1;

    p1 = p;

    cout << p1.getName() << ' ' << p1.getSurname() << ' ' << p1.getAge() << '\n';

}