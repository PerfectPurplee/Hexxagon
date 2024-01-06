#pragma once

#include <SFML/Graphics.hpp>
#include "../main/gameboard/GameBoard.h"
#include "GameState.h"
#include "../main/enums.cpp"

class Menu : public GameState {

private:
    sf::Font *font;
    sf::RenderWindow *pWindow;
    GameStates *pCurrentGameState;
    std::vector<std::pair<sf::RectangleShape, sf::Text>> listOfMainMenuButtons;
    std::vector<std::pair<sf::RectangleShape, sf::Text>> listOfChooseGameModeMenuButtons;
    std::vector<std::pair<sf::RectangleShape ,sf::Text > *> listOfAllMenuButtons;

    MenuStates currentMenuState;


//    functions
    void initMainMenuButtons();

    void initChooseGameModeButtons();

    void createMenuButton(float x, float y, const std::string &buttonText, MenuStates menuState);

public:
    Menu(sf::RenderWindow &window, sf::Font &font_, GameStates &currentGameState);

    void eventHandler(sf::Event event) override;

    void update() override;

    void draw() override;


};



