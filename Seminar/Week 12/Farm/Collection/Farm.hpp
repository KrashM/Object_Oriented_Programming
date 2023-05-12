#pragma once
#include "../Animals/Animal.hpp"
#include <cstddef>

class Farm{

public:
	Farm();
	Farm(Farm const &);
	Farm &operator=(Farm const &);
	~Farm();

	void addAnimal(Animal const &);

	void allSayHello() const;

private:
	void resize();
	void copy(Farm const &);
	void free();

private:
	std::size_t size, capacity;
	Animal **animals;

};
