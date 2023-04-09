#include "Vector.hpp"
#include <cassert>

Vector::Vector(): _size(0){}

Vector &Vector::operator +=(double const element){

    if(_size == 20) return *this;
    _v[_size++] = element;
    return *this;

}

Vector operator +(Vector const &vec, double const element){

    Vector result(vec);
    result += element;
    return result;

}

Vector operator +(double const element, Vector const &vec){

    Vector result(vec);
    result += element;
    return result;

}

double &Vector::operator [](size_t const index){

    assert(index < _size);
    return _v[index];

}

double const Vector::operator [](size_t const index) const{
    
    assert(index < _size);
    return _v[index];

}

size_t Vector::getSize() const{
    return _size;
}

double Vector::computeSize() const{

    double vecSize = 0;

    for(size_t i = 0; i < _size; ++i)
        vecSize += _v[i] * _v[i];

    return vecSize;

}

bool operator <(Vector const &lhs, Vector const &rhs){

    assert(lhs._size == rhs._size);
    return lhs.computeSize() < rhs.computeSize();

}

bool operator ==(Vector const &lhs, Vector const &rhs){

    assert(lhs._size == rhs._size);
    return lhs.computeSize() == rhs.computeSize();

}