#pragma once


#include "SFML/Graphics/RenderWindow.hpp"
#include "../main/gameboard/GameBoard.h"
#include "GameState.h"

class Playing : public GameState {

private:
    sf::RenderWindow* pWindow;
    GameBoard gameBoard;

public:
//  Constructors & Deconstructors
    explicit Playing(sf::RenderWindow& window);

//  Functions
    void eventHandler(sf::Event event) override;

    void update() override;

    void draw() override;


    void handleMouseEventOnField(sf::Event event);

    void checkPossibleMoves(FieldOnTheGameBoard& fieldOnTheGameBoard);

};



