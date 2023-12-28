
#include "GameEngine.h"


GameEngine::GameEngine() {
    this->videoMode = sf::VideoMode(1920, 1080);
    this->window = new sf::RenderWindow(videoMode,
                                        "Hexxagon",
                                        sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(60);
    this->currentGameState = GameStates::MENU;
// Starts GameLoop
    this->running();
}

void GameEngine::render(sf::RenderWindow *pWindow) {
    switch (currentGameState) {

        case PLAYING:
            this->playing.draw(pWindow);
            break;
        case MENU:
            this->menu.draw(pWindow);
            break;
    }
}

void GameEngine::update(sf::RenderWindow *pWindow) {
    switch (currentGameState) {

        case PLAYING:
            this->playing.update(pWindow);
            break;
        case MENU:
            this->menu.update(pWindow);
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
        this->update(window);

//        Drawing
        this->render(window);

        window->display();
    }
}


