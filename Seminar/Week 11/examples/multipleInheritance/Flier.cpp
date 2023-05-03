#include "Flier.h"

#include <iostream>

Flier::Flier(): Animal()
{
	//std::cout << "Flier constructor called\n";
}

Flier::~Flier()
{
	std::cout << "Flier destructor called\n";
	delete[] sth;
}

void Flier::print()
{
	Animal::print();
	std::cout << "Hi, I'm a flier!\n";
}

void Flier::fly()
{
}
