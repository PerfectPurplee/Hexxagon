//
// Created by Drizzt on 27/12/2023.
//
#include "Menu.h"
#include "../main/gameboard/GameBoard.h"
#include "ranges"


Menu::Menu(sf::RenderWindow &window, sf::Font &font_) : pWindow(&window), font(&font_) {
    this->initMenuButtons();

    std::cout << listOfMenuButtons.size();
}

void Menu::eventHandler(sf::Event event) {
    static auto* hoveredButton = static_cast<std::pair<sf::RectangleShape, sf::Text>*>(nullptr);

    if (event.type == sf::Event::MouseMoved) {
        auto newHoveredButton  = std::ranges::find_if(listOfMenuButtons,[&](std::pair<sf::RectangleShape, sf::Text> &element) {
          return element.first.getGlobalBounds().contains(event.mouseMove.x,event.mouseMove.y);
        });

        if (hoveredButton != nullptr) {
            hoveredButton->second.setCharacterSize(60);
        }
        if (newHoveredButton != listOfMenuButtons.end()) {
            newHoveredButton->second.setCharacterSize(70);
            hoveredButton = &(*newHoveredButton);
        } else {
            // If no button is hovered, set hoveredButton to nullptr
            hoveredButton = nullptr;
        }
    }
}

void Menu::update() {

}

void Menu::draw() {
    std::ranges::for_each(listOfMenuButtons, [&](std::pair<sf::RectangleShape, sf::Text> &element) {
        pWindow->draw(element.first);
        pWindow->draw(element.second);
    });

}

void Menu::initMenuButtons() {

    createMenuButton(200, 150, std::string("Start new game"));
    createMenuButton(200, 250, std::string("Load game"));
    createMenuButton(200, 350, std::string("Scoreboard"));
    createMenuButton(200, 450, std::string("Quit"));

}

void Menu::createMenuButton(float x, float y, const std::string &text) {
    auto fontSize = 60;

    sf::RectangleShape buttonField(sf::Vector2f(300, 80));
    buttonField.setPosition(x, y);
    buttonField.setFillColor(sf::Color::Transparent);

    sf::Text buttonText(text, *font, fontSize);
    buttonText.setPosition(x, y);
    buttonText.setFillColor(sf::Color::White);


    listOfMenuButtons.emplace_back(buttonField, buttonText);

}




