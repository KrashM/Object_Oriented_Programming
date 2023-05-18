#pragma once
#include "Animal.hpp"

class Cat : public Animal{

public:
	void sayHello() const override;
	Animal *clone() const override;

};