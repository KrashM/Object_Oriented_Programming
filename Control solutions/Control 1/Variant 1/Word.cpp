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

Word operator +(Word const &word, char const element){

    Word result(word);
    result += element;
    return result;

}

Word operator +(char const element, Word const &word){

    Word result(word);
    result += element;
    return result;

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