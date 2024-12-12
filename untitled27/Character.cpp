//
// Created by USER on 17.11.2024.
//

#include "Character.h"

Character::Character(int level, int xp, int hp, int attack, int defence, int mana, int agility) {
    _level = level; // 1-10
    _xp = xp; // 1-1000
    _hp = hp; // 0-200
    _attack = attack; // 1-10
    _defence = defence; // 1-10
    _mana = mana; // 0 - 100
    _agility = agility; // 1-10
}
