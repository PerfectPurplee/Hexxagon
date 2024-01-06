//
// Created by Drizzt on 27/12/2023.
//
#include "Menu.h"
#include "../main/gameboard/GameBoard.h"
#include "ranges"


Menu::Menu(sf::RenderWindow &window, sf::Font &font_, GameStates &currentGameState) : pWindow(&window), font(&font_),
                                                                                      pCurrentGameState(
                                                                                              &currentGameState) {
    this->currentMenuState = MenuStates::MAIN_MENU;
    this->initMainMenuButtons();
    this->initChooseGameModeButtons();
    for (std::pair<sf::RectangleShape, sf::Text> &button: listOfMainMenuButtons) {
        listOfAllMenuButtons.push_back(&button);
    }
    for (auto &button: listOfChooseGameModeMenuButtons) {
        listOfAllMenuButtons.push_back(&button);
    }

}

void Menu::eventHandler(sf::Event event) {
    static auto *hoveredButton = static_cast<std::pair<sf::RectangleShape, sf::Text> *>(nullptr);

    if (event.type == sf::Event::MouseMoved) {
        auto newHoveredButton = std::ranges::find_if(listOfAllMenuButtons,
                                                     [&](std::pair<sf::RectangleShape, sf::Text> *element) {
                                                         return element->first.getGlobalBounds().contains(
                                                                 event.mouseMove.x, event.mouseMove.y);
                                                     });

        if (hoveredButton != nullptr) {
            hoveredButton->second.setCharacterSize(60);
        }
        if (newHoveredButton != listOfAllMenuButtons.end()) {
            (*newHoveredButton)->second.setCharacterSize(70);
            hoveredButton = &(**newHoveredButton);
        } else {
            // If no button is hovered, set hoveredButton to nullptr
            hoveredButton = nullptr;
        }
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        auto pressedButton = std::ranges::find_if(listOfAllMenuButtons,
                                                  [&](std::pair<sf::RectangleShape, sf::Text> *element) {
                                                      return (element->first.getGlobalBounds().contains(
                                                              event.mouseButton.x, event.mouseButton.y));
                                                  });
        if (pressedButton != listOfAllMenuButtons.end()) {
            switch (currentMenuState) {

                case MAIN_MENU: {
                    if ((*pressedButton)->second.getString() == "Start new game") {
                        currentMenuState = MenuStates::CHOOSING_GAME_MODE;
                    }
                }
                    break;
                case CHOOSING_GAME_MODE: {
                    if ((*pressedButton)->second.getString() == "Player vs Player") {
                        *pCurrentGameState = GameStates::PLAYING;
                    }
                }
                    break;
                case LOADING_SAVE:
                    break;
            }


        }
    }
}

void Menu::update() {

}

void Menu::draw() {
    switch (currentMenuState) {

        case MAIN_MENU:
            std::ranges::for_each(listOfMainMenuButtons, [&](std::pair<sf::RectangleShape, sf::Text> &element) {
                pWindow->draw(element.first);
                pWindow->draw(element.second);
            });
            break;
        case CHOOSING_GAME_MODE:
            std::ranges::for_each(listOfChooseGameModeMenuButtons,
                                  [&](std::pair<sf::RectangleShape, sf::Text> &element) {
                                      pWindow->draw(element.first);
                                      pWindow->draw(element.second);
                                  });
            break;
        case LOADING_SAVE:
            break;
    }


}

void Menu::initMainMenuButtons() {

    createMenuButton(200, 150, std::string("Start new game"), MenuStates::MAIN_MENU);
    createMenuButton(200, 250, std::string("Load game"), MenuStates::MAIN_MENU);
    createMenuButton(200, 350, std::string("Scoreboard"), MenuStates::MAIN_MENU);
    createMenuButton(200, 450, std::string("Quit"), MenuStates::MAIN_MENU);

}

void Menu::initChooseGameModeButtons() {
    createMenuButton(350, 250, std::string("Player vs Player"), MenuStates::CHOOSING_GAME_MODE);
    createMenuButton(350, 350, std::string("Player vs Computer"), MenuStates::CHOOSING_GAME_MODE);

}

void Menu::createMenuButton(float x, float y, const std::string &text, MenuStates menuState) {
    auto fontSize = 60;

    sf::RectangleShape buttonField(sf::Vector2f(300, 80));
    buttonField.setPosition(x, y);
    buttonField.setFillColor(sf::Color::Transparent);

    sf::Text buttonText(text, *font, fontSize);
    buttonText.setPosition(x, y);
    buttonText.setFillColor(sf::Color::White);

    if (menuState == MenuStates::MAIN_MENU)
        listOfMainMenuButtons.emplace_back(buttonField, buttonText);
    else if (menuState == MenuStates::CHOOSING_GAME_MODE)
        listOfChooseGameModeMenuButtons.emplace_back(buttonField, buttonText);

}






