#include <iostream>

class Vehicle {
protected:
    char*_brand;
    char*_model;
    int _speed;

public:
    void*data;
Vehicle(char* brand,char*model,int speed) {
    _brand=brand;
    _model=model;
    _speed=speed;
}
   virtual void vehicle_information()=0;

};
class Car : public Vehicle{
private:
    int _doors;
    bool _conditioner;
public:
    Car(char* brand,char*model,int speed, int doors,bool conditioner) :Vehicle( brand,model,speed) {
        _doors=doors;
        _conditioner=conditioner;
    }



    void vehicle_information() override {
        std::cout << "information about Car"<<std::endl;
    }
    Vehicle* getVehicle() {
       return this;
    }
    void reinterpret_foo() {
        Car*car=reinterpret_cast<Car *>(data);
        if (car) {
            car->vehicle_information();
        }
        else{ std::cout << "Data does not point to a Car object."<<std::endl; }
    }
};



class Motorcycle :public Vehicle {
private:
   char _car_steering_wheel;
public:
    Motorcycle(char* brand,char*model,int speed,char car_steering_wheel):Vehicle(brand,model,speed) {
        _car_steering_wheel=car_steering_wheel;
    }
    void vehicle_information() override {
        std::cout << "information about Motorcycle"<<std::endl;
    }
};

void dynamic(Vehicle*car){
    Car*car2=dynamic_cast<Car*>(car);
    if (car2) {
        car2->vehicle_information();
    }
    else {
        std::cout << "This is not a car."<<std::endl;
    }
}




int main(){

    Vehicle* car1=new Car("dsja","dwda",9,2,"yes");
    dynamic(car1);
    Car* car=new Car("tayota","cruze",250,4,"yes");
    Vehicle*vehicle=car->getVehicle();
    Car*casted_car=static_cast<Car*>(vehicle);
    casted_car->vehicle_information();
    Vehicle*car3=new Car("dsja","dwda",9,2,"yes");
    Car *car5=new Car("dsada,""dsadsa","dw",2,6,"dw");
    car5->reinterpret_foo();
    car5->data=reinterpret_cast<void*>(car5);
    car5->reinterpret_foo();






return 0;
}