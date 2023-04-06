#pragma once

#include <iostream>

using std::size_t;
using std::istream;
using std::ostream;

class Nvector{

    public:
        Nvector() = delete;
        Nvector(size_t);
        Nvector(Nvector const &);
        ~Nvector();

        Nvector &operator =(Nvector const &);
        Nvector &operator +=(Nvector const &);
        Nvector &operator -=(Nvector const &);
        Nvector &operator *=(int);

        double operator ~() const;     // length
        int operator [](size_t) const; // get
        int &operator [](size_t);      // get set

        friend Nvector operator +(Nvector const &, Nvector const &);
        friend Nvector operator -(Nvector const &, Nvector const &);
        friend int operator *(Nvector const &, Nvector const &); // Scalar product
        friend Nvector operator *(Nvector const &, int);
        friend Nvector operator *(int, Nvector const &);

        friend bool operator ||(Nvector const &, Nvector const &); // Are parallel
        friend bool operator |=(Nvector const &, Nvector const &); // Are perpendicular

        friend istream &operator >>(istream &, Nvector &);
        friend ostream &operator <<(ostream &, Nvector const &);

    private:
        void copyFrom(Nvector const &);
        void free();

        size_t size;
        int *v;

};