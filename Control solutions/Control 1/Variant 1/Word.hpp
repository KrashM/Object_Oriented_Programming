#pragma once

#include <cstddef>

using std::size_t;

class Word{

    public:
        Word();

        char &operator [](size_t const);
        char const operator [](size_t const) const;

        Word &operator +=(char const);
        Word &operator +(char const);

        size_t getSize() const;

        friend bool operator <(Word const &, Word const &);
        friend bool operator ==(Word const &, Word const &);

    private:
        char _w[20];
        size_t _size;
    
};