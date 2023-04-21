#include <exception>
#include <iostream>
#include <cstddef>

using std::cout;
using std::size_t;
using std::out_of_range;
using std::invalid_argument;

class Array{

    public:
        Array(size_t const size){

            array = new int[size];
            this -> size = size;

        }
        Array(int const * const array, size_t const size): Array(size){

            if(!array) throw invalid_argument("Array was nullptr");

            for(size_t i = 0; i < size; ++i)
                this -> array[i] = array[i];

        }

        Array(Array const &other){
            copyFrom(other);
        }

        ~Array(){
            free();
        }

        Array &operator =(Array const &other){

            if(this == &other) return *this;

            free();
            copyFrom(other);

            return *this;

        }

        Array(Array &&other){

            array = other.array;
            size = other.size;

            other.array = nullptr;
            other.size = 0;

        }

        Array &operator =(Array &&other){

            if(this == &other) return *this;

            free();

            array = other.array;
            size = other.size;

            other.array = nullptr;

        }

        int &operator [](size_t const index){

            if(index < size) return array[index];
            throw std::out_of_range("Your index is out of range");

        }

        const int operator [](size_t const index) const{

            if(index < size) return array[index];
            throw std::out_of_range("Your index is out of range");

        }

    private:
        void copyFrom(Array const &other){

            array = new int[other.size];
            size = other.size;

            for(size_t i = 0; i < size; ++i)
                array[i] = other.array[i];

        }

        void free(){

            delete[] array;
            array = nullptr;

        }

        int *array;
        size_t size;

};

int main(){

    Array a(2);
    try{
        Array a2(nullptr, 4);
        a[3];
    }
    catch(out_of_range const &ex){
        std::cerr << ex.what() << '\n';
    }
    catch(invalid_argument const &ex){
        std::cerr << ex.what() << '\n';
    }
    catch(std::exception const &ex){
        std::cerr << ex.what() << '\n';
    }
    catch(...){
        std::cerr << "Exception occurred\n";
    }

    cout << "Hello\n";

}