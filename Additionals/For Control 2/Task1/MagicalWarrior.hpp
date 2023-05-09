#pragma once

#include "Warrior.hpp"
#include "Mage.hpp"

class MagicalWarrior : public Warrior, Mage{

public:
    MagicalWarrior() = default;
    explicit MagicalWarrior(std::string const &, unsigned const, unsigned const, unsigned const = 0, unsigned const = 0, Warrior::Weapon const & = Warrior::Weapon::Sword, Mage::Weapon const & = Mage::Weapon::Staff);
    MagicalWarrior(MagicalWarrior const &) = default;
    MagicalWarrior(MagicalWarrior &&) = default;

    MagicalWarrior &operator =(MagicalWarrior const &) = default;
    MagicalWarrior &operator =(MagicalWarrior &&) = default;

    void attack(Entity * const) const override;
    void takeDamage(unsigned const) override;
    void print() const override;
    void doQuest();

private:
    bool _questFinished = false;

};