#pragma once

#include "IPrintable.hpp"
#include "Product.hpp"
#include <cstddef>

class User final : public IPrintable{

public:
    User() = delete;
    User(char const * const, char const * const, char const * const);
    User(User const &);
    User(User &&);
    ~User();

    User &operator =(User const &);
    User &operator =(User &&);

    void add_product(Product const &);

    char const * const get_name() const;
    char const * const get_password() const;

public:
    void print() const override final;

private:
    void resize(std::size_t const);
    void copy(User const &);
    void free();

private:
    std::size_t _capacity, _size;
    Product **_products;
    char *_name, *_email, *_password;

};
