#pragma once


#include "SFML/Graphics/RenderWindow.hpp"
#include "../main/gameboard/GameBoard.h"
#include "GameState.h"
#include "../Entities/Player.h"

class Playing : public GameState {

private:
    Player player1;
    Player player2;
    Player *currentRoundPlayer;

    sf::RenderWindow *pWindow;
    GameBoard gameBoard;

//    Vectors containing pointers to current Possible Player moves
    std::vector<FieldOnTheGameBoard *> currentOneStepPossibleMoves;
    std::vector<FieldOnTheGameBoard *> currentTwoStepPossibleMoves;

    FieldOnTheGameBoard *pOriginFieldOfPlayerMove{};

public:
//  Constructors & Deconstructors
    explicit Playing(sf::RenderWindow &window);

//  Functions
    void eventHandler(sf::Event event) override;

    void update() override;

    void draw() override;


    void handleMouseEventOnField(sf::Event event);

    void checkPossibleMoves(FieldOnTheGameBoard &fieldOnTheGameBoard);

    void handlePlayerMove(FieldOnTheGameBoard &fieldOnTheGameBoard);

    void setInitialPlayerHexagons();

};



