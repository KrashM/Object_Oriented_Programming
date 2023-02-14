#include "BrowserTab.h"
#include <cstring>

BrowserTab::BrowserTab(){

    this -> URL = nullptr;
    this -> HTML = nullptr;
    
}

BrowserTab::BrowserTab(const BrowserTab &bt){

    this -> URL = new char[strlen(bt.URL) + 1];
    this -> HTML = new char[strlen(bt.HTML) + 1];
    strcpy(this -> URL, bt.URL);
    strcpy(this -> HTML, bt.HTML);

}

// Non constant reference not sure if prefered
// BrowserTab::BrowserTab(BrowserTab &bt){

//     this -> URL = bt.getURL();
//     this -> HTML = bt.getHTML();

// }

BrowserTab::BrowserTab(const char *URL, const char *HTML){

    this -> URL = new char[strlen(URL) + 1];
    this -> HTML = new char[strlen(HTML) + 1];
    strcpy(this -> URL, URL);
    strcpy(this -> HTML, HTML);
    
}

BrowserTab::~BrowserTab(){

    delete[] this -> URL;
    delete[] this -> HTML;

}

char *BrowserTab::getURL(){ return this -> URL; }
char *BrowserTab::getHTML(){ return this -> HTML; }