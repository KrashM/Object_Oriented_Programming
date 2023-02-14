#pragma once

#include "SimpleEvent.hpp"

class EventWithFixedIntermission: public SimpleEvent{

    public:
        EventWithFixedIntermission();
        EventWithFixedIntermission(const size_t, const size_t, const size_t);
        EventWithFixedIntermission(const EventWithFixedIntermission &);
        EventWithFixedIntermission &operator =(const EventWithFixedIntermission &);

        virtual void display() const override;
        virtual SimpleEvent *clone() const override;

    protected:
        size_t intermissionStart;

    private:
        void copy(const EventWithFixedIntermission &);

};