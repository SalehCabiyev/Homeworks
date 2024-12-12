#include <iostream>
#include <string.h>

class Car {
private:
    char *_name;
    char*_colour;
    float _motor;
public:
    void display_Car() {
        std::cout << _name<<std::endl<<_colour<<std::endl<<_motor<<std::endl;
    }
    Car() {
        _name=nullptr;
        _colour=nullptr;
        _motor=0;
    }
    Car(const char*name,const char* colour,float motor):_motor(motor) {
        _name=new char[strlen(name)+1];
        _colour=new char[strlen(colour)+1];

        strcpy(_name,name);
        strcpy(_colour,colour);
    }
    Car(const Car & other):_motor(other._motor) {
        if (other._name && other._colour){
            _name=new char[strlen(other._name)+1];
            _colour=new char[strlen(other._colour)+1];

            strcpy(_name,other._name);
            strcpy(_colour,other._colour);
        }
        else
            _name=nullptr;
            _colour=nullptr;
    }
        ~Car() {
            delete[]_name;
            delete[]_colour;
    }
    Car& operator=(const Car& other) {
        if (this != &other)
        {
            delete[] _name;
            delete[] _colour;
            _motor=other._motor;
            if (other._name && other._colour)
            {
                _name = new char[strlen(other._name) + 1];
                _colour = new char[strlen(other._colour) + 1];


                strcpy(_name, other._name);
                strcpy(_colour, other._colour);
            }
            else {
                _name = nullptr;
                _colour = nullptr;
            }
        }
        return *this;

    }
    Car operator=(Car && other)noexcept {
        if (this!=&other) {
            delete[]_name;
            delete[]_colour;

            _name=other._name;
            _colour=other._colour;
             _motor=other._motor;

            other._name=nullptr;
            other._colour=nullptr;
            other._motor=0;
        }
        return *this;
    }
    int length () {
        int len=0;
        while (_name[len]!='\0'){len++;}
        return len;
    }
     int lengthd ( const char* other)const {
        int len=0;
        while (other[len]!='\0'){len++;}
        return len;
    }
    void append(const char*other) {
        if (other==nullptr || lengthd(other)==0) return;
        int currentlength=0;
        if (_name) {
            currentlength=lengthd(_name);
        }
        int otherlength=lengthd(other);
        int newlength=currentlength+otherlength;
        char* new_name=new char[newlength+1];
        if (_name) {
            for (size_t i = 0; i < currentlength; ++i) {
                new_name[i] = _name[i];
            }
        }
        for (size_t i = 0; i < otherlength; ++i) {
            new_name[currentlength + i] = other[i];
        }
        new_name[newlength] = '\0';
        delete[] _name;
        _name = new_name;

    }
    char* substring(int start, int length) const {
        if (start < 0 || length <= 0) {
            return nullptr;
        }

        if (_name == nullptr) {
            return nullptr;
        }

        int name_length = lengthd(_name);

        if (start >= name_length) {
            return nullptr;
        }


        if (start + length > name_length) {
            length = name_length - start;
        }


        char* result = new char[length + 1];

        for (int i = 0; i < length; ++i) {
            result[i] = _name[start + i];
        }

        result[length] = '\0';


        return result;
    }
    int find(const char* substr) const {
        if (substr == nullptr || _name == nullptr) {
            return -1;
        }

        int name_length = lengthd(_name);
        int substr_length = lengthd(substr);

        if (substr_length == 0) {
            return 0;
        }

        for (int i = 0; i <= name_length - substr_length; ++i) {
            bool found = true;

            for (int j = 0; j < substr_length; ++j) {
                if (_name[i + j] != substr[j]) {
                    found = false;
                    break;
                }
            }

            if (found) {
                return i;
            }
        }

        return -1;
    }
    void to_upper() {
        if (_name == nullptr) return;
        for (int i=0;i<lengthd(_name);i++) {
          if (_name[i]>='a'&& _name[i]<='z') {
            _name[i]=_name[i]-32;

          }

        }



    }




};


int main() {
    Car my_car("Tayota","black",4.1);
    Car car_2("kamaz","blue",2.2);
    my_car.display_Car();

    car_2=my_car;
    car_2.display_Car();

    my_car.length();


    my_car.append("saleh");
    my_car.display_Car();




    my_car.substring(1,5);


    car_2.to_upper();
    car_2.display_Car();

    return 0;
}
