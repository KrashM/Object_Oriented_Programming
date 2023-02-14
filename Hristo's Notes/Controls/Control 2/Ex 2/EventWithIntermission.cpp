#include "EventWithIntermission.hpp"

// TODO: validations for time
EventWithIntermission::EventWithIntermission(): EventWithFixedIntermission(), endOfIntermission(0){}
EventWithIntermission::EventWithIntermission(const size_t start, const size_t end, const size_t startOfIntermission, const size_t endOfIntermission): EventWithFixedIntermission(start, end, startOfIntermission), endOfIntermission(endOfIntermission){}
EventWithIntermission::EventWithIntermission(const EventWithIntermission &other){ this -> copy(other); }
EventWithIntermission &EventWithIntermission::operator =(const EventWithIntermission &other){

    if(this != &other) this -> copy(other);
    return *this;

}

void EventWithIntermission::display() const{

    cout << this -> start / 100 << ':' << (this -> start % 100) / 10 << this -> start % 10 << '-'
        << this -> end / 100 << ':' << (this -> end % 100) / 10 << this -> end % 10 << '\n'
        << "Intermission: " << this -> intermissionStart / 100 << ':' << this -> intermissionStart % 100 << '-'
        << this -> endOfIntermission / 100 << ':' << (this -> endOfIntermission % 100) / 10 << this -> endOfIntermission % 10 << '\n';
    
}

void EventWithIntermission::copy(const EventWithIntermission &other){

    this -> start = other.start;
    this -> end = other.end;
    this -> intermissionStart = other.intermissionStart;
    this -> endOfIntermission = other. endOfIntermission;

}

SimpleEvent *EventWithIntermission::clone() const{

    EventWithIntermission *newEvent = new EventWithIntermission(*this);
    return newEvent;

}