#pragma once

#include "EventWithFixedIntermission.hpp"

class EventWithIntermission: public EventWithFixedIntermission{

    public:
        EventWithIntermission();
        EventWithIntermission(const size_t, const size_t, const size_t, const size_t);
        EventWithIntermission(const EventWithIntermission &);
        EventWithIntermission &operator =(const EventWithIntermission &);

        void display() const override;
        SimpleEvent *clone() const override;

    private:
        size_t endOfIntermission;

        void copy(const EventWithIntermission &);

};