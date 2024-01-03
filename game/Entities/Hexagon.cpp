//
// Created by Drizzt on 27/12/2023.
//

#include "Hexagon.h"

Hexagon::Hexagon(float x, float y) {
    hexagonVisual.setRadius(20);
    hexagonVisual.setOutlineColor(sf::Color::Red);
    hexagonVisual.setOutlineThickness(2);
    hexagonVisual.setFillColor(sf::Color::Blue);
    hexagonVisual.setPosition(x - hexagonVisual.getRadius(), y - hexagonVisual.getRadius());
}

const sf::CircleShape &Hexagon::getHexagonVisual() const {
    return hexagonVisual;
}
