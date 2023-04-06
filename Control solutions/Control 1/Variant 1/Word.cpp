#include <cassert>
#include <cstring>
#include "Word.hpp"

Word::Word(): _size(0){}

char &Word::operator [](size_t const index){

    assert(index < _size);
    return _w[index];

}

char const Word::operator [](size_t const index) const{

    assert(index < _size);
    return _w[index];

}

Word &Word::operator +=(char const element){

    if(_size == 20) return *this;
    _w[_size++] = element;
    return *this;

}

Word &Word::operator +(char const element){

    if(_size == 20) return *this;
    _w[_size++] = element;
    return *this;

}

size_t Word::getSize() const{
    return _size;
}

bool operator <(Word const &lhs, Word const &rhs){

    assert(lhs._size == rhs._size);
    return !~strcmp(lhs._w, rhs._w);

}

bool operator ==(Word const &lhs, Word const &rhs){

    assert(lhs._size == rhs._size);
    return !strcmp(lhs._w, rhs._w);

}