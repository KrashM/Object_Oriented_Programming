#include <cstring>
#include "catch2/catch2.hpp"
#include "../Headers/garage.h"
#include "../Headers/vehicle.h"

TEST_CASE ("constructor with parameter")
{
    Garage myGarage(20);

    REQUIRE (myGarage.size() == 0);
    REQUIRE (myGarage.empty());
    REQUIRE_THROWS (myGarage.at(0), "Invalid index");
}

TEST_CASE ("adding vehicles")
{
    Garage myGarage(10);
    Vehicle peshoCar("V 3945 PK", "Pesho's car", 1);
    Vehicle peshoYacht("V 3946 PK", "Pesho's yacht", 5);
    Vehicle peshoPlane("V 3947 PK", "Pesho's plane", 10);

    REQUIRE_NOTHROW (myGarage.insert(peshoCar));
    REQUIRE_NOTHROW (myGarage.insert(peshoYacht));
    //REQUIRE_THROWS (myGarage.insert(peshoPlane), "There is not enough space in the garage");
    //REQUIRE_THROWS (myGarage.insert(peshoCar), "A vehicle with the same registration number is already in the garage");
    REQUIRE (myGarage.size() == 2);
    REQUIRE_THROWS (myGarage.at(2), "Invalid index");
}

TEST_CASE ("removing vehicles")
{
    Garage myGarage(20);
    Vehicle peshoCar("V 3945 PK", "Pesho's car", 1);
    Vehicle peshoYacht("V 3946 PK", "Pesho's yacht", 5);
    Vehicle peshoPlane("V 3947 PK", "Pesho's plane", 10);

    myGarage.insert(peshoCar);
    myGarage.insert(peshoYacht);
    myGarage.insert(peshoPlane);

    myGarage.erase("V 3945 PK");
    REQUIRE (myGarage.size() == 2);

    myGarage.erase("V 3945 PK");
    REQUIRE (myGarage.size() == 2);

    myGarage.erase("V 3948 PK");
    REQUIRE (myGarage.size() == 2);

    myGarage.erase("V 3946 PK");
    REQUIRE (myGarage.size() == 1);

    myGarage.erase("V 3947 PK");
    REQUIRE (myGarage.size() == 0);

    REQUIRE_THROWS (myGarage.at(0), "Invalid index");
}

TEST_CASE("dunction `find`")
{
    Garage myGarage(20);
    Vehicle peshoCar("V 3945 PK", "Pesho's car", 1);
    Vehicle peshoYacht("V 3946 PK", "Pesho's yacht", 5);
    Vehicle peshoPlane("V 3947 PK", "Pesho's plane", 10);

    myGarage.insert(peshoCar);
    myGarage.insert(peshoYacht);
    myGarage.insert(peshoPlane);

    REQUIRE (myGarage.find("V 3948 PK") == nullptr);

    REQUIRE (strcmp(myGarage.find("V 3945 PK")->getRegistration(), "V 3945 PK") == 0);
}