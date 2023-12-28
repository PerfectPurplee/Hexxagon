//
// Created by Drizzt on 27/12/2023.
//

#ifndef HEXXAGON_MENU_H
#define HEXXAGON_MENU_H

#include <SFML/Graphics.hpp>


class Menu {

private:
    sf::RectangleShape rectangle;

public:
    void draw(sf::RenderWindow *pWindow);

    void update(sf::RenderWindow *pWindow);
};


#endif //HEXXAGON_MENU_H
