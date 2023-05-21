#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "fibonacciSolver.h"

TEST_CASE("basic")
{
    FibonacciSolver solver;

    REQUIRE(solver.solve(1) == 0);
    REQUIRE(solver.solve(2) == 1);

    REQUIRE(solver.solve(5) == 3);
    REQUIRE(solver.solve(6) == 5);
    REQUIRE(solver.solve(7) == 8);

    REQUIRE_THROWS_AS(solver.solve(-1), std::invalid_argument);
    REQUIRE_THROWS_AS(solver.solve(0), std::invalid_argument);

    REQUIRE_EQ(solver.solve(51), 12586269025);
}