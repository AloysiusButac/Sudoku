#include <iostream>
#include "Game/Resources.h"

int main() {

    std::array<int,81> values = {
        7, 9, 3, 8, 5, 2, 6, 1, 4,
        6, 4, 5, 1, 9, 3, 7, 2, 8,
        2, 8, 1, 7, 4, 6, 9, 3, 5,
        8, 5, 6, 2, 1, 9, 4, 7, 3,
        9, 3, 4, 6, 7, 5, 1, 8, 2,
        1, 7, 2, 3, 8, 4, 5, 9, 6,
        3, 6, 9, 4, 2, 1, 8, 5, 7,
        4, 1, 7, 5, 3, 8, 2, 6, 9,
        5, 2, 8, 9, 6, 7, 3, 4, 1,
    };

    SudokuGame game;
    game.Start(values);
    game.Run();

    std::cout << "Program Exit.";
    return 0;
}