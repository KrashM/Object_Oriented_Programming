#include "String.h"

String::String(): size(0), str(nullptr){}
String::String(const char *str): size(strlen(str)), str(new char[this -> size + 1]){ strcpy(this -> str, str); }
String::String(size_t n){

    size_t digits = (size_t)log10(n) + 1;
    this -> str = new char[digits + 1];

    for(size_t i = 0; i < digits; i++, n /= 10) this -> str[digits - 1 - i] = '0' + n % 10;
    this -> str[digits] = '\0';
    this -> size = digits;

}
String::String(const String &other){ this -> copy(other); }
String::String(String &&other){

    this -> size = other.size;
    this -> str = other.str;
    other.str = nullptr;

}
String::~String(){ this -> free(); }
String &String::operator =(const String &other){

    if(this != &other){

        this -> free();
        this -> copy(other);

    }

    return *this;

}
String &String::operator =(String &&other){

    if(this != &other){

        this -> free();
        this -> size = other.size;
        this -> str = other.str;
        other.str = nullptr;

    }

    return *this;

}
String &String::operator +=(const char *str){

    size_t catLen = strlen(str);
    char *temp = new char[this -> size + catLen + 1];
    strcpy(temp, this -> str);
    strcat(temp, str);

    this -> free();
    this -> str = temp;
    this -> size += catLen;

    return *this;

}
String &String::operator +=(const String &other){

    char *temp = new char[this -> size + other.size + 1];
    strcpy(temp, this -> str);
    strcat(temp, other.str);

    this -> free();
    this -> str = temp;
    this -> size += other.size;

    return *this;

}
String &String::operator +=(size_t n){

    size_t digits = (size_t)log10(n) + 1;
    char *temp = new char[this -> size + digits + 1];
    strcpy(temp, this -> str);
    this -> free();

    for(size_t i = this -> size; i < this -> size + digits; i++, n /= 10) temp[digits - 1 - i] = '0' + n % 10;
    temp[this -> size + digits] = '\0';

    this -> str = temp;
    this -> size += digits;

    return *this;

}
char &String::operator [](const size_t index){ if(index >= this -> size) throw MessageException("Index out of range"); return this -> str[index]; }
const char &String::operator [](const size_t index) const{ return this -> str[index]; }

size_t String::length() const{ return this -> size; }
const char *String::c_str() const{ return this -> str; }

ostream &operator <<(ostream &os, const String &obj){

    os << obj.str;
    return os;

}
istream &operator >>(istream &is, String &obj){

    delete[] obj.str;
    char buffer[1024];
    is >> setw(1024) >> buffer;

    obj.size = strlen(buffer);
    obj.str = new char[obj.size + 1];
    strcpy(obj.str, buffer);

    return is;

}
bool operator ==(const String &lhs, const String &rhs){

    if(lhs.length() != rhs.length()) return false;

    for(size_t i = 0; i < lhs.length(); i++)
        if(lhs[i] != rhs[i]) return false;

    return true;

}
bool operator !=(const String &lhs, const String &rhs){ return !(lhs == rhs); }
String &operator +(const String lhs, const String &rhs){

    String temp(lhs);
    temp += rhs;
    return temp;

}

void String::free(){ delete[] this -> str; }
void String::copy(const String &other){

    this -> size = other.size;
    this -> str = new char[other.size + 1];
    strcpy(this -> str, other.str);

}