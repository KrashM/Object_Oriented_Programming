#include <iostream>

template <typename T>
T accumulate(T from, T to, T (*term)(T), T (*op)(T, T), T startingValue);

int main() {
    return 0;
}

template <typename T>
T accumulate(T from, T to, T (*term)(T), T (*op)(T, T), T startingValue) {
    for (; from <= to; ++from) {
        startingValue = op(startingValue, term(from));
    }

    return startingValue;
}
