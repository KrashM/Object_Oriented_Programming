#pragma once

#include <iostream>

using std::istream;
using std::ostream;

class ComplexNumber{

    public:
        ComplexNumber();
        ComplexNumber(double, double);
        ComplexNumber(ComplexNumber const &) = default;
        ~ComplexNumber() = default;

        ComplexNumber getConjugated() const;  //връща комплексно спрегнатото число на текущия обект.

        //assignment operators 
        // a+=b Към а се добавя стойността на b. а се променя , b не се. Операцията  ще върне a за да може да се правят верижни изрази (a+=b+=c)
        ComplexNumber &operator =(ComplexNumber const &) = default;
        ComplexNumber &operator +=(ComplexNumber const &);
        ComplexNumber &operator -=(ComplexNumber const &);
        ComplexNumber &operator *=(ComplexNumber const &);
        ComplexNumber &operator /=(ComplexNumber const &);


        // a+b. Операторът връща НОВА променлива(ComplexNumber), която е резултатът от операцията.
        friend ComplexNumber operator +(ComplexNumber const &, ComplexNumber const &);
        friend ComplexNumber operator -(ComplexNumber const &, ComplexNumber const &);
        friend ComplexNumber operator *(ComplexNumber const &, ComplexNumber const &);
        friend ComplexNumber operator /(ComplexNumber const &, ComplexNumber const &);

        //stream opeartors   ( std::cout << c1)  (std::cin >> c1 )
        friend ostream &operator <<(ostream&, ComplexNumber const &);
        friend istream &operator >>(istream&, ComplexNumber &);

    private:
        double real, im;

};