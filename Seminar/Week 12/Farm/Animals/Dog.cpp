#include "Dog.hpp"

void Dog::sayHello() const{
	std::cout << "Hello, I am a Dog!\n";
}

Animal *Dog::clone() const{
	return new Dog(*this);;
}