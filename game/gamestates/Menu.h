#pragma once

#include <SFML/Graphics.hpp>
#include "../main/gameboard/GameBoard.h"
#include "GameState.h"


class Menu : public GameState {

private:
    sf::RectangleShape rectangle;
    sf::RenderWindow* pWindow;


public:
    explicit Menu(sf::RenderWindow& window);

    void eventHandler(sf::Event event) override;

    void update() override;

    void draw() override;


};



