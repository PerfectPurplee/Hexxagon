#pragma once

#include <SFML/Graphics.hpp>
#include <random>

struct BackgroundCometElement {

private:
    std::random_device rd;

    float randomNumberForComet() {
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> range(1, 10);
        return range(generator);
    }

    void setCometStartingPosition() {
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> xDistribution(0, 1280 - static_cast<int>(comet.getRadius()) * 2);
        std::uniform_int_distribution<int> yDistribution(0, 720 - static_cast<int>(comet.getRadius()) * 2);

        comet.setPosition(xDistribution(generator), yDistribution(generator));
    }


public:
    sf::CircleShape comet;
    float flyingSpeed;

    BackgroundCometElement() : comet(randomNumberForComet()),
                               flyingSpeed(randomNumberForComet()) {

        this->setCometStartingPosition();
    }


};

struct Background {

private:
    int totalNumberOfComets = 20;

    void populateListOfBackgroundComets() {
//        for (int i = 0; i < totalNumberOfComets; i++) {
//            auto comet = new BackgroundCometElement();
//            listOfBackgroundComets.push_back(comet);
//        }
    }

public:
    std::vector<BackgroundCometElement> listOfBackgroundComets;


    Background() {

    }


};

