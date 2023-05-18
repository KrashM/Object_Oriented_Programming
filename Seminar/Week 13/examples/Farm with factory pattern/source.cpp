#include "Collection/Farm.hpp"
#include "Factory/Factory.hpp"

int main(){

	Farm f;
	f.addAnimal(Animal::AnimalType::Cat);
	f.addAnimal(Animal::AnimalType::Dog);

	f.allSayHello();

}