#include <iostream>

using std::cin;
using std::cout;

struct Sum{

    Sum();
    Sum(const size_t &);
    ~Sum();

    void add(const int &);
    void removeLast();

    void changeAt(const int &, const size_t &);

    int getSum() const;

    int *array;
    size_t capacity, size;

};

Sum::Sum(): array(new int[10]), capacity(10), size(0){}
Sum::Sum(const size_t &n): array(new int[n]), capacity(n), size(0){}

Sum::~Sum(){
    delete[] array;
}

void Sum::add(const int &number){

    if(size == capacity) return;
    array[size++] = number;

}

void Sum::removeLast(){

    if(size == 0) return;
    size--;

}

void Sum::changeAt(const int &number, const size_t &index){

    if(size <= index) return;
    array[index] = number;

}

int pow(const int &number, const int &power){

    if(power == 0) return 1;
    return number * pow(number, power - 1);

}

int Sum::getSum() const{

    int sum = 0;
    for(size_t i = 0; i < size; ++i)
        sum += pow(array[i], i);
    return sum;

}

int main(){

    {

        Sum sumator;

        sumator.add(4);
        sumator.add(2);

        cout << sumator.getSum() << '\n';

        sumator.add(5);

        cout << sumator.getSum() << '\n';

        sumator.removeLast();

        cout << sumator.getSum() << '\n';

        sumator.changeAt(5, 1);

        cout << sumator.getSum() << '\n';

    }

    cout << '\n';

    {

        Sum sumator(1);

        sumator.add(4);
        sumator.add(2);

        cout << sumator.getSum() << '\n';

        sumator.add(5);

        cout << sumator.getSum() << '\n';

        sumator.removeLast();

        cout << sumator.getSum() << '\n';

        sumator.changeAt(5, 0);

        cout << sumator.getSum() << '\n';

        sumator.add(5);

        cout << sumator.getSum() << '\n';

    }

}