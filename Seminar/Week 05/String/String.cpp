#include "String.hpp"
#include <cstring>
#include <new>

using std::nothrow;

String::String(): str(new(nothrow) char[1]){ // Слагаме по default стрингът да е празен а не nullptr, за да може функциите за дължина и печат да работят.
    if(str) *str = '\0';
}

String::String(char const *str): str(new(nothrow) char[strlen(str) + 1]){
    if(this -> str) strcpy(this -> str, str);
}

String::String(String const &other){
    copyFrom(other);
}

String &String::operator =(String const &other){

    if(this != &other){

        free();
        copyFrom(other);

    }

    return *this;

}

String::~String(){
    free();
}

char const *String::c_str() const{
    return str;
}
size_t String::length() const{
    return strlen(str);
}

void String::free(){
    delete[] str;
}

void String::copyFrom(String const &other){

    str = new(nothrow) char[strlen(other.str) + 1];
    if(str) strcpy(str, other.str);

}