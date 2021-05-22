#pragma once

#include <array>
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Game/Cells.hpp"

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
    // Loads the board to the game window.
    void Render();
    // Runs the game.
    // Contains the game loop.
    void Run();
private:
    sf::RenderWindow game_window;
    Cells board;
};