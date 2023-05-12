#pragma once
#include "Animal.hpp"

class Dog : public Animal{

public:
	void sayHello() const override;
	Animal *clone() const override;

};