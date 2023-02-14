#pragma once

#include <fstream>

using std::istream;
using std::ostream;

class NaturalNumbers{

    private:
        double *numbers;
        size_t numberOfElements;
        char *name;

    public:
        NaturalNumbers();
        NaturalNumbers(const double *numbers, const char *name, const size_t numberOfElements);
        NaturalNumbers(const NaturalNumbers &other);
        ~NaturalNumbers();

        const double *getNumbers() const;
        const char *getName() const;
        const size_t getNumberOfElements() const;

        void setName(const char *name);
        void setNumberOfElements(const size_t numberOfElements);
        void setNumbers(const double *numbers);

        NaturalNumbers &operator *(const NaturalNumbers &other) const;
        NaturalNumbers &operator *=(const NaturalNumbers &other);

        friend void operator >>(const istream &is, NaturalNumbers &rhs);
        friend ostream &operator <<(ostream &os, const NaturalNumbers &rhs);

        const bool &operator [](const size_t number) const;

};