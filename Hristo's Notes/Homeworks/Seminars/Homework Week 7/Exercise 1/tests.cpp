#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest.h"
#include "Dispenser.h"

TEST_SUITE("Testing dispenser class"){

    TEST_CASE("Test default constructor"){

        Dispenser dis;
        CHECK_EQ(dis.getIncome(), 0);

    }

}