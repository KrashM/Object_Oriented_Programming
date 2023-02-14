#include <iostream>
#include "HexViewer.h"

using std::cin;
using std::cout;

int main(){

    char fileName[50];
    cout << "Enter a file path:\n>";
    cin >> fileName;
    cin.get();
    HexViewer hexview(fileName);
    if(hexview.fail()) return -1;
    while(hexview.menu());

    return 0;

}