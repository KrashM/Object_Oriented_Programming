#pragma once
#include <iostream>

class Animal{

public:
	enum class AnimalType{

		Cat = 0,
		Dog = 1,
		Mouse = 2

	};

public:
	virtual ~Animal() {} //!!!

	virtual void sayHello() const = 0;
	virtual Animal *clone()  const = 0; //!!!

};