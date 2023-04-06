// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_DISABLE
#include "../../utils/doctest.h"
#include "Athlete.hpp"
#include <cstring>

TEST_SUITE("Testing the getters"){

    TEST_CASE("Name getter"){

        Athlete a("Hristo", 3, 3, 3, false, "Tigri", Sport::Tennis);
        CHECK_EQ(strcmp(a.getName(), "Hristo"), 0);

    }

    TEST_CASE("Stamina getter"){

        Athlete a("Hristo", 3, 3, 3, false, "Tigri", Sport::Tennis);
        CHECK_EQ(a.getStamina(), 3);

    }

    TEST_CASE("Power getter"){

        Athlete a("Hristo", 3, 3, 3, false, "Tigri", Sport::Tennis);
        CHECK_GE(a.getPower(), 3);

    }

}

TEST_SUITE("Testing the setters"){

    TEST_CASE("Name"){

        Athlete a("Hristo", 3, 3, 3, false, "Tigri", Sport::Tennis);
        CHECK_EQ(strcmp(a.getName(), "Hristo"), 0);

    }

}