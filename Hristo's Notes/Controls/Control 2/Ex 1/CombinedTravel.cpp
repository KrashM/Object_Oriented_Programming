#include "CombinedTravel.hpp"
#include <cstring>
#include <iostream>
using std::cout;

CombinedTravel::CombinedTravel(): travelWithCar(nullptr), travelWithAir(nullptr), destinations(nullptr), numberOfDestinations(0), freeTime(0){}
CombinedTravel::CombinedTravel(const CarTravel *&travelWithCar, const AirTravel *&travelWithAir, const char **destinations, const size_t numberOfDestinations, const size_t freeTime): travelWithCar(travelWithCar->clone()), travelWithAir(travelWithAir->clone()), destinations(new char *[numberOfDestinations]), numberOfDestinations(numberOfDestinations), freeTime(freeTime){

    for(size_t i = 0; i < numberOfDestinations; i++){

        this -> destinations[i] = new char[strlen(destinations[i]) + 1];
        strcpy(this -> destinations[i], destinations[i]);

    }
    
}
CombinedTravel::CombinedTravel(const CombinedTravel &other){ this -> copy(other); }
CombinedTravel::~CombinedTravel(){ this -> free(); }
CombinedTravel &CombinedTravel::operator=(const CombinedTravel &other){

    if(this != &other){

        this -> free();
        this -> copy(other);

    }

    return *this;

}

size_t CombinedTravel::getDuration() const{

    size_t time = 0;
    time += this -> travelWithAir -> getTravelTime();
    time += this -> travelWithCar -> getTravelTime();
    time += this -> freeTime;

    return time;

}
void CombinedTravel::print() const{

    this -> travelWithAir -> print();
    this -> travelWithCar -> print();
    cout << "Free time is: " << this -> freeTime << '\n';

}

void CombinedTravel::free(){

    for(size_t i = 0; i < this -> numberOfDestinations; i++)
        delete[] this -> destinations[i];
    delete[] this -> destinations;

}

void CombinedTravel::copy(const CombinedTravel &other){

    this -> travelWithCar = other.travelWithCar;
    this -> travelWithAir = other.travelWithAir;
    this -> numberOfDestinations = other.numberOfDestinations;
    this -> destinations = new char*[other.numberOfDestinations];
    for(size_t i = 0; i < other.numberOfDestinations; i++){

        this -> destinations[i] = new char[strlen(other.destinations[i]) + 1];
        strcpy(this -> destinations[i], other.destinations[i]);

    }
    this -> freeTime = other.freeTime;

}