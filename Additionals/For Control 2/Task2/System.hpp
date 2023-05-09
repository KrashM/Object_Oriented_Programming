#pragma once

#include "User.hpp"
#include "Product.hpp"

class System{

public:
    System();
    System(System const &);
    System(System &&);
    ~System();

    System &operator =(System const &);
    System &operator =(System &&);

    void register_user(char const * const, char const * const, char const * const);
    User *log_in_user(char const * const, char const * const);

private:
    void resize(std::size_t const);
    void copy(System const &);
    void free();

private:
    std::size_t _capacity, _size;
    User **_users;

};