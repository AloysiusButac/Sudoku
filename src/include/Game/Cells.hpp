#pragma once

#include <array>
#include <iostream>

class Cells {
public:
    // Return values in the input coordinate's row
    std::array<int, 9> getRow(int x, int y);
    // Return values in the input coordinate's coloumn
    std::array<int, 9> getCol(int x, int y);
    // Return values in the input coordinate's block
    std::array<int, 9> getBlock(int x, int y);

public:
    int board [9][9];
};

std::array<int, 9> Cells::getRow(int x, int y) {
    std::array<int, 9> row;
    for(int i = 0; i < 9; i++) {
        row[i] = board[i][y];
    }
    return row;
}
std::array<int, 9> Cells::getCol(int x, int y) {
    std::array<int, 9> col;
    for(int i = 0; i < 9; i++) {
        col[i] = board[x][i];
    }
    return col;
}
std::array<int, 9> Cells::getBlock(int x, int y) {
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

