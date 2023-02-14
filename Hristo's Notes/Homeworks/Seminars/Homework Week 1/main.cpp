#include "dynamicArray.h"
#include <iostream>

// dynamic array with a specified capacity and with certain number of elements (size)

// reason why the input argument for the array is of type int*&?
// create a header file with the declarations of the functions,
// move the definitions to a .cpp file
// show how they are used in main.cpp

int main(){

    DynamicArray list;

    list.allocateMemory();

    list.addElement(1);
    list.addElement(2);
    list.addElement(3);

    std::cout << "The capacity of the array is " << list.capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << list.size << std::endl;
    list.print();

    list.addElement(4, 2);

    std::cout << "\nThe capacity of the array is " << list.capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << list.size << std::endl;
    list.print();

    list.removeElement(0);
    list.removeElement(0);
    list.removeElement(0);

    std::cout << "\nThe capacity of the array is " << list.capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << list.size << std::endl;

    list.print();

    list.freeMemory();
    
}