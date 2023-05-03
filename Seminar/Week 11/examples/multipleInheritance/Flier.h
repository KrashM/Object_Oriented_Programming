#pragma once
#include "Ainmal.h"

// Flier IS-A animal
class Flier: virtual public Animal
{
	int wingWidth;
	char* sth = nullptr;
	// age
	// weight
public:
	Flier();
	~Flier();
	void print() override;
	void fly();
};

