#include "SudokuGame.h"

SudokuGame::SudokuGame() { }
void SudokuGame::CreateGameWidow() {
    this->game_window.create(sf::VideoMode(700,700),"Sudoku", sf::Style::Titlebar | sf::Style::Close);
}
void SudokuGame::ClearWindow() {
    this->game_window.clear(sf::Color(230, 255, 255));
}
void SudokuGame::DisplayWindow() {
    this->game_window.display();
}
void SudokuGame::Start() {
    CreateGameWidow();
}
void SudokuGame::Render() {
    // TODO: Insert here code adding game board visual components to the game window.
}
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
        Render();
        DisplayWindow();
    }
    std::cout << "game stopped..\n";
}

