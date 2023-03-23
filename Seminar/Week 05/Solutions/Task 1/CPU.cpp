#include "CPU.h"

CPU::CPU(): HZ(0), CORES(0), CACHE(0){}

CPU::CPU(double const &HZ, unsigned const &CORES, unsigned const &CACHE): HZ(HZ), CORES(CORES), CACHE(CACHE){}

CPU::CPU(CPU const &other){
    copyFrom(other);
}

CPU &CPU::operator =(CPU const &other){

    if(this != &other) copyFrom(other);
    return *this;

}

void CPU::print() const{
    cout << HZ << "HZ, " << CORES << "Cores, " << CACHE << "KB";
}

void CPU::copyFrom(CPU const &other){

    this -> HZ = other.HZ;
    this -> CORES = other.CORES;
    this -> CACHE = other.CACHE;

}