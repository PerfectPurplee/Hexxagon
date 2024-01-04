//
// Created by Drizzt on 27/12/2023.
//

#include "Hexagon.h"

Hexagon::Hexagon(float x, float y, Player *player_) : player(player_) {
    hexagonVisual.setRadius(20);
    player->getId() == 1 ? hexagonVisual.setFillColor(sf::Color::Blue) : hexagonVisual.setFillColor(sf::Color::Red);
    hexagonVisual.setOutlineThickness(2);
    hexagonVisual.setPosition(x - hexagonVisual.getRadius(), y - hexagonVisual.getRadius());
}

const sf::CircleShape &Hexagon::getHexagonVisual() const {
    return hexagonVisual;
}

Player *Hexagon::getPlayer() const {
    return player;
}
