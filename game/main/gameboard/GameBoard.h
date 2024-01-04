#pragma once

#include <vector>
#include "FieldOnTheGameBoard.cpp"
#include "set"

class GameBoard {

private:
//    Variables
    std::vector<FieldOnTheGameBoard> listOfGameBoardFields;



//    Functions
    void initGameBoardFields();

    void initGameBoardFieldsBETTER();

    void setDrawingRepresentationForFields();

    void setInitialPlayerHexagons();

public:

    const std::vector<HexCoordinates> directionsOneStep = {
            HexCoordinates(-1, 1, 0), HexCoordinates(0, 1, -1), HexCoordinates(1, 0, -1),
            HexCoordinates(1, -1, 0), HexCoordinates(0, -1, 1), HexCoordinates(-1, 0, 1)
    };

    const std::vector<HexCoordinates> directionsTwoSteps = {
            HexCoordinates(-2, 2, 0), HexCoordinates(0, 2, -2), HexCoordinates(2, 0, -2),
            HexCoordinates(2, -2, 0), HexCoordinates(0, -2, 2), HexCoordinates(-2, 0, 2),
            HexCoordinates(-1,-1,2), HexCoordinates(-2, 1, 1), HexCoordinates(-1, 2, -1),
            HexCoordinates(1,1,-2), HexCoordinates(2, -1, -1), HexCoordinates(1,-2,1)
    };


    GameBoard();



//    Getters
     std::vector<FieldOnTheGameBoard> &getListOfGameBoardFields();

};



