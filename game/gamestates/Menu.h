#pragma once

#include <SFML/Graphics.hpp>
#include "../main/gameboard/GameBoard.h"
#include "GameState.h"


class Menu : public GameState {

private:
    sf::Font *font;
    sf::RenderWindow *pWindow;
    std::vector<std::pair<sf::RectangleShape, sf::Text>> listOfMenuButtons;



//    functions
    void initMenuButtons();

    void createMenuButton(float x, float y, const std::string& buttonText);

public:
    Menu(sf::RenderWindow &window, sf::Font &font_);

    void eventHandler(sf::Event event) override;

    void update() override;

    void draw() override;


};



