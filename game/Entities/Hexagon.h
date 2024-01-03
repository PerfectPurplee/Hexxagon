#pragma once

#include <SFML/Graphics.hpp>

class Hexagon {

private:



public:
    sf::CircleShape hexagonVisual;
    Hexagon(float x, float y);

    const sf::CircleShape &getHexagonVisual() const;
};



