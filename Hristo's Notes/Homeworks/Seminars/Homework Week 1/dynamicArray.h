#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

struct DynamicArray{

    int *array{nullptr};
    size_t capacity = 3, size = 0;
    
    // allocate the memory
    void allocateMemory();

    // delete the allocated memory
    void freeMemory();

    // reallocate memory with different capacity
    bool reallocateMemory();

    // resize the array, if necessary
    // double the size
    bool resize();

    // add element at the end of the array
    // if the size is less than the capacity, the array should be resized
    // resize the array, if necessary
    bool addElement(int newElem);

    // add element at a specified position of the array
    // resize if necessary
    bool addElement(int newElem, size_t position);

    // print the elements of the array
    void print();

    // remove the element at the specified position
    // if the number of elements are less than 1/4 of the capacity,
    // resize the array, use half of its capacity
    bool removeElement(size_t position);

};

#endif