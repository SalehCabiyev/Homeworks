#include <iostream>
#include <conio.h>

const short ROWS = 6;
const short COLS = 6;
int score = 0;
int lives = 3; //

template<typename T>
void generate_matrix(T matrix[ROWS][COLS], T initial_value) {

    for (unsigned short i = 0; i < ROWS; i++) {
        for (unsigned short j = 0; j < COLS; j++) {
            matrix[i][j] = initial_value;
        }
    }


    for (int i = 0; i < 5; ++i) {
        matrix[rand() % ROWS][rand() % COLS] = '#';
    }


    int g_row, g_col;
    while (true) {
        g_row = rand() % ROWS;
        g_col = rand() % COLS;
        if (matrix[g_row][g_col] == '.') {
            matrix[g_row][g_col] = 'G';
            break;
        }
    }


    for (int i = 0; i < 3; ++i) {
        int mine_row, mine_col;
        while (true) {
            mine_row = rand() % ROWS;
            mine_col = rand() % COLS;
            if (matrix[mine_row][mine_col] == '.') {
                matrix[mine_row][mine_col] = 'M';
                break;
            }
        }
    }
}

template<typename T>
void display_matrix(const T matrix[ROWS][COLS], int p_row, int p_col) {
    system("cls");
    for (unsigned short i = 0; i < ROWS; i++) {
        for (unsigned short j = 0; j < COLS; j++) {
            if (i == p_row && j == p_col) {
                std::cout << 'P' << ' ';
            } else {
                std::cout << matrix[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << "scet: " << score << "  jizni: " << lives << std::endl;
}

template<int row, int col>
void move_player(char direction, int& p_row, int& p_col, char matrix[row][col]) {
    int new_row = p_row;
    int new_col = p_col;

    switch (direction) {
        case 'w':
            if (p_row > 0) --new_row;
            break;
        case 's':
            if (p_row < row - 1) ++new_row;
            break;
        case 'a':
            if (p_col > 0) --new_col;
            break;
        case 'd':
            if (p_col < col - 1) ++new_col;
            break;
        default:
            std::cout << "neverniy xod" << std::endl;
            return;
    }

    if (matrix[new_row][new_col] != '#') {
        p_row = new_row;
        p_col = new_col;
    }
}

int main() {
    char matrix[ROWS][COLS];
    generate_matrix(matrix, '.');

    int player_row = 0, player_col = 0;

    display_matrix(matrix, player_row, player_col);

    while (true) {
        char move = _getch();

        if (move == 'q') break;

        matrix[player_row][player_col] = '.';
        move_player<ROWS, COLS>(move, player_row, player_col, matrix);

        if (matrix[player_row][player_col] == 'G') {
            score++;
            std::cout << "scet: " << score << std::endl;


            int g_row, g_col;
            while (true) {
                g_row = rand() % ROWS;
                g_col = rand() % COLS;
                if (matrix[g_row][g_col] == '.') {
                    matrix[g_row][g_col] = 'G';
                    break;
                }
            }
        } else if (matrix[player_row][player_col] == 'M') {
            lives--;
            score = 0;
            std::cout << "vi popali v minu! jizni: " << lives << std::endl;


            int mine_row, mine_col;
            while (true) {
                mine_row = rand() % ROWS;
                mine_col = rand() % COLS;
                if (matrix[mine_row][mine_col] == '.') {
                    matrix[mine_row][mine_col] = 'M';
                    break;
                }
            }
        }

        matrix[player_row][player_col] = 'P';
        display_matrix(matrix, player_row, player_col);

        if (lives <= 0) {
            std::cout << "game over." << std::endl;
            break;
        }
    }

    return 0;
}
