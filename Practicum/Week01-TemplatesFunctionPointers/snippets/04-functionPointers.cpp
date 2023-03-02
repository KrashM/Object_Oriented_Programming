#include <iostream>

void print(const int* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int sum(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    return a / b;
}

// typedef int (*binaryFunction) (int, int);
using binaryFunction = int (*) (int, int);

const char operations[] = {'+', '-', '*', '/'};
const binaryFunction functions[] = {sum, subtract, multiply, divide};
const std::size_t SIZE = sizeof(operations) / sizeof(operations[0]);

void calculate(int a, int b, char operation)
{
    for (std::size_t i = 0; i < SIZE; ++i)
    {
        if (operations[i] == operation)
        {
            std::cout << functions[i](a, b) << std::endl;
            return;
        }
    }
    std::cout << "Invalid operation!" << std::endl;
}

int main ()
{
    calculate(5, 3, '+');
    calculate(5, 3, '-');
    calculate(5, 3, '*');
    calculate(5, 3, '/');

    return 0;
}