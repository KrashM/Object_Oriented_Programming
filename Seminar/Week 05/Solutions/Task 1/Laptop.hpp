#pragma once

#include "CPU.hpp"

class Laptop{

    private:
        CPU cpu;
        double price, screenSize;
        char *brandName, *model;
        unsigned ram, battery;

        void copyFrom(Laptop const &);
        void free();

    public:
        Laptop();
        Laptop(CPU const &, unsigned const &, double const &, double const &, char const * const &, char const * const &, unsigned const &);
        Laptop(const Laptop &);
        ~Laptop();

        Laptop &operator =(const Laptop &);

        void upgradeCPU(CPU const &);
        void upgradeRAM(unsigned const &);

        void print() const;

};