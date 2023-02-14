#include "Pencil.h"
#include <cstring>

Pencil::Pencil():brand(""), year(0), hardness(0){}

Pencil::Pencil(const char *brand, const unsigned year, const short hardness){

    strcpy(this -> brand, brand);
    this -> year = year;
    this -> hardness = hardness;

}

Pencil::Pencil(const Pencil &other){

    strcpy(this -> brand, other.brand);
    this -> year = other.year;
    this -> hardness = other.hardness;

}

const Pencil &Pencil::operator =(const Pencil &other){

    if(this != &other){

        strcpy(this -> brand, other.brand);
        this -> year = other.year;
        this -> hardness = other.hardness;

    }

    return *this;

}

const char *Pencil::getBrand() const{ return this -> brand; }
const unsigned Pencil::getYear() const{ return this -> year; }
const short Pencil::getHardness() const{ return this -> hardness; }

void Pencil::setBrand(const char *brand){ strcpy(this -> brand, brand); }
void Pencil::setYear(const unsigned year){ this -> year = year; }
void Pencil::setHardness(const short hardness){ this -> hardness = hardness; }

ostream &operator <<(ostream &os, const Pencil &pencil){

    os << pencil.getBrand() << ' ' << pencil.getYear() << ' ' << pencil.getHardness() << '\n';
    return os;

}