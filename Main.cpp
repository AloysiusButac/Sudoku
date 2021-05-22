#include <cstdlib>
#include <iostream>

#include "Game/SudokuGame.hpp"

void change(int& n, int m) {
    n = m;
}

int main() {

    SudokuGame game;
    game.Start();
    game.Run();

    std::cout << "Program Exit.";

    return 0;
}