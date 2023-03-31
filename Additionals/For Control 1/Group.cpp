#include "Group.hpp"

Group::Group(): _capacity(4), _size(0), _collection(new(nothrow) Person*[_capacity]){}

Group::Group(Group const &other){
    copyFrom(other);
}

Group::~Group(){
    free();
}

Group &Group::operator=(Group const &other){

    if(this == &other) return *this;

    free();
    copyFrom(other);

    return *this;

}

Person *&Group::operator [](size_t const index){

    assert(index < _size);
    return _collection[index];

}

Person const * const Group::operator [](size_t const index) const{

    assert(index < _size);
    return _collection[index];

}

void Group::push_back(Person * const person){

    if(_size == _capacity) resize(2 * _capacity);
    _collection[_size++] = person;

}

void Group::pop_back(){

    assert(_size > 0);
    --_size;

}

void Group::clear(){
    _size = 0;
}

size_t Group::size() const{
    return _size;
}

ostream &operator <<(ostream &os, Group const &obj){

    for(size_t i = 0; i < obj._size; ++i)
        if(obj._collection[i])
            os << *obj._collection[i] << '\n';
    return os;

}

void Group::resize(size_t const newCapacity){

    _capacity = newCapacity;
    Person **temp = new(nothrow) Person*[newCapacity];

    assert(temp);

    for(size_t i = 0; i < _size; ++i)
        temp[i] = _collection[i];
    
    delete[] _collection;
    _collection = temp;

}

void Group::copyFrom(Group const &other){

    _capacity = other._capacity;
    _size = other._size;
    _collection = new(nothrow) Person*[other._capacity];

    assert(_collection);

    for(size_t i = 0; i < other._size; ++i)
        _collection[i] = other._collection[i];

}

void Group::free(){
    delete[] _collection;
}