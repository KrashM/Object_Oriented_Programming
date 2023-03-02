#include <iostream>

template <typename T>
bool cmp1(T a, T b)
{
    return a < b;
}

template <typename T>
bool cmp2(T a, T b)
{
    return a > b;
}

bool cmp3(int a, int b)
{
    return std::abs(a) > std::abs(b);
}

template <typename T>
void sort(T* arr, std::size_t size, bool (*compareFunction) (T, T))
{
    for (std::size_t i = 0; i < size - 1; ++i)
    {
        for (std::size_t j = i + 1; j < size; ++j)
        {
            if (compareFunction(arr[i], arr[j]))
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
void print(const T* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main ()
{
    int intArr[] = {5, -2, 3, 8, -7, 10};
    int intSize = 6;

    char charArr[] = {'p', 'e', 's', 'h', 'o'};
    int charSize = 5;

    sort<int>(intArr, intSize, cmp1<int>);
    print(intArr, intSize);
    sort<int>(intArr, intSize, cmp2<int>);
    print(intArr, intSize);
    sort<int>(intArr, intSize, cmp3);
    print(intArr, intSize);
    
    sort<char>(charArr, charSize, cmp1<char>);
    print(charArr, charSize);
    sort<char>(charArr, charSize, cmp2<char>);
    print(charArr, charSize);

    return 0;
}