#include <iostream> 
#include "../Headers/utils.h"

void introduction()
{
    std::cout << std::endl;
    std::cout << "\t\t\t" << "Hello! Welcome to the World Of Vahicles!" << std::endl << std::endl;
    std::cout << "Here you can create unlimited collection of vehicles and a garage with limited parking spaces!" << std::endl;
    std::cout << "Please enter the maximum amount of parking spaces in your garage: ";
}

void whatToDo()
{
    std::cout << "Now you can create some vehicles, add them to your garage, then get them out of it, etc..." << std::endl;
}

void menu()
{
    std::cout << std::endl;
    std::cout << "--------------------------MENU--------------------------" << std::endl;
    std::cout << "1. Create a vehicle" << std::endl;
    std::cout << "2. Destroy a vehicle" << std::endl;
    std::cout << "3. Destroy all vehicles" << std::endl;
    std::cout << "4. Print information about the collection of vehicles" << std::endl;
    std::cout << "5. Add a vehicle to the garage" << std::endl;
    std::cout << "6. Get a vehicle out of the garage" << std::endl;
    std::cout << "7. Clear your garage" << std::endl;
    std::cout << "8. Print information about the garage" << std::endl;
    std::cout << "9. Print information about the Vehicle World" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void bye()
{
    std::cout << "Bye, bye! Have a nice day!" << std::endl;
}