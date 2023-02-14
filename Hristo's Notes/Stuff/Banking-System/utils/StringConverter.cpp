#include "StringConverter.hpp"
#include <math.h>

const char *StringConverter::doubleToString(const double value){

    size_t numberOfDigitsWholePart = (size_t)log10(value) + 1, powerOfTen = 1;
    char *result = new char[numberOfDigitsWholePart + 4];

    for(size_t i = 0; i < numberOfDigitsWholePart; i++){

        result[numberOfDigitsWholePart - i - 1] = '0' + (size_t)(value / powerOfTen) % 10;
        powerOfTen *= 10;

    }

    result[numberOfDigitsWholePart] = '.';
    result[numberOfDigitsWholePart + 1] = '0' + (size_t)(value * 10) % 10;
    result[numberOfDigitsWholePart + 2] = '0' + (size_t)(value * 100) % 10;
    result[numberOfDigitsWholePart + 3] = '\0';

    return result;

}