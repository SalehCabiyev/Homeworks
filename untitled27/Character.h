//
// Created by USER on 17.11.2024.
//

#ifndef CHARACTER_H
#define CHARACTER_H



class Character {
protected:
    int _level;
    int _xp;
    int _hp;
    int _attack;
    int _defence;
    int _mana;
    int _agility;
public:


    Character(int level, int xp, int hp, int attack, int defence, int mana, int agility);

    virtual void defence(){}
    virtual void attack(){}
    virtual void level_up(){}
    virtual void stats(){}

};



#endif //CHARACTER_H
