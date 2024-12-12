#include <iostream>
#include <string.h>

class Grocery {
private:
    char* _name;
    char* _type;
    float _price;
public:
    // Constructor
    Grocery() {
        _name = nullptr;
        _type = nullptr;
        _price = 0;
    }
    Grocery(const char* name, const char* type, float price) : _price(price)
    {
        _name = new char[strlen(name) + 1];
        _type = new char[strlen(type) + 1];


        strcpy(_name, name);
        strcpy(_type, type);
    }
    // copy constructor
    Grocery(const Grocery& other) : _price(other._price) {
        if (other._name && other._type)
        {
            _name = new char[strlen(other._name) + 1];
            _type = new char[strlen(other._type) + 1];


            strcpy(_name, other._name);
            strcpy(_type, other._type);
        }
        else {
            _name = nullptr;
            _type = nullptr;
        }
    }

    ~Grocery() {
        delete[] _name;
        delete[] _type;
    }

    Grocery& operator=(const Grocery& other) {
        if (this != &other)
        {
            delete[] _name;
            delete[] _type;
            _price = other._price;
            if (other._name && other._type)
            {
                _name = new char[strlen(other._name) + 1];
                _type = new char[strlen(other._type) + 1];


                strcpy(_name, other._name);
                strcpy(_type, other._type);
            }
            else {
                _name = nullptr;
                _type = nullptr;
            }
        }
        return *this;
    }

    // getters
    char* get_name() const;
    char* get_type() const;
    float get_price() const;

    //setters
    void set_name(char* other);
    void set_type(char* other);
    void set_price(float other);


};


char* Grocery::get_name() const {
    return _name;
}
char* Grocery::get_type() const {
    return _type;
}
float Grocery::get_price() const {
    return _price;
}
void Grocery::set_name(char* other) {
    if (other != nullptr)
    {
        _name = other;
    }
}
void Grocery::set_type(char* other) {
    if (other != nullptr)
    {
        _type = other;
    }
}
void Grocery::set_price(float other) {
    if (other >= 0)
    {
        _price = other;
    }
}


class Market {
private:
    char* _name;
    Grocery* _groceries;
    size_t _capacity;
    size_t _count;

public:
    Market(const char* name, size_t capacity)
    {
        _capacity = capacity;
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
        _count = 0;
        _groceries = new Grocery[capacity];
    }

    ~Market() {
        delete[] _groceries;
        delete[] _name;
    }

    void add_grocery_index(unsigned int index);

    void remove_index(unsigned int index, const Grocery &grocery);

    void remove_index(unsigned int index);


    int find(const char*name);

    bool remove_grocery_index(size_t index);

    void add_grocery_index(unsigned int index, const Grocery &grocery);

    bool add_grocery(const Grocery& grocery);
    bool remove_grocery(const char* name);
    size_t get_count() const;
    const Grocery& get_grocery(int index);
};
int Market:: find(const char*parametr) {
    for (int i=0;i<_count;i++) {
        if (strcmp(_groceries[i].get_name(), parametr) == 0) {
            std::cout << i<<" ";//dla proverki
            break;

        }
        else if (strcmp(_groceries[i].get_type(),parametr)== 0) {

            std::cout << i<<" ";//dla proverki
            break;
        }

    }
    return 0;

}

bool Market::remove_grocery_index(size_t index) {
    if (index<_count) {
        for (size_t i=index;i<_count-1;i++) {
            _groceries[i]=_groceries[i+1];
        }
        _count--;
        return true;
    }
    else return false;

}
void Market::add_grocery_index(unsigned int index, const Grocery& grocery) {
    if (_count < _capacity && index <= _count) {

        for (size_t i = _count; i > index; --i) {
            _groceries[i] = _groceries[i - 1];
        }

        _groceries[index] = grocery;
        ++_count;
    }
}

bool Market::add_grocery(const Grocery& grocery) {
    if (_count < _capacity)
    {
        _groceries[_count++] = grocery;
        return true;
    }

    return false;
}

bool Market::remove_grocery(const char* name) {
    for (size_t i = 0; i < _count; i++)
    {
        if (strcmp(_groceries[i].get_name(), name) == 0)
        {
            for (size_t j = 0; j < _count - 1; j++)
            {
                _groceries[j] = _groceries[j + 1];
            }
            --_count;
            return true;
        }
    }
    return false;
}

size_t Market::get_count() const {
    return _count;
}


const Grocery& Market::get_grocery(int index) {
    if (index>= 0 && index < _count)
    {
        return _groceries[index];
    }
}

void display_products(Market& market) {
    for (size_t i = 0; i < market.get_count(); i++)
    {
        std::cout << "\nName: " << market.get_grocery(i).get_name();
        std::cout << "\nType: " << market.get_grocery(i).get_type();
        std::cout << "\nPrice: " << market.get_grocery(i).get_price();
    }
}



int main() {
    Market market("AftandilShop", 10);

    Grocery product_1("Orange", "Fruit", 5);
    Grocery product_2("Banana", "Fruit", 9);
    Grocery product_3("Cucumber", "Vegetable", 1.2f);
    Grocery product_4(product_3);

    market.add_grocery(product_1);
    market.add_grocery(product_2);
    market.add_grocery(product_3);
    market.add_grocery(product_4);
    market.add_grocery_index(1,product_4);
    market.remove_grocery_index(1);
    market.find("Cucumber");
    display_products(market);
}