#pragma once
#include "Serializable.h"

class Animal: public Serializable
{
protected:
	int age;
	double weight;
public:
	Animal(int age = 0, double weight = 0.0);
	virtual ~Animal();
	virtual void print();
};

