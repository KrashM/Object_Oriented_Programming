#include "Collection/Farm.hpp"
#include "Animals/Dog.hpp"
#include "Animals/Cat.hpp"
#include "Animals/Mouse.hpp"

int main(){

	Farm f;
	f.addAnimal(Dog());
	f.addAnimal(Cat());

	f.allSayHello();

}