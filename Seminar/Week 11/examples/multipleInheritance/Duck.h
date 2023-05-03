#pragma once
#include <string>

#include "Flier.h"
#include "Swimmer.h"
class Duck :
    public Swimmer, public Flier
{
	std::string name;
	// speed;
	// age
	// weight
	// wingWidth;
	// age
	// weight
public:
	Duck(const std::string& name);
	~Duck();
	void print() override;
	void serialize() override;
	void deserialize() override;
};

