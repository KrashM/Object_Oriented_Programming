#include <iostream>
#include <cstring>
#include <cassert>
#include "../Headers/garage.h"

Garage::Garage(std::size_t size) : maxSpaces(size), currentSpaces(0), countVehicles(0)
{
    this->vehicles = new Vehicle*[size];
    
    for (std::size_t i = 0; i < this->maxSpaces; ++i)
    {
        this->vehicles[i] = nullptr;
    }
    
    std::cout << "Great! Your garage has been created successfully!" << std::endl;
}

void Garage::clear()
{
    for (std::size_t i = 0; i < maxSpaces; ++i)
    {
        this->vehicles[i] = nullptr;
    }

    this->currentSpaces = 0;
    this->countVehicles = 0;

    std::cout << "You have successfully cleared your garage!" << std::endl;
}

void Garage::deallocate()
{
    for (std::size_t i = 0; i < this->maxSpaces; ++i)
    {
        this->vehicles[i] = nullptr;
    }
    delete[] this->vehicles;
}

void Garage::copy(const Garage& other)
{
    Vehicle** buffer = nullptr;

    try
    {
        buffer = new Vehicle*[other.maxSpaces];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < other.maxSpaces; ++i)
    {
        buffer[i] = other.vehicles[i];
    }

    this->vehicles = buffer;
    this->maxSpaces = other.maxSpaces;
    this->currentSpaces = other.currentSpaces;
    this->countVehicles = other.countVehicles;
}

Garage::~Garage()
{
    this->deallocate();
}

Garage::Garage(const Garage& other)
{
    this->copy(other);
}

Garage& Garage::operator = (const Garage& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

void Garage::insert(Vehicle& v)
{
    try 
    {
        if (this->find(v.getRegistration()))
        {
            throw std::invalid_argument("A vehicle with the same registration number is already in the garage");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    
    try
    {
        if ((currentSpaces + v.getSpace()) > maxSpaces)
        {
            throw std::overflow_error("There is not enough space in the garage");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    
    this->vehicles[this->countVehicles++] = &v;
    this->currentSpaces += v.getSpace();

    std::cout << "Your vehicle has been added successfully!" << std::endl;
}

void Garage::erase(const char* registration)
{
    if (this->empty())
    {
        std::cout << "Your garage is still empty!" << std::endl;
        return;
    }

    int searchedVehicleIndex = -1;
    for (std::size_t i = 0; i < this->countVehicles; ++i)
    {
        if (strcmp(this->vehicles[i]->getRegistration(), registration) == 0)
        {
            searchedVehicleIndex = i;
            break;
        }
    }

    if (searchedVehicleIndex == -1)
    {
        std::cout << "There is not a vehicle with such registration number in the garage!" << std::endl;
        return;
    }

    this->currentSpaces -= this->vehicles[searchedVehicleIndex]->getSpace();

    this->vehicles[searchedVehicleIndex] = this->vehicles[this->countVehicles - 1];
    this->vehicles[this->countVehicles - 1] = nullptr;
    --this->countVehicles;

    std::cout << "Your vehicle has been removed from the garage successfully!" << std::endl;     
}

const Vehicle& Garage::at(std::size_t pos) const
{
    if (pos >= this->countVehicles)
    {
        throw std::out_of_range("Invalid index");
    }

    return *(this->vehicles[pos]);    
}

const Vehicle& Garage::operator [] (std::size_t pos) const
{
    assert (pos < this->countVehicles);

    return *(this->vehicles[pos]);
}

bool Garage::empty() const
{
    return this->countVehicles == 0;
}

std::size_t Garage::size() const
{
    return this->countVehicles;
}

const Vehicle* Garage::find(const char* registration) const
{
    int searchedVehicleIndex = -1;
    for (std::size_t i = 0; i < this->countVehicles; ++i)
    {
        if (strcmp(this->vehicles[i]->getRegistration(), registration) == 0)
        {
            searchedVehicleIndex = i;
            break;
        }
    }

    if (searchedVehicleIndex == -1)
    {
        return nullptr;
    }

    return this->vehicles[searchedVehicleIndex];
}

std::ostream& operator << (std::ostream& out, const Garage& garage)
{
    out << "Count of vehicles in the garage: " << garage.countVehicles << std::endl;
    out << "Currently occupied parking spaces: " << garage.currentSpaces << std::endl;
    out << "Count of parking spaces in the garage: " << garage.maxSpaces;

    if (!garage.empty())
    {
        out << std::endl;
        out << "The garage is " << (double)garage.currentSpaces/(double)garage.maxSpaces*100 << "% full" << std::endl;

        if (garage.maxSpaces - garage.currentSpaces > 0)
        {
            if (garage.maxSpaces - garage.currentSpaces == 1)
            {
                out << "There is 1 free space in the garage" << std::endl;
            }
            else
            {
                out << "There are " << garage.maxSpaces - garage.currentSpaces << " free spaces in the garage" << std::endl;
            }
        }

        out << std::endl;
        out << "------Vehicles in the garage------";
        for (std::size_t i = 0; i < garage.countVehicles; ++i)
        {
            out << std::endl << std::endl;
            out << "Vehicle #" << i+1 << ": " << std::endl;
            out << *(garage.vehicles[i]);
        }
    }

    return out;
}