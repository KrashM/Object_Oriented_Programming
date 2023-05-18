#include "Factory.hpp"
#include "../Animals/Cat.hpp"
#include "../Animals/Dog.hpp"
#include "../Animals/Mouse.hpp"

Animal *animalFactory(Animal::AnimalType const type){

    switch(type){

        case Animal::AnimalType::Cat: return new Cat();
        case Animal::AnimalType::Dog: return new Dog();
        case Animal::AnimalType::Mouse: return new Mouse();
        default: return nullptr;

    }
    
}