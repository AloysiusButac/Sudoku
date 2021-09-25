#pragma once

#include "Resources.h"

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
    void fillBoardWithInput(std::array<int, 9*9>& values);
    // Remove values of cell randomly
    void removeCells();
    // Valicates if the input is correct.
    bool checkInput(int x, int y, int value);
    // Inputs a value at (x,y) if valid.
    void inputValue(int x, int y, int value);
public:
    int board [9][9];
};