#include "Laptop.hpp"

int main(){

    Laptop myLaptop;
    myLaptop.print();

    cout << '\n';

    Laptop otherLaptop(CPU(3.4, 8, 64), 16, 2500, 15.7, "Acer", "Nitro 5", 5000);
    otherLaptop.print();

    otherLaptop.upgradeRAM(32);
    otherLaptop.print();

}