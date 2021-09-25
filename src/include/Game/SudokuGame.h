#pragma once

#include "Resources.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define SQUARE_SIDE_LENGTH 65.0f

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
    void Start(std::array<int, 9*9>& values);
    // Renders board and game window.
    void Render();
    // Updates each squares' visual appearance.
    void UpdateSquares();
    // Runs the game. Contains the game loop and game logic.
    void Run();
    // Takes in a vector position of a mouse input.
    // Returns an index for the selected square relative to the current board.
    int getSquare(sf::Vector2i square_position);
    // Highlight   a square at a specific index.
    void highlightSquare(int index);
    // Clears all the highlights; Make all squares to the default color.
    void clearHighlights(int index);
private:
    int selected_index = -1;
    sf::RenderWindow game_window;
    Board board;
    std::array<Square, 81> board_squares;
    sf::Font default_font;
    
    /*    DEBUG STUFF    */
    sf::Text debug_text;
};