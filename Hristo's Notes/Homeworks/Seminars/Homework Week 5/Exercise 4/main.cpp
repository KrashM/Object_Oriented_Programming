#include "LicenceKey.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){

    int key, maxCopies;
    cin >> key >> maxCopies;

    // how to catch error while still initializing
    LicenceKey lk(key, maxCopies);

    try{ cout << lk.activate() << '\n'; }
    catch(const int ex){ if(ex == -1) cout << "Max number of copies has been reached\n"; }
    

}