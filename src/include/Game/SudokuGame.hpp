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
    sf::Color sq_color;
    for(int i = 0;i < board_squares.size(); i++)  {
        if(board_squares[i].is_selected)
            sq_color = sf::Color(184, 245, 203);
        else if(board_squares[i].is_highlighted)
            sq_color = sf::Color(204, 255, 230);
        else
            sq_color = sf::Color::White;
            
        board_squares[i].shape.setFillColor(sq_color);
    }
}
void SudokuGame::Run() {
    std::cout << "game running..\n";
    std::cout << "allocating squares..";
    /* Reading font */
    if(!default_font.loadFromFile("src\\font\\OpenSans-Regular.ttf")) { }
    /* Setting up the squares */ 
    CreateSquares();
    std::cout << "\rallocating squares finished.\n";
    /* DEBUG STUFF */
    sf::Text debug_text;
    debug_text.setFont(default_font);
    debug_text.setCharacterSize(12);
    debug_text.setFillColor(sf::Color::Black);
    debug_text.setPosition(sf::Vector2f(10,10));
    /* DEBUG STUFF END*/

    // GAME LOOP
    while(this->game_window.isOpen()) {
        sf::Event e;
        while (this->game_window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed) {
                game_window.close();
            }
            if(e.type == sf::Event::KeyPressed) {
                if(selected_index >= 0) {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) 
                        board_squares[selected_index].text.setString("1");
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) 
                        board_squares[selected_index].text.setString("2");
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) 
                        board_squares[selected_index].text.setString("3");
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) 
                        board_squares[selected_index].text.setString("4");
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) 
                        board_squares[selected_index].text.setString("5");
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) 
                        board_squares[selected_index].text.setString("6");
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) 
                        board_squares[selected_index].text.setString("7");
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) 
                        board_squares[selected_index].text.setString("8");
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) 
                        board_squares[selected_index].text.setString("9");
                }
                UpdateSquares();
            }
            if(e.type == sf::Event::MouseButtonPressed) {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    try {
                        highlightSquare(getSquare(sf::Mouse::getPosition()));
                    } 
                    catch (int n) { 
                        std::cout << n << std::endl;
                    }
                }
                UpdateSquares();
            }

            /* DEBUG STUFF */
            if(e.type == sf::Event::MouseMoved) {
                debug_text.setString("Square: " + std::to_string(getSquare(sf::Mouse::getPosition())));
            }
            /* DEBUG STUFF END*/
        }
        ClearWindow();
        Render();

        /* DEBUG STUFF */
        this->game_window.draw(debug_text);
        /* DEBUG STUFF END*/

        DisplayWindow();
    }
    std::cout << "game stopped..\n";
}
int SudokuGame::getSquare(sf::Vector2i square_position) {
    sf::Vector2i mouse_pos = square_position - sf::Vector2i(115, 115);

    auto tmp1 = ((mouse_pos.x-42) / 65)-8;
    auto tmp2 = ((mouse_pos.y-42) / 65)-2;

    return (tmp2 * 9) + tmp1;
}
void SudokuGame::highlightSquare(int index) {
    clearHighlights(index);
    if(index == selected_index) {
        board_squares[index].is_selected = false;
        selected_index = -1;
        std::cout << "same square clicked.\n";
    } else 
    {
        board_squares[index].is_selected = true;
        selected_index = index;
    }

    int row = index / 9;
    int col = index % 9;
    int blk_1 = row / 3;
    int blk_2 = col / 3;

    for(int i = 0; i < board_squares.size(); i++) {
        if(i == index)
            continue;
        if(i / 9 == row) 
            board_squares[i].is_highlighted = board_squares[index].is_selected;
        if(i % 9 == col) 
            board_squares[i].is_highlighted = board_squares[index].is_selected;
        if(i % 9 / 3 == blk_2 && i / 9 / 3 == blk_1) 
            board_squares[i].is_highlighted = board_squares[index].is_selected;
    }
}
void SudokuGame::clearHighlights(int index) {
    for(int i = 0; i < board_squares.size(); i++) {
        if(i == index)
            continue;
        board_squares[i].is_selected = false;
        board_squares[i].is_highlighted = false;
    }
}