#include "NaturalNumbers.h"
#include <cstring>
#include <iostream>

using std::getline;

NaturalNumbers::NaturalNumbers():numbers(nullptr), numberOfElements(0){

    const char defaultName[] = "Empty set";
    this -> name = new char[strlen(defaultName) + 1];
    strcpy(this -> name, defaultName);

}

NaturalNumbers::NaturalNumbers(const double *numbers, const char *name, const size_t numberOfElements){

    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
    this -> numbers = new double[numberOfElements];
    for(size_t i = 0; i < numberOfElements; i++)
        this -> numbers[i] = numbers[i];
    this -> numberOfElements = numberOfElements;

}

NaturalNumbers::NaturalNumbers(const NaturalNumbers &other){

    this -> name = new char[strlen(other.name) + 1];
    strcpy(this -> name, other.name);
    this -> numbers = new double[other.numberOfElements];
    for(size_t i = 0; i < other.numberOfElements; i++)
        this -> numbers[i] = other.numbers[i];
    this -> numberOfElements = other.numberOfElements;

}

NaturalNumbers::~NaturalNumbers(){

    delete[] this -> name;
    delete[] this -> numbers;

}

const double *NaturalNumbers::getNumbers() const{ return this -> numbers; }
const char *NaturalNumbers::getName() const{ return this -> name; }
const size_t NaturalNumbers::getNumberOfElements() const{ return this -> numberOfElements; }

void NaturalNumbers::setName(const char *name){
    
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);

}
void NaturalNumbers::setNumberOfElements(const size_t numberOfElements){ this -> numberOfElements = numberOfElements; }
void NaturalNumbers::setNumbers(const double *numbers){

    this -> numbers = new double[this -> numberOfElements];
    for(size_t i = 0; i < this -> numberOfElements; i++)
        this -> numbers[i] = numbers[i];

}

NaturalNumbers &NaturalNumbers::operator *(const NaturalNumbers &other) const{

    // 21 Length of 'Intersection of  and '
    // Create the new name
    char *newName = new char[strlen(this -> name) + strlen(other.name) + strlen("Intersection of  and ") + 1];
    newName[0] = '\0';
    strcat(newName, "Intersection of ");
    strcat(newName, this -> name);
    strcat(newName, " and ");
    strcat(newName, other.name);

    // Find how many numbers intersect
    size_t numberOfElementsInNewSet = 0;
    for(size_t i = 0; i < this -> numberOfElements; i++)
        for(size_t j = 0; j < other.numberOfElements; j++)
            if(this -> numbers[i] == other.numbers[j]){

                numberOfElementsInNewSet++;
                break;

            }
    
    // Create array with size = the number of elements that intersect
    double *newNumbers = new double[numberOfElementsInNewSet];
    size_t index = 0;
    for(size_t i = 0; i < this -> numberOfElements; i++)
        for(size_t j = 0; j < other.numberOfElements; j++)
            if(this -> numbers[i] == other.numbers[j]){

                newNumbers[index] = this -> numbers[i];
                index++;
                break;

            }

    NaturalNumbers temp;
    temp.setName(newName);
    temp.setNumberOfElements(numberOfElementsInNewSet);
    temp.setNumbers(newNumbers);
    return temp;

}

NaturalNumbers &NaturalNumbers::operator *=(const NaturalNumbers &other){

    // 21 Length of 'Intersection of  and '
    // Create the new name
    char *newName = new char[strlen(this -> name) + strlen(other.name) + strlen("Intersection of  and ") + 1];
    newName[0] = '\0';
    strcat(newName, "Intersection of ");
    strcat(newName, this -> name);
    strcat(newName, " and ");
    strcat(newName, other.name);

    // Find how many numbers intersect
    size_t numberOfElementsInNewSet = 0;
    for(size_t i = 0; i < this -> numberOfElements; i++)
        for(size_t j = 0; j < other.numberOfElements; j++)
            if(this -> numbers[i] == other.numbers[j]){

                numberOfElementsInNewSet++;
                break;

            }
    
    // Create array with size = the number of elements that intersect
    double *newNumbers = new double[numberOfElementsInNewSet];
    size_t index = 0;
    for(size_t i = 0; i < this -> numberOfElements; i++)
        for(size_t j = 0; j < other.numberOfElements; j++)
            if(this -> numbers[i] == other.numbers[j]){

                newNumbers[index] = this -> numbers[i];
                index++;
                break;

            }

    this -> name = new char[strlen(newName) + 1];
    strcpy(this -> name, newName);
    this -> numberOfElements = numberOfElements;
    this -> numbers = new double[numberOfElements];
    for(size_t i = 0; i < numberOfElements; i++)
        this -> numbers[i] = newNumbers[i];
    return *this;

}

const bool &NaturalNumbers::operator [](const size_t number) const{

    for(size_t i = 0; i < this -> numberOfElements; i++)
        if(this -> numbers[i] == number)
            return true;

    return false;

}

void operator >>(istream &is, NaturalNumbers &rhs){

    char name[100];
    size_t numberOfElements;
    is >> name >> numberOfElements;
    double numbers[numberOfElements];
    for(size_t i = 0; i < rhs.getNumberOfElements(); i++)
        is >> numbers[i];

    rhs.setName(name);
    rhs.setNumberOfElements(numberOfElements);
    rhs.setNumbers(numbers);

}

ostream &operator <<(ostream &os, const NaturalNumbers &rhs){

    os << rhs.name << '\n';
    for(size_t i = 0; i < rhs.numberOfElements; i++)
        os << rhs.numbers[i] << '\n';
    os << rhs.numberOfElements << '\n';

    return os;

}