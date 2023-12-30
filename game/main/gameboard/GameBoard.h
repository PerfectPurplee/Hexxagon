#pragma once

#include <vector>
#include "FieldOnTheGameBoard.cpp"


class GameBoard {

private:
//    Variables
    std::vector<FieldOnTheGameBoard> ListOfGameBoardFields;

//    Functions
    void initGameBoardFields();

public:
    GameBoard();

};



