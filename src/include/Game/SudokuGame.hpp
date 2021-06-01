#include "SudokuGame.h"

SudokuGame::SudokuGame() { }
void SudokuGame::CreateGameWidow() {
    this->game_window.create(sf::VideoMode(700,700),"Sudoku", sf::Style::Titlebar | sf::Style::Close);
}
void SudokuGame::CreateSquares() {
    int x = 0, y = 0, n = 0;
    std::string num = "";
    for(int i = 0; i < board_squares.size(); i++) {
        x = i % 9;
        y = i / 9; 
        n = this->board.board[x][y];
        sf::Color sq_color = sf::Color::White;
        num = n > 0 ? std::to_string(n) : " ";
        sf::RectangleShape tmp(sf::Vector2f(65.0f,65.0f));
        board_squares[i].shape = tmp;
        board_squares[i].shape.setPosition(sf::Vector2f((x+1)*65.0f, (y+1)*65.0f));
        board_squares[i].shape.setOutlineColor(sf::Color::Black);
        board_squares[i].shape.setOutlineThickness(2.0f);
        board_squares[i].shape.setFillColor(sq_color);
        board_squares[i].text.setFont(default_font);
        board_squares[i].text.setCharacterSize(30);
        board_squares[i].text.setFillColor(sf::Color::Black);
        board_squares[i].text.setString(num);
        board_squares[i].text.setPosition(sf::Vector2f((x+1)*65.0f + 22, (y+1)*65.0f+ 15));
    }
}
void SudokuGame::ClearWindow() {
    this->game_window.clear(sf::Color(230, 255, 255));
}
void SudokuGame::DisplayWindow() {
    this->game_window.display();
}
void SudokuGame::Start() {
    CreateGameWidow();
    this->board.randomize(this->board.board);
}
void SudokuGame::Start(std::array<int, 9*9> values) {
    CreateGameWidow();
    board.fillBoardWithInput(values);
    board.removeCells();
}
void SudokuGame::Render() {
    for(auto r : board_squares) {
        this->game_window.draw(r.shape);
        this->game_window.draw(r.text);
    }
}
void SudokuGame::UpdateSquares() {
    for(int i = 0;i < board_squares.size(); i++)  {
        sf::Color sq_color = board_squares[i].is_selected ? sf::Color(113, 201, 81) : sf::Color::White;
        board_squares[i].shape.setFillColor(sq_color);
    }
    printf("%s -> [%d] ", "Squares updated.", board_squares[0].shape.getFillColor().toInteger());
}
void SudokuGame::Run() {
    std::cout << "game running..\n";
    std::cout << "allocating squares..";
    /* Reading font */
    if(!default_font.loadFromFile("src\\font\\OpenSans-Regular.ttf")) { }
    /* Setting up the squares */ 
    CreateSquares();
    std::cout << "\rallocating squares finished.\n";

    // GAME LOOP
    while(this->game_window.isOpen()) {
        sf::Event e;
        while (this->game_window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed) {
                game_window.close();
            }
            if(e.type == sf::Event::KeyPressed) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                    board_squares[0].is_selected = !board_squares[0].is_selected;
                }
                UpdateSquares();
            }
        }
        ClearWindow();
        Render();
        DisplayWindow();
    }
    std::cout << "game stopped..\n";
}
int SudokuGame::getSquare(sf::Vector2f square_position) {
    auto tmp1 = square_position.x / 65;
    auto tmp2 = square_position.y / 65;

    auto tmp3 = (tmp2 * 9) + tmp1;

    return tmp3;
}
