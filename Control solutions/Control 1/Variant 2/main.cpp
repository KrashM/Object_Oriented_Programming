#include "Sequence.hpp"

using std::cout;

int main(){

    Vector v;
    v += 1;
    v += 2;
    v += 3;
    v + 4;

    Vector v1;

    v1 = v;

    Sequence s;
    s.addVector(v1);

    cout << s << '\n';
    
}