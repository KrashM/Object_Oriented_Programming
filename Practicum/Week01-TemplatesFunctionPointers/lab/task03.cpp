#include <iostream>
#include <assert.h>

template <typename T>
struct MyArray {
    T array[100];
    std::size_t size{ 0 };
};

template <typename T>
void pushBack(MyArray<T>& arr, const T& elem) {
    arr.array[size++] = elem;
}

template <typename T>
void popBack(MyArray<T>& arr) {
    arr.array[arr.size--] = 0;
}

template <typename T>
T at(const MyArray<T>& arr, std::size_t index) {
    if (index < 0 || index >= arr.size) {
        assert("Index out of bounds!");
    }
    
    return arr.array[index];
}

template <typename T>
bool empty(const MyArray<T>& arr) {
    return arr.size == 0;
}

template <typename T>
void print(const MyArray<T>& arr) {
    for (std::size_t index{ 0 }; index < arr.size; ++index) {
        std::cout << arr[index] << ' ';
    }

    std::cout << std::endl;
}
