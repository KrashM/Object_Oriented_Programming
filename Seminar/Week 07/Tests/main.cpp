#define DOCTEST_CONFIG_IMPLEMENT
#include "../../utils/doctest.h"
#include "Athlete.hpp"
#include <cstring>

TEST_SUITE("Testing the getters"){

    TEST_CASE("Testing with parametric constructor"){

        Athlete a("Hristo", 3, 3, 3, false, "Tigri", Sport::Tennis);

        SUBCASE("Name"){
            CHECK_EQ(strcmp(a.getName(), "Hristo"), 0);
        }

        SUBCASE("Stamina"){
            CHECK_EQ(a.getStamina(), 3);
        }

        SUBCASE("Power"){
            CHECK_GE(a.getPower(), 3);
        }


    }

}

int main(){
    
    doctest::Context().run();

}