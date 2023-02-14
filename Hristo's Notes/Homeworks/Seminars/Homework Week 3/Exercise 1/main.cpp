#include "Timestamp.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){

    unsigned seconds;
    
    do{ cin >> seconds; } while(seconds <= 86399);
    Timestamp time1(seconds);
    
    do{ cin >> seconds; } while(seconds <= 86399);
    Timestamp time2(seconds);

    cout << time1.toString() << '\n';
    cout << time2.toString() << '\n';

    Timestamp time3 = Timestamp::add(time1, time2);
    cout << time3.toString() << '\n';

}