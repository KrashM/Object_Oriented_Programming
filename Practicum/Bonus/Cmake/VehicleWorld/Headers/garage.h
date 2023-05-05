#ifndef GARAGE_H
#define GARAGE_H

#include "vehicle.h"

class Garage
{
private:
    Vehicle** vehicles;
    std::size_t maxSpaces;
    std::size_t currentSpaces;
    std::size_t countVehicles;

    void deallocate();
    void copy(const Garage& other);

public:
    Garage(std::size_t size);
    Garage(const Garage& other);
    Garage& operator = (const Garage& other);
    ~Garage();

    void insert(Vehicle& v);
    void erase(const char* registration);

    const Vehicle& at(std::size_t pos) const;
    const Vehicle& operator [] (std::size_t pos) const;

    bool empty() const;
    void clear();

    std::size_t size() const;
    
    const Vehicle* find(const char* registration) const;

    friend std::ostream& operator << (std::ostream& out, const Garage& garage);
};

#endif
