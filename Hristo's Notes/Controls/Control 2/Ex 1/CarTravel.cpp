#include "CarTravel.hpp"
#include <iostream>
using std::cout;

CarTravel::CarTravel(): regNumber(nullptr), distance(0), travelTime(0){}
CarTravel::CarTravel(const size_t *regNumber, const size_t distance, const size_t travelTime): regNumber(new size_t[4]), distance(distance), travelTime(travelTime){

    for(size_t i = 0; i < 4; i++) this -> regNumber[i] = regNumber[i];

}
CarTravel::CarTravel(const CarTravel &other){ this -> copy(other); }
CarTravel &CarTravel::operator =(const CarTravel &other){

    if(this != &other) this -> copy(other);
    return *this;

}

void CarTravel::copy(const CarTravel &other){

    this -> regNumber = new size_t[4];
    for(size_t i = 0; i < 4; i++) this -> regNumber[i] = other.regNumber[i];
    this -> distance = other.distance;
    this -> travelTime = other.travelTime;

}

CarTravel *CarTravel::clone() const{

    CarTravel *newTravel = new CarTravel(*this);
    return newTravel;

}

size_t CarTravel::getTravelTime() const{ return this -> travelTime; }

void CarTravel::print() const{

    cout << "CarTravel duration: " << this -> travelTime << '\n'
        << "Car reg number: " << this -> regNumber << '\n'
        << "Distance with car: " << this -> distance << '\n';


}