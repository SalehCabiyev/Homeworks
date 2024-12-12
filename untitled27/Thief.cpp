//
// Created by USER on 18.11.2024.
//

#include "Thief.h"
#include "iostream"

Thief::Thief(): Character(1, 0, 50, 3, 0, 0, 5) {}

void Thief::defence() {
    std::cout << "Thief defence: " << _defence << std::endl;
}

void Thief::attack() {
    _xp += 125;
    std::cout << "Mage cast: " << _attack << std::endl;
}

void Thief::stats() {
    std::cout << "Level: " << _level << std::endl
             << "HP: " << _hp << std::endl
             << "XP: " << _xp << std::endl
             << "Attack: " << _attack << std::endl
             << "Defence:" << _defence << std::endl
             << "Mana: " << _mana << std::endl
             << "Agility:" << _agility << std::endl;
}

void Thief::level_up() {
    if (_xp >= 1000) {
        _level++;
        _hp += 10;
        _xp = 0;
        _agility++;
    }
}
