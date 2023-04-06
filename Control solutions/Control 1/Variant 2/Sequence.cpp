#include "Sequence.hpp"

Sequence::Sequence(): _capacity(4), _size(0), _v(new double[_capacity]){}

Sequence::Sequence(Sequence const &other){
    copyFrom(other);
}

Sequence::~Sequence(){
    free();
}

Sequence &Sequence::operator =(Sequence const &other){

    if(this == &other) return *this;

    free();
    copyFrom(other);

    return *this;

}

void Sequence::addVector(Vector const &vec){

    while(_size + vec.getSize() >= _capacity) resize(2 * _capacity);

    for(size_t i = 0; i < vec.getSize(); ++i)
        _v[_size++] = vec[i];

}

ostream &operator <<(ostream &os, Sequence const &seq){

    for(size_t i = 0; i < seq._size; ++i)
        os << seq._v[i] << ' ';
    return os;

}

void Sequence::resize(size_t const newCapacity){

    _capacity = newCapacity;
    double *temp = new double[newCapacity];

    for(size_t i = 0; i < _size; ++i)
        temp[i] = _v[i];
    
    free();
    _v = temp;

}

void Sequence::copyFrom(Sequence const &other){

    _capacity = other._capacity;
    _size = other._size;
    _v = new double[other._capacity];

    for(size_t i = 0; i < other._size; ++i)
        _v[i] = other._v[i];

}

void Sequence::free(){
    delete[] _v;
}