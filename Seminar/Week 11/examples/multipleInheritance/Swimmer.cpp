#include "Swimmer.h"

#include <iostream>

Swimmer::Swimmer(): Animal()
{
	//std::cout << "Swimmer constructor called\n";
}

Swimmer::~Swimmer()
{
	std::cout << "Swimmer detructor called\n";
}

void Swimmer::print()
{
	Animal::print();
	std::cout << "Hi, I'm a swimmer!\n";
}
