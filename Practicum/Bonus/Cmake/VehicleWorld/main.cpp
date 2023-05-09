#include <iostream>
#include <limits>
#include "Headers/vehicleWorld.h"
#include "Headers/utils.h"

const int MAX_BUFFER_SIZE = 100;

int main ()
{
    introduction();
    
    std::size_t garageCapacity;
    
    std::cin >> garageCapacity;   
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number: ";
        std::cin >> garageCapacity;
    }
    std::cin.ignore();

    std::cout << std::endl;

    VehicleWorld myVehicleWorld(garageCapacity);

    whatToDo();

    char tempRegistration[MAX_BUFFER_SIZE], tempDescription[MAX_BUFFER_SIZE];
    std::size_t tempSpaces;
    Vehicle* tempVehicle;
    unsigned int option;

    do
    {
        menu();

        std::cout << "Please choose an option: ";
        std::cin >> option;
        while (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number: ";
            std::cin >> option;
        }
        std::cin.ignore();

        std::cout << std::endl;
        
        switch (option)
        {
            case 0:
                break;

            case 1:
                myVehicleWorld.createVehicle();
                break;

            case 2:
                myVehicleWorld.destroyVehicle();
                break;

            case 3:
                myVehicleWorld.destroyAllVehicles();
                break;

            case 4:
                myVehicleWorld.printVehicleCollection();
                break;

            case 5:
                myVehicleWorld.addVehicleToGarage();
                break;

            case 6:
                myVehicleWorld.getVehicleOutOfGarage();
                break;

            case 7:
                myVehicleWorld.clearGarage();
                break;

            case 8:
                myVehicleWorld.printGarage();
                break;

            case 9:
                std::cout << myVehicleWorld;
                break;

            default:
                std::cout << "Invalid option! Try again!" << std::endl;
                break;
        }
    } while (option);
    
    bye();

    return 0;
}