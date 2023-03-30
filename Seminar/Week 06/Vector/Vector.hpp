#pragma once

#include <iostream>
#include <cstddef>

using std::size_t;
using std::ostream;

class Vector{

    public:
        Vector();
        Vector(Vector const &);
        ~Vector();

        Vector &operator =(Vector const &);

        int &operator [](size_t const);
        int const operator [](size_t const) const;

        void reserve(size_t const);
        void assign(size_t const, int const);
        void push_back(int const);
        void pop_back();
        void insert(size_t const, int const);
        void erase(size_t const);
        void clear();
        
        size_t capacity() const;
        size_t size() const;

        bool empty() const;
        bool contains(int const) const;

        int const front() const;
        int &front();
        int const back() const;
        int &back();

        friend ostream &operator <<(ostream &, Vector const &);

    private:
        void resize(size_t const);
        void copyFrom(Vector const &);
        void free();

        size_t _capacity, _size;
        int *_v;

};