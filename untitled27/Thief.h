//
// Created by USER on 18.11.2024.
//

#ifndef THIEF_H
#define THIEF_H
#include "Character.h"



class Thief:public Character {
    Thief();

    void defence() override ;

    void attack() override;

    void stats() override ;

    void level_up() override ;
};



#endif //THIEF_H
