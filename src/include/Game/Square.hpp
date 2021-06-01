#pragma once

#include <SFML/Graphics.hpp>

class Square {
public: 
    sf::Text text;
    sf::RectangleShape shape;
    sf::Vector2f position;
    bool is_selected = false;

    void MouseLeftClick();
    void MouseHover();
    void MouseEnter();
    void MouseExit();
    bool setSelect();
    bool isSelected();
    void setPosition(sf::Vector2f new_position);
    void getPosition();
};

