#include <iostream>
#include <cstring>

class Skill {
private:
    char _name[30];
    char _type[10];
    int _manaCost;

public:
    Skill() : _name(""), _type(""), _manaCost(0) {}

    Skill(const char* name, const char* type, int manaCost) {
        strncpy(_name, name, sizeof(_name) - 1);
        _name[sizeof(_name) - 1] = '\0';

        strncpy(_type, type, sizeof(_type) - 1);
        _type[sizeof(_type) - 1] = '\0';

        _manaCost = manaCost;
    }

    void use() const {
        std::cout << "Using skill: " << _name << " (Type: " << _type << ", Mana Cost: " << _manaCost << ")\n";
    }

    int getManaCost() const {
        return _manaCost;
    }
};

class Character {
protected:
    int _level;
    int _xp;
    int _hp;
    int _attack;
    int _defence;
    int _mana;
    int _agility;
    Skill _skills[2];
    int _skillCount;

public:
    Character(int level, int xp, int hp, int attack, int defence, int mana, int agility)
        : _level(level), _xp(xp), _hp(hp), _attack(attack), _defence(defence), _mana(mana), _agility(agility), _skillCount(0) {}

    virtual void defence() = 0;
    virtual void attack() = 0;
    virtual void level_up() = 0;
    virtual void stats() = 0;

    void addSkill(const Skill& skill) {
        if (_skillCount < 2) {
            _skills[_skillCount++] = skill;
        }
    }

    void useSkill(int index) {
        if (index < _skillCount) {
            if (_mana >= _skills[index].getManaCost()) {
                _skills[index].use();
                _mana -= _skills[index].getManaCost();
            } else {
                std::cout << "Not enough mana to use " << _skills[index].getManaCost() << "!\n";
            }
        } else {
            std::cout << "Skill not found!\n";
        }
    }

    void gainXp(int amount) {
        _xp += amount;
        if (_xp >= 1000) {
            level_up();
        }
    }

    void takeDamage(int damage) {
        _hp -= damage;
        if (_hp < 0) _hp = 0;
    }

    int getAttack() const {
        return _attack;
    }

    int getHP() const {
        return _hp;
    }

    bool isAlive() const {
        return _hp > 0;
    }
};

class Tank : public Character {
public:
    Tank() : Character(1, 0, 100, 2, 5, 10, 1) {
        addSkill(Skill("Shield Bash", "defense", 10));
        addSkill(Skill("Call for Help", "support", 5));
    }

    void defence() override {
        std::cout << "Tank Defence: " << _defence << std::endl;
    }

    void attack() override {
        std::cout << "Tank Attack: " << _attack << std::endl;
    }

    void stats() override {
        std::cout << "Level: " << _level << std::endl
                  << "HP: " << _hp << std::endl
                  << "XP: " << _xp << std::endl
                  << "Attack: " << _attack << std::endl
                  << "Defence: " << _defence << std::endl
                  << "Mana: " << _mana << std::endl
                  << "Agility: " << _agility << std::endl;
    }

    void level_up() override {
        if (_xp >= 1500) {
            _level++;
            _hp += 15;
            _xp = 0;
            _attack++;
            _defence += 2;
        }
    }
};

class Mage : public Character {
public:
    Mage() : Character(1, 0, 25, 5, 1, 100, 0) {
        addSkill(Skill("Fireball", "attack", 20));
        addSkill(Skill("Healing", "support", 15));
    }

    void defence() override {
        std::cout << "Mage Defence: " << _defence << std::endl;
    }

    void attack() override {
        _xp += 125;
        _mana -= 20;
        if (_mana < 0) {
            takeDamage(5);
            _mana = 0;
        }
        std::cout << "Mage casts: " << _attack << std::endl;
    }

    void stats() override {
        std::cout << "Level: " << _level << std::endl
                  << "HP: " << _hp << std::endl
                  << "XP: " << _xp << std::endl
                  << "Attack: " << _attack << std::endl
                  << "Defence: " << _defence << std::endl
                  << "Mana: " << _mana << std::endl
                  << "Agility: " << _agility << std::endl;
    }

    void level_up() override {
        if (_xp >= 1000) {
            _level++;
            _hp += 10;
            _xp = 0;
            _attack++;
            _mana += 15;
        }
    }
};

class Thief : public Character {
public:
    Thief() : Character(1, 0, 50, 3, 0, 0, 5) {
        addSkill(Skill("Backstab", "attack", 10));
        addSkill(Skill("Dodge", "defense", 5));
    }

    void defence() override {
        std::cout << "Thief Defence: " << _defence << std::endl;
    }

    void attack() override {
        _xp += 125;
        std::cout << "Thief Attack: " << _attack << std::endl;
    }

    void stats() override {
        std::cout << "Level: " << _level << std::endl
                  << "HP: " << _hp << std::endl
                  << "XP: " << _xp << std::endl
                  << "Attack: " << _attack << std::endl
                  << "Defence: " << _defence << std::endl
                  << "Mana: " << _mana << std::endl
                  << "Agility: " << _agility << std::endl;
    }

    void level_up() override {
        if (_xp >= 800) {
            _level++;
            _hp += 5;
            _xp = 0;
            _agility += 2;
        }
    }
};

class Battle {
public:
    void start(Character& player, Character& enemy) {
        std::cout << "Battle begins!\n";

        while (player.isAlive() && enemy.isAlive()) {
            player.attack();
            enemy.takeDamage(player.getAttack());
            std::cout << "Enemy's HP after attack: " << enemy.getHP() << std::endl;

            if (!enemy.isAlive()) {
                std::cout << "The enemy has been defeated!\n";
                break;
            }

            enemy.attack();
            player.takeDamage(enemy.getAttack());
            std::cout << "Your HP after enemy attack: " << player.getHP() << std::endl;

            if (!player.isAlive()) {
                std::cout << "You have been defeated!\n";
            }
        }
    }
};

int main() {
    int choice;
    std::cout << "Choose character class:\n1. Tank\n2. Mage\n3. Thief\n";
    std::cin >> choice;

    Character* player = nullptr;
    switch (choice) {
        case 1: player = new Tank(); break;
        case 2: player = new Mage(); break;
        case 3: player = new Thief(); break;
        default:
            std::cout << "Invalid choice!\n";
            return 1;
    }


    Character* enemy = new Mage();


    std::cout << "Your character:\n";
    player->stats();

    std::cout << "\nEnemy character:\n";
    enemy->stats();


    Battle battle;
    battle.start(*player, *enemy);


    delete player;
    delete enemy;

    return 0;
}
