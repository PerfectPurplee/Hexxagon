
#include <iostream>
#include "GameBoard.h"
#include "ranges"
#include "cmath"




//Constructors and Deconstructors
GameBoard::GameBoard() {

    this->listOfGameBoardFields = std::vector<FieldOnTheGameBoard>();
    this->initGameBoardFieldsBETTER();
//    this->initGameBoardFields();
    this->setDrawingRepresentationForFields();
//    this->setInitialPlayerHexagons();
//    std::cout << listOfGameBoardFields.size();
}

void GameBoard::initGameBoardFields() {
    auto allColumns = 9.f;
    auto currentColumnRows = 5;

    auto hexWidth = 40.0f;
    auto hexHeight = std::sqrt(3.0f) * hexWidth / 2.0f;
    auto initialPositionX = (1280 / 2) - (allColumns - 1) * (hexWidth);
    auto initialPositionY = 720 - allColumns * (hexHeight - 5);

    for (auto i = 0; i < allColumns; i++) {
        for (auto j = 0; j < currentColumnRows; j++) {
            auto gameField = FieldOnTheGameBoard(i, j);

            // First column, first row
            if (i == 0 && j == 0) {
                gameField.hexagonField.setPosition(initialPositionX, initialPositionY);
            }
                // First row in every column excluding the first
//                Offset Grid Upwards
            else if ((i <= 4 && j == 0 && i % 2 == 1) || (i > 4 && j == 0 && i % 2 == 0)) {
                gameField.hexagonField.setPosition(
                        (listOfGameBoardFields.back().hexagonField.getPosition().x + hexWidth / 2 +
                         (0.75f * 1.5f * hexWidth)),
                        listOfGameBoardFields.back().hexagonField.getPosition().y - hexHeight);
//                Offset Downwards
            } else if ((i <= 4 && j == 0 && i % 2 == 0) || (i > 4 && j == 0 && i % 2 == 1)) {
                gameField.hexagonField.setPosition(
                        (listOfGameBoardFields.back().hexagonField.getPosition().x + hexWidth / 2 +
                         (0.75f * 1.5f * hexWidth)),
                        listOfGameBoardFields.back().hexagonField.getPosition().y + hexHeight);
            }
                // For even columns
            else if (i % 2 == 0) {
                gameField.hexagonField.setPosition(
                        listOfGameBoardFields.back().hexagonField.getPosition().x,
                        listOfGameBoardFields.back().hexagonField.getPosition().y - hexHeight * 2);
            }
                // For odd columns
            else if (i % 2 == 1) {
                gameField.hexagonField.setPosition(
                        listOfGameBoardFields.back().hexagonField.getPosition().x,
                        listOfGameBoardFields.back().hexagonField.getPosition().y + hexHeight * 2);
            }

            this->listOfGameBoardFields.push_back(gameField);
        }

        i < 4 ? currentColumnRows++ : currentColumnRows--;
    }
}

void GameBoard::setInitialPlayerHexagons() {
//    listOfGameBoardFields[4].hexagon = new Hexagon(listOfGameBoardFields[4].hexagonField.getPosition().x + 45,
//                                                   listOfGameBoardFields[4].hexagonField.getPosition().y + 45,
//                                                   );
//    listOfGameBoardFields[26].hexagon = new Hexagon(listOfGameBoardFields[26].hexagonField.getPosition().x + 45,
//                                                    listOfGameBoardFields[26].hexagonField.getPosition().y + 45);
//    listOfGameBoardFields[60].hexagon = new Hexagon(listOfGameBoardFields[60].hexagonField.getPosition().x + 45,
//                                                    listOfGameBoardFields[60].hexagonField.getPosition().y + 45);

}


void GameBoard::initGameBoardFieldsBETTER() {
    auto const N = 4;

    for (int q = -N; q <= N; q++) {
        int r1 = std::max(-N, -q - N);
        int r2 = std::min(N, -q + N);
        for (int r = r1; r <= r2; r++) {
            auto gameField = FieldOnTheGameBoard(q, r, -q - r);
            this->listOfGameBoardFields.push_back(gameField);
        }
    }
}

void GameBoard::setDrawingRepresentationForFields() {

    auto allColumns = 9.f;
    auto hexWidth = 40.0f;
    auto hexHeight = std::sqrt(3.0f) * hexWidth / 2.0f;
    auto initialPositionX = (1280 / 2) - (allColumns / 2) * (hexWidth / 2);
    auto initialPositionY = (720 / 2) - (allColumns / 2) * ((hexHeight - 10) / 2);

    for (auto &element: listOfGameBoardFields) {
        auto x = hexWidth * (3. / 2 * element.hexCoordinates->q);
        auto y = hexWidth * (sqrt(3) / 2 * element.hexCoordinates->q + sqrt(3) * element.hexCoordinates->r);
        element.hexagonField.setPosition(x + initialPositionX, y + initialPositionY);
    }
}

std::vector<FieldOnTheGameBoard> &GameBoard::getListOfGameBoardFields() {
    return listOfGameBoardFields;
}

