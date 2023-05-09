#include <iostream>
#include <limits>
#include "../Headers/vehicleWorld.h"

const int MAX_BUFFER_SIZE = 100;

VehicleWorld::VehicleWorld(std::size_t garageCapacity)
{
    this->vehicleCollection = new VehicleCollection();

    try
    {
        this->garage = new Garage(garageCapacity);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        delete[] this->vehicleCollection;
    }
}

VehicleWorld::~VehicleWorld()
{
    delete this->vehicleCollection;
    delete this->garage;
}

void VehicleWorld::createVehicle()
{
    char tempRegistration[MAX_BUFFER_SIZE], tempDescription[MAX_BUFFER_SIZE];
    std::size_t tempSpaces;

    std::cout << "Please enter the details of the vehicle you want to create" << std::endl;
                
    std::cout << "Registration number: ";
    std::cin.getline(tempRegistration, MAX_BUFFER_SIZE);
    
    std::cout << "Description: ";
    std::cin.getline(tempDescription, MAX_BUFFER_SIZE);
    
    std::cout << "Required parking spaces: ";
    std::cin >> tempSpaces;   
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number: ";
        std::cin >> tempSpaces;
    }
    std::cin.ignore();

    std::cout << std::endl;

    this->vehicleCollection->allocateNewVehicle(tempRegistration, tempDescription, tempSpaces);
}

void VehicleWorld::addVehicleToGarage()
{
    char tempRegistration[MAX_BUFFER_SIZE];

    if (this->vehicleCollection->empty())
    {
        std::cout << "Currently you have not created any vehicles!" << std::endl;
        return;
    }

    std::cout << "Please enter the registration number of the vehicle you want to add to your garage: ";
    std::cin.getline(tempRegistration, MAX_BUFFER_SIZE);

    std::cout << std::endl;

    Vehicle* vehicle = this->vehicleCollection->find(tempRegistration);
    
    if (vehicle)
    {
        this->garage->insert(*vehicle);
    }
    else
    {
        std::cout << "You have not created a vehicle with such registration number!" << std::endl;
    }
}

void VehicleWorld::destroyVehicle()
{
    char tempRegistration[MAX_BUFFER_SIZE];

    if (this->vehicleCollection->empty())
    {
        std::cout << "Currently you have not created any vehicles!" << std::endl;
        return;
    }
    
    std::cout << "Please enter the registration number of the vehicle you want to destroy: ";
    std::cin.getline(tempRegistration, MAX_BUFFER_SIZE);

    std::cout << std::endl;

    if (this->garage->find(tempRegistration))
    {
        this->garage->erase(tempRegistration);
    }
    this->vehicleCollection->deallocateVehicle(tempRegistration);
}

void VehicleWorld::destroyAllVehicles()
{
    if (this->vehicleCollection->empty())
    {
        std::cout << "Currently you have not created any vehicles!" << std::endl;
        return;
    }

    if (!this->garage->empty())
    {
        this->garage->clear();
    }
    this->vehicleCollection->destroyAll();
}

void VehicleWorld::getVehicleOutOfGarage()
{
    char tempRegistration[MAX_BUFFER_SIZE];

    if (this->garage->empty())
    {
        std::cout << "Your garage is still empty!" << std::endl;
        return;
    }

    std::cout << "Please enter the registration number of the vehicle you want to get out of the garage: ";
    std::cin.getline(tempRegistration, MAX_BUFFER_SIZE);

    std::cout << std::endl;

    this->garage->erase(tempRegistration);
}

void VehicleWorld::clearGarage()
{
    if (this->garage->empty())
    {
        std::cout << "Your garage is still empty!" << std::endl;
        return;
    }
    this->garage->clear();
}

void VehicleWorld::printVehicleCollection()
{
    std::cout << *(this->vehicleCollection) << std::endl;
}
void VehicleWorld::printGarage()
{
    std::cout << *(this->garage) << std::endl;
}

std::ostream& operator << (std::ostream& out, const VehicleWorld& vehicleWorld)
{
    out << " ------------------------------------ " << std::endl;
    out << "|          THE VEHICLE WORLD         |" << std::endl;
    out << " ------------------------------------ " << std::endl;
    out << std::endl;
    out << "--------COLLECTION OF VEHICLES--------" << std::endl;
    out << *(vehicleWorld.vehicleCollection) << std::endl;
    out << std::endl;
    out << "----------------GARAGE----------------" << std::endl;
    out << *(vehicleWorld.garage) << std::endl;

    return out;
}