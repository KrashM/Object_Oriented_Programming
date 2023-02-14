#include "LicenceKey.h"

LicenceKey::LicenceKey(){

    this -> key = 0;
    this -> numberOfCopies = 0;
    this -> maxNumberOfCopies = 0;

}

LicenceKey::LicenceKey(int key, int maxNumberOfCopies){

    if(key > 9999999 && key < 100000000) this -> key = key;
    // Catch this error
    else throw -2;
    this -> maxNumberOfCopies = maxNumberOfCopies;
    this -> numberOfCopies = 0;

}

int LicenceKey::activate(){

    if(this -> numberOfCopies == this -> maxNumberOfCopies) throw -1;
    this -> numberOfCopies++;
    return this -> key;

}