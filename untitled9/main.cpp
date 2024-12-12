#include <iostream>

    char *stroka="DSDFJlfhjskdfhsk ";
  int len() {
      for (int i=0;i<i+1;i++) {
              if (stroka[i]==' '){std::cout<<i;break;}
          }
      return 0;


  }

char *strokab="asfhkfjdshf ";
void upper() {
    for (int i=0;i<i+1;i++) {
        if (strokab[i]==' '){break;}
        int asciiCode=strokab[i]-32;
        char character = (char)asciiCode;
        std::cout<<character;
    }
std::cout<<std::endl;
}


int arr[5] = {5, 3, 8, 6, 2};
int size = 5;
void sortArray(int* arr, int size, int (*compare)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) > 0) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int compareAsc(int a, int b) {
    return a - b;
}


int compareDesc(int a, int b) {
    return b - a;
}
int print_matrix() {
    for (int i=0;i<size;i++) {
        std::cout<<arr[i]<<" ";
    }std::cout<<std::endl;
    return 0;
}
///////////////////////////////////////////////////////
const int OPERATIONS_SIZE = 4;

template<typename T>
T add(T a, T b){
    return a + b;
}

template<typename T>
T subtract(T a, T b){
    return a - b;
}

template<typename T>
T multiply(T a, T b){
    return a * b;
}

template<typename T>
T divide(T a, T b){
    return a / b;
}


int main() {

    // test1

    upper();
    len();
    // test2

    // sortArray(arr, 5, compareAsc);
    //
    // print_matrix();
    //
    // sortArray(arr, 5, compareDesc);
    // print_matrix();
   //test3

    // std::cout<<"menu:"<<std::endl;
    // std::cout<<"0. add"<<std::endl;
    // std::cout<<"1. subtract"<<std::endl;
    // std::cout<<"2. multiply"<<std::endl;
    // std::cout<<"3. divide"<<std::endl;
    // int n=0;
    // int a=0;
    // int b=0;
    // while (true) {
    //     std::cout<<"enter operation number"<<std::endl;
    //     std::cin>>n;
    //     std::cout<<"enter a "<<std::endl;
    //     std::cin>>a;
    //     std::cout<<"enter b"<<std::endl;
    //     std::cin>>b;
    //     if (b==0 && n==3){std::cout<<"error";}
    //
    //     float (*operations[OPERATIONS_SIZE])(float, float) = {add, subtract, multiply,divide};
    //     std::cout<<"result"<<std::endl;
    //     auto result = operations[n](a,b);
    //     std::cout<<result<<std::endl;
    //     if (b!=0 && n!=3){break;}
    // }
    return 0;
}
