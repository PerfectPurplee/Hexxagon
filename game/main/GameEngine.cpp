
#include "GameEngine.h"


GameEngine::GameEngine() {
    this->videoMode = sf::VideoMode(1280, 720);
    this->window = new sf::RenderWindow(videoMode,
                                        "Hexxagon",
                                        sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(60);

    this->currentGameState = GameStates::MENU;


// Starts GameLoop
    this->running();
}

void GameEngine::render() {
    switch (currentGameState) {

        case PLAYING:
            this->playing.draw();
            break;
        case MENU:
            this->menu.draw();
            break;
    }
}

void GameEngine::update() {
    switch (currentGameState) {

        case PLAYING:
            this->playing.update();
            break;
        case MENU:
            this->menu.update();
            break;
    }
}

void GameEngine::running() {


    while (window->isOpen()) {
        auto event = sf::Event();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
//        Logical updates
        this->update();

//        Drawing
        this->render();

        window->display();
    }
}


