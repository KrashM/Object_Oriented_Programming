#include "Product.hpp"
#include <cstring>
#include <iostream>

std::ostream &operator <<(std::ostream &os, Product::Size const &size){
    
    switch(size){

        case Product::Size::S: os << "S\n"; break;
        case Product::Size::M: os << "M\n"; break;
        case Product::Size::L: os << "L\n"; break;
        case Product::Size::XL: os << "XL\n"; break;
        case Product::Size::XXL: os << "XLL\n"; break;
        case Product::Size::XXXL: os << "XXXL\n"; break;
        default: os.setstate(std::ios::failbit); break;

    }

    return os;

}

Product::Product(char const * const name, double const price, Size const &size): _price(price), _size(size){

    if(!name) return;
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);

}

Product::Product(Product const &other){
    copy(other);
}

Product::Product(Product &&other):
    _name(std::move(other._name)), _price(other._price), _size(other._size){}

Product::~Product(){
    free();
}

Product &Product::operator =(Product const &other){

    if(this == &other) return *this;

    free();
    copy(other);

    return *this;

}

Product &Product::operator =(Product &&other){

    if(this == &other) return *this;

    free();
    
    _name = std::move(other._name);
    _price = other._price;
    _size = other._size;

    return *this;

}

void Product::print() const{

    std::cout << _name << '\n'
        << _price << '\n'
        << _size << '\n';

}

    
void Product::copy(Product const &other){

    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);

    _price = other._price;
    _size = other._size;

}

void Product::free(){

    delete[] _name;
    _name = nullptr;

}