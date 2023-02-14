#include "EventWithIntermission.hpp"
#include "EventManager.hpp"

int main(){

    SimpleEvent *first = new EventWithFixedIntermission(100, 200, 140);
    SimpleEvent *second = new EventWithIntermission(100, 250, 140, 220);
    SimpleEvent *myEvent = new SimpleEvent(100, 200);

    EventManager<10> myEvents;
    myEvents.addEvent(myEvent);
    myEvents.addEvent(first);
    myEvents.addEvent(second);

    myEvents[0]->display();
    myEvents[1]->display();
    myEvents[2]->display();

    delete myEvent;
    delete first;
    delete second;

}