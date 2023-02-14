#include "ParamDefn.h"
#include <cmath>

using std::log10;

ParamDefn::ParamDefn(const char *varName, const char *varValue){

    if(!nameIsValid(varName)) throw invalid_argument("Variable name is incorrect");
    if(!valueIsValid(varValue)) throw invalid_argument("Variable value is incorrect");

    this -> varName = new char[strlen(varName) + 1];
    this -> varValue = new char[strlen(varValue) + 1];

    strcpy(this -> varName, varName);
    strcpy(this -> varValue, varValue);

}

bool contains(const size_t *array, const size_t size, const size_t element){

    for(size_t i = 0; i < size; i++)
        if(array[i] == element) return false;
    return true;

}

void ParamDefn::insert(const size_t index, const size_t cutout, const char *insertion){

    cout << this -> varValue << '\n' << index << '\n' << cutout << '\n' << insertion << '\n';
    size_t size = strlen(this -> varValue), insertionSize = strlen(insertion);
    char *temp = new char[size + insertionSize + 1];
    for(size_t i = 0; i < index; i++) temp[i] = this -> varValue[i];
    for(size_t i = 0; i < insertionSize; i++) temp[index + i] = insertion[i];
    for(size_t i = index; i < size; i++) temp[i + insertionSize] = this -> varValue[i + cutout];
    cout << temp << '\n';
    cout << "Size: " << size + insertionSize << '\n';
    temp[size + insertionSize] = '\0';

    cout << temp << '\n';

    delete[] this -> varValue;
    this -> varValue = temp;

}

void ParamDefn::print(){

    size_t size = strlen(this -> varValue), numberOfParams = 0;
    char *input = new char[101];

    for(size_t i = 0; i < size; i++)
        if(this -> varValue[i] == '#') numberOfParams++;

    size_t paramIndexes[numberOfParams], paramValues[numberOfParams], indexesIndex = 0, valuesIndex = 0, uniqueValues = 0;

    for(size_t i = 0; i < size - 1; i++){

        if(this -> varValue[i] == '#'){

            paramIndexes[indexesIndex++] = i;
            size_t value = 0, powTen = 1;
            i++;
            for(; i < size; i++){

                if(!(this -> varValue[i] >= '0' && this -> varValue[i] <= '9')) break;
                value += (this -> varValue[i] - '0') * powTen;
                powTen *= 10;
    
            }
            uniqueValues += contains(paramValues, valuesIndex, value);
            paramValues[valuesIndex++] = value;

        }

    }

    for(size_t i = 0; i < uniqueValues; i++){

        cin >> setw(100) >> input;

        size_t paramIndex = 1;

        for(size_t j = 0; j < numberOfParams; j++)
            if(paramValues[j] == i + 1){
                insert(paramIndexes[j], (size_t)log10(paramValues[j]) + 2, input);
                cout << "After insertion: " << this -> varValue << '\n';
            }

    }

    cout << this -> varValue << '\n';


}

bool ParamDefn::valueIsValid(const char *value){

    size_t size = strlen(value);
    for(size_t i = 0; i < size - 1; i++)
        if(value[i] == '#' && (value[i + 1] >= '0' && value[i + 1] <= '9')) return true;
    return false;

}