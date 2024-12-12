#include <iostream>

template<typename T>
T** generate_matrix(int rows, int cols) {
    T** temp_matrix = new T * [rows];

    for (unsigned short i = 0; i < rows; i++)
    {
        temp_matrix[i] = new T[cols];
    }
    return temp_matrix;
}

template<typename T>
void fill_matrix(T**& matrix, int rows, int cols) {
    srand(time(NULL));
    for (unsigned short i = 0; i < rows; i++)
    {
        for (unsigned short j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

template<typename T>
void display_matrix(T** matrix, int rows, int cols) {
    for (unsigned short i = 0; i < rows; i++)
    {
        for (unsigned short j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }std::cout << "\n\n\n\n";
    }
}

template<typename T>
void free_matrix(T**& matrix, int rows) {
    for (unsigned short i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}
// ########################################
// test1
template<typename T>
T** generate_newmatrix(int& rows, int &cols) {
    rows++;
    T** new_matrix = new T * [rows];

    for (unsigned short i = 0; i < rows; i++)
    {
        new_matrix[i] = new T[cols]();
    }
    return new_matrix;
}
template<typename T>
void copy_matrix(int rows,int cols,T**&new_matrix,T**& matrix) {
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            new_matrix[i][j] = matrix[i][j];

        }
    }
}
//########################################

template<typename T>
T** generate_newcollmatrix(int rows, int &cols) {
    cols++;
    T** new_matrix = new T * [rows];

    for (unsigned short i = 0; i < rows; i++)
    {
        new_matrix[i] = new T[cols]();
        for (unsigned short j = 0; j < cols; j++) {
            new_matrix[i][j] = (j < cols - 1) ? 0 : 0;
        }
    }
    return new_matrix;
}
template<typename T>
void copy_collsmatrix(int rows,int cols,T**&new_matrix,T**& matrix) {
    for (int i = 0; i < rows ; ++i) {
        for (int j = 0; j < cols-1; ++j) {
            new_matrix[i][j] = matrix[i][j];

        }
    }
}
//########################################
template<typename T>
T** generate_newremoverowmatrix(int& rows, int &cols) {
    rows--;
    T** new_matrix = new T * [rows];

    for (unsigned short i = 0; i < rows; i++)
    {
        new_matrix[i] = new T[cols]();
    }
    return new_matrix;
}
template<typename T>
void copy_rowmatrix(int rows,int cols,T**&new_matrix,T**& matrix) {
    for (int i = 0; i < rows ; ++i) {
        for (int j = 0; j < cols; ++j) {
            new_matrix[i][j] = matrix[i][j];

        }
    }
}
//########################################
template<typename T>
T** generate_newremovecallmatrix(int& rows, int &cols) {
    cols--;
    T** new_matrix = new T * [rows];

    for (unsigned short i = 0; i < rows; i++)
    {
        new_matrix[i] = new T[cols]();
    }
    return new_matrix;
}
template<typename T>
void copy_collsremovematrix(int rows,int cols,T**&new_matrix,T**& matrix) {
    for (int i = 0; i < rows ; ++i) {
        for (int j = 0; j < cols; ++j) {
            new_matrix[i][j] = matrix[i][j];

        }
    }
}



int main() {
//     int rows, cols;
//
//     std::cout << "Enter rows and columns(NxM): ";
//     std::cin >> rows >> cols;
//
//     int** matrix = generate_matrix<int>(rows, cols);
//     fill_matrix(matrix, rows, cols);
//     display_matrix(matrix, rows, cols);
//
//     int** new_matrix=generate_newmatrix<int>(rows,cols);
//     copy_matrix( rows,cols,new_matrix ,matrix);
//
//
//     for (int i=0;i<cols;i++) {
//         std::cin>>new_matrix[rows - 1][i];
//
//     }
//     display_matrix(new_matrix,rows,cols);
//     free_matrix(matrix,rows);
// free_matrix(new_matrix,rows);
    //test 2
    // int rows, cols;
    //
    // std::cout << "Enter rows and columns(NxM): ";
    // std::cin >> rows >> cols;
    //
    // int** matrix = generate_matrix<int>(rows, cols);
    // fill_matrix(matrix, rows, cols);
    // display_matrix(matrix, rows, cols);
    // int **newcollmatrix=generate_newcollmatrix<int>(rows,cols);
    // copy_collsmatrix(rows,cols,newcollmatrix,matrix);
    // for (int i=0;i<rows;i++) {
    //     std::cin>>newcollmatrix[i][cols-1];
    // }
    // display_matrix(newcollmatrix,rows,cols);
    // free_matrix(matrix,rows);
    // free_matrix(newcollmatrix,rows);

//test3
    // int rows, cols;
    //
    // std::cout << "Enter rows and columns(NxM): ";
    // std::cin >> rows >> cols;
    //
    // int** matrix = generate_matrix<int>(rows, cols);
    // fill_matrix(matrix, rows, cols);
    // display_matrix(matrix, rows, cols);
    // int**new_matrix=generate_newremoverowmatrix<int>(rows,cols);
    // copy_rowmatrix(rows,cols,new_matrix,matrix);
    // std::cout<<"second matrix"<<std::endl;
    // display_matrix(new_matrix,rows,cols);
    // free_matrix(matrix,rows);
    // free_matrix(new_matrix,rows);

//test4
    int rows, cols;

    std::cout << "Enter rows and columns(NxM): ";
    std::cin >> rows >> cols;

    int** matrix = generate_matrix<int>(rows, cols);
    fill_matrix(matrix, rows, cols);
    display_matrix(matrix, rows, cols);
    int**new_matrix=generate_newremovecallmatrix<int>(rows,cols);
    copy_collsremovematrix(rows,cols,new_matrix,matrix);
    std::cout<<"second matrix"<<std::endl;
    display_matrix(new_matrix,rows,cols);
    free_matrix(matrix,rows);
    free_matrix(new_matrix,rows);


    return 0;
}