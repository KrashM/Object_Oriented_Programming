#include <iostream>
#include <cstring>
#include "Developer.h"

using std::cin;
using std::cout;

int main(){

    Developer me;
    me.readFromFile();
    cout << me.toString() << '\n';

    char *mld = new char[1], *mFirstName = new char[1], *mLastName = new char[1], pos[16];

    cin >> mld >> mFirstName >> mLastName >> pos;
    Developer newDev(mld, mFirstName, mLastName, Developer::translateToPos(pos));

    cout << newDev.toString() << '\n';
    newDev.saveToFile();
    newDev.readFromFile();

    cout << newDev.toString() << '\n';

}