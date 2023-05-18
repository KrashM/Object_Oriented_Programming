#pragma once
#include "../Animals/Animal.hpp"
#include <cstddef>

class Farm{

public:
	Farm();
	Farm(Farm const &);
	~Farm();

	Farm &operator =(Farm const &);

	Animal const * const operator [](std::size_t const) const;

	void addAnimal(Animal const &);
	bool addAnimal(Animal::AnimalType const);

	void allSayHello() const;

private:
	void resize();
	void copy(Farm const &);
	void free();

private:
	std::size_t size, capacity;
	Animal **animals;

};
