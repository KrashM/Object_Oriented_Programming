#include "dynamicArray.h"
#include <iostream>

#define EXPANSION 2
#define SHRINK 4
using std::cout;

// allocate the memory
void DynamicArray::allocateMemory(){ this->array = new int[this->capacity]; }

// delete the allocated memory
void DynamicArray::freeMemory(){
    
    delete[] this->array;
    this->size = 0;
    this->capacity = 0;
    
}

// reallocate memory with different capacity
bool DynamicArray::reallocateMemory(){

    int *newArray = new int[this->capacity];
    if(newArray == nullptr) return false;
    for(int i = 0; i < this->size; i++)
        newArray[i] = this->array[i];
    delete[] this->array;
    this->array = newArray;
    return true;

}

// resize the array, if necessary
// double the size
bool DynamicArray::resize(){

    if(this->size < this->capacity) return true;

    this->capacity *= EXPANSION;
    return reallocateMemory();

}

// add element at the end of the array
// if the size is less than the capacity, the array should be resized
// resize the array, if necessary
bool DynamicArray::addElement(int newElem){

    if(this->size == this->capacity) resize();
    this->array[this->size] = newElem;
    this->size++;
    return true;

}

// add element at a specified position of the array
// resize if necessary
bool DynamicArray::addElement(int newElem, size_t position){

    if(position > this->size || position < 0) return false;

    if(this->size == this->capacity) resize();

    this->size++;
    for(int i = this->size - 1; i > position; i--)
        this->array[i] = this->array[i - 1];
    this->array[position] = newElem;

    return true;

}

// print the elements of the array
void DynamicArray::print(){

    cout << this->array[0];
    for(int i = 1; i < this->size; i++)
        cout << ' ' << this->array[i];

}

// remove the element at the specified position
// if the number of elements are less than 1/4 of the capacity,
// resize the array, use half of its capacity
bool DynamicArray::removeElement(size_t position){

    if(position > this->size || position < 0) return false;

    for(int i = position; i <= this->size; i++)
        this->array[i] = this->array[i + 1];
    this->size--;

    if(this->size < this->capacity / SHRINK){
        
        this->capacity /= 2;
        reallocateMemory();

    }

    return true;

}