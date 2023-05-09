#include "Mage.hpp"
#include <iostream>

Mage::Mage(std::string const &name, unsigned const rangeAttack, unsigned const magicItemPoints, Weapon const &weapon):
    Entity(name), _rangeAttack(rangeAttack), _magicItemPoints(magicItemPoints), _weapon(weapon){}

void Mage::attack(Entity * const victim) const{
    victim -> takeDamage(_rangeAttack * (unsigned)_weapon);
}

void Mage::takeDamage(unsigned const damage){

    if(!_health) return;

    _health = std::max(_health -= damage - damage * 0.02 * _magicItemPoints, 0);
    _visible = _health;

}

void Mage::print() const{

    std::cout << "Mage name is: " << _name
        << "\n Health is: " << _health
        << "\n It is invincible: " << std::boolalpha << _invincible
        << "\n It is visible: " << _visible
        << "\n Range attack power: " << _rangeAttack
        << "\n Magic item points: " << _magicItemPoints
        << "\n Weapon is: ";
    
    switch(_weapon){

        case Weapon::Staff:
            std::cout << "Staff\n";
            break;

        case Weapon::Scepter:
            std::cout << "Scepter\n";
            break;

        case Weapon::Wand:
            std::cout << "Wand\n";
            break;

    }

}