#include <iostream>
#include <functional>
#include <string>

template <typename T>
class MyDummyArray
{
private:
    static const std::size_t INITIAL_CAPACITY = 2;
    static const std::size_t INCREASE_STEP = 2;

    T* arr;
    std::size_t size;
    std::size_t capacity;

    void resize()
    {
        T* newArr = new T[this->capacity * INCREASE_STEP];

        for (std::size_t i = 0; i < this->size; ++i)
        {
            newArr[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = newArr;
        this->capacity *= INCREASE_STEP;
    }

    void copy(const MyDummyArray<T>& other)
    {
        this->arr = new T[other.capacity];

        for (std::size_t i = 0; i < other.size; ++i)
        {
            this->arr[i] = other.arr[i];
        }

        this->size = other.size;
        this->capacity = other.capacity;
    }

    void deallocate()
    {
        delete[] this->arr;
    }

public:
    MyDummyArray()
        : size(0), capacity(INITIAL_CAPACITY), arr(new T[INITIAL_CAPACITY]) 
    {}

    MyDummyArray(const T* arr, std::size_t size)
        : size(0), capacity(INITIAL_CAPACITY), arr(new T[INITIAL_CAPACITY])
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            this->push_back(arr[i]);
        }
    }

    MyDummyArray(const MyDummyArray<T>& other) 
    {
        this->copy(other);
    }

    MyDummyArray& operator = (const MyDummyArray<T>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }
    
    ~MyDummyArray()
    {
        this->deallocate();
    }

    void push_back(const T& element)
    {
        if (this->size == this->capacity)
        {
            resize();
        }

        this->arr[this->size++] = element;
    }

    void print(const char* label) const
    {
        std::cout << label << ": ";
        for (std::size_t i = 0; i < this->size; ++i)
        {
            std::cout << "[" << this->arr[i] << "] ";
        }
        std::cout << std::endl;
    }

    MyDummyArray<T> filter(std::function<bool(const T&)> predicate)
    {
        MyDummyArray<T> result;

        for (std::size_t i = 0; i < this->size; ++i)
        {
            if (predicate(this->arr[i]))
            {
                result.push_back(this->arr[i]);
            }
        }

        return result;
    }

    template <typename R>
    MyDummyArray<R> map(std::function<R(const T&)> mapper)
    {
        MyDummyArray<R> result;

        for (std::size_t i = 0; i < this->size; ++i)
        {
            result.push_back(mapper(this->arr[i]));
        }

        return result;
    }

    template <typename R>
    R reduce(const R& init, std::function<R(const R&, const T&)> reducer)
    {
        R result = init;

        for (std::size_t i = 0; i < this->size; ++i)
        {
            result = reducer(result, this->arr[i]);
        }

        return result;
    }
};

bool isPositive(int number)
{
    return number > 0;
}


int main ()
{
    int raw[] = {1, 5, 3, 2, 7, -4, -10, 16, 100};
    std::size_t sizeArr = sizeof(raw) / sizeof(raw[0]);

    MyDummyArray<int> numbers(raw, sizeArr);
    numbers.print("Original");

    MyDummyArray<int> even = numbers.filter([](int el)->bool{return el % 2 == 0;});
    even.print("Even numbers");

    MyDummyArray<int> positive = numbers.filter(isPositive);
    positive.print("Positive numbers");

    std::string rawStrings[] = {"Hello", "kak", "si", "haresvash", "li", "kaka", "Presi", "???"};
    std::size_t sizeStrings = sizeof(rawStrings) / sizeof(rawStrings[0]);

    MyDummyArray<std::string> strings(rawStrings, sizeStrings);
    strings.print("Strings");

    MyDummyArray<std::size_t> sizes = strings.map<std::size_t>([](const std::string& str)->std::size_t{return str.size();});
    sizes.print("String sizes");

    MyDummyArray<int> squares = numbers.map<int>([](int el)->int{return el * el;});
    squares.print("Squares");

    std::string concatenatedString = strings.reduce<std::string>("", [](const std::string& acc, const std::string& newStr)->std::string{return acc + " " +  newStr;});
    std::cout << concatenatedString << std::endl;

    std::size_t sumLengts = strings.reduce<std::size_t>(0, [](std::size_t acc, const std::string& newStr)->std::size_t{return acc + newStr.size();});
    std::cout << sumLengts << std::endl;

    return 0;
}