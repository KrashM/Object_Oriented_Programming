#ifndef VEHICLE_H
#define VEHICLE_H

#include "myString.h"

class Vehicle
{
private:
    MyString registration;
    MyString description;
    std::size_t space;

public:
    Vehicle(const char* registration, const char* description, std::size_t space);

    const char* getRegistration() const;
    const char* getDescription() const;
    std::size_t getSpace() const;

    friend std::ostream& operator << (std::ostream& out, const Vehicle& vehicle);
};

#endif