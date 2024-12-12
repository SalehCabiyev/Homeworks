//
// Created by USER on 18.11.2024.
//

#ifndef MAGE_H
#define MAGE_H
#include "Character.h"



class Mage :public Character {
    Mage();

    void defence() override ;

    void attack() override;


    void stats() override ;

    void level_up() override ;

};



#endif //MAGE_H
