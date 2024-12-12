#include <iostream>
void insert(int index,float number,int &size,int*&array,int*&newarray) {

    for (int i=0;i<index;i++) {
        newarray[i]=array[i];
    }
    for (int i=0;i<size-index;i++) {
        newarray[index+1+i]=array[index+i];
    }
    newarray[index]=number;
    size++;
    delete[]array;
}
void pop(int*newarray, int* array, unsigned int &size, unsigned int index,int number) {


    for (int i=0;i<index;i++) {
        newarray[i]=array[i];
    }
    for (int i=0;i<size-index;i++) {
        newarray[index+i]=array[index+1+i];
    }
    delete[]array;
    size--;
}
    void print_array(int* array,unsigned int size) {
     for (int i=0;i<size;i++) {
         std::cout<<array[i]<<" ";
         } std::cout<<std::endl;
}
    void full_array(int*array,unsigned int size) {
    srand(time(NULL));
    for (int i=0;i<size;i++) {
        array[i]=rand()%100;
    }

}
void clear(int*&array,int size) {
    delete[]array;
    array=nullptr;
    size=0;

}
int main() {
    //test 1 (insert)

    // int new_simvol=0;
    // int size=0;
    // std::cout<<"Enter size:";
    // std::cin>>size;
    // int*newarray=new int[size+1];
    // int*array=new int [size];
    // srand(time(NULL));
    // full_array(array,size);
    // print_array(array,size);
    //  int index=0;
    // int number=0;
    // std::cout<<"Enter index";
    // std::cin >> index;
    // std::cout<<"Enter number";
    // std::cin >> number;
    // insert(index,number,size,array,newarray);
    // print_array(newarray,size);
////////////////////////////////////////////////////////
// test 2 (pop)
//     unsigned int size=0;
//     unsigned int index=0;
//     int number=0;
//     int*array=new int[size];
//     int *newarray=new int[size-1];
//
// while (true) {
//     std::cout<<"Enter array size:"<<std::endl;
//     std::cin >> size;
//     if (size==0){std::cout<<"wrong size"<<std::endl;}
//     else break;
// }
//     full_array(array,size);
//     print_array(array,size);
//     std::cout<<"Enter array index:"<<std::endl;
//     std::cin >> index;
//     pop(newarray,array,size,index,number);
//     print_array(newarray,size);

//test 3 (clear)
    // unsigned int size=0;
    // std::cout<<"Enter array size:"<<std::endl;
    // std::cin >> size;
    // int *array=new int[size];
    // full_array(array,size);
    // print_array(array,size);
    // clear(array,size);
    // if (array == nullptr) {
    //     std::cout << "The array is cleared." << std::endl;
    // }


    return 0;
}
