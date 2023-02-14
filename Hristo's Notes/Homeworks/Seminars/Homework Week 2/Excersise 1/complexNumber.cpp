#include "complexNumber.h"

unsigned largestPowerOfTen(int n){

    unsigned pow = 1;
    while(pow * 10 < n) pow *= 10;

    return pow;

}

char* complexNumber::toString(){

    char *string = new char[100];

    int copyA = a, copyB = b;

    int index = 0;
    if(copyA < 0){

        string[index] = '-';
        index++;
        copyA *= -1;

    }

    unsigned powTen = largestPowerOfTen(copyA);
    while(copyA != 0){

        string[index] = '0' + copyA / powTen;
        copyA = copyA % powTen;
        powTen /= 10;
        index++;

    }

    if(copyB >= 0 && index != 0){

        string[index] = '+';
        index++;

    }

    if(copyB < 0){

        string[index] = '-';
        index++;
        copyB *= -1;

    }
    
    powTen = largestPowerOfTen(copyB);
    while(copyB != 0){

        string[index] = '0' + copyB / powTen;
        copyB = copyB % powTen;
        powTen /= 10;
        index++;

    }

    string[index] = 'i';
    string[index + 1] = '\0';

    return string;

}