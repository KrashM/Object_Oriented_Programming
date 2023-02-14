#include "WaterDispenser.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){

    cout << "Enter initialy liters:" << '\n';
    double liters;
    cin >> liters;

    cout << "Enter max capacity (liters):" << '\n';
    double maxLiters;
    cin >> maxLiters;

    WaterDispenser dispenser(liters, maxLiters);

    cout << "Fill a cup/bottle (milliliters):" << '\n';
    double dispecedMilliliters;
    cin >> dispecedMilliliters;

    if(!dispenser.dispence(dispecedMilliliters))
        cout << "Not enought water in the dispencer." << '\n';
    cout << "Dispenced:" << dispenser.getLiters() << '\n';

    cout << "Refill (liters):" << '\n';
    double fillAmount;
    cin >> fillAmount;

    dispenser.refill(fillAmount);
    cout << "Refilled:" << dispenser.getLiters();

}
