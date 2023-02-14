#include "WaterDispenser.h"

WaterDispenser::WaterDispenser(double liters, double maxLiters){

    this->liters = liters;
    this->maxLiters = maxLiters;

}

WaterDispenser::WaterDispenser(double maxLiters){

    this->liters = maxLiters;
    this->maxLiters = maxLiters;

}

bool WaterDispenser::dispence(double milliliters){

    if(milliliters/1000 > liters) return false;
    
    liters -= milliliters/1000;
    return true;

}

void WaterDispenser::refill(double liters){

    if(this->liters + liters > maxLiters) liters = maxLiters;
    else this->liters += liters;

}

double WaterDispenser::getLiters(){

    return this->liters;

}