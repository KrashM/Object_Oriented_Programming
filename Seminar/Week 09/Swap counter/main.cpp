#include <iostream>
#include <cstdint>
#include <cstddef>

class SwapCounter{

public:
    template <typename T>
	static void swap(T &, T &);

	static void resetCount();
	static uint32_t getCount();

private:
	static uint32_t count;

};

uint32_t SwapCounter::count = 0;

template <typename T>
void SwapCounter::swap(T &a, T &b){

    T temp = a;
    a = b;
    b = temp;
    count++;

}

uint32_t SwapCounter::getCount(){ return count; }

void SwapCounter::resetCount(){ count = 0; }

void print(int const * const arr, std::size_t const size){

	for(std::size_t i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << '\n';

}

void bubbleSort(int * const arr, std::size_t const size){

	for(std::size_t i = 0; i < size - 1; ++i){

		bool isSwapped = false;
		for(std::size_t j = 0; j < size - 1 - i; ++j){

			if(arr[j + 1] < arr[j]){

				SwapCounter::swap(arr[j], arr[j + 1]);
				isSwapped = true;

			}

		}

		if(!isSwapped) return;

	}

}

void selectionSort(int * const arr, std::size_t const size){

	for(std::size_t i = 0; i < size - 1; i++){

		int minElIndex = i;
		for(int j = i + 1; j < size; j++)
			if(arr[j] < arr[minElIndex])
				minElIndex = j;

		if(minElIndex != i)
			SwapCounter::swap(arr[minElIndex], arr[i]);

	}

}



int main(){

	{

		int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
		bubbleSort(arr, 10);
		std::cout << "Bubble sort swaps: " << SwapCounter::getCount() << '\n';

	}
	{

		SwapCounter::resetCount();
		int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
		selectionSort(arr, 10);
		std::cout << "Selection sort swaps: " << SwapCounter::getCount() << '\n';

	}

}