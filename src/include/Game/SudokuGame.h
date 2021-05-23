#pragma once

#include <array>
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Game/Board.hpp"
#include "Game/Square.hpp"

class SudokuGame {
public:
    // Sudoku Game default Constructor. (empty)
    SudokuGame();

    // Initializes an sf::RenderWindow that serves as the game window.
    void CreateGameWidow();
    // Clears game window.
    void ClearWindow();
    // Displays the game widow
    void DisplayWindow();
    // Initializes a Sudoku Game.
    // Creates a window and board.
    void Start();
    // Renders board and game window.
    void Render();
    // Runs the game.
    // Contains the game loop and game logic.
    void Run();
private:
    sf::RenderWindow game_window;
    Board board;
    std::array<Square, 9*9> board_squares;
};