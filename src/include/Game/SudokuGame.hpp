#include "SudokuGame.h"

SudokuGame::SudokuGame() { }
void SudokuGame::CreateGameWidow() {
    this->game_window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Sudoku", sf::Style::Titlebar | sf::Style::Close);
    this->game_window.setFramerateLimit(30);
}
void SudokuGame::CreateSquares() {
    int x = 0, y = 0, n = 0;
    std::string num;
    for(int i = 0; i < board_squares.size(); i++) {
        x = i % 9;
        y = i / 9; 
        n = this->board.board[x][y];
        sf::Color sq_color = sf::Color::White;
        num = n > 0 ? std::to_string(n) : " ";
        // SHAPES
        sf::RectangleShape tmp(sf::Vector2f(SQUARE_SIDE_LENGTH,SQUARE_SIDE_LENGTH));
        board_squares[i].shape = tmp;
        board_squares[i].shape.setPosition(sf::Vector2f((x+1)*SQUARE_SIDE_LENGTH, (y+1)*SQUARE_SIDE_LENGTH));
        board_squares[i].shape.setOutlineColor(sf::Color::Black);
        board_squares[i].shape.setOutlineThickness(2.0f);
        board_squares[i].shape.setFillColor(sq_color);
        // TEXTS
        board_squares[i].text.setFont(default_font);
        board_squares[i].text.setCharacterSize(30);
        board_squares[i].text.setFillColor(sf::Color::Black);
        board_squares[i].text.setString(num);
        board_squares[i].text.setPosition(sf::Vector2f((x+1)*SQUARE_SIDE_LENGTH + 22, (y+1)*SQUARE_SIDE_LENGTH+ 15));
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
void SudokuGame::Start(std::array<int, 9*9>& values) {
    CreateGameWidow();
    board.fillBoardWithInput(values);
    board.removeCells();
}
void SudokuGame::Render() {
    for(auto& r : board_squares) {
        this->game_window.draw(r.shape);
        this->game_window.draw(r.text);
    }
}
void SudokuGame::UpdateSquares() {
    sf::Color sq_color;
    std::string num;
    for(int i = 0;i < board_squares.size(); i++)  {
        if(board_squares[i].is_selected)
            sq_color = sf::Color(184, 245, 203);
        else if(board_squares[i].is_highlighted)
            sq_color = sf::Color(204, 255, 230);
        else
            sq_color = sf::Color::White;
            
        board_squares[i].shape.setFillColor(sq_color);
        num = board.board[i%9][i/9] > 0 ? std::to_string(board.board[i%9][i/9]) : " ";
        board_squares[i].text.setString(num);
    }
}
void SudokuGame::Run() {
    std::cout << "game running..\n";
    std::cout << "creating squares..";
    /* Reading font */
    if(!default_font.loadFromFile("src\\font\\OpenSans-Regular.ttf")) { }
    CreateSquares();
    std::cout << "\rcreating squares finished.\n";

    /* DEBUG STUFF */
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
                        board.inputValue(selected_index % 9, selected_index / 9, 1);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) 
                        board.inputValue(selected_index % 9, selected_index / 9, 2);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) 
                        board.inputValue(selected_index % 9, selected_index / 9, 3);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) 
                        board.inputValue(selected_index % 9, selected_index / 9, 4);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) 
                        board.inputValue(selected_index % 9, selected_index / 9, 5);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) 
                        board.inputValue(selected_index % 9, selected_index / 9, 6);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) 
                        board.inputValue(selected_index % 9, selected_index / 9, 7);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) 
                        board.inputValue(selected_index % 9, selected_index / 9, 8);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) 
                        board.inputValue(selected_index % 9, selected_index / 9, 9);
                }
                UpdateSquares();
            }
            if(e.type == sf::Event::MouseButtonPressed) {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    try {
                        highlightSquare(getSquare(sf::Mouse::getPosition(game_window)));
                    } 
                    catch (int n) { 
                        std::cout << n << std::endl;
                    }
                }
                UpdateSquares();
            }

            /* DEBUG STUFF */
            if(e.type == sf::Event::MouseMoved) {
                debug_text.setString("Square: " + std::to_string(getSquare(sf::Mouse::getPosition(game_window)))
                                    + "\n[" + std::to_string(sf::Mouse::getPosition(game_window).x) 
                                    + ", " + std::to_string(sf::Mouse::getPosition(game_window).y) + "]");
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
    float board_side_l = SQUARE_SIDE_LENGTH * 9;
    int sq_row = (square_position.y / SQUARE_SIDE_LENGTH) > 10 ? -1 : (square_position.y / SQUARE_SIDE_LENGTH);
    int sq_col = (square_position.x / SQUARE_SIDE_LENGTH) > 10 ? -1 : (square_position.x / SQUARE_SIDE_LENGTH);
    int output = (sq_row-1) * 9 + sq_col;
    bool sq_lw_restrictions = sq_row < 1 || sq_row > 9 || sq_col < 1 || sq_col > 9;
    return output < 0 || output > 81 || sq_lw_restrictions ? -1 : output-1;
}
void SudokuGame::highlightSquare(int index) {
    clearHighlights(index);
    if(index == selected_index || index == -1) {
        board_squares[index].is_selected = false;
        selected_index = -1;
        // std::cout << "same square clicked.\n";
    } else {
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
        if(i / 9 == row) // HIGHLIGHT ROW SQUARES
            board_squares[i].is_highlighted = board_squares[index].is_selected;
        if(i % 9 == col) // HIGHLIGHT COLUMN SQUARES
            board_squares[i].is_highlighted = board_squares[index].is_selected;
        if(i % 9 / 3 == blk_2 && i / 9 / 3 == blk_1) // HIGHLIGHT BLOCK SQUARES
            board_squares[i].is_highlighted = board_squares[index].is_selected;
    }
    std::cout << "selected index: " << selected_index << std::endl;
}
void SudokuGame::clearHighlights(int index) {
    for(int i = 0; i < board_squares.size(); i++) {
        if(i == index)
            continue;
        board_squares[i].is_selected = false;
        board_squares[i].is_highlighted = false;
    }
}