#pragma once

#include <iostream>

using std::cout;

class SimpleEvent{

    public:
        SimpleEvent();
        SimpleEvent(const size_t, const size_t);
        SimpleEvent(const SimpleEvent &);
        SimpleEvent &operator =(const SimpleEvent &);

        virtual void display() const;
        virtual SimpleEvent *clone() const;

    protected:
        size_t start, end;

    private:
        void copy(const SimpleEvent &);

};