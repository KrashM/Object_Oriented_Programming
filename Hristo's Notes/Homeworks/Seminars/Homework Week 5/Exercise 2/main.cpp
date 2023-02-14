#include <iostream>
#include "BrowserTab.h"

using std::cin;
using std::cout;

int main(){

    char *URL = new char[100], *HTML = new char[100];
    cin >> URL >> HTML;

    BrowserTab bt(URL, HTML);
    cout << bt.getURL() << '\n' << bt.getHTML() << '\n';

    BrowserTab bt2(bt);
    cout << bt2.getURL() << '\n' << bt2.getHTML() << '\n';

}