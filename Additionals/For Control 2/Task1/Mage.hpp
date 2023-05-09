#pragma once

#include "Entity.hpp"

class Mage : public Entity{

public:
    enum class Weapon{
        Staff = 2,
        Scepter = 6,
        Wand = 10
    };

public:
    Mage() = default;
    explicit Mage(std::string const &, unsigned const, unsigned const = 0, Weapon const & = Weapon::Staff);
    Mage(Mage const &) = default;
    Mage(Mage &&) = default;

    Mage &operator =(Mage const &) = default;
    Mage &operator =(Mage &&) = default;

    virtual void attack(Entity * const) const;
    void takeDamage(unsigned const) override;
    void print() const override;

protected:
    unsigned _rangeAttack = 0, _magicItemPoints = 0;
    Weapon _weapon = Weapon::Staff;

};