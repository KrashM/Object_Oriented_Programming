#include <new>
#include <cmath>
#include <exception>
#include "Nvector.hpp"

using std::sqrt;
using std::nothrow;
using std::out_of_range;
using std::invalid_argument;

Nvector::Nvector(size_t size): size(size), v(new(nothrow) int[size]){}

Nvector::Nvector(Nvector const &other){
    copyFrom(other);
}

Nvector::~Nvector(){
    free();
}

Nvector &Nvector::operator =(Nvector const &other){

    if(this == &other)
        return *this;

    free();
    copyFrom(other);

    return *this;

}

Nvector &Nvector::operator +=(Nvector const &other){

    if(size != other.size) return *this;

    for(size_t i = 0; i < size; ++i)
        v[i] += other.v[i];
    
    return *this;

}

Nvector &Nvector::operator -=(Nvector const &other){

    if(size != other.size) return *this;

    for(size_t i = 0; i < size; ++i)
        v[i] -= other.v[i];
    
    return *this;

}

Nvector &Nvector::operator *=(int scallar){

    for(size_t i = 0; i < size; ++i)
        v[i] *= scallar;
    
    return *this;

}

double Nvector::operator ~() const{

    int sum = 0;

    for(size_t i = 0; i < size; ++i)
        sum += v[i];

    return sqrt(sum);

}

int Nvector::operator [](size_t index) const{

    if(index >= size)
        throw out_of_range("Index out of bounds");

    return v[index];

}

int &Nvector::operator [](size_t index){

    if(index >= size)
        throw out_of_range("Index out of bounds");

    return v[index];

}

Nvector operator +(Nvector const &lhs, Nvector const &rhs){

    if(lhs.size != rhs.size)
        throw invalid_argument("Sizes don't match");
    
    Nvector result(lhs.size);

    for(size_t i = 0; i < lhs.size; ++i)
        result[i] = lhs[i] + rhs[i];
    
    return result;

}

Nvector operator -(Nvector const &lhs, Nvector const &rhs){
    
    if(lhs.size != rhs.size)
        throw invalid_argument("Sizes don't match");
    
    Nvector result(lhs.size);

    for(size_t i = 0; i < lhs.size; ++i)
        result[i] = lhs[i] - rhs[i];
    
    return result;

}

int operator *(Nvector const &lhs, Nvector const &rhs){

    if(lhs.size != rhs.size) return 0;
    
    int result = 0;

    for(size_t i = 0; i < lhs.size; ++i)
        result += lhs[i] * rhs[i];
    
    return result;

}

Nvector operator *(Nvector const &v, int scallar){

    Nvector result(v.size);

    for(size_t i = 0; i < v.size; ++i)
        result[i] = v[i] * scallar;

    return result;

}

Nvector operator *(int scallar, Nvector const &v){
    return v * scallar;
}

bool operator ||(Nvector const &lhs, Nvector const &rhs){

	if(lhs.size != rhs.size) return false;

	double coef = (double)lhs[0] / rhs[0], eps = 0.01, currCoef;

	for(size_t i = 1; i < lhs.size; i++){

		currCoef = (double)lhs[i] / rhs[i];
		if(abs(currCoef - coef) > eps) return false;

	}

	return true;

}

bool operator |=(Nvector const &lhs, Nvector const &rhs){
    return lhs * rhs == 0;
}

istream &operator >>(istream &is, Nvector &v){

    for(size_t i = 0; i < v.size; ++i)
        is >> v[i];
    
    return is;

}

ostream &operator <<(ostream &os, Nvector const &v){

    os << "[ ";
    for(size_t i = 0; i < v.size; ++i)
        os << v[i] << ' ';
    os << ']';

    return os;

}

void Nvector::copyFrom(Nvector const &other){

    size = other.size;
    v = new(nothrow) int[size];

    for(size_t i = 0; i < size; ++i)
        v[i] = other[i];

}
void Nvector::free(){
    delete[] v;
}