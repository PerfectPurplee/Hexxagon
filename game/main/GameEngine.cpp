
#include <filesystem>
#include "GameEngine.h"


GameEngine::GameEngine()
        : videoMode(1280, 720),
          window(videoMode,
                 "Hexxagon",
                 sf::Style::Close | sf::Style::Titlebar),
          playing(window),
          menu(window, font, currentGameState) {

    this->window.setFramerateLimit(60);
    this->currentGameState = GameStates::MENU;
    GameEngine::setFont();


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
        case SCOREBOARD:
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
        case SCOREBOARD:
            break;
    }
}

void GameEngine::eventHandler(sf::Event event) {
    switch (currentGameState) {

        case PLAYING:
            this->playing.eventHandler(event);
            break;
        case MENU:
            this->menu.eventHandler(event);
            break;
        case SCOREBOARD:
            break;
    }
}

void GameEngine::running() {


    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
//        Handle events in current game state
            this->eventHandler(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
//        Logical updates
        this->update();

//        Drawing
        this->render();

        window.display();
    }
}

const sf::Font &GameEngine::getFont() {
    return font;
}

void GameEngine::setFont() {
    if (!font.loadFromFile(R"(..\game\resources\fonts\DotGothic16-Regular.ttf)")) {
//        std::cout << std::filesystem::current_path();
    }
}




