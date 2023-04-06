#include "Sentence.hpp"

Sentence::Sentence(): _capacity(4), _size(0), _w(new char[_capacity]){}

Sentence::Sentence(Sentence const &other){
    copyFrom(other);
}

Sentence::~Sentence(){
    free();
}

Sentence &Sentence::operator =(Sentence const &other){

    if(this == &other) return *this;

    free();
    copyFrom(other);

    return *this;

}

void Sentence::addWord(Word const &word){

    while(_size + word.getSize() >= _capacity) resize(2 * _capacity);

    for(size_t i = 0; i < word.getSize(); ++i)
        _w[_size++] = word[i];

}

ostream &operator <<(ostream &os, Sentence const &seq){

    for(size_t i = 0; i < seq._size; ++i)
        os << seq._w[i] << ' ';
    return os;

}

void Sentence::resize(size_t const newCapacity){

    _capacity = newCapacity;
    char *temp = new char[newCapacity];

    for(size_t i = 0; i < _size; ++i)
        temp[i] = _w[i];
    
    free();
    _w = temp;

}

void Sentence::copyFrom(Sentence const &other){

    _capacity = other._capacity;
    _size = other._size;
    _w = new char[other._capacity];

    for(size_t i = 0; i < other._size; ++i)
        _w[i] = other._w[i];

}

void Sentence::free(){
    delete[] _w;
}