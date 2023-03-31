#pragma once

#include "Person.hpp"

class Group{

    public:
        Group();
        Group(Group const &);
        ~Group();
        Group &operator=(Group const &);

        Person *&operator [](size_t const);
        Person const * const operator [](size_t const) const;
        
        void push_back(Person * const);
        void pop_back();
        void clear();

        size_t size() const;
    
        friend ostream &operator <<(ostream &, Group const &);

    private:
        void resize(size_t const);
        void copyFrom(Group const &);
        void free();

        size_t _size, _capacity;
        Person** _collection;

};