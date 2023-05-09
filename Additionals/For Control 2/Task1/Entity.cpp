#include "Entity.hpp"
#include <iostream>

Entity::Entity(std::string const &name, bool const invincible, bool const visible):
    _name(name), _health(100), _invincible(invincible), _visible(visible){}

void Entity::takeDamage(unsigned const damage){

    if(!_invincible && _health)
        _health = std::max(_health -= damage, 0);
    _visible = _health;

}

void Entity::print() const{

    std::cout << "Entity name is: " << _name
        << "\n Health is: " << _health
        << "\n It is invincible: " << std::boolalpha << _invincible
        << "\n It is visible: " << _visible << '\n';

}