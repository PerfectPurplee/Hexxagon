#pragma once
#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual void eventHandler(sf::Event event) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};


