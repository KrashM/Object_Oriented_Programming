#include "Beverage.h"
#include <cstring>

Beverage::Beverage(){

    this -> name = new char[1];
    this -> name[0] = '\0';
    this -> lieters = 0;
    this -> price = 0;
    this -> calories = 0;

}

Beverage::Beverage(const char *name, const double lieters, const double price, const int calories){

    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
    this -> lieters = lieters;
    this -> price = price;
    this -> calories = calories;

}

Beverage::Beverage(const Beverage &bev){

    this -> name = new char[strlen(bev.name) + 1];
    strcpy(this -> name, bev.name);
    this -> lieters = bev.lieters;
    this -> price = bev.price;
    this -> calories = bev.calories;

}

Beverage::~Beverage(){

    delete[] this -> name;

}

const bool Beverage::operator ==(const Beverage &other){

    return !strcmp(this -> name, other.name) &&
        this -> lieters == other.lieters &&
        this -> price == other.price &&
        this -> calories == other.calories;

}

const bool Beverage::operator >(const Beverage &other){ return this -> calories > other.calories; }

void Beverage::addLieters(const double lieters){ this -> lieters += lieters; }
const char *Beverage::getName() const{ return this -> name; }
const double Beverage::getPrice() const{ return this -> price; }
const double Beverage::getLieters() const{ return this -> lieters; }