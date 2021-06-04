#pragma once

#include <array>
#include <iostream>
#include <cstdlib>

/////////////////////////////////////////////////////
/// TODO: Revise the get ROW, COL, and BLOCK functions
/////////////////////////////////////////////////////

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
    // Validates of a number can be placed in a block
    bool isValidBlock(int x, int y, int value);
    // Checks if the grid is empty
    bool isBoardFull();
    // Randomizes values in a board
    void randomize(int b[9][9]);
    // Fills the board with an inputted value
    void fillBoardWithInput(std::array<int, 9*9> values);
    // Remove values in a cell randomly
    void removeCells();
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
    int x_blk2 = x % 9;
    int y_blk2 = y % 9;
    if(x_blk2 == 0 && y_blk2 == 0) { // 0, 0
        blk[0] = board[x][y];
        blk[1] = board[x+1][y];
        blk[2] = board[x+2][y];
        blk[3] = board[x][y+1];
        blk[4] = board[x+1][y+1];
        blk[5] = board[x+2][y+1];
        blk[6] = board[x][y+2];
        blk[7] = board[x+1][y+2];
        blk[8] = board[x+2][y+2];
    } else if(x_blk2 == 0 && y_blk2 == 1) { // 1, 0
        blk[0] = board[x-1][y];
        blk[1] = board[x][y];
        blk[2] = board[x+1][y];
        blk[3] = board[x-1][y+1];
        blk[4] = board[x][y+1];
        blk[5] = board[x+1][y+1];
        blk[6] = board[x-1][y+2];
        blk[7] = board[x][y+2];
        blk[8] = board[x+1][y+2];
    } else if(x_blk2 == 0 && y_blk2 == 2) { // 2, 0
        blk[0] = board[x-2][y];
        blk[1] = board[x-1][y];
        blk[2] = board[x][y];
        blk[3] = board[x-2][y+1];
        blk[4] = board[x-2][y+1];
        blk[5] = board[x][y+1];
        blk[6] = board[x-2][y+2];
        blk[7] = board[x-1][y+2];
        blk[8] = board[x][y+2];
    } else if(x_blk2 == 1 && y_blk2 == 0) { // 0, 1
        blk[0] = board[x][y-1];
        blk[1] = board[x+1][y-1];
        blk[2] = board[x+2][y-1];
        blk[3] = board[x][y];
        blk[4] = board[x+1][y];
        blk[5] = board[x+2][y];
        blk[6] = board[x][y+1];
        blk[7] = board[x+1][y+1];
        blk[8] = board[x+2][y+1];
    } else if(x_blk2 == 1 && y_blk2 == 1) { // 1, 1
        blk[0] = board[x-1][y-1];
        blk[1] = board[x][y-1];
        blk[2] = board[x+1][y-1];
        blk[3] = board[x-1][y];
        blk[4] = board[x][y];
        blk[5] = board[x+1][y];
        blk[6] = board[x-1][y+1];
        blk[7] = board[x][y+1];
        blk[8] = board[x+1][y+1];
    } else if(x_blk2 == 1 && y_blk2 == 2) { // 2, 1
        blk[0] = board[x-2][y-1];
        blk[1] = board[x-1][y-1];
        blk[2] = board[x][y-1];
        blk[3] = board[x-2][y];
        blk[4] = board[x-2][y];
        blk[5] = board[x][y];
        blk[6] = board[x-2][y+1];
        blk[7] = board[x-1][y+1];
        blk[8] = board[x][y+1];
    } else if(x_blk2 == 2 && y_blk2 == 0) { // 0, 2
        blk[0] = board[x][y-2];
        blk[1] = board[x+1][y-2];
        blk[2] = board[x+2][y-2];
        blk[3] = board[x][y-1];
        blk[4] = board[x+1][y-1];
        blk[5] = board[x+2][y-1];
        blk[6] = board[x][y];
        blk[7] = board[x+1][y];
        blk[8] = board[x+2][y];
    } else if(x_blk2 == 2 && y_blk2 == 1) { // 1, 2
        blk[0] = board[x-1][y-2];
        blk[1] = board[x][y-2];
        blk[2] = board[x+1][y-2];
        blk[3] = board[x-1][y-1];
        blk[4] = board[x][y-1];
        blk[5] = board[x+1][y-1];
        blk[6] = board[x-1][y];
        blk[7] = board[x][y];
        blk[8] = board[x+1][y];
    } else if(x_blk2 == 2 && y_blk2 == 2) { // 2, 2
        blk[0] = board[x-2][y-2];
        blk[1] = board[x-1][y-2];
        blk[2] = board[x][y-2];
        blk[3] = board[x-2][y-1];
        blk[4] = board[x-2][y-1];
        blk[5] = board[x][y-1];
        blk[6] = board[x-2][y];
        blk[7] = board[x-1][y];
        blk[8] = board[x][y];
    }

    std::cout << " Coord: [" << x << ", " << y << "] ";
    std::cout << " Value [" << board[x][y] << "] ";
    std::cout << " Block: [ ";
    for(auto n : blk) {
        std::cout << n << " ";
    }
    std::cout << " ]\n";

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
    return isValidRow(x, y, value) && isValidColoumn(x, y, value) && isValidBlock(x, y, value);
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
bool Board::isValidBlock(int x, int y, int value) {
    auto blk = getBlock(x, y);
    for(int i = 0; i < 9; i++) {
        if(value == blk[i]) {
            return false;
        }
    }
    return true;
}
bool Board::isBoardFull() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == 0)
                return false;
        }
    }
    return true;
}
void Board::randomize(int b[9][9]) {
    // TODO: LOGIC STILL BROKEN
    /* create initial random number */
    time(0);
    int r = std::rand() % 9;
    int x, y;
    /* loop through each cell/square */
    for(int i = 0; i < 81; i++) {
        x = i % 9;
        y = i / 9;
        /* if current cell is empty */
        if(b[x][y] == 0) {
            int tmp = r;
            /* fill with random number until it is a valid number */
            for(int n = 1; n <= 9; n++) {
                /* is value valid */
                if(isValidPos(x, y, r)) {
                    b[x][y] = r;
                    break;
                }
                /* value is not valid */
                r = rand() % 9;
                for(int k = 0; k < 9; k++) {
                    if(r == tmp) {
                        break;
                    }
                    r = rand() % 9;
                }
            }
        }
    }
    std::cout << "\n";
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << b[i][j] << " ";
        }
    }
    std::cout << "\n";
    auto tmpblk = getBlock(0,0);
    for(int i = 0; i < tmpblk.size(); i++) {
        std::cout << tmpblk[i] << " ";
    }
    std::cout << "\n";
}
void Board::fillBoardWithInput(std::array<int, 9*9> values) {
    int x = 0, y = 0;
    for(int i = 0; i < 81; i++) {
        x = i % 9;
        y = i / 9;
        board[x][y] = values[i];
    }
}
void Board::removeCells() {
    time(0);
    int n = rand() % 10;
    int x = 0, y = 0;
    for(int i = 0; i < 81; i++) {
        x = i % 9;
        y = i / 9;

        if(n >= 5) {
            board[x][y] = 0;
        }

        n = rand() % 10;
    }
}




