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


// Getters and Setters
    void setPlayer(Player *player);

    Player *getPlayer() const;

    const sf::CircleShape &getHexagonVisual() const;
};



