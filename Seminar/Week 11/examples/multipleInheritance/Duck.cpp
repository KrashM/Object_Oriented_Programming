#include "Duck.h"

#include <iostream>


Duck::Duck(const std::string& name) : Animal(5, 10.4), Flier(), Swimmer(), name{name}
{
}

Duck::~Duck()
{
	std::cout << "Duck destructor called\n";
}

void Duck::print()
{
	Flier::print();
	Swimmer::print();
	std::cout << "Hi, I'm a duck!\n";
	std::cout << age << " " << weight << std::endl;
}

void Duck::serialize()
{
	std::cout << "Serialize duck\n";
}

void Duck::deserialize()
{
	std::cout << "Deserialize duck\n";
}
