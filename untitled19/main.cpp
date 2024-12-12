
#include <iostream>
#include <string.h>


std::istream operator>>(const std::istream & is, char * rhs);

class Car {
private:

    char* _name;
    char*_colour;
public:
    static int count;

    Car() {
        count++;
        _name=nullptr;
        _colour=nullptr;
    }
    Car(char*name,char*colour) {;
        count++;
        _name=new char[strlen(name)+1];
        _colour=new char[strlen(colour)+1];
        strcpy(_name,name);
        strcpy(_colour,colour);

    }
    Car& operator=(const Car& other) {

        if (this != &other)
        {
            delete[] _name;
            delete[] _colour;

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
    ~Car() {
        delete[] _name;
        delete[] _colour;
    }
    Car operator+(const Car& other) {
        char* Newname=new char[strlen(_name)+strlen(other._name)+1];
        char* Newcolour=new char[strlen(_colour)+strlen(other._colour)+1];
        strcpy(Newname,_name);
        strcpy(Newcolour,_colour);
        strcat(Newname,other._name);
        strcat(Newcolour,other._colour);
        return Car(Newname,Newcolour);

    }
    bool operator==( const Car& other) {
        if ((strcmp(_name,other._name)==0) && (strcmp(_colour,other._colour)==0) ) return true;
        else return false;

    }
    Car operator+=(const Car &other) {

            char*Newname=new char[strlen(_name)+strlen(other._name)+1];
            char*Newcolour=new char[strlen(_colour)+strlen(other._colour)+1];
            strcpy(Newname,_name);
            strcpy(Newcolour,_colour);
            strcat(Newname,other._name);
            strcat(Newcolour,other._colour);

            _name=Newname;
            _colour=Newcolour;
            return Car(Newname,Newcolour);
        }

    bool operator!=( const Car& other) {
        if ((strcmp(_name,other._name)==0) && (strcmp(_colour,other._colour)==0) ) return false;
        else return true;

    }
    Car operator*(const int &n) {
        if (n>0) {
            char*Newname=new char[strlen(_name)*n+1];
            char*Newcolour=new char[strlen(_colour)*n+1];
            Newname[0] = '\0';
            Newcolour[0] = '\0';

            for (int i=0;i<n;i++) {
                strcat(Newname,_name);
                strcat(Newcolour,_colour);
            }


            return Car(Newname,Newcolour);
        }
    }
    // Move constructor
    Car (Car &&other)noexcept {
        _name=other._name;
        _colour=other._colour;
        other._name=nullptr;
        other._colour=nullptr;
    }
    // Move assignment operator
    Car &operator=(Car &&other)noexcept {
        if (this!=&other) {
            delete[]_name;
            delete[]_colour;
            _name=other._name;
            _colour=other._colour;
            other._name=nullptr;
            other._colour=nullptr;

        }
        return *this;
    }
    //test1
    char operator()(size_t index) const{
        if (index<strlen(_name)) {
            return _name[index];
        }
        else return 1;
    }
    //test2
    char& operator[](size_t index) {
       if (index<strlen(_name)) {
             return _name[index];
       }
    }
     const char & operator[](size_t index)const {
       if (index<strlen(_name)) {
             return _name[index];
       }
    }
    void change(size_t index,char symbol) {
        if (index<strlen(_name)) {
            _name[index]=symbol;
        }
    }
    friend std::ostream& operator<<(std::ostream &os,const Car& car) {
        os<<"("<<car._name<<","<<car._colour<<")";
        return os;

    }friend std::istream& operator>>(std::istream& is, Car& car) {
        int const Bufer_size=256;
        char name[Bufer_size];
        char colour[Bufer_size];
        is >>name>>colour;
        car._name=new char[strlen(name)+1];
        strcpy(car._name,name);
        car._colour=new char[strlen(colour)+1];
        strcpy(car._colour,colour);
        return is;

    }






    char *get_name() const;

    char *get_colour() const;

    void *set_name(char* other);

    void *set_colour(char *other);
};
int Car::count=0;
char* Car::get_name()const {return _name;}

char *Car::get_colour()const{return _colour;}

void *Car::set_name(char* other) {
    if (other != nullptr) {

        _name = other;
    }
}
void *Car::set_colour(char*other) {
    if (other != nullptr) {

        _colour = other;
    }
}
void display(Car &other) {
    std::cout << "Name: "<<other.get_name()<<std::endl<<"Colour: "<<other.get_colour()<<std::endl;
}


int main() {
    Car car1("tayota","black");
    Car car2("Bmw","white");
    Car car4("porshe","red");
    display(car2);
    Car car3=car1+car2;
    display(car3);
    car1==car2;

   Car car5=car1*3;
    display(car5);

    car1+=car4;
    display(car1);
    Car car9=std::move(car2);
    display(car9);
    car1=std::move(car3);
    Car car8;

    std::cout<<"count: "<<Car::count<<std::endl;

    //test 1
    std::cout<<"show symbol by index: "<<car1(1)<<std::endl;
    //test 2
    car1.change(2,'d');
    std::cout<<"change symbol by index: "<<car1.get_name()<<std::endl;
    //test 3
    std::cout<<" Operator <<: "<<car1<<std::endl;
    //test 4
    std::cout<<"Enter name and colour";
    std::cin >> car8;
    std::cout<<car8<<std::endl;






    return 0;
}
