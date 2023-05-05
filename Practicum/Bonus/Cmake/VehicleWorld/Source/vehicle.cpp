#include <iostream>
#include "../Headers/vehicle.h"

Vehicle::Vehicle(const char* registration, const char* description, std::size_t space) 
                : registration(registration), description(description), space(space) {}
    
const char* Vehicle::getRegistration() const
{
    return this->registration.c_str();
}

const char* Vehicle::getDescription() const
{
    return this->description.c_str();
}

std::size_t Vehicle::getSpace() const
{
    return this->space;
}

std::ostream& operator << (std::ostream& out, const Vehicle& vehicle)
{
    out << "Registration: " << vehicle.getRegistration() << std::endl;
    out << "Description: " << vehicle.getDescription() << std::endl;
    out << "Occupied parking spaces: " << vehicle.getSpace();

    return out;
}