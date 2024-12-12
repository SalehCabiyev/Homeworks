#include <iostream>

 int main() {
//      int n = 5;
//     int numbers_array[n][n] =
//     {
//         {1,2,3,8,6},
//         {4,5,6,1,4},
//         {7,8,9,7,9},
//           {1,2,3,8,6},
//           {1,2,3,4,2}
//     };
//     for (int i=0;i<n;i++) {
//         for (int j=0;j<n;j++) {
//             std::cout << numbers_array[i][j] << " ";
    //
    //     }
    //
    //         std::cout <<std::endl ;
    // }
    // std::cout <<std::endl ;
    //
    // for (int i = 0; i < n / 2; ++i) {
    //     int temp = numbers_array[i][i];
    //     numbers_array[i][i] = numbers_array[n - 1 - i][n - 1 - i];
    //     numbers_array[n - 1 - i][n - 1 - i] = temp;
    // }
    // for (int i = 0; i < n / 2; ++i) {
    //     int temp = numbers_array[i][n - 1 - i];
    //     numbers_array[i][n - 1 - i] = numbers_array[n - 1 - i][i];
    //     numbers_array[n - 1 - i][i] = temp;
    // }
    //
    // for (int k=0;k<n;k++) {
    //     for (int b=0;b<n;b++) {
    //         std::cout << numbers_array[k][b] << " ";
    //
    //     }
    //
    //     std::cout <<std::endl ;

    // }
    const int row = 5, col = 5;
    int numbers_array[row][col] =
    {
        {1,2,3,8,6},
         {4,5,6,1,4},
         {7,8,9,7,9},
           {1,2,3,8,6},
           {1,2,3,4,2}
    };
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            std::cout << numbers_array[i][j] << " ";

        }

        std::cout <<std::endl ;
    }
    std::cout <<std::endl ;


     for (int i = 0; i < row; ++i) {

         int first = numbers_array[i][0];


         for (int j = 0; j < col - 1; ++j) {
             numbers_array[i][j] = numbers_array[i][j + 1];
         }


         numbers_array[i][col - 1] = first;
     }




    for (int k=0;k<row;k++) {
        for (int b=0;b<col;b++) {
            std::cout << numbers_array[k][b] << " ";

        }

        std::cout <<std::endl ;
    }
        return 0;

}