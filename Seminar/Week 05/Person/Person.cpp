#include "Person.hpp"

#include <cstring>
#include <new>

using std::nothrow;

Person::Person(): name(new(nothrow) char[1]), surname(new(nothrow) char[1]), age(0){

    if(name) *name = '\0';
    if(surname) *surname = '\0';

}

Person::Person(const char * const &name, const char * const &surname, int const &age): name(new(nothrow) char[strlen(name) + 1]),
    surname(new(nothrow) char[strlen(surname) + 1]), age(age){

    if(this -> name) strcpy(this -> name, name);
    if(this -> surname) strcpy(this -> surname, surname);

}

Person::Person(Person const &other){
    copyFrom(other);
}

Person &Person::operator =(Person const &other){

    if(this != &other){

        free();
        copyFrom(other);

    }

    return *this;

}

Person::~Person(){
    free();
}

int const &Person::getAge() const{
    return age;
}

char const *Person::getName() const{
    return name;
}

char const *Person::getSurname() const{
    return surname;
}

void Person::free(){

    delete[] name;
    delete[] surname;

}

void Person::copyFrom(Person const &other){

    name = new(nothrow) char[strlen(other.name) + 1];
    surname = new(nothrow) char[strlen(other.surname) + 1];

    if(name) strcpy(name, other.name);
    if(surname) strcpy(surname, other.surname);

    age = other.age;

}