#include "Farm.hpp"

Farm::Farm(): capacity(4), size(0), animals(new Animal *[capacity]){}

Farm::Farm(Farm const &other){
	copy(other);
}

Farm &Farm::operator=(Farm const &other){

	if(this == &other) return *this;

	free();
	copy(other);

	return *this;

}

Farm::~Farm(){
	free();
}

void Farm::addAnimal(Animal const &new_animal){

	if(size == capacity) resize();
	animals[size++] = new_animal.clone();

}

void Farm::allSayHello() const{

	for(std::size_t i = 0; i < size; i++)
		animals[i] -> sayHello();

}

void Farm::resize(){

	Animal **newCollection = new Animal *[capacity *= 2];
	for(std::size_t i = 0; i < size; i++)
		newCollection[i] = animals[i];

	delete[] animals;
	animals = newCollection;

}

void Farm::free(){

	for(std::size_t i = 0; i < size; i++)
		delete animals[i];
	delete[] animals;
	animals = nullptr;

}

void Farm::copy(Farm const &other){

	animals = new Animal *[other.capacity];
	capacity = other.capacity;
	size = other.size;

	for(std::size_t i = 0; i < size; i++)
		animals[i] = other.animals[i]->clone();

}