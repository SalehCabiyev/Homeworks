//
// Created by USER on 17.11.2024.
//

#include "Tank.h"
#include <iostream>

Tank::Tank(): Character(1, 0, 100, 2, 5, 0, 1) {}

void Tank::defence() {
    std::cout << "Tank defence: " << _defence << std::endl;
    _xp += 125;
    _hp -= 10;
}

void Tank::attack() {
    std::cout << "Tank attack: " << _attack << std::endl;
}

void Tank::stats() {
    std::cout << "Level: " << _level << std::endl
            << "HP: " << _hp << std::endl
            << "XP: " << _xp << std::endl
            << "Attack: " << _attack << std::endl
            << "Defence:" << _defence << std::endl
            << "Mana: " << _mana << std::endl
            << "Agility:" << _agility << std::endl;
}

void Tank::level_up() {
    if (_xp >= 1000) {
        _level++;
        _hp += 10;
        _xp = 0;
        _attack++;
        _defence++;
    }
}



