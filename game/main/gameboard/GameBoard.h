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
    GameBoard();



//    Getters
     std::vector<FieldOnTheGameBoard> &getListOfGameBoardFields();

};



