#include <cstring>
#include "Todo.hpp"

using std::boolalpha;

Todo::Todo(): description(new char[1]){
    description[0] = '\0';
}

Todo::Todo(char const * const &description, unsigned const &id, bool const &done): description(new char[strlen(description) + 1]), id(id), done(done){
    strcpy(this -> description, description);
}

Todo::Todo(Todo const &other){
    copyFrom(other);
}

Todo::~Todo(){
    free();
}

Todo &Todo::operator =(Todo const &other){

    if(this != &other){

        free();
        copyFrom(other);

    }

    return *this;

}

void Todo::complete(){
    done = true;
}

void Todo::print() const{

    cout << "Id: " << id
        << "\nDescription: " << description
        << "\nDone: " << boolalpha << done << '\n';

}

void Todo::copyFrom(Todo const &other){

    this -> description = new char[strlen(other.description) + 1];
    strcpy(this -> description, other.description);
    this -> id = other.id;
    this -> done = other.done;

}

void Todo::free(){
    delete[] description;
}