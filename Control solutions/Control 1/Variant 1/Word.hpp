#pragma once

#include <cstddef>

using std::size_t;

class Word{

    public:
        Word(); // 10т.

        char &operator [](size_t const); // 2.5т.
        char const operator [](size_t const) const; // 2.5т.

        Word &operator +=(char const); // 5т.
        friend Word operator +(Word const &, char const); // 2.5т.
        friend Word operator +(char const, Word const &); // 2.5т.

        size_t getSize() const;

        friend bool operator <(Word const &, Word const &); // 5т.
        friend bool operator ==(Word const &, Word const &); // 5т.

    private:
        char _w[20];
        size_t _size;
    
};