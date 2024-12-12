#include <iostream>
//  const int  a=3;
//
//
// void print_matrix(int matrix[a][a]) {
//     for (int i=0;i<a;i++) {
//         for (int j=0;j<a;j++) {
//             std::cout<<matrix[i][j]<<" ";
//         }std::cout<<std::endl;
//     }std::cout<<std::endl;
//
// }
//
// void transpose_matrix(int source[a][a], int dest[a][a]) {
//     for (int i = 0; i < a; ++i) {
//         for (int j = 0; j < a; ++j) {
//             dest[j][i] = source[i][j];

//         }
//     }
// }
// int main() {
//     int matrix[a][a]={
//         {1,2,3},
//         {4,5,6},
//         {0,0,0}
//     };
//     int transposed[a][a];
//     print_matrix(matrix);
//     transpose_matrix(matrix,transposed);
//     print_matrix(transposed);
//     return 0;

//}
// test2

  const unsigned int  n=3;
void print_matrix(int matrix[n][n]) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            std::cout<<matrix[i][j]<<" ";
        }std::cout<<std::endl;
    }std::cout<<std::endl;
}
void zapolneniye(int matrix[n][n]) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            std::cin>>matrix[i][j];
        }std::cout<<std::endl;
    }
    print_matrix(matrix);
}
void rotate_matrix_90(int source[n][n], int dest[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dest[j][(n - 1 - i)] = source[i][j];
        }
    }
}


int main() {
    int matrix[n][n]={
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
;
    int rotated [n][n];

    zapolneniye(matrix);

    rotate_matrix_90(matrix,rotated);
    print_matrix(rotated);







    return 0;
}
