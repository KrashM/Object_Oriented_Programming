#include "Complex.h"
#include "../../../Converter.h"
#include <cstring>

Complex::Complex(int real, int imag){

    this -> real = real;
    this -> imag = imag;

}

const Complex &Complex::operator =(const Complex &other){

    if(this != &other){

        this -> real = other.real;
        this -> imag = other.imag;

    }

    return *this;

}

const Complex &Complex::operator +(const Complex &other){

    Complex temp(this -> real + other.real, this -> imag + other.imag);
    return temp;

}

const Complex &Complex::operator -(const Complex &other){

    Complex temp(this -> real - other.real, this -> imag - other.imag);
    return temp;

}

const Complex &Complex::operator *(const Complex &other){

    Complex temp(this -> real * other.real - this -> imag * other.imag, this -> real * other.imag + this -> imag * other.real);
    return temp;

}

const Complex &Complex::operator /(const Complex &other){

    Complex temp((this -> real * other.real + this -> imag * other.imag) / (Converter::pow(other.real, 2) + Converter::pow(other.imag, 2)), (this -> imag * other.real - this -> real * other.imag) / (Converter::pow(other.real, 2) + Converter::pow(other.imag, 2)));
    return temp;

}

const bool Complex::operator ==(const Complex &other) const{ return this -> real == other.real && this -> imag == other.imag; }
const bool Complex::operator !=(const Complex &other) const{ return !(*this == other); }

const char* Complex::toString() const{

    size_t digitsImag = Converter::numberOfDigits(this -> imag), digitsReal = Converter::numberOfDigits(this -> real);
    char *string = new char[digitsReal + digitsImag + 3];

    int copyA = this -> real, copyB = this -> imag;

    int index = 0;
    if(copyA < 0){

        string[index++] = '-';
        copyA *= -1;

    }

    unsigned powTen = Converter::pow(10, Converter::numberOfDigits(copyA) - 1);
    while(powTen != 0){

        string[index++] = '0' + (this -> real / powTen) % 10;
        powTen /= 10;

    }

    if(copyB >= 0 && index != 0) string[index++] = '+';
    if(copyB < 0){

        string[index++] = '-';
        copyB *= -1;

    }
    
    powTen = Converter::pow(10, Converter::numberOfDigits(copyB) - 1);
    while(powTen != 0){

        string[index++] = '0' + (this -> imag / powTen) % 10;
        powTen /= 10;

    }

    string[index++] = 'i';
    string[index] = '\0';

    return string;

}