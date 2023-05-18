#include "Mouse.hpp"

void Mouse::sayHello() const{
	std::cout << "Hello, I am a Mouse!\n";
}

Animal *Mouse::clone() const{
	return new Mouse(*this);
}