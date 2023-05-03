#pragma once
#include "Ainmal.h"

// swimmer IS-A animal
class Swimmer: virtual public Animal
{
	int speed;
	// age
	// weight
public:
	Swimmer();
	~Swimmer();
	void print();
};

