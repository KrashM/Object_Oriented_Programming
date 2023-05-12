#pragma once
#include "Animal.hpp"

class Mouse : public Animal{

public:
	void sayHello() const override;
	Animal *clone() const override;

};