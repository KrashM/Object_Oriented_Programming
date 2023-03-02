#include <iostream>

template <typename T>
struct DummyArray
{   
    T* array;
    std::size_t size;
};

template <typename T>
void init(DummyArray<T>& array, std::size_t size);

template <typename T>
void fill(DummyArray<T>& array, std::size_t size, T elem);

template <typename T>
void print(DummyArray<T>& array, std::size_t size);

const std::size_t SIZE = 5;

int main ()
{
    DummyArray<int> intArr;
    init(intArr, SIZE);
    fill(intArr, SIZE, 4);
    print(intArr, SIZE);

    DummyArray<char> charArr;
    init(charArr, SIZE);
    fill(charArr, SIZE, 'p');
    print(charArr, SIZE);

    delete[] intArr.array;
    delete[] charArr.array;
}

template <typename T>
void init(DummyArray<T>& array, std::size_t size)
{
    if (size == 0)
    {
        array.array = nullptr;
        array.size = 0;
        return;
    }

    array.size = size;
    array.array = new (std::nothrow) T[size];
    if (!array.array)
    {
        array.size = 0;
        return;
    }
}

template <typename T>
void fill(DummyArray<T>& array, std::size_t size, T elem)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        array.array[i] = elem;
    }
}

template <typename T>
void print(DummyArray<T>& array, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << array.array[i] << " ";
    }
    std::cout << std::endl;
}