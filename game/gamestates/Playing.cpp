//
// Created by Drizzt on 27/12/2023.
//

#include "Playing.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Playing::Playing(sf::RenderWindow &window) : currentRoundPlayer(&player1) {
    this->pWindow = &window;
    this->setInitialPlayerHexagons();

}


void Playing::eventHandler(sf::Event event) {

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        handleMouseEventOnField(event);
    }

}

void Playing::update() {
    checkForGameOver();
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
//    PLAYER CHOSE HIS FIELD AND CHECKS POSSIBLE MOVES
    if (chosenField != gameBoard.getListOfGameBoardFields().end() && chosenField->hexagon != nullptr &&
        chosenField->hexagon->getPlayer() == currentRoundPlayer) {
        checkPossibleMoves(*chosenField);
    }
//    HANDLES PLAYER MOVE (chosenField in this case is a field player will make a move to)
    else if (chosenField != gameBoard.getListOfGameBoardFields().end() && pOriginFieldOfPlayerMove != nullptr) {
        handlePlayerMove(*chosenField);
    }

}

void Playing::checkPossibleMoves(FieldOnTheGameBoard &chosenField) {
    pOriginFieldOfPlayerMove = &chosenField;

    currentOneStepPossibleMoves.clear();
    currentTwoStepPossibleMoves.clear();

    std::ranges::for_each(gameBoard.getListOfGameBoardFields(), [](FieldOnTheGameBoard &element) {
        element.hexagonField.setOutlineColor(sf::Color(139, 34, 230));
    });

    for (auto &field: gameBoard.getListOfGameBoardFields()) {
        auto it = std::ranges::find_if(
                gameBoard.directionsOneStep,
                [&](const HexCoordinates &direction) {
                    return (
                            field.hexCoordinates->q == chosenField.hexCoordinates->q + direction.q &&
                            field.hexCoordinates->r == chosenField.hexCoordinates->r + direction.r &&
                            field.hexCoordinates->s == chosenField.hexCoordinates->s + direction.s &&
                            field.hexagon == nullptr);
                });

        auto it2 = std::ranges::find_if(
                gameBoard.directionsTwoSteps,
                [&](const HexCoordinates &direction) {
                    return (
                            field.hexCoordinates->q == chosenField.hexCoordinates->q + direction.q &&
                            field.hexCoordinates->r == chosenField.hexCoordinates->r + direction.r &&
                            field.hexCoordinates->s == chosenField.hexCoordinates->s + direction.s &&
                            field.hexagon == nullptr);
                });

        if (it != gameBoard.directionsOneStep.end()) {
            currentOneStepPossibleMoves.push_back(&field);
            field.hexagonField.setOutlineColor(sf::Color::Green);
        } else if (it2 != gameBoard.directionsTwoSteps.end()) {
            currentTwoStepPossibleMoves.push_back(&field);
            field.hexagonField.setOutlineColor(sf::Color::Yellow);
        }
    }
}

void Playing::handlePlayerMove(FieldOnTheGameBoard &chosenField) {
    auto it1 = std::ranges::find(currentOneStepPossibleMoves, &chosenField);
    auto it2 = std::ranges::find(currentTwoStepPossibleMoves, &chosenField);

//    Handles player move to neighbour fields
    if (it1 != currentOneStepPossibleMoves.end()) {
        chosenField.hexagon = new Hexagon(chosenField.hexagonField.getPosition().x + 45,
                                          chosenField.hexagonField.getPosition().y + 45,
                                          currentRoundPlayer);
        pOriginFieldOfPlayerMove = nullptr;

        std::ranges::for_each(gameBoard.getListOfGameBoardFields(), [](FieldOnTheGameBoard &element) {
            element.hexagonField.setOutlineColor(sf::Color(139, 34, 230));
        });
//        TAKE OVER NEIGHOBR ENEMY FIELDS
        takeOverNeighborEnemyPlayerFields(chosenField);

//        ENDS PLAYER ROUND AND START ROUND FOR OTHER PLAYER
        currentRoundPlayer == &player1 ? currentRoundPlayer = &player2 : currentRoundPlayer = &player1;

//        Handles player move to neighbour + 1 fields
    } else if (it2 != currentTwoStepPossibleMoves.end()) {
//        Removes a pointer to hexagon from player list for score purposes
        pOriginFieldOfPlayerMove->hexagon->getPlayer()->getSetOfPlayerHexagons().erase(
                pOriginFieldOfPlayerMove->hexagon);
        pOriginFieldOfPlayerMove->hexagon = nullptr;

        chosenField.hexagon = new Hexagon(chosenField.hexagonField.getPosition().x + 45,
                                          chosenField.hexagonField.getPosition().y + 45,
                                          currentRoundPlayer);
        pOriginFieldOfPlayerMove = nullptr;

        std::ranges::for_each(gameBoard.getListOfGameBoardFields(), [](FieldOnTheGameBoard &element) {
            element.hexagonField.setOutlineColor(sf::Color(139, 34, 230));
        });

        takeOverNeighborEnemyPlayerFields(chosenField);
//        ENDS PLAYER ROUND AND START ROUND FOR OTHER PLAYER
        currentRoundPlayer == &player1 ? currentRoundPlayer = &player2 : currentRoundPlayer = &player1;
    }

}

void Playing::takeOverNeighborEnemyPlayerFields(FieldOnTheGameBoard &fieldToCheckForEnemyNeighbors) {
    auto listOfFieldsToTakeOver = std::vector<FieldOnTheGameBoard *>();

    for (auto &field: gameBoard.getListOfGameBoardFields()) {
        auto it = std::ranges::find_if(
                gameBoard.directionsOneStep,
                [&](const HexCoordinates &direction) {
                    return (
                            field.hexCoordinates->q == fieldToCheckForEnemyNeighbors.hexCoordinates->q + direction.q &&
                            field.hexCoordinates->r == fieldToCheckForEnemyNeighbors.hexCoordinates->r + direction.r &&
                            field.hexCoordinates->s == fieldToCheckForEnemyNeighbors.hexCoordinates->s + direction.s &&
                            field.hexagon != nullptr && field.hexagon->getPlayer() != currentRoundPlayer);
                });
        if (it != gameBoard.directionsOneStep.end()) {
            listOfFieldsToTakeOver.push_back(&field);
        }
    }
    for (auto &element: listOfFieldsToTakeOver) {
//        Erase hexagon pointer element from one player list, change player owning hexagon and add hexagon to his list
        element->hexagon->getPlayer()->getSetOfPlayerHexagons().erase(element->hexagon);
        element->hexagon->setPlayer(currentRoundPlayer);
        element->hexagon->getPlayer()->getSetOfPlayerHexagons().insert(element->hexagon);
//        Swaps Hexagon color
        element->hexagon->hexagonVisual.getFillColor() == sf::Color::Red ?
        element->hexagon->hexagonVisual.setFillColor(sf::Color::Blue) :
        element->hexagon->hexagonVisual.setFillColor(sf::Color::Red);

    }

}

void Playing::checkForGameOver() {
    if (player1.getSetOfPlayerHexagons().size() + player2.getSetOfPlayerHexagons().size() >= 61 ||
        (player1.getSetOfPlayerHexagons().empty() || player2.getSetOfPlayerHexagons().empty())) {
//        std::cout << "GAME OVER ";
    }
}

void Playing::setInitialPlayerHexagons() {
    gameBoard.getListOfGameBoardFields()[4].hexagon = new Hexagon(
            gameBoard.getListOfGameBoardFields()[4].hexagonField.getPosition().x + 45,
            gameBoard.getListOfGameBoardFields()[4].hexagonField.getPosition().y + 45,
            &player1);
    gameBoard.getListOfGameBoardFields()[26].hexagon = new Hexagon(
            gameBoard.getListOfGameBoardFields()[26].hexagonField.getPosition().x + 45,
            gameBoard.getListOfGameBoardFields()[26].hexagonField.getPosition().y + 45,
            &player1);
    gameBoard.getListOfGameBoardFields()[60].hexagon = new Hexagon(
            gameBoard.getListOfGameBoardFields()[60].hexagonField.getPosition().x + 45,
            gameBoard.getListOfGameBoardFields()[60].hexagonField.getPosition().y + 45, &player1);

    gameBoard.getListOfGameBoardFields()[0].hexagon = new Hexagon(
            gameBoard.getListOfGameBoardFields()[0].hexagonField.getPosition().x + 45,
            gameBoard.getListOfGameBoardFields()[0].hexagonField.getPosition().y + 45,
            &player2);
    gameBoard.getListOfGameBoardFields()[34].hexagon = new Hexagon(
            gameBoard.getListOfGameBoardFields()[34].hexagonField.getPosition().x + 45,
            gameBoard.getListOfGameBoardFields()[34].hexagonField.getPosition().y + 45,
            &player2);
    gameBoard.getListOfGameBoardFields()[56].hexagon = new Hexagon(
            gameBoard.getListOfGameBoardFields()[56].hexagonField.getPosition().x + 45,
            gameBoard.getListOfGameBoardFields()[56].hexagonField.getPosition().y + 45, &player2);

}







