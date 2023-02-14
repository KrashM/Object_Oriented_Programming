#pragma once

class Magic{

    private:
        int *props;
        unsigned SIZE, CAPACITY;

        void resize();

    public:
        Magic();
        ~Magic();

        const unsigned getSize(){ return this -> SIZE; }
        const unsigned getCapacity(){ return this -> CAPACITY; }
        const int getElement(unsigned index){ return this -> props[index]; }
        void insert(int prop);
        const int pop();

};