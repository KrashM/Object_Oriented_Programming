#include "SimpleEvent.hpp"

// TODO: validations for time
SimpleEvent::SimpleEvent(): start(0), end(0){}
SimpleEvent::SimpleEvent(const size_t start, const size_t end): start(start), end(end){}
SimpleEvent::SimpleEvent(const SimpleEvent &other){ this -> copy(other); }
SimpleEvent &SimpleEvent::operator =(const SimpleEvent &other){

    if(this != &other) this -> copy(other);
    return *this;

}

void SimpleEvent::copy(const SimpleEvent &other){
    
    this -> start = other.start;
    this -> end = other.end;

}

void SimpleEvent::display() const{

    cout << this -> start / 100 << ':' << (this -> start % 100) / 10 << this -> start % 10 << '-' << this -> end / 100 << ':' << (this -> end % 100) / 10 << this -> end % 10 << '\n';

}

SimpleEvent *SimpleEvent::clone() const{

    SimpleEvent *newEvent = new SimpleEvent(*this);
    return newEvent;

}