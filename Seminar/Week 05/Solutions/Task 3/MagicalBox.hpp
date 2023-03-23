#pragma once

#include <iostream>

using std::cout;

class MagicalBox{

    public:
        MagicalBox();
        MagicalBox(MagicalBox const &);
        ~MagicalBox();

        MagicalBox &operator =(MagicalBox const &);

        void insert(int const &);
        int pop();

    private:
        void resize(size_t const &);
        void copyFrom(MagicalBox const &);
        void free();

        int *array;
        size_t size;

};