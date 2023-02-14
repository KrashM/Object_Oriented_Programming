#include "complexNumber.h"

complexNumber::complexNumber(double a, double b){

    this->a = a;
    this->b = b;

}

complexNumber::complexNumber(){

    this->a = 0;
    this->b = 0;

}

void complexNumber::setValue(double a, double b){

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

    int copyA = a * 100, copyB = b * 100;

    int index = 0;
    if(copyA < 0){

        string[index] = '-';
        index++;
        copyA *= -1;

    }

    unsigned powTen = largestPowerOfTen(copyA);
    if(powTen < 100){

        string[index] = '0';
        index++;

    }
    while(powTen > 10 && copyA != 0){

        string[index] = '0' + (copyA / powTen) % 10;
        powTen /= 10;
        index++;

    }
    
    if(copyA != 0){

        string[index] = '.';
        index++;
        string[index] = '0' + (copyA / 10) % 10;
        index++;
        string[index] = '0' + (copyA / 1) % 10;
        index++;

    }

    if(copyB >= 0 && index != 0 && copyB != 0){

        string[index] = '+';
        index++;

    }

    if(copyB < 0){

        string[index] = '-';
        index++;
        copyB *= -1;

    }
    
    powTen = largestPowerOfTen(copyB);
    if(powTen < 100 && copyB != 0){

        string[index] = '0';
        index++;

    }
    while(powTen > 10){

        string[index] = '0' + (copyB / powTen) % 10;
        powTen /= 10;
        index++;

    }

    if(copyB != 0){

        string[index] = '.';
        index++;
        string[index] = '0' + (copyB / 10) % 10;
        index++;
        string[index] = '0' + (copyB / 1) % 10;
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