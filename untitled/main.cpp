#include <iostream>

int main() {
    int number;
    std::cout<<"Enter number";
    std::cin>>number;
    int firstnumber;
    firstnumber=number/100000+2;
    int secondnumber=number % 100000 /10000+2;
    int thirdnumber=number % 10000/1000+2;
    int fournumber=number % 1000/100+2;
    int fivenumber=number % 100/10+2;
    int sixnumber=number % 10+2;





    std::cout<<firstnumber;
    std::cout<<secondnumber;
    std::cout<<thirdnumber;
    std::cout<<fournumber;
    std::cout<<fivenumber;
    std::cout<<sixnumber;



}
