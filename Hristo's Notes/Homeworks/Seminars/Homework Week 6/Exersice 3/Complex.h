#pragma once

class Complex{

    private:
        int real, imag;

    public:
        Complex(int real, int imag);

        const Complex &operator =(const Complex &other);
        const Complex &operator +(const Complex &other);
        const Complex &operator -(const Complex &other);
        const Complex &operator *(const Complex &other);
        const Complex &operator /(const Complex &other);

        const bool operator ==(const Complex &other) const;
        const bool operator !=(const Complex &other) const;
        
        const char* toString() const;

};