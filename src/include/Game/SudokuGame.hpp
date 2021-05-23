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
    // this->board.NewGameBoard();
    this->board.randomize(this->board.board);
}
void SudokuGame::Render() {
    for(auto& r : board_squares) {
        this->game_window.draw(r.shape);
        this->game_window.draw(r.text);
    }
}
void SudokuGame::Run() {
    std::cout << "game running..\n";
    std::cout << "allocating squares..";
    int x = 0, y = 0;
    sf::Font font;
    if(!font.loadFromFile("src\\font\\OpenSans-Regular.ttf")) { }
    std::string num = "";
    int n = 0;
    for(int i = 0; i < board_squares.size(); i++) {
        x = i % 9;
        y = i / 9; 
        n =this->board.board[x][y];
        num = n > 0 ? std::to_string(n) : " ";
        sf::RectangleShape tmp(sf::Vector2f(65.0f,65.0f));
        board_squares[i].shape = tmp;
        board_squares[i].shape.setPosition(sf::Vector2f((x+1)*65.0f, (y+1)*65.0f));
        board_squares[i].shape.setOutlineColor(sf::Color::Black);
        board_squares[i].shape.setOutlineThickness(2.0f);
        board_squares[i].shape.setFillColor(sf::Color::White);
        board_squares[i].text.setFont(font);
        board_squares[i].text.setCharacterSize(30);
        board_squares[i].text.setFillColor(sf::Color::Black);
        board_squares[i].text.setString(num);
        board_squares[i].text.setPosition(sf::Vector2f((x+1)*65.0f + 22, (y+1)*65.0f+ 15));
    }
    std::cout << "\rallocating squares finished.\n";

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

