#include "Plane.hpp"

Plane::Plane(Nvector const &v1, Nvector const &v2): v1(v1), v2(v2){}

Plane::Plane(Plane const &other): v1(other.v1), v2(other.v2){}

Plane &Plane::operator =(Plane const &other){

    if(this == &other) return *this;

    v1 = other.v1;
    v2 = other.v2;
    return *this;

}

Nvector Plane::getVectorByCoordinates(int x, int y) const{
    return v1 * x + v2 * y;
}

Nvector Plane::getCoordinatesByVector(Nvector const &v) const{

    Nvector invV1(2), invV2(2);
    int determinant = v1[0] * v2[1] - v1[1] * v2[0];

    invV1[0] = v2[1] / determinant;
    invV1[1] = -v1[1] / determinant;
    invV2[0] = -v2[0] / determinant;
    invV2[1] = v1[0] / determinant;

    return invV1 * v[0] + invV2 * v[1];

}