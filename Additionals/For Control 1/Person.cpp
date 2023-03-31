#include "Person.hpp"

Person::Person(char const *name, unsigned const age, unsigned const fn){

    setName(name);
    setAge(age);
    setFN(fn);

}

Person::Person(Person const &other){
    copyFrom(other);
}

Person::~Person(){
    free();
}

Person &Person::operator =(Person const &other){

    if(this == &other) return *this;

    free();
    copyFrom(other);

    return *this;

}

void Person::setName(char const * const name){

    assert(name);

    this -> name = new(nothrow) char[strlen(name) + 1];
    assert(this -> name);

    strcpy(this -> name, name);

}

void Person::setAge(unsigned const age){

    assert(age < 100);
    this -> age = age;

}


void Person::setFN(unsigned const fn){

    assert(fn >= 100'000 && fn < 1'000'000);
    this -> fn = fn;

}

char const *Person::getName() const{
    return name;
}

unsigned const Person::getAge() const{
    return age;
}

unsigned const Person::getFN() const{
    return fn;
}

ostream &operator <<(ostream &os, Person const &obj){

    return os << "Name: " << obj.name << '\n'
        << "Age: " << obj.age << '\n'
        << "FN: " << obj.fn;

}

void Person::copyFrom(Person const &other){

    name = new(nothrow) char[strlen(other.name) + 1];
    assert(!name);
    strcpy(this -> name, other.name);
    this -> age = other.age;
    this -> fn = other.fn;

}

void Person::free(){
    delete[] name;
}