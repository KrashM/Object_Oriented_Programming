#include "Plane.hpp"

using std::cin;
using std::cout;

int main(){

    {

        Nvector v(2);
        cin >> v;

        Nvector v2(2);
        cin >> v2;

        Nvector result = v + v2;
        cout << result << '\n';

    }

    {
        Nvector v1(2);
        v1[0] = 2;
        v1[1] = 1;
        
        Nvector v2(2);
        v2[0] = 3;
        v2[1] = 1;
        
        Nvector toTransform(2);
        toTransform[0] = 7;
        toTransform[1] = 4;

        Plane s(v1, v2);
        
        cout << s.getVectorByCoordinates(7, 4) << '\n'; // [26, 11]
        cout << s.getCoordinatesByVector(toTransform) << '\n'; // [5, -1]

    }

}