#pragma once

#include "IPrintable.hpp"
#include <iostream>

class Product final : public IPrintable{

public:
	enum class Size : unsigned{
        S,
        M,
        L,
        XL,
        XXL,
        XXXL
    };

    friend std::ostream &operator <<(std::ostream &, Product::Size const &);

public:
    Product() = delete;
    Product(char const * const, double const, Size const &);
    Product(Product const &);
    Product(Product &&);
    ~Product();

    Product &operator =(Product const &);
    Product &operator =(Product &&);

public:
    void print() const override final;

private:
    void copy(Product const &);
    void free();

private:
    char *_name;
    double _price;
    Size _size;

};