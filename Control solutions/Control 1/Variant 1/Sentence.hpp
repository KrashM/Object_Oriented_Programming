#pragma once

#include <iostream>
#include "Word.hpp"

using std::ostream;

class Sentence{

    public:
        Sentence(); // 10т.
        Sentence(Sentence const &); // 10т.
        ~Sentence(); // 5т.

        Sentence &operator =(Sentence const &); // 10т.

        void addWord(Word const &); // 15т.

        friend ostream &operator <<(ostream &, Sentence const &); // 15т.

    private:
        void resize(size_t const);
        void copyFrom(Sentence const &);
        void free();

        size_t _capacity, _size;
        char *_w;

};