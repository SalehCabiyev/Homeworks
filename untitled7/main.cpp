#include <iostream>

int main() {
   //  int m=3;
   //  int n=4;
   // int matrix[m][n]={
   //     {1,2,3,4},
   //     {5,6,55,8},
   //     {9,10,11,5}
   //
   // };
   //  int matrix2[m][n]={
   //      {1,2,3,4},
   //      {5,6,7,8},
   //      {9,10,11,12}
   //  };
   //  int matrix3[m][n]={
   //      {0,0,0,0},
   //      {0,0,0,0},
   //      {0,0,0,0}
   //  };

    // int *ptr1=&matrix[0][0];
    // int *ptr2=&matrix2[0][0];
    // int *ptr3=&matrix3[0][0];
    // for (int i=0;i<m*n;i++) {
    //     *(ptr3+i)=*(ptr2+i)+*(ptr1+i);
    //
    //
    // }
    //
    // for (int i=0;i<m;i++) {
    //     for (int j=0;j<n;j++) {
    //         std::cout<<matrix3[i][j]<<" ";
    //     }std::cout<<std::endl;
    // }
//test2

    // int*ptr4=&matrix[0][0];
    // for (int i=0;i<m;i++) {
    //     for(int j=0;j<n;j++) {
    //         if(matrix[i][j]==55){std::cout<<"m="<< i <<"n="<<j;}
    //     }std::cout<<std::endl;
    //
    // }
    //
    // for (int i=0;i<m*n;i++) {
    //     if (*ptr4<*(ptr4+i)){*ptr4=*(ptr4+i);}
    //
    // }std::cout<<"max element="<<*ptr4;
// test3
    int n=4;
    int matrix4[n][n]={
        {1,2,3,4},
        {5,6,7,8},
        {9,1,6,2},
        {5,6,7,8}
    };
    int k=0;
    int b=0;

    int* ptr5=&matrix4[0][0];
    int* ptr6=&matrix4[0][3];

    for (int i=0;i<n;i++) {
        k+=*(ptr5+n*i+i);
        b+=*(ptr6+(n-1)*i);

    }

    std::cout<<k<<"  pervaya diaqonal";std::cout<<std::endl;
    std::cout<<b<<"  vtoraya diaqonal";std::cout<<std::endl;
    std::cout<<k+b<<"  summa diaqonaley";std::cout<<std::endl;










    return 0;
}

