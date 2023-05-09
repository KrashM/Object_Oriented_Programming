#include "Warrior.hpp"
#include <iostream>

Warrior::Warrior(std::string const &name, unsigned const meleeAttack, unsigned const armorPoints, Weapon const &weapon):
    Entity(name), _meleeAttack(meleeAttack), _armorPoints(armorPoints), _weapon(weapon){}

void Warrior::attack(Entity * const victim) const{
    victim -> takeDamage(_meleeAttack * (unsigned)_weapon);
}

void Warrior::takeDamage(unsigned const damage){

    if(!_health) return;

    _health = std::max(_health -= damage - damage * 0.02 * _armorPoints, 0);
    _visible = _health;

}

void Warrior::print() const{

    std::cout << "Warrior name is: " << _name
        << "\n Health is: " << _health
        << "\n It is invincible: " << std::boolalpha << _invincible
        << "\n It is visible: " << _visible
        << "\n Melee attack power: " << _meleeAttack
        << "\n Armor points: " << _armorPoints
        << "\n Weapon is: ";
    
    switch(_weapon){

        case Weapon::Sword:
            std::cout << "Sword\n";
            break;

        case Weapon::Axe:
            std::cout << "Axe\n";
            break;

        case Weapon::Mace:
            std::cout << "Mace\n";
            break;

    }

}