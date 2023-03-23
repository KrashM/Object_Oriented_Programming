#pragma once

class CPU{

    private:
        double HZ;
        unsigned CORES, CACHE;

        void copyFrom(CPU const &);

    public:
        CPU();
        CPU(double const &, unsigned const &, unsigned const &);
        CPU(CPU const &);

        CPU &operator =(CPU const &);

        void print() const;

};