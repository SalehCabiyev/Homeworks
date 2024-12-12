//
// Created by USER on 18.11.2024.
//

#include "Mage.h"
#include "iostream"

Mage::Mage(): Character(1, 0, 25, 5, 1, 100, 0) {}

void Mage::defence() {
    std::cout << "Tank defence: " << _defence << std::endl;

}

void Mage::attack() {
    _xp += 125;
    _mana -= 20;
    if (_mana <= 0)
    {
        _hp -= 5;
    }
    std::cout << "Mage cast: " << _attack << std::endl;
}

void Mage::stats() {
    std::cout << "Level: " << _level << std::endl
            << "HP: " << _hp << std::endl
            << "XP: " << _xp << std::endl
            << "Attack: " << _attack << std::endl
            << "Defence:" << _defence << std::endl
            << "Mana: " << _mana << std::endl
            << "Agility:" << _agility << std::endl;
}

void Mage::level_up() {
    if (_xp >= 1000) {
        _level++;
        _hp += 10;
        _xp = 0;
        _attack++;
        _mana += 10;
    }
}
