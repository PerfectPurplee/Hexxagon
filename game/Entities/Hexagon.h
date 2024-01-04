#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Player;

class Hexagon {

private:
    Player *player;


public:
    sf::CircleShape hexagonVisual;

    Hexagon(float x, float y, Player *player_);

    const sf::CircleShape &getHexagonVisual() const;

    Player *getPlayer() const;
};



