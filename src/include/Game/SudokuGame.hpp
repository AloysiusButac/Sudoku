#pragma once 

#include "SudokuGame.h"

// Sudoku Game default Constructor. (empty)
SudokuGame::SudokuGame() { }
// Initializes an sf::RenderWindow that serves as the game window.
void SudokuGame::CreateGameWidow() {
    this->game_window.create(sf::VideoMode(700,700),"Sudoku", sf::Style::Titlebar | sf::Style::Close);
}
// Initialize the game board.
void SudokuGame::CreateBoard() {
    for(int i = 0; i < this->game_board.size(); i++)
        game_board[i] = 1;
}
// Loads the board to the game window.
void SudokuGame::LoadBoard() {
    // TODO: Insert here code adding game board visual components to the game window.
}
// Clears game window.
void SudokuGame::ClearWindow() {
    this->game_window.clear();
}
// Displays the game widow
void SudokuGame::DisplayWindow() {
    this->game_window.display();
}
// Initializes a Sudoku Game.
// Creates a window and board.
void SudokuGame::Start() {
    CreateGameWidow();
    CreateBoard();
}
// Runs the game.
// Contains the game loop.
void SudokuGame::Run() {
    std::cout << "game running..\n";
    while(this->game_window.isOpen()) {
        sf::Event e;
        while (this->game_window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                game_window.close();
        }
        ClearWindow();
        LoadBoard();
        DisplayWindow();
    }
    std::cout << "game stopped..\n";
}

