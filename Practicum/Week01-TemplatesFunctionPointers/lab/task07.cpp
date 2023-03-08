#include <iostream>

template <typename DataType, typename OpType>
OpType fold(DataType* arr, std::size_t size, OpType(*op)(const OpType&, const DataType&), OpType acc);

int max2(const int& firstNum, const int& secondNum);

bool anyEven(const bool& res, const int& num);

int main() {
    constexpr std::size_t ARR_SIZE{ 5 };
    int arr[ARR_SIZE]{ 1, 2, 8, 4, 5 };

    std::cout << fold(arr, ARR_SIZE, max2, arr[0]) << std::endl; // 8
    std::cout << std::boolalpha << fold(arr, ARR_SIZE, anyEven, false) << std::endl; // true

    return 0;
}

template <typename DataType, typename OpType>
OpType fold(DataType* arr, std::size_t size, OpType(*op)(const OpType&, const DataType&), OpType acc) {
    for (std::size_t index{ 0 }; index < size; ++index) {
        acc = op(acc, arr[index]);
    }

    return acc;
}

int max2(const int& firstNum, const int& secondNum) {
    return std::max(firstNum, secondNum);
}

bool anyEven(const bool& res, const int& num) {
    return res || num % 2 == 0;
}
