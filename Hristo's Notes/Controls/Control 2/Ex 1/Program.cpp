#include "CombinedTravel.hpp"
#include <iostream>
#include <cstring>

using std::cout;

// TODO: Add class travel for car and air travel to inherit from
int main(){

    size_t regNumber[4] = {7, 0, 3, 2};
    CarTravel carTravel(regNumber, 100, 23);
    AirTravel airTravel("Hello", 50);
    const size_t destinationsCount = 3, freeTime = 10;
    char **destinations = new char *[destinationsCount];
    for(size_t i = 0; i < destinationsCount; i++) destinations[i] = new char[100];
    strcpy(destinations[0], "Hello");
    strcpy(destinations[1], "there");
    strcpy(destinations[2], "again");
    // TODO: fix constructor parameters
    CombinedTravel myTravel(carTravel, airTravel, destinations, destinationsCount, freeTime);

    myTravel.print();
    cout << myTravel.getDuration() << '\n';

}