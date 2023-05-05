#include <cstring>
#include <cassert>
#include "../Headers/vehicleCollection.h"

VehicleCollection::VehicleCollection() : size(0), capacity(INITIAL_CAPACITY)
{
    this->vehicles = new Vehicle*[INITIAL_CAPACITY];

    for (std::size_t i = 0; i < INITIAL_CAPACITY; ++i)
    {
        this->vehicles[i] = nullptr;
    }
}

VehicleCollection::~VehicleCollection()
{
    this->deallocate();
}

void VehicleCollection::deallocate()
{
    for (std::size_t i = 0; i < this->size; ++i)
    {
        delete this->vehicles[i];
    }
    delete[] this->vehicles;

    this->vehicles = nullptr;
}

void VehicleCollection::copy(const VehicleCollection& other)
{
    Vehicle** buffer = nullptr;

    try
    {
        buffer = new Vehicle*[other.capacity];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < other.capacity; ++i)
    {
        if (i < other.size)
        {
            try
            {
                buffer[i] = new Vehicle(*(other.vehicles[i]));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                for (std::size_t j = 0; j < i; ++j)
                {
                    delete buffer[j];
                }
                delete[] buffer;
                
                return;
            }
        }
        else
        {
            buffer[i] = nullptr; 
        }
    }

    this->vehicles = buffer;
    this->size = other.size;
    this->capacity = other.capacity;
}

VehicleCollection::VehicleCollection(const VehicleCollection& other)
{
    this->copy(other);
}

VehicleCollection& VehicleCollection::operator = (const VehicleCollection& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

void VehicleCollection::resize()
{
    Vehicle** newVehicles = nullptr;

    try
    {
        newVehicles = new Vehicle*[this->capacity * INCREASE_STEP];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < this->capacity * INCREASE_STEP; ++i)
    {
        newVehicles[i] = nullptr;
    }

    for (std::size_t i = 0; i < this->capacity; ++i)
    {
        try
        {
            newVehicles[i] = new Vehicle(*(this->vehicles[i]));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            for (std::size_t j = 0; j < i; ++j)
            {
                delete newVehicles[j];
            }
            delete[] newVehicles;

            return;
        }
    }

    this->deallocate();
    this->capacity *= INCREASE_STEP;
    this->vehicles = newVehicles;
}

void VehicleCollection::allocateNewVehicle(const char* registration, const char* description, std::size_t space)
{
    if (this->size >= this->capacity)
    {
        this->resize();
    }

    if (this->find(registration))
    {
        std::cout << "You have already created a vehicle with the same registration number!" << std::endl;
        return;
    }

    try
    {
        this->vehicles[this->size] = new Vehicle(registration, description, space);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    
    ++this->size;
    std::cout << "You have successfully created the vehicle!" << std::endl;
}

const Vehicle& VehicleCollection::operator [] (std::size_t index) const
{
    assert (index < this->size);

    return *(this->vehicles[index]);
}

std::size_t VehicleCollection::getSize() const
{
    return this->size;
}

std::size_t VehicleCollection::getCapacity() const
{
    return this->capacity;
}

void VehicleCollection::deallocateVehicle(const char* registration)
{
    for (std::size_t i = 0; i < this->size; ++i)
    {
        if (strcmp(this->vehicles[i]->getRegistration(), registration) == 0)
        {
            delete this->vehicles[i];
            this->vehicles[i] = this->vehicles[this->size - 1];
            this->vehicles[this->size - 1] = nullptr;
            --this->size;

            std::cout << "You have successfully destroyed the vehicle!" << std::endl;

            return;
        }
    }

    std::cout << "You have not created a vehicle with such registration number!" << std::endl;
}

Vehicle* VehicleCollection::find(const char* registration)
{
    for (std::size_t i = 0; i < this->size; ++i)
    {
        if (strcmp(this->vehicles[i]->getRegistration(), registration) == 0)
        {
            return this->vehicles[i];
        }
    }

    return nullptr; 
}

void VehicleCollection::destroyAll()
{
    this->deallocate();
    this->size = 0;

    this->vehicles = new Vehicle*[INITIAL_CAPACITY];

    for (std::size_t i = 0; i < INITIAL_CAPACITY; ++i)
    {
        this->vehicles[i] = nullptr;
    }

    std::cout << "You have successfully destroyed all vehicles!" << std::endl;
}

bool VehicleCollection::empty() const
{
    return this->size == 0;
}

std::ostream& operator << (std::ostream& out, const VehicleCollection& vehicleCollection)
{
    out << "Number of created vehicles: " << vehicleCollection.getSize();
    if (!vehicleCollection.empty())
    {
        std::cout << std::endl;
    }
    for (std::size_t i = 0; i <vehicleCollection.size; ++i)
    {
        out << std::endl;
        out << "Vehicle #" << i+1 << ": " << std::endl;
        out << *(vehicleCollection.vehicles[i]) << std::endl;
    }

    return out;
}