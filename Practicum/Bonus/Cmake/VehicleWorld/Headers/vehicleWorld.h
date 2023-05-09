#ifndef VEHICLE_WORLD_H
#define VEHICLE_WORLD_H

#include "vehicleCollection.h"
#include "garage.h"

class VehicleWorld
{
private:
    VehicleCollection* vehicleCollection;
    Garage* garage;

public:
    VehicleWorld(std::size_t garageCapacity);
    VehicleWorld(const VehicleWorld& other) = delete;
    VehicleWorld& operator = (const VehicleWorld& other) = delete;
    ~VehicleWorld();

    void createVehicle();
    void addVehicleToGarage();
    void destroyVehicle();
    void destroyAllVehicles();
    void getVehicleOutOfGarage();
    void clearGarage();

    void printVehicleCollection();
    void printGarage();

    friend std::ostream& operator << (std::ostream& out, const VehicleWorld& vehicleWorld);
};

#endif