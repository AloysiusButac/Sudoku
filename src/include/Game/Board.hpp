#pragma once

#include <array>
#include <iostream>
#include <cstdlib>

class Board {
public:
    // Return values in the input coordinate's row
    std::array<int, 9> getRow(int x, int y);
    // Return values in the input coordinate's coloumn
    std::array<int, 9> getCol(int x, int y);
    // Return values in the input coordinate's block
    std::array<int, 9> getBlock(int x, int y);
    // Randomizes digits and removes digits in the board array
    void NewGameBoard();
    // Validates of a number can be placed in a cell
    bool isValidPos(int x, int y, int value);
    // Validates of a number can be placed in a row
    bool isValidRow(int x, int y, int value);
    // Validates of a number can be placed in a coloumn
    bool isValidColoumn(int x, int y, int value);
    // Randomizes values in a board
    void randomize(int b[9][9]);

public:
    int board [9][9];
};

std::array<int, 9> Board::getRow(int x, int y) {
    std::array<int, 9> row;
    for(int i = 0; i < 9; i++) {
        row[i] = board[i][y];
    }
    return row;
}
std::array<int, 9> Board::getCol(int x, int y) {
    std::array<int, 9> col;
    for(int i = 0; i < 9; i++) {
        col[i] = board[x][i];
    }
    return col;
}
std::array<int, 9> Board::getBlock(int x, int y) {
    // TODO: Fix logic
    std::array<int, 9> blk;
    int x_blk = 9 / x;
    int y_blk = 9 / y;
    int x_blk2 = 9 % x;
    int y_blk2 = 9 % y;

    int index = 0;
    int i = 0, j = 0;
    if(x_blk2 == 0) {
        j = x;
    } else if(x_blk2 == 1) {
        j = x-1;
    } else if(x_blk2 = 2) {
        j = x-2;
    }

    if(y_blk2 == 1) {
        i = y;
    } else if(y_blk2 == 1) {
        i = y-1;
    } else if(y_blk2 = 2) {
        i = y-2;
    }

    for(; i < y+3; i++) {
        for(; i < x+3; j++) {
            blk[0] = this->board[j][i];
            j++;
        }
    }

    int coord_x = (x_blk * 3) + x_blk2;
    int coord_y = (y_blk * 3) + y_blk2;

    std::cout << "[" << coord_x << ", " << coord_y << "]\n[";
    for(auto n : blk) {
        std::cout << n << " ";
    }
    std::cout << "]";

    return blk;
}
void Board::NewGameBoard() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            board[j][i] = j+1;
        }
    }
}
bool Board::isValidPos(int x, int y, int value) {
    return isValidRow(x, y, value) && isValidColoumn(x, y, value);
}
bool Board::isValidRow(int x, int y, int value) {
    auto row = getRow(x, y);
    for(int i = 0; i < 9; i++) {
        if(value == row[i]) {
            return false;
        }
    }
    return true;
}
bool Board::isValidColoumn(int x, int y, int value) {
    auto col = getCol(x, y);
    for(int i = 0; i < 9; i++) {
        if(value == col[i]) {
            return false;
        }
    }
    return true;
}

void Board::randomize(int b[9][9]) {
    std::time(0);
    int n = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            n = std::rand() % 9;
            if(isValidPos(i, j, n)) {
                b[i-1][j-1] = n+1;
                continue;
            }
            j = j > 0 ? j-- : 0;
            i = i > 0 ? i-- : 0;
        }
    }
}
