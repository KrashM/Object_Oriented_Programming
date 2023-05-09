#include "MagicalWarrior.hpp"
#include <iostream>

MagicalWarrior::MagicalWarrior(std::string const &name, unsigned const meleeAttack, unsigned const rangeAttack, unsigned const armorPoints, unsigned const magicItemPoints, Warrior::Weapon const &meleeWeapon, Mage::Weapon const &rangeWeapon):
    Warrior(name, meleeAttack, armorPoints, meleeWeapon), Mage(name, rangeAttack, magicItemPoints, rangeWeapon){}

void MagicalWarrior::attack(Entity * const victim) const{
    
    Warrior::attack(victim);
    if(_questFinished) Mage::attack(victim);

}

void MagicalWarrior::takeDamage(unsigned const damage){

    if(!Warrior::_health) return;

    Warrior::_health = std::max(Warrior::_health -= damage - damage * 0.02 * _armorPoints * (_questFinished ? 0.02 * _magicItemPoints : 1), 0);
    Warrior::_visible = Warrior::_health;

}

void MagicalWarrior::print() const{

    std::cout << "MagicalWarrior name is: " << Warrior::_name
        << "\n Health is: " << Warrior::_health
        << "\n It is invincible: " << std::boolalpha << Warrior::_invincible
        << "\n It is visible: " << Warrior::_visible
        << "\n Melee attack power: " << _meleeAttack
        << "\n Armor points: " << _armorPoints
        << "\n Weapon is: ";
    
    switch(Warrior::_weapon){

        case Warrior::Weapon::Sword:
            std::cout << "Sword\n";
            break;

        case Warrior::Weapon::Axe:
            std::cout << "Axe\n";
            break;

        case Warrior::Weapon::Mace:
            std::cout << "Mace\n";
            break;

    }

    if(!_questFinished) return;

    std::cout << "Range attack power: " << _rangeAttack
        << "\n Magic item points: " << _magicItemPoints
        << "\n Weapon is: ";
    
    switch(Mage::_weapon){

        case Mage::Weapon::Staff:
            std::cout << "Staff\n";
            break;

        case Mage::Weapon::Scepter:
            std::cout << "Scepter\n";
            break;

        case Mage::Weapon::Wand:
            std::cout << "Wand\n";
            break;

    }

}

void MagicalWarrior::doQuest(){
    _questFinished = true;
}