#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest.h"
#include "Magic.h"

TEST_SUITE("Test the Magic class"){

    TEST_CASE("Test constructor"){

        Magic magical;
        CHECK_EQ(magical.getSize(), 0);
        CHECK_EQ(magical.getCapacity(), 1);

    }

    TEST_CASE("Test insert"){

        Magic magical;
        magical.insert(5);
        magical.insert(7);
        CHECK_EQ(magical.getSize(), 2);
        CHECK_EQ(magical.getCapacity(), 2);
        CHECK_EQ(magical.getElement(0), 5);

    }

    TEST_CASE("Test pop"){

        Magic magical;
        magical.insert(5);
        CHECK_EQ(magical.pop(), 5);

    }

}