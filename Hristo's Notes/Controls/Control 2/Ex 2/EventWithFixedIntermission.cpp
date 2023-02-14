#include "EventWithFixedIntermission.hpp"

// TODO: Validations for time
EventWithFixedIntermission::EventWithFixedIntermission(): SimpleEvent(), intermissionStart(0){}
EventWithFixedIntermission::EventWithFixedIntermission(const size_t start, const size_t end, const size_t intermissionStart): SimpleEvent(start, end), intermissionStart(intermissionStart){}
EventWithFixedIntermission::EventWithFixedIntermission(const EventWithFixedIntermission &other){ this -> copy(other); }

EventWithFixedIntermission &EventWithFixedIntermission::operator =(const EventWithFixedIntermission &other){

    if(this != &other) this -> copy(other);
    return *this;

}

void EventWithFixedIntermission::display() const{

    size_t intermissionEnd = this -> intermissionStart + 20;
    // Jump one hour
    if(intermissionEnd % 100 >= 60) intermissionEnd += 40;

    cout << this -> start / 100 << ':' << (this -> start % 100) / 10 << this -> start % 10 << '-'
        << this -> end / 100 << ':' << (this -> end % 100) / 10 << this -> end % 10 << '\n'
        << "Intermission: " << this -> intermissionStart / 100 << ':' << this -> intermissionStart % 100 << '-'
        << intermissionEnd / 100 << ':' << (intermissionEnd % 100) / 10 << intermissionEnd % 10 << '\n';
    
}

void EventWithFixedIntermission::copy(const EventWithFixedIntermission &other){

    this -> start = other.start;
    this -> end = other.end;
    this -> intermissionStart = other.intermissionStart;

}

SimpleEvent *EventWithFixedIntermission::clone() const{

    EventWithFixedIntermission *newEvent = new EventWithFixedIntermission(*this);
    return newEvent;

}