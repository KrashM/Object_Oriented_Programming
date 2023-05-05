#ifndef VEHICLE_COLLECTION_H
#define VEHICLE_COLLECTION_H

#include "vehicle.h"

const int INITIAL_CAPACITY = 2;
const int INCREASE_STEP = 2;

class VehicleCollection
{
private:
    Vehicle** vehicles;
    std::size_t size;
    std::size_t capacity;

    void resize();
    void deallocate();
    void copy(const VehicleCollection& other);

public:
    VehicleCollection();
    VehicleCollection(const VehicleCollection& other);
    VehicleCollection& operator = (const VehicleCollection& other);
    ~VehicleCollection(); 
    
    void allocateNewVehicle(const char* registration, const char* description, std::size_t space);
    void deallocateVehicle(const char* registration);

    std::size_t getSize() const;
    std::size_t getCapacity() const;
    
    const Vehicle& operator [] (std::size_t index) const;

    Vehicle* find(const char* registration);
    
    void destroyAll();
    bool empty() const;

    friend std::ostream& operator << (std::ostream& out, const VehicleCollection& vehicleCollection);
};

#endif
