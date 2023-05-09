#include "MagicalWarrior.hpp"
#include "Warrior.hpp"
#include "Entity.hpp"
#include "Mage.hpp"

int main(){

    Entity e("Hristo", false);
    e.print();

    Warrior w("Arthur", 5, 3, Warrior::Weapon::Axe);
    w.print();
    w.attack(&e);
    e.print();
    w.takeDamage(20);
    w.print();

    Mage m("Merlin", 2, 8, Mage::Weapon::Scepter);
    m.print();
    m.attack(&w);
    w.print();
    m.takeDamage(10);
    m.print();

    MagicalWarrior mw("Arthur&Merlin", 10, 8, 10, 9, Warrior::Weapon::Mace, Mage::Weapon::Wand);
    mw.print();
    mw.attack(&m);
    m.print();
    mw.doQuest();
    mw.print();
    mw.attack(&m);
    m.print();

}