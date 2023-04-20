#include "Record.hpp"
#include <cstring>
#include <new>

using std::nothrow;

Record::Record(char const * const key, char const * const value){

    this -> key = new(nothrow) char[strlen(key) + 1];
    strcpy(this -> key, key);

    this -> value = new(nothrow) char[strlen(value) + 1];
    strcpy(this -> value, value);

}

Record::Record(Record const &other){
    copyFrom(other);
}

Record::~Record(){
    free();
}

Record &Record::operator =(Record const &other){

    if(this == &other) return *this;

    free();
    copyFrom(other);

    return *this;

}

char const *Record::getKey() const{
    return key;
}

char const *Record::getValue() const{
    return value;
}

bool operator ==(Record const &lhs, Record const &rhs){
    return !strcmp(lhs.key, rhs.key) && !strcmp(lhs.value, rhs.value);
}

bool operator !=(Record const &lhs, Record const &rhs){
    return !(lhs == rhs);
}

ostream &operator <<(ostream &os, Record const &rec){
    return os << rec.key << " - " << rec.value;
}

void Record::copyFrom(Record const &other){

    key = new(nothrow) char[strlen(other.key) + 1];
    strcpy(key, other.key);

    value = new(nothrow) char[strlen(other.value) + 1];
    strcpy(value, other.value);

}

void Record::free(){

    delete[] key;
    delete[] value;

    key = nullptr;
    value = nullptr;

}