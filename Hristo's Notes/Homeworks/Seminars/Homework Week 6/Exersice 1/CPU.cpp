#include "../../../Converter.h"
#include "CPU.h"
#include <cstring>

CPU::CPU(double HZ, int CORES, int CACHE){

    this -> HZ = HZ;
    this -> CORES = CORES;
    this -> CACHE = CACHE;

}

const CPU &CPU::operator =(const CPU &other){

    if(this != &other){

        this -> HZ = other.HZ;
        this -> CORES = other.CORES;
        this -> CACHE = other.CACHE;

    }

    return *this;

}

const bool CPU::operator ==(const CPU &other){

    return this -> HZ == other.HZ &&
    this -> CORES == other.CORES &&
    this -> CACHE == other.CACHE;

}

const bool CPU::operator !=(const CPU &other){

    return this -> HZ != other.HZ &&
    this -> CORES != other.CORES &&
    this -> CACHE != other.CACHE;

}

const char *CPU::toString() const{

    char *result = new char[20];
    result[0] = '\0';

    strcat(result, Converter::doubleToString(this -> HZ));
    strcat(result, "HZ ");
    strcat(result, Converter::intToString(this -> CORES));
    strcat(result, "Cores ");
    strcat(result, Converter::intToString(this -> CACHE));
    strcat(result, "KB\0");

    return result;

}