#include <iostream>

int accumulate(int from, int to, int (*term)(int), int (*op)(int, int), int startingValue);

int id(int num);

int pow2(int num);

int sum(int firstNum, int secondNum);

int product(int firstNum, int secondNum);

int main() {
    std::cout << accumulate(1, 4, id, sum, 0) << std::endl; // 10
    std::cout << accumulate(1, 4, pow2, sum, 0) << std::endl; // 30
    std::cout << accumulate(1, 5, id, product, 1) << std::endl; // 120

    return 0;
}

int accumulate(int from, int to, int (*term)(int), int (*op)(int, int), int startingValue) {
    for (; from <= to; ++from) {
        startingValue = op(startingValue, term(from));
    }

    return startingValue;
}

int id(int num) {
    return num;
}

int pow2(int num) {
    return num * num;
}

int sum(int firstNum, int secondNum) {
    return firstNum + secondNum;
}

int product(int firstNum, int secondNum) {
    return firstNum * secondNum;
}
