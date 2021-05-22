#include <cstdlib>
#include <iostream>

#include "Game/SudokuGame.hpp"

int main() {

    SudokuGame game;
    game.Start();
    game.Run();

    std::cout << "Program Exit.";

    return 0;
}