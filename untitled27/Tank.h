//
// Created by USER on 17.11.2024.
//

#ifndef TANK_H
#define TANK_H
#include "Character.h"



class Tank : public Character {
    Tank();

    void defence() override ;

    void attack() override ;


    void stats() override ;

    void level_up() override ;
};



#endif //TANK_H
