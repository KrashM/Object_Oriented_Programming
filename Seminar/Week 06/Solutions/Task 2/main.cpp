#include "ComplexNumber.hpp"

using std::cin;
using std::cout;

int main(){

    ComplexNumber c;
	cin >> c;

	ComplexNumber c2;
	cin >> c2;

	ComplexNumber result = c2 / c;

	cout << result << '\n';

}