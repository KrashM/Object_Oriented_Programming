#include "Dictionary.hpp"
#include <cstring>

using std::swap;

Dictionary::Dictionary(Record const * const * const records, size_t const size): size(size){

    for (size_t i = 0; i < size; ++i)
        this -> records[i] = new Record(*records[i]);

}

Dictionary::Dictionary(Dictionary const &other){
    copyFrom(other);
}

Dictionary::~Dictionary(){
    free();
}

Dictionary &Dictionary::operator =(Dictionary const &other){

    if(this == &other) return *this;

    free();
    copyFrom(other);

    return *this;

}

void Dictionary::add(Record const &rec){

    if(size == MAX_CAPACITY) return;
    records[size++] = new Record(rec);

}

void Dictionary::remove(char const * const key){

    for(size_t i = 0; i < size; i++)
        if (!strcmp(key, records[i] -> getKey())){

            for(size_t j = i; j < size - 1; j++)
                records[j] = records[j + 1];

            delete records[--size];
            break;

        }
}

char const * const Dictionary::operator [](char const * const key) const{

    for(size_t i = 0; i < size; ++i)
        if(!strcmp(records[i] -> getKey(), key))
            return records[i] -> getValue();

    return "";

}

char const * const Dictionary::operator [](size_t const index) const{
    
    if(index < size) return records[index] -> getValue();
    return "";

}

void Dictionary::sort(){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = 0; j < size - i - 1; ++j)
            if(strcmp(records[j] -> getKey(), records[j + 1] -> getKey()) > 0)
                swap(records[j], records[j + 1]);

}

size_t Dictionary::getSize() const{
    return size;
}

bool operator ==(Dictionary const &lhs, Dictionary const &rhs){
    
    if(lhs.size != rhs.getSize()) return false;

    for(size_t i = 0; i < lhs.size; ++i)
        if(*lhs.records[i] != *rhs.records[i]) return false;
    
    return true;

}

bool operator !=(Dictionary const &lhs, Dictionary const &rhs){
    return !(lhs == rhs);
}

ostream &operator <<(ostream &os, Dictionary const &dict){

    for(size_t i = 0; i < dict.size; ++i)
        if(i != dict.size - 1) os << *dict.records[i] << '\n';
        else os << *dict.records[i];
    return os;

}

void Dictionary::copyFrom(Dictionary const &other){

    size = other.size;
    for(size_t i = 0; i < other.size; ++i)
        records[i] = new Record(*other.records[i]);

}

void Dictionary::free(){

    for(size_t i = 0; i < size; ++i){

        delete records[i];
        records[i] = nullptr;

    }

    size = 0;

}