#include "Cat.hpp"

void Cat::sayHello() const{
	std::cout << "Hello, I am a Cat!\n";
}

Animal *Cat::clone() const{
	return new Cat(*this);
}