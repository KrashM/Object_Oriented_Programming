#include <cstring>
#include "catch2/catch2.hpp"
#include "../Headers/vehicleCollection.h"

TEST_CASE ("default constructor, getters, function `empty`")
{
    VehicleCollection myVehicleCollection;

    REQUIRE (myVehicleCollection.getCapacity() == 2);
    REQUIRE (myVehicleCollection.getSize() == 0);
    REQUIRE (myVehicleCollection.empty());
}

TEST_CASE ("adding and removing vehicles, resizing, getters")
{
    VehicleCollection myVehicleCollection;
    myVehicleCollection.allocateNewVehicle("V 3945 PK", "Pesho's car", 1);

    SECTION ("adding a vehicle")
    {
        REQUIRE (myVehicleCollection.getCapacity() == 2);
        REQUIRE (myVehicleCollection.getSize() == 1);
        REQUIRE_FALSE (myVehicleCollection.empty());
        REQUIRE (strcmp(myVehicleCollection[0].getRegistration(), "V 3945 PK") == 0);
        REQUIRE (strcmp(myVehicleCollection[0].getDescription(), "Pesho's car") == 0);
        REQUIRE (myVehicleCollection[0].getSpace() == 1);
    }

    myVehicleCollection.allocateNewVehicle("V 1245 SN", "Sonya's yacht", 5);

    SECTION ("adding another vehicle")
    {
        REQUIRE (myVehicleCollection.getCapacity() == 2);
        REQUIRE (myVehicleCollection.getSize() == 2);
        REQUIRE_FALSE (myVehicleCollection.empty());
        REQUIRE (strcmp(myVehicleCollection[1].getRegistration(), "V 1245 SN") == 0);
        REQUIRE (strcmp(myVehicleCollection[1].getDescription(), "Sonya's yacht") == 0);
        REQUIRE (myVehicleCollection[1].getSpace() == 5);
    }

    myVehicleCollection.allocateNewVehicle("V 3946 PK", "Pesho's plane", 10);

    SECTION ("adding a third vehicle + resize")
    {
        REQUIRE (myVehicleCollection.getCapacity() == 4);
        REQUIRE (myVehicleCollection.getSize() == 3);
        REQUIRE_FALSE (myVehicleCollection.empty());
        REQUIRE (strcmp(myVehicleCollection[2].getRegistration(), "V 3946 PK") == 0);
        REQUIRE (strcmp(myVehicleCollection[2].getDescription(), "Pesho's plane") == 0);
        REQUIRE (myVehicleCollection[2].getSpace() == 10);
    }

    myVehicleCollection.allocateNewVehicle("V 1245 SN", "Sonya's yacht", 5);

    SECTION ("trying to add an already existing vehicle")
    {
        REQUIRE (myVehicleCollection.getCapacity() == 4);
        REQUIRE (myVehicleCollection.getSize() == 3);
        REQUIRE_FALSE (myVehicleCollection.empty());
        REQUIRE (strcmp(myVehicleCollection[2].getRegistration(), "V 3946 PK") == 0);
        REQUIRE (strcmp(myVehicleCollection[2].getDescription(), "Pesho's plane") == 0);
        REQUIRE (myVehicleCollection[2].getSpace() == 10);
    }

    myVehicleCollection.deallocateVehicle("V 3945 PK");

    SECTION ("removing a vehicle")
    {
        REQUIRE (myVehicleCollection.getCapacity() == 4);
        REQUIRE (myVehicleCollection.getSize() == 2);
        REQUIRE_FALSE (myVehicleCollection.empty());
        REQUIRE (strcmp(myVehicleCollection[0].getRegistration(), "V 3946 PK") == 0);
        REQUIRE (strcmp(myVehicleCollection[0].getDescription(), "Pesho's plane") == 0);
        REQUIRE (myVehicleCollection[0].getSpace() == 10);
        REQUIRE (strcmp(myVehicleCollection[1].getRegistration(), "V 1245 SN") == 0);
        REQUIRE (strcmp(myVehicleCollection[1].getDescription(), "Sonya's yacht") == 0);
        REQUIRE (myVehicleCollection[1].getSpace() == 5);
    }

    myVehicleCollection.deallocateVehicle("V 4040 PK");

    SECTION ("trying to remove a vehicle which is not created yet")
    {
        REQUIRE (myVehicleCollection.getCapacity() == 4);
        REQUIRE (myVehicleCollection.getSize() == 2);
        REQUIRE_FALSE (myVehicleCollection.empty());
        REQUIRE (strcmp(myVehicleCollection[0].getRegistration(), "V 3946 PK") == 0);
        REQUIRE (strcmp(myVehicleCollection[0].getDescription(), "Pesho's plane") == 0);
        REQUIRE (myVehicleCollection[0].getSpace() == 10);
        REQUIRE (strcmp(myVehicleCollection[1].getRegistration(), "V 1245 SN") == 0);
        REQUIRE (strcmp(myVehicleCollection[1].getDescription(), "Sonya's yacht") == 0);
        REQUIRE (myVehicleCollection[1].getSpace() == 5);
    }
}

TEST_CASE ("function `find`")
{
    VehicleCollection myVehicleCollection;
    myVehicleCollection.allocateNewVehicle("V 3945 PK", "Pesho's car", 1);
    myVehicleCollection.allocateNewVehicle("V 1245 SN", "Sonya's yacht", 5);
    myVehicleCollection.allocateNewVehicle("V 3946 PK", "Pesho's plane", 10);

    Vehicle* peshoCar = myVehicleCollection.find("V 3945 PK");
    Vehicle* sonyaYacht = myVehicleCollection.find("V 1245 SN");
    Vehicle* peshoPlane = myVehicleCollection.find("V 3946 PK");
    Vehicle* nullVehicle = myVehicleCollection.find("V 3333 PN");

    REQUIRE (strcmp(peshoCar->getRegistration(), "V 3945 PK") == 0);
    REQUIRE (strcmp(peshoCar->getDescription(), "Pesho's car") == 0);
    REQUIRE (peshoCar->getSpace() == 1);

    REQUIRE (strcmp(sonyaYacht->getRegistration(), "V 1245 SN") == 0);
    REQUIRE (strcmp(sonyaYacht->getDescription(), "Sonya's yacht") == 0);
    REQUIRE (sonyaYacht->getSpace() == 5);

    REQUIRE (strcmp(peshoPlane->getRegistration(), "V 3946 PK") == 0);
    REQUIRE (strcmp(peshoPlane->getDescription(), "Pesho's plane") == 0);
    REQUIRE (peshoPlane->getSpace() == 10);

    REQUIRE (nullVehicle == nullptr);
}

TEST_CASE ("destroying all vehicles")
{
    VehicleCollection myVehicleCollection;
    myVehicleCollection.allocateNewVehicle("V 3945 PK", "Pesho's car", 1);
    myVehicleCollection.allocateNewVehicle("V 1245 SN", "Sonya's yacht", 5);
    myVehicleCollection.allocateNewVehicle("V 3946 PK", "Pesho's plane", 10);

    myVehicleCollection.destroyAll();

    REQUIRE (myVehicleCollection.empty());
    REQUIRE (myVehicleCollection.getSize() == 0);
    REQUIRE (myVehicleCollection.getCapacity() == 4);
}