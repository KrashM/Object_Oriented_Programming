#include "complexNumber.h"

complexNumber::complexNumber(int a, int b){

    this->a = a;
    this->b = b;

}

unsigned largestPowerOfTen(int n){

    unsigned pow = 1;
    while(pow * 10 <= n) pow *= 10;

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
    while(powTen > 0 && copyA != 0){

        string[index] = '0' + (copyA / powTen) % 10;
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
    while(powTen > 0){

        string[index] = '0' + (copyB / powTen) % 10;
        powTen /= 10;
        index++;

    }

    if(b != 0){

        string[index] = 'i';
        index++;

    }
    string[index] = '\0';

    return string;

}

complexNumber complexNumber::operator +(complexNumber n){

    complexNumber temp(a + n.a, b + n.b);
    return temp;

}

complexNumber complexNumber::operator *(complexNumber n){

    complexNumber temp(a * n.a + b * n.b * -1, a * n.b + b * n.a);
    return temp;

}