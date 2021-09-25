#pragma once

#include <SFML/Graphics.hpp>

class Square {
public: 
    sf::Text text;
    sf::RectangleShape shape;
    sf::Vector2f position;
    bool is_selected = false;
    bool is_highlighted = false;
};

