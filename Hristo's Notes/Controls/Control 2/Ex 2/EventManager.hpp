#pragma once

#include "EventWithIntermission.hpp"

template <size_t N>
class EventManager{

    public:
        EventManager(): size(0){}
        bool addEvent(const SimpleEvent *event){

            if(size == N) return false;
            this -> events[size++] = event->clone();
            return true;

        }

        SimpleEvent *operator [](const size_t index){

            return this -> events[index];

        }

    private:
        SimpleEvent **events = new SimpleEvent*[N];
        size_t size;

};