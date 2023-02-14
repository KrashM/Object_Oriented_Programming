#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest.h"
#include "Laptop.h"
#include "CPU.h"
#include <cstring>
#include <iostream>

TEST_SUITE("Testing laptop class"){

    TEST_CASE("Test defalt constructor"){

        Laptop myLaptop;
        CHECK_EQ(strcmp(myLaptop.toString(), "Brand: \nModel: \nCPU: 0.00HZ 0Cores 0KB\nRAM: 0\nBattery: 0\nScreen size: 0.00\nPrice: 0.00"), 0);

    }
    
    TEST_CASE("Test parametric constructor"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        CHECK_EQ(strcmp(myLaptop.toString(), "Brand: Acer\nModel: Predator Helios 300\nCPU: 3.14HZ 8Cores 64KB\nRAM: 16\nBattery: 2500\nScreen size: 15.49\nPrice: 3800.50"), 0);

    }
    
    TEST_CASE("Test copy constructor"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        Laptop newLaptop(myLaptop);
        CHECK_EQ(strcmp(newLaptop.toString(), "Brand: Acer\nModel: Predator Helios 300\nCPU: 3.14HZ 8Cores 64KB\nRAM: 16\nBattery: 2500\nScreen size: 15.49\nPrice: 3800.50"), 0);

    }
    
    TEST_CASE("Test = operator"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        Laptop newLaptop = myLaptop;
        CHECK_EQ(strcmp(myLaptop.toString(), "Brand: Acer\nModel: Predator Helios 300\nCPU: 3.14HZ 8Cores 64KB\nRAM: 16\nBattery: 2500\nScreen size: 15.49\nPrice: 3800.50"), 0);

    }
    
    TEST_CASE("Test == operator"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        Laptop newLaptop = myLaptop;
        CHECK_EQ(myLaptop == newLaptop, true);

    }
    
    TEST_CASE("Test != operator"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        Laptop newLaptop = myLaptop;
        CHECK_EQ(myLaptop != newLaptop, false);

    }
    
    TEST_CASE("Test > operator"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        Laptop newLaptop = myLaptop;
        CHECK_EQ(myLaptop > newLaptop, false);

    }
    
    TEST_CASE("Test < operator"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        Laptop newLaptop = myLaptop;
        CHECK_EQ(myLaptop < newLaptop, false);

    }
    
    TEST_CASE("Test upgrade cpu"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        myLaptop.upgradeCPU(CPU(4.27, 16, 256));
        std::cout << myLaptop.toString() << '\n';
        CHECK_EQ(strcmp(myLaptop.toString(), "Brand: Acer\nModel: Predator Helios 300\nCPU: 4.27HZ 16Cores 256KB\nRAM: 16\nBattery: 2500\nScreen size: 15.49\nPrice: 3800.50"), 0);

    }
    
    TEST_CASE("Test upgrade ram"){

        Laptop myLaptop(CPU(3.14, 8, 64), 16, 3800.50, 15.49, "Acer", "Predator Helios 300", 2500);
        myLaptop.upgradeRAM(32);
        CHECK_EQ(strcmp(myLaptop.toString(), "Brand: Acer\nModel: Predator Helios 300\nCPU: 3.14HZ 8Cores 64KB\nRAM: 32\nBattery: 2500\nScreen size: 15.49\nPrice: 3800.50"), 0);

    }

}