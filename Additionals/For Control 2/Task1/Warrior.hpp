#pragma once

#include "Entity.hpp"

class Warrior : public Entity{

public:
    enum class Weapon{
        Sword = 3,
        Axe = 5,
        Mace = 10
    };

public:
    Warrior() = default;
    explicit Warrior(std::string const &, unsigned const, unsigned const = 0, Weapon const & = Weapon::Sword);
    Warrior(Warrior const &) = default;
    Warrior(Warrior &&) = default;

    Warrior &operator =(Warrior const &) = default;
    Warrior &operator =(Warrior &&) = default;

    virtual void attack(Entity * const) const;
    void takeDamage(unsigned const) override;
    void print() const override;

protected:
    unsigned _meleeAttack = 0, _armorPoints = 0;
    Weapon _weapon = Weapon::Sword;

};