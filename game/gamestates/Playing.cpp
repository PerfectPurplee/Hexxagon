//
// Created by Drizzt on 27/12/2023.
//

#include "Playing.h"
#include <SFML/Graphics.hpp>
#include "../main/gameboard/GameBoard.h"


Playing::Playing(sf::RenderWindow &window) {
    this->pWindow = &window;
}


void Playing::eventHandler(sf::Event event) {

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        handleMouseEventOnField(event);
    }

}

void Playing::update() {

}

void Playing::draw() {

//    DRAWING GAME BOARD FIELDS
    std::ranges::for_each(gameBoard.getListOfGameBoardFields(),
                          [&](auto &element) {
                              this->pWindow->draw(element.hexagonField);
                              if (element.hexagon != nullptr) {
                                  this->pWindow->draw(element.hexagon->hexagonVisual);
                              }
                          });

}

void Playing::handleMouseEventOnField(sf::Event event) {
    auto chosenField = std::ranges::find_if(gameBoard.getListOfGameBoardFields(), [&](auto &element) {
        return element.hexagonField.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
    });
    if (chosenField != gameBoard.getListOfGameBoardFields().end() && chosenField->hexagon != nullptr) {
        chosenField->hexagonField.setFillColor(sf::Color::White);
        checkPossibleMoves(*chosenField);
    }
}

void Playing::checkPossibleMoves(FieldOnTheGameBoard &chosenField) {

}



