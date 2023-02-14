#pragma once

#include <fstream>

using std::istream;
using std::ostream;

class Pencil{

    private:
        char brand[100];
        unsigned year;
        short hardness;

    public:
        Pencil();
        Pencil(const char *brand, const unsigned year, const short hardness);
        Pencil(const Pencil &other);

        const char *getBrand() const;
        const unsigned getYear() const;
        const short getHardness() const;

        const Pencil &operator =(const Pencil &other);

        void setBrand(const char *brand);
        void setYear(const unsigned year);
        void setHardness(const short hardness);

        // friend istream &operator >>(const istream &is, Pencil &pencil);
        friend ostream &operator <<(ostream &os, const Pencil &pencil);

};