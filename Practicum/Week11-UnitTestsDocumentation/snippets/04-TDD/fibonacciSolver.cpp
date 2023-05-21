#include "fibonacciSolver.h"
#include <stdexcept>

long long FibonacciSolver::solve(int n)
{
    if (n <= 0)
    {
        throw std::invalid_argument("N must be positive");
    }

    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    // 3

    long long pre_prev = 0, prev = 1, result;
    for (int i = 0; i < n - 2; ++i)
    {
        result = pre_prev + prev;
        pre_prev = prev;
        prev = result;
    }

    return result;
}

// f(n) = f(n-1) + f(n-2)