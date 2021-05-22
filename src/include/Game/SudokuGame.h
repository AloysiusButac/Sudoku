#pragma once

#include <array>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "SudokuGame.hpp"

class SudokuGame {
public:
    SudokuGame();

    void CreateGameWidow();
    void CreateBoard();
    void LoadBoard();
    void ClearWindow();
    void DisplayWindow();
    void Start();
    void Run();
private:
    sf::RenderWindow game_window;
    std::array<int, 9*9> game_board;
};