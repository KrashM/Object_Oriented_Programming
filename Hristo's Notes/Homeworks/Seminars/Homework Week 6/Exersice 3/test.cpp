#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest.h"
#include "Complex.h"
#include <cstring>

TEST_SUITE("test the constructors of the complex class"){

    TEST_CASE("test parametric constructor"){

        Complex c(1, 3);
        CHECK_EQ(strcmp(c.toString(), "1+3i"), 0);

    }

    TEST_CASE("test operator ="){

        Complex c(2, 4);
        Complex z = c;
        CHECK_EQ(strcmp(z.toString(), "2+4i"), 0);

    }

}