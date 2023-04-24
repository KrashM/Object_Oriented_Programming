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


String &String::operator +=(String const &other){

    char *temp = new(nothrow) char[strlen(str) + strlen(other.str) + 1];
    strcpy(temp, str);
    strcat(temp, other.str);

    free();

    str = temp;

    return *this;
    
}

String &String::operator +=(char const *other){

    char *temp = new(nothrow) char[strlen(str) + strlen(other) + 1];
    strcpy(temp, str);
    strcat(temp, other);

    free();

    str = temp;

    return *this;

}

ostream &operator <<(ostream &os, String const &str){

    os << str.str;
    return os;

}

istream &operator >>(istream &is, String &str){

    char buffer[1024];
    is >> buffer;
    str.free();
    str = new(nothrow) char[strlen(buffer) + 1];
    strcpy(str.str, buffer);
    return is;

}

char &String::operator [](size_t const index){

    if(index >= length()) return str[0];
    return str[index];

}

char const String::operator [](size_t const index) const{
    
    if(index >= length()) return '\0';
    return str[index];

}

String operator +(String const &lhs, String const &rhs){

    String result;

    result.str = new(nothrow) char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(result.str, lhs.str);
    strcat(result.str, rhs.str);

    return result;

}

String operator +(String const &lhs, char const *rhs){

    String result;

    result.str = new(nothrow) char[strlen(lhs.str) + strlen(rhs) + 1];
    strcpy(result.str, lhs.str);
    strcat(result.str, rhs);

    return result;

}

String operator +(char const *lhs, String const &rhs){

    String result;

    result.str = new(nothrow) char[strlen(lhs) + strlen(rhs.str) + 1];
    strcpy(result.str, lhs);
    strcat(result.str, rhs.str);

    return result;

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