#pragma once

#include "Beverage.h"
#include "../../../Vector.h"

class Dispenser{

    private:
        Vector<Beverage> beverages;
        double income;

    public:
        Dispenser():income{0}{}
        const bool addBeverage(const Beverage &bev);
        const bool fillBeverage(const Beverage &bev, double lieters);
        const double buyBeverage(const char *bevName, const double money, const double quantity);
        const double getIncome() const;
    
};