#pragma once

#include "SFML/Graphics.hpp"
#include "enums.cpp"
#include "../gamestates/Playing.h"
#include "../gamestates/Menu.h"


class GameEngine {

private:

//    Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;

    GameStates currentGameState;

    Playing playing;
    Menu menu;


//    Functions
    void update();

    void render();

    void running();


public:
//Constructors & Deconstructors
    GameEngine();

//Getters and Setters

// Functions

};



