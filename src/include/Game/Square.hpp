#pragma once

#include <SFML/Graphics.hpp>

class Square {
public: 
    sf::Text text;
    sf::RectangleShape shape;
    sf::Vector2f position;
    bool is_selected = false;
    bool is_highlighted = false;

    void MouseLeftClick();
    void MouseHover();
    void MouseEnter();
    void MouseExit();
    void setSelect(bool select);
    bool isSelected();
    void setHighlighted(bool highlight);
    bool isHighlighted();
    void setPosition(sf::Vector2f new_position);
    void getPosition();
};

