#pragma once

#include "CPU.h"

class Laptop{

    private:
        CPU cpu;
        double price, screenSize;
        char *brandName, *model;
        unsigned ram, battery;

    public:
        Laptop();
        Laptop(const CPU cpu, const unsigned ram, const double price, const double screenSize, const char *brandName, const char *model, const unsigned battery);
        Laptop(const Laptop &other);
        ~Laptop();

        const Laptop& operator =(const Laptop &other);
        
        const bool operator ==(const Laptop &other);
        const bool operator !=(const Laptop &other);
        const bool operator >(const Laptop &other);
        const bool operator <(const Laptop &other);

        void upgradeCPU(const CPU &cpu);
        void upgradeRAM(const unsigned ram);

        const char *toString() const;

};