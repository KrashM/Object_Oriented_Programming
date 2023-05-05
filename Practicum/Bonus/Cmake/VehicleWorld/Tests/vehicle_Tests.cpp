#include <cstring>
#include "catch2/catch2.hpp"
#include "../Headers/vehicle.h"

TEST_CASE ("constructor and getters")
{
    SECTION ("non-null vehicle")
    {
        Vehicle myVehicle("V 2356 ST", "my car", 2);

        CHECK (strcmp(myVehicle.getRegistration(), "V 2356 ST") == 0);
        CHECK (strcmp(myVehicle.getDescription(), "my car") == 0);
        CHECK (myVehicle.getSpace() == 2);
    }

    SECTION ("null vehicle")
    {
        Vehicle myVehicle(nullptr, nullptr, 0);

        CHECK (myVehicle.getDescription() == nullptr);
        CHECK (myVehicle.getRegistration() == nullptr);
        CHECK (myVehicle.getSpace() == 0);
    }   
}