#pragma once

#include <cstddef>

using std::size_t;

class Vector{

    public:
        Vector(); // 10/10т.

        Vector &operator +=(double const); // 5т.
        Vector &operator +(double const); // 5т.

        double &operator [](size_t const); // 2.5т.
        double const operator [](size_t const) const; // 2.5т.

        size_t getSize() const;

        friend bool operator <(Vector const &, Vector const &); // 5т.
        friend bool operator ==(Vector const &, Vector const &); // 5т.

    private:
        double computeSize() const;

        double _v[20];
        size_t _size;

};