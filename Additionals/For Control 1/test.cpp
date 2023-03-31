#include "Group.hpp"

using std::cout;

int main(){

    Person p("Hristo", 20, 123'456), p1("Plamen", 20, 123'456), p2 = Person("Maria", 15, 345'678);

    Group g;

    g.push_back(&p);
    g.push_back(&p1);
    g.push_back(nullptr);
    g.push_back(&p2);

    cout << *g[3] << "\n\n";

    g.pop_back();

    cout << g.size() << '\n';

    cout << g;

    g.clear();
    cout << g.size() << '\n';

}