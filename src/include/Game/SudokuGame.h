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
    // Create the squares to be diplayed on the board.
    void CreateSquares();
    // Clears game window.
    void ClearWindow();
    // Displays the game widow
    void DisplayWindow();
    // Initializes a Sudoku Game.
    // Creates a window and board.
    void Start();
    // Initializes a Sudoku Game.
    // Creates a window and board with inputted values.
    void Start(std::array<int, 9*9>);
    // Renders board and game window.
    void Render();
    // Updates the squares on the board
    void UpdateSquares();
    // Runs the game. Contains the game loop and game logic.
    void Run();
    // Takes in a vector position of an input.
    // Returns an index for the selected square relative to the current board.
    int getSquare(sf::Vector2i square_position);
    // Highlight   a square at a specific index.
    void highlightSquare(int index);
private:
    sf::RenderWindow game_window;
    Board board;
    std::array<Square, 9*9> board_squares;
    sf::Font default_font;
};