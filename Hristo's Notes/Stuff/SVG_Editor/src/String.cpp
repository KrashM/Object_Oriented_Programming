#include "../headers/String.h"

#include <cstring>
#include <iomanip>
#include <math.h>
#include <stdexcept>

using std::setw;
using std::out_of_range;

String::String(): size(0), str(new char[1]){ this -> str[0] = '\0'; }
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
String &String::operator +=(const char character){

    char *temp = new char[this -> size + 2];

    strcpy(temp, this -> str);
    temp[this -> size] = character;
    temp[this -> size + 1] = '\0';

    this -> free();

    this -> str = temp;
    this -> size++;

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
String &String::operator +=(const size_t n){

    size_t digits = (size_t)log10(n) + 1, powerOfTen = 1;
    char *temp = new char[this -> size + digits + 1];
    
    strcpy(temp, this -> str);

    this -> free();

    for(size_t i = this -> size; i < this -> size + digits; i++, powerOfTen *= 10) temp[digits - 1 - i] = '0' + (n / powerOfTen) % 10;
    temp[this -> size + digits] = '\0';

    this -> str = temp;
    this -> size += digits;

    return *this;

}
String &String::operator +=(const double n){

    size_t digits = (size_t)log10(n) + 1, powerOfTen = 1;
    char *temp = new char[this -> size + digits + 4];

    strcpy(temp, this -> str);
    
    this -> free();

    for(size_t i = this -> size + digits - 1; i >= this -> size; i--, powerOfTen *= 10) temp[i] = '0' + ((size_t)n / powerOfTen) % 10;
    temp[this -> size + digits] = '.';
    temp[this -> size + digits + 1] = '0' + (size_t)(n * 10) % 10;
    temp[this -> size + digits + 2] = '0' + (size_t)(n * 100) % 10;
    temp[this -> size + digits + 3] = '\0';

    this -> str = temp;
    this -> size += digits + 3;

    return *this;

}

char &String::operator [](const size_t index){
    
    if(index >= this -> size) throw out_of_range("Index is out of range");
    return this -> str[index];
    
}

const char &String::operator [](const size_t index) const{
    
    if(index >= this -> size) throw out_of_range("Index is out of range");
    return this -> str[index];
    
}

size_t String::length() const{ return this -> size; }
const char *String::c_str() const{ return this -> str; }

bool String::contains(const char character) const{

    for(size_t i = 0; i < this -> size; i++)
        if(this -> str[i] == character)
            return true;
    
    return false;

}

bool String::contains(const char *substring) const{

    for(size_t substringSize = strlen(substring), i = 0; i < this -> size - substringSize; i++)
        if(this -> substring(i, i + substringSize) == *this) return true;

    return false;

}

bool String::contains(const String &substring) const{

    for(size_t i = 0; i < this -> size - substring.size; i++)
        if(this -> substring(i, i + substring.size) == *this) return true;

    return false;

}

int String::find(const char character) const{

    for(size_t i = 0; i < this -> size; i++)
        if(this -> str[i] == character)
            return i;
    
    return -1;

}

int String::find(const char *substring) const{

    for(size_t substringSize = strlen(substring), i = 0; i < this -> size - substringSize; i++)
        if(this -> substring(i, i + substringSize) == *this)
            return i;

    return -1;

}

int String::find(const String &substring) const{

    for(size_t i = 0; i < this -> size - substring.size; i++)
        if(this -> substring(i, i + substring.size) == *this)
            return i;

    return -1;

}

String String::substring(const size_t end) const{

    String result;
    for(size_t i = 0; i < end; i++) result += this -> str[i];

    return result;

}

String String::substring(const size_t start, const size_t len) const{

    String result;
    for(size_t i = 0; i < len; i++) result += this -> str[start + i];

    return result;

}

ostream &operator <<(ostream &os, const String &obj){

    os << obj.str;
    return os;

}
istream &operator >>(istream &is, String &obj){

    char buffer[1024];
    
    is >> setw(1024) >> buffer;
    obj = String(buffer);

    return is;

}
bool operator ==(const String &lhs, const String &rhs){

    if(lhs.length() != rhs.length()) return false;

    for(size_t i = 0; i < lhs.length(); i++)
        if(lhs[i] != rhs[i]) return false;

    return true;

}
bool operator ==(const String &lhs, const char *rhs){

    if(lhs.length() != strlen(rhs)) return false;

    for(size_t i = 0; i < lhs.length(); i++)
        if(lhs[i] != rhs[i]) return false;

    return true;

}

bool operator !=(const String &lhs, const char *rhs){ return !(lhs == rhs); }
bool operator !=(const String &lhs, const String &rhs){ return !(lhs == rhs); }

String operator +(const String &lhs, const String &rhs){

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