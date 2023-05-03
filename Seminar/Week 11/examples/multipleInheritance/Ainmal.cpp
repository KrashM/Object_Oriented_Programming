#include "Ainmal.h"

#include <iostream>

Animal::Animal(int age, double weight): age{age}, weight{weight}
{
	//std::cout << "Animal constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

void Animal::print()
{
	std::cout << "Hi, I'm an animal!\n";
}
