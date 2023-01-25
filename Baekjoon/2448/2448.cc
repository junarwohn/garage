#include <iostream>

void init(char **, int);
void erase_pyramid(char **, int, int, int);
int N = 0;

int main(void) {
    std::cin >> N;
    char ** pyramid = new char*[N];
    for (int i = 0; i < N; i++) {
        pyramid[i] = new char[2* N + 1];
        for (int j = 0; j < 2*N; j++) {
            pyramid[i][j] = ' ';
        }
        pyramid[i][2 * N - 1] = '\0';
    }
    init(pyramid, N);
    erase_pyramid(pyramid, 0, N - 1, N);
    for (int i = 0; i < N; i++)
        std::cout << pyramid[i] << '\n';
}

void init(char ** py_, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = -i; j <= i; j++) {
            py_[i][n - 1 + j] = '*';
        }
    }
}

void erase_pyramid(char ** py_, int row, int col, int height) {
    // std::cout << "row : " << row << " , col is : " << col << " , height is : " << height << '\n';
    // py_[row][col] = '@';
    if (height <= 3) {
        py_[row + 1][col] = ' ';
        // for (int i = 0; i < N; i++)
        //     std::cout << py_[i] << '\n';
    } else {
        int erase_range = ((height) / 2) - 1;
        int erase_row_s = row + (height) / 2;
        int erase_col_s = col;
        for (int y = erase_row_s; y < row + height; y++) {
            for (int x = erase_col_s - erase_range; x <= erase_col_s + erase_range; x++) {
                py_[y][x] = ' ';
            }
            erase_range--;
        }
        // for (int i = 0; i < N; i++)
        //     std::cout << py_[i] << '\n';
        erase_pyramid(py_, row, col, height/2);
        erase_pyramid(py_, row + height/2, col - height/2, height/2);
        erase_pyramid(py_, row + height/2, col + height/2, height/2);
    }
}