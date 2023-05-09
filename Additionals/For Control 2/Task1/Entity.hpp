#pragma once

#include "IPrintable.hpp"
#include <cstddef>
#include <string>

class Entity : public IPrintable{

public:
    Entity() = default;
    explicit Entity(std::string const &, bool const = true, bool const = true);
    Entity(Entity const &) = default;
    Entity(Entity &&) = default;
    ~Entity() = default;

    Entity &operator =(Entity const &) = default;
    Entity &operator =(Entity &&) = default;

    virtual void takeDamage(unsigned const damage);
    void print() const override;

protected:
    std::string _name = "";
    int _health = 100;
    bool _invincible = false, _visible = true;

};