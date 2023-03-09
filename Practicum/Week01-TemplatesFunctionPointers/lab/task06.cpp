#include <iostream>
#include <assert.h>

template <typename T>
void map(T* arr, std::size_t size, void (*mapper)(T&));

template <typename T>
std::size_t countPreds(T*& arr, std::size_t size, bool (*pred)(const T&));

template <typename T>
void filter(T*& arr, std::size_t& size, bool (*pred)(const T&));

void multBy2(int& num);

bool divBy4(const int& num);

void printer(int& num);

int main() {
    std::size_t size{ 5 };
    int* arr{ new (std::nothrow) int[5]{ 1, 2, 3, 4, 5 } };

    if (!arr) {
        std::cout << "Didn't allocate memory" << std::endl;

        return -1;
    }

    map(arr, size, multBy2);
    map(arr, size, printer);
    std::cout << std::endl;

    filter(arr, size, divBy4);
    map(arr, size, printer);
    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}

template <typename T>
void map(T* arr, std::size_t size, void (*mapper)(T&)) {
    for (std::size_t index = 0; index < size; ++index) {
        mapper(arr[index]);
    }
}

template <typename T>
std::size_t countPreds(T*& arr, std::size_t size, bool (*pred)(const T&)) {
    std::size_t counter{ 0 };
    
    for (std::size_t index{ 0 }; index < size; ++index) {
        if (pred(arr[index])) {
            ++counter;
        }
    }

    return counter;
}

template <typename T>
void filter(T*& arr, std::size_t& size, bool (*pred)(const T&)) {
    const std::size_t newSize{ countPreds(arr, size, pred) };

    if (newSize == 0) {
        arr = nullptr;
        size = 0;

        return;
    }

    T* newArr{ new (std::nothrow) T[newSize] };

    if (!newArr) {
        assert("Couldn't allocate memory");
    }

    std::size_t newArrIndex{ 0 };

    for (std::size_t index{ 0 }; index < size; ++index) {
        if (pred(arr[index])) {
            newArr[newArrIndex++] = arr[index];
        }
    }

    delete[] arr;
    arr = newArr;
    size = newSize;
}

void multBy2(int& num) {
    num *= 2;
}

bool divBy4(const int& num) {
    return num % 4 == 0;
}

void printer(int& num) {
    std::cout << num << ' ';
}
