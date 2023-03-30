#include <cassert>
#include <new>
#include "Vector.hpp"

using std::nothrow;

Vector::Vector(): _capacity(4), _size(0), _v(new(nothrow) int[_capacity]){}

Vector::Vector(Vector const &other){
    copyFrom(other);
}

Vector::~Vector(){
    free();
}

Vector &Vector::operator =(Vector const &other){

    if(this == &other) return *this;

    free();
    copyFrom(other);

    return *this;

}

int &Vector::operator [](size_t const index){

    assert(index < _size);
    return _v[index];

}

int const Vector::operator [](size_t const index) const{

    assert(index < _size);
    return _v[index];

}

void Vector::reserve(size_t const capacity){

    free();

    _capacity = capacity;
    _size = 0;
    _v = new(nothrow) int[capacity];

}

size_t nearest_power_of_ten(size_t const size){

    size_t result = 1;
    while(result <= size) result <<= 1;
    return result;

}

void Vector::assign(size_t const size, int const value){

    free();

    _capacity = nearest_power_of_ten(size);
    _size = size;
    _v = new(nothrow) int[_capacity];

    for(size_t i = 0; i < size; ++i)
        _v[i] = value;

}

void Vector::push_back(int const element){

    if(_size == _capacity) resize(2 * _capacity);

    _v[_size++] = element;

}

void Vector::pop_back(){

    assert(_size > 0);
    --_size;

}

void Vector::insert(size_t const index, int const element){

    if(_size == _capacity) resize(2 * _capacity);
    for(size_t i = _size; i > index; --i)
        _v[i] = _v[i - 1];
    _v[index] = element;


}

void Vector::erase(size_t const element){

    if(!_size) return;

    bool found = false;

    for(size_t i = 0; i < _size - 1; ++i){

        found |= _v[i] == element;
        _v[i] = found ? _v[i + 1] : _v[i];

    }

    --_size;

    if(_size == _capacity / 4) resize(_capacity / 2);

}

void Vector::clear(){
    _size = 0;
}

size_t Vector::capacity() const{
    return _capacity;
}

size_t Vector::size() const{
    return _size;
}

bool Vector::empty() const{
    return !_size;
}
bool Vector::contains(int const element) const{

    for(size_t i = 0; i < _size; ++i)
        if(_v[i] == element) return true;
    return false;

}

int const Vector::front() const{
    return _v[0];
}

int &Vector::front(){
    return _v[0];
}

int const Vector::back() const{
    return _v[_size - 1];
}

int &Vector::back(){
    return _v[_size - 1];
}

ostream &operator <<(ostream &os, Vector const &obj){

    for(size_t i = 0; i < obj._size; ++i)
        os << obj._v[i] << ' ';
    return os;

}

void Vector::resize(size_t const newCapacity){

    _capacity = newCapacity;
    int *temp = new(nothrow) int[newCapacity];

    for(size_t i = 0; i < _size; ++i)
        temp[i] = _v[i];
    
    delete[] _v;
    _v = temp;

}

void Vector::copyFrom(Vector const &other){

    _capacity = other._capacity;
    _size = other._size;

    free();
    _v = new(nothrow) int[other._capacity];

    for(size_t i = 0; i < other._size; ++i)
        _v[i] = other._v[i];

}
void Vector::free(){
    delete[] _v;
}