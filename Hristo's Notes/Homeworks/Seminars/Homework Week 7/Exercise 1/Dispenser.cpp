#include "Dispenser.h"

const bool Dispenser::addBeverage(const Beverage &bev){

    if(this -> beverages.contains(bev)) return false;
    this -> beverages.pushBack(bev);
    return true;

}

const bool Dispenser::fillBeverage(const Beverage &bev, double lieters){

    if(!this -> beverages.contains(bev)) return false;
    this -> beverages[this -> beverages.getIndex(bev)].addLieters(lieters);

    return true;

}

const double Dispenser::buyBeverage(const char *bevName, const double money, const double quantity){

    for(int i = 0; i < this -> beverages.getSize(); i++)
        if(!strcmp(this -> beverages[i].getName(), bevName)){

            if(this -> beverages[i].getLieters() <= quantity){

                const double priceToTake = this -> beverages[i].getLieters() * this -> beverages[i].getPrice();
                this -> income += priceToTake;
                this -> beverages.removeAt(i);
                return money - priceToTake;

            }
            else{

                this -> income += money;
                if(this -> beverages[i].getPrice() * quantity > money) return -1;

            }

        }

    return -2;

}

const double Dispenser::getIncome() const{ return this -> income; }