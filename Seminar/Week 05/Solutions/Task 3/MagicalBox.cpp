#include "MagicalBox.hpp"
#include <time.h>

using std::min;

MagicalBox::MagicalBox(): array(nullptr), size(0){}

MagicalBox::MagicalBox(MagicalBox const &other){
    copyFrom(other);
}

MagicalBox::~MagicalBox(){
    free();
}

MagicalBox &MagicalBox::operator =(MagicalBox const &other){

    if(this != &other){

        free();
        copyFrom(other);

    }

    return *this;

}

void MagicalBox::insert(int const &item){

    resize(size + 1);
    array[size - 1] = item;

}

int MagicalBox::pop(){

    if(!size){

        cout << "List is empty can't pop\n";
        return INT_MIN;

    }

    srand(time(0));

    size_t index = rand() % size;
    int value = array[index];

    for(size_t i = index; i < size - 1; ++i)
        array[i] = array[i + 1];

    resize(size - 1);

    return value;

}

void MagicalBox::resize(size_t const &newSize){

    int *newArray = new int[newSize];
    for(size_t i = 0; i < min(size, newSize); ++i)
        newArray[i] = array[i];
    
    delete[] array;
    array = newArray;
    size = newSize;

}

void MagicalBox::copyFrom(MagicalBox const &other){

    size = other.size;
    array = new int[size];
    for(size_t i = 0; i < size; ++i)
        array[i] = other.array[i];

}

void MagicalBox::free(){
    delete[] array;
}