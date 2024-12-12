#include <iostream>
#include <string.h>

class Item
{
public:

    virtual void use()                          = 0;
    virtual const char* get_name() const        = 0;
    virtual ~Item() {}
    virtual const char* get_description() const = 0;
    virtual char* effect()                      = 0;
};

class Food : public Item {
public:
    void use() override {
        std::cout << "You used a food!" << std::endl;
    }

    const char* get_name() const {
        return "Food";
    }
    const char* get_description() const override  {
        return "food description";

    }
    char* effect() override {
        return "+ helth";
    }

};

class Stick : public Item {
public:
    void use() override {
        std::cout << "You used a stick!" << std::endl;
    }

    const char* get_name() const {
        return "Stick";
    }
   const char* get_description() const override {
        return "Stick description";

    }
    char* effect() override {
        return "+ other";

    }
};

class Inventory {
private:
    Item* _items[10];
    int _item_count;
public:
    Inventory() : _item_count(0) {}

    ~Inventory() {
        for (size_t i = 0; i < _item_count; i++)
        {
            delete _items[i];
        }
    }

    int get_items_count() const {
        return _item_count;
    }

    bool add_item(Item* item)
    {
        if (_item_count < 10)
        {
            _items[_item_count++] = item;
            return true;
        }
        return false;
    }

    bool use_item(int index) {
        if (index >= 0 && index < _item_count)
        {
            _items[index]->use();
            return true;
        }
        return false;
    }

    Item* operator[](int index) {
        return _items[index];
    }

};

void show_inventory(Inventory& inventory) {
    for (size_t i = 0; i < inventory.get_items_count(); i++)
    {
        std::cout << i << ". " << inventory[i]->get_name() << std::endl;
    }
}
class Potion :public Item{
public:
    void use() override {
        std::cout << "You used a potion!" << std::endl;
    }
    const char* get_name() const {
        return "Potion";
    }
   const char* get_description() const override {
        return "Potion description";

    }
    char* effect() override {
        return "+ bonus";
    }
};
class Armor :public Item{
public:
    void use() override {
        std::cout << "You used a Armor!" << std::endl;
    }
    const char* get_name() const {
        return "Armor";
    }
   const char* get_description() const override {
        return "Armor description";

    }
    char *effect() override {
       return  "+ Hp";
    }

};
void use_all_items(Inventory& inventory) {
    for (int i=0;i<inventory.get_items_count();i++) {
        inventory[i]->use();

    }
}

int main()
{
    Inventory inventory;

    inventory.add_item(new Food());
    inventory.add_item(new Food());
    inventory.add_item(new Food());

    inventory.add_item(new Stick());
    inventory.add_item(new Stick());
    inventory.add_item(new Potion());
    inventory.add_item(new Armor());

    show_inventory(inventory);

    inventory.use_item(0);
    inventory.use_item(1);
    inventory.use_item(5);
    inventory.use_item(6);

    show_inventory(inventory);
    use_all_items(inventory);
    Item *items[4];
    items[0]=new Armor;
    items[1]=new Food;
    items[2]=new Stick;
    items[3]=new Potion;
    for (int i=0;i<4;i++) {
        std::cout <<items[i]->get_description()<<std::endl;
        std::cout << items[i]->effect()<<std::endl;
    }



    return 0;
}