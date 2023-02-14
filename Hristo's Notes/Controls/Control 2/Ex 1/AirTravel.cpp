#include "AirTravel.hpp"
#include <cstring>
#include <iostream>

using std::cout;

AirTravel::AirTravel(): travelNumber(nullptr), flightTime(0){}
AirTravel::AirTravel(const char *travelNumber, const size_t flightTime): travelNumber(new char[strlen(travelNumber) + 1]), flightTime(flightTime){ strcpy(this -> travelNumber, travelNumber); }
AirTravel::AirTravel(const AirTravel &other){ this -> copy(other); }
AirTravel::~AirTravel(){ this -> free(); }
AirTravel &AirTravel::operator =(const AirTravel &other){

    if(this != &other){

        this -> free();
        this -> copy(other);

    }

    return *this;

}

void AirTravel::free(){ delete[] this -> travelNumber; }
void AirTravel::copy(const AirTravel &other){

    this -> travelNumber = new char[strlen(other.travelNumber) + 1];
    strcpy(this -> travelNumber, other.travelNumber);
    this -> flightTime = other.flightTime;
    
}

AirTravel *AirTravel::clone() const{

    AirTravel *newTravel = new AirTravel(*this);
    return newTravel;

}

size_t AirTravel::getTravelTime() const{ return this -> flightTime; }

void AirTravel::print() const{

    cout << "AirTravel duration: " << this -> flightTime << '\n'
        << "Travel number: " << this -> travelNumber << '\n';

}