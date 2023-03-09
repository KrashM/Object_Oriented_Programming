#include <iostream>

void bubbleSort(int* numbers, std::size_t size);

void insertInSorted(int* numbers, std::size_t size, int number);

void insertionSort(int* numbers, std::size_t size);

std::size_t minFrom(int* array, std::size_t from, std::size_t to);

void selectionSort(int* numbers, std::size_t size);

void sortNumbers(int* numbers, std::size_t size, void (*sorter) (int*, std::size_t));

void printArray(int* numbers, std::size_t size);

int main () {
    constexpr std::size_t ARR_CAPCITY{ 100 };
    
    std::size_t size;
    int numbersBubble[ARR_CAPCITY], numbersInsertion[ARR_CAPCITY], numbersMerge[ARR_CAPCITY];

    std::cin >> size;

    for (std::size_t index{ 0 }; index < size; ++index) {
        int number{ 0 };

        std::cin >> number;
        
        numbersBubble[index] = number;
        numbersInsertion[index] = number;
        numbersMerge[index] = number;
    }

    sortNumbers(numbersBubble, size, bubbleSort);
    std::cout << "Bubble sort: ";
    printArray(numbersBubble, size);

    sortNumbers(numbersInsertion, size, insertionSort);
    std::cout << "Insertion sort: ";
    printArray(numbersInsertion, size);

    sortNumbers(numbersMerge, size, selectionSort);
    std::cout << "Selection sort: ";
    printArray(numbersMerge, size);

    return 0;
}

void bubbleSort(int* numbers, std::size_t size) {
    bool changed{ false };
    std::size_t end{ 0 };

    do {
        changed = false;
        for (std::size_t index{ size - 1 }; index > end; --index) {
            if (numbers[index] < numbers[index - 1]) {
                std::swap(numbers[index], numbers[index - 1]);
                
                changed = true;
            }
        }

        ++end;
    } while (changed);   
}

void insertInSorted(int numbers[], std::size_t size, int number) {
    std::size_t i{ size };
    
    while (i > 0 && numbers[i-1] > number) {
        numbers[i] = numbers[i-1];
        --i;
    }

    numbers[i] = number;
}

void insertionSort(int* numbers, std::size_t size) {
    for (std::size_t index{ 1 }; index < size; ++index) {
        insertInSorted(numbers, index, numbers[index]);
    }
}

std::size_t minFrom(int* numbers, std::size_t from, std::size_t to) {
    std::size_t min{ from };

    for (std::size_t index{ from + 1 }; index < to; ++index) {
        if (numbers[index] < numbers[min]) {
            min = index;
        }
    }

    return min;
}

void selectionSort(int* numbers, std::size_t size) {
    for (std::size_t index{ 0 }; index < size - 1; ++index) {
        int minIndex = minFrom(numbers, index, size);
        
        std::swap(numbers[index], numbers[minIndex]);
    } 
}

void sortNumbers(int* numbers, std::size_t size, void (*sort) (int*, std::size_t)) {
    sort(numbers, size);
}

void printArray(int* numbers, std::size_t size) {
    for (std::size_t index{ 0 }; index < size; ++index) {
        std::cout << numbers[index] << ' ';
    }
    std::cout << std::endl;
}
